/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "pimoroni_trackball.h"
#include "i2c_master.h"
#include "print.h"
#include "debug.h"

static uint16_t precision = 128;

float pimoroni_trackball_get_precision(void) { return ((float)precision / 128); }
void  pimoroni_trackball_set_precision(float floatprecision) { precision = (floatprecision * 128); }

void pimoroni_trackball_set_rgbw(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
    uint8_t                              data[4] = {r, g, b, w};
    __attribute__((unused)) i2c_status_t status  = i2c_writeReg(PIMORONI_TRACKBALL_ADDRESS << 1, PIMORONI_TRACKBALL_REG_LED_RED, data, sizeof(data), PIMORONI_TRACKBALL_TIMEOUT);

    if (debug_mouse) dprintf("Trackball RGBW i2c_status_t: %d\n", status);
}

i2c_status_t read_pimoroni_trackball(pimoroni_data_t* data) {
    i2c_status_t status = i2c_readReg(PIMORONI_TRACKBALL_ADDRESS << 1, PIMORONI_TRACKBALL_REG_LEFT, (uint8_t*)data, sizeof(*data), PIMORONI_TRACKBALL_TIMEOUT);
    if (debug_mouse) dprintf("Trackball READ i2c_status_t: %d\nLeft: %d\nRight: %d\nUp: %d\nDown: %d\nSwtich: %d\n", status, data->left, data->right, data->up, data->down, data->click);

    return status;
}

__attribute__((weak)) void pimironi_trackball_device_init(void) {
    i2c_init();
    pimoroni_trackball_set_rgbw(0x00, 0x00, 0x00, 0x00);
}

int16_t pimoroni_trackball_get_offsets(uint8_t negative_dir, uint8_t positive_dir, uint8_t scale) {
    uint8_t offset     = 0;
    bool    isnegative = false;
    if (negative_dir > positive_dir) {
        offset     = negative_dir - positive_dir;
        isnegative = true;
    } else {
        offset = positive_dir - negative_dir;
    }
    uint16_t magnitude = (scale * offset * offset * precision) >> 7;
    return isnegative ? -(int16_t)(magnitude) : (int16_t)(magnitude);
}

void pimoroni_trackball_adapt_values(int8_t* mouse, int16_t* offset) {
    if (*offset > 127) {
        *mouse = 127;
        *offset -= 127;
    } else if (*offset < -127) {
        *mouse = -127;
        *offset += 127;
    } else {
        *mouse  = *offset;
        *offset = 0;
    }
}
