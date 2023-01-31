/*
Copyright 2022 Yiancar-Designs

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published byß
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

#define MATRIX_ROW_PINS { A2, A14, A15, B3, B4, B5 }
#define MATRIX_COL_PINS { A1, B9, A3, A4, A5, A6, A7, B0, B1, B2, B10, B11, B12, B13, B14, B15, A8 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Ensure we jump to bootloader if the RESET keycode was pressed */
#define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

/* Indicator LEDs */
#define LED_CAPS_LOCK_PIN B6
#define LED_SCROLL_LOCK_PIN B7
#define LED_PIN_ON_STATE 0

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is userful for the Windows task manager shortcut (ctrl+shift+esc).
 */
// #define GRAVE_ESC_CTRL_OVERRIDE
