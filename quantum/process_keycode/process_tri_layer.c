// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "process_tri_layer.h"
#include "action_layer.h"

extern uint8_t tri_layer_lower_layer;
extern uint8_t tri_layer_raise_layer;
extern uint8_t tri_layer_adjust_layer;

bool process_tri_layer(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TRI_LAYER_LOWER:
            if (record->event.pressed) {
                layer_on(tri_layer_lower_layer);
                update_tri_layer(tri_layer_lower_layer, tri_layer_raise_layer, tri_layer_adjust_layer);
            } else {
                layer_off(tri_layer_lower_layer);
                update_tri_layer(tri_layer_lower_layer, tri_layer_raise_layer, tri_layer_adjust_layer);
            }
            return false;
            break;
        case QK_TRI_LAYER_RAISE:
            if (record->event.pressed) {
                layer_on(tri_layer_raise_layer);
                update_tri_layer(tri_layer_lower_layer, tri_layer_raise_layer, tri_layer_adjust_layer);
            } else {
                layer_off(tri_layer_raise_layer);
                update_tri_layer(tri_layer_lower_layer, tri_layer_raise_layer, tri_layer_adjust_layer);
            }
            return false;
            break;
    }
    return true;
}
