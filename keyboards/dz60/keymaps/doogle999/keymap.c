#include "dz60.h"

#include "users/doogle999/doogle999.h"

#define ______ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer
 * ,-----------------------------------------------------------------------------------------.
 * | ESC |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
 * |-----------------------------------------------------------------------------------------+
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \   |
 * |-----------------------------------------------------------------------------------------+
 * |   Fn    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
 * |-----------------------------------------------------------------------------------------+
 * |   Shift   |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |   Shift   |  U  | Del |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Cmd  |  Alt  |               Space               |  /  |  Fn  |  L  |  D  |  R  |
 * `-----------------------------------------------------------------------------------------'
 */

	LAYOUT_directional(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
      MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, ______, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT, KC_UP, KC_DELETE,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_SLSH, MO(1), KC_LEFT, KC_DOWN, KC_RIGHT
      ),

/* Fn layer
 * ,-----------------------------------------------------------------------------------------.
 * |  ~  | F1  | F2  | F3  | F4  | F5  | F6  | f7  | F8  | F9  | F10 | F11 | F12 | Backspace |
 * |-----------------------------------------------------------------------------------------+
 * | Reset  | NP1 | NP2 | NP3 | NP4 | NP5 | NP6 | NP7 | NP8 | NP9 | NP0 |VolD |VolU |  Mute  |
 * |-----------------------------------------------------------------------------------------+
 * |         |     |     |     |     |     |     |     |     | BlD | BlI | BlT |    Menu     |
 * |-----------------------------------------------------------------------------------------+
 * |   Shift   | Cyc+| Cyc-| Val+| Val-| Hue+| Hue-| Sat+| Sat-| Tog |   Shift   | Pup | Ins |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl |  Cmd  |  Alt  |               Space               |HwCal|      |Home | Pdn | End |
 * `-----------------------------------------------------------------------------------------'
 */

	LAYOUT_directional(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, ______, KC_CALC,
      RESET, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_VOLD, KC_VOLU, KC_MUTE,
      ______, ______, ______, ______, ______, ______, ______, ______, ______, BL_DEC, BL_INC, BL_TOGG, KC_APP,
      KC_LSFT, ______, RGB_MOD, RGB_RMOD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_TOG, KC_RSFT, KC_PGUP, KC_INSERT,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, TO(2), ______, KC_HOME, KC_PGDOWN, KC_END
      ),

  /* Hardware calculator layer
  * ,-----------------------------------------------------------------------------------------.
  * |EndCa|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
  * |-----------------------------------------------------------------------------------------+
  * |        |  Q  |     |  E  |     |  T  |     |     |     |     |  P  |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |  S  |     |     |     |     |     |     |  L  |     |     |     Calc    |
  * |-----------------------------------------------------------------------------------------+
  * |   Shift   |     |     |     |  C  |     |     |     |     |  .  |   Shift   |     |     |
  * |-----------------------------------------------------------------------------------------+
  * |      |        |      |                                   |  /  |      |     |     |     |
  * `-----------------------------------------------------------------------------------------'
  */

	LAYOUT_directional(
    ENDCALC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, ______, KC_BSPC,
    ______, KC_Q,  ______, KC_E, ______, KC_T, ______, ______, ______, ______, KC_P,  ______, ______, ______,
    ______, ______, KC_S, ______, ______, ______, ______, ______, ______, KC_L, ______, ______, CALC,
    KC_LSFT, ______, ______, ______, KC_C, ______, ______, ______, ______, ______, KC_DOT, KC_RSFT, ______, ______,
    ______, ______, ______, ______, ______, ______, KC_SLSH, ______, ______, ______, ______
  ),
};