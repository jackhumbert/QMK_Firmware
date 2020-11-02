#include QMK_KEYBOARD_H

#define LAYERNUM 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, TO(1)),
    [1] = LAYOUT(KC_TRNS, KC_MSTP, KC_MRWD, KC_MFFD, TO(0))
};

int get_icon_start_position(int key_position) {
    if (key_position == 1) {
        return 0;
    } else {
        return (key_position - 1) * 3;
    }
}

void clear_up_down_indicator(void) {
    wait_ms(3000);
    oled_set_cursor(get_icon_start_position(7), 2);
    oled_write_P(PSTR(" "), false);
    oled_set_cursor(get_icon_start_position(7), 3);
    oled_write_P(PSTR(" "), false);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    static const char PROGMEM UP_ICON[] = {0x1E,0};
    static const char PROGMEM DOWN_ICON[] = {0x1F,0};
    if (index == 0) {
        if (layer_state_is(0)) {
            if (clockwise) {
                tap_code(KC_VOLU);
                oled_set_cursor(get_icon_start_position(7), 3);
                oled_write_P(PSTR(" "), false);
                oled_set_cursor(get_icon_start_position(7), 2);
                oled_write_P(UP_ICON, false);
            } else {
                tap_code(KC_VOLD);

                oled_set_cursor(get_icon_start_position(7), 2);
                oled_write_P(PSTR(" "), false);
                oled_set_cursor(get_icon_start_position(7), 3);
                oled_write_P(DOWN_ICON, false);
            }
        } else {
            if (clockwise) {
                tap_code(KC_BRIU);
                oled_set_cursor(get_icon_start_position(7), 3);
                oled_write_P(PSTR(" "), false);
                oled_set_cursor(get_icon_start_position(7), 2);
                oled_write_P(UP_ICON, false);
            } else {
                tap_code(KC_BRID);
                oled_set_cursor(get_icon_start_position(7), 2);
                oled_write_P(PSTR(" "), false);
                oled_set_cursor(get_icon_start_position(7), 3);
                oled_write_P(DOWN_ICON, false);
            }
        }
    }
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

void draw_mute_icon(int key_position, int row) {
    static const char PROGMEM ICON_MUTE_0[] = {0x88, 0x89, 0};
    static const char PROGMEM ICON_MUTE_1[] = {0xA8, 0xA9, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_MUTE_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_MUTE_1, false);
}

void draw_play_icon(int key_position, int row) {
    static const char PROGMEM ICON_PLAY_0[] = {0x8A, 0x8B, 0};
    static const char PROGMEM ICON_PLAY_1[] = {0xAA, 0xAB, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_PLAY_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_PLAY_1, false);
}

void draw_rewind_icon(int key_position, int row) {
    static const char PROGMEM ICON_REWIND_0[] = {0x8C, 0x8D, 0};
    static const char PROGMEM ICON_REWIND_1[] = {0xAC, 0xAD, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_REWIND_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_REWIND_1, false);
}

void draw_fast_forward_icon(int key_position, int row) {
    static const char PROGMEM ICON_FAST_FORWARD_0[] = {0x8E, 0x8F, 0};
    static const char PROGMEM ICON_FAST_FORWARD_1[] = {0xAE, 0xAF, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_FAST_FORWARD_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_FAST_FORWARD_1, false);
}

void draw_prev_icon(int key_position, int row) {
    static const char PROGMEM ICON_PREV_0[] = {0x90, 0x91, 0};
    static const char PROGMEM ICON_PREV_1[] = {0xB0, 0xB1, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_PREV_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_PREV_1, false);
}

void draw_next_icon(int key_position, int row) {
    static const char PROGMEM ICON_NEXT_0[] = {0x92, 0x93, 0};
    static const char PROGMEM ICON_NEXT_1[] = {0xB2, 0xB3, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_NEXT_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_NEXT_1, false);
}

void draw_stop_icon(int key_position, int row) {
    static const char PROGMEM ICON_STOP_0[] = {0xA0, 0xA1, 0};
    static const char PROGMEM ICON_STOP_1[] = {0xC0, 0xC1, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_STOP_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_STOP_1, false);
}

void draw_sound_icon(int key_position, int row) {
    static const char PROGMEM ICON_SOUND_0[] = {0xA2, 0xA3, 0};
    static const char PROGMEM ICON_SOUND_1[] = {0xC2, 0xC3, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_SOUND_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_SOUND_1, false);
}

void draw_raise_icon(int key_position, int row) {
    static const char PROGMEM ICON_RAISE_0[] = {0xA4, 0xA5, 0};
    static const char PROGMEM ICON_RAISE_1[] = {0xC4, 0xC5, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_RAISE_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_RAISE_1, false);
}

void draw_lower_icon(int key_position, int row) {
    static const char PROGMEM ICON_LOWER_0[] = {0xA6, 0xA7, 0};
    static const char PROGMEM ICON_LOWER_1[] = {0xC6, 0xC7, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_LOWER_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_LOWER_1, false);
}

void draw_brightness_icon(int key_position, int row) {
    static const char PROGMEM ICON_BRIGHTNESS_0[] = {0xB9, 0xBA, 0};
    static const char PROGMEM ICON_BRIGHTNESS_1[] = {0xD9, 0xDA, 0};
    oled_set_cursor(get_icon_start_position(key_position), row);
    oled_write_P(ICON_BRIGHTNESS_0, false);
    oled_set_cursor(get_icon_start_position(key_position), row + 1);
    oled_write_P(ICON_BRIGHTNESS_1, false);
}

void oled_task_user(void) {
    // Host Keyboard Layer Status
    static const char PROGMEM ICON_LAYER[] = {0x80, 0x81, 0x82, 0x83, 0};
    static const char PROGMEM ICON_ENCODER[] = {0x84, 0x85, 0x86, 0x87, 0};
    // static const char PROGMEM ICON_MUTE[] = {0x88, 0x89,0xA9, 0xAA};

    oled_write_P(ICON_LAYER, false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("1ST "), false);
            break;
        case 1:
            oled_write_P(PSTR("2ND "), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_P(PSTR("UNDF"), false);
    }

    oled_write_P(PSTR("     "), false);

    oled_write_P(ICON_ENCODER, false);
    switch(get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("VOL "), false);
            break;
        case 1:
            oled_write_P(PSTR("BRGT"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_P(PSTR("UNDF"), false);
    }

    switch(get_highest_layer(layer_state)) {
        default:
        case 0:
            draw_mute_icon(1, 2);
            draw_play_icon(2, 2);
            draw_prev_icon(3, 2);
            draw_next_icon(4, 2);
            draw_raise_icon(5, 2);
            draw_sound_icon(6, 2);
            break;
        case 1:
            draw_mute_icon(1, 2);
            draw_stop_icon(2, 2);
            draw_rewind_icon(3, 2);
            draw_fast_forward_icon(4, 2);
            draw_lower_icon(5, 2);
            draw_brightness_icon(6, 2);
            break;
    }

    // Host Keyboard LED Status
}

#endif
