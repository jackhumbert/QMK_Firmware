/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fsl_device_registers.h"
#include "fsl_sim_hal.h"
#include "fsl_clock_manager.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Table of base addresses for instances. */
extern const uint32_t g_simBaseAddr[];
extern const uint32_t g_mcgBaseAddr[];

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetDmaFreq
 * Description   : Gets the clock frequency for DMA module
 * This function gets the clock frequency for DMA moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetDmaFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kSystemClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetDmamuxFreq
 * Description   : Gets the clock frequency for DMAMUX module
 * This function gets the clock frequency for DMAMUX moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetDmamuxFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetPortFreq
 * Description   : Gets the clock frequency for PORT module
 * This function gets the clock frequency for PORT moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetPortFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kLpoClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetMpuFreq
 * Description   : Gets the clock frequency for MPU module
 * This function gets the clock frequency for MPU moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetMpuFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kSystemClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetEwmFreq
 * Description   : Gets the clock frequency for Ewm module
 * This function gets the clock frequency for Ewm moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetEwmFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kLpoClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetFlexbusFreq
 * Description   : Gets the clock frequency for FLEXBUS module
 * This function gets the clock frequency for FLEXBUS moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetFlexbusFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kSystemClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetFtfFreq
 * Description   : Gets the clock frequency for FTF module. (Flash Memory)
 * This function gets the clock frequency for FTF moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetFtfFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kFlashClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetCrcFreq
 * Description   : Gets the clock frequency for CRC module
 * This function gets the clock frequency for CRC moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetCrcFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetRngaFreq
 * Description   : Gets the clock frequency for RNGA module
 * This function gets the clock frequency for RNGA moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetRngaFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetAdcFreq
 * Description   : Gets the clock frequency for ADC module
 * This function gets the clock frequency for ADC moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetAdcFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kOsc0ErClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetCmpFreq
 * Description   : Gets the clock frequency for CMP module
 * This function gets the clock frequency for CMP moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetCmpFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetVrefFreq
 * Description   : Gets the clock frequency for VREF module
 * This function gets the clock frequency for VREF moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetVrefFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetPdbFreq
 * Description   : Gets the clock frequency for PDB module
 * This function gets the clock frequency for PDB moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetPdbFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetFtmFreq
 * Description   : Gets the clock frequency for FTM module. (FlexTimers)
 * This function gets the clock frequency for FTM moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetFtmFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kMcgFfClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetPitFreq
 * Description   : Gets the clock frequency for Pit module. 
 * This function gets the clock frequency for Pit moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetPitFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetCmtFreq
 * Description   : Gets the clock frequency for CMT module. 
 * This function gets the clock frequency for CMT moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetCmtFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetEnetRmiiFreq
 * Description   : Gets the clock frequency for ENET module RMII clock. 
 * This function gets the clock frequency for ENET moudle RMII clock.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetEnetRmiiFreq(uint32_t instance)
{
    uint32_t freq = 0;
    uint8_t setting;
    clock_names_t clockName;
    /* get the sim clock source setting*/
    if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockRmiiSrc, &setting) != kSimHalSuccess)
    {
        return freq;
    }

    if ((sim_rmii_clock_source_t)setting == kSimRmiiSrcExtalClk)
    {
        clockName = kEXTAL_Clock;
    }
    else
    {
        clockName = kENET_1588_CLKIN;
    }

    CLOCK_SYS_GetFreq(clockName, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetEnetTimeStampFreq
 * Description   : Gets the clock frequency for ENET module TIME clock. 
 * This function gets the clock frequency for ENET moudle TIME clock.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetEnetTimeStampFreq(uint32_t instance)
{
    uint32_t freq = 0;
    uint8_t setting;
    clock_names_t clockName;

    /* get the sim clock source setting*/
    if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockTimeSrc, &setting) != kSimHalSuccess)
    {
        return freq;
    }

    switch ((sim_time_clock_source_t)setting)
    {
    case kSimTimeSrcCoreSysClk:  /* Core/system clock */
        clockName = kCoreClock;
        break;
    case kSimTimeSrcPllFllSel:   /* clock as selected by SOPT2[PLLFLLSEL]. */
        /* get the sim clock source setting*/
        if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockPllfllSel, &setting) != kSimHalSuccess)
        {
            return freq;
        }

        switch ((sim_pllfll_clock_sel_t)setting) 
        {
        case kSimPllFllSelFll:       /* Fll clock */
            clockName = kMcgFllClock;
            break;
        case kSimPllFllSelPll:        /* Pll0 clock */
            clockName = kMcgPll0Clock;
            break;
        default:
            clockName = kReserved;
            break;
        }
        break;
    case kSimTimeSrcOscerclk:    /* OSCERCLK clock */
        clockName = kOsc0ErClock;
        break;
    case kSimTimeSrcExt:         /* Enet 1588 clock */
        clockName = kENET_1588_CLKIN;
        break;
    default:
        clockName = kReserved;
        break;
    }

    /* Get ref clock freq */
    CLOCK_SYS_GetFreq(clockName, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetUsbFreq
 * Description   : Gets the clock frequency for USB FS OTG module. 
 * This function gets the clock frequency for USB FS OTG moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetUsbFreq(uint32_t instance)
{
    uint32_t freq = 0;
    uint8_t setting;
    clock_names_t clockName;
    uint32_t frac = 0;
    uint32_t divider = 0;

    /* get the sim clock source setting*/
    if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockUsbSrc, &setting) != kSimHalSuccess)
    {
        return freq;
    }

    switch ((sim_usb_clock_source_t)setting)
    {
    case kSimUsbSrcClkIn:  /* Core/system clock */
        clockName = kUSB_CLKIN;
        break;
    case kSimUsbSrcPllFllSel:   /* clock as selected by SOPT2[PLLFLLSEL]. */
        /* get the sim clock source setting*/
        if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockPllfllSel, &setting) != kSimHalSuccess)
        {
            return freq;
        }

        switch ((sim_pllfll_clock_sel_t)setting) 
        {
        case kSimPllFllSelFll:       /* Fll clock */
            clockName = kMcgFllClock;
            break;
        case kSimPllFllSelPll:        /* Pll0 clock */
            clockName = kMcgPll0Clock;
            break;
        default:
            clockName = kReserved;
            break;
        }
        break;
    default:
        clockName = kReserved;
        break;
    }

    /* Get ref clock freq */
    CLOCK_SYS_GetFreq(clockName, &freq);

    /* Get divider and frac */
    CLOCK_HAL_GetDivider(g_simBaseAddr[0], kClockDividerUsbDiv, &divider);
    CLOCK_HAL_GetDivider(g_simBaseAddr[0], kClockDividerUsbFrac, &frac);

    /* Divider output clock = Divider input clock � [ (FRAC+1) / (DIV+1) ]*/
    freq = (freq) * (frac + 1) / (divider + 1);

    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetUsbdcdFreq
 * Description   : Gets the clock frequency for USB DCD module. 
 * This function gets the clock frequency for USB DCD moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetUsbdcdFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetSpiFreq
 * Description   : Gets the clock frequency for SPI module. 
 * This function gets the clock frequency for SPI moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetSpiFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetI2cFreq
 * Description   : Gets the clock frequency for I2C module. 
 * This function gets the clock frequency for I2C moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetI2cFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetUartFreq
 * Description   : Gets the clock frequency for UART module. 
 * This function gets the clock frequency for UART moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetUartFreq(uint32_t instance)
{
    uint32_t freq = 0;

    switch (instance)
    {
    case 0:
    case 1:
        CLOCK_SYS_GetFreq(kSystemClock, &freq);
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        CLOCK_SYS_GetFreq(kBusClock, &freq);
        break;
    default:
        break;
    }

    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetSdhcFreq
 * Description   : Gets the clock frequency for SDHC module
 * This function gets the clock frequency for SDHC moudle
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetSdhcFreq(uint32_t instance)
{
    uint32_t freq = 0;
    uint8_t setting;
    clock_names_t clockName;

    /* get the sim clock source setting*/
    if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockSdhcSrc, &setting) != kSimHalSuccess)
    {
        return freq;
    }

    switch ((sim_sdhc_clock_source_t)setting)
    {
    case kSimSdhcSrcCoreSysClk:  /* Core/system clock */
        clockName = kCoreClock;
        break;
    case kSimSdhcSrcPllFllSel:   /* clock as selected by SOPT2[PLLFLLSEL]. */
        /* get the sim clock source setting*/
        if (CLOCK_HAL_GetSource(g_simBaseAddr[0], kClockPllfllSel, &setting) != kSimHalSuccess)
        {
            return freq;
        }

        switch ((sim_pllfll_clock_sel_t)setting) 
        {
        case kSimPllFllSelFll:       /* Fll clock */
            clockName = kMcgFllClock;
            break;
        case kSimPllFllSelPll:        /* Pll0 clock */
            clockName = kMcgPll0Clock;
            break;
        default:
            clockName = kReserved;
            break;
        }
        break;
    case kSimSdhcSrcOscerclk:    /* OSCERCLK clock */
        clockName = kOsc0ErClock;
        break;
    case kSimSdhcSrcExt:         /* SDHC CLKIN clock */
        clockName = kSDHC0_CLKIN;
        break;
    default:
        clockName = kReserved;
        break;
    }

    /* Get ref clock freq */
    CLOCK_SYS_GetFreq(clockName, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetSaiFreq
 * Description   : Gets the clock frequency for I2S module
 * This function gets the clock frequency for I2S moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetSaiFreq(uint32_t instance)
{
    uint32_t freq = 0;
    CLOCK_SYS_GetFreq(kBusClock, &freq);
    return freq;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : CLOCK_SYS_GetGpioFreq
 * Description   : Gets the clock frequency for GPIO module. 
 * This function gets the clock frequency for GPIO moudle.
 *
 *END**************************************************************************/
uint32_t    CLOCK_SYS_GetGpioFreq(uint32_t instance)
{
    uint32_t freq = 0;

    CLOCK_SYS_GetFreq(kSystemClock, &freq);

    return freq;
}
/*******************************************************************************
 * EOF
 ******************************************************************************/
