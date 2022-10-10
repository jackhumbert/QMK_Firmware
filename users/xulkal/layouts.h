#pragma once

 /* Qwerty Layout
  * ,-----------------------------------------.  ,-----------------------------------------.
  * | GESC |   1  |   2  |  3   |  4   |  5   |  |  6   |  7   |  8   |  9   |  0   | BkSp |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |  E   |  R   |  T   |  |  Y   |  U   |  I   |  O   |  P   |   \  |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |FN(CAPS)| A  |   S  |   D  |  F   |  G   |  |  H   |  J   |  K   |  L   |  ;   | Enter|
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * | Sft[ |   Z  |   X  |   C  |  V   |  B   |  |  N   |  M   |  ,   |  .   |  /   | Sft] |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * | Ctrl |  Win |  ADJ |  FN  | Alt  | Space|  | Space| Left |  Up  | Down | Right| Ctrl |
  * `-----------------------------------------'  `-----------------------------------------'
  */

#define _________________QWERTY_L1_________________ KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define _________________QWERTY_L2_________________ KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T
#define _________________QWERTY_L3_________________ RIS_CAPS, KC_A,     KC_S,     KC_D,     KC_F,     KC_G
#define _________________QWERTY_L4_________________ KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B
#define _________________QWERTY_L5_________________ KC_LCPO,  KC_LGUI,  KC_LALT,  LOWER,    RAISE,  KC_SPC

#define _________________QWERTY_R1_________________           KC_6,    KC_7,      KC_8,     KC_9,     KC_0,     TD_BSPC
#define _________________QWERTY_R2_________________           KC_Y,    KC_U,      KC_I,     KC_O,     KC_P,     KC_BSLS
#define _________________QWERTY_R3_________________           KC_H,    KC_J,      KC_K,     KC_L,     KC_SCLN,  KC_ENT
#define _________________QWERTY_R4_________________           KC_N,    KC_M,      TD_COMM,  KC_DOT,   KC_SLASH, KC_RSPC
#define _________________QWERTY_R5_________________           KC_SPC,  KC_LEFT,   KC_UP,    KC_DOWN,  KC_RIGHT, KC_RCPC


#define ___________________GAME_L1_________________ KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5
#define ___________________GAME_L2_________________ KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T
#define ___________________GAME_L3_________________ KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G
#define ___________________GAME_L4_________________ KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B
#define ___________________GAME_L5_________________ KC_LCTL,  KC_LGUI,  LOWER,    RAISE,    KC_LALT,  KC_SPC

#define ___________________GAME_R1_________________           KC_6,    KC_7,      KC_8,     KC_9,     KC_0,     KC_BSPC
#define ___________________GAME_R2_________________           KC_Y,    KC_U,      KC_I,     KC_O,     KC_P,     KC_BSLS
#define ___________________GAME_R3_________________           KC_H,    KC_J,      KC_K,     KC_L,     KC_SCLN,  KC_ENT
#define ___________________GAME_R4_________________           KC_N,    KC_M,      KC_COMM,  KC_DOT,   KC_SLASH, KC_RSFT
#define ___________________GAME_R5_________________           KC_SPC,  KC_LEFT,   KC_UP,    KC_DOWN,  KC_RIGHT, KC_RCTL


 /* RAISE Layout
  * ,-----------------------------------------.  ,-----------------------------------------.
  * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      | PGDN |  UP  | PGUP |      |QWERTY|  |      | INS  | HOME | PGUP | PRINT|      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      | LEFT | DOWN | RIGHT|      | GAME |  |      | DEL  | END  | PGDN |SCRLCK|      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |      |      |      |      |      |  |      |      |      |      |      |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |      |      |      |      |      |  |      | PREV | VOL+ | VOL- | NEXT | PLAY |
  * `-----------------------------------------'  `-----------------------------------------'
  */

#define __________________RAISE_L1_________________ KC_F12,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
#define __________________RAISE_L2_________________ _______,  KC_PGDN,  KC_UP,    KC_PGUP,  _______,  QWERTY
#define __________________RAISE_L3_________________ _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  _______,  GAME
#define __________________RAISE_L4_________________ _______,  _______,  _______,  _______,  _______,  _______
#define __________________RAISE_L5_________________ _______,  _______,  _______,  _______,  _______,  _______

#define __________________RAISE_R1_________________           KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11
#define __________________RAISE_R2_________________           _______,  KC_INS,   KC_HOME,  KC_PGUP,  KC_PSCR,  _______
#define __________________RAISE_R3_________________           _______,  KC_DEL,   KC_END,   KC_PGDN,  KC_SLCK,  _______
#define __________________RAISE_R4_________________           _______,  _______,  _______,  _______,  _______,  _______
#define __________________RAISE_R5_________________           _______,  KC_MPRV,  KC_VOLU,  KC_VOLD,  KC_MNXT,  KC_MPLY

  /* LOWER Layout
  * ,-----------------------------------------.  ,-----------------------------------------.
  * |      |RGBMD |RGBRMD|RGBTOG|      |      |  |      |      |      | SLCK | NLCK |  DEL |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * | SPDI | SAI  | VAI  | HUI  | RESET|      |  |      |      |  7   |  8   |  9   |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * | SPDD | SAD  | VAD  | HUD  |RGBRST|      |  |      |      |  4   |  5   |  6   |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |      |      |      |      |      |  |      |      |  1   |  2   |  3   |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |      |      |      |      |      |  |      |      |      |  0   |  .   |      |
  * `-----------------------------------------'  `-----------------------------------------'
  */

#define __________________LOWER_L1_________________ _______,  RGB_RMOD, RGB_MOD,  RGB_TOG,  _______,  _______
#define __________________LOWER_L2_________________ RGB_SPI,  RGB_SAI,  RGB_VAI,  RGB_HUI,  RESET,    _______
#define __________________LOWER_L3_________________ RGB_SPD,  RGB_SAD,  RGB_VAD,  RGB_HUD,  RGBRST,   _______
#define __________________LOWER_L4_________________ _______,  _______,  _______,  _______,  _______,  _______
#define __________________LOWER_L5_________________ _______,  _______,  _______,  _______,  _______,  _______

#define __________________LOWER_R1_________________           _______,  _______,  _______,  KC_SLCK,  KC_NLCK,  KC_DEL
#define __________________LOWER_R2_________________           _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  _______
#define __________________LOWER_R3_________________           _______,  _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,  _______
#define __________________LOWER_R4_________________           _______,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  _______
#define __________________LOWER_R5_________________           _______,  _______,  _______,  KC_KP_0,  KC_PDOT,  _______

  /* ADJUST Layout
  * ,-----------------------------------------.  ,-----------------------------------------.
  * |      |      |      |      |      |      |  |      |      |      |      |      |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      | RESET| DEBUG|      |      |      |  |      |      |      |   |      |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |      |MusMod|Aud on|AudOff|AGnorm|  |AGswap|ClkUp |ClkDwn|      |      |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|  |MidOff|ClkOn |ClkOff|      |      |      |
  * |------+------+------+------+------+------|  |------+------+------+------+------+------|
  * |      |      |      |      |      |      |  |      |      |      |      |      |      |
  * `-----------------------------------------'  `-----------------------------------------'
  */

#define _________________ADJUST_L1_________________ _______,  _______,  _______,  _______,  _______,  _______
#define _________________ADJUST_L2_________________ _______,  RESET,    DEBUG,    _______,  _______,  _______
#define _________________ADJUST_L3_________________ _______,  _______,  MU_MOD,   AU_ON,    AU_OFF,   AG_NORM
#define _________________ADJUST_L4_________________ _______,  MUV_DE,   MUV_IN,   MU_ON,    MU_OFF,   MI_ON
#define _________________ADJUST_L5_________________ _______,  _______,  _______,  _______,  _______,  _______

#define _________________ADJUST_R1_________________           _______,  _______,  _______,  _______,  _______,  _______
#define _________________ADJUST_R2_________________           _______,  _______,  _______,  _______,  _______,  _______
#define _________________ADJUST_R3_________________           AG_SWAP,  CK_UP,    CK_DOWN,  _______,  _______,  _______
#define _________________ADJUST_R4_________________           MI_OFF,   CK_ON,    CK_OFF,   _______,  _______,  _______
#define _________________ADJUST_R5_________________           _______,  _______,  _______,  _______,  _______,  _______
