
/* A QWERTY 3 Layer layout for the Dactyl Manuform 6x6 Keyboard */

#include QMK_KEYBOARD_H
#include "klackygears.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


  [_MACBASE] = LAYOUT_wrapper( \
     _______________DVORAK_L1___________________,      _______________DVORAK_R1___________________, \
     _______________DVORAK_L2___________________,      _______________DVORAK_R2___________________, \
     _______________MACDVK_L3___________________,      _______________MACDVK_R3___________________, \
                          __________________MAC_THUMB_CLUSTER_V2______________ \
  ),


  [_WINBASE] = LAYOUT_wrapper( \
     _______________DVORAK_L1___________________,      _______________DVORAK_R1___________________, \
     _______________DVORAK_L2___________________,      _______________DVORAK_R2___________________, \
     _______________WINDVK_L3___________________,      _______________WINDVK_R3___________________, \
                          __________________WIN_THUMB_CLUSTER_V2______________ \
  ),
/*
  [_QWERTY] = LAYOUT_wrapper( \

      _________________QWERTY_L1_________________,     _________________QWERTY_R1_________________, \
      _________________QWERTY_L2_________________,     _________________QWERTY_R2_________________, \
      _________________QWERTY_L3_________________,     _________________QWERTY_R3_________________, \
                          __________________WIN_THUMB_CLUSTER_V2______________ \
      ),*/
  [_NUMB] = LAYOUT_wrapper( \
     _________________WINNAV_L1_________________,      _________________NUMB_R1___________________, \
     _________________WINNAV_L2_________________,      _________________NUMB_R2___________________, \
     _________________WINNAV_L3_________________,      _________________NUMB_R3_WIN_______________, \
                       _______, _______, _______,      _______, KC_RSFT, _______ \
  ),

  [_SYMB] = LAYOUT_wrapper( \

      _________________PUNC_L1_ALT_______________,     _________________PUNC_R1___________________,  \
      _________________PUNC_L3___________________,     _________________PUNC_R2___________________, \
      _________________PUNC_L3_ALT_______________,     _________________PUNC_R3___________________, \
                            KC_____, KC_____, KC_DEL,  KC_CAPS, KC_____, KC_____ \
      ),

  [_FUNC] = LAYOUT_wrapper( \

      _____________FUNC_L1_______________________,     KC_WINBASE, _____________FUNC_1_______________, \
      ________MAC_MISSION_CTRL__________, LGUI(KC_L),  KC_MACBASE, _____________FUNC_2_______________, \
      _____________FUNC_L3_______________________,     KC_GRV,     _____________FUNC_3_______________, \
                        KC_____, KC_____, KC_____, KC_CAPS, KC_LSFT,   MO(_MDIA) \
      ),

  [_MNMB] = LAYOUT_wrapper( \

      _________________MACNAV_L1_________________,     _________________NUMB_R1___________________, \
      _________________MACNAV_L2_________________,     _________________NUMB_R2___________________, \
      _________________MACNAV_L3_________________,     _________________NUMB_R3_MAC_______________, \
                             KC_____, KC_____, KC_BSPC, KC_____, KC_LSFT,  KC_0 \
      ),

  [_NUMB] = LAYOUT_wrapper( \

      _________________WINNAV_L1_________________,     _________________NUMB_R1___________________, \
      _________________WINNAV_L2_________________,     _________________NUMB_R2___________________, \
      _________________WINNAV_L3_________________,     _________________NUMB_R3_WIN_______________, \
                              KC_____, KC_____, KC_BSPC, KC_____, KC_LSFT,  KC_0 \
      ),


  [_MDIA] =  LAYOUT_wrapper( \

      _________________LYOUT_____________________,     _________________RGB_1_____________________, \
      _________________KC_BLANK__________________,     _________________RGB_2_____________________, \
      _________________KC_BLANK__________________,     _________________MEDIA_____________________, \
                            KC_____, KC_____, KC_____, KC_____, KC_____, KC_____ \
      )
  };
