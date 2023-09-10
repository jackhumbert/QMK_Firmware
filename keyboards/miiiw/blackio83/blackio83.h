/* Copyright 2023 ArthurCyy <https://github.com/ArthurCyy>
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

#pragma once

#include "quantum.h"

#define XXX KC_NO

enum custom_keycodes {
#ifdef VIA_ENABLE
    DEV_BT1 = SAFE_RANGE,
#endif
    DEV_BT2,
    DEV_BT3,
    DEV_RF24,
    ALT_TAB,
    RGB_RST,
	NEW_SAFE_RANGE
};

#undef SAFE_RANGE
#define SAFE_RANGE NEW_SAFE_RANGE
