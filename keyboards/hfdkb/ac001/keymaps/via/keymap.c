/* Copyright (C) 2022 Westberry Technology (ChangZhou) Corp., Ltd
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
    [0] = LAYOUT( /* Base */
		RGB_MOD, KC_LCTL, KC_ENT,KC_NO,KC_NO),
    [1] = LAYOUT(
		RGB_MOD, KC_LCTL, KC_ENT,KC_NO,KC_NO),
    [2] = LAYOUT(
		RGB_MOD, KC_LCTL, KC_ENT,KC_NO,KC_NO),
    [3] = LAYOUT(
		RGB_MOD, KC_LCTL, KC_ENT,KC_NO,KC_NO)
};

