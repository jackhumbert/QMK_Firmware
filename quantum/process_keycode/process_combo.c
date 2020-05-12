/* Copyright 2016 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "print.h"
#include "process_combo.h"
#include "action_tapping.h"

#ifndef COMBO_VARIABLE_LEN
__attribute__((weak)) combo_t key_combos[COMBO_COUNT] = {};
#else
extern combo_t  key_combos[];
extern int      COMBO_LEN;
#endif

__attribute__((weak)) void process_combo_event(uint8_t combo_index, bool pressed) {}

static uint16_t timer               = 0;
static uint8_t  active_combo_index  = 0;
static bool     is_active           = true;
static bool     b_combo_enable      = true;  // defaults to enabled
static combo_t  *active_combo       = NULL;

static uint8_t buffer_size = 0;
static keyrecord_t key_buffer[MAX_COMBO_LENGTH];

static inline void send_combo(uint16_t action, bool pressed) {
    if (action) {
        if (pressed) {
            register_code16(action);
        } else {
            unregister_code16(action);
        }
    } else {
        process_combo_event(active_combo_index, pressed);
    }
}

static inline void dump_key_buffer(bool emit) {
    if (buffer_size == 0) {
        return;
    }

    if (emit) {
        for (uint8_t i = 0; i < buffer_size; i++) {
            action_tapping_process(key_buffer[i]);
        }
    }
    clear_combos(emit);

    buffer_size = 0;
}

void fire_combo(void) {
    send_combo(active_combo->keycode, true);
    active_combo = NULL;
    dump_key_buffer(false);
}

#define ALL_COMBO_KEYS_ARE_DOWN (((1 << count) - 1) == combo->state)
#define KEY_STATE_DOWN(key)         \
    do {                            \
        combo->state |= (1 << key); \
    } while (0)
#define KEY_STATE_UP(key)            \
    do {                             \
        combo->state &= ~(1 << key); \
    } while (0)

static bool process_single_combo(combo_t *combo, uint16_t keycode, keyrecord_t *record, uint8_t combo_index) {
    uint8_t count = 0;
    uint8_t index = -1;
    /* Find index of keycode and number of combo keys */
    for (const uint16_t *keys = combo->keys;; ++count) {
        uint16_t key = pgm_read_word(&keys[count]);
        if (keycode == key) index = count;
        if (COMBO_END == key) break;
    }

    /* Continue processing if key isn't part of current combo.
     * Also disable current combo and reset its state. */
    if (-1 == (int8_t)index) {
        combo->disabled = true;
        combo->state = 0;
        return false;
    }

    bool is_combo_active = is_active & !combo->disabled;

    if (record->event.pressed) {
        if (is_combo_active) {
            KEY_STATE_DOWN(index);
            if (ALL_COMBO_KEYS_ARE_DOWN) { /* Combo was pressed */
                /* Save the combo so we can fire it after COMBO_TERM */
                active_combo = combo;
                active_combo_index = combo_index;
            }
        }
    } else {
        if (ALL_COMBO_KEYS_ARE_DOWN) { /* Combo was released */
            if (active_combo && !active_combo->disabled) {
                /* Fire combo immediately if it was released inside COMBO_TERM */
                fire_combo();
            }
            send_combo(combo->keycode, false);
        } else {
            /* continue processing without immediately returning */
            is_combo_active = false;
        }

        KEY_STATE_UP(index);
    }

    return is_combo_active;
}

#define NO_COMBO_KEYS_ARE_DOWN (0 == combo->state)

bool process_combo(uint16_t keycode, keyrecord_t *record) {
    bool is_combo_key          = false;
    bool no_combo_keys_pressed = true;

    if (keycode == CMB_ON && record->event.pressed) {
        combo_enable();
        return true;
    }

    if (keycode == CMB_OFF && record->event.pressed) {
        combo_disable();
        return true;
    }

    if (keycode == CMB_TOG && record->event.pressed) {
        combo_toggle();
        return true;
    }

    if (!is_combo_enabled()) {
        return true;
    }
#ifndef COMBO_VARIABLE_LEN
    for (uint8_t idx = 0; idx < COMBO_COUNT; ++idx) {
#else
    for (uint8_t idx = 0; idx < COMBO_LEN; ++idx) {
#endif
        combo_t *combo = &key_combos[idx];
        is_combo_key |= process_single_combo(combo, keycode, record, idx);
        no_combo_keys_pressed = no_combo_keys_pressed && NO_COMBO_KEYS_ARE_DOWN;
    }

    if (!is_combo_key) {
        /* if no combos claim the key we need to emit the keybuffer */
        dump_key_buffer(true);

        // reset state if there are no combo keys pressed at all
        if (no_combo_keys_pressed) {
            timer     = 0;
            is_active = true;
            clear_combos(true);
        }
    } else if (record->event.pressed && is_active) {
        /* otherwise the key is consumed and placed in the buffer */
        timer = timer_read();

        if (buffer_size < MAX_COMBO_LENGTH) {
            key_buffer[buffer_size++] = *record;
        }
    }

    return !is_combo_key;
}

void clear_combos(bool clear_state) {
    uint8_t index = 0;
#ifndef COMBO_VARIABLE_LEN
    for (index = 0; index < COMBO_COUNT; ++index) {
#else
    for (index = 0; index < COMBO_LEN; ++index) {
#endif
        combo_t *combo = &key_combos[index];
        combo->disabled = false;
        if (clear_state) {
            combo->state = 0;
        }
    }
}

void matrix_scan_combo(void) {
    if (b_combo_enable && is_active && timer && timer_elapsed(timer) > COMBO_TERM) {
        /* This disables the combo, meaning key events for this
         * combo will be handled by the next processors in the chain
         */
        if (active_combo && !active_combo->disabled) {
            fire_combo();
        } else {
            active_combo = NULL;
            is_active = false;
            dump_key_buffer(true);
        }
    } else if (b_combo_enable && !is_active && timer && timer_elapsed(timer) > TAPPING_TERM) {
        /* Re-enable combo processing after TAPPING_TERM so combos are usable
         * with mods from ModTap keys that are also combo keys */
        is_active = true;
        timer = 0;
        clear_combos(false);
    }
}

void combo_enable(void) { is_active = b_combo_enable = true; }

void combo_disable(void) {
    b_combo_enable = is_active = false;
    timer                      = 0;
    active_combo               = NULL;
    dump_key_buffer(true);
}

void combo_toggle(void) {
    if (b_combo_enable) {
        combo_disable();
    } else {
        combo_enable();
    }
}

bool is_combo_enabled(void) { return b_combo_enable; }
