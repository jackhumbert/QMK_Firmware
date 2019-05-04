#include "dz60rgb.h"
#include "config.h"
#if defined (dzrgb60_iso)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, K_14,   J_14,   L_14},
    {0, K_13,   J_13,   L_13},
    {0, K_12,   J_12,   L_12},
    {0, K_11,   J_11,   L_11},
    {0, K_10,   J_10,   L_10},
    {0, K_9,    J_9,    L_9},
    {0, K_8,    J_8,    L_8},
    {0, K_7,    J_7,    L_7},
    {0, K_6,    J_6,    L_6},
    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},
    {0, K_1,    J_1,    L_1},
    {0, H_15,   G_15,   I_15},
    {0, H_13,   G_13,   I_13},
    {0, H_12,   G_12,   I_12},
    {0, H_11,   G_11,   I_11},
    {0, H_10,   G_10,   I_10},
    {0, H_9,    G_9,    I_9},
    {0, H_8,    G_8,    I_8},
    {0, H_7,    G_7,    I_7},
    {0, H_6,    G_6,    I_6},
    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},
    {0, H_1,    G_1,    I_1},
    {0, B_14,   A_14,   C_14},
    {0, E_12,   D_12,   F_12},
    {0, E_11,   D_11,   F_11},
    {0, E_10,   D_10,   F_10},
    {0, E_9,    D_9,    F_9},
    {0, E_8,    D_8,    F_8},
    {0, E_7,    D_7,    F_7},
    {0, E_6,    D_6,    F_6},
    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},
    {0, E_1,    D_1,    F_1},
    {0, B_13,   A_13,   C_13},
    {0, B_11,   A_11,   C_11},
    {0, B_10,   A_10,   C_10},
    {0, B_9,    A_9,    C_9},
    {0, B_8,    A_8,    C_8},
    {0, B_7,    A_7,    C_7},
    {0, B_6,    A_6,    C_6},
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},
    {0, B_1,    A_1,    C_1},
    {0, B_15,   A_15,   C_15},
    {0, E_13,   D_13,   F_13},
    {0, B_12,   A_12,   C_12},
    {0, E_15,   D_15,   F_15},
    {0, B_16,   A_16,   C_16},
    {0, E_16,   D_16,   F_16},
    {0, H_16,   G_16,   I_16},
    {0, K_16,   J_16,   L_16},
};

const led_config_t g_led_config = { {
    {  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0 },
    {  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,  28 },
    {  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,  29, ___,  14 },
    {  52,  51,  50,  49,  48,  47,  46,  45,  44,  43,  42,  41, ___, ___ },
    {  60,  59,  58, ___, ___,  57, ___, ___, ___,  56,  55,  54, ___,  53 }
}, {
    { 216,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 }, {   0,   0 },
    { 220,  24 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 }, {   4,  16 },
    { 204,  32 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 }, {   6,  32 }, { 210,  48 },
    { 180,  48 }, { 164,  48 }, { 148,  48 }, { 132,  48 }, { 116,  48 }, { 100,  48 }, {  84,  48 }, {  68,  48 }, {  52,  48 }, {  20,  48 }, {  10,  48 }, { 222,  64 }, { 202,  64 }, { 182,  64 },
    { 162,  64 }, { 102,  64 }, {  42,  64 }, {  22,  64 }, {   2,  64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
    1, 4, 1, 1, 1
} };

#elif defined (dzrgb60_hhkb)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
	{0, H_15,   G_15,   I_15},
    {0, K_14,   J_14,   L_14},
    {0, K_13,   J_13,   L_13},
    {0, K_12,   J_12,   L_12},
    {0, K_11,   J_11,   L_11},
    {0, K_10,   J_10,   L_10},
    {0, K_9,    J_9,    L_9},
    {0, K_8,    J_8,    L_8},
    {0, K_7,    J_7,    L_7},
    {0, K_6,    J_6,    L_6},
    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},
    {0, K_1,    J_1,    L_1},
    {0, H_14,   G_14,   I_14},
    {0, H_13,   G_13,   I_13},
    {0, H_12,   G_12,   I_12},
    {0, H_11,   G_11,   I_11},
    {0, H_10,   G_10,   I_10},
    {0, H_9,    G_9,    I_9},
    {0, H_8,    G_8,    I_8},
    {0, H_7,    G_7,    I_7},
    {0, H_6,    G_6,    I_6},
    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},
    {0, H_1,    G_1,    I_1},
    {0, E_14,   D_14,   F_14},
    {0, E_12,   D_12,   F_12},
    {0, E_11,   D_11,   F_11},
    {0, E_10,   D_10,   F_10},
    {0, E_9,    D_9,    F_9},
    {0, E_8,    D_8,    F_8},
    {0, E_7,    D_7,    F_7},
    {0, E_6,    D_6,    F_6},
    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},
    {0, E_1,    D_1,    F_1},
    {0, B_14,   A_14,   C_14},
    {0, B_13,   A_13,   C_13},
    {0, B_11,   A_11,   C_11},
    {0, B_10,   A_10,   C_10},
    {0, B_9,    A_9,    C_9},
    {0, B_8,    A_8,    C_8},
    {0, B_7,    A_7,    C_7},
    {0, B_6,    A_6,    C_6},
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},
    {0, B_1,    A_1,    C_1},
    {0, B_15,   A_15,   C_15},
    {0, E_13,   D_13,   F_13},
    {0, B_12,   A_12,   C_12},
    {0, B_16,   A_16,   C_16},
    {0, E_16,   D_16,   F_16},
    {0, H_16,   G_16,   I_16},
    {0, K_16,   J_16,   L_16},
};

const led_config_t g_led_config = { {
    {  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1 },
    {  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15 },
    {  41,  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,   0,  29 },
    {  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,  43, ___,  42 },
    {  61,  60,  59, ___, ___,  58, ___, ___, ___, ___,  57,  56, ___,  55 }
}, {
    { 224,   0 }, { 208,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 },
    {   0,   0 }, { 220,  16 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 },
    {   4,  16 }, { 204,  32 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 }, {   6,  32 },
    { 224,  48 }, { 202,  48 }, { 180,  48 }, { 164,  48 }, { 148,  48 }, { 132,  48 }, { 116,  48 }, { 100,  48 }, {  84,  48 }, {  68,  48 }, {  52,  48 }, {  20,  48 }, {  10,  48 }, { 218,  64 },
    { 198,  64 }, { 178,  64 }, { 112,  64 }, {  46,  64 }, {  26,  64 }, {   6,  64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 1, 4, 1, 1, 1
} };

#elif defined (dzrgb60_hhkb_iso)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
	{0, H_15,   G_15,   I_15},
    {0, K_14,   J_14,   L_14},
    {0, K_13,   J_13,   L_13},
    {0, K_12,   J_12,   L_12},
    {0, K_11,   J_11,   L_11},
    {0, K_10,   J_10,   L_10},
    {0, K_9,    J_9,    L_9},
    {0, K_8,    J_8,    L_8},
    {0, K_7,    J_7,    L_7},
    {0, K_6,    J_6,    L_6},
    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},
    {0, K_1,    J_1,    L_1},
    {0, K_15,   J_15,   L_15},
    {0, H_13,   G_13,   I_13},
    {0, H_12,   G_12,   I_12},
    {0, H_11,   G_11,   I_11},
    {0, H_10,   G_10,   I_10},
    {0, H_9,    G_9,    I_9},
    {0, H_8,    G_8,    I_8},
    {0, H_7,    G_7,    I_7},
    {0, H_6,    G_6,    I_6},
    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},
    {0, H_1,    G_1,    I_1},
    {0, E_15,   D_15,   F_15},
    {0, E_12,   D_12,   F_12},
    {0, E_11,   D_11,   F_11},
    {0, E_10,   D_10,   F_10},
    {0, E_9,    D_9,    F_9},
    {0, E_8,    D_8,    F_8},
    {0, E_7,    D_7,    F_7},
    {0, E_6,    D_6,    F_6},
    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},
    {0, E_1,    D_1,    F_1},
    {0, B_14,   A_14,   C_14},
    {0, B_13,   A_13,   C_13},
    {0, B_11,   A_11,   C_11},
    {0, B_10,   A_10,   C_10},
    {0, B_9,    A_9,    C_9},
    {0, B_8,    A_8,    C_8},
    {0, B_7,    A_7,    C_7},
    {0, B_6,    A_6,    C_6},
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},
    {0, B_1,    A_1,    C_1},
    {0, B_15,   A_15,   C_15},
    {0, E_13,   D_13,   F_13},
    {0, B_12,   A_12,   C_12},
    {0, B_16,   A_16,   C_16},
    {0, E_16,   D_16,   F_16},
    {0, H_16,   G_16,   I_16},
    {0, K_16,   J_16,   L_16},
};

const led_config_t g_led_config = { {
    {  14,  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1 },
    {  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  29 },
    {  41,  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,   0,  15 },
    {  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,  43, ___,  42 },
    {  61,  60,  59, ___, ___,  58, ___, ___, ___, ___,  57,  56, ___,  55 }
}, {
    { 224,   0 }, { 208,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 },
    {   0,   0 }, { 220,  24 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 },
    {   4,  16 }, { 204,  32 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 }, {   6,  32 },
    { 224,  48 }, { 202,  48 }, { 180,  48 }, { 164,  48 }, { 148,  48 }, { 132,  48 }, { 116,  48 }, { 100,  48 }, {  84,  48 }, {  68,  48 }, {  52,  48 }, {  20,  48 }, {  10,  48 }, { 218,  64 },
    { 198,  64 }, { 178,  64 }, { 112,  64 }, {  46,  64 }, {  26,  64 }, {   6,  64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    1, 1, 4, 1, 1, 1
} };

#elif defined (dzrgb60_ansi)
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, K_14,   J_14,   L_14},
    {0, K_13,   J_13,   L_13},
    {0, K_12,   J_12,   L_12},
    {0, K_11,   J_11,   L_11},
    {0, K_10,   J_10,   L_10},
    {0, K_9,    J_9,    L_9},
    {0, K_8,    J_8,    L_8},
    {0, K_7,    J_7,    L_7},
    {0, K_6,    J_6,    L_6},
    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},
    {0, K_1,    J_1,    L_1},
    {0, H_14,   G_14,   I_14},
    {0, H_13,   G_13,   I_13},
    {0, H_12,   G_12,   I_12},
    {0, H_11,   G_11,   I_11},
    {0, H_10,   G_10,   I_10},
    {0, H_9,    G_9,    I_9},
    {0, H_8,    G_8,    I_8},
    {0, H_7,    G_7,    I_7},
    {0, H_6,    G_6,    I_6},
    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},
    {0, H_1,    G_1,    I_1},
    {0, E_14,   D_14,   F_14},
    {0, E_12,   D_12,   F_12},
    {0, E_11,   D_11,   F_11},
    {0, E_10,   D_10,   F_10},
    {0, E_9,    D_9,    F_9},
    {0, E_8,    D_8,    F_8},
    {0, E_7,    D_7,    F_7},
    {0, E_6,    D_6,    F_6},
    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},
    {0, E_1,    D_1,    F_1},
    {0, B_13,   A_13,   C_13},
    {0, B_11,   A_11,   C_11},
    {0, B_10,   A_10,   C_10},
    {0, B_9,    A_9,    C_9},
    {0, B_8,    A_8,    C_8},
    {0, B_7,    A_7,    C_7},
    {0, B_6,    A_6,    C_6},
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},
    {0, B_1,    A_1,    C_1},
    {0, B_15,   A_15,   C_15},
    {0, E_13,   D_13,   F_13},
    {0, B_12,   A_12,   C_12},
    {0, E_15,   D_15,   F_15},
    {0, B_16,   A_16,   C_16},
    {0, E_16,   D_16,   F_16},
    {0, H_16,   G_16,   I_16},
    {0, K_16,   J_16,   L_16},
};

const led_config_t g_led_config = { {
    {  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0 },
    {  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,  14 },
    {  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,  29, ___,  28 },
    {  52,  51,  50,  49,  48,  47,  46,  45,  44,  43,  42,  41, ___, ___ },
    {  60,  59,  58, ___, ___,  57, ___, ___, ___,  56,  55,  54, ___,  53 }
}, {
    { 216,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 }, { 144,   0 }, { 128,   0 }, { 112,   0 }, {  96,   0 }, {  80,   0 }, {  64,   0 }, {  48,   0 }, {  32,   0 }, {  16,   0 }, {   0,   0 },
    { 220,  16 }, { 200,  16 }, { 184,  16 }, { 168,  16 }, { 152,  16 }, { 136,  16 }, { 120,  16 }, { 104,  16 }, {  88,  16 }, {  72,  16 }, {  56,  16 }, {  40,  16 }, {  24,  16 }, {   4,  16 },
    { 214,  24 }, { 188,  32 }, { 172,  32 }, { 156,  32 }, { 140,  32 }, { 124,  32 }, { 108,  32 }, {  92,  32 }, {  76,  32 }, {  60,  32 }, {  44,  32 }, {  28,  32 }, {   6,  32 }, { 210,  48 },
    { 180,  48 }, { 164,  48 }, { 148,  48 }, { 132,  48 }, { 116,  48 }, { 100,  48 }, {  84,  48 }, {  68,  48 }, {  52,  48 }, {  20,  48 }, {  10,  48 }, { 222,  64 }, { 202,  64 }, { 182,  64 },
    { 162,  64 }, { 102,  64 }, {  42,  64 }, {  22,  64 }, {   2,  64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1,
    1, 4, 1, 1, 1
} };

#else
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
    {0, K_14,   J_14,   L_14},
    {0, K_13,   J_13,   L_13},
    {0, K_12,   J_12,   L_12},
    {0, K_11,   J_11,   L_11},
    {0, K_10,   J_10,   L_10},
    {0, K_9,    J_9,    L_9},
    {0, K_8,    J_8,    L_8},
    {0, K_7,    J_7,    L_7},
    {0, K_6,    J_6,    L_6},
    {0, K_5,    J_5,    L_5},
    {0, K_4,    J_4,    L_4},
    {0, K_3,    J_3,    L_3},
    {0, K_2,    J_2,    L_2},
    {0, K_1,    J_1,    L_1},
    {0, H_14,   G_14,   I_14},
    {0, H_13,   G_13,   I_13},
    {0, H_12,   G_12,   I_12},
    {0, H_11,   G_11,   I_11},
    {0, H_10,   G_10,   I_10},
    {0, H_9,    G_9,    I_9},
    {0, H_8,    G_8,    I_8},
    {0, H_7,    G_7,    I_7},
    {0, H_6,    G_6,    I_6},
    {0, H_5,    G_5,    I_5},
    {0, H_4,    G_4,    I_4},
    {0, H_3,    G_3,    I_3},
    {0, H_2,    G_2,    I_2},
    {0, H_1,    G_1,    I_1},
    {0, E_14,   D_14,   F_14},
    {0, E_12,   D_12,   F_12},
    {0, E_11,   D_11,   F_11},
    {0, E_10,   D_10,   F_10},
    {0, E_9,    D_9,    F_9},
    {0, E_8,    D_8,    F_8},
    {0, E_7,    D_7,    F_7},
    {0, E_6,    D_6,    F_6},
    {0, E_5,    D_5,    F_5},
    {0, E_4,    D_4,    F_4},
    {0, E_3,    D_3,    F_3},
    {0, E_2,    D_2,    F_2},
    {0, E_1,    D_1,    F_1},
    {0, B_14,   A_14,   C_14},
    {0, B_13,   A_13,   C_13},
    {0, B_11,   A_11,   C_11},
    {0, B_10,   A_10,   C_10},
    {0, B_9,    A_9,    C_9},
    {0, B_8,    A_8,    C_8},
    {0, B_7,    A_7,    C_7},
    {0, B_6,    A_6,    C_6},
    {0, B_5,    A_5,    C_5},
    {0, B_4,    A_4,    C_4},
    {0, B_3,    A_3,    C_3},
    {0, B_2,    A_2,    C_2},
    {0, B_1,    A_1,    C_1},
    {0, B_15,   A_15,   C_15},
    {0, E_13,   D_13,   F_13},
    {0, B_12,   A_12,   C_12},
    {0, E_15,   D_15,   F_15},
    {0, H_15,   G_15,   I_15},
    {0, B_16,   A_16,   C_16},
    {0, E_16,   D_16,   F_16},
    {0, H_16,   G_16,   I_16},
    {0, K_16,   J_16,   L_16},
};

const led_config_t g_led_config = { {
    {  13,  12,  11,  10,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0 },
    {  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,  14 },
    {  40,  39,  38,  37,  36,  35,  34,  33,  32,  31,  30,  29, ___,  28 },
    {  53,  52,  51,  50,  49,  48,  47,  46,  45,  44,  43,  42, ___,  41 },
    {  62,  61,  60, ___, ___,  59, ___, ___,  58,  57,  56,  55, ___,  54 }
}, {
    { 223,   0 }, { 206,   0 }, { 189,   0 }, { 172,   0 }, { 155,   0 }, { 137,   0 }, { 120,   0 }, { 103,   0 }, {  86,   0 }, {  68,   0 }, {  51,   0 }, {  34,   0 }, {  17,   0 }, {   0,   0 },
    { 223,  16 }, { 206,  16 }, { 189,  16 }, { 172,  16 }, { 155,  16 }, { 137,  16 }, { 120,  16 }, { 103,  16 }, {  86,  16 }, {  68,  16 }, {  51,  16 }, {  34,  16 }, {  17,  16 }, {   0,  16 },
    { 223,  32 }, { 189,  32 }, { 172,  32 }, { 155,  32 }, { 137,  32 }, { 120,  32 }, { 103,  32 }, {  86,  32 }, {  68,  32 }, {  51,  32 }, {  34,  32 }, {  17,  32 }, {   0,  32 }, { 223,  48 },
    { 189,  48 }, { 172,  48 }, { 155,  48 }, { 137,  48 }, { 120,  48 }, { 103,  48 }, {  86,  48 }, {  68,  48 }, {  51,  48 }, {  34,  48 }, {  17,  48 }, {   0,  48 }, { 223,  64 }, { 189,  64 },
    { 172,  64 }, { 155,  64 }, { 137,  64 }, {  86,  64 }, {  34,  64 }, {  17,  64 }, {   0,  64 }
}, {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,
    1, 1, 1, 4, 1, 1, 1
} };

#endif

void matrix_init_kb(void) {
    matrix_init_user();
}
void matrix_scan_kb(void) {
    matrix_scan_user();
}
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    return process_record_user(keycode, record);
}
void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
