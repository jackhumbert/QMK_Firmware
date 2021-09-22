/* Copyright 2021 Walter Hanley
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

// Defines keycode alias
#define ECTL LCTL_T(KC_ESC)
#define DELSYM LT(_SYMBOL, KC_DEL)
#define SCLNAV LT(_NAV, KC_SCLN)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE
    _SYMBOL
    _NAV
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
     KC_PSLS, KC_7,    KC_8,    KC_9,    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,  KC_INS,  KC_HOME, KC_PGUP, KC_NO,
     KC_PAST, KC_4,    KC_5,    KC_6,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, KC_DEL,  KC_END,  KC_PGDN, KC_NO,
     KC_PMNS, KC_1,    KC_2,    KC_3,    ECTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    SCLNAV,  KC_QUOT, KC_NO,   KC_UP,   KC_NO,   KC_NO,
     KC_PPLS, KC_0,    KC_DOT,  KC_ENT,  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
                                                           KC_NO,   KC_LALT, KC_LGUI, KC_BSPC, KC_ENT,  KC_SPC,  DELSYM,  KC_RGUI, KC_RALT, KC_MUTE
    ),

    /* Symbols and F-Keys */
    [_SYMBOL] = LAYOUT(
     _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, KC_UNDS, KC_LCBR, KC_LBRC, _______,                   _______, KC_RBRC, KC_RCBR, KC_MINS, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Nav Cluster and Text Macros*/
    [_NAV] = LAYOUT(
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                                           _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_TAB);
        } else {
            tap_code(S(KC_TAB));
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}
