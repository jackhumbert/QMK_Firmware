// pvinis ergodox ez
// ,------------------------------------.          ,------------------------------------.
// |      |    |    |    |    |    |    |          |    |    |    |    |    |    |      |
// |------+----+----+----+----+---------|          |----+----+----+----+----+----+------|
// |      |    |    |    |    |    |    |          |    |    |    |    |    |    |      |
// |------+----+----+----x----x----|    |          |    |----x----x----+----+----+------|
// |      |    |    |    |    |    |----|          |----|    |    |    |    |    |      |
// |------+----+----+----x----x----|    |          |    |----x----x----+----+----+------|
// |      |    |    |    |    |    |    |          |    |    |    |    |    |    |      |
// `------+----+----+----+----+---------'          `---------+----+----+----+----+------'
//   |    |    |    |    |    |                              |    |    |    |    |    |
//   `------------------------'                              `------------------------'
//                              ,---------.      ,---------.
//                              |    |    |      |    |    |
//                         ,----+----+----|      |----+----+----.
//                         |    |    |    |      |    |    |    |
//                         |    |    |----|      |----|    |    |
//                         |    |    |    |      |    |    |    |
//                         `--------------'      `--------------'


#include QMK_KEYBOARD_H
#include "pvinis.h"
#include "mousekey.h"


// layers
enum {
  MOUSE = 8,
};

// extra keys
enum {
  NONE = 30,
  TD_LAYR, // SYSCTL and MOUSE layer switch
};

// application selection
// this is sending ctrl-alt-gui-<key>, and this is picked up by hammerspoon
#define AP_SLCK ALLM(KC_S)
#define AP_XCOD ALLM(KC_X)
#define AP_MSGR ALLM(KC_M)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // ,------------------------------------.          ,------------------------------------.
  // |4xFLSH|    |    |    |    |    |Opt |          |    |    |    |    |    |    |      |
  // |------+----+----+----+----+---------|          |----+----+----+----+----+----+------|
  // | Tab  |    |    |    |    |    |    |          |    |    |    |    |    |    |      |
  // |------+----+----+----x----x----|    |          |    |----x----x----+----+----+------|
  // |EscCtl|    |    |    |    |    |----|          |----|    |    |    |    |    | Ent  |
  // |------+----+----+----x----x----|    |          |    |----x----x----+----+----+------|
  // |LShift|    |    |    |    |    |    |          |    |    |    |    |    |    |RShift|
  // `------+----+----+----+----+---------'          `---------+----+----+----+----+------'
  //   |    |    |    |    |Cmd |                              |    |    |    |    |    |
  //   `------------------------'                              `------------------------'
  //                              ,---------.      ,---------.
  //                              |QWER|    |      |    |    |
  //                         ,----+----+----|      |----+----+----.
  //                         | Ba | L  |    |      |    |    |    |
  //                         | ck |Shi |----|      |----|    |Spc |
  //                         | spc| ft |    |      |    |    |    |
  //                         `--------------'      `--------------'
  [LR_BASE] = LAYOUT_ergodox_pretty_wrapper(
    TD_3FLS, _______, _______, _______, _______, _______, KC_LALT,      _______, _______, _______, _______, _______, _______, _______,
    KC_TAB , _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    PV_ESCC, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, KC_ENT ,
    KC_LSFT, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, KC_RSFT,
    _______, _______, _______, KC_LGUI, SYMBOL ,                                          SYSCTL , _______, _______, _______, _______,
                                                 QWERTY , CARPALX,      _______, _______,
                                                          _______,      _______,
                                        KC_BSPC, _______, _______,      _______, _______, KC_SPC
  ),

  // ,------------------------------------.          ,------------------------------------.
  // |      |        NUMBERS_L       |    |          |  - |        NUMBERS_R       |  =   |
  // |------+----+----+----+----+---------|          |----+----+----+----+----+----+------|
  // |      |                        |  [ |          | ]  |                        |      |
  // |------+                        |    |          |    |                        +------|
  // |      |         QWERTY_L       |----|          |----|         QWERTY_R       |      |
  // |------+                        |  ( |          | )  |                        +------|
  // |      |                        |    |          |    |                        |      |
  // `------+----+----+----+----+---------'          `---------+----+----+----+----+------'
  //   |    | `  |    |    |    |                              |    |    |    |  ' |    |
  //   `------------------------'                              `------------------------'
  //                              ,---------.      ,---------.
  //                              |    |    |      |    |    |
  //                         ,----+----+----|      |----+----+----.
  //                         |    |    |    |      |    |    |    |
  //                         |    |    |----|      |----|    |    |
  //                         |    |    |    |      |    |    |    |
  //                         `--------------'      `--------------'
  // See `users/pvinis/pvinis.h`
  [LR_QWERTY] = LAYOUT_ergodox_pretty_wrapper(
    _______, ________________NUMBERS_L__________________, _______,      KC_MINS, ________________NUMBERS_R__________________, KC_EQL ,
    _______, _________________QWERTY_L1_________________, KC_LBRC,      KC_RBRC, _________________QWERTY_R1_________________, _______,
    _______, _________________QWERTY_L2_________________,                        _________________QWERTY_R2_________________, _______,
    _______, _________________QWERTY_L3_________________, KC_LPRN,      KC_RPRN, _________________QWERTY_R3_________________, _______,
    _______, KC_GRV, _______, KC_LEFT, _______,                                          _______, KC_DOWN, _______, KC_QUOT , _______,
                                                 _______, _______,      _______, _______,
                                                          _______,      _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  // ,------------------------------------.          ,------------------------------------.
  // |      |        NUMBERS_L       |    |          |    |        NUMBERS_R       |      |
  // |------+----+----+----+----+---------|          |----+----+----+----+----+----+------|
  // |      |                        |    |          |    |                        |      |
  // |------+                        |    |          |    |                        +------|
  // |      |        CARPALX_L       |----|          |----|        CARPALX_R       |      |
  // |------+                        |    |          |    |                        +------|
  // |      |                        |    |          |    |                        |      |
  // `------+----+----+----+----+---------'          `---------+----+----+----+----+------'
  //   |    |    |    |    |    |                              |    |    |    |    |    |
  //   `------------------------'                              `------------------------'
  //                              ,---------.      ,---------.
  //                              |    |    |      |    |    |
  //                         ,----+----+----|      |----+----+----.
  //                         |    |    |    |      |    |    |    |
  //                         |    |    |----|      |----|    |    |
  //                         |    |    |    |      |    |    |    |
  //                         `--------------'      `--------------'
  // See `users/pvinis/pvinis.h`
  [LR_CARPALX] = LAYOUT_ergodox_pretty_wrapper(
    _______, ________________NUMBERS_L__________________, _______,      _______, ________________NUMBERS_R__________________, _______,
    _______, ________________CARPALX_L1_________________, _______,      _______, ________________CARPALX_R1_________________, _______,
    _______, ________________CARPALX_L2_________________,                        ________________CARPALX_R2_________________, _______,
    _______, ________________CARPALX_L3_________________, _______,      _______, ________________CARPALX_R3_________________, _______,
    _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______,
                                                 _______, _______,      _______, _______,
                                                          _______,      _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  // See `users/pvinis/pvinis.h`
  [LR_SYMBOL] = LAYOUT_ergodox_pretty_wrapper(
    _______, ______________________F_L__________________, KC_F11 ,      KC_F12 , ______________________F_R__________________, _______,
    _______, _________________SYMBOL_L1_________________, _______,      _______, _________________SYMBOL_R1_________________, _______,
    _______, _________________SYMBOL_L2_________________,                        _________________SYMBOL_R2_________________, _______,
    _______, _________________SYMBOL_L3_________________, _______,      _______, _________________SYMBOL_R3_________________, _______,
    _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______,
                                                 _______, _______,      _______, _______,
                                                          _______,      _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  // See `users/pvinis/pvinis.h`
  [LR_SYSCTL] = LAYOUT_ergodox_pretty_wrapper(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _________________SYSCTL_R1_________________, _______,
    _______, _______, _______, _______, _______, _______,                        _________________SYSCTL_R2_________________, _______,
    _______, _______, _______, _______, _______, _______, _______,      _______, _________________SYSCTL_R3_________________, _______,
    _______, _______, _______, _______, _______,                                          _______, _______, _______, _______, _______,

                                                 _______, _______,      _______, _______,
                                                          _______,      _______,
                                        _______, _______, _______,      _______, _______, _______
  ),

  // See `users/pvinis/pvinis.h`
  [LR_KBCTL] = LAYOUT_ergodox_pretty_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, __________________KBCTL_R1_________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        __________________KBCTL_R2_________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, __________________KBCTL_R3_________________, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                                          _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

                                                 XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX,
                                                          XXXXXXX,      XXXXXXX,
                                        XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
  ),

/* MOUSE
 * a keymap to control my system.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ^    |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | MsUp |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |MsLeft| MsDn |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |MidClk|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Left  |Right |
 *                                 |      |      |------|       |------| Click| Click|
 *                                 |      |      |  ^   |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
  [MOUSE] = LAYOUT_ergodox_pretty(
   KC_TRNS    ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO    ,KC_NO
  ,KC_NO      ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO    ,KC_NO
  ,KC_NO      ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO
  ,KC_NO      ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO    ,KC_NO
  ,KC_NO      ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO

                                                        ,KC_NO  ,KC_NO
                                                                ,KC_NO
                                                ,KC_NO  ,KC_NO  ,KC_TRNS

                    ,KC_NO    ,KC_NO  ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO
                    ,KC_NO    ,KC_NO  ,KC_NO    ,KC_MS_U  ,KC_NO    ,KC_NO    ,KC_NO
                              ,KC_NO  ,KC_MS_L  ,KC_MS_D  ,KC_MS_R  ,KC_NO    ,KC_NO
                    ,KC_NO    ,KC_NO  ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO
                                      ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO    ,KC_NO

            ,KC_NO  ,KC_NO
            ,KC_NO
            ,KC_NO  ,KC_NO  ,KC_NO
  ),
};

// keyboard initialization
// void matrix_init_user() {
//   ergodox_led_all_on();
//   for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
//     ergodox_led_all_set(i);
//     wait_ms(5);
//   }
//   wait_ms(1000);
//   for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
//     ergodox_led_all_set(i);
//     wait_ms(10);
//   }
//   ergodox_led_all_off();
// }

// light up leds based on the layer
// void matrix_scan_user(void) {
//   uint8_t layer = biton32(layer_state);

//   switch(layer) {
//   case LR_SYSCTL:
//     ergodox_right_led_3_on();
//     break;
//   case MOUSE:
//     ergodox_right_led_2_on();
//     break;
//   default:
//     ergodox_right_led_1_off();
//     ergodox_right_led_2_off();
//     ergodox_right_led_3_off();
//     break;
//   }
// }

// extra keys
// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // switch (id) {
  // }
  // return MACRO_NONE;
// }

// tap dances

// flash keyboard on 4x tap, with leds
// void flash_each_tap(qk_tap_dance_state_t *state, void *user_data) {
//   switch (state->count) {
//   case 1:
//     ergodox_right_led_3_on();
//     break;
//   case 2:
//     ergodox_right_led_2_on();
//     break;
//   case 3:
//     ergodox_right_led_1_on();
//     break;
//   case 4:
//     ergodox_right_led_3_off();
//     wait_ms(50);
//     ergodox_right_led_2_off();
//     wait_ms(50);
//     ergodox_right_led_1_off();
//     break;
//   }
// }

// void flash_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count >= 4) {
//     reset_keyboard();
//     reset_tap_dance(state);
//   }
// }

// void flash_dance_reset(qk_tap_dance_state_t *state, void *user_data) {
//   ergodox_right_led_1_off();
//   wait_ms(50);
//   ergodox_right_led_2_off();
//   wait_ms(50);
//   ergodox_right_led_3_off();
// }

// SYSCTL on first tap, MOUSE ON second tap
// void layers_dance_finished(qk_tap_dance_state_t *state, void *user_data) {
//   uint8_t layer = biton32(layer_state);

//   switch(state->count) {
//   case 1:
//     switch(layer) {
//     case LR_SYSCTL:
//       layer_off(LR_SYSCTL);
//       break;
//     case MOUSE:
//       layer_off(MOUSE);
//       break;
//     default:
//       layer_on(LR_SYSCTL);
//       break;
//     }
//     break;
//   case 2:
//     layer_on(MOUSE);
//     break;
//   }
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
  // [TD_FLSH] = ACTION_TAP_DANCE_FN_ADVANCED( flash_each_tap, flash_dance_finished, flash_dance_reset ),
  // [TD_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED( NULL, layers_dance_finished, NULL ),
// };
