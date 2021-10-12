/* Copyright 2021 Ocean
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

/*LAYOUT
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
  * │k00│k01│k02│k03│k04│k05│k06│k07│k08│k09│k0A│k0B│k0C│  k0D  │k0F│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
  * │ k10 │k11│k12│k13│k14│k15│k16│k17│k18│k19│k1A│k1B│k1C│ k1D │k1E│
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
  * │ k20  │k21│k22│k23│k24│k25│k26│k27│k28│k29│k2A│k2B│  k2D   │k2E│
  * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
  * │   k30  │k32│k33│k34│k35│k36│k37│k38│k39│k3A│k3B│  k3C │k3D│k3E│
  * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
  * │k40 │k41 │k42 │  k44                   │k49 │k4A │ │k4C│k4D│k4E│
  * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
    1     2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
*/
#define LAYOUT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k2D, k2E, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42,      k44,                     k49, k4A,      k4C, k4D, k4E  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, XXX, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k1D, k1E, XXX }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, XXX, k2D, k2E, XXX }, \
    { k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, XXX }, \
    { k40, k41, k42, XXX, k44, XXX, XXX, XXX, XXX, k49, k4A, XXX, k4C, k4D, k4E, XXX }, \
}

/*LAYOUT_iso
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  * │k00│k01│k02│k03│k04│k05│k06│k07│k08│k09│k0A│k0B│k0C│k0D│k0E│k0F│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
  * │ k10 │k11│k12│k13│k14│k15│k16│k17│k18│k19│k1A│k1B│k1C│ K2D │k1E│
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
  * │ k20  │k21│k22│k23│k24│k25│k26│k27│k28│k29│k2A│k2B│k1D│    │k2E│
  * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
  * │   k30  │k32│k33│k34│k35│k36│k37│k38│k39│k3A│k3B│  k3C │k3D│k3E│
  * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
  * │k40 │k41 │k42 │  k44                   │k49 │k4A │ │k4C│k4D│k4E│
  * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
    1     2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
*/
#define LAYOUT_iso( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k1D, k2E, \
    k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42,      k44,                     k49, k4A,      k4C, k4D, k4E  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, XXX }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, XXX, k2D, k2E, XXX }, \
    { k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, XXX }, \
    { k40, k41, k42, XXX, k44, XXX, XXX, XXX, XXX, k49, k4A, XXX, k4C, k4D, k4E, XXX }, \
}

/*LAYOUT_Split_left_shift
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  * │k00│k01│k02│k03│k04│k05│k06│k07│k08│k09│k0A│k0B│k0C│k0D│k0E│k0F│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
  * │ k10 │k11│k12│k13│k14│k15│k16│k17│k18│k19│k1A│k1B│k1C│ K2D │k1E│
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
  * │ k20  │k21│k22│k23│k24│k25│k26│k27│k28│k29│k2A│k2B│k1D│    │k2E│
  * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
  * │k30 │k31│k32│k33│k34│k35│k36│k37│k38│k39│k3A│k3B│  k3C │k3D│k3E│
  * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
  * │k40 │k41 │k42 │  k44                   │k49 │k4A │ │k4C│k4D│k4E│
  * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
    1     2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
*/
#define LAYOUT_Split_left_shift( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k1D, k2E, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42,      k44,                     k49, k4A,      k4C, k4D, k4E  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, XXX, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, XXX, k2D, k2E, XXX }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, XXX }, \
    { k40, k41, k42, XXX, k44, XXX, XXX, XXX, XXX, k49, k4A, XXX, k4C, k4D, k4E, XXX }, \
}

/*LAYOUT_7U_Space
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  * │k00│k01│k02│k03│k04│k05│k06│k07│k08│k09│k0A│k0B│k0C│k0D│k0E│k0F│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
  * │ k10 │k11│k12│k13│k14│k15│k16│k17│k18│k19│k1A│k1B│k1C│ K2D │k1E│
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
  * │ k20  │k21│k22│k23│k24│k25│k26│k27│k28│k29│k2A│k2B│k1D│    │k2E│
  * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
  * │k30 │k31│k32│k33│k34│k35│k36│k37│k38│k39│k3A│k3B│  k3C │k3D│k3E│
  * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬─┬───┼───┼───┤
  * │k40 │k41 │k42 │  k44                       │k4A  │ │k4C│k4D│k4E│
  * └────┴────┴────┴────────────────────────────┴─────┘ └───┴───┴───┘
    1     2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
*/
#define LAYOUT_7U_Space( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k1D, k2E, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42,      k44,                          k4A,      k4C, k4D, k4E  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, XXX, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, XXX, k2D, k2E, XXX }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, XXX }, \
    { k40, k41, k42, XXX, k44, XXX, XXX, XXX, XXX, XXX, k4A, XXX, k4C, k4D, k4E, XXX }, \
}

/*LAYOUT_Split_space_1
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  * │k00│k01│k02│k03│k04│k05│k06│k07│k08│k09│k0A│k0B│k0C│k0D│k0E│k0F│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
  * │ k10 │k11│k12│k13│k14│k15│k16│k17│k18│k19│k1A│k1B│k1C│ K2D │k1E│
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
  * │ k20  │k21│k22│k23│k24│k25│k26│k27│k28│k29│k2A│k2B│k1D│    │k2E│
  * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
  * │k30 │k31│k32│k33│k34│k35│k36│k37│k38│k39│k3A│k3B│  k3C │k3D│k3E│
  * ├────┼───┴┬──┴─┬─┴───┴───┴┬──┴─┬─┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
  * │k40 │k41 │k42 │k43       │K44 │ K46    │K49 │k4A │ │k4C│k4D│k4E│
  * └────┴────┴────┴──────────┴────┴────────┴────┴────┘ └───┴───┴───┘
    1     2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
*/
#define LAYOUT_Split_space_1( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k1D, k2E, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42, K43, k44,      K46,           K49, k4A,      k4C, k4D, k4E  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, XXX, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, XXX, k2D, k2E, XXX }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, XXX }, \
    { k40, k41, k42, K43, k44, XXX, K46, XXX, XXX, XXX, k4A, XXX, k4C, k4D, k4E, XXX }, \
}

/*LAYOUT_split_space_2
  * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
  * │k00│k01│k02│k03│k04│k05│k06│k07│k08│k09│k0A│k0B│k0C│k0D│k0E│k0F│
  * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
  * │ k10 │k11│k12│k13│k14│k15│k16│k17│k18│k19│k1A│k1B│k1C│ K2D │k1E│
  * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
  * │ k20  │k21│k22│k23│k24│k25│k26│k27│k28│k29│k2A│k2B│k1D│    │k2E│
  * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
  * │k30 │k31│k32│k33│k34│k35│k36│k37│k38│k39│k3A│k3B│  k3C │k3D│k3E│
  * ├────┼───┴┬──┴─┬─┴───┴──┬┴───┼───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
  * │k40 │k41 │k42 │k43     │K44 │ K46      │K49 │k4A │ │k4C│k4D│k4E│
  * └────┴────┴────┴────────┴────┴──────────┴────┴────┘ └───┴───┴───┘
    1     2    3    4    5    6    7    8    9    10   11   12   13   14   15   16
*/
#define LAYOUT_split_space_2( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B,      k1D, k2E, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, \
    k40, k41, k42, K43, k44,      K46,           K49, k4A,      k4C, k4D, k4E  \
) { \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0A, k0B, k0C, k0D, k0E, k0F }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1A, k1B, k1C, k2D, k1E, XXX, }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2A, k2B, XXX, k2D, k2E, XXX }, \
    { k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3A, k3B, k3C, k3D, k3E, XXX }, \
    { k40, k41, k42, K43, k44, XXX, K46, XXX, XXX, XXX, k4A, XXX, k4C, k4D, k4E, XXX }, \
}
