/* Copyright 2020 noclew
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
#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
  float song_coin[][2]  = SONG(COIN_SOUND);
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    BASE,
    LOWER,
    RAISE,
    RGBF,
    RGBR,
    VOLUP,
    VOLDN
};

#define RGBF RGB_MODE_FORWARD
#define RGBR RGB_MODE_REVERSE
#define VOLUP KC__VOLUP
#define VOLDN KC__VOLDOWN


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
     * -------------------------------------------               -------------------------------------------
     * |   `  |   1  |   2  |   3  |   4  |   5  |               |   6  |   7  |   8  |   9  |   0  | Bksp |
     * -------------------------------------------               -------------------------------------------
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |               |   Y  |   U  |   I  |   O  |   P  | Del  |
     * -------------------------------------------   ---------  --------------------------------------------
     * | Esc  |   A  |   S  |   D  |   F  |   G  |   | Right |   |   H  |   J  |   K  |   L  |   ;  |Enter |
     * -------------------------------------------   ---------   -------------------------------------------
     * | Shift|   Z  |   X  |   C  |   V  |   B  |   | LEFT  |   |   N  |   M  |   ,  |   .  |   /  | "    |
     * -------------------------------------------   ---------   -------------------------------------------
     *        | Ctrl | GUI  |  Alt |Lower |Space |               |Space |Raise |Alt   | DOWN | UP   |
     *        ------------------------------------               ------------------------------------
     */

    [_BASE] = LAYOUT_vanana( \
    KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_BSPC,    \
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSLASH,  \
    KC_ESC,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_RIGHT,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,     \
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LEFT,        KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    MT(MOD_RSFT, KC_QUOT),    \
                KC_LCTL,    KC_LALT,    KC_LGUI,    LOWER,      KC_SPC,                     KC_SPC,     RAISE,      KC_RALT,    KC_DOWN,    KC_UP                   \
    ),
    [_LOWER] = LAYOUT_vanana( \
    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,                      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
    _______,    _______,    _______,    KC_7,       KC_8,       KC_9,                       _______,    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    KC_0,       KC_4,       KC_5,       KC_6,       KC_UP,          _______,    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       KC_DOWN,        _______,    _______,    _______,    _______,    _______,    _______,    \
                _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______                 \
    ),

    [_RAISE] = LAYOUT_vanana( \
    _______,    _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    _______,                    _______,    KC_HOME,    KC_BSPC,    KC_END,     _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,        KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   _______,    _______,    \
    _______,    _______,    _______,    _______,    _______,    _______,    _______,        _______,    KC_PGUP,    KC_DEL ,    KC_PGDN,    _______,    _______,    \
                _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______                 \
    ),
    [_ADJUST] = LAYOUT_vanana( \
    RESET  ,    _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______,    DEBUG,      \
    _______,    RGB_TOG,    RGBF,       RGBR,       RGB_SAD,    RGB_SAI,                    _______,    _______,    _______,    _______,    _______,    _______,    \
    KC_CAPSLOCK,_______,    RGB_HUD,    RGB_HUI,    RGB_VAD,    RGB_VAI,    VOLUP,          _______,    _______,    _______,    _______,    _______,    _______,    \
    _______,    AU_ON  ,    AU_OFF ,    _______,    _______,    _______,    VOLDN,          _______,    _______,    _______,    _______,    _______,    _______,    \
                _______,    _______,    _______,    _______,    _______,                    _______,    _______,    _______,    _______,    _______     \
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return false;
        break;

        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return false;
        break;

        case RESET:
            if (record->event.pressed) {
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(song_coin);
                #endif
            }
        return false;
        break;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    /* With an if statement we can check which encoder was turned. */
    if (index == 0) { /* First encoder */
        /* And with another if statement we can check the direction. */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }

    } else if (index == 1) { /* Second encoder. Only supported by Elite-C */
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }
}


