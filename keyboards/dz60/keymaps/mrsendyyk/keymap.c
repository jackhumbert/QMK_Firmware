#include QMK_KEYBOARD_H

// ANSI Arrow Layout

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default [0]
   * ,-----------------------------------------------------------------------------------------.
   * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
   * |-----------------------------------------------------------------------------------------+
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
   * |-----------------------------------------------------------------------------------------+
   * |Caps Lock|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
   * |-----------------------------------------------------------------------------------------+
   * | Shift      |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  RShift  |  Up |  /  |
   * |-----------------------------------------------------------------------------------------+
   * | Ctrl  |  OS  | Alt  |              Space                 | RAlt | Fn  |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------'
   */

	[0] = LAYOUT_60_b_ansi(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
                        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
                        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
                        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, KC_UP, KC_SLSH,
                        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, LT(2, KC_RALT), MO(1), KC_LEFT, KC_DOWN, KC_RGHT),

  /* Fn Layer [1]
   * ,-----------------------------------------------------------------------------------------.
   * | ` ~ |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  Delete   |
   * |-----------------------------------------------------------------------------------------+
   * | Bri Up |     |     | End | Rst |     |     |     | Ins |     | P Sc|     |     | Eject  |
   * |-----------------------------------------------------------------------------------------+
   * | Bri Down|     | Sc L|     |     |     | Home|     |     |     |     |     |    Mute     |
   * |-----------------------------------------------------------------------------------------+
   * | Vol +      |     |     | Calc|     |     |Num L| Mail|     |     |          |Pg U |Pause|
   * |-----------------------------------------------------------------------------------------+
   * | Vol - | Rwd  | F Fd |                 Play               | M Stp|     | Prev| Pg D| Next|
   * `-----------------------------------------------------------------------------------------'
   */

	[1] = LAYOUT_60_b_ansi(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
                        KC_BRIU, _______, _______, KC_END, RESET, _______, _______, _______, KC_INS, _______, KC_PSCR, _______, _______, KC_EJCT,
                        KC_BRID, _______, KC_SLCK, _______, _______, _______, KC_HOME, _______, _______, _______, _______, _______, KC_MUTE,
                        KC_VOLU, _______, _______, KC_CALC, _______, _______, KC_NLCK, KC_MAIL, _______, _______, _______, KC_PGUP, KC_PAUS,
                        KC_VOLD, KC_MRWD, KC_MFFD, KC_MPLY, KC_MPLY, KC_MPLY, KC_MSTP, KC_TRNS, KC_MPRV, KC_PGDN, KC_MNXT),

  /* Fn Layer [2] (Keyboard Settings)
   * ,-----------------------------------------------------------------------------------------.
   * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
   * |-----------------------------------------------------------------------------------------+
   * |        |R Tog|R Mo+|Hue +|Hue -|Sat +|Sat -|Bri +|Bri -|     |     |     |     |        |
   * |-----------------------------------------------------------------------------------------+
   * |         |     |     |     |     |     |     |     |     |     |     |     |             |
   * |-----------------------------------------------------------------------------------------+
   * |            |     |     |     |BL - |B Tog|BL +|B Cyc|      |     |          |     |     |
   * |-----------------------------------------------------------------------------------------+
   * |       |      |      |                                    |      |     |     |     |     |
   * `-----------------------------------------------------------------------------------------'
   */

	[2] = LAYOUT_60_b_ansi(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, BL_DEC, BL_TOGG, BL_INC, BL_STEP, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______, KC_TRNS, _______, _______, _______, _______)
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(0, 0, 0);
};

// RGB Underglow Indicator (Caps Lock, Num Lock, and Layer)

void update_led(void) { // Num Lock Indicator
  if (host_keyboard_leds() & (1<<USB_LED_NUM_LOCK)) {
    rgblight_setrgb(100, 255, 100);
  }
};

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) { // Caps Lock Indicator
    writePinLow(B2);
    rgblight_setrgb(255, 110, 0);
  } else { // Layer Indicator
      switch (biton32(layer_state)) {
        case 1: // Fn Layer
          rgblight_setrgb(225, 8, 0);
          break;
        case 2: // Fn Layer (Keyboard Settings)
          rgblight_setrgb(225, 8, 0);
          break;
        default:
          rgblight_setrgb(0, 0, 0);
          break;
      }
      update_led();
    }
};

uint32_t layer_state_set_user(uint32_t state) {
  update_led();
  return state;
}