/* Copyright 2020 José Andrés García
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

// Sendstring lookup tables for Spanish Dvorak layout

#pragma once

#include "keymap_spanish_dvorak.h"
#include "quantum.h"

// clang-format off

const uint8_t ascii_to_shift_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 1, 1, 0, 1, 1, 1, 0),
    KCLUT_ENTRY(1, 1, 1, 0, 0, 0, 0, 1),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 1, 1, 0, 1, 1, 1),
    KCLUT_ENTRY(0, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 0, 0, 0, 1, 1),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0)
};

const uint8_t ascii_to_altgr_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 0, 0, 1, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(1, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 1, 1, 1, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 1, 1, 1, 1, 0)
};

const uint8_t ascii_to_keycode_lut[128] PROGMEM = {
    // NUL   SOH      STX      ETX      EOT      ENQ      ACK      BEL
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // BS    TAB      LF       VT       FF       CR       SO       SI
    KC_BSPC, KC_TAB,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // DLE   DC1      DC2      DC3      DC4      NAK      SYN      ETB
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // CAN   EM       SUB      ESC      FS       GS       RS       US
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    //       !        "        #        $        %        &        '
    KC_SPC,  DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    DV_6,    DV_QUOT,
    // (     )        *        +        ,        -        .        /
    DV_8,    DV_9,    DV_PLUS, DV_PLUS, DV_COMM, DV_MINS, DV_DOT,  DV_7,
    // 0     1        2        3        4        5        6        7
    DV_0,    DV_1,    DV_2,    DV_3,    DV_4,    DV_5,    DV_6,    DV_7,
    // 8     9        :        ;        <        =        >        ?
    DV_8,    DV_9,    DV_DOT,  DV_COMM, DV_LABK, DV_0,    DV_LABK, DV_QUOT,
    // @     A        B        C        D        E        F        G
    DV_2,    DV_A,    DV_B,    DV_C,    DV_D,    DV_E,    DV_F,    DV_G,
    // H     I        J        K        L        M        N        O
    DV_H,    DV_I,    DV_J,    DV_K,    DV_L,    DV_M,    DV_N,    DV_O,
    // P     Q        R        S        T        U        V        W
    DV_P,    DV_Q,    DV_R,    DV_S,    DV_T,    DV_U,    DV_V,    DV_W,
    // X     Y        Z        [        \        ]        ^        _
    DV_X,    DV_Y,    DV_Z,    DV_GRV,  DV_MORD, DV_PLUS, DV_GRV,  DV_MINS,
    // `     a        b        c        d        e        f        g
    DV_GRV,  DV_A,    DV_B,    DV_C,    DV_D,    DV_E,    DV_F,    DV_G,
    // h     i        j        k        l        m        n        o
    DV_H,    DV_I,    DV_J,    DV_K,    DV_L,    DV_M,    DV_N,    DV_O,
    // p     q        r        s        t        u        v        w
    DV_P,    DV_Q,    DV_R,    DV_S,    DV_T,    DV_U,    DV_V,    DV_W,
    // x     y        z        {        |        }        ~        DEL
    DV_X,    DV_Y,    DV_Z,    DV_ACUT, DV_1,    DV_CCED, DV_4,    KC_DEL
};
