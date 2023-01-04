// Copyright 2023 takashicompany (@takashicompany)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1 }


#define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6

#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 3 * 2
#    define RGBLED_SPLIT { 3, 3 }
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#endif

/*

 "matrix_pins": {
        "cols": [
            "F4",
            "F5",
            "F6",
            "F7",
            "B1",
            "B3",
            "B2",
            "B6",
            "B5",
            "B4"
        ],
        "rows": [
            "D4",
            "C6",
            "D7",
            "E6"
        ]
    },
*/