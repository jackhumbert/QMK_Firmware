#include QMK_KEYBOARD_H
#include "keymap.h"
#include "settings.h"

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return OLED_ROTATION_270;
}

// static void render_logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//         0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//     };
// 
//     oled_write_P(qmk_logo, false);
// }
uint16_t texts = 0;
static void render_left(void) {
    oled_clear();

    // oled_set_cursor(0, 2);

    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
    // switch (get_highest_layer(layer_state)) {
    //     case _QWERTY:
    //         oled_write_P(PSTR("Default\n"), false);
    //         break;
    //     case _LOWER:
    //         oled_write_P(PSTR("Lower\n"), false);
    //         break;
    //     case _RAISE:
    //         oled_write_P(PSTR("Raise\n"), false);
    //         break;
    //     case _ADJUST:
    //         oled_write_P(PSTR("Adjust\n"), false);
    //         break;
    //     default:
    //         oled_write_P(PSTR("Undefined\n"), false);
    // }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();

    oled_set_cursor(0, 0);
    if (IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)) oled_write_P(PSTR("C"), false);

    oled_set_cursor(1, 0);
    if (user_config.dead_keys) oled_write_P(PSTR("D"), false);

    oled_set_cursor(2, 0);
    if (IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)) oled_write_P(PSTR("N"), false);

    oled_set_cursor(3, 0);
    if (IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK)) oled_write_P(PSTR("S"), false);

    for (uint8_t i=0; i<oled_max_chars();i++) {
        oled_set_cursor(i, 1);
        oled_write_P(PSTR("\x80"), false);
    }
}

static void render_right(void) {
  oled_write_P(PSTR("WPM: "), false);
  char snum[5];
  itoa(get_current_wpm(), snum, 10);
  oled_write(snum, false);
}

uint16_t render_timer = 0;
void oled_task_user(void) {
    if (timer_elapsed(render_timer) >= 1000 / OLED_FRAMERATE) {
        if (is_keyboard_master()) {
            render_left(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        } else {
            render_right(); 
        }
        render_timer = timer_read();
    }
}
#endif