/* Copyright 2021 xSteins <itsmesteins@gmail.com>
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
	_BASE,
	_FN1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65_ANSI(
              KC_ESC,  KC_1,    KC_2,                                                                                   KC_MINS, KC_EQL,  KC_BSPC,          KC_GRV,
            KC_TAB,       KC_Q,       KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,          KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL,
          KC_CAPS,        KC_A,  KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN, KC_QUOT, KC_ENT,             KC_HOME,
        KC_LSFT,             KC_Z, KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,           KC_SLSH,  KC_LALT,    KC_UP,     KC_END,
        KC_LCTL,                        KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LGUI,         KC_LEFT, KC_DOWN, KC_RGHT,
                                        KC_LALT,   KC_SPC,           MO(_FN1),        KC_SPC,                  MO(_FN1)
    ),
    [_FN1] = LAYOUT_65_ANSI(
              KC_GRV,  KC_F1,   KC_F2,                                                                                  KC_F11,  KC_F12,  _______,          _______,
            _______,      _______,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                KC_F7,   KC_F8,   KC_F9,   KC_F10,        _______, _______, _______,     _______,
          KC_LCTL,        _______, _______,   _______, _______, _______,              _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,            _______,
        KC_LSFT,          KC_LEFT, KC_S, _______, _______, _______,              _______, KC_VOLD, KC_MUTE, KC_VOLU,        _______,  _______,    KC_MS_WH_UP,   _______,
        _______,                        KC_UP, KC_DOWN, KC_RGHT, _______,            _______, _______, _______, _______, _______,           KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT,
                                        KC_LGUI,   _______,          _______,     _______,                 _______
    )
};
/* const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65_ANSI(
              KC_ESC,  KC_1,    KC_2,                                                                                   KC_MINS, KC_EQL,  KC_BSPC,          KC_GRV,
            KC_TAB,       KC_Q,       KC_3,    KC_4,    KC_5,    KC_6,                 KC_7,    KC_8,    KC_9,    KC_0,          KC_LBRC, KC_RBRC, KC_BSLS,     KC_DEL,
          KC_CAPS,        KC_A,  KC_W,    KC_E,    KC_R,    KC_T,                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN, KC_QUOT, KC_ENT,             KC_HOME,
        KC_LSFT,             KC_Z, KC_S,    KC_D,    KC_F,    KC_G,                 KC_H,    KC_J,    KC_K,    KC_L,           KC_SLSH,  KC_LALT,    KC_UP,     KC_END,
        KC_LCTL,                        KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_LGUI,         KC_LEFT, KC_DOWN, KC_RGHT,
                                        KC_LALT,   KC_SPC,           MO(_FN1),        KC_SPC,                  MO(_FN1)
    ),
    [_FN1] = LAYOUT_65_ANSI(
              KC_GRV,  KC_F1,   KC_F2,                                                                                  KC_F11,  KC_F12,  _______,          _______,
            _______,      _______,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                KC_F7,   KC_F8,   KC_F9,   KC_F10,        _______, _______, _______,     _______,
          KC_LCTL,        KC_LEFT, KC_UP,   _______, _______, _______,              _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,            _______,
        KC_LSFT,          _______, KC_DOWN, KC_RGHT, _______, _______,              _______, KC_VOLD, KC_MUTE, KC_VOLU,        _______,  _______,    _______,   _______,
        _______,                        _______, _______, _______, _______,            _______, _______, _______, _______, _______,           _______, _______, _______,
                                        KC_LGUI,   _______,          _______,     _______,                 _______
    )
};
*/