/*
Copyright 2019 Batuhan Başerdem <baserdem.batuhan@gmail.com> @bbaserdem
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
#include "bbaserdem.h"
#include "bb-crkbdarm-oled.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_wrapper(
        BB_ENC0,_BL1_5_,_BR1_5_,BB_ENC1,
        _BL2_1_,_BL2_5_,_BR2_5_,_BR2_1_,
        _BL3_1_,_BL3_5_,_BR3_5_,_BR3_1_,
                _BL4_3_,_BR4_3_
    ),
    [_CHAR] = LAYOUT_split_3x6_3_wrapper(
        _______,_CL1_5_,_CR1_5_,_______,
        XXXXXXX,_CL2_5_,_CR2_5_,XXXXXXX,
        XXXXXXX,_CL3_5_,_CR3_5_,XXXXXXX,
                _CL4_3_,_CR4_3_
    ),
    [_GAME] = LAYOUT_split_3x6_3_wrapper(
        _______,_GA1_5_,___6___,
        _GA2_1_,_GA2_5_,___6___,
        _GA3_1_,_GA3_5_,___6___,
                _GA4_3_,___3___
    ),
    [_MEDI] = LAYOUT_split_3x6_3_wrapper(
        ___6___,_ME1_5_,_______,
        ___6___,_ME2_5_,xxx1xxx,
        ___6___,_ME3_5_,xxx1xxx,
        ___3___,_ME4_3_
    ),
    [_NAVI] = LAYOUT_split_3x6_3_wrapper(
        ___6___,_NA1_5_,_______,
        ___6___,_NA2_5_,xxx1xxx,
        ___6___,_NA3_5_,xxx1xxx,
        ___3___,_NA4_3_
    ),
    [_SYMB] = LAYOUT_split_3x6_3_wrapper(
        ___6___,_SY1_5_,_______,
        ___6___,_SY2_5_,xxx1xxx,
        ___6___,_SY3_5_,xxx1xxx,
        ___3___,_SY4_3_
    ),
    [_NUMB] = LAYOUT_split_3x6_3_wrapper(
        _______,_NU1_5_,___6___,
        xxx1xxx,_NU2_5_,___6___,
        xxx1xxx,_NU3_5_,___6___,
                _NU4_3_,___3___
    ),
    [_FUNC] = LAYOUT_split_3x6_3_wrapper(
        _______,_FU1_5_,___6___,
        xxx1xxx,_FU2_5_,___6___,
        xxx1xxx,_FU3_5_,___6___,
                _FU4_3_,___3___
    ),
    [_MOUS] = LAYOUT_split_3x6_3_wrapper(
        _______,_MO1_5_,___6___,
        xxx1xxx,_MO2_5_,___6___,
        xxx1xxx,_MO3_5_,___6___,
                _MO4_3_,___3___
    ),
    [_MUSI] = LAYOUT_split_3x6_3_wrapper(
            _MU_12_,
            _MU_12_,
            _MU_12_,
        _MUL_3_,_MUR_3_
    )
};

#ifdef AUDIO_ENABLE
// crkbd
#if defined(KEYBOARD_crkbd_rev1)
// Audio requires some fixes to work on @waffle's PCB
// ! Copy pasted from ItsWaffle's waffle fork
void keyboard_pre_init_keymap(void) {
    //thank you to @sigprof for this
    // Set audio pins to analog mode
    palSetLineMode(A5, PAL_MODE_INPUT_ANALOG);
    palSetLineMode(B1, PAL_MODE_INPUT_ANALOG);
}

void keyboard_post_init_keymap(void) {
    // Enable OPAMP1 as A5 → B1 follower
    OPAMP3->CSR = OPAMP3_CSR_VMSEL_1 | OPAMP3_CSR_VMSEL_0 | OPAMP3_CSR_VPSEL_0 | OPAMP3_CSR_OPAMP3EN;
}

// Flip the display on the right half
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_left()) {
        return OLED_ROTATION_180; 
    }

    return rotation;
}

bool oled_task_keymap(void) {
    if (is_keyboard_left()) {
        render_status_left();
    } else {
        render_status_right();
    }
    return false;
}
#endif // End of differentiations
#endif // End of audio specific stuff
