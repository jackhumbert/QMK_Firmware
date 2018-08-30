/* Copyright 2017 REPLACE_WITH_YOUR_NAME
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

#include "xtonhasvim.h"
#include "fancylighting.h"

#define _______ KC_TRNS
#define X_____X KC_NO

enum layers {
  _QWERTY,
  _FUN,
  _MOVE,
  _CMD
};

extern uint8_t vim_cmd_layer(void) { return _CMD; }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  X_____X, KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_BSLS, \
        LT(_MOVE, KC_CAPS),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
        KC_LSFT, X_____X,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, X_____X,  \
        KC_LCTL, KC_LALT, KC_LGUI,               KC_SPC,                          KC_RGUI, KC_RALT,  VIM_START, MO(_FUN)),


    [_MOVE] = LAYOUT_all(
        X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X,
        X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, KC_HOME, KC_PGDN, KC_PGUP, KC_END, X_____X, X_____X, X_____X, X_____X,
        _______, X_____X, LGUI(KC_LBRC), LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), LGUI(KC_RBRC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, X_____X, X_____X, VIM_START,
        _______, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, _______,
        _______,   _______,   _______,               _______,                                                      _______,   _______,  _______,  _______),


    [_FUN] = LAYOUT_all(
	       KC_GRV,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  X_____X, KC_DEL, \
	       X_____X,   RGB_M_P,  KC_UP,    RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,   X_____X, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,    X_____X,          KC_INS, \
	       X_____X,   KC_LEFT,  KC_DOWN,  KC_RIGHT, RGB_HUD,  RGB_SAD,  RGB_VAD,   X_____X, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT,          X_____X,          \
	       X_____X,   X_____X,  BL_DEC,   BL_STEP,  BL_INC,   X_____X,  KC_VOLD,   KC_VOLU, KC_MUTE, KC_END,  KC_PGDN,  KC_DOWN,X_____X, X_____X,  \
	       X_____X,   X_____X,  X_____X,            X_____X,                                                           X_____X,  X_____X, X_____X, _______
    ),

    [_CMD] = LAYOUT_all(
        VIM_ESC, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X, X_____X,
        X_____X, X_____X, VIM_W, VIM_E, X_____X, X_____X, VIM_Y, VIM_U, VIM_I, VIM_O, VIM_P, X_____X, X_____X, X_____X,
        _______,   VIM_A, VIM_S, VIM_D, X_____X, VIM_G, VIM_H, VIM_J, VIM_K, VIM_L, X_____X, X_____X, X_____X,
        VIM_SHIFT,     X_____X, X_____X, VIM_X, VIM_C, VIM_V, VIM_B, X_____X, X_____X, VIM_COMMA, VIM_PERIOD, X_____X, VIM_SHIFT,X_____X,
        _______, _______, _______,               _______,                          _______, _______,  _______, TO(_QWERTY)
    )
};


void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRE  |=  (1<<PE6);
        PORTE &= ~(1<<PE6);
    }
    else {
        // Hi-Z
        DDRE  &= ~(1<<PE6);
        PORTE &= ~(1<<PE6);
    }
}

#define C_RED 0xFF, 0x00, 0x00
#define C_GRN 0x00, 0xFF, 0x00
#define C_BLU 0x00, 0x00, 0xFF

#define C_YAN 0x00, 0xFF, 0xFF
#define C_PRP 0x7A, 0x00, 0xFF
#define C_ORG 0xFF, 0x93, 0x00

/** the underglow LEDs aren't individually addressable, sadly */
void rgbflag(uint8_t r, uint8_t g, uint8_t b) {
  LED_TYPE *target_led = user_rgb_mode ? shadowed_led : led;
  target_led[0].r = r;
  target_led[0].g = g;
  target_led[0].b = b;
  rgblight_set();
}

void set_state_leds(void) {
  if (rgblight_get_mode() == 1) {
    switch (biton32(layer_state)) {
    case _MOVE:
      rgbflag(C_BLU);
      break;
    case _CMD:
      switch(vstate) {
        case VIM_V:
        case VIM_VI:
        case VIM_VS:
        case VIM_C:
        case VIM_CI:
        case VIM_D:
        case VIM_DI:
          rgbflag(C_RED);
          break;
        case VIM_G:
          rgbflag(C_PRP);
          break;
        case VIM_Y:
          rgbflag(C_ORG);
          break;
        case VIM_START:
        default:
          rgbflag(C_GRN);
          break;
      }
      break;
    default: //  for any other layers, or the default layer
      rgbflag(C_YAN);
      break;
    }
  }
}
