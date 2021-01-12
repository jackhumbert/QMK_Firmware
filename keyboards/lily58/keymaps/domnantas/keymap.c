 /* Copyright 2020 Domantas Petrauskas
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
#include <stdio.h>

#define LT_1 RALT(KC_1)
#define LT_2 RALT(KC_2)
#define LT_3 RALT(KC_3)
#define LT_4 RALT(KC_4)
#define LT_5 RALT(KC_5)
#define LT_6 RALT(KC_6)
#define LT_7 RALT(KC_7)
#define LT_8 RALT(KC_8)
#define LT_9 RALT(KC_9)
#define LT_0 RALT(KC_0)

// Naming according to Unicode specifications
#define LT_A_OG KC_1
#define LT_C_CA KC_2
#define LT_E_OG KC_3
#define LT_E_DO KC_4
#define LT_I_OG KC_5
#define LT_S_CA KC_6
#define LT_U_OG KC_7
#define LT_U_MA KC_8
#define LT_Z_CA KC_EQL

#define LT_EQL RALT(KC_EQL)

// OLED setup
#define IDLE_FRAMES 5
#define IDLE_SPEED 30
#define TAP_FRAMES 2
#define TAP_SPEED 40
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 512

char     wpm_str[10];
uint32_t anim_timer         = 0;
uint32_t anim_sleep         = 0;
uint8_t  current_idle_frame = 0;
uint8_t  current_tap_frame  = 0;

static long int oled_timeout = OLED_TIMEOUT;  // 10 minutes

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const bool *is_keyboard_left(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   Ą  |   Č  |   Ę  |   Ė  |   Į  |                    |   Š  |   Ų  |   Ū  |   (  |   )  |   Ž  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |   -  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | RAlt |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | / Space /       \Enter \  | Bksp |RAISE | Del  |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_QWERTY] = LAYOUT(
        KC_ESC,   LT_A_OG, LT_C_CA, LT_E_OG, LT_E_DO, LT_I_OG,                  LT_S_CA, LT_U_OG, LT_U_MA, KC_9,    KC_0,    LT_Z_CA,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTRL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                                KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC,  KC_ENT,  KC_BSPC, MO(_RAISE), KC_DEL
    ),

    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   4  |   5  |   6  |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   7  |   8  |   9  |   0  |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCTRL |   =  |   +  |   -  |   |  |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | / Space /       \ Enter\  | Bksp |RAISE | Del  |
     *                   |      |      ||||||||/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(
        _______, LT_1,    LT_2,    LT_3,    LT_4,    LT_5,                      LT_6,    LT_7,    LT_8,    LT_9,    LT_0,    KC_GRV,
        _______, LT_4,    LT_5,    LT_6,    _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, LT_7,    LT_8,    LT_9,    LT_0,    _______,                   _______, _______, _______, _______, _______, _______,
        _______, LT_EQL, KC_PPLS, KC_PMNS, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |PrScr |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  | F11  | F12  |      |      |      |                    |      | PgUp | Home |  Up  | End  | Vol+ |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------.    ,-------|      | PgDn | Left | Down |Right | Vol- |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCTRL | Undo | Cut  | Copy |Paste |      |-------|    |-------|      |      |MPrev |MNext |MPlPa |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | / Space /       \ Enter\  | Bksp |RAISE | Del  |
     *                   |      |      |      |/       /         \      \ |      ||||||||      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_RAISE] = LAYOUT( \
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR, \
        _______, KC_F11,  KC_F12,  _______, _______, _______,                   _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_VOLU, \
        _______, _______, _______, _______, _______, _______,                   _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, \
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______, \
                                   _______, _______, _______, _______, _______, _______, _______, _______ \
    ),

    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CAPS |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  | Bksp |RAISE | Del  |
     *                   |      |      ||||||||/       /         \      \ |      ||||||||      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                   _______, _______, _______, _______, _______,  _______, _______, _______ \
    )
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_left()) return OLED_ROTATION_270;
    return OLED_ROTATION_180;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

static void render_bongo_cat(void) {

    // Idle animation
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 16, 8,  8,  4,  4, 4, 8, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 100, 130, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 56, 4, 3, 0, 0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1,   1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 16, 8,  8,  4,  4, 4, 8, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 100, 130, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 192, 56, 4, 3, 0, 0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1,   1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 64, 64, 64, 64, 32, 32,  32, 32, 16, 8,  4,  2,  2,  4, 24, 96, 128, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60, 194, 1, 1, 2, 2, 4, 4, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 96, 96, 0, 129, 130, 130, 132, 8, 16, 32, 64, 128, 0, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 25, 6, 0, 0, 0, 0, 0, 0, 0, 24,  24,  24, 27, 3,  0,  64, 160, 34, 36, 20, 18, 18, 18, 11, 8, 8,  8,  8,   5, 5, 9, 9, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8, 8, 8, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0, 0,   0,   0,   0,   0, 0,  0,  0,  0,   0, 0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  0, 0, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 8,  8,  4,  2,  2, 2, 4, 56, 64, 128, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28, 226, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 192, 193, 193, 194, 4, 8, 16, 32, 64, 128, 0, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3, 0, 0, 0, 0, 0, 0, 0,   12, 12, 12, 13, 1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8, 8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16, 17, 15, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 2, 2, 4, 4, 8, 8,   8,   8, 8, 7, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0,   0,   0,   0,   0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    };

    // Prep animation
    static const char PROGMEM prep[][ANIM_SIZE] = {

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0,  0, 0, 0,   128, 64,  64,  32,  32, 32, 32, 16, 16, 16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 129, 128, 128, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 24, 6, 5, 152, 153, 132, 195, 124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 4, 4, 4, 4, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 0,   0,   0,   0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0, 0, 0,   0,  0, 0, 0,  0,  0, 0,   0,   0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    };

    // Typing animation
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0,  0, 0, 0,   128, 64,  64, 32,  32, 32, 32, 16, 16, 16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0,  0,  0,  0,  248, 248, 248, 248, 0,  0,   0,   0,   0,   128, 128, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30, 225, 0, 0, 1, 1, 2, 2, 129, 128, 128, 0, 0, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 0, 1, 1, 2, 4, 8, 16, 32, 67, 135, 7, 1, 0, 184, 188, 190, 159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 24, 6, 5, 152, 153, 132, 67, 124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 8, 8, 16, 16, 16, 16, 16,  17,  15,  1,   61, 124, 252, 252, 252, 252, 252, 60, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 2,  2,   1, 1, 1, 1, 1, 1, 0,   0,   0,   0, 0, 0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,   0, 0, 0, 0,   0,   1,   3,   3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,  128, 128, 0, 0, 0, 0, 0, 128, 64, 64, 32, 32, 32, 32, 16, 16,  16, 16, 8,  4,  2,  1,  1, 2, 12, 48, 64, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30,  225, 0,   0,   1,   1,   2,  2,  1, 0, 0, 0, 0, 128, 128, 0,   0,   0,   0,   0, 0, 0, 0, 0, 128, 0, 48, 48, 0, 0, 1, 225, 26, 6, 9, 49, 53, 1, 138, 124, 0, 0, 128, 128, 128, 128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
         0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 112, 12, 3,   0,   0, 0, 0, 0, 0, 0,   0,  0,  0,  1,  1,  0,  64, 160, 33, 34, 18, 17, 17, 17, 9, 8, 8,  8,  8,  4,   4, 4, 4, 4, 4, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 2, 3, 122, 122, 121, 121, 121, 121, 57, 49, 2, 2, 4, 4, 8, 8,   8,   136, 136, 135, 128, 0, 0, 0, 0, 0, 0,   0, 0,  0,  0, 0, 0, 0,   0,  0, 0, 0,  0,  0, 0,   0,   0, 0, 0,   0,   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    };

    void animation_phase(void) {
        if (get_current_wpm() <= IDLE_SPEED) {
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES - 1) - current_idle_frame)], ANIM_SIZE);
        }

        if (get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED) {
            oled_write_raw_P(prep[0], ANIM_SIZE);
        }

        if (get_current_wpm() >= TAP_SPEED) {
            current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
            oled_write_raw_P(tap[abs((TAP_FRAMES - 1) - current_tap_frame)], ANIM_SIZE);
        }
    }

    if (get_current_wpm() != 000) {
        oled_on();

        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }

        anim_sleep = timer_read32();
    } else {
        if (timer_elapsed32(anim_sleep) > oled_timeout) {
            oled_off();
        } else {
            if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

static void render_status(void) {
    // WPM
    oled_write_ln_P(PSTR("wpm"), false);
    sprintf(wpm_str, "%03d", get_current_wpm());
    oled_write_ln(wpm_str, false);
    oled_write_ln_P(PSTR(""), false);

    // Layer display
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("deflt"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("raise"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("lower"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("adjst"), false);
            break;
        default:
            oled_write_ln_P(PSTR("error"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR("caps"), led_state.caps_lock);
}

void oled_task_user(void) {
    if (is_keyboard_left()) {
        render_status();
    } else {
        render_bongo_cat();
    }
}
