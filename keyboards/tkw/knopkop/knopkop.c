/* Copyright 2020 zvecr <git@zvecr.com>
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
#include "knopkop.h"

void keyboard_pre_init_kb(void){
    // Workaround for reversible pcb/mcu
    palSetLineMode(C13, PAL_MODE_INPUT_PULLUP);
    palSetLineMode(C15, PAL_MODE_INPUT_PULLUP);
    palSetLineMode(B7, PAL_MODE_OUTPUT_OPENDRAIN);
    palSetLineMode(A0, PAL_MODE_OUTPUT_OPENDRAIN);
    palSetLineMode(A1, PAL_MODE_OUTPUT_OPENDRAIN);

    keyboard_pre_init_user();
}
