/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5845  // XE
#define PRODUCT_ID      0x0108  // X-108
#define DEVICE_VER      0x0001
#define MANUFACTURER    Xelus
#define PRODUCT         XS108
#define DESCRIPTION     Xelus XS108

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 21

// #define MATRIX_ROW_PINS { B8, B9, A10, A3, A1, A0 }
// #define MATRIX_COL_PINS { A9, A8, B15, B14, B13, B12, B11, B10, B2, B1, B0, A7, A6, A5, A4, B6, B5, B4, B3, A15, A14 }
#define MATRIX_ROW_PINS { C14, C13, A10, A3, A1, A0 }
#define MATRIX_COL_PINS { A9, A8, B15, B14, B13, B12, B11, B10, B2, B1, B0, A7, A6, A5, A4, B6, B5, B4, B3, A15, A14 }
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// LED defines
#define LED_CAPS_LOCK_PIN A2
#define LED_SCROLL_LOCK_PIN A13
#define LED_NUM_LOCK_PIN B7
#define LED_PIN_ON_STATE 1

// I2C setup
#define I2C1_SCL_PAL_MODE   4
#define I2C1_SDA_PAL_MODE   4
#define I2C1_TIMINGR_PRESC  0U
#define I2C1_TIMINGR_SCLDEL 7U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH   45U
#define I2C1_TIMINGR_SCLL   149U

// I2C EEPROM
#define EEPROM_I2C_24LC64

// More EEPROM for layers
#define DYNAMIC_KEYMAP_EEPROM_MAX_ADDR 8191
