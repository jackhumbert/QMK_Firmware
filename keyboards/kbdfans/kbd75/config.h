// Copyright 2017-2021 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


/* key matrix pins */
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D5, B7 }
#define MATRIX_COL_PINS { F0, F1, E6, C7, C6, F5, D4, B1, B0, B5, B4, D7, D6, B3, F4, F6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN E2
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 16
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#define RGBLIGHT_SLEEP
/* If defined, the RGB lighting will be switched off when the host goes to sleep */
#define RGBLIGHT_SLEEP
#endif
