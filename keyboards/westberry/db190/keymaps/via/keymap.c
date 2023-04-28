/* Copyright (C) 2023 Westberry Technology Corp., Ltd
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

enum layers{
    WIN_BASE = 0,
    WIN_FN,
    MAC_BASE,
    MAC_FN
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_BASE] = LAYOUT( /* Base */
        KC_ESC,   KC_F1,        KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,  KC_F11,      KC_F12,     KC_DEL,
        KC_GRV,   KC_1,         KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,     KC_EQL,     KC_BSPC,  KC_PGUP,
        KC_TAB,   KC_Q,         KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,    KC_LBRC,     KC_RBRC,    KC_BSLS,  KC_PGDN,
        KC_CAPS,  KC_A,         KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN, KC_QUOT,     KC_ENT,               KC_HOME,
        KC_LSFT,  KC_Z,         KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT,                           KC_UP,
        KC_LCTL,  KC_LGUI,      KC_LALT,                                KC_SPC,                                 KC_RGUI, MO(WIN_FN),  KC_RCTL,    KC_LEFT,  KC_DOWN,  KC_RIGHT),

    [WIN_FN] = LAYOUT( /* FN */
        QK_BOOT,  KC_BRID,      KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,    _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  RGB_VAD,    RGB_VAI,    EE_CLR,    _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,   _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,               _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                           RGB_TOG,
        _______,  DF(MAC_BASE), _______,                                _______,                                _______,  _______,    _______,    RGB_RMOD,  RGB_TOG,  RGB_MOD),

    [MAC_BASE] = LAYOUT( /* Base */
        KC_ESC,   KC_BRID,      KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,    KC_DEL,
        KC_GRV,   KC_1,         KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,   KC_PGUP,
        KC_TAB,   KC_Q,         KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,   KC_PGDN,
        KC_CAPS,  KC_A,         KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_ENT,                KC_HOME,
        KC_LSFT,  KC_Z,         KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                           KC_UP,
        KC_LCTL,  _______,      _______,                                KC_SPC,                                 _______,  MO(MAC_FN), _______,    KC_LEFT,   KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT( /* FN */
        QK_BOOT,  KC_F1,        KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,     _______,
        _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    EE_CLR,   _______,
        RGB_TOG,  RGB_VAI,      _______,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,    _______,  _______,
        _______,  RGB_VAD,      RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,              _______,
        _______,  _______,      _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,                          RGB_TOG,
        _______,  _______,      DF(WIN_BASE),                           _______,                                _______,  _______,    _______,    RGB_RMOD, RGB_TOG,  RGB_MOD)
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}
};
#endif
