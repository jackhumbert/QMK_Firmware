/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC, KC_RBRC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,          KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI,          KC_LALT,     LT(1,KC_SPC), LT(2,KC_BSPC),    KC_RALT,                    KC_RGUI, KC_RCTL
    ),

    [1] = LAYOUT(
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS, KC_TRNS
	),

    [2] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,          KC_TRNS,                   KC_TRNS, KC_TRNS
	)
};

void matrix_init_user(void) {
    setPinOutput(B2);
//    writePinLow(B2);
    writePinHigh(B2);
}

//layer_state_t layer_state_set_user(layer_state_t state) {
//    switch (get_highest_layer(state)) {
//        case 1:
//		    writePinHigh(B2);
//		    break;	
//        case 2:
//		    writePinHigh(B2);
//		    break;
//        case 3:
//		    writePinHigh(B2);
//		    break;	
//        default:
//		    writePinLow(B2);
//        break;
//    }
//    return state;
//}
