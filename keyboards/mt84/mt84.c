#include "mt84.h"

#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
 /* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */

   {0, A_11,   B_11,   C_11},
   {0, D_11,   E_11,   F_11},
   {0, G_11,   H_11,   I_11},
   {0, J_11,   K_11,   L_11},
   {0, A_12,   B_12,   C_12},
   {0, D_12,   E_12,   F_12},
   {0, G_12,   H_12,   I_12},
   {0, J_12,   K_12,   L_12},
   {1, A_11,   B_11,   C_11},
   {1, D_11,   E_11,   F_11},
   {1, G_11,   H_11,   I_11},
   {1, J_11,   K_11,   L_11},
   {1, A_12,   B_12,   C_12},
   {1, D_12,   E_12,   F_12},
   {1, G_12,   H_12,   I_12},
   {1, J_12,   K_12,   L_12},
       
   {0, A_1,   B_1,   C_1},
   {0, D_1,   E_1,   F_1},
   {0, G_1,   H_1,   I_1},
   {0, J_1,   K_1,   L_1},
   {0, A_6,   B_6,   C_6},
   {0, D_6,   E_6,   F_6},
   {0, G_6,   H_6,   I_6},
   {0, J_6,   K_6,   L_6},
   {1, A_1,   B_1,   C_1},
   {1, D_1,   E_1,   F_1},
   {1, G_1,   H_1,   I_1},
   {1, J_1,   K_1,   L_1},
   {1, A_6,   B_6,   C_6},
   {1, D_6,   E_6,   F_6},
   {1, G_6,   H_6,   I_6},

   {0, A_2,   B_2,   C_2},
   {0, D_2,   E_2,   F_2},
   {0, G_2,   H_2,   I_2},
   {0, J_2,   K_2,   L_2},
   {0, A_7,   B_7,   C_7},
   {0, D_7,   E_7,   F_7},
   {0, G_7,   H_7,   I_7},
   {0, J_7,   K_7,   L_7},
   {1, A_2,   B_2,   C_2},
   {1, D_2,   E_2,   F_2},
   {1, G_2,   H_2,   I_2},
   {1, J_2,   K_2,   L_2},
   {1, A_7,   B_7,   C_7},
   {1, D_7,   E_7,   F_7},
   {1, G_7,   H_7,   I_7},
       
   {0, A_3,   B_3,   C_3},
   {0, D_3,   E_3,   F_3},
   {0, G_3,   H_3,   I_3},
   {0, J_3,   K_3,   L_3},
   {0, A_8,   B_8,   C_8},
   {0, D_8,   E_8,   F_8},
   {0, G_8,   H_8,   I_8},
   {0, J_8,   K_8,   L_8},
   {1, A_3,   B_3,   C_3},
   {1, D_3,   E_3,   F_3},
   {1, G_3,   H_3,   I_3},
   {1, J_3,   K_3,   L_3},
   {1, A_8,   B_8,   C_8},
   {1, G_8,   H_8,   I_8},
       
   {0, A_4,   B_4,   C_4},
   {0, D_4,   E_4,   F_4},
   {0, G_4,   H_4,   I_4},
   {0, J_4,   K_4,   L_4},
   {0, A_9,   B_9,   C_9},
   {0, D_9,   E_9,   F_9},
   {0, G_9,   H_9,   I_9},
   {0, J_9,   K_9,   L_9},
   {1, A_4,   B_4,   C_4},
   {1, D_4,   E_4,   F_4},
   {1, G_4,   H_4,   I_4},
   {1, J_4,   K_4,   L_4},
   {1, A_9,   B_9,   C_9},
   {1, G_9,   H_9,   I_9},

   {0, A_5,   B_5,   C_5},
   {0, D_5,   E_5,   F_5},
   {0, G_5,   H_5,   I_5},
   {0, D_10,  E_10,  F_10},
   {1, D_5,   E_5,   F_5},
   {1, G_5,   H_5,   I_5},
   {1, J_5,   K_5,   L_5},
   {1, A_10,  B_10,  C_10},
   {1, D_10,  E_10,  F_10},
   {1, G_10,   H_10,   I_10}
};

led_config_t g_led_config = {{
    {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14 },
    { 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27,  28, 29 },
    { 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44 },
    { 45, 46, 47, 48, 49, 50, 51, 52, 53, 54,  55, 56, 57, 58 },
    { 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73 },
    {74, 75, 76, 77, 78, 79, 80, 81, 82, 83 }
}, {
    {   0,  0 }, {  15,  0 }, {  30,  0 }, {  45,  0 }, {  60,  0 }, { 75,  0 }, { 90,  0 }, { 105,  0 }, { 120,  0 }, { 135,  0 }, { 150,  0 }, { 165,  0 }, { 180,  0 }, { 195,  0 }, { 210,  0 }, { 224,  0 },
    {   0,  13 }, {  15,  13 }, {  30,  13 }, {  45,  13 }, {  60,  13 }, { 75,  13 }, { 90,  13 }, { 105,  13 }, { 120,  13 }, { 135,  13 }, { 150,  13 }, { 165,  13 }, { 180,  13 }, { 205,  13 }, { 224,  13 },
    {   3, 26 }, {  18, 26 }, {  33, 26 }, {  48, 26 }, {  63, 26 }, { 78, 26 }, { 93, 26 }, { 108, 26 }, { 123, 26 }, { 138, 26 }, { 153, 26 }, { 168, 26 }, { 183,  26 }, { 205,  26 },{ 224,  26 },
    {   6, 39 }, {  20, 39 }, {  36, 39 }, {  52, 39 }, {  68, 39 }, { 84, 39 }, { 100, 39 }, { 116, 39 }, { 132, 39 }, { 148, 39 }, { 164, 39 }, { 180, 39 }, { 212,  39 }, { 224,  39 },
    {   9, 52 }, {  27, 52 }, {  43, 52 }, {  59, 52 }, {  75, 52 }, { 91, 52 }, { 107, 52 }, { 123, 52 }, { 139, 52 }, { 155, 52 }, { 171, 52 }, { 187, 52 }, { 212,  52 }, { 224,  52 },
{   2, 64 }, {  18, 64 }, {  33, 64 },                 {  93, 64 },                                                                              { 150, 64 }, { 165,  64 }, { 180, 64 }, { 195, 64 }, { 210, 64 }, { 224, 64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 1, 1,         4,              1, 1, 1, 4, 4, 4,
}};
#endif
