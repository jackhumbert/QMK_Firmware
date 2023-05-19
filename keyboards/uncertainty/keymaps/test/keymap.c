#include QMK_KEYBOARD_H


#include "print.h"
#include <stdio.h>
char wpm_str[10];
typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

/* Encoder mapping */
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)  }
};
#endif

/* Keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0
    *        ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
    *        │ Esc  │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │PrtScn│  Del │ Home │  End │ PgUp │ PgDn │
    *        ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┴──────┼──────┼──────┼──────┼──────┤
    *        │   `  │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │  -   │  =   │    Bksp     │ # Lk │   /  │   *  │  -   │
    * ┌──────┼──────┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬─────────┼──────┼──────┼──────┼──────┤
    * │ Mute │   Tab    │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │  [   │  ]   │    \    │  7   │  8   │  9   │      │
    * ├──────┼──────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─────────┼──────┼──────┼──────┤  +   |
    * │ Null │   Caps     │   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │    Enter     │  4   │  5   │  6   │      |
    * ├──────┼────────────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴─┬────┴───────┬──────┼──────┤──────┼──────┼──────┤
    * │ Null │     Shft     │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │    Shft    │  Up  │  1   │  2   │  3   │      │
    * ├──────┼───────┬──────┴┬─────┴─┬────┴──────┴──────┴──────┴──────┴──────┴─────┬┴─────┬┴─────┬┴─────┬──────┼──────┼──────┼──────┼──────┤ Entr |
    * │ Null │ Ctrl  │ Gui   │ Alt   │                  Space                      │ Alt  │   Fn │ Ctrl │ Left │ Down │ Right│  0   │   .  │      │
    * └──────┴───────┴───────┴───────┴─────────────────────────────────────────────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
    */
    [0] = LAYOUT(
                 KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_DEL,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, 
                 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC         , KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, 
        TD_OLED, KC_TAB   ,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS      , KC_P7,   KC_P8,   KC_P9,   KC_PPLS, 
        XXXXXXX, KC_CAPS     , KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT             ,  KC_P4,   KC_P5,   KC_P6,   
        XXXXXXX, KC_LSFT      , KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT            , KC_UP,   KC_P1,   KC_P2,   KC_P3,   KC_PENT, 
        XXXXXXX, KC_LCTL  , KC_LGUI  , KC_LALT  ,                    KC_SPC                           ,  KC_RALT, MO(1)   , KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0,   KC_PDOT  
    )
};
/* end Keymap */

/* OLED test */
enum tap_dances {
    TD_OLED,
};
enum oled_test_modes {
    // Modes between TEST_FIRST and TEST_LAST (inclusive) can be switched with a keypress.
    TEST_FIRST,
    TEST_LOGO = TEST_FIRST,
    TEST_CHARACTERS,
    TEST_SLOW_UPDATE,
    TEST_ALL_ON,
    TEST_FRAME,
    TEST_ALL_OFF,
    TEST_FILL_HORZ_0,
    TEST_FILL_HORZ_1,
    TEST_FILL_VERT_0,
    TEST_FILL_VERT_1,
    TEST_FILL_CHECKERBOARD_1,
    TEST_FILL_CHECKERBOARD_2,
    TEST_FILL_CHECKERBOARD_4,
    TEST_LAST = TEST_FILL_CHECKERBOARD_4,

    // Special modes which are not reachable normally.
    TEST_DRAW_ALWAYS_ON,
    TEST_DRAW_ALWAYS_OFF,
};

static enum oled_test_modes test_mode = TEST_FIRST;

static oled_rotation_t rotation = OLED_ROTATION_0;

static bool     scrolling;
static uint8_t  scrolling_speed;
static bool     need_update = true;
static bool     draw_always;
static bool     update_speed_test;
static uint32_t update_speed_start_timer;
static uint16_t update_speed_count;
static bool     restart_test;

static void stop_scrolling(void) {
    if (scrolling) {
        oled_scroll_off();
        scrolling = false;
    }
}

static void dance_oled_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            if (state->pressed) {
                // single hold - step through rotations
                switch (rotation) {
                    case OLED_ROTATION_0:
                        rotation = OLED_ROTATION_90;
                        break;
                    case OLED_ROTATION_90:
                        rotation = OLED_ROTATION_180;
                        break;
                    case OLED_ROTATION_180:
                        rotation = OLED_ROTATION_270;
                        break;
                    default:
                        rotation = OLED_ROTATION_0;
                        break;
                }
                stop_scrolling();
                oled_init(rotation);
            } else {
                // single tap - step through test modes
                if (test_mode < TEST_LAST) {
                    ++test_mode;
                } else {
                    test_mode = TEST_FIRST;
                }
                stop_scrolling();
                oled_clear();
            }
            restart_test = true;
            need_update  = true;
            break;

        case 2:
            if (state->pressed) {
                // tap + hold - change scrolling speed
                scrolling_speed = (scrolling_speed + 1) % 8;
                stop_scrolling();
                oled_scroll_set_speed(scrolling_speed);
                // Cannot reactivate scrolling here, because oled_scroll_off()
                // marks the whole display as dirty, and oled_scroll_left()
                // silently does nothing if either the display is dirty or
                // scrolling is already active.
            } else {
                // double tap - toggle scrolling
                if (!scrolling) {
                    scrolling = true;
                    oled_scroll_left();
                } else {
                    scrolling = false;
                    oled_scroll_off();
                }
            }
            need_update = true;
            break;

        case 3:
            if (state->pressed) {
                // double tap + hold - toggle `draw_always`
                draw_always = !draw_always;
                if (draw_always) {
                    test_mode = TEST_DRAW_ALWAYS_ON;
                } else {
                    test_mode = TEST_DRAW_ALWAYS_OFF;
                }
                stop_scrolling();
                oled_clear();
                restart_test = true;
                need_update  = true;
            } else {
                // triple tap - toggle update speed test
                update_speed_test = !update_speed_test;
                if (update_speed_test) {
                    stop_scrolling();
                    update_speed_start_timer = timer_read32();
                    update_speed_count       = 0;
                }
            }
            break;
        case 4:
            if (!state->pressed) {
                // quadruple tap - step through brightness levels
                oled_set_brightness(oled_get_brightness() + 0x10);
            }
            break;
        default:
            break;
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {[TD_OLED] = ACTION_TAP_DANCE_FN(dance_oled_finished)};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {LAYOUT_ortho_1x1(TD(TD_OLED))};

// `bool oled_is_dirty(void)` does not exist at the moment
extern OLED_BLOCK_TYPE oled_dirty;

static inline uint8_t pixel_width(void) {
    if (!(rotation & OLED_ROTATION_90)) {
        return OLED_DISPLAY_WIDTH;
    }
    return OLED_DISPLAY_HEIGHT;
}

static inline uint8_t pixel_height(void) {
    if (!(rotation & OLED_ROTATION_90)) {
        return OLED_DISPLAY_HEIGHT;
    }
    return OLED_DISPLAY_WIDTH;
}

// Draw the QMK logo at the top left corner, clipping if it does not fit.
static void test_logo(void) {
    uint8_t lines = oled_max_lines();
    if (lines > 3) {
        lines = 3;
    }
    uint8_t chars = oled_max_chars();
    if (chars > 21) {
        chars = 21;
    }
    for (uint8_t row = 0; row < lines; ++row) {
        oled_set_cursor(0, row);
        for (uint8_t col = 0; col < chars; ++col) {
            oled_write_char(0x80 + 0x20 * row + col, false);
        }
    }
}

static const PROGMEM char fill_ff[OLED_MATRIX_SIZE] = {[0 ... OLED_MATRIX_SIZE - 1] = 0xff};

// Fill the whole screen with a pattern made from two bytes alternating after the specified number of repeats.
static void test_fill(uint8_t byte0, uint8_t byte1, uint8_t repeats) {
    uint8_t  width = pixel_width();
    uint8_t  lines = oled_max_lines();
    uint16_t index = 0;
    for (uint8_t row = 0; row < lines; ++row) {
        for (uint8_t col = 0; col < width; ++col) {
            uint8_t byte = ((col / repeats) % 2) ? byte1 : byte0;
            oled_write_raw_byte(byte, index++);
        }
    }
}

// Draw a frame at the edges of the OLED screen.
static void test_frame(void) {
    uint8_t width  = pixel_width();
    uint8_t height = pixel_height();
    for (uint8_t x = 0; x < width; ++x) {
        oled_write_pixel(x, 0, true);
        oled_write_pixel(x, height - 1, true);
    }
    for (uint8_t y = 1; y < height - 1; ++y) {
        oled_write_pixel(0, y, true);
        oled_write_pixel(width - 1, y, true);
    }
}

// Use all 94 visible ASCII characters for testing.
#define TEST_CHAR_COUNT ('~' - '!' + 1)

static char get_test_char(uint8_t char_index) { return char_index + '!'; }

// Fill the whole screen with distinct characters (if the display is large enough to show more than 94 characters
// at once, the sequence is repeated the second time with inverted characters).
static void test_characters(void) {
    uint8_t cols       = oled_max_chars();
    uint8_t rows       = oled_max_lines();
    bool    invert     = false;
    uint8_t char_index = 0;
    for (uint8_t row = 0; row < rows; ++row) {
        for (uint8_t col = 0; col < cols; ++col) {
            oled_write_char(get_test_char(char_index), invert);
            if (++char_index >= TEST_CHAR_COUNT) {
                char_index = 0;
                invert     = !invert;
            }
        }
    }
}

// Test screen updating after drawing a single character or pixel.
void test_slow_update(void) {
    static uint8_t  phase, x, y, char_index, first_char;
    static uint16_t timer;
    static uint16_t delay = 500;

    if (restart_test) {
        // Initialize all state variables before starting the test.
        restart_test = false;
        phase        = 0;
        x            = 0;
        y            = 0;
        char_index   = 0;
        first_char   = 0;
        delay        = 500;
    } else {
        // Wait for the specified time between steps.
        if (timer_elapsed(timer) < delay) {
            return;
        }
    }

    timer = timer_read();
    switch (phase) {
        case 0:
            // Phase 0: fill the whole screen with mostly distinct characters, one character at a time.  Here the
            // inversion trick is not used, so that the frame which is drawn in subsequent phases would not be
            // overlapped by the inverted character background.
            oled_set_cursor(x, y);
            oled_write_char(get_test_char(char_index), false);
            if (++char_index >= TEST_CHAR_COUNT) {
                char_index = 0;
            }
            if (++x >= oled_max_chars()) {
                x = 0;
                if (++y >= oled_max_lines()) {
                    // The whole screen was filled - start the next phase.
                    ++phase;
                    x = y = 0;
                }
            }
            delay = 250;
            break;

        case 1:
            // Phase 1: draw a line along the left edge of the screen, one pixel at a time.
            oled_write_pixel(x, y, true);
            if (y < pixel_height() - 1) {
                ++y;
            } else {
                // The bottom left corner is reached - start the next phase.
                ++phase;
                ++x;
            }
            delay = 50;
            break;

        case 2:
            // Phase 2: draw a line along the bottom edge of the screen, one pixel at a time.
            oled_write_pixel(x, y, true);
            if (x < pixel_width() - 1) {
                ++x;
            } else {
                // The bottom right corner was reached - start the next phase.
                ++phase;
                --y;
            }
            delay = 50;
            break;

        case 3:
            // Phase 3: draw a line along the right edge of the screen, one pixel at a time.
            oled_write_pixel(x, y, true);
            if (y > 0) {
                --y;
            } else {
                // The top right corner was reached - start the next phase.
                ++phase;
                --x;
            }
            delay = 50;
            break;

        case 4:
            // Phase 4: draw a line along the top edge of the screen, one pixel at a time.
            oled_write_pixel(x, y, true);
            if (x > 0) {
                --x;
            } else {
                // The top left corner was reached - start the next phase.
                ++phase;
            }
            delay = 50;
            break;

        default:
            // Restart from phase 0, but change the first character of the sequence to make screen updates visible.
            if (++first_char >= TEST_CHAR_COUNT) {
                first_char = 0;
            }
            phase      = 0;
            x          = 0;
            y          = 0;
            char_index = first_char;
            delay      = 500;
            break;
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_scroll_set_area(0, 0);
    oled_scroll_set_speed(scrolling_speed);
    return rotation;
}

bool oled_task_user(void) {
    if (update_speed_test) {
        // Speed test mode - wait for screen update completion.
        if (!oled_dirty) {
            // Update statistics and send the measurement result to the console.
            update_speed_count++;
            if (update_speed_count % 256 == 0) {
                uprintf("OLED: %u updates, %lu ms\n", update_speed_count, timer_elapsed32(update_speed_start_timer));
            }

            // Toggle between the "all on" and "all off" states and trigger the screen update again.
            if (test_mode == TEST_ALL_ON) {
                test_mode = TEST_ALL_OFF;
            } else {
                test_mode = TEST_ALL_ON;
            }
            need_update = true;
        }
    }

    // The sample implementation of oled_task_user() in the documentation redraws the image after every call, relying on
    // the fact that drawing functions check whether the output actually changes anything in the image, and set dirty
    // bits only when something has actually changed.  However, redrawing the image only when some of the underlying
    // data has changed is more efficient.  Make it possible to test both modes here.
    if (!draw_always || update_speed_test) {
        // Draw the image only when the `need_update` flag is set, except for the "slow update" test.
        // This mode is also forced when the screen update speed test is performed.
        if (!need_update) {
            if (test_mode != TEST_SLOW_UPDATE) {
                return false;
            }
        }
        need_update = false;
    }

    switch (test_mode) {
        case TEST_LOGO:
            test_logo();
            break;
        case TEST_CHARACTERS:
            test_characters();
            break;
        case TEST_SLOW_UPDATE:
            test_slow_update();
            break;
        case TEST_ALL_ON:
            oled_write_raw_P(fill_ff, sizeof(fill_ff));
            break;
        case TEST_FRAME:
            test_frame();
            break;
        case TEST_ALL_OFF:
            // `oled_clear()` is faster, but cannot be used with `draw_always`, because it does not check the previous
            // content of the buffer and always marks the whole buffer as dirty.
            if (update_speed_test) {
                oled_clear();
            } else {
                test_fill(0x00, 0x00, 1);
            }
            break;
        case TEST_FILL_HORZ_0:
            test_fill(0x55, 0x55, 1);
            break;
        case TEST_FILL_HORZ_1:
            test_fill(0xaa, 0xaa, 1);
            break;
        case TEST_FILL_VERT_0:
            test_fill(0xff, 0x00, 1);
            break;
        case TEST_FILL_VERT_1:
            test_fill(0x00, 0xff, 1);
            break;
        case TEST_FILL_CHECKERBOARD_1:
            test_fill(0x55, 0xaa, 1);
            break;
        case TEST_FILL_CHECKERBOARD_2:
            test_fill(0x33, 0xcc, 2);
            break;
        case TEST_FILL_CHECKERBOARD_4:
            test_fill(0x0f, 0xf0, 4);
            break;

        case TEST_DRAW_ALWAYS_ON:
            oled_write_P(PSTR("Draw Always"), false);
            break;
        case TEST_DRAW_ALWAYS_OFF:
            oled_write_P(PSTR("Draw Once"), false);
            break;
    }
    return false;
}
/* -------------------------------------------------------------------*/
/* end OLED test */

user_config_t user_config;

/* RGB Test */
#ifdef RGBLIGHT_ENABLE
// Light LEDs 0 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}       // Light 1 LEDs, starting with LED 0
);

// Light LEDs 1 red when num lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_GREEN}       // Light 1 LEDs, starting with LED 1
);

const rgblight_segment_t PROGMEM indicators_off_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_OFF}       // Light 1 LEDs, starting with LED 1
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    indicators_off_layer,
    my_capslock_layer,
    my_numlock_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.num_lock);
    return true;
}

/* end RGB Test */

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_cyan();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);

    // // Enable the LED layers
    // rgblight_layers = my_rgb_layers;
    // rgblight_set_layer_state(0, 1);
    // // rgblight_mode_noeeprom(RGBLIGHT_EFFECT_KNIGHT);
    // rgblight_set_effect_range(2, 6);
    
    // rgblight_enable();
    // //rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);

}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case :
      if (record->event.pressed) {
        // Do something when pressed
      } else {
        // Do something else when release
        print("begin rgb_mod\n");
        user_config.raw= eeconfig_read_user();
        uprintf("pre raw value: %lx\n", user_config.raw);

        user_config.rgb_layer_change = !user_config.rgb_layer_change;
        eeconfig_update_user(user_config.raw);

        user_config.raw= eeconfig_read_user();
        uprintf("post raw value: %lx\n", user_config.raw);
        print("done release rgb_mod\n");

        #ifdef RGBLIGHT_ENABLE
        print("begin change rgb mode\n");
        rgblight_step();
        print("done change rgb mode\n");
        #endif

      }
      return false; // Skip all further processing of this key
      default:
      return true; // Process all other keycodes normally
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 2;
  user_config.rgb_layer_change = true; // We want this enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now

  // use the non noeeprom versions, to write these values to EEPROM too
//   rgblight_enable(); // Enable RGB by default
//   rgblight_sethsv_cyan();  // Set it to CYAN by default
//   rgblight_mode(1); // set to solid by default
}

// void keyboard_post_init_user(void) {

//     debug_enable=true;
//     debug_matrix=true;

// }
