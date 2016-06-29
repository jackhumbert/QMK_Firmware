#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define CALC 3 // number pads keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | `~     |   1  |   2  |   3  |   4  |   5  | Wake |           | L2   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | L1   |           | L3   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc/Gui|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |Ent/Ctrl|
 * |--------+------+------+------+------+------| Hyper|           | =/Meh|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *    |Hyper|UpCtrl|DwnAlt| Left |RgtGui|                                       |   =  |   [  |   ]  |   '  | Meh |
 *    `---------------------------------'                                       `---------------------------------'
 *                                       ,--------------.       ,---------------.
 *                                       |Ent/Alt| Space|       | Up   |  Down  |
 *                               ,-------|-------|------|       |------+--------+-------.
 *                               |       |       | PgUp |       | Home |        |       |
 *                               |Bspc/L1| LGui  |------|       |------|  -/~L1 | Space |
 *                               |       |       | PgDn |       | End  |        |       |
 *                               `----------------------'       `-----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,       KC_1,        KC_2,          KC_3,   KC_4, KC_5, KC_WAKE,
        KC_TAB,       KC_Q,        KC_W,          KC_E,   KC_R, KC_T, TG(SYMB),
        GUI_T(KC_ESC),KC_A,        KC_S,          KC_D,   KC_F, KC_G,
        KC_LSFT,      KC_Z,        KC_X,          KC_C,   KC_V, KC_B, ALL_T(KC_NO),
        ALL_T(KC_NO), CTL_T(KC_UP),ALT_T(KC_DOWN),KC_LEFT,GUI_T(KC_RGHT),
                                                        ALT_T(KC_ENT),KC_SPC,
                                                                      KC_PGUP,
                                             LT(SYMB,KC_BSPC),KC_LGUI,KC_PGDN,
        // right hand
        TG(MDIA),     KC_6, KC_7,  KC_8,   KC_9,   KC_0,    KC_MINS,
        TG(CALC),     KC_Y, KC_U,  KC_I,   KC_O,   KC_P,    KC_BSLS,
                      KC_H, KC_J,  KC_K,   KC_L,   KC_SCLN, CTL_T(KC_ENT),
        MEH_T(KC_EQL),KC_N, KC_M,  KC_COMM,KC_DOT, KC_SLSH, KC_RSFT,
                            KC_EQL,KC_LBRC,KC_RBRC,KC_QUOT, MEH_T(KC_NO),
        KC_UP, KC_DOWN,
        KC_HOME,
        KC_END,LT(SYMB,KC_MINS),KC_SPC
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,-------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | Sleep|           | XXXX |  F6  |  F7  |  F8  |  F9  |  F10 |  F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+-------|
 * |        |      |      |      |      |      | XXXX |           | XXXX |   _  |   [  |   -  |   ]  |      |  F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+-------|
 * |        |      |      |LGui+D|      |      |------|           |------|   +  |   {  |   =  |   }  |      |       |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+-------|
 * |        |      |      |      |      |      |      |           |      |   "  |   (  |   '  |   )  |      |       |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+-------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Calc |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | XXXX |Delete|------|       |------| XXXX |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
        // left hand
        KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_SLEP,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,LGUI(KC_D),KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                        KC_TRNS,KC_TRNS,
                                                KC_TRNS,
                                KC_TRNS,KC_DELT,KC_TRNS,
        // right hand
        KC_TRNS,KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,
        KC_TRNS,KC_UNDS,KC_LBRC,KC_MINS,KC_RBRC,KC_TRNS,KC_F12,
                KC_PLUS,KC_LCBR,KC_EQL, KC_RCBR,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_DQUO,KC_LPRN,KC_QUOT,KC_RPRN,KC_TRNS,KC_TRNS,
                        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,
        KC_TRNS,
        KC_TRNS,KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | XXXX |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      | XXXX |           | XXXX |      | Lclk | Rclk |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|MsLeft|MsDown| MsUp |MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |MSWhUp|MsWhDn| Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 | Lclk | Rclk |------|       |------|Fwd   |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
        // left hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                            KC_TRNS, KC_TRNS,
                                                     KC_TRNS,
                                   KC_BTN1, KC_BTN2, KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY,
        KC_TRNS, KC_WH_U, KC_WH_D, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_WBAK, KC_WFWD
),

/* Keymap 3: Calculator Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           | XXXX |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | XXXX |           | XXXX |   Up |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Down |   4  |   5  |   6  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   *  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  |   /  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      | Calc |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Number pad keys
[CALC] = KEYMAP(
        // left hand
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                        KC_TRNS,KC_TRNS,
                                                KC_TRNS,
                                KC_TRNS,KC_TRNS,KC_TRNS,
        // right hand
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_PLUS, KC_TRNS,
                 KC_DOWN, KC_4,    KC_5,    KC_6,    KC_MINS, KC_TRNS,
        KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_ASTR, KC_TRNS,
                          KC_0,    KC_0,    KC_DOT,  KC_SLSH, KC_TRNS,
        KC_TRNS, KC_CALC,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
        case SYMB: // red light
            ergodox_right_led_1_on();
            break;
        case MDIA: // green light
            ergodox_right_led_2_on();
            break;
        case CALC: // blue light
            ergodox_right_led_3_on();
            break;
        default: // none
            break;
    }
};
