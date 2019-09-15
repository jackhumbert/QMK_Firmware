#include QMK_KEYBOARD_H
#include "ninjonas.h"	

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper( 
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________QWERTY_L1______________________,       _____________________QWERTY_R1______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________QWERTY_L2______________________,       _____________________QWERTY_R2______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________QWERTY_L3______________________,       _____________________QWERTY_R3______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    T_GUI, KC_LCTL,LT_RAI,       LT_LOW,KC_BSPC,KC_DEL
                                 //`---------------------'      `---------------------'
  ),

  [_DVORAK] = LAYOUT_wrapper( 
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________DVORAK_L1______________________,       _____________________DVORAK_R1______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________DVORAK_L2______________________,       _____________________DVORAK_R2______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________DVORAK_L3______________________,       _____________________DVORAK_R3______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    T_GUI, KC_LCTL,LT_RAI,       LT_LOW,KC_BSPC,KC_DEL
                                 //`---------------------'      `---------------------'
  ),

  [_COLEMAK] = LAYOUT_wrapper( 
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________COLEMAK_L1_____________________,       _____________________COLEMAK_R1_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________COLEMAK_L2_____________________,       _____________________COLEMAK_R2_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________COLEMAK_L3_____________________,       _____________________COLEMAK_R3_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    T_GUI, KC_LCTL,LT_RAI,       LT_LOW,KC_BSPC,KC_DEL
                                 //`---------------------'      `---------------------'
  ),

  [_LOWER] = LAYOUT_wrapper( 
  //,----------------------------------------------------.      ,----------------------------------------------------.
     XXXXXXX, XXXXXXX, _________MEDIA_1_________, XXXXXXX,       _______________NAV_1______________,  XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     XXXXXXX, XXXXXXX, _________MEDIA_2_________, XXXXXXX,       _______________NAV_2______________,   K_LOCK, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     XXXXXXX, XXXXXXX, _________MEDIA_3_________,  T_LBRC,         T_RBRC, XXXXXXX, XXXXXXX,  M_CODE,  M_ZOOM, M_PYNV,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),

  [_RAISE] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________NUM_LEFT_______________________,       _____________________NUM_RIGHT______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________SYM_LEFT_______________________,       _____________________SYM_RIGHT______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________FUNC_LEFT______________________,       _____________________FUNC_RIGHT_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),

  [_ADJUST] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
       M_MAKE, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       RGB_TOG, XXXXXXX, XXXXXXX, COLEMAK,  DVORAK, QWERTY,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
       M_VRSN, XXXXXXX, XXXXXXX, RGB_SAI, RGB_HUI, RGB_VAI,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
       M_FLSH, XXXXXXX, XXXXXXX, RGB_SAD, RGB_HUD, RGB_VAD,       RGB_M_P, RGB_M_B, RGB_M_G,RGB_M_SW, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),
/*
  [_TEMPLATE] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),
*/
};