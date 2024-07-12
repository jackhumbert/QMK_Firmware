/* Copyright 2022 bdtc123
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

enum my_keycodes {
    RMT = QK_KB_0,
    RMS,
    RMIH,
    RMDH,
    RMIS,
    RMDS,
    RMIV,
    RMDV
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RMT:
      if (record->event.pressed)
      {rgb_matrix_toggle();
      }
      return false;
    case RMS:
      if (record->event.pressed)
      {rgb_matrix_step();
      }
      return false;
      case RMIH:
      if (record->event.pressed)
      {rgb_matrix_increase_hue();
      }
      return false;
      case RMDH:
      if (record->event.pressed)
      {rgb_matrix_decrease_hue();
      }
      return false;
      case RMIS:
      if (record->event.pressed)
      {rgb_matrix_increase_sat();
      }
      return false;
      case RMDS:
      if (record->event.pressed)
      {rgb_matrix_decrease_sat();
      }
      return false;
      case RMIV:
      if (record->event.pressed)
      {rgb_matrix_increase_val();
      }
      return false;
      case RMDV:
      if (record->event.pressed)
      {rgb_matrix_decrease_val();
      }
      return true;
      default:
      return true;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_GRV,  KC_PGUP, KC_PGDN,
        KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,          KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,        KC_UP,   KC_SLSH,
        KC_LCTL,   KC_LGUI,   KC_LALT,                       KC_SPC,                              KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  QK_BOOT, _______, _______, _______,
        _______,     RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
        _______,       RMT,  RMS,  RMIH,  RMDH,  RMIS,  RMDS,  RMIV,  RMDV, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,        _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______
    ),
     [2] = LAYOUT(
        _______, _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______, _______, _______,
        _______,    _______,_______,_______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______,
        _______,       _______,_______,_______,_______,_______,_______,_______,_______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______
    ),
     [3] = LAYOUT(
         _______, _______,  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,  _______, _______, _______,
        _______,    _______,_______,_______,_______,_______,_______,_______,_______, _______, _______, _______, _______, _______,
        _______,       _______,_______,_______,_______,_______,_______,_______,_______, _______, _______, _______, _______,
        _______,            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______, _______,
        _______,   _______,   _______,                      _______,                              _______, _______, _______, _______, _______
    ),

};

