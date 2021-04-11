/* Copyright 2021 Drashna Jael're
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
    /* Base */
    [0] = LAYOUT_via(
        KC_A,    KC_1,    MO(1),
        KC_VOLD, KC_VOLU
    ),
    [1] = LAYOUT_via(
        RESET,   _______, _______,
        _______, _______
    ),
    [2] = LAYOUT_via(
        RESET,   _______, _______,
        _______, _______
    ),
    [3] = LAYOUT_via(
        RESET,   _______, _______,
        _______, _______
    )
};
