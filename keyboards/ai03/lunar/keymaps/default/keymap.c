/* Copyright 2019 Ryota Goto
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MANUAL = SAFE_RANGE,
  SWPLURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	
	/*
	
	Layout
	
	K000 K001 K002 K003 K004 K005 K006 K007 K008 K009 K010 K011 K012 K013 K212 K014
	K100  K101  K102 K103 K104 K105 K106 K107 K108 K109 K110 K111   K112  K113 K114
	K200    K201 K202 K203 K204 K205 K206 K207 K208 K209 K210 K211     K213    K214
	K300      K301 K302 K303 K304 K305 K306 K307 K308 K309 K310 K311    K313   K314
	K400 K401 K402        K403       K405       K407       K409 K410 K411 K413 K414
	
	K212 = Split backspace (bound to Del by default)
	K403, K407 = Split space (bound to space by default)
	K405 = Main space
	
	*/
	
	[0] = LAYOUT( /* Base */
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_HOME, 
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END, 
		MO(1),            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, 
		KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,          KC_UP,   KC_PGDN, 
		KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,                    MO(1),   KC_GRV,  KC_LEFT, KC_DOWN, KC_RGHT
	),
	[1] = LAYOUT( /* FN */
		RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,  MANUAL, 
		KC_CAPS,          _______, KC_UP,   _______, _______, _______, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_MPRV, KC_MPLY, KC_MNXT, _______, SWPLURL, 
		_______,          KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_VOLD, KC_VOLU, KC_P4,   KC_P5,   KC_P6,   _______, _______,          _______, _______, 
		_______,          KC_RCTL, KC_RGUI, KC_RALT, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   _______, _______,          KC_PGUP, _______, 
		_______, _______, _______,          _______,          _______,          _______,                   _______, _______, KC_HOME, KC_PGDN, KC_END
	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MANUAL:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("https://kb.ai03.me/redir/lunar/index.html");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case SWPLURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://switchplate.co/collections/lunar-group-buy");
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
