/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#include "gotham.h"

/*
 * The `LAYOUT_lily58_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

// clang-format off
#define LAYOUT_lily58_base( \
        K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
        K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
        K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
        K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A  \
    ) \
    LAYOUT_wrapper( \
        KC_GRV,  K01, K02, K03, K04, K05,                    K06, K07, K08, K09, K0A, KC_EQL,  \
        KC_ESC,  K11, K12, K13, K14, K15,                    K16, K17, K18, K19, K1A, KC_BSLS, \
        KC_LSFT, K21, K22, K23, K24, K25,                    K26, K27, K28, K29, K2A, RSFT_T(KC_QUOT), \
        KC_LCTL, K31, K32, K33, K34, K35, KC_CCCV,  KC_APP,  K36, K37, K38, K39, K3A, RCTL_T(KC_MINS), \
               KC_LGUI, KC_LALT, SP_LOWR, TB_RAIS,  EN_LOWR, BK_RAIS, MS_DEL, KC_EQL \
    )
/* Re-pass though to allow templates to be used */
#define LAYOUT_lily58_base_wrapper(...) LAYOUT_lily58_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
        _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
        _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
    ),

    [_DVORAK] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),

    [_WORKMAN] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________WORKMAN_L1________________, _________________WORKMAN_R1________________,
        _________________WORKMAN_L2________________, _________________WORKMAN_R2________________,
        _________________WORKMAN_L3________________, _________________WORKMAN_R3________________
    ),

    [_NORMAN] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________NORMAN_L1_________________, _________________NORMAN_R1_________________,
        _________________NORMAN_L2_________________, _________________NORMAN_R2_________________,
        _________________NORMAN_L3_________________, _________________NORMAN_R3_________________
    ),

    [_GAME] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        __________________GAME_L1__________________, _________________QWERTY_R1_________________,
        __________________GAME_L2__________________, _________________QWERTY_R2_________________,
        __________________GAME_L3__________________, _________________QWERTY_R3_________________
    ),

    [_GAMENAV] = LAYOUT_lily58_base_wrapper(
        ___________________BLANK___________________, ___________________BLANK___________________,
        ___________________BLANK___________________, _______, _______, KC_UP,   _______, _______,
        ___________________BLANK___________________, _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______,
        ___________________BLANK___________________, _______, _______, _______, _______, _______
    ),

    [_GAMENUM] = LAYOUT_lily58_base_wrapper(
        __________________FN_LEFT__________________, __________________FN_RIGHT_________________,
        ___________________BLANK___________________, _______, _______, _______,  KC_F11,  KC_F12,
        ___________________BLANK___________________, ___________________BLANK___________________,
        ___________________BLANK___________________, ___________________BLANK___________________
    ),

    [_GAMENUM] = LAYOUT_lily58_base_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        KC_NO,   KC_1,   KC_2,   KC_3,   KC_NO,      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F10,
        KC_0,    KC_4,   KC_5,   KC_6,   KC_NO,      KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_F11,
        KC_NO,   KC_7,   KC_8,   KC_9,   KC_NO,      KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F12
    ),

    [_LOWER] = LAYOUT_lily58_base_wrapper(
        ___________________BLANK___________________, ___________________BLANK___________________,
        _________________LOWER_L1__________________, _________________LOWER_R1__________________,
        _________________LOWER_L2__________________, _________________LOWER_R2__________________,
        _________________LOWER_L3__________________, _________________LOWER_R3__________________
    ),

    [_RAISE] = LAYOUT_lily58_base_wrapper(
        ___________________BLANK___________________, ___________________BLANK___________________,
        _________________RAISE_L1__________________, _________________RAISE_R1__________________,
        _________________RAISE_L2__________________, _________________RAISE_R2__________________,
        _________________RAISE_L3__________________, _________________RAISE_R3__________________
    ),

    [_ADJUST] = LAYOUT_lily58_base_wrapper(
        ___________________BLANK___________________, ___________________BLANK___________________,
        _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,
        _________________ADJUST_L2_________________, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________, _________________ADJUST_R3_________________
    ),

    [_MOUSE] = LAYOUT_lily58_base_wrapper(
        ___________________BLANK___________________, ___________________BLANK___________________,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   __________________MOUSE1___________________,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   __________________MOUSE2___________________,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   __________________MOUSE3___________________
    ),
};
// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }
