/*
 * Copyright 2024 João Silva @https://github.com/Ghost-Spot
 *
 * This is an adaptation of several pieces of code
 * I found online, starting from a copy of a sofle,
 * as it as the same layout (minus 2 thumb keys),
 * an OLED and an encoder, on each half.
 *
 * Use this at your own discretion!
 *
 */

#pragma once

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */