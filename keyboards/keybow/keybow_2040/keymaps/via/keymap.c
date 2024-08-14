/* Copyright 2024 Sandy Macdonald (https://github.com/sandyjmacdonald)
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

#define KC_LYR1 LT(1, KC_P0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_P7, KC_P8, KC_P9, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PAST, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_LYR1, KC_PDOT, KC_PENT, KC_PPLS, RGB_TOG ),
    [1] = LAYOUT( _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, RGB_HUD, RGB_HUI, _______, RGB_TOG, RGB_RMOD, RGB_MOD, _______ )
};
