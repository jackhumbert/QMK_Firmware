// Copyright 2022 peepeetee (@peepeetee)
// Copyright 2022 Xelus22
// SPDX-License-Identifier: GPL-2.0-or-later

#include "v3.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return true;
}
#endif

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    { 8,   9,      34,   35,   64,   65,   NO_LED,   NO_LED, NO_LED, NO_LED,   NO_LED },
    { 7,   NO_LED, 33,   36,   63,   66,   NO_LED,   NO_LED, NO_LED, NO_LED,   NO_LED },
    { 6,   10,     32,   37,   62,   67,   NO_LED,   NO_LED, 49,     50,       79 },
    { 0,   11,     31,   38,   61,   68,   21,       NO_LED, 48,     NO_LED,   77 },
    { 1,   12,     30,   39,   60,   69,   20,       22,     47,     52,   76 },
    { 2,   13,     29,   40,   59,   70,   19,       23,     46,     53,   75 },
    { 5,   14,     28,   41,   58,   71,   NO_LED,   NO_LED, NO_LED, 51,   78 },
    { 3,   15,     27,   42,   57,   72,   18,       24,     45,     54,   74 },
    { 4,   16,     26,   43,   56,   73,   17,       25,     44,     55,   NO_LED },
}, {
    // LED Index to Physical Position
{224, 64}, {209, 64}, {195, 64}, {173, 61}, {151, 61}, {94 , 61}, {39 , 61}, {20 , 61}, {2  , 61}, {9  , 50}, {33 , 50},
{48 , 50}, {62 , 50}, {77 , 50}, {92 , 50}, {106, 50}, {121, 50}, {136, 50}, {151, 50}, {165, 50}, {185, 50}, {209, 53},
{196, 39}, {173, 39}, {158, 39}, {143, 39}, {129, 39}, {114, 39}, {99 , 39}, {84 , 39}, {70 , 39}, {55 , 39}, {40 , 39},
{26 , 39}, {6  , 39}, {4  , 28}, {22 , 28}, {37 , 28}, {51 , 28}, {66 , 28}, {81 , 28}, {95 , 28}, {110, 28}, {125, 28},
{140, 28}, {154, 28}, {169, 28}, {184, 28}, {202, 28}, {224, 28}, {224, 17}, {198, 17}, {176, 17}, {162, 17}, {147, 17},
{132, 17}, {118, 17}, {103, 17}, {88 , 17}, {73 , 17}, {59 , 17}, {44 , 17}, {29 , 17}, {15 , 17}, {0  , 17}, {0  ,  0},
{18 ,  0}, {33 ,  0}, {48 ,  0}, {62 ,  0}, {81 ,  0}, {95 ,  0}, {110,  0}, {125,  0}, {143,  0}, {158,  0}, {173,  0},
{187,  0}, {206,  0}, {224,  0},

{ 207,  13},
{ 207,  32},
{ 207,  51},{ 174,  51},{ 141,  51},{ 108,  51},{ 73,  51},{ 40,  51},{  13,  51 },
{ 13,  32},
{ 13,  13},{ 40,  13},{ 73,  13},{ 108,  13},{ 141,  13},{ 174,  13},

}, {
    // LED Index to Flag
1,1,1,1,1,4,1,1,1,
1,4,4,4,4,4,4,4,4,4,4,1,1,
1,4,4,4,4,4,4,4,4,4,4,4,1,
1,4,4,4,4,4,4,4,4,4,4,4,4,4,1,
1,1,4,4,4,4,4,4,4,4,4,4,4,4,4,
1,4,4,4,4,1,1,1,1,4,4,4,4,1,1,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,

} };

#endif
