/*
Copyright 2024 Asmodus
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

#include "quantum.h"

#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX) && defined(SCROLL_LOCK_LED_INDEX)

#if !defined(CAPS_LOCK_MAX_BRIGHTNESS)
    #define CAPS_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#if !defined(CAPS_LOCK_VAL_STEP)
    #define CAPS_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif

#if !defined(SCROLL_LOCK_MAX_BRIGHTNESS)
    #define SCROLL_LOCK_MAX_BRIGHTNESS RGB_MATRIX_MAXIMUM_BRIGHTNESS
#endif

#if !defined(SCROLL_LOCK_VAL_STEP)
    #define SCROLL_LOCK_VAL_STEP RGB_MATRIX_VAL_STEP
#endif


bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        uint8_t b = rgb_matrix_get_val();
        if (b < CAPS_LOCK_VAL_STEP) {
            b = CAPS_LOCK_VAL_STEP;
        } else if (b < (CAPS_LOCK_MAX_BRIGHTNESS - CAPS_LOCK_VAL_STEP)) {
            b += CAPS_LOCK_VAL_STEP;  // one step more than current brightness
        } else {
            b = CAPS_LOCK_MAX_BRIGHTNESS;
        }
        rgb_matrix_set_color(CAPS_LOCK_LED_INDEX, b, b, b);  // white, with the adjusted brightness
    }
        if (host_keyboard_led_state().scroll_lock) {
        uint8_t b = rgb_matrix_get_val();
        if (b < SCROLL_LOCK_VAL_STEP) {
            b = SCROLL_LOCK_VAL_STEP;
        } else if (b < (SCROLL_LOCK_MAX_BRIGHTNESS - SCROLL_LOCK_VAL_STEP)) {
            b += SCROLL_LOCK_VAL_STEP;  // one step more than current brightness
        } else {
            b = SCROLL_LOCK_MAX_BRIGHTNESS;
        }
        rgb_matrix_set_color(SCROLL_LOCK_LED_INDEX, b, b, b);  // white, with the adjusted brightness
    }
    return false;
}

#endif
