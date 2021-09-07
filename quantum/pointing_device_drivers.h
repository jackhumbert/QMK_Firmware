/*
Copyright 2017 Joshua Broekhuijsen <snipeye+qmk@gmail.com>

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

#include <stdint.h>
#include "report.h"

typedef struct {
    void (*init)(void);
    report_mouse_t (*get_report)(report_mouse_t mouse_report);
} pointing_device_driver_t;

extern const pointing_device_driver_t pointing_device_driver;

#if defined(POINTING_DEVICE_DRIVER_adns5050)
#    include "drivers/sensors/adns5050.h"
#elif defined(POINTING_DEVICE_DRIVER_adns9800)
#    include "drivers/sensors/adns9800.h"
#elif defined(POINTING_DEVICE_DRIVER_pimoroni_trackball)
#    include "drivers/sensors/pimoroni_trackball.h"
#elif defined(POINTING_DEVICE_DRIVER_pmw3360)
#    include "drivers/sensors/pmw3360.h"
#endif
