#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

// ws2812 options
#define RGB_DI_PIN D2 // pin the DI on the ws2812 is hooked-up to
#define RGBLED_NUM 8 // number of LEDs
#define RGBLIGHT_ANIMATIONS
