#pragma once
#define ENCODER_DIRECTION_FLIP
#define OLED_TIMEOUT 10000

#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTION 4
#endif
#define TAPPING_TERM_PER_KEY
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif
#ifdef MANUFACTURER
    #undef MANUFACTURER
    #define MANUFACTURER Flare576
#endif
