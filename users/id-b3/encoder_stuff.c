/*
Copyright 2021 id-b3
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "id-b3.h"

#ifdef ENCODER_ENABLE

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (biton32(layer_state)) {
            case _COLEMAK:
                // Tabbing through windows
				if (clockwise) {
				  if (!is_alt_tab_active) {
					is_alt_tab_active = true;
					register_code(KC_LALT);
				  }
				  alt_tab_timer = timer_read();
				  tap_code16(KC_TAB);
				} else {
				  if (!is_alt_tab_active) {
				    is_alt_tab_active = true;
				    register_code(KC_LALT);
				  }
				  alt_tab_timer = timer_read();
				  tap_code16(S(KC_TAB));
				}
                break;
			case _NAVIGATION:
                // Move whole words. Hold shift to select while moving.
                if (clockwise) {
                    tap_code16(C(KC_RGHT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
				break;
//			case _WARHAMMER:
                // scroll through units.
  //              if (clockwise) {
    //                tap_code16(KC_DOT);
      //          } else {
        //            tap_code16(KC_COMM);
          //      }
			//	break;
            default:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(C(KC_Y));
                } else {
                    tap_code16(C(KC_Z));
                }
                break;
        }
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case _COLEMAK:
                // Scroll through tabs
                if (clockwise) {
                    tap_code16(C(KC_PGDN));
                } else {
                    tap_code16(C(KC_PGUP));
                }
                break;
			case _SHORTCUT:
                // Volume Control
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            default:
                // History Scrubbing
				if (clockwise) {
				  tap_code16(C(KC_Y));
				} else {
				  tap_code16(C(KC_Z));
				}
                break;
        }
    }
}
#endif