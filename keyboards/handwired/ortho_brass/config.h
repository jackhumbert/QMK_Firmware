/* Copyright 2021 Christoph Jabs (BifbofII)
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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6060
#define DEVICE_VER 0x0001
#define MANUFACTURER BifbofII
#define PRODUCT Ortho Brass

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Handwired pin-out */
#define MATRIX_ROW_PINS \
    { D3, D2, D1, D0 }
#define MATRIX_COL_PINS \
    { F4, F7, F5, F1, C7, F0, B1, B0, F6, B6, B2, B3 }
#define UNUSED_PINS \
    { B0, B1, B2, F0, F1, F4, D4, D5, E6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
