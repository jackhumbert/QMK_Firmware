/* Copyright 2017 Joshua Broekhuijsen <snipeye+qmk@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2021 Dasky (@daskygit)
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

#include "pointing_device.h"
#include "debug.h"
#include "timer.h"
#include <stddef.h>

// get_report functions should probably be moved to their respective drivers.
#if defined(POINTING_DEVICE_DRIVER_adns5050)
report_mouse_t adns5050_get_report(report_mouse_t mouse_report) {
    report_adns5050_t data = adns5050_read_burst();

    if (data.dx != 0 || data.dy != 0) {
        if (debug_mouse) dprintf("Raw ] X: %d, Y: %d\n", data.dx, data.dy);

        mouse_report.x = data.dx;
        mouse_report.y = data.dy;
    }

    return mouse_report;
}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init         = adns5050_init,
    .get_report   = adns5050_get_report,
    .set_cpi    = adns5050_set_cpi,
    .get_cpi    = adns5050_get_cpi,
};
// clang-format on
#elif defined(POINTING_DEVICE_DRIVER_adns9800)

report_mouse_t adns9800_get_report_driver(report_mouse_t mouse_report) {
    report_adns9800_t sensor_report = adns9800_get_report();

    int8_t clamped_x = CLAMP_HID(sensor_report.x);
    int8_t clamped_y = CLAMP_HID(sensor_report.y);

    mouse_report.x = clamped_x;
    mouse_report.y = clamped_y;

    return mouse_report;
}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init       = adns9800_init,
    .get_report = adns9800_get_report_driver,
    .set_cpi    = adns9800_set_cpi,
    .get_cpi    = adns9800_get_cpi
};
// clang-format on
#elif defined(POINTING_DEVICE_DRIVER_analog_joystick)
report_mouse_t analog_joystick_get_report(report_mouse_t mouse_report) {
    report_analog_joystick_t data = analog_joystick_read();

    if (debug_mouse) dprintf("Raw ] X: %d, Y: %d\n", data.x, data.y);

    mouse_report.x = data.x;
    mouse_report.y = data.y;

    mouse_report.buttons = pointing_device_handle_buttons(data.button, POINTING_DEVICE_BUTTON1);

    return mouse_report;
}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init       = analog_joystick_init,
    .get_report = analog_joystick_get_report,
    .set_cpi    = NULL,
    .get_cpi    = NULL
};
// clang-format on
#elif defined(POINTING_DEVICE_DRIVER_cirque_trackpad)
#    ifndef TAPPING_CHECK
#        define TAPPING_CHECK 200
#    endif

report_mouse_t cirque_trackpad_get_report(report_mouse_t mouse_report) {
    tm040040_data_t touchData = cirque_trackpad_read_data();
    static uint16_t x = 0, y = 0, mouse_timer = 0;
    static bool     is_z_down = false;

    cirque_trackpad_scale_data(&touchData, cirque_trackpad_get_scale(), cirque_trackpad_get_scale());  // Scale coordinates to arbitrary X, Y resolution

    if (x && y && touchData.xValue && touchData.yValue) {
        mouse_report.x = (int8_t)(touchData.xValue - x);
        mouse_report.y = (int8_t)(touchData.yValue - y);
    }
    x = touchData.xValue;
    y = touchData.yValue;

    if ((bool)touchData.zValue != is_z_down) {
        is_z_down = (bool)touchData.zValue;
        if (!touchData.zValue) {
            if (timer_elapsed(mouse_timer) < TAPPING_CHECK && mouse_timer != 0) {
                mouse_report.buttons = pointing_device_handle_buttons(true, POINTING_DEVICE_BUTTON1);
            } else if (mouse_timer == 0) {
                mouse_report.buttons = pointing_device_handle_buttons(false, POINTING_DEVICE_BUTTON1);
            }
        }
        mouse_timer = timer_read();
    }
    if (timer_elapsed(mouse_timer) > (2 * TAPPING_CHECK)) {
        mouse_timer = 0;
    }

    return mouse_report;
}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init       = cirque_trackpad_init,
    .get_report = cirque_trackpad_get_report,
    .set_cpi    = cirque_trackpad_set_scale,
    .get_cpi    = cirque_trackpad_get_scale
};
// clang-format on

#elif defined(POINTING_DEVICE_DRIVER_pimoroni_trackball)
report_mouse_t pimorono_trackball_get_report(report_mouse_t mouse_report) {
    static fast_timer_t throttle      = 0;
    static uint16_t     debounce      = 0;
    static uint8_t      error_count   = 0;
    pimoroni_data_t     pimoroni_data = {0};
    static int16_t      x_offset = 0, y_offset = 0;

    if (error_count < PIMORONI_TRACKBALL_ERROR_COUNT && timer_elapsed_fast(throttle) >= PIMORONI_TRACKBALL_INTERVAL_MS) {
        i2c_status_t status = read_pimoroni_trackball(&pimoroni_data);

        if (status == I2C_STATUS_SUCCESS) {
            error_count = 0;

            if (!(pimoroni_data.click & 128)) {
                mouse_report.buttons = pointing_device_handle_buttons(false, POINTING_DEVICE_BUTTON1);
                if (!debounce) {
                    x_offset += pimoroni_trackball_get_offsets(pimoroni_data.right, pimoroni_data.left, PIMORONI_TRACKBALL_SCALE);
                    y_offset += pimoroni_trackball_get_offsets(pimoroni_data.down, pimoroni_data.up, PIMORONI_TRACKBALL_SCALE);
                    pimoroni_trackball_adapt_values(&mouse_report.x, &x_offset);
                    pimoroni_trackball_adapt_values(&mouse_report.y, &y_offset);
                } else {
                    debounce--;
                }
            } else {
                mouse_report.buttons = pointing_device_handle_buttons(true, POINTING_DEVICE_BUTTON1);
                debounce = PIMORONI_TRACKBALL_DEBOUNCE_CYCLES;
            }
        } else {
            error_count++;
        }
        throttle = timer_read_fast();
    }
    return mouse_report;
}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init       = pimironi_trackball_device_init,
    .get_report = pimorono_trackball_get_report,
    .set_cpi    = NULL,
    .get_cpi    = NULL
};
// clang-format on
#elif defined(POINTING_DEVICE_DRIVER_pmw3360)

static void init(void) { pmw3360_init(); }

report_mouse_t pmw3360_get_report(report_mouse_t mouse_report) {
    report_pmw3360_t data        = pmw3360_read_burst();
    static uint16_t  MotionStart = 0;  // Timer for accel, 0 is resting state

    if (data.isOnSurface && data.isMotion) {
        // Reset timer if stopped moving
        if (!data.isMotion) {
            if (MotionStart != 0) MotionStart = 0;
            return mouse_report;
        }

        // Set timer if new motion
        if ((MotionStart == 0) && data.isMotion) {
            if (debug_mouse) dprintf("Starting motion.\n");
            MotionStart = timer_read();
        }
        mouse_report.x = constrain(data.dx, -127, 127);
        mouse_report.y = constrain(data.dy, -127, 127);
    }

    return mouse_report;
}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init       = init,
    .get_report = pmw3360_get_report,
    .set_cpi    = pmw3360_set_cpi,
    .get_cpi    = pmw3360_get_cpi
};
// clang-format on
#else
__attribute__((weak)) void           pointing_device_driver_init(void) {}
__attribute__((weak)) report_mouse_t pointing_device_driver_get_report(report_mouse_t mouse_report) { return mouse_report; }
__attribute__((weak)) uint16_t       pointing_device_driver_get_cpi(void) { return 0; }
__attribute__((weak)) void           pointing_device_driver_set_cpi(uint16_t cpi) {}

// clang-format off
const pointing_device_driver_t pointing_device_driver = {
    .init       = pointing_device_driver_init,
    .get_report = pointing_device_driver_get_report,
    .get_cpi    = pointing_device_driver_get_cpi,
    .set_cpi    = pointing_device_driver_set_cpi
};
// clang-format on
#endif
