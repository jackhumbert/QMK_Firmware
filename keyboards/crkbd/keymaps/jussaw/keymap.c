/*
Copyright 2019 @foostan
Copyrig2ht 2020 Drashna Jaelre <@drashna>

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
#include <stdio.h>

enum layers {
    _QWERTY,
    _COLEMAKDH,
    _LOWER,
    _UPPER,
    _ADJUST,
    _GAME,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAKDH,
    LOWER,
    UPPER,
    ADJUST,
    GAME,
};

enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
} td_state_t;

#define LOWER MO(_LOWER)
#define UPPER MO(_UPPER)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
   * |  Tab   |    Q   |    W   |    E   |    R   |    T   |                    |    Y   |    U   |    I   |    O   |    P   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |  Esc   | LGUI,A | LALT,S | LCTL,D | LSFT,F |    G   |                    |    H   | RSFT,J | RCTL,K | RALT,L | RGUI,; |   ""   |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |        |    Z   |    X   |    C   |    V   |    B   |                    |    N   |    M   |    ,   |    .   |    /   | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                     |        | Lower  | Space  |  |        | Upper  |        |
   *                                     `--------------------------'  `--------------------------'
   */
  [_QWERTY] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
    //    KC_ESC,MT(MOD_LGUI, KC_A),MT(MOD_LALT,KC_S),MT(MOD_LCTL, KC_D),MT(MOD_LSFT, KC_F),    KC_G, KC_H,MT(MOD_RSFT,KC_J),MT(MOD_RCTL,KC_K),MT(MOD_RALT, KC_L),MT(MOD_RGUI,KC_SCLN), KC_QUOT,
      KC_ESC,LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,              KC_H,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN), KC_QUOT,
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                          XXXXXXX,   LOWER,  KC_SPC,    XXXXXXX,   UPPER,  XXXXXXX
  ),

  /* Colemak Mod-DH
   * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
   * |  Tab   |    Q   |    W   |    F   |    P   |    B   |                    |    J   |    L   |    U   |    Y   |    ;   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |  Esc   |    A   |    R   |    S   |    T   |    G   |                    |    M   |    N   |    E   |    I   |    O   |   ""   |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |  Alt   |    Z   |    X   |    C   |    D   |    V   |                    |    K   |    H   |    ,   |    .   |    /   | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                     |  Ctrl  | Lower  | Space  |  | Shift  | Upper  |  GUI   |
   *                                     `--------------------------'  `--------------------------'
   */
  [_COLEMAKDH] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
       KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
      KC_LALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                          KC_LCTL,   LOWER,  KC_SPC,    KC_RSFT,   UPPER, KC_RGUI
  ),

  /* Lower
   * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
   * |  Tab   |    !   |    @   |    #   |    $   |    %   |                    |    ^   |    &   |    *   |    (   |    )   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |   F11  |   F1   |   F2   |   F3   |   F4   |   F5   |                    |    `   |    -   |    =   |    [   |    ]   |   \    |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |   F12  |   F6   |   F7   |   F8   |   F9   |  F10   |                    |    ~   |    _   |    +   |    {   |    }   |   |    |
   * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                     |  Ctrl  | Trans  | Space  |  | Shift  | Adjust |  Alt   |
   *                                     `--------------------------'  `--------------------------'
   */
  [_LOWER] = LAYOUT_split_3x6_3(
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
       KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_GRV, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
       KC_F12,   KC_F5,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                          KC_LCTL, KC_TRNS,  KC_SPC,    KC_RSFT,  ADJUST, KC_RALT
  ),


  /* Upper
   * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
   * |  Tab   |    1   |    2   |    3   |    4   |    5   |                    |    6   |    7   |    8   |    9   |    0   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |  Del   |  LGUI  |  LALT  |  LCTL  |  LSFT  |        |                    |        |  Left  |  Down  |   Up   | Right  |   ""   |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |  Alt   |        |        |        |        |        |                    |        |  Home  |Pg Down | Pg Up  |  End   | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                     |  Ctrl  | Adjust | Space  |  | Shift  | Trans  |  GUI   |
   *                                     `--------------------------'  `--------------------------'
   */
  [_UPPER] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
       KC_DEL, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_QUOT,
      KC_LALT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_ENT,
                                          KC_LCTL,  ADJUST,  KC_SPC,    KC_RSFT, KC_TRNS, KC_RGUI
  ),


  /* Adjust
   * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
   * |  RESET |        |        |        |        |TG(GAME)|                    |  Play  |  Prev  |  Next  |        |        |        |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |DF(QWRT)|        |        | Mouse2 | Mouse1 |        |                    |  Vol+  |Ms Left |Ms Down | Ms Up  |Ms Right|        |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |DF(CMDH)|        |        | Mouse4 | Mouse5 |        |                    |  Vol-  | MsWl L | MsWl D | MsWl U | MsWl R |        |
   * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                     |        | Lower  |        |  |        | Upper  |        |
   *                                     `--------------------------'  `--------------------------'
   */
  [_ADJUST] = LAYOUT_split_3x6_3(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_GAME),                     KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
      DF(_QWERTY),XXXXXXX,XXXXXXX, KC_BTN2, KC_BTN1, XXXXXXX,                    KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,
      DF(_COLEMAKDH), XXXXXXX, XXXXXXX, KC_BTN4, KC_BTN5, XXXXXXX,               KC_VOLD, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
                                         XXXXXXX, KC_TRNS, XXXXXXX,     XXXXXXX, KC_TRNS, XXXXXXX
  ),


  /* Game
   * ,-----------------------------------------------------.                    ,-----------------------------------------------------.
   * |    T   |  Tab   |    Q   |    W   |    E   |    R   |                    |    Y   |    U   |    I   |    O   |    P   |  Bksp  |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |    G   |  Shift |    A   |    S   |    D   |    F   |                    |    H   |    J   |    K   |    L   |    ;   |   ""   |
   * |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   * |    B   |  Ctrl  |    Z   |    X   |    C   |    V   |                    |    N   |    M   |    ,   |    .   |    /   | Enter  |
   * |--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
   *                                     |   Esc  |  Alt   | Space  |  |        |        |TG(GAME)|
   *                                     `--------------------------'  `--------------------------'
   */
  [_GAME] = LAYOUT_split_3x6_3(
         KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
         KC_G,  KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
         KC_B,  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,
                                           KC_ESC, KC_LALT, KC_SPC,     XXXXXXX, XXXXXXX,    TG(_GAME)
  ),
};
