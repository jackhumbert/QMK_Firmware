#pragma once


/* key matrix pins */
#define MATRIX_ROW_PINS { B3, B2, B1, B0, E6 }
#define MATRIX_COL_PINS { D7, B4, B6, C6, C7, F6, F7, D4, D2, D3, D5, D6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#ifdef AUDIO_ENABLE
  #define AUDIO_PIN B5
  #define STARTUP_SONG SONG(ONE_UP_SOUND)
  #define NO_MUSIC_MODE
#endif

#define RGB_DI_PIN F5
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_SLEEP
#define RGBLED_NUM 47
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_EFFECT_KNIGHT_LED_NUM 12
