/* Copyright 2018 James Underwood
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
#include "fleuron.h"

enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DZ,
  LOWER,
  RAISE
};

/*
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
*/

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ortho_6x16(
  /* Qwerty
   * ,---------------------------------------------------------------------------------------------------------------.
   * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |  F12 | Home | PgUp | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |  Del | End  | PgDn |  /   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |  7   |  8   |  9   |  *   |
   * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------+------|
   * | Caps |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |  4   |  5   |  6   |  -   |
   * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |  1   |  2   |  3   |  +   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | RGB  | Ctrl | Alt  | GUI  |Lower |Shift |Space |Raise | Left | Down |  Up  |Right |  0   |  00  |  .   |Enter |
   * `---------------------------------------------------------------------------------------------------------------'
   */
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_HOME,  KC_PGUP, KC_BSPC, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, KC_DEL, KC_END,   KC_PGDN, KC_PSLS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, KC_P7,  KC_P8,    KC_P9,   KC_PAST, \
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_P4,  KC_P5,    KC_P6,   KC_PMNS, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,  KC_P1,  KC_P2,    KC_P3,   KC_PPLS, \
  RGB_MOD, KC_LCTL, KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_P0,  DZ,       KC_PDOT, KC_PENT \
),

[_LOWER] = LAYOUT_ortho_6x16(
  /* Lower
   * ,---------------------------------------------------------------------------------------------------------------.
   * |RESET |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      | _    | +    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      | {    | }    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |RGBtog|      |      |      |      |      |      |      | Home | PgUp | PgDn | End  |      |      |      |      |
   * `---------------------------------------------------------------------------------------------------------------'
   */
  RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UNDS,  KC_PLUS,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LCBR,  KC_RCBR,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  RGB_TOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   _______,  _______,  _______,  _______ \
),

[_RAISE] = LAYOUT_ortho_6x16(
  /* Raise
   * ,---------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+-------------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      | -    | =    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------|------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      | [    | ]    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      | Prev | Vol- | Vol+ | Next |      |      |      |      |
   * `---------------------------------------------------------------------------------------------------------------'
   */
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MINS,  KC_EQL,   _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  _______,  _______,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MRWD,  KC_VOLD,  KC_VOLU,  KC_MFFD,  _______,  _______,  _______,  _______ \
)
};

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case DZ:
              SEND_STRING("00"); // Double 0 macro for numpad
              return false;
              break;
            case LOWER:
              
        }
    }
    return true;
};
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case DZ:
      if (record->event.pressed) {
        SEND_STRING("00"); // Double 0 macro for numpad
        return false;
        break;
      }
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
