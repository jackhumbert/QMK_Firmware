// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


enum layer_names {
    _BASE,
    _SPECIAL1,
    _SPECIAL2,
    _STANDBY
};

enum custom_keycodes {
    LYR_MUL = SAFE_RANGE,
    LYR_MUR,
    LYR_MDL,
    LYR_MDR,
    NXTAPP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * The matrix is logically this:
     * ┌─────┬─────┬─────┬───────────┐
     * │ 0,0 │ 0,1 │ 0,2 │ 0,3 Enc 1 │
     * ├─────┼─────┼─────┼───────────┤
     * │ 1,0 │ 1,1 │ 1,2 │ 1,3 Enc 2 │
     * ├─────┼─────┼─────┼───────────┤
     * │ 2,0 │ 2,1 │ 2,2 │ 2,3 Enc 3 │
     * ├─────┼─────┼─────┼───────────┤
     * │ 3,0 │ 3,1 │ 3,2 │ 3,3 Enc 4 │
     * └─────┴─────┴─────┴───────────┘
     *
     * But is physically mounted like this:
     *
     *                  ┌───────────┐  ┌───────────┐
     *                  │ 0,3 Enc 1 │  │ 1,3 Enc 2 │
     *                  └───────────┘  └───────────┘
     * ┌─────┬─────┬─────┬─────┐
     * │ 3,0 │ 2,0 │ 1,0 │ 0,0 │       ┌───────────┐
     * ├─────┼─────┼─────┼─────┤       │ 2,3 Enc 3 │
     * │ 3,1 │ 2,1 │ 1,1 │ 0,1 │       └───────────┘
     * ├─────┼─────┼─────┼─────┤       ┌───────────┐
     * │ 3,2 │ 2,2 │ 1,2 │ 0,2 │       │ 3,3 Enc 4 │
     * └─────┴─────┴─────┴─────┘       └───────────┘
     *
     *
     */
    [_BASE] = LAYOUT(
        KC_P3,      KC_P7,      NXTAPP,       KC_BSPC,
        KC_P2,      KC_P6,      KC_DOT,       KC_DEL,
        KC_P1,      KC_P5,      KC_P9,        KC_SPC,
        KC_P0,      KC_P4,      KC_P8,        TO(_SPECIAL1)
    ),
    [_SPECIAL1] = LAYOUT(
        KC_P7,      KC_P8,      KC_P9,      KC_NO,
        KC_P4,      KC_P5,      KC_P6,      KC_NO,
        KC_P1,      KC_P2,      KC_P3,      KC_NO,
        KC_P0,      KC_PENT,    KC_NO,      TO(_SPECIAL2)
    ),
    [_SPECIAL2] = LAYOUT(
        KC_ACL0,    KC_ACL1,    KC_ACL2,    KC_NO,
        LYR_MUR,    KC_MS_R,    LYR_MDR,    KC_NO,
        KC_MS_U,    KC_MS_BTN1, KC_MS_D,    KC_NO,
        LYR_MUL,    KC_MS_L,    LYR_MDL,    TO(_STANDBY)
    ),
    [_STANDBY] = LAYOUT(
        KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,
        KC_NO,      KC_NO,      KC_NO,      TO(_BASE)
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =       { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_UP, KC_DOWN),

                    ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),

                    ENCODER_CCW_CW(KC_WH_U, KC_WH_D)
                    },
    [_SPECIAL1] =   { ENCODER_CCW_CW(KC_TRNS,KC_TRNS),  ENCODER_CCW_CW(KC_MS_L, KC_MS_R),

                    ENCODER_CCW_CW(KC_PGUP, KC_PGDN),

                    ENCODER_CCW_CW(KC_TRNS,KC_TRNS)
                    },
    [_SPECIAL2] =   { ENCODER_CCW_CW(KC_TRNS,KC_TRNS),  ENCODER_CCW_CW(KC_WH_U, KC_WH_D),

                    ENCODER_CCW_CW(KC_PGUP, KC_PGDN),

                    ENCODER_CCW_CW(KC_TRNS,KC_TRNS)
                    },
    [_STANDBY] =    { ENCODER_CCW_CW(KC_NO, KC_NO),     ENCODER_CCW_CW(KC_NO, KC_NO),

                    ENCODER_CCW_CW(KC_NO, KC_NO),

                    ENCODER_CCW_CW(KC_NO, KC_NO)
                    },
};
#endif





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LYR_MUL:
            if (record->event.pressed){
                register_code(KC_MS_U);
                register_code(KC_MS_L);
            } else {
                unregister_code(KC_MS_U);
                unregister_code(KC_MS_L);
            }
            break;
        case LYR_MUR:
            if (record->event.pressed){
                register_code(KC_MS_U);
                register_code(KC_MS_R);
            } else {
                unregister_code(KC_MS_U);
                unregister_code(KC_MS_R);
            }
            break;
        case LYR_MDL:
            if (record->event.pressed){
                register_code(KC_MS_D);
                register_code(KC_MS_L);
            } else {
                unregister_code(KC_MS_D);
                unregister_code(KC_MS_L);
            }
            break;
        case LYR_MDR:
            if (record->event.pressed){
                register_code(KC_MS_D);
                register_code(KC_MS_R);
            } else {
                unregister_code(KC_MS_D);
                unregister_code(KC_MS_R);
            }
            break;
        case NXTAPP:
            if (record->event.pressed){
                SEND_STRING(SS_LGUI("\t"));
            }
            return false;
            break;
    }
    return true;
}




#ifdef OLED_ENABLE

        static void render_logo(void) {
            static const char PROGMEM aks_mls_logo[] = {
                // 'mls_logo_layers_totop', 128x24px
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x18,
                0x08, 0xc4, 0xc4, 0x84, 0x02, 0x02, 0x02, 0x83, 0xc1, 0x01, 0x01, 0xc1, 0xc1, 0x01, 0x01, 0x01,
                0x01, 0x01, 0x03, 0x82, 0xc2, 0x42, 0x44, 0x44, 0x84, 0x08, 0x18, 0x10, 0x20, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x30, 0x40, 0x80, 0x80,
                0x00, 0x3f, 0x01, 0x03, 0x07, 0x02, 0x01, 0x3f, 0x3f, 0x00, 0x00, 0x3f, 0x3f, 0x20, 0x20, 0x20,
                0x20, 0x00, 0x00, 0x13, 0x27, 0x26, 0x26, 0x3e, 0x1c, 0x00, 0x80, 0x80, 0x40, 0x30, 0x0f, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x01, 0x03, 0x07, 0x02, 0x01, 0x3f, 0x3f, 0x00, 0x00,
                0x18, 0x3d, 0x25, 0x25, 0x3f, 0x3e, 0x00, 0x00, 0x1e, 0x3f, 0x21, 0x21, 0x21, 0x00, 0x3f, 0x3f,
                0x02, 0x03, 0x03, 0x00, 0x1e, 0x3f, 0x21, 0x21, 0x3f, 0x1e, 0x00, 0xff, 0xff, 0x21, 0x21, 0x3f,
                0x1e, 0x00, 0x00, 0x18, 0x3d, 0x25, 0x25, 0x3f, 0x3e, 0x00, 0x1e, 0x3f, 0x21, 0x21, 0x3f, 0x3f,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
                0x01, 0x02, 0x02, 0x06, 0x04, 0x04, 0x04, 0x0c, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08,
                0x08, 0x08, 0x0c, 0x04, 0x04, 0x04, 0x06, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
            };
            oled_write_raw_P(aks_mls_logo, sizeof(aks_mls_logo));
        }

        bool oled_init(oled_rotation_t(OLED_ROTATION_0));

        bool oled_task_user(void) {
            render_logo();

            oled_set_cursor(0, 3);
            // oled_write(PSTR("Layer: "), false);

            switch (get_highest_layer(layer_state)) {
                case _BASE:
                    // oled_write_ln(PSTR("Base"), false);
                    oled_write_ln(PSTR("_Base Layer"), false);
                    oled_advance_page(true);
                    oled_advance_page(true);
                    break;
                case _SPECIAL1:
                    // oled_write_ln(PSTR("Special1"), false);
                    oled_write_ln(PSTR("_Special1 Layer"), false);
                    oled_advance_page(true);
                    break;
                case _SPECIAL2:
                    // oled_write_ln(PSTR("Special2"), false);
                    oled_write_ln(PSTR("_Special2 Layer"), false);
                    oled_advance_page(true);
                    oled_advance_page(true);
                    break;
                case _STANDBY:
                    oled_write_ln(PSTR("_Standby Layer"), false);
                    oled_write_ln(PSTR("Keys do nothing"), false);
                    oled_write_ln(PSTR("Layer key re-engages"),     false);
                break;
                default:
                    oled_write_ln_P(PSTR("Undefined"), false);
                    oled_advance_page(true);
                    oled_advance_page(true);

            }

            return false;
        }

        // bool oled_task_kb(void) {
        //     oled_set_cursor(0,8);
        //     oled_write_ln(PSTR("Key Pressed"), false);
        //     return false;
        // }

#endif
