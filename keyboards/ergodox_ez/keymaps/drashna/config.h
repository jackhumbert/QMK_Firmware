#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include QMK_KEYBOARD_CONFIG_H


#ifdef RGBLIGHT_ENABLE
#undef RGBLIGHT_SAT_STEP 
#define RGBLIGHT_SAT_STEP 12
#define RGBLIGHT_EFFECT_KNIGHT_LENGTH 7
#define RGBLIGHT_EFFECT_SNAKE_LENGTH 7
#define RGBLIGHT_EFFECT_BREATHE_CENTER 1
#endif // RGBLIGHT_ENABLE

#undef PRODUCT
#define PRODUCT         DrashnaDox - Hacked ErgoDox EZ Shine

#endif
