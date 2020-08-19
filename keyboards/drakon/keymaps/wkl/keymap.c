/* Copyright 2020 jagdpietr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

char wpm_str[10];

// Defines names for use in layer keycodes and the keymap
enum Layer_names {
_Base,
_FN,
_Lyr2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_Base] = LAYOUT_wkl(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_DEL,            KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,            KC_MPRV, KC_MPLY, KC_MNXT,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                      KC_MSTP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
        KC_LCTL,          KC_LALT, KC_SPC,                                               KC_APP,  MO(_FN),          KC_LEFT, KC_DOWN,  KC_RIGHT
    ),

    [_FN] = LAYOUT_wkl(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_TRNS,             KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                      KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,
        KC_TRNS,          KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END
    ),

    [_Lyr2] = LAYOUT_wkl(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS,             KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,                      KC_TRNS,
        KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP,
        KC_TRNS,          KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS,          KC_HOME, KC_PGDN, KC_END
    )

};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

void encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;  // flips the display 90 degrees if offhand

}

void render_status(void) {
    //Host Keyboard Layer Status
    oled_set_cursor(0,10);
    oled_write_P(PSTR("Lyr: "), false);

    switch (get_highest_layer(layer_state)) {
        case _Base:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _Lyr2:
            oled_write_P(PSTR("Lyr2\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_set_cursor(0,12);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);

}

//Credits to u/Pop-X- for letting me use his keymap as reference
// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 128 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x60, 
        0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x0c, 0x06, 0x03, 0x81, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x04, 0x0c, 0x18, 0x10, 0x18, 0x08, 0xf8, 0x00, 0x00, 0x00, 
        0x00, 0x3e, 0x23, 0x20, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10, 0x30, 0x21, 0x21, 0x63, 0x43, 0x42, 
        0xc0, 0x80, 0x88, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x73, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x05, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x06, 0x04, 0x0c, 0x08, 0x0b, 0x08, 0x00
        },
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x30, 0x10, 0x08, 0x04, 0x04, 0x06, 0x01, 0x01, 0x06, 
        0x04, 0x0c, 0x08, 0x18, 0x10, 0x30, 0x20, 0x40, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0x00, 0x00, 
        0xe0, 0x98, 0x04, 0x03, 0x01, 0x80, 0x80, 0x80, 0x80, 0x84, 0x86, 0x80, 0x08, 0x18, 0x10, 0x00, 
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x78, 0x87, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 
        0x02, 0x02, 0x0e, 0x3e, 0x20, 0x20, 0x20, 0x10, 0x10, 0x18, 0x18, 0x10, 0x10, 0x33, 0x3e, 0x00
        },
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x60, 
        0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x0c, 0x06, 0x03, 0x81, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x04, 0x0c, 0x18, 0x10, 0x18, 0x08, 0xf8, 0x00, 0x00, 0x00, 
        0x00, 0x3e, 0x23, 0x20, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10, 0x30, 0x21, 0x21, 0x63, 0x43, 0x42, 
        0xc0, 0x80, 0x88, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x73, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x05, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x06, 0x04, 0x0c, 0x08, 0x0b, 0x08, 0x00
        },
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x30, 0x10, 0x08, 0x04, 0x04, 0x06, 0x01, 0x01, 0x06, 
        0x04, 0x0c, 0x08, 0x18, 0x10, 0x30, 0x20, 0x40, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0x00, 0x00, 
        0xe0, 0x98, 0x04, 0x03, 0x01, 0x80, 0x80, 0x80, 0x80, 0x84, 0x86, 0x80, 0x08, 0x18, 0x10, 0x00, 
        0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x78, 0x87, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 
        0x02, 0x02, 0x0e, 0x3e, 0x20, 0x20, 0x20, 0x10, 0x10, 0x18, 0x18, 0x10, 0x10, 0x33, 0x3e, 0x00
        },
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x30, 0x18, 0x60, 
        0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0x20, 0x10, 0x0c, 0x06, 0x03, 0x81, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x04, 0x0c, 0x18, 0x10, 0x18, 0x08, 0xf8, 0x00, 0x00, 0x00, 
        0x00, 0x3e, 0x23, 0x20, 0x20, 0x20, 0x30, 0x10, 0x10, 0x10, 0x30, 0x21, 0x21, 0x63, 0x43, 0x42, 
        0xc0, 0x80, 0x88, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x73, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x05, 0x08, 0x08, 0x08, 0x08, 0x04, 0x04, 0x06, 0x04, 0x0c, 0x08, 0x0b, 0x08, 0x00
        }
    };
    static const char PROGMEM prep[][ANIM_SIZE] = {
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x30, 0x18, 0x0c, 0x38, 
        0x60, 0xc0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xf8, 0x18, 0x0c, 0x0c, 0x38, 0x0c, 0x06, 0x03, 0x01, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x03, 0x02, 0x06, 0x04, 0x08, 0x18, 0x30, 0x18, 0x18, 0xf8, 0x00, 0x00, 
        0x00, 0x07, 0x0c, 0x18, 0x18, 0x10, 0x10, 0x10, 0x20, 0x60, 0x61, 0x41, 0x42, 0xc2, 0x86, 0x84, 
        0x80, 0x00, 0x00, 0x18, 0x10, 0xfc, 0x02, 0x02, 0x04, 0x1c, 0x00, 0x00, 0x3e, 0xe1, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
        0x01, 0x03, 0x03, 0x02, 0x06, 0x07, 0x06, 0x0c, 0x0c, 0x0c, 0x10, 0x10, 0x30, 0x20, 0x3f, 0x00
        }
    };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x40, 0x30, 0x18, 0x0c, 0x38, 
        0x60, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xfe, 0xfe, 0x80, 0xc0, 0x60, 0x18, 0x0c, 0x02, 0x01, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x06, 0x04, 0x08, 0x10, 0x10, 0x18, 0x08, 0xfc, 0x00, 0x00, 
        0xf9, 0xff, 0xe3, 0xe0, 0xc0, 0x40, 0x60, 0x20, 0x20, 0x60, 0x41, 0x40, 0xc3, 0x82, 0x86, 0x04, 
        0x00, 0x00, 0x00, 0x18, 0x18, 0xfc, 0x06, 0x06, 0x04, 0x38, 0x00, 0x00, 0x1c, 0xe7, 0x00, 0x00, 
        0xf0, 0xfc, 0x03, 0x00, 0x01, 0x07, 0x7c, 0x78, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
        0x01, 0x03, 0x02, 0x02, 0x06, 0x07, 0x04, 0x0c, 0x08, 0x08, 0x18, 0x10, 0x30, 0x21, 0x3f, 0x38
        },
        {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40, 0x60, 0x30, 0x18, 0x0c, 0x38, 
        0x60, 0x40, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xe0, 0xf8, 0x04, 0x04, 0x0c, 0x3c, 0x06, 0x03, 0x01, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x0c, 0x18, 0x98, 0x08, 0x0c, 0xfc, 0x00, 0x00, 
        0x03, 0x07, 0x04, 0x0c, 0x08, 0x08, 0x18, 0x10, 0x10, 0x30, 0x20, 0x20, 0x61, 0x43, 0x43, 0xc2, 
        0x80, 0x80, 0x80, 0x8c, 0x80, 0x00, 0x00, 0xe0, 0xf8, 0x7e, 0x3f, 0x1f, 0x1f, 0x7d, 0x80, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0x70, 
        0x30, 0x38, 0x19, 0x0f, 0x1e, 0x1c, 0x79, 0xf8, 0xe8, 0xc4, 0x84, 0x08, 0x08, 0x18, 0x1f, 0x1c
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <=IDLE_SPEED){
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
         }
         if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }
         if(get_current_wpm() >=TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }
    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}
/*
void oled_task_user(void) {
        render_anim();
        oled_set_cursor(0,0);
        sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
        oled_set_cursor(0,4);
        oled_write(wpm_str, false);

}
*/
void oled_task_user(void) {

        render_anim();
        oled_set_cursor(0,6);
        sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
        oled_set_cursor(0,5);
        oled_write(wpm_str, false);

        render_status();

    }

#endif
