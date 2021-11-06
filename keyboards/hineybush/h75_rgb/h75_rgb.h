/* Copyright 2021 hineybush
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

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT_all( \
    k00,   k02, k03, k04,   k05, k06, k07, k08,   k09, k0A, k0B, k0C,       k0D, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, k1F, \
    k20,       k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, k2C, k2D, k2E, k2F, \
    k30,       k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, k3F, \
    k40, k42, k43, k44, k45, k46, k47, k48, k49, k4A, k4B, k4C,       k4E, k4F, \
    k50, k51, k52,                        k56,              k5A, k5B,       k5D, k5E, k5F  \
) { \
    {k00,  KC_NO,  k02,  k03,  k04,  k05,  k06,  k07,  k08,  k09,   k0A,   k0B,   k0C,   k0D, KC_NO, k0F}, \
    {k10,  k11,  k12,  k13,  k14,  k15,  k16,  k17,  k18,  k19,   k1A,   k1B,   k1C,   k1D,   k1E, k1F}, \
    {k20,  KC_NO, k22,  k23,  k24,  k25,  k26,  k27,  k28,  k29,   k2A,   k2B,   k2C,   k2D,   k2E, k2F}, \
    {k30,  KC_NO, k32,  k33,  k34,  k35,  k36,  k37,  k38,  k39,   k3A,   k3B,   k3C,   k3D,   k3E, k3F}, \
    {k40,  KC_NO,  k42,  k43,  k44,  k45,  k46,  k47,  k48,  k49,   k4A,   k4B,   k4C,   KC_NO,  k4E, k4F}, \
    {k50,  k51,  k52,  KC_NO, KC_NO, KC_NO, k56,  KC_NO, KC_NO, KC_NO,  k5A,   k5B,   KC_NO,  k5D,   k5E, k5F}  \
}

// NUBS is k41