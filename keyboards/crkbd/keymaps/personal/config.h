#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options..
*/

/* Memory saving*/
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

#define LAYER_STATE_8BIT // Up to 8 layers
//#define CUSTOM_LAYER_READ // if you remove this it causes issues - needs better guarding

// Keyboard matrix print
// wiring of each half
//#define SPLIT_USB_DETECT
//#define EE_HANDS
#define MASTER_RIGHT

// Tapdancing
//#define TAPPING_TERM 200

// Memory Saver
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT
#define DISABLE_LEADER

// Number of combos used
//#define COMBO_COUNT 3
//#define ONESHOT_TAP_TOGGLE 1
//#define ONESHOT_TIMEOUT 5000

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LIMIT_VAL 160 //Power draw may exceed 0.6A at max brightness with white colour.
    #define RGBLIGHT_LAYERS
    #define SPLIT_LED_STATE_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define RGBLIGHT_MAX_LAYERS 5
    #define RGBLIGHT_SLEEP
    #define RGBLIGHT_EFFECT_BREATHING

    #undef  RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE


    #define RGBLED_NUM 54 // Number of LEDs
    #define RGBLIGHT_SPLIT
    #define RGBLED_SPLIT { 27, 27 }
#endif

/*
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define RGB_MATRIX_KEYPRESSES
#    define RGB_MATRIX_DEFAULT_SPD 170

#    undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#    undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#    undef ENABLE_RGB_MATRIX_BREATHING
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SAT
#    undef ENABLE_RGB_MATRIX_BAND_VAL
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#    undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#    undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#    undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    undef ENABLE_RGB_MATRIX_DUAL_BEACON
#    undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#    undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    undef ENABLE_RGB_MATRIX_RAINDROPS
#    undef ENABLE_RGB_MATRIX_RAINDROPS
#    undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#    undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#    undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#    undef ENABLE_RGB_MATRIX_SPLASH
#    undef ENABLE_RGB_MATRIX_MULTISPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#    undef ENABLE_RGB_MATRIX_SOLID_COLOR

#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE

#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_WIDE

#endif
*/
#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
