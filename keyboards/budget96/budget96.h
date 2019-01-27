/* Copyright 2019 MechMerlin
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
#ifndef BUDGET96_H
#define BUDGET96_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define LAYOUT( \
    k50, k52, k53, k54, k55, k60, k6A, k7A, k70, k5B, k5C, k5E, k1D, k1E, k0D, k76, k79, k78, \
    k40, k41, k42, k43, k44, k45, k61, k6B, k7B, k71, k4A, k4B, k4C, k4D, k4E, k46, k47, k48, k49, \
    k30, k31, k32, k33, k34, k35, k62, k6C, k7C, k72, k3A, k3B, k3C, k3D, k36, k37, k38, k39,      \
    k20, k21, k22, k23, k24, k25, k63, k6D, k7D, k73, k2A, k2B, k2C, k26, k27, k28, k29,           \
    k10,      k11, k12, k13, k14, k15, k64, k6E, k7E, k74, k1A, k1B, k68, k16, k17, k18,           \
    k00, k01, k02, k65, k75, k0B, k66, k67, k69, k06, k08, k09                                \
) \
{ \
    { k00, k01,   k02, KC_NO, KC_NO, KC_NO, k06,   KC_NO, k08,   k09,   KC_NO, k0B, KC_NO, k0D,   KC_NO }, \
    { k10, k11,   k12, k13,   k14,   k15,   k16,   k17,   k18,   KC_NO, k1A,   k1B, KC_NO, k1D,   k1E },   \
    { k20, k21,   k22, k23,   k24,   k25,   k26,   k27,   k28,   k29,   k2A,   k2B, k2C,   KC_NO, KC_NO }, \
    { k30, k31,   k32, k33,   k34,   k35,   k36,   k37,   k38,   k39,   k3A,   k3B, k3C,   k3D,   KC_NO }, \
    { k40, k41,   k42, k43,   k44,   k45,   k46,   k47,   k48,   k49,   k4A,   k4B, k4C,   k4D,   k4E },   \
    { k50, KC_NO, k52, k53,   k54,   k55,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, k5B, k5C,   KC_NO, k5E },   \
    { k60, k61,   k62, k63,   k64,   k65,   k66,   k67,   k68,   k69,   k6A,   k6B, k6C,   k6D,   k6E },   \
    { k70, k71,   k72, k73,   k74,   k75,   k76,   KC_NO, k78,   k79,   k7A,   k7B, k7C,   k7D,   KC_NO }, \
}

#endif
