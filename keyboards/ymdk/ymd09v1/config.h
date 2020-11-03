/*
Copyright 2020 James Badger

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x594D // "YM"
#define PRODUCT_ID   0x4409 // "D" + 09
#define DEVICE_VER   0x0000
#define MANUFACTURER YMDK
#define PRODUCT      YMD09V1
#define DESCRIPTION  9-Key Macropad v1

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

/* Keyboard Matrix Assignments */
#define MATRIX_ROW_PINS { A0, A1, A2 }
#define MATRIX_COL_PINS { B0, B1, B2 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define RGB_DI_PIN C0
#ifdef RGB_DI_PIN
  #define RGBLED_NUM 9
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_LIMIT_VAL 255
  #define RGBLIGHT_SLEEP
  /*== all animations enable ==*/
  #define RGBLIGHT_ANIMATIONS
#endif

/* Debounce reduces chatter (unintended double-presses) */
#define DEBOUNCE 5
