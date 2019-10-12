#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "tominabox1.h"

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper( \
  ___________________CRKBD1__________________,
  ___________________CRKBD2__________________,
  ___________________CRKBD3__________________,
  ___________________CRKBD4__________________
  ),

  [_RAISE] = LAYOUT_wrapper( \
  ___________________RAISE1__________________,
  ___________________RAISE2__________________,
  ___________________CRKBD_RAISE3____________,
  ___________________CRKBD_RAISE4____________
  ),

  [_LOWER] = LAYOUT_wrapper( \
  _________________LOWER_1___________________,
  _________________LOWER_2___________________,
  ___________________CRKBD_LOW3______________,
  ___________________CRKBD_LOW4______________
  ),

  [_ADJUST] = LAYOUT_wrapper( \
  ___________________ADJST1__________________,
  ___________________CRKBD_ADJST2____________,
  ___________________CRKBD_ADJST3____________,
  ___________________CRKBD_ADJST4____________
  ),

  [_ARROW] = LAYOUT_wrapper( \
  ___________________ARROW1__________________,
  ___________________ARROW2__________________,
  ___________________ARROW3__________________,
  ___________________ARROW4__________________
   ),
   [_FKEY] = LAYOUT_wrapper( \
  ___________________FKEY1___________________,
  ___________________FKEY2___________________,
  ___________________CRKBD_FKEY3_____________,
  ___________________CRKBD_FKEY4_____________
  )

};
