/*
Copyright 2012-2018 Jun Wako, Jack Humbert, Yiancar

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
#include <stdint.h>
#include <stdbool.h>
#include "util.h"
#include "matrix.h"
#include "matrix_demux.h"
#include "debounce.h"
#include "quantum.h"

#ifdef DIRECT_PINS
static pin_t direct_pins[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS;
#elif (DIODE_DIRECTION == ROW2COL) || (DIODE_DIRECTION == COL2ROW)
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;
#endif

/* matrix state(1:on, 0:off) */
extern matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
extern matrix_row_t matrix[MATRIX_ROWS];      // debounced values

// matrix code

#ifndef DEMUX_INPUT_PINS
#    error MATRIX_DEMUX requires DEMUX_INPUT_PINS to be defined!
#endif

#ifndef DEMUX_NO_ENABLE_PIN
#   ifndef DEMUX_ENABLE_PIN
#       error MATRIX_DEMUX requires DEMUX_ENABLE_PIN to be defined! If Y0 is unused on your demultiplexer, you can ignore this error by defining DEMUX_NO_ENABLE_PIN.
#   endif
#endif

#ifdef DEMUX_74HC138
#   define DEMUX_INPUTS 3
#elif defined(DEMUX_74HC154)
#   define DEMUX_INPUTS 4
#endif

#ifndef DEMUX_INPUTS
#   error Please define which demultiplexer you have with #define DEMUX_HC138 or #define DEMUX_HC154.
#endif

static pin_t demux_input_pins[DEMUX_INPUTS] = DEMUX_INPUT_PINS;

static void unselect_demux(void) {
    for (uint8_t x = 0; x < DEMUX_INPUTS; x++) {
        setPinOutput(demux_input_pins[x]);
        writePinLow(demux_input_pins[x]);
    }
#ifndef DEMUX_NO_ENABLE_PIN
#   ifdef DEMUX_ENABLE_HIGH
    setPinOutput(DEMUX_ENABLE_PIN);
    writePinLow(DEMUX_ENABLE_PIN);
#   else
    setPinOutput(DEMUX_ENABLE_PIN);
    writePinHigh(DEMUX_ENABLE_PIN);
#   endif
#endif
}

static void activate_demux(void) {
#ifndef DEMUX_NO_ENABLE_PIN
#   ifdef DEMUX_ENABLE_HIGH
    setPinOutput(DEMUX_ENABLE_PIN);
    writePinHigh(DEMUX_ENABLE_PIN);
#   else
    setPinOutput(DEMUX_ENABLE_PIN);
    writePinLow(DEMUX_ENABLE_PIN);
#   endif
#endif
}

static void demux_set_active(uint8_t pin) {
    unselect_demux();

#define DEMUX_A0 demux_input_pins[0]
#define DEMUX_A1 demux_input_pins[1]
#define DEMUX_A2 demux_input_pins[2]

#ifdef DEMUX_74HC154
#   define DEMUX_A3 demux_input_pins[3]
#endif
    switch (pin) {
        case Y0:
            activate_demux();
            break;
        case Y1:
            activate_demux();
            writePinHigh(DEMUX_A0);
            break;
        case Y2:
            activate_demux();
            writePinHigh(DEMUX_A1);
            break;
        case Y3:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A1);
            break;
        case Y4:
            activate_demux();
            writePinHigh(DEMUX_A2);
            break;
        case Y5:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A2);
            break;
        case Y6:
            activate_demux();
            writePinHigh(DEMUX_A1);
            writePinHigh(DEMUX_A2);
            break;
        case Y7:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A1);
            writePinHigh(DEMUX_A2);
            break;
#ifdef DEMUX_74HC154
        case Y8:
            activate_demux();
            writePinHigh(DEMUX_A3);
            break;
        case Y9:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A3);
            break;
        case Y10:
            activate_demux();
            writePinHigh(DEMUX_A1);
            writePinHigh(DEMUX_A3);
            break;
        case Y11:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A1);
            writePinHigh(DEMUX_A3);
            break;
        case Y12:
            activate_demux();
            writePinHigh(DEMUX_A2);
            writePinHigh(DEMUX_A3);
            break;
        case Y13:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A2);
            writePinHigh(DEMUX_A3);
            break;
        case Y14:
            activate_demux();
            writePinHigh(DEMUX_A1);
            writePinHigh(DEMUX_A2);
            writePinHigh(DEMUX_A3);
            break;
        case Y15:
            activate_demux();
            writePinHigh(DEMUX_A0);
            writePinHigh(DEMUX_A1);
            writePinHigh(DEMUX_A2);
            writePinHigh(DEMUX_A3);
            break;
#endif
        default:
            setPinOutput(pin);
            writePinLow(pin);
            break;
    }
}

#ifdef DIRECT_PINS
#    error DIRECT_PINS is not supported by MATRIX_DEMUX!
#elif defined(DIODE_DIRECTION)
#    if (DIODE_DIRECTION == COL2ROW)

static void select_row(uint8_t row) {
    demux_set_active(row_pins[row]);
}

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
    unselect_demux();
}

static void init_pins(void) {
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // Select row and wait for row selecton to stabilize
    select_row(current_row);
    matrix_io_delay();

    // For each col...
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = readPin(col_pins[col_index]);

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_rows();

    // If the row has changed, store the row and return the changed flag.
    if (current_matrix[current_row] != current_row_value) {
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}

#    elif (DIODE_DIRECTION == ROW2COL)

static void select_col(uint8_t col) {
    demux_set_active(col_pins[col]);
}

static void unselect_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        setPinInputHigh(col_pins[x]);
    }
    unselect_demux();
}

static void init_pins(void) {
    unselect_cols();
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;

    // Select col and wait for col selecton to stabilize
    select_col(current_col);
    matrix_io_delay();

    // For each row...
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // Store last value of row prior to reading
        matrix_row_t last_row_value    = current_matrix[row_index];
        matrix_row_t current_row_value = last_row_value;

        // Check row pin state
        if (readPin(row_pins[row_index]) == 0) {
            // Pin LO, set col bit
            current_row_value |= (MATRIX_ROW_SHIFTER << current_col);
        } else {
            // Pin HI, clear col bit
            current_row_value &= ~(MATRIX_ROW_SHIFTER << current_col);
        }

        // Determine if the matrix changed state
        if ((last_row_value != current_row_value)) {
            matrix_changed |= true;
            current_matrix[row_index] = current_row_value;
        }
    }

    // Unselect col
    unselect_cols();

    return matrix_changed;
}

#    else
#        error DIODE_DIRECTION must be one of COL2ROW or ROW2COL!
#    endif
#else
#    error DIODE_DIRECTION is not defined!
#endif

void matrix_init(void) {
    // initialize key pins
    init_pins();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i]     = 0;
    }

    debounce_init(MATRIX_ROWS);

    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    bool changed = false;

#if defined(DIRECT_PINS) || (DIODE_DIRECTION == COL2ROW)
    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        changed |= read_cols_on_row(raw_matrix, current_row);
    }
#elif (DIODE_DIRECTION == ROW2COL)
    // Set col, read rows
    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
        changed |= read_rows_on_col(raw_matrix, current_col);
    }
#endif

    debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    matrix_scan_quantum();
    return (uint8_t)changed;
}
