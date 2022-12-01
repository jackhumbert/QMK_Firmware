/* Copyright 2020 Brandon Schlack
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
#include "brandonschlack.h"

/**
 * Layer Names
 *
 * Layers mostly used for macro keys
 */
#define _REEDER      _M1
#define _MAIL        _M2
#define _REEDER_FN   _M1_FN1
#define _MAIL_FN     _M2_FN1

/**
 * Keycodes & Macros
 */
#define TG_BASE   TO(_BASE)
#define TG_REDR   TO(_REEDER)
#define TG_MAIL   TO(_MAIL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │Ply│ │Esc│! 1│@ 2│# 3│$ 4│% 5│^ 6│         │& 7│* 8│( 9│) 0│_ -│+ =│| \│~ `│
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │VlU│ │Tab  │ Q │ W │ E │ R │ T │         │ Y │ U │ I │ O │ P │{ [│} ]│ Bspc│
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │VlD│ │HyCaps│ A │ S │ D │ F │ G │         │ H │ J │ K │ L │: ;│" '│   Enter│
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │LShift  │ Z │ X │ C │ V │ B │     │ B │ N │ M │< ,│> .│? /│  Shft│Fn │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │Opt  │     │Cmd  │Spc/Lwr│Ctrl│   │   Spc/Rai│  Cmd│           │  Opt│
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_BASE] = LAYOUT_all( \
    KC_MPLY, KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  \
    KC_VOLU, KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    KC_VOLD, HY_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  \
             KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  LOWER,   KC_RSFT, KC_SLSH, \
             KC_LOPT,          KC_LCMD,     SPC_LWR,      KC_LCTL,          SPC_RAI,          KC_RCMD,                   KC_ROPT \
),
/* Reeder
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │ H │ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │ K │ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │ J │ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_REEDER] = LAYOUT_all( \
    KC_H,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_K,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_J,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
/* Mail
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │Del│ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │It+│ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │It-│ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_MAIL] = LAYOUT_all( \
    G(KC_BSPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_DOWN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
/* Lower
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │Mut│ │Mke│ F1│ F2│ F3│ F4│ F5│ F6│         │ F7│ F8│ F9│F10│F11│F12│LHP│SLP│
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │Nxt│ │RMod │RH+│RS+│RV+│Sp+│   │         │   │   │   │   │PgU│Hom│End│  Del│
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │Prv│ │RTgl  │RH-│RS-│RV-│Sp-│   │         │   │   │Prv│Nxt│PgD│ ↑ │   Play │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │LYR│Thm│   │   │   │     │   │   │   │   │ ← │ ↓ │→ Shft│   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_LOWER] = LAYOUT_all( \
    KC_MUTE, QM_MAKE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  MC_LHPD, MC_SLPD, \
    KC_MNXT, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_END,  KC_DEL,  \
    KC_MPRV, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, KC_MPRV, KC_MNXT, KC_PGDN, KC_UP,            KC_MPLY, \
             _______, RGB_LYR, RGB_THM, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, _______, RGT_SFT, KC_DOWN, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
/* Reeder Function
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │ L │ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │ P │ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │ N │ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_REEDER_FN] = LAYOUT_all( \
    KC_L,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_P,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_N,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
/* Mail
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │Del│ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │It+│ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │It-│ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_MAIL_FN] = LAYOUT_all( \
    KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    A(G(KC_LBRC)),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    A(G(KC_RBRC)), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
/* Raise
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │   │ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │   │ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_RAISE] = LAYOUT_all( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

),
/* Adjust
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │Bse│ │Mke│   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │Rdr│ │RMod │RH+│RS+│RV+│Sp+│   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │Mai│ │RTgl  │RH-│RS-│RV-│Sp-│   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │LYR│Thm│   │EEP│Rst│     │Rst│   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
[_ADJUST] = LAYOUT_all( \
    TG_BASE, QM_MAKE, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    TG_REDR, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    TG_MAIL, RGB_TOG, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, RGB_LYR, RGB_THM, _______, EE_CLR,  QK_BOOT, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

)
/* Layout
 * ┌───┐ ┌───┬───┬───┬───┬───┬───┬───┐         ┌───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │ │   │   │   │   │   │   │   │         │   │   │   │   │   │   │   │   │
 * ├───┤ ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┘       ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤
 * │   │ │     │   │   │   │   │   │         │   │   │   │   │   │   │   │     │
 * ├───┤ ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐        └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
 * │   │ │      │   │   │   │   │   │         │   │   │   │   │   │   │        │
 * └───┘ ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┐     ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┤
 *       │        │   │   │   │   │   │     │   │   │   │   │   │   │      │   │
 *       ├─────┬──┴──┬┴───┴┬──┴───┴┬──┴─┐   ├───┴───┴──┬┴───┴┬──┴───┴────┬─┴───┤
 *       │     │     │     │       │    │   │          │     │           │     │
 *       └─────┘     └─────┴───────┴────┘   └──────────┴─────┘           └─────┘
 */
/*
[_BLANK] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
             _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
             _______,          _______,     _______,      _______,          _______,          _______,                   _______ \

)
*/
};

layer_state_t layer_state_set_keymap(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER,  _RAISE, _ADJUST);
    state = update_tri_layer_state(state, _REEDER, _LOWER, _REEDER_FN);
    state = update_tri_layer_state(state, _MAIL,   _LOWER, _MAIL_FN);
    return state;
}

#ifdef USE_LEDS_FOR_LAYERS
bool led_update_keymap(led_t led_state) {
    writePin(TOP_LED, LED_ON(IS_LAYER_ON(_REEDER) || IS_LAYER_ON(_MAIL))); // Use for Macro Layer
    writePin(MIDDLE_LED, LED_ON(IS_LAYER_ON(_FN1))); // Use for Layer 2
    writePin(BOTTOM_LED, LED_ON(led_state.caps_lock)); // Use for Caps Lock
    return false; // Override default set by KB
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RGHT);
        }
    }
    else if (index == 2) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    }
    return true;
}

  #endif
