/* Copyright 2021 ianklug
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    	_1,
	_2,
	_3,
	_4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_1] = LAYOUT(
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
	[_2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
	[_4] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};