/* Copyright 2021 Jonathan Rascher
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

enum layer {
    LAYER_DEFAULT,
    LAYER_FUNCTION,
};

#define LY_FN MO(LAYER_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer: http://www.keyboard-layout-editor.com/#/gists/60a262432bb340b37d364a4424f3037b */
    [LAYER_DEFAULT] = LAYOUT_65(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,   KC_HOME,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,            KC_PGUP,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,                      KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,  LY_FN,    KC_SPC,                       KC_SPC,   XXXXXXX,  KC_RALT,  LY_FN,    KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    /* Function layer: http://www.keyboard-layout-editor.com/#/gists/59636898946da51f91fb290f8e078b4d */
    [LAYER_FUNCTION] = LAYOUT_65(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,   KC_DEL,   RGB_HUI,
        KC_CAPS,  NK_TOGG,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,  EEP_RST,  RESET,    KC_PSCR,  KC_SLCK,  KC_PAUS,  _______,  _______,  _______,            RGB_SAI,
        _______,  _______,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            RGB_TOG,            RGB_SAD,
        _______,  KC_APP,   _______,  KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                      RGB_VAI,  RGB_HUD,
        _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,            RGB_RMOD, RGB_VAD,  RGB_MOD
    ),
};
