/* Copyright 2021 James R. Maynard III <jaymaynard@gmail.com>
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

enum custom_keycodes {
    JM_DOT = SAFE_RANGE, // . both shifted and unshifted
    JM_COMM,      // , both shifted and unshifted
    JM_GRLS,      // < and > on one key
    JM_CBRC,      // { and } on one key
    JM_CENT,      // cent sign and ! on one key
    JM_NLIN,      // tab to next line
    JM_RSET,      // RESET
    JM_PA1,       // PA1
    JM_PA2,       // PA2
    JM_BTAB,      // backwards tab
    JM_JUMP,      // JUMP/PA3,
    JM_ATTN,      // ATTN
    JM_CLR,       // CLEAR
    JM_CSEL,      // CrSel (cursor select)
    JM_XSEL,      // ExSel (extended select)
    JM_EEOF,      // ErEOF (erase to end of field)
    JM_COPY,      // Copy
    JM_HOME,      // Home
    JM_ZOOM,      // Zoom
    JM_DEL,       // Delete
    JM_F13,       // F13
    JM_F14,       // F14
    JM_F15,       // F15
    JM_F16,       // F16
    JM_F17,       // F17
    JM_F18,       // F18
    JM_F19,       // F19
    JM_F20,       // F20
    JM_F21,       // F21
    JM_F22,       // F22
    JM_F23,       // F23
    JM_F24        // F24
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // PC/3270 layout: PC legends (blue)
    [0] = LAYOUT(
                          KC_F13,  KC_F14,  KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22,  KC_F23,  KC_F24,
                          KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,
        KC_NO,   KC_NO,   KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_ESC,  KC_PGUP, KC_PGDN,    KC_NLCK, KC_SLCK, KC_PAST, KC_PSLS,
        KC_NO,   KC_PAUS, KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,    KC_END,  KC_INS,  KC_DEL,     KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_NO,   KC_NO,   KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,                     KC_UP,               KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_PSCR, KC_NO,   KC_LSFT, JM_GRLS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,            KC_LEFT, KC_HOME, KC_RIGHT,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MO(10),  KC_LGUI, KC_LCTL, KC_LALT,                                        KC_SPC,                            KC_RALT, KC_RCTL,                     KC_DOWN,             KC_P0,            KC_PDOT
    ),

 // PC/3270 layout: 3270 legends (black), with x3270 keycodes
    [1] = LAYOUT(
                           JM_F13,  JM_F14,  JM_F15, JM_F16, JM_F17, JM_F18, JM_F19, JM_F20, JM_F21, JM_F22,  JM_F23,  JM_F24,
                           KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10,  KC_F11,  KC_F12,
        JM_ATTN,  JM_CLR,  KC_GRV,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   JM_PA1,  JM_PA2,  JM_JUMP,    KC_NO,   KC_NO,   KC_PCMM, KC_SPC,
        KC_CRSEL, KC_PAUS, KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    JM_CENT, KC_BSLS, JM_NLIN,   JM_BTAB, KC_INS,  JM_DEL,     KC_P7,   KC_P8,   KC_P9,   KC_TAB,
        KC_EXSEL, JM_EEOF, KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, JM_CBRC,                     KC_UP,               KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
        KC_PSCR,  JM_COPY, KC_LSFT, JM_GRLS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   JM_COMM, JM_DOT,  KC_SLSH, KC_RSFT,            KC_LEFT, JM_HOME, KC_RIGHT,   KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MO(10),   KC_LGUI, JM_RSET, KC_LALT,                                        KC_SPC,                            KC_RALT, KC_ENT,                      KC_DOWN,             KC_P0,            KC_PDOT
    ),

// Function layer, accessed by the Zoom key
    [10] = LAYOUT(
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        DF(0),    DF(1),    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                                              MO(11),                             KC_TRNS, KC_TRNS,                    KC_TRNS,            KC_TRNS,          KC_TRNS
    ),

// Firmware layer, accessed by the Zoom/Space key pair (hold both down)
    [11] = LAYOUT(
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, EEP_RST, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, DEBUG,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,                                              KC_TRNS,                            KC_TRNS, KC_TRNS,                    KC_TRNS,            KC_TRNS,          KC_TRNS
    ),
};

bool left_shift_down = false;
bool right_shift_down = false;
bool left_alt_down = false;
bool right_alt_down = false;
bool left_ctrl_down = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LSHIFT:
        if (record->event.pressed) {
            left_shift_down = true;
        return true;
        } else {
            left_shift_down = false;
            return true;
        }
        break;
        case KC_RSHIFT:
        if (record->event.pressed) {
            right_shift_down = true;
            return true;
        } else {
            right_shift_down = false;
            return true;
        }
        break;
        case KC_LALT:
        if (record->event.pressed) {
            left_alt_down = true;
            return true;
        } else {
            left_alt_down = false;
            return true;
        }
        break;
        case KC_RALT:
        if (record->event.pressed) {
            right_alt_down = true;
            return true;
        } else {
            right_alt_down = false;
            return true;
        }
        break;
        case KC_LCTL:
        if (record->event.pressed) {
            left_ctrl_down = true;
            return true;
        } else {
            left_ctrl_down = false;
            return true;
        }
        break;
        case JM_GRLS:
        if (left_shift_down || right_shift_down) {
            if(record->event.pressed) {
                SEND_STRING(">");
            }
            return false;
        } else {
            if(record->event.pressed) {
                SEND_STRING("<");
            }
            return false;
        }
        break;
        case JM_CBRC:
        if (left_shift_down || right_shift_down) {
            if (record->event.pressed) {
                SEND_STRING("}");
            }
            return false;
        } else {
            if(record->event.pressed) {
                SEND_STRING("{");
            }
            return false;
        }
        break;
        case JM_CENT:
        if (left_shift_down || right_shift_down) {
            if (record->event.pressed) {
                SEND_STRING("!");
            }
            return false;
        } else {
            if (record->event.pressed) {
                SEND_STRING("<");  // TODO: what does tn3270 want for a cent sign?
            }
            return false;
        }
        break;
        case JM_COMM:
        if (record->event.pressed){
            SEND_STRING(",");
        }
        return false;
        case JM_DOT:
        if (record->event.pressed) {
            SEND_STRING(".");
        }
        return false;
        case JM_NLIN:
        if (record->event.pressed) {
            register_code(KC_LSHIFT);
            register_code(KC_ENTER);
            unregister_code(KC_ENTER);
            if (!left_shift_down) {
                unregister_code(KC_LSHIFT);
            }
        }
        return false;
        case JM_RSET:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("r");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_PA1:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("1");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_PA2:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("2");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_BTAB:
        if (record->event.pressed) {
            register_code(KC_LSHIFT);
            register_code(KC_TAB);
            unregister_code(KC_TAB);
            if (!left_shift_down) {
                unregister_code(KC_LSHIFT);
            }
        }
        return false;
        case JM_JUMP:
        if (record->event.pressed) {
            if (left_alt_down || right_alt_down) {
                SEND_STRING("3");
            }
        }
        return false;
        case JM_ATTN:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("a");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_CLR:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("c");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_EEOF:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("e");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_HOME:
        if (record->event.pressed) {
            register_code(KC_LALT);
            SEND_STRING("h");
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_DEL:
        if (record->event.pressed) {
            if (left_alt_down || right_alt_down) {
                unregister_code(KC_LALT);
                unregister_code(KC_RALT);
                register_code(KC_LCTL);
                SEND_STRING("w");
                if (!left_ctrl_down) {
                   unregister_code(KC_LCTL);
                }
                if (left_alt_down) {
                    register_code(KC_LALT);
                }
                if (right_alt_down) {
                    register_code(KC_RALT);
                }
            } else {
                register_code(KC_DEL);
                unregister_code(KC_DEL);
            }
        }
        return false;
        case JM_F13:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F1);
            unregister_code(KC_F1);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F14:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F2);
            unregister_code(KC_F2);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F15:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F3);
            unregister_code(KC_F3);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F16:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F4);
            unregister_code(KC_F4);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F17:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F5);
            unregister_code(KC_F5);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F18:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F6);
            unregister_code(KC_F6);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F19:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F7);
            unregister_code(KC_F7);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F20:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F8);
            unregister_code(KC_F8);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F21:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F9);
            unregister_code(KC_F9);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F22:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F10);
            unregister_code(KC_F10);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F23:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F11);
            unregister_code(KC_F11);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
        case JM_F24:
        if (record->event.pressed) {
            register_code(KC_LALT);
            register_code(KC_F12);
            unregister_code(KC_F12);
            if (!left_alt_down) {
                unregister_code(KC_LALT);
            }
        }
        return false;
    }

    return true;
}
