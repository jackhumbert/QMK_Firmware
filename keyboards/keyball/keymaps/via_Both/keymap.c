/*
Copyright 2021 @Yowkees

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "pointing_device.h"
#include "oledkit.h"

enum keymap_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _BALL,
};

/////////////////////////////////////////////////////////////////////////////
// Special key codes for shorthand

// clang-format off

// layer
#define KC_L_SPC    LT(_LOWER, KC_SPC)
#define KC_R_ENT    LT(_RAISE, KC_ENT)

// shift_t
#define KC_S_EN     LSFT_T(KC_LANG2)

// original
#define KC_A_JA     LT(_BALL, KC_LANG1)     // cmd or adjust
#define KC_AL_CP    MT(MOD_LALT, KC_CAPS)   // alt or caps lock
#define KC_G_BS     MT(MOD_LGUI, KC_BSPC)   // command or back space
#define KC_G_DEL    MT(MOD_LGUI, KC_DEL)    // command or delete
#define KC_A_BS     LT(_BALL, KC_BSPC)      // adjust or back space
#define KC_A_DEL    LT(_BALL, KC_DEL)       // adjust or delete
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_double_balls(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------'                    `--------+--------+--------+--------+--------+--------|
       KC_ESC,  KC_GRV, KC_LALT,      KC_BSPC,KC_L_SPC,                             KC_R_ENT,  KC_DEL,      KC_LBRC, KC_RBRC, KC_BSLS
  //`--------+--------+--------'    `--------+--------'                            `--------+--------'    `--------+--------+--------'
  ),

  [_RAISE] = LAYOUT_double_balls(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_HASH,    KC_7,    KC_8,    KC_9, KC_PLUS,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_ASTR,    KC_4,    KC_5,    KC_6,  KC_DOT,                        KC_AT, KC_EXLM, KC_AMPR, KC_PIPE, KC_PERC,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_SLSH,    KC_1,    KC_2,    KC_3,  KC_EQL,                       KC_GRV,  KC_DQT, KC_QUOT, KC_CIRC, KC_TILD, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------'                    `--------+--------+--------+--------+--------+--------|
       KC_ESC,  KC_GRV,    KC_0,     KC_LANG2,KC_A_DEL,                              _______, _______,      KC_LPRN, KC_RPRN, KC_BSLS
  //`--------+--------+--------'    `--------+--------'                            `--------+--------'    `--------+--------+--------'
  ),

  [_LOWER] = LAYOUT_double_balls(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, _______, KC_LEFT,   KC_UP, KC_RGHT, _______,                      _______, KC_BTN1, KC_PGUP, KC_BTN2, KC_BTN3,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, KC_DOWN, _______, _______,                      _______, _______, KC_PGDN, _______, _______, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------'                    `--------+--------+--------+--------+--------+--------|
       KC_ESC,  KC_GRV, KC_LALT,      _______, _______,                              KC_A_BS,KC_LANG1,      KC_LPRN, KC_RPRN, KC_BSLS
  //`--------+--------+--------'    `--------+--------'                            `--------+--------'    `--------+--------+--------'
  ),

  [_BALL] = LAYOUT_double_balls(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------'                    `--------+--------+--------+--------+--------+--------|
      _______, _______, _______,      _______, _______,                              _______, _______,      _______, _______, _______
  //`--------+--------+--------'    `--------+--------'                            `--------+--------'    `--------+--------+--------'
  ),

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BALL:
            keyball_set_scroll_mode(true);
            break;
        default:
            keyball_set_scroll_mode(false);
            break;
    }
    return state;
}

#ifdef OLED_ENABLE

void oledkit_render_info_user(void) {
    const char *n;
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            n = PSTR("Default");
            break;
        case _RAISE:
            n = PSTR("Raise");
            break;
        case _LOWER:
            n = PSTR("Lower");
            break;
        case _BALL:
            n = PSTR("Adjust");
            break;
        default:
            n = PSTR("Undefined");
            break;
    }
    oled_write_P(PSTR("Layer: "), false);
    oled_write_ln_P(n, false);

    keyball_oled_render_ballinfo();
    keyball_oled_render_keyinfo();
}

#endif
