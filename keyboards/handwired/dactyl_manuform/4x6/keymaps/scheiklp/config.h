// Copyright 2021 Paul Maria Scheikl (@ScheiklP)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


#define USE_I2C
#define SPLIT_HAND_PIN F6

#undef WS2812_DI_PIN
#undef RGBLED_NUM

#define DEBOUNCE 5

#define AUTO_SHIFT_TIMEOUT 100
#define NO_AUTO_SHIFT_SPECIAL
#define NO_AUTO_SHIFT_NUMERIC

// require two taps for a TT layer switch (default 5)
#define TAPPING_TOGGLE 2

// Mouse control
// constant mode (velocity)
#define MK_3_SPEED
// KC_ACL0 < KC_ACL1 < unmodified < KC_ACL2

// Cursor offset per movement (unmodified)
#define MK_C_OFFSET_UNMOD 16
// Time between cursor movements (unmodified)
#define MK_C_INTERVAL_UNMOD 10
/* #define MK_C_INTERVAL_UNMOD 16 */

// Cursor offset per movement (KC_ACL0)
#define MK_C_OFFSET_0 1
// Time between cursor movements (KC_ACL0)
#define MK_C_INTERVAL_0 32

// Cursor offset per movement (KC_ACL1)
#define MK_C_OFFSET_1 4
// Time between cursor movements (KC_ACL1)
#define MK_C_INTERVAL_1 16

// Cursor offset per movement (KC_ACL2)
#define MK_C_OFFSET_2 20
/* #define MK_C_OFFSET_2 32 */
// Time between cursor movements (KC_ACL2)
#define MK_C_INTERVAL_2 16
