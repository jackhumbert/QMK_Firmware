/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#ifndef REV1_CONFIG_H
#define REV1_CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xC0DE
#define PRODUCT_ID      0x1337
#define DEVICE_VER      0x0001
#define MANUFACTURER    KgOfHedgehogs
#define PRODUCT         Jian
#define DESCRIPTION     An ergo split keyboard

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { D3, D2, E6, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2 }

/* Use I2C or Serial, not both */
// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS


// different Jian configs
#define DIPS_ENABLE
#define PHYSICAL_LEDS_ENABLE
#define NUM_LOCK_LED_ENABLE
#define CAPS_LOCK_LED_ENABLE
#define SCROLL_LOCK_LED_ENABLE

#ifdef PHYSICAL_LEDS_ENABLE

#ifdef NUM_LOCK_LED_ENABLE
//#define NUM_LOCK_INVERT  //uncomment this if you using n-mosfet
#define NUM_LOCK_LED_PORT PORTC
#define NUM_LOCK_LED_DDR DDRC
#define NUM_LOCK_LED_BIT PC6
#endif

#ifdef CAPS_LOCK_LED_ENABLE
//#define CAPS_LOCK_INVERT  //uncomment this if you using n-mosfet
#define CAPS_LOCK_LED_PORT PORTD
#define CAPS_LOCK_LED_DDR DDRD
#define CAPS_LOCK_LED_BIT PD7
#endif

#ifdef SCROLL_LOCK_LED_ENABLE
//#define SCROLL_LOCK_INVERT  //uncomment this if you using n-mosfet
#define SCROLL_LOCK_LED_PORT PORTB
#define SCROLL_LOCK_LED_DDR DDRB
#define SCROLL_LOCK_LED_BIT PB5
#endif

#endif

#ifdef BACKLIGHT_ENABLE
#define BACKLIGHT_PIN B6
#define BACKLIGHT_LEVELS 5
//#define BACKLIGHT_BREATHING
#define BREATHING_PERIOD 6
#endif

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
// #define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* ws2812 RGB LED */
#define RGB_DI_PIN D4
#define RGBLIGHT_TIMER
#define RGBLED_NUM 10    // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_LIMIT_VAL 255
#define ws2812_PORTREG  PORTD
#define ws2812_DDRREG   DDRD

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif //REV1_CONFIG_H
