/* Copyright 2022 IFo Hancroft
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Default Layer
    * *---------------------------------------------------------------------*                             *---------------------------------------------------------------------*
    * | `       | 1       | 2       | 3       | 4       | 5       | -       |                             | =       | 6       | 7       | 8       | 9       | 0       | Del     |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * | Tab     | Q       | W       | E       | R       | T       | [       |                             | ]       | Y       | U       | I       | O       | P       | \       |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * | ESC     | A       | S       | D       | F       | G       |         |                             |         | H       | J       | K       | L       | ;       | '       |
    * |---------+---------+---------+---------+---------+---------+---------*                             *---------+---------+---------+---------+---------+---------+---------|
    * | Shift   | Z       | X       | C       | V       | B       |                                                 | N       | M       | ,       | .       | /       | Shift   |
    * |---------+---------+---------+---------+---------+---------*                                                 *---------+---------+---------+---------+---------+---------|
    * | Ctrl    | Super   | Alt     |         | OSL(1)  |                                                                     | MO(1)   | TT(1)   | Alt     | Super   | Ctrl    |
    * *-------------------------------------------------*                                                                     *-------------------------------------------------*
    *
    *                                                             *-------------------*         *-------------------*
    *                                                             |         |         |         |         |         |
    *                                                   *---------+---------+---------|         |---------+---------+---------*
    *                                                   |         |         |         |         |         |         |         |
    *                                                   | Bckspc  | Enter   |---------|         |---------| Enter   | Space   |
    *                                                   |         |         | SH_OS   |         |         |         |         |
    *                                                   *---------+---------+---------*         *---------+---------+---------*
    */

    LAYOUT_ergodox_pretty(
        KC_GRV,   KC_1,     KC_2,     KC_3,    KC_4,      KC_5,     KC_MINS,                                KC_EQL,   KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,     KC_LBRC,                                KC_RBRC,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
        KC_ESC,   KC_A,     KC_S,     KC_D,    KC_F,      KC_G,                                                       KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,      KC_B,     KC_NO,                                  KC_NO,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
        KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,   OSL(1),                                                                          MO(1),    TT(1),    KC_RALT,  KC_RGUI,  KC_RCTL,

                                                                    KC_NO,    KC_NO,              KC_NO,    KC_NO,
                                                                              KC_NO,              KC_NO,
                                                          KC_BSPC,  KC_ENT,   SH_OS,              KC_NO,    KC_ENT,   KC_SPC
    ),

    /* Function Keys Layer
    * *---------------------------------------------------------------------*                             *---------------------------------------------------------------------*
    * | NumLock | F1      | F2      | F3      | F4      | F5      | F11     |                             | F12     | F6      | F7      | F8      | F9      | F10     |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * |         | +       | 7       | 8       | 9       | *       |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * |         | -       | 4       | 5       | 6       | /       |         |                             |         | Left    | Down    | Up      | Right   |         |         |
    * |---------+---------+---------+---------+---------+---------+---------*                             *---------+---------+---------+---------+---------+---------+---------|
    * |         | 0       | 1       | 2       | 3       | .       |                                                 | NK_TOGG |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------*                                                 *---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |                                                                     |         | Left    | Down    | Up      | Right   |
    * *-------------------------------------------------*                                                                     *-------------------------------------------------*
    *
    *                                                             *-------------------*         *-------------------*
    *                                                             |         |         |         |         |         |
    *                                                   *---------+---------+---------|         |---------+---------+---------*
    *                                                   |         |         |         |         |         |         |         |
    *                                                   |         | Enter   |---------|         |---------|         |         |
    *                                                   |         |         | PgUp    |         | PgDn    |         |         |
    *                                                   *---------+---------+---------*         *---------+---------+---------*
    */

    LAYOUT_ergodox_pretty(
        KC_NUM,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,                                 KC_F12,   KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,
        _______,  KC_PPLS,  KC_P7,    KC_P8,    KC_P9,    KC_PAST,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_PMNS,  KC_P4,    KC_P5,    KC_P6,    KC_PSLS,                                                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,
        _______,  KC_P0,    KC_P1,    KC_P2,    KC_P3,    KC_PDOT,  _______,                                _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,                                                                        _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,

                                                                    _______,  _______,            _______,  _______,
                                                                              _______,            _______,
                                                          _______,  KC_PENT,  KC_PGUP,            KC_PGDN,  _______,  _______
    ),

    /* Empty Layer
    * *---------------------------------------------------------------------*                             *---------------------------------------------------------------------*
    * |         |         |         |         |         |         |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |         |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |         |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------*                             *---------+---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |         |                                                 |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------*                                                 *---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |                                                                     |         |         |         |         |         |
    * *-------------------------------------------------*                                                                     *-------------------------------------------------*
    *
    *                                                             *-------------------*         *-------------------*
    *                                                             |         |         |         |         |         |
    *                                                   *---------+---------+---------|         |---------+---------+---------*
    *                                                   |         |         |         |         |         |         |         |
    *                                                   |         |         |---------|         |---------|         |         |
    *                                                   |         |         |         |         |         |         |         |
    *                                                   *---------+---------+---------*         *---------+---------+---------*
    */

    LAYOUT_ergodox_pretty(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,                                                                        _______,  _______,  _______,  _______,  _______,

                                                                    _______,  _______,            _______,  _______,
                                                                              _______,            _______,
                                                          _______,  _______,  _______,            _______,  _______,  _______
    ),

    /* Empty Layer
    * *---------------------------------------------------------------------*                             *---------------------------------------------------------------------*
    * |         |         |         |         |         |         |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |         |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |         |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------*                             *---------+---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |         |                                                 |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------*                                                 *---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |                                                                     |         |         |         |         |         |
    * *-------------------------------------------------*                                                                     *-------------------------------------------------*
    *
    *                                                             *-------------------*         *-------------------*
    *                                                             |         |         |         |         |         |
    *                                                   *---------+---------+---------|         |---------+---------+---------*
    *                                                   |         |         |         |         |         |         |         |
    *                                                   |         |         |---------|         |---------|         |         |
    *                                                   |         |         |         |         |         |         |         |
    *                                                   *---------+---------+---------*         *---------+---------+---------*
    */

    LAYOUT_ergodox_pretty(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,                                                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,                                                                        _______,  _______,  _______,  _______,  _______,

                                                                    _______,  _______,            _______,  _______,
                                                                              _______,            _______,
                                                          _______,  _______,  _______,            _______,  _______,  _______
    )
};

    /* Left Hand Layer
    * *---------------------------------------------------------------------*                             *---------------------------------------------------------------------*
    * | Del     | 6       | 7       | 8       | 9       | 0       | =       |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * | \       | Y       | U       | I       | O       | P       | ]       |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------|                             |---------+---------+---------+---------+---------+---------+---------|
    * | '       | H       | J       | K       | L       | ;       |         |                             |         |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------+---------*                             *---------+---------+---------+---------+---------+---------+---------|
    * |         | N       | M       | ,       | .       | /       |                                                 |         |         |         |         |         |         |
    * |---------+---------+---------+---------+---------+---------*                                                 *---------+---------+---------+---------+---------+---------|
    * |         |         |         |         |         |                                                                     |         |         |         |         |         |
    * *-------------------------------------------------*                                                                     *-------------------------------------------------*
    *
    *                                                             *-------------------*         *-------------------*
    *                                                             |         |         |         |         |         |
    *                                                   *---------+---------+---------|         |---------+---------+---------*
    *                                                   |         |         |         |         |         |         |         |
    *                                                   |         |         |---------|         |---------|         |         |
    *                                                   |         |         |         |         |         |         |         |
    *                                                   *---------+---------+---------*         *---------+---------+---------*
    */

/*const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
       {{13, 0},   {8, 0},   {9, 0},  {10, 0},  {11, 0},  {12, 0},   {7, 0},                                 {7, 0},   {8, 0},   {9, 0},   {10, 0},   {11, 0},   {12, 0},  {13, 0}},
       {{13, 1},   {8, 1},   {9, 1},  {10, 1},  {11, 1},  {12, 1},   {7, 1},                                 {7, 1},   {8, 1},   {9, 1},   {10, 1},   {11, 1},   {12, 1},  {13, 1}},
       {{13, 2},   {8, 2},   {9, 2},  {10, 2},  {11, 2},  {12, 2},                                                     {8, 2},   {9, 2},   {10, 2},   {11, 2},   {12, 2},  {13, 2}},
        {{0, 3},   {8, 3},   {9, 3},  {10, 3},  {11, 3},  {12, 3},   {7, 3},                                 {7, 3},   {8, 3},   {9, 3},   {10, 3},   {11, 3},   {12, 3},  {13, 3}},
        {{0, 4},   {1, 4},   {2, 4},  {3, 4},  {4, 4},                                                                           {9, 4},   {10, 4},   {11, 4},   {12, 4},  {13, 4}},

                                                                    {{5, 5},   {6, 5},             {7, 5},   {8, 5},
                                                                               {4, 5},             {9, 5},
                                                           {3, 5},   {2, 5},   {1, 5},            {12, 5},  {11, 5}, {10, 5}},
};
*/
