//  Copyright 2023 JZ-Skyloong (@JZ-Skyloong)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
int FN_WIN = 0;
int FN_MAC = 0;
int L_WIN = 0;
int L_MAC = 0;


void suspend_power_down_kb() {
    writePinLow(MAC_PIN);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb() {
    suspend_wakeup_init_user();
}

bool shutdown_kb(bool jump_to_bootloader) {
    return shutdown_user(jump_to_bootloader);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
     case TO(0):
      if (record->event.pressed) {
       L_WIN = 1;
       set_single_persistent_default_layer(0); // Save default layer 0 to eeprom
      } else {
       L_WIN = 0;
      }
      return true; // continue all further processing of this key

     case MO(2):
      if (record->event.pressed) {
       FN_WIN = 1;
      } else {
       FN_WIN = 0;
      }
      return true; // continue all further processing of this key

     case TO(1):
      if (record->event.pressed) {
       L_MAC = 1;
       set_single_persistent_default_layer(1);  //Save default layer 1 to eeprom
      } else {
       L_MAC = 0;
      }
      return true; // continue all further processing of this key

     case MO(3):
      if (record->event.pressed) {
       FN_MAC = 1;
      } else {
       FN_MAC = 0;
      }
      return true; // continue all further processing of this key
    default:
      return true;
    }
}

layer_state_t default_layer_state_set_kb(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        writePinLow(MAC_PIN);
        break;
    case 1:
        writePinHigh(MAC_PIN);
        break;
    }
  return state;
}


void board_init(void) {
    // JTAG-DP Disabled and SW-DP Disabled
    AFIO->MAPR = (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG_Msk) | AFIO_MAPR_SWJ_CFG_DISABLE;
    setPinOutput(MAC_PIN);
    writePinHigh(MAC_PIN);
}