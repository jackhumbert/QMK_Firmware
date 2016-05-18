/*
Copyright 2012 Jun Wako 
Generated by planckkeyboard.com (2014 Jack Humbert)

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

/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

#ifndef DEBOUNCE
#   define DEBOUNCE 10
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

#if DIODE_DIRECTION == ROW2COL
    static matrix_row_t matrix_reversed[MATRIX_COLS];
    static matrix_row_t matrix_reversed_debouncing[MATRIX_COLS];
#endif


#if MATRIX_COLS > 16
    #define SHIFTER 1UL
#else
    #define SHIFTER 1
#endif

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

__attribute__ ((weak))
void matrix_init_quantum(void) {

}

__attribute__ ((weak))
void matrix_scan_quantum(void) {

}

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // To use PORTF disable JTAG with writing JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);


    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }

    matrix_init_quantum();
}


uint8_t matrix_scan(void)
{

#if DIODE_DIRECTION == COL2ROW
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }
#else
    for (uint8_t i = 0; i < MATRIX_COLS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t rows = read_cols();
        if (matrix_reversed_debouncing[i] != rows) {
            matrix_reversed_debouncing[i] = rows;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_COLS; i++) {
                matrix_reversed[i] = matrix_reversed_debouncing[i];
            }
        }
    }
    for (uint8_t y = 0; y < MATRIX_ROWS; y++) {
        matrix_row_t row = 0;
        for (uint8_t x = 0; x < MATRIX_COLS; x++) {
            row |= ((matrix_reversed[x] & (1<<y)) >> y) << x;
        }
        matrix[y] = row;
    }
#endif

    matrix_scan_quantum();

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

static void init_cols(void)
{
    int B = 0, C = 0, D = 0, E = 0, F = 0;

#if DIODE_DIRECTION == COL2ROW
    for(int x = 0; x < MATRIX_COLS; x++) {
        int col = COLS[x];
#else
    for(int x = 0; x < MATRIX_ROWS; x++) {
        int col = ROWS[x];
#endif
        if ((col & 0xF0) == 0x20) { 
            B |= (1<<(col & 0x0F)); 
        } else if ((col & 0xF0) == 0x30) { 
            C |= (1<<(col & 0x0F)); 
        } else if ((col & 0xF0) == 0x40) { 
            D |= (1<<(col & 0x0F)); 
        } else if ((col & 0xF0) == 0x50) { 
            E |= (1<<(col & 0x0F)); 
        } else if ((col & 0xF0) == 0x60) { 
            F |= (1<<(col & 0x0F)); 
        } 
    }
    DDRB &= ~(B); PORTB |= (B);
    DDRC &= ~(C); PORTC |= (C); 
    DDRD &= ~(D); PORTD |= (D);
    DDRE &= ~(E); PORTE |= (E);
    DDRF &= ~(F); PORTF |= (F);
}

static matrix_row_t read_cols(void)
{
    matrix_row_t result = 0;

#if DIODE_DIRECTION == COL2ROW
    for(int x = 0; x < MATRIX_COLS; x++) {     
        int col = COLS[x];
#else
    for(int x = 0; x < MATRIX_ROWS; x++) {
        int col = ROWS[x];
#endif

        if ((col & 0xF0) == 0x20) { 
            result |= (PINB&(1<<(col & 0x0F)) ? 0 : (SHIFTER<<x)); 
        } else if ((col & 0xF0) == 0x30) { 
            result |= (PINC&(1<<(col & 0x0F)) ? 0 : (SHIFTER<<x)); 
        } else if ((col & 0xF0) == 0x40) { 
            result |= (PIND&(1<<(col & 0x0F)) ? 0 : (SHIFTER<<x)); 
        } else if ((col & 0xF0) == 0x50) { 
            result |= (PINE&(1<<(col & 0x0F)) ? 0 : (SHIFTER<<x)); 
        } else if ((col & 0xF0) == 0x60) { 
            result |= (PINF&(1<<(col & 0x0F)) ? 0 : (SHIFTER<<x)); 
        } 
    }
    return result;
}

static void unselect_rows(void)
{
    int B = 0, C = 0, D = 0, E = 0, F = 0;

#if DIODE_DIRECTION == COL2ROW
    for(int x = 0; x < MATRIX_ROWS; x++) { 
        int row = ROWS[x];
#else
    for(int x = 0; x < MATRIX_COLS; x++) { 
        int row = COLS[x];
#endif
        if ((row & 0xF0) == 0x20) { 
            B |= (1<<(row & 0x0F)); 
        } else if ((row & 0xF0) == 0x30) { 
            C |= (1<<(row & 0x0F)); 
        } else if ((row & 0xF0) == 0x40) { 
            D |= (1<<(row & 0x0F)); 
        } else if ((row & 0xF0) == 0x50) { 
            E |= (1<<(row & 0x0F)); 
        } else if ((row & 0xF0) == 0x60) { 
            F |= (1<<(row & 0x0F)); 
        } 
    }
    DDRB &= ~(B); PORTB |= (B);
    DDRC &= ~(C); PORTC |= (C); 
    DDRD &= ~(D); PORTD |= (D);
    DDRE &= ~(E); PORTE |= (E);
    DDRF &= ~(F); PORTF |= (F);
}

static void select_row(uint8_t row)
{

#if DIODE_DIRECTION == COL2ROW
    int row_pin = ROWS[row];
#else
    int row_pin = COLS[row];
#endif

    if ((row_pin & 0xF0) == 0x20) { 
        DDRB  |= (1<<(row_pin & 0x0F));
        PORTB &= ~(1<<(row_pin & 0x0F));
    } else if ((row_pin & 0xF0) == 0x30) { 
        DDRC  |= (1<<(row_pin & 0x0F));
        PORTC &= ~(1<<(row_pin & 0x0F));
    } else if ((row_pin & 0xF0) == 0x40) { 
        DDRD  |= (1<<(row_pin & 0x0F));
        PORTD &= ~(1<<(row_pin & 0x0F));
    } else if ((row_pin & 0xF0) == 0x50) { 
        DDRE  |= (1<<(row_pin & 0x0F));
        PORTE &= ~(1<<(row_pin & 0x0F));
    } else if ((row_pin & 0xF0) == 0x60) { 
        DDRF  |= (1<<(row_pin & 0x0F));
        PORTF &= ~(1<<(row_pin & 0x0F));
    }  
}