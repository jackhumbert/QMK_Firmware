#include QMK_KEYBOARD_H
/* 
enable rgb here 
*/



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
			KC_NO, KC_P7, KC_P8, KC_P9, KC_PMNS, 
			KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, 
			KC_A, KC_P1, KC_P2, KC_P3, KC_TAB, 
			KC_B, KC_DEL, KC_P0, KC_PDOT, KC_PENT)
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { /* First encoder */
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  } else if (index == 1) { /* Second encoder */  
    if (clockwise) {
      tap_code(KC_WH_U); 
    } else {
      tap_code(KC_WH_D); 
    }
  }
}
