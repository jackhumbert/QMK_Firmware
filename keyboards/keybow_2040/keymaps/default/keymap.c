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

enum layer {
    LAYER_0,
    LAYER_1,
};

#define KC_LYR1     LT(LAYER_1, KC_P0) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */
    [LAYER_0] = LAYOUT_ortho_4x4(KC_P7, KC_P8, KC_P9, KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PAST, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_LYR1, KC_PDOT, KC_PENT, KC_PPLS),
    [LAYER_1] = LAYOUT_ortho_4x4(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_MOD, RGB_RMOD)};
