// Copyright 2020 MaiKong<704340378@qq.com>
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H



enum mt84_layers {
    _DEFAULT,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_75_ansi(
    	 KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,    KC_F6,    KC_F7,   KC_F8,   KC_F9  , KC_F10, KC_F11,    KC_F12,   KC_PSCR, KC_PAUSE, KC_DELETE,
        KC_GRAVE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,  KC_UP,  KC_END,
        KC_LCTL,    KC_LALT, KC_LWIN,              KC_SPC,                                          MO(1),  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
                        ),
   [_FN]   = LAYOUT_75_ansi(
      	 _______,  _______,  _______, _______,    _______, _______,  _______, _______, _______,  _______, _______,    _______, _______,  _______, _______,_______,
      	 _______,  _______,  _______, _______,    _______, _______,  _______, _______, _______,  _______, _______,    _______, _______,  _______, _______,
      	 _______,  _______,  _______, _______,    _______, _______,  _______, _______, _______,  _______, _______,    _______, _______,  _______, _______,
        RM_TOGG, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD, RM_SPDU, RM_SPDD, _______, _______,_______, _______,_______,
        _______,  RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, _______,_______,_______,_______,
        _______,  _______,  _______,                        _______,                                                                     KC_TRNS, _______,  _______, _______, _______, _______
                      )
};

bool rgb_matrix_indicators_user(void) {
	led_t led_state = host_keyboard_led_state();
	    switch (get_highest_layer(layer_state)) {
	      case _FN:
	        rgb_matrix_set_color(77,0xFF, 0x80, 0x00);
          break;
    }
    if (led_state.caps_lock) {
          rgb_matrix_set_color(46, 0xFF, 0xFF, 0xFF);
    }
    return false;
}
