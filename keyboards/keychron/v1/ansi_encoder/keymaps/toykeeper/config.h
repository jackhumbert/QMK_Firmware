// Copyright 2022 Selene ToyKeeper
// SPDX-License-Identifier: GPL-2.0-or-later
// config.h for ToyKeeper's Keychron V1 layout
#pragma once

#define KEYMAP_URL "http://toykeeper.net/keyboard/qmk/tk-q1-v1.png"

///// personal config stuff /////

#define HAS_RGB
#define HAS_DIPSWITCH
#define HAS_F_ROW
#define USE_NUMPAD
//#define USE_CAPSWORD_KLUDGE  // improve CapsWord when host remaps the keys?


// my space bar keeps double-triggering, and it happens slowly
// (all other keys seem fine though)
#ifdef DEBOUNCE
#undef DEBOUNCE
#endif
#define DEBOUNCE 50  // default 5


#ifdef HAS_RGB

    ///// RGB stuff... /////
    // https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-lighting

    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255

    // disable backlight when USB suspended (PC sleep/hibernate/shutdown)
    #undef  RGB_DISABLE_WHEN_USB_SUSPENDED
    #define RGB_DISABLE_WHEN_USB_SUSPENDED 1

    // disable backlight after timeout in minutes, 0 = no timeout
    #define RGB_MATRIX_TIMEOUT (1000*60*5)  // 5 minutes
    #define RGB_DISABLE_TIMEOUT RGB_MATRIX_TIMEOUT

    // reactive RGB effects
    #define RGB_MATRIX_KEYPRESSES
    #undef RGB_MATRIX_KEYRELEASES

    // turn off all RGB Matrix effects, then selectively enable the ones I like
    #undef ENABLE_RGB_MATRIX_ALPHAS_MODS
    #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
    #undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
    #undef ENABLE_RGB_MATRIX_BAND_SAT
    #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
    #undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
    #undef ENABLE_RGB_MATRIX_BAND_VAL
    #undef ENABLE_RGB_MATRIX_BREATHING
    #undef ENABLE_RGB_MATRIX_CYCLE_ALL
    #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
    #undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
    #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
    #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
    #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
    #undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
    #undef ENABLE_RGB_MATRIX_DUAL_BEACON
    #undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
    #undef ENABLE_RGB_MATRIX_HUE_BREATHING
    #undef ENABLE_RGB_MATRIX_HUE_PENDULUM
    #undef ENABLE_RGB_MATRIX_HUE_WAVE
    #undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
    #undef ENABLE_RGB_MATRIX_MULTISPLASH
    #undef ENABLE_RGB_MATRIX_PIXEL_FLOW
    #undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL
    #undef ENABLE_RGB_MATRIX_PIXEL_RAIN
    #undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
    #undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
    #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
    #undef ENABLE_RGB_MATRIX_RAINDROPS
    #undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #undef ENABLE_RGB_MATRIX_SOLID_SPLASH
    #undef ENABLE_RGB_MATRIX_SPLASH
    #undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #undef RGB_MATRIX_FRAMEBUFFER_EFFECTS

    #define ENABLE_RGB_MATRIX_MULTISPLASH

    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_DEFAULT_MODE
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_MULTISPLASH

#endif

