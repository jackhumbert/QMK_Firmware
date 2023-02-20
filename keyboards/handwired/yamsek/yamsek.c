/* Copyright 2022 Johannes Schneider (@JohSchneider) */
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include "yamsek.h"

void keyboard_post_init_kb(void) {
    debug_enable=true;
//    debug_mouse=true;
//    debug_matrix=true;

#ifdef RGBLIGHT_ENABLE
    rgblight_sethsv_at(45, 255,20 ,0); // pale yellow
#endif

#ifdef POINTING_DEVICE_ENABLE
    pimoroni_trackball_set_rgbw(0,64,0,0);
#endif

    if (debug_enable) {
        wait_ms(1000); // workaround: usb needs some time to initialize, and qmk console does too to reconnect; without this, early 'print's are lost
        dprint("YaMseK: post_init done :-)\n");
    }
    keyboard_post_init_user();
}
