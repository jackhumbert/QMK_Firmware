 /* 
 Copyright 2020 Alec Penland
 Copyright 2020 Garret Gartner
  
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

#include "quantum.h"

#define xxx KC_NO

#define LED_CAP_LOCK_INDEX 29

/* === All used matrix spots populated === */
#define LAYOUT_split_space( \
    k00,                                                                                              \
          k11,  k12,  k13,   k14,   k15,   k16,  k17,   k18,   k19,  k1A,  k1B,  k1C,  k1D,  k1E, k1F,\
    k20,  k21,  k22,  k23,   k24,   k25,   k26,  k27,   k28,   k29,  k2A,  k2B,  k2C,  k2D,           \
    k30,  k31,  k32,  k33,   k34,   k35,   k36,  k37,   k38,   k39,  k3A,  k3B,        k3D,  k3E, k3F,\
    k40,        k42,  k43,   k44,   k45,   k46,  k47,   k48,   k49,  k4A,  k4B,        k4D,  k4E, k4F,\
    k50,  k51,  k52,                       k56,                k59,  k5A,        k5C,  k5D,  k5E, k5F \
) { \
   {k00,  xxx,  xxx,  xxx,   xxx,   xxx,   xxx,  xxx,   xxx,   xxx,  xxx,  xxx,  xxx,  xxx,  xxx, xxx},\
   {xxx,  k11,  k12,  k13,   k14,   k15,   k16,  k17,   k18,   k19,  k1A,  k1B,  k1C,  k1D,  k1E, k1F},\
   {k20,  k21,  k22,  k23,   k24,   k25,   k26,  k27,   k28,   k29,  k2A,  k2B,  k2C,  k2D,  xxx, xxx},\
   {k30,  k31,  k32,  k33,   k34,   k35,   k36,  k37,   k38,   k39,  k3A,  k3B,  xxx,  k3D,  k3E, k3F},\
   {k40,  xxx,  k42,  k43,   k44,   k45,   k46,  k47,   k48,   k49,  k4A,  k4B,  xxx,  k4D,  k4E, k4F},\
   {k50,  k51,  k52,  xxx,   xxx,   xxx,   k56,  xxx,   xxx,   k59,  k5A,  xxx,  k5C,  k5D,  k5E, k5F} \
}

