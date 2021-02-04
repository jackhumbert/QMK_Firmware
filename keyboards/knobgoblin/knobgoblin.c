/* Copyright 2020 MrT1ddl3s
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "knobgoblin.h"

#ifdef ENCODER_ENABLE
/* assign keycodes to the encoder rotation */
__attribute__((weak)) void encoder_update_user(uint8_t index, bool clockwise) {

			if (index == 1) { /* Bottom encoder */
				if (clockwise) {
					tap_code(KC_VOLU);
				} else {
					tap_code(KC_VOLD);
				}
			}
			if (index == 0) { /* Top encoder */
				if (clockwise) {
					tap_code(KC_MNXT);
				} else {
					tap_code(KC_MPRV);
				}
			}
}
#endif

#ifdef OLED_DRIVER_ENABLE
/* rotate screen for proper orentation*/
__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

/* byte map for the goblin logo, knob goblin text, and level text */
static void render_goblin_logo(void) {
    static const char PROGMEM my_logo[] = {
		0x00, 0xe0, 0x40, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x60, 0x20, 0x10, 0x08, 0x08, 0x08, 
		0x08, 0x08, 0x08, 0x10, 0x20, 0x60, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x40, 0xe0, 0x00, 
		0x00, 0x03, 0x06, 0x3c, 0x49, 0x91, 0x21, 0x00, 0x40, 0x80, 0x80, 0x80, 0x80, 0x00, 0x60, 0x00, 
		0x00, 0x60, 0x00, 0x80, 0x80, 0x80, 0x80, 0x40, 0x00, 0x21, 0x91, 0x49, 0x3c, 0x06, 0x03, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x60, 0x40, 0xc0, 0x06, 0x0e, 0x0f, 0x67, 0x50, 0xc0, 
		0xc0, 0x50, 0x67, 0x0f, 0x0e, 0x06, 0xc0, 0x40, 0x60, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x7b, 0xc7, 0x8e, 0x1e, 0x3e, 0x3e, 
		0x3e, 0x3e, 0x1e, 0x8e, 0xc7, 0x7b, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x04, 
		0x04, 0x06, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x03, 0x03, 0x03, 0x03, 0x03, 0x83, 0x03, 0x03, 0x03, 0x83, 0x03, 0x83, 0x03, 0x03, 0x03, 0x83, 
		0x03, 0x03, 0x83, 0x83, 0x83, 0x03, 0x03, 0x83, 0x83, 0x83, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x04, 0x06, 0x09, 0x10, 0x00, 0x1f, 0x03, 0x06, 0x0c, 0x1f, 
		0x00, 0x0f, 0x10, 0x10, 0x10, 0x0f, 0x00, 0x1f, 0x12, 0x12, 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x78, 0xfc, 0x84, 0xa4, 0xa4, 0x68, 0x00, 0x78, 0x84, 0x84, 0x84, 0x78, 0x00, 0xfc, 0x94, 
		0x94, 0x68, 0x00, 0xfc, 0x80, 0x80, 0x80, 0x00, 0xfc, 0x00, 0xfc, 0x18, 0x30, 0x60, 0xfc, 0x00, 
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 
		0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x50, 0x50, 0x50, 0x00, 0xf0, 0x00, 0x00, 
		0x00, 0xf0, 0x00, 0xf0, 0x50, 0x50, 0x50, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x00, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x00, 0x03, 0x02, 0x02, 0x02, 0x00, 0x00, 0x01, 0x02, 
		0x01, 0x00, 0x00, 0x03, 0x02, 0x02, 0x02, 0x00, 0x03, 0x02, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00		
    };
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

/* text display for layer indication */
__attribute__((weak)) void oled_task_user(void) {
	
	render_goblin_logo();
	
	switch (get_highest_layer(layer_state)) {
		case 0:
			oled_set_cursor(0,11);
			/*oled_advance_char();*/
			oled_write_P(PSTR(" ONE\n"), false);
			break;
		case 1:
			oled_set_cursor(0,11);
			/*oled_advance_char();*/
			oled_write_P(PSTR(" TWO\n"), false);
			break;
		case 2:
			oled_set_cursor(0,11);
			oled_write_P(PSTR("THREE\n"), false);
			break;
        case 3:
			oled_set_cursor(0,11);
			oled_write_P(PSTR("FOUR\n"), false);
			break;
		case 4:
			oled_set_cursor(0,11);
			oled_write_P(PSTR("FIVE\n"), false);
			break;
		case 5:
			oled_set_cursor(0,11);
			oled_write_P(PSTR(" SIX\n"), false);
			break;
	}
}
#endif
