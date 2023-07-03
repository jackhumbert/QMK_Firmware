/* Copyright 2020 Christopher Ko <chriskopher@gmail.com>
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

#include "shared_enum.h"

#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Modified Qwerty for chriskopher: base default layer
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
     * `---'   `---------------' `---------------' `---------------' `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   \   | |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  Bsp| |Del|End|PgD| |  7|  8|  9|   |
     * |-----------------------------------------------------------| `-----------' |-----------|   |
     * |Ctl/Esc|  A|  S|  D|  F|  G|  H|  J|  K| L|;/:| ' |  Return|               |  4|  5|  6|  +|
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shift/( |Dev/Z| X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift/)|     | ↑ |     |  1|  2|  3|   |
     * |-----------------------------------------------------------| ,-----------. |-----------|   |
     * |Meh/CapsL|Gui|Alt|     Space       |Alt|Adjust/Gui|App| Ctl| | ← | ↓ | → | |      0|  .|Ent|
     * `-----------------------------------------------------------' `-----------' `---------------'
    */
    [_CKO] = LAYOUT_fullsize_ansi(
        KC_ESC,                           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,        KC_F10,   KC_F11,    KC_F12,              KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,           KC_1,           KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,         KC_MINS,  KC_EQL,    KC_BSLS,    KC_INS,  KC_HOME, KC_PGUP,            KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,           KC_Q,           KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,         KC_LBRC,  KC_RBRC,   KC_BSPC,    KC_DEL,  KC_END,  KC_PGDN,            KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        LCTL_T(KC_ESC),   KC_A,           KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    TD(SCLN_CLN), KC_QUOT,             KC_ENT,                                           KC_P4,   KC_P5,   KC_P6,
        TD(ESPC_L),       LT(_DEV,KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,                           TD(ESPC_R),          KC_UP,                       KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        MEH_T(KC_CAPS), KC_LGUI, KC_LALT,                   KC_SPC,                                   KC_RALT, LT(_ADJUST,KC_RGUI),      KC_APP,  KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT,            KC_P0,            KC_PDOT
    ),

    /* Regular Qwerty: default layer
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
     * `---'   `---------------' `---------------' `---------------' `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|   |
     * |-----------------------------------------------------------| `-----------' |-----------|   |
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     | ↑ |     |  1|  2|  3|   |
     * |-----------------------------------------------------------| ,-----------. |-----------|   |
     * |Ctl|Gui|Alt|           Space        |Alt|Adjust/Gui|App|Ctl| | ← | ↓ | → | |      0|  .|Ent|
     * `-----------------------------------------------------------' `-----------' `---------------'
    */
    [_QWERTY] = LAYOUT_fullsize_ansi(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,   KC_F12,             KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,   KC_BSPC,   KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC,   KC_RBRC,  KC_BSLS,   KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,                                  KC_P4,   KC_P5,   KC_P6,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,                      KC_RSFT,            KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                         KC_RALT,  LT(_ADJUST,KC_RGUI), KC_APP,  KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),

    /* SuperDuper
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
     * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |   |   |
     * `---'   `---------------' `---------------' `---------------' `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   | |   |   |   |   |
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |     |   |   |   |   |   |   |1T |T← |T→ |9T |   |    |    | |   |   |   | |   |   |   |   |
     * |-----------------------------------------------------------| `-----------' |-----------|   |
     * |      |Alt|[SuperDuper]|Bksp|Ctl| ← | ↓ | ↑ | → |Del|   |  |               |   |   |   |   |
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |        |   |   |   |   |   |   |   |   |   |ToggleSD|     |     |   |     |   |   |   |   |
     * |-----------------------------------------------------------| ,-----------. |-----------|   |
     * |   |   |   |             Shift             |   |   |   |   | |   |   |   | |       |   |   |
     * `-----------------------------------------------------------' `-----------' `---------------'
    */
    [_SUPERDUPER] = LAYOUT_fullsize_ansi(
        _______,          _______, _______, _______, _______, _______, _______, _______,      _______,    _______,   _______, _______, _______,              _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,    _______,   _______, _______,          _______,     _______, _______, _______,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, C(KC_1), C(S(KC_TAB)), C(KC_TAB),  C(KC_9),   _______, _______,          _______,     _______, _______, _______,    _______, _______, _______, _______,
        _______, KC_LALT, _______, _______, KC_BSPC, KC_LCTL, KC_LEFT, KC_DOWN, KC_UP,        KC_RIGHT,   KC_DEL,    _______,                   _______,                                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______,    TG(_SUPERDUPER),                      _______,              _______,             _______, _______, _______, _______,
        _______, _______, _______,                   KC_LSFT,                                                        _______, _______, _______, _______,     _______, _______, _______,    _______,          _______
    ),

    /* Dev
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
     * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |   |   |
     * `---'   `---------------' `---------------' `---------------' `-----------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   | |   |   |   |   |
     * |-----------------------------------------------------------| |-----------| |---------------|
     * |     |   |   |   |   |   |   | - | + | ( | ) |   |   |     | |   |   |   | |   |   |   |   |
     * |-----------------------------------------------------------| `-----------' |-----------|   |
     * |      |   |   |   |   |   | _ | [ | ] | { | } |   |        |               |   |   |   |   |
     * |-----------------------------------------------------------|     ,---.     |---------------|
     * |        |   |   |   |   |   | = | | | < | > | ? |          |     |   |     |   |   |   |   |
     * |-----------------------------------------------------------| ,-----------. |-----------|   |
     * |   |   |   |                               |   |   |   |   | |   |   |   | |       |   |   |
     * `-----------------------------------------------------------' `-----------' `---------------'
    */
    [_DEV] = LAYOUT_fullsize_ansi(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                           _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                       _______,     _______, _______, _______,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, S(KC_EQL), S(KC_9), S(KC_0),  _______, _______,                    _______,     _______, _______, _______,    _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, S(KC_MINS), KC_LBRC, KC_RBRC, S(KC_LBRC), S(KC_RBRC),  _______,                      _______,                                   _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_EQL, S(KC_BSLS), S(KC_COMM), S(KC_DOT), S(KC_SLSH),                               _______,              _______,             _______, _______, _______, _______,
        _______, _______, _______,                   _______,                                                           _______, _______, _______, _______,     _______, _______, _______,    _______,          _______
    ),

    /* Adjust
     * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
     * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |   |   |
     * `---'   `---------------' `---------------' `---------------' `-----------'
     * ,-----------------------------------------------------------. ,--------------. ,---------------.
     * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |Play|Next|VolU| |   |   |   |   |
     * |-----------------------------------------------------------| |--------------| |---------------|
     * |     |QWERTY|   |   |   |   |   |   |   |   |   |   |  |   | |Stop|Prev|VolD| |   |   |   |   |
     * |-----------------------------------------------------------| `--------------' |-----------|   |
     * |      |   |   |   |   |   |   |   |   |   |   |   |        |                  |   |   |   |   |
     * |-----------------------------------------------------------|     ,---.        |---------------|
     * |        |   |   |CKO|   |   |  |Play|Mute|VolD|VolU| SD|   |     |   |        |   |   |   |   |
     * |-----------------------------------------------------------| ,-----------.    |-----------|   |
     * |   |   |   |                               |   |   |   |   | |   |   |   |    |       |   |   |
     * `-----------------------------------------------------------' `-----------'    `---------------'
    */
    [_ADJUST] = LAYOUT_fullsize_ansi(
        _______,               _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,
        _______, _______,      _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     KC_MPLY, KC_MNXT, KC_VOLU,    _______, _______, _______, _______,
        _______, DF(_QWERTY),  _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     KC_MSTP, KC_MPRV, KC_VOLD,    _______, _______, _______, _______,
        _______, _______,      _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                   _______, _______, _______,
        _______, _______,      _______, DF(_CKO),  _______, _______, KC_MPLY,  KC_MUTE, KC_VOLD, KC_VOLU, TG(_SUPERDUPER),                   _______,              _______,             _______, _______, _______, _______,
        _______, _______,      _______,                     _______,                                              _______, _______, _______, _______,     _______, _______, _______,    _______,          _______
    )

/* Empty layout for future reference
  * ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
  * |   |   |   |   |   |   | |   |   |   |   | |   |   |   |   | |   |   |   |
  * `---'   `---------------' `---------------' `---------------' `-----------'
  * ,-----------------------------------------------------------. ,-----------. ,---------------.
  * |   |   |   |   |   |   |   |   |   |   |   |   |   |       | |   |   |   | |   |   |   |   |
  * |-----------------------------------------------------------| |-----------| |---------------|
  * |     |   |   |   |   |   |   |   |   |   |   |   |   |     | |   |   |   | |   |   |   |   |
  * |-----------------------------------------------------------| `-----------' |-----------|   |
  * |      |   |   |   |   |   |   |   |   |   |   |   |        |               |   |   |   |   |
  * |-----------------------------------------------------------|     ,---.     |---------------|
  * |        |   |   |   |   |   |   |   |   |   |   |          |     |   |     |   |   |   |   |
  * |-----------------------------------------------------------| ,-----------. |-----------|   |
  * |   |   |   |                               |   |   |   |   | |   |   |   | |       |   |   |
  * `-----------------------------------------------------------' `-----------' `---------------'
 */
 /*
  *  [_EMPTY] = LAYOUT_fullsize_ansi(
  *      _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,              _______, _______, _______,
  *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     _______, _______, _______,    _______, _______, _______, _______,
  *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,     _______, _______, _______,    _______, _______, _______, _______,
  *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                                   _______, _______, _______,
  *      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                            _______,              _______,             _______, _______, _______, _______,
  *      _______, _______, _______,                   _______,                                              _______, _______, _______, _______,     _______, _______, _______,    _______,          _______
  *  ),
 */
};
// clang-format on

// Configure hold on other key press per key
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // I don't like how ignore interrupt feels with these keys specifically when I'm typing
        case LCTL_T(KC_ESC):
            return true;
        default:
            return false;
    }
}

enum combo_event {
    SD_LAYER_COMBO,
    KL_MEH_COMBO,
};

const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};  // Combo: S + D for SuperDuper mode
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};  // Combo: K + L for Meh modifier

// Register the combo action
combo_t key_combos[] = {
    [SD_LAYER_COMBO] = COMBO_ACTION(sd_combo),
    [KL_MEH_COMBO]   = COMBO_ACTION(kl_combo),
};

// Called after a combo event is triggered
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case SD_LAYER_COMBO:
            if (pressed) {
                layer_on(_SUPERDUPER);
            } else {
                layer_off(_SUPERDUPER);
            }
            break;

        case KL_MEH_COMBO:
            if (pressed) {
                register_mods(MOD_MEH);
            } else {
                unregister_mods(MOD_MEH);
            }
            break;
    }
}
