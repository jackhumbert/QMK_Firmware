#include QMK_KEYBOARD_H

/* Keyboard layout
*   ,---------.   ,---------------------------------------.  ,---------------------------------------.  ,---------------------------------------.    ,---------.
*   |   ka0   |   |   ka1   |   ka2   |   ka3   |   ka4   |  |   ka5   |   ka6   |   ka7   |   ka8   |  |   ka9   |  ka10   |  ka11   |  ka12   |    |  sw99   |
*   `---------'   `---------+---------+---------+---------'  `---------+---------+---------+---------'  `---------+---------+---------+---------'    `---------'
*   ,-------------------------------------------------------------------------------------------------------------------------------------------.    ,---------.
*   |   kb0   |   kb1   |   kb2   |   kb3   |   kb4   |   kb5   |   kb6   |   kb7   |   kb8   |   kb9   |  kb10   |  kb11   |  kb12   |  kb13   |    |  kd13   |
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|    |---------|
*   |   kc0   |   kc1   |   kc2   |   kc3   |   kc4   |   kc5   |   kc6   |   kc7   |   kc8   |   kc9   |  kc10   |  kc11   |  kc12   |         |    |  ke13   |
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+  kc13   |    |---------|
*   |   kd0   |   kd1   |   kd2   |   kd3   |   kd4   |   kd5   |   kd6   |   kd7   |   kd8   |   kd9   |  kd10   |  kd11   |  kd12   |         |    |  kf13   |
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'---------'    `---------'
*   |   ke0   |   ke1   |   ke2   |   ke3   |   ke4   |   ke5   |   ke6   |   ke7   |   ke8   |   ke9   |  ke10   |  ke11   |  ke12   |  ,---------.
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'  |  kf12   |
*   |   kf0   |   kf1   |   kf2   |   kf3   |           ,---------.     ,---------.           |   kf6   |   kf7   |   kf8   |  ,---------|---------|---------.
*   `---------+---------+---------+---------+           |   kf4   |     |   kf5   |           +---------+---------+---------'  |   kf9   |  kf10   |  kf11   |
*                                                       `---------'     `---------'                                            `---------+---------+---------'
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap: BASE
*   ,---------.   ,---------------------------------------.  ,---------------------------------------.  ,---------------------------------------.    ,---------.
*   |   ESC   |   |   F1    |   F2    |   F3    |   F4    |  |   F5    |   F6    |   F7    |   F8    |  |   F9    |   F10   |   F11   |   F12   |    | ENCODER |
*   `---------'   `---------+---------+---------+---------'  `---------+---------+---------+---------'  `---------+---------+---------+---------'    `---------'
*   ,-------------------------------------------------------------------------------------------------------------------------------------------.    ,---------.
*   |    `    |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |    -    |    =    |Backspace|    |  Delete |
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|    |---------|
*   |   Tab   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |    [    |    ]    |         |    |   HOME  |
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+  ENTER  |    |---------|
*   |  CapsL  |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    '    |  NUHS * |         |    |   END   |
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'---------'    `---------'
*   | LShift  | NUBS <  |    Z    |    X    |    C    |    V    |    B    |    N    |    M    |    ,    |    .    |    /    | RShift  |  ,---------.
*   |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------'  |    UP   |
*   |  LCtrl  |   LGUI  |   LAlt  |  CODE   |           ,---------.     ,---------.           |   RAlt  |  RCtrl  |   FUNC  |  ,---------|---------|---------.
*   |---------+---------+---------+---------+           |  Space  |     |  Space  |           +---------+---------+---------'  |  LEFT   |   DOWN  |  RIGHT  |
*                                                       `---------'     `---------'                                            `---------+---------+---------'   
*/
    [_BASE] = LAYOUT_iso(
          KC_ESC,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,           KC_MPLY,  \
          
          KC_GRV,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC,   KC_DEL,  \
          KC_TAB,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_ENT,  KC_HOME,  \
         KC_CAPS,    KC_A, LT(0,KC_S),       KC_D,       KC_F,       KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, KC_NUHS,            KC_END,  \
         KC_LSFT, KC_NUBS,       KC_Z, LT(0,KC_X), LT(0,KC_C), LT(0,KC_V),    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,    KC_UP,           \
         KC_LCTL, KC_LGUI,    KC_LALT,     L_CODE,        KC_SPC,        KC_SPC,             KC_RALT, KC_RCTL, TO_FUNC,           KC_LEFT, KC_DOWN, KC_RGHT   \
    ),

    [_CODE] = LAYOUT_iso(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,  \

       _SCRNSHOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,           \
         XXXXXXX, XXXXXXX, XXXXXXX, _______,         XXXXXXX,       XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX   \
    ),

    [_FUNC] = LAYOUT_iso(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             RGB_TOG,  \

         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_VAI,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              RGB_VAD,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     RGB_HUI,           \
         XXXXXXX, XXXXXXX, XXXXXXX, _______,         XXXXXXX,       XXXXXXX,              RGB_SPD, RGB_SPI, TO_BASE,     RGB_SAD, RGB_HUD, RGB_SAI   \
    ),

    [_TOP] = LAYOUT_iso(
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX,  \

         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,              XXXXXXX,  \
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,           \
         XXXXXXX, XXXXXXX, XXXXXXX, _______,         XXXXXXX,       XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX   \
    ),

};

/*****************************************************************************************************/

#ifdef OLED_ENABLE
    static void render_status(void) {
        // 21 characters per line
        // 16 cols / 4 rows

        oled_write_P(PSTR("    Kanagawa rev 2.0   "), false);
        //oled_write_ln("", false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _BASE:
                oled_write_P(PSTR("_\n"), false);
                break;
            case _FUNC:
                oled_write_P(PSTR("[Fn]\n"), false);
                break;
            case _CODE:
                oled_write_P(PSTR("[Code]\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Host Keyboard LED Status
        led_t led_state = host_keyboard_led_state();
        oled_write_ln(led_state.caps_lock ? "CAPLOCK" : "       ", false);
        // oled_write_P(PSTR("         "), false);
        
        // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
        // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

        oled_write_ln("", false);
        // oled_write_ln("", false);
        // oled_write_ln("", false);
        // oled_write_ln("", false);
        // oled_write_ln("", false);
    }

    bool oled_task_user(void) {
        
        render_status();

        return false;
    }
#endif

/*****************************************************************************************************/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CUSTOMKEY:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_SHIFT) {
                tap_code16(G(A(KC_K)));
            } else {
                tap_code(KC_MPLY);
            }
        } 
        break; 
    case LT(0,KC_X):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_X)); // Intercept hold function to send Ctrl-X
            return false;
        }
        return true;
    case LT(0,KC_C):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_C)); // Intercept hold function to send Ctrl-C
            return false;
        }
        return true;
    case LT(0,KC_V):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
            return false;
        }
        return true;  
    case LT(0,KC_S):
        if (!record->tap.count && record->event.pressed) {
            tap_code16(C(KC_S)); // Intercept hold function to send Ctrl-S
            return false;
        }
        return true;  
  }
  return true;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_CODE] =  { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [_FUNC] =   { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD) },    
    [_TOP] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif
