/*
Copyright 2018 listofoptions <listofoptions@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

#define VENDOR_ID         0xFEED
#define PRODUCT_ID        0x6060
#define DEVICE_VER        1
#define MANUFACTURER      QMK
#define PRODUCT           46010A keyboard converter
#define DESCRIPTION       46010A keyboard converter
                          
#define MATRIX_ROWS       14
#define MATRIX_COLS       8

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION CUSTOM_MATRIX
#undef MATRIX_HAS_GHOST

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

//#define QMK_KEYS_PER_SCAN 107



#endif // CONFIG_H
