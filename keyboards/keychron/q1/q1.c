/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

#include "q1.h"


const matrix_row_t matrix_mask[] = {
    0b0111111111111101,
    0b0111111111111111,
    0b0111111111111111,
    0b0111111111111111,
    0b0111111111111111,
    0b0111111111111111,
};

bool dip_switch_update_kb(uint8_t index, bool active) {
    if (!dip_switch_update_user(index, active)) { return false;}
    if (index == 0) {
        default_layer_set(1UL << (active ? 2 : 0));
    }
<<<<<<< HEAD
<<<<<<< HEAD
    dip_switch_update_user(index, active);
}
=======
    return true;
}
>>>>>>> 605de079583db1f1106ebfd239b948170d929a58
=======
    return true;
}
>>>>>>> 3fa592a4024a24a636fa0c562e6761667a94f565
