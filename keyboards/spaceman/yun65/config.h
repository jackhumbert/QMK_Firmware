/* Copyright 2020 Spaceman
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
#define VENDOR_ID       0x5342 // "SB"
#define PRODUCT_ID      0x594E // "YN"
#define DEVICE_VER      0x0001
#define MANUFACTURER    Spaceman
#define PRODUCT         Yun 65

/* Key Matrix perameter */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

#define MATRIX_ROW_PINS { E6, D3, D2, D1, D0 }
#define MATRIX_COL_PINS { F0, D1, D4, F5, F6, F7, D4, D6, D7, B4, B5, B6, C6, C7, B3 }

#define UNUSED_PINS
