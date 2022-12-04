#pragma once


/* Key matrix pins */
#define MATRIX_ROW_PINS { B8, B9, B1, B2, B4 }

#define MATRIX_COL_PINS { A2, B0, A7, A8, A13, A14, B12, B11, B10, B15, B14, B13 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* RGB Underglow */
#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN A15
#define RGBLED_NUM 14
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_ANIMATIONS
#endif

/* Audio */
#ifdef AUDIO_ENABLE
#define STARTUP_SONG_DOOM SONG(E1M1_DOOM)
#define STARTUP_SONG SONG( \
    Q__NOTE(_E6), \
    Q__NOTE(_A6), \
    H__NOTE(_E7), \
    Q__NOTE(_E6), \
    Q__NOTE(_E7) \
)
#endif

/* OLED */
#define OLED_FONT_H "glcdfont_d48.c"
#define OLED_TIMEOUT 0
// #define OLED_SCROLL_TIMEOUT 1000

/* Taps (encoder tap_code) */
#define TAP_CODE_DELAY 10

/* I2C */
//#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
//#define PAL_MODE_STM32_ALTERNATE_OPENDRAIN (PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN)

/* DS1307 */
#define DS1307_ADDR (0x68 << 1)
