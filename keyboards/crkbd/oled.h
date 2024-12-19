// The next section is only applicable if OLEDs are enabled.
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void oled_render_logo(void) {
    // clang-format off
    static const char PROGMEM marley_katakana[] = {
        // https://javl.github.io/image2cpp/
        // Code Output: Plain Bytes; Draw Mode: Vertical; Rotate Image: 0 degrees
        // 'marley katakana_rotated.jpg'; 128x32px   
        // (source image was rotated 90 degrees to lay horizontally
        // with the bottom of the image on the left and the top of the image on the right)
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 
        0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0e, 0x0f, 0x0f, 0x1f, 
        0x1f, 0x1f, 0x3f, 0x3f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x0f, 0x0f, 0x03, 0x01, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xc0, 0xc0, 0xc0, 0xe0, 0xe0, 
        0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 
        0x38, 0x00, 0x00, 0x01, 0x0f, 0x3f, 0xff, 0xff, 0xf1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0f, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x1c, 0x3c, 0x78, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 
        0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf4, 0xfc, 0x78, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0f, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 
        0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x7c, 0x7e, 0x3f, 0x3f, 0x1f, 0x07, 0x0f, 
        0x3e, 0x7c, 0xf8, 0xf0, 0xe0, 0xe0, 0xc1, 0xcf, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x0f, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    // clang-format on
    oled_write_raw_P(marley_katakana, sizeof(marley_katakana));
}

void oled_render_status(void) {

    // Print layer status
    oled_set_cursor(0, 0);
    oled_write("LAYER", false);

    oled_set_cursor(0, 2);
    switch (get_highest_layer(layer_state)) {

        case _COLEMAK_DH:
            oled_write("COLMK", false);
            break;

        case _NUMBER:
            oled_write("NUMBR", false);
            break;

        case _SYMBOL:
            oled_write("SYMBL ", false);
            break;

        case _FUNCTION:
            oled_write("FNCTN", false);
            break;

        case _NAVIGATION:
            oled_write("NVGTN", false);
            break;

        case _MOUSE:
            oled_write("MOUSE", false);
            break;

        case _RGB:
            oled_write("RGBLT", false);
            break;

    default:
            oled_write("UNDEF", false);

    }

    led_t led_usb_state = host_keyboard_led_state();

    // print num lock status
    oled_set_cursor(0, 8);
    if(led_usb_state.num_lock) {
        oled_write("NUMLK", true);
    } else {
        oled_write("     ", false);
    }
    
    // print scroll lock status
    oled_set_cursor(0, 10);
    if (led_usb_state.scroll_lock) {
        oled_write("SCRLK", true);
    } else {
        oled_write("     ", false);
    }

    // print caps lock status
    oled_set_cursor(0, 12);
    if (led_usb_state.caps_lock) {
        oled_write("CPSLK", true);
    } else {
        oled_write("     ", false);
    }

}

bool oled_task_user(void) {
    
    if (is_keyboard_master()) {
        oled_render_status();
    } else {
        oled_render_logo();
    }

    return false;
}

#endif // End OLED_ENABLE