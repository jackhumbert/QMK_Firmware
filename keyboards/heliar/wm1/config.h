#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xD070
#define DEVICE_VER      0x0001
#define MANUFACTURER    Heliar 
#define PRODUCT         wm1 hotswap
#define DESCRIPTION     69% custom keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { D5, D3, B3, F0, E6 }
#define MATRIX_COL_PINS { D2, B0, B1, B2, D1, D0, C7, C6, B6, B5, B4, F4, F5, F6, F1 }

#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_PIN B7
#define BACKLIGHT_LEVELS 3