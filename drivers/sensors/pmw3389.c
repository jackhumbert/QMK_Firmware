/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 * Copyright 2021 Alabastard (@Alabastard-64)
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

#include "pmw3389.h"
#include "wait.h"
#include "debug.h"
#include "print.h"
#include PMW3389_FIRMWARE_H

// Registers
// clang-format off
#define REG_Product_ID                 0x00
#define REG_Revision_ID                0x01
#define REG_Motion                     0x02
#define REG_Delta_X_L                  0x03
#define REG_Delta_X_H                  0x04
#define REG_Delta_Y_L                  0x05
#define REG_Delta_Y_H                  0x06
#define REG_SQUAL                      0x07
#define REG_RawData_Sum                0x08
#define REG_Maximum_RawData            0x09
#define REG_Minimum_RawData            0x0A
#define REG_Shutter_Lower              0x0B
#define REG_Shutter_Upper              0x0C
#define REG_Ripple_Control             0x0D
#define REG_Resolution_L               0x0E
#define REG_Resolution_H               0x0F
#define REG_Config2                    0x10
#define REG_Angle_Tune                 0x11
#define REG_Frame_Capture              0x12
#define REG_SROM_Enable                0x13
#define REG_Run_Downshift              0x14
#define REG_Rest1_Rate_Lower           0x15
#define REG_Rest1_Rate_Upper           0x16
#define REG_Rest1_Downshift            0x17
#define REG_Rest2_Rate_Lower           0x18
#define REG_Rest2_Rate_Upper           0x19
#define REG_Rest2_Downshift            0x1A
#define REG_Rest3_Rate_Lower           0x1B
#define REG_Rest3_Rate_Upper           0x1C
#define REG_Observation                0x24
#define REG_Data_Out_Lower             0x25
#define REG_Data_Out_Upper             0x26
#define REG_SROM_ID                    0x2A
#define REG_Min_SQ_Run                 0x2B
#define REG_RawData_Threshold          0x2C
#define REG_Control2                   0x2D
#define REG_Config5_L                  0x2E
#define REG_Config5_H                  0x2F
#define REG_Power_Up_Reset             0X3A
#define REG_Shutdown                   0x3B
#define REG_Inverse_Product_ID         0x3F
#define REG_LiftCutoff_Cal3            0x41
#define REG_Angle_Snap                 0x42
#define REG_LiftCutoff_Cal1            0x4A
#define REG_Motion_Burst               0x50
#define REG_SROM_Load_Burst            0x62
#define REG_Lift_Config                0x63
#define REG_RawData_Burst              0x64
#define REG_LiftCutoff_Cal2            0x65
#define REG_LiftCutoff_Cal_Timeout     0x71
#define REG_LiftCutoff_Cal_Min_Length  0x72
#define REG_PWM_Period_Cnt             0x73
#define REG_PWM_Width_Cnt              0x74

// clang-format on

#ifndef MAX_CPI
#    define MAX_CPI 0x013F  // limits to 0--319, should be max cpi/50 -1
#endif

bool _inBurst = false;

#ifdef CONSOLE_ENABLE
void print_byte(uint8_t byte) { dprintf("%c%c%c%c%c%c%c%c|", (byte & 0x80 ? '1' : '0'), (byte & 0x40 ? '1' : '0'), (byte & 0x20 ? '1' : '0'), (byte & 0x10 ? '1' : '0'), (byte & 0x08 ? '1' : '0'), (byte & 0x04 ? '1' : '0'), (byte & 0x02 ? '1' : '0'), (byte & 0x01 ? '1' : '0')); }
#endif
#define constrain(amt, low, high) ((amt) < (low) ? (low) : ((amt) > (high) ? (high) : (amt)))

bool spi_start_adv(void) {
    bool status = spi_start(PMW3389_CS_PIN, PMW3389_SPI_LSBFIRST, PMW3389_SPI_MODE, PMW3389_SPI_DIVISOR);
    wait_us(1);
    return status;
}

void spi_stop_adv(void) {
    wait_us(1);
    spi_stop();
}

spi_status_t spi_write_adv(uint8_t reg_addr, uint8_t data) {
    if (reg_addr != REG_Motion_Burst) {
        _inBurst = false;
    }

    spi_start_adv();
    // send address of the register, with MSBit = 1 to indicate it's a write
    spi_status_t status = spi_write(reg_addr | 0x80);
    status              = spi_write(data);

    // tSCLK-NCS for write operation
    wait_us(35);

    // tSWW/tSWR (=180us) minus tSCLK-NCS. Could be shortened, but is looks like a safe lower bound
    wait_us(145);
    spi_stop();
    return status;
}

uint8_t spi_read_adv(uint8_t reg_addr) {
    spi_start_adv();
    // send adress of the register, with MSBit = 0 to indicate it's a read
    spi_write(reg_addr & 0x7f);

    uint8_t data = spi_read();

    // tSCLK-NCS for read operation is 120ns
    wait_us(1);

    //  tSRW/tSRR (=20us) minus tSCLK-NCS
    wait_us(19);

    spi_stop();
    return data;
}

void pmw3389_set_cpi(uint16_t cpi) {
    uint16_t cpival = constrain((cpi / 50) - 1, 0, MAX_CPI);

    spi_start_adv();
    // Set upper byte first for more consistent setting of cpi
    spi_write_adv(REG_Resolution_H, (cpival >> 8) & 0xFF);
    spi_write_adv(REG_Resolution_L, cpival & 0xFF);
    spi_stop();
}

uint16_t pmw3389_get_cpi(void) {
    uint16_t cpival = (spi_read_adv(REG_Resolution_H) << 8) | spi_read_adv(REG_Resolution_L);
    return (uint16_t)((cpival + 1) & 0xFFFF) * 50;
}

bool pmw3389_init(void) {
    setPinOutput(PMW3389_CS_PIN);

    spi_init();
    _inBurst = false;

    spi_stop();
    spi_start_adv();
    spi_stop();

    spi_write_adv(REG_Shutdown, 0xb6);  // Shutdown first
    wait_ms(300);

    spi_start_adv();
    wait_us(40);
    spi_stop_adv();
    wait_us(40);

    spi_write_adv(REG_Power_Up_Reset, 0x5a);
    wait_ms(50);

    spi_read_adv(REG_Motion);
    spi_read_adv(REG_Delta_X_L);
    spi_read_adv(REG_Delta_X_H);
    spi_read_adv(REG_Delta_Y_L);
    spi_read_adv(REG_Delta_Y_H);

    pmw3389_upload_firmware();

    spi_stop_adv();

    wait_ms(10);
    pmw3389_set_cpi(PMW3389_CPI);

    wait_ms(1);

    spi_write_adv(REG_Config2, 0x00);

    spi_write_adv(REG_Angle_Tune, constrain(ROTATIONAL_TRANSFORM_ANGLE, -127, 127));

    spi_write_adv(REG_Lift_Config, PMW3389_LIFTOFF_DISTANCE);

    bool init_success = pmw3389_check_signature();

    writePinLow(PMW3389_CS_PIN);

    return init_success;
}

void pmw3389_upload_firmware(void) {
    spi_write_adv(REG_SROM_Enable, 0x1d);

    wait_ms(10);

    spi_write_adv(REG_SROM_Enable, 0x18);

    spi_start_adv();
    spi_write(REG_SROM_Load_Burst | 0x80);
    wait_us(15);

    unsigned char c;
    for (int i = 0; i < FIRMWARE_LENGTH; i++) {
        c = (unsigned char)pgm_read_byte(firmware_data + i);
        spi_write(c);
        wait_us(15);
    }
    wait_us(200);

    spi_read_adv(REG_SROM_ID);

    spi_write_adv(REG_Config2, 0x00);

    spi_stop();
    wait_ms(10);
}

bool pmw3389_check_signature(void) {
    uint8_t pid      = spi_read_adv(REG_Product_ID);
    uint8_t iv_pid   = spi_read_adv(REG_Inverse_Product_ID);
    uint8_t SROM_ver = spi_read_adv(REG_SROM_ID);
    return (pid == firmware_signature[0] && iv_pid == firmware_signature[1] && SROM_ver == firmware_signature[2]);  // signature for SROM 0x04
}

report_pmw3389_t pmw3389_read_burst(void) {
    if (!_inBurst) {
#ifdef CONSOLE_ENABLE
        dprintf("burst on");
#endif
        spi_write_adv(REG_Motion_Burst, 0x00);
        _inBurst = true;
    }

    spi_start_adv();
    spi_write(REG_Motion_Burst);
    wait_us(35);  // waits for tSRAD

    report_pmw3389_t data = {0};

    data.motion = spi_read();
    spi_write(0x00);  // skip Observation
    data.dx  = spi_read();
    data.mdx = spi_read();
    data.dy  = spi_read();
    data.mdy = spi_read();

    spi_stop();

#ifdef CONSOLE_ENABLE
    if (debug_mouse) {
        print_byte(data.motion);
        print_byte(data.dx);
        print_byte(data.mdx);
        print_byte(data.dy);
        print_byte(data.mdy);
        dprintf("\n");
    }
#endif

    data.isMotion    = (data.motion & 0x80) != 0;
    data.isOnSurface = (data.motion & 0x08) == 0;
    data.dx |= (data.mdx << 8);
    data.dx = data.dx * -1;
    data.dy |= (data.mdy << 8);
    data.dy = data.dy * -1;

    spi_stop();

    if (data.motion & 0b111) {  // panic recovery, sometimes burst mode works weird.
        _inBurst = false;
    }

    return data;
}
