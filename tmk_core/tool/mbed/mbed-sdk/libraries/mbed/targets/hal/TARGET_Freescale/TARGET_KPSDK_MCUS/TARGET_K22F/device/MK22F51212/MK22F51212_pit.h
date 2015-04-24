/*
** ###################################################################
**     Compilers:           Keil ARM C/C++ Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    K22P121M120SF7RM, Rev. 1, March 24, 2014
**     Version:             rev. 2.5, 2014-05-06
**     Build:               b140604
**
**     Abstract:
**         Extension to the CMSIS register access layer header.
**
**     Copyright (c) 2014 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2013-07-23)
**         Initial version.
**     - rev. 1.1 (2013-09-17)
**         RM rev. 0.4 update.
**     - rev. 2.0 (2013-10-29)
**         Register accessor macros added to the memory map.
**         Symbols for Processor Expert memory map compatibility added to the memory map.
**         Startup file for gcc has been updated according to CMSIS 3.2.
**         System initialization updated.
**     - rev. 2.1 (2013-10-30)
**         Definition of BITBAND macros updated to support peripherals with 32-bit acces disabled.
**     - rev. 2.2 (2013-12-20)
**         Update according to reference manual rev. 0.6,
**     - rev. 2.3 (2014-01-13)
**         Update according to reference manual rev. 0.61,
**     - rev. 2.4 (2014-02-10)
**         The declaration of clock configurations has been moved to separate header file system_MK22F51212.h
**     - rev. 2.5 (2014-05-06)
**         Update according to reference manual rev. 1.0,
**         Update of system and startup files.
**         Module access macro module_BASES replaced by module_BASE_PTRS.
**
** ###################################################################
*/

/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_PIT_REGISTERS_H__
#define __HW_PIT_REGISTERS_H__

#include "MK22F51212.h"
#include "fsl_bitaccess.h"

/*
 * MK22F51212 PIT
 *
 * Periodic Interrupt Timer
 *
 * Registers defined in this header file:
 * - HW_PIT_MCR - PIT Module Control Register
 * - HW_PIT_LDVALn - Timer Load Value Register
 * - HW_PIT_CVALn - Current Timer Value Register
 * - HW_PIT_TCTRLn - Timer Control Register
 * - HW_PIT_TFLGn - Timer Flag Register
 *
 * - hw_pit_t - Struct containing all module registers.
 */

#define HW_PIT_INSTANCE_COUNT (1U) /*!< Number of instances of the PIT module. */

/*******************************************************************************
 * HW_PIT_MCR - PIT Module Control Register
 ******************************************************************************/

/*!
 * @brief HW_PIT_MCR - PIT Module Control Register (RW)
 *
 * Reset value: 0x00000006U
 *
 * This register enables or disables the PIT timer clocks and controls the
 * timers when the PIT enters the Debug mode.
 */
typedef union _hw_pit_mcr
{
    uint32_t U;
    struct _hw_pit_mcr_bitfields
    {
        uint32_t FRZ : 1;              /*!< [0] Freeze */
        uint32_t MDIS : 1;             /*!< [1] Module Disable - (PIT section) */
        uint32_t RESERVED0 : 30;       /*!< [31:2]  */
    } B;
} hw_pit_mcr_t;

/*!
 * @name Constants and macros for entire PIT_MCR register
 */
/*@{*/
#define HW_PIT_MCR_ADDR(x)       ((x) + 0x0U)

#define HW_PIT_MCR(x)            (*(__IO hw_pit_mcr_t *) HW_PIT_MCR_ADDR(x))
#define HW_PIT_MCR_RD(x)         (HW_PIT_MCR(x).U)
#define HW_PIT_MCR_WR(x, v)      (HW_PIT_MCR(x).U = (v))
#define HW_PIT_MCR_SET(x, v)     (HW_PIT_MCR_WR(x, HW_PIT_MCR_RD(x) |  (v)))
#define HW_PIT_MCR_CLR(x, v)     (HW_PIT_MCR_WR(x, HW_PIT_MCR_RD(x) & ~(v)))
#define HW_PIT_MCR_TOG(x, v)     (HW_PIT_MCR_WR(x, HW_PIT_MCR_RD(x) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PIT_MCR bitfields
 */

/*!
 * @name Register PIT_MCR, field FRZ[0] (RW)
 *
 * Allows the timers to be stopped when the device enters the Debug mode.
 *
 * Values:
 * - 0 - Timers continue to run in Debug mode.
 * - 1 - Timers are stopped in Debug mode.
 */
/*@{*/
#define BP_PIT_MCR_FRZ       (0U)          /*!< Bit position for PIT_MCR_FRZ. */
#define BM_PIT_MCR_FRZ       (0x00000001U) /*!< Bit mask for PIT_MCR_FRZ. */
#define BS_PIT_MCR_FRZ       (1U)          /*!< Bit field size in bits for PIT_MCR_FRZ. */

/*! @brief Read current value of the PIT_MCR_FRZ field. */
#define BR_PIT_MCR_FRZ(x)    (BITBAND_ACCESS32(HW_PIT_MCR_ADDR(x), BP_PIT_MCR_FRZ))

/*! @brief Format value for bitfield PIT_MCR_FRZ. */
#define BF_PIT_MCR_FRZ(v)    ((uint32_t)((uint32_t)(v) << BP_PIT_MCR_FRZ) & BM_PIT_MCR_FRZ)

/*! @brief Set the FRZ field to a new value. */
#define BW_PIT_MCR_FRZ(x, v) (BITBAND_ACCESS32(HW_PIT_MCR_ADDR(x), BP_PIT_MCR_FRZ) = (v))
/*@}*/

/*!
 * @name Register PIT_MCR, field MDIS[1] (RW)
 *
 * Disables the standard timers. This field must be enabled before any other
 * setup is done.
 *
 * Values:
 * - 0 - Clock for standard PIT timers is enabled.
 * - 1 - Clock for standard PIT timers is disabled.
 */
/*@{*/
#define BP_PIT_MCR_MDIS      (1U)          /*!< Bit position for PIT_MCR_MDIS. */
#define BM_PIT_MCR_MDIS      (0x00000002U) /*!< Bit mask for PIT_MCR_MDIS. */
#define BS_PIT_MCR_MDIS      (1U)          /*!< Bit field size in bits for PIT_MCR_MDIS. */

/*! @brief Read current value of the PIT_MCR_MDIS field. */
#define BR_PIT_MCR_MDIS(x)   (BITBAND_ACCESS32(HW_PIT_MCR_ADDR(x), BP_PIT_MCR_MDIS))

/*! @brief Format value for bitfield PIT_MCR_MDIS. */
#define BF_PIT_MCR_MDIS(v)   ((uint32_t)((uint32_t)(v) << BP_PIT_MCR_MDIS) & BM_PIT_MCR_MDIS)

/*! @brief Set the MDIS field to a new value. */
#define BW_PIT_MCR_MDIS(x, v) (BITBAND_ACCESS32(HW_PIT_MCR_ADDR(x), BP_PIT_MCR_MDIS) = (v))
/*@}*/

/*******************************************************************************
 * HW_PIT_LDVALn - Timer Load Value Register
 ******************************************************************************/

/*!
 * @brief HW_PIT_LDVALn - Timer Load Value Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * These registers select the timeout period for the timer interrupts.
 */
typedef union _hw_pit_ldvaln
{
    uint32_t U;
    struct _hw_pit_ldvaln_bitfields
    {
        uint32_t TSV : 32;             /*!< [31:0] Timer Start Value */
    } B;
} hw_pit_ldvaln_t;

/*!
 * @name Constants and macros for entire PIT_LDVALn register
 */
/*@{*/
#define HW_PIT_LDVALn_COUNT (4U)

#define HW_PIT_LDVALn_ADDR(x, n) ((x) + 0x100U + (0x10U * (n)))

#define HW_PIT_LDVALn(x, n)      (*(__IO hw_pit_ldvaln_t *) HW_PIT_LDVALn_ADDR(x, n))
#define HW_PIT_LDVALn_RD(x, n)   (HW_PIT_LDVALn(x, n).U)
#define HW_PIT_LDVALn_WR(x, n, v) (HW_PIT_LDVALn(x, n).U = (v))
#define HW_PIT_LDVALn_SET(x, n, v) (HW_PIT_LDVALn_WR(x, n, HW_PIT_LDVALn_RD(x, n) |  (v)))
#define HW_PIT_LDVALn_CLR(x, n, v) (HW_PIT_LDVALn_WR(x, n, HW_PIT_LDVALn_RD(x, n) & ~(v)))
#define HW_PIT_LDVALn_TOG(x, n, v) (HW_PIT_LDVALn_WR(x, n, HW_PIT_LDVALn_RD(x, n) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PIT_LDVALn bitfields
 */

/*!
 * @name Register PIT_LDVALn, field TSV[31:0] (RW)
 *
 * Sets the timer start value. The timer will count down until it reaches 0,
 * then it will generate an interrupt and load this register value again. Writing a
 * new value to this register will not restart the timer; instead the value will
 * be loaded after the timer expires. To abort the current cycle and start a
 * timer period with the new value, the timer must be disabled and enabled again.
 */
/*@{*/
#define BP_PIT_LDVALn_TSV    (0U)          /*!< Bit position for PIT_LDVALn_TSV. */
#define BM_PIT_LDVALn_TSV    (0xFFFFFFFFU) /*!< Bit mask for PIT_LDVALn_TSV. */
#define BS_PIT_LDVALn_TSV    (32U)         /*!< Bit field size in bits for PIT_LDVALn_TSV. */

/*! @brief Read current value of the PIT_LDVALn_TSV field. */
#define BR_PIT_LDVALn_TSV(x, n) (HW_PIT_LDVALn(x, n).U)

/*! @brief Format value for bitfield PIT_LDVALn_TSV. */
#define BF_PIT_LDVALn_TSV(v) ((uint32_t)((uint32_t)(v) << BP_PIT_LDVALn_TSV) & BM_PIT_LDVALn_TSV)

/*! @brief Set the TSV field to a new value. */
#define BW_PIT_LDVALn_TSV(x, n, v) (HW_PIT_LDVALn_WR(x, n, v))
/*@}*/
/*******************************************************************************
 * HW_PIT_CVALn - Current Timer Value Register
 ******************************************************************************/

/*!
 * @brief HW_PIT_CVALn - Current Timer Value Register (RO)
 *
 * Reset value: 0x00000000U
 *
 * These registers indicate the current timer position.
 */
typedef union _hw_pit_cvaln
{
    uint32_t U;
    struct _hw_pit_cvaln_bitfields
    {
        uint32_t TVL : 32;             /*!< [31:0] Current Timer Value */
    } B;
} hw_pit_cvaln_t;

/*!
 * @name Constants and macros for entire PIT_CVALn register
 */
/*@{*/
#define HW_PIT_CVALn_COUNT (4U)

#define HW_PIT_CVALn_ADDR(x, n)  ((x) + 0x104U + (0x10U * (n)))

#define HW_PIT_CVALn(x, n)       (*(__I hw_pit_cvaln_t *) HW_PIT_CVALn_ADDR(x, n))
#define HW_PIT_CVALn_RD(x, n)    (HW_PIT_CVALn(x, n).U)
/*@}*/

/*
 * Constants & macros for individual PIT_CVALn bitfields
 */

/*!
 * @name Register PIT_CVALn, field TVL[31:0] (RO)
 *
 * Represents the current timer value, if the timer is enabled. If the timer is
 * disabled, do not use this field as its value is unreliable. The timer uses a
 * downcounter. The timer values are frozen in Debug mode if MCR[FRZ] is set.
 */
/*@{*/
#define BP_PIT_CVALn_TVL     (0U)          /*!< Bit position for PIT_CVALn_TVL. */
#define BM_PIT_CVALn_TVL     (0xFFFFFFFFU) /*!< Bit mask for PIT_CVALn_TVL. */
#define BS_PIT_CVALn_TVL     (32U)         /*!< Bit field size in bits for PIT_CVALn_TVL. */

/*! @brief Read current value of the PIT_CVALn_TVL field. */
#define BR_PIT_CVALn_TVL(x, n) (HW_PIT_CVALn(x, n).U)
/*@}*/
/*******************************************************************************
 * HW_PIT_TCTRLn - Timer Control Register
 ******************************************************************************/

/*!
 * @brief HW_PIT_TCTRLn - Timer Control Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * These registers contain the control bits for each timer.
 */
typedef union _hw_pit_tctrln
{
    uint32_t U;
    struct _hw_pit_tctrln_bitfields
    {
        uint32_t TEN : 1;              /*!< [0] Timer Enable */
        uint32_t TIE : 1;              /*!< [1] Timer Interrupt Enable */
        uint32_t CHN : 1;              /*!< [2] Chain Mode */
        uint32_t RESERVED0 : 29;       /*!< [31:3]  */
    } B;
} hw_pit_tctrln_t;

/*!
 * @name Constants and macros for entire PIT_TCTRLn register
 */
/*@{*/
#define HW_PIT_TCTRLn_COUNT (4U)

#define HW_PIT_TCTRLn_ADDR(x, n) ((x) + 0x108U + (0x10U * (n)))

#define HW_PIT_TCTRLn(x, n)      (*(__IO hw_pit_tctrln_t *) HW_PIT_TCTRLn_ADDR(x, n))
#define HW_PIT_TCTRLn_RD(x, n)   (HW_PIT_TCTRLn(x, n).U)
#define HW_PIT_TCTRLn_WR(x, n, v) (HW_PIT_TCTRLn(x, n).U = (v))
#define HW_PIT_TCTRLn_SET(x, n, v) (HW_PIT_TCTRLn_WR(x, n, HW_PIT_TCTRLn_RD(x, n) |  (v)))
#define HW_PIT_TCTRLn_CLR(x, n, v) (HW_PIT_TCTRLn_WR(x, n, HW_PIT_TCTRLn_RD(x, n) & ~(v)))
#define HW_PIT_TCTRLn_TOG(x, n, v) (HW_PIT_TCTRLn_WR(x, n, HW_PIT_TCTRLn_RD(x, n) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PIT_TCTRLn bitfields
 */

/*!
 * @name Register PIT_TCTRLn, field TEN[0] (RW)
 *
 * Enables or disables the timer.
 *
 * Values:
 * - 0 - Timer n is disabled.
 * - 1 - Timer n is enabled.
 */
/*@{*/
#define BP_PIT_TCTRLn_TEN    (0U)          /*!< Bit position for PIT_TCTRLn_TEN. */
#define BM_PIT_TCTRLn_TEN    (0x00000001U) /*!< Bit mask for PIT_TCTRLn_TEN. */
#define BS_PIT_TCTRLn_TEN    (1U)          /*!< Bit field size in bits for PIT_TCTRLn_TEN. */

/*! @brief Read current value of the PIT_TCTRLn_TEN field. */
#define BR_PIT_TCTRLn_TEN(x, n) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(x, n), BP_PIT_TCTRLn_TEN))

/*! @brief Format value for bitfield PIT_TCTRLn_TEN. */
#define BF_PIT_TCTRLn_TEN(v) ((uint32_t)((uint32_t)(v) << BP_PIT_TCTRLn_TEN) & BM_PIT_TCTRLn_TEN)

/*! @brief Set the TEN field to a new value. */
#define BW_PIT_TCTRLn_TEN(x, n, v) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(x, n), BP_PIT_TCTRLn_TEN) = (v))
/*@}*/

/*!
 * @name Register PIT_TCTRLn, field TIE[1] (RW)
 *
 * When an interrupt is pending, or, TFLGn[TIF] is set, enabling the interrupt
 * will immediately cause an interrupt event. To avoid this, the associated
 * TFLGn[TIF] must be cleared first.
 *
 * Values:
 * - 0 - Interrupt requests from Timer n are disabled.
 * - 1 - Interrupt will be requested whenever TIF is set.
 */
/*@{*/
#define BP_PIT_TCTRLn_TIE    (1U)          /*!< Bit position for PIT_TCTRLn_TIE. */
#define BM_PIT_TCTRLn_TIE    (0x00000002U) /*!< Bit mask for PIT_TCTRLn_TIE. */
#define BS_PIT_TCTRLn_TIE    (1U)          /*!< Bit field size in bits for PIT_TCTRLn_TIE. */

/*! @brief Read current value of the PIT_TCTRLn_TIE field. */
#define BR_PIT_TCTRLn_TIE(x, n) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(x, n), BP_PIT_TCTRLn_TIE))

/*! @brief Format value for bitfield PIT_TCTRLn_TIE. */
#define BF_PIT_TCTRLn_TIE(v) ((uint32_t)((uint32_t)(v) << BP_PIT_TCTRLn_TIE) & BM_PIT_TCTRLn_TIE)

/*! @brief Set the TIE field to a new value. */
#define BW_PIT_TCTRLn_TIE(x, n, v) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(x, n), BP_PIT_TCTRLn_TIE) = (v))
/*@}*/

/*!
 * @name Register PIT_TCTRLn, field CHN[2] (RW)
 *
 * When activated, Timer n-1 needs to expire before timer n can decrement by 1.
 * Timer 0 cannot be chained.
 *
 * Values:
 * - 0 - Timer is not chained.
 * - 1 - Timer is chained to previous timer. For example, for Channel 2, if this
 *     field is set, Timer 2 is chained to Timer 1.
 */
/*@{*/
#define BP_PIT_TCTRLn_CHN    (2U)          /*!< Bit position for PIT_TCTRLn_CHN. */
#define BM_PIT_TCTRLn_CHN    (0x00000004U) /*!< Bit mask for PIT_TCTRLn_CHN. */
#define BS_PIT_TCTRLn_CHN    (1U)          /*!< Bit field size in bits for PIT_TCTRLn_CHN. */

/*! @brief Read current value of the PIT_TCTRLn_CHN field. */
#define BR_PIT_TCTRLn_CHN(x, n) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(x, n), BP_PIT_TCTRLn_CHN))

/*! @brief Format value for bitfield PIT_TCTRLn_CHN. */
#define BF_PIT_TCTRLn_CHN(v) ((uint32_t)((uint32_t)(v) << BP_PIT_TCTRLn_CHN) & BM_PIT_TCTRLn_CHN)

/*! @brief Set the CHN field to a new value. */
#define BW_PIT_TCTRLn_CHN(x, n, v) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(x, n), BP_PIT_TCTRLn_CHN) = (v))
/*@}*/
/*******************************************************************************
 * HW_PIT_TFLGn - Timer Flag Register
 ******************************************************************************/

/*!
 * @brief HW_PIT_TFLGn - Timer Flag Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * These registers hold the PIT interrupt flags.
 */
typedef union _hw_pit_tflgn
{
    uint32_t U;
    struct _hw_pit_tflgn_bitfields
    {
        uint32_t TIF : 1;              /*!< [0] Timer Interrupt Flag */
        uint32_t RESERVED0 : 31;       /*!< [31:1]  */
    } B;
} hw_pit_tflgn_t;

/*!
 * @name Constants and macros for entire PIT_TFLGn register
 */
/*@{*/
#define HW_PIT_TFLGn_COUNT (4U)

#define HW_PIT_TFLGn_ADDR(x, n)  ((x) + 0x10CU + (0x10U * (n)))

#define HW_PIT_TFLGn(x, n)       (*(__IO hw_pit_tflgn_t *) HW_PIT_TFLGn_ADDR(x, n))
#define HW_PIT_TFLGn_RD(x, n)    (HW_PIT_TFLGn(x, n).U)
#define HW_PIT_TFLGn_WR(x, n, v) (HW_PIT_TFLGn(x, n).U = (v))
#define HW_PIT_TFLGn_SET(x, n, v) (HW_PIT_TFLGn_WR(x, n, HW_PIT_TFLGn_RD(x, n) |  (v)))
#define HW_PIT_TFLGn_CLR(x, n, v) (HW_PIT_TFLGn_WR(x, n, HW_PIT_TFLGn_RD(x, n) & ~(v)))
#define HW_PIT_TFLGn_TOG(x, n, v) (HW_PIT_TFLGn_WR(x, n, HW_PIT_TFLGn_RD(x, n) ^  (v)))
/*@}*/

/*
 * Constants & macros for individual PIT_TFLGn bitfields
 */

/*!
 * @name Register PIT_TFLGn, field TIF[0] (W1C)
 *
 * Sets to 1 at the end of the timer period. Writing 1 to this flag clears it.
 * Writing 0 has no effect. If enabled, or, when TCTRLn[TIE] = 1, TIF causes an
 * interrupt request.
 *
 * Values:
 * - 0 - Timeout has not yet occurred.
 * - 1 - Timeout has occurred.
 */
/*@{*/
#define BP_PIT_TFLGn_TIF     (0U)          /*!< Bit position for PIT_TFLGn_TIF. */
#define BM_PIT_TFLGn_TIF     (0x00000001U) /*!< Bit mask for PIT_TFLGn_TIF. */
#define BS_PIT_TFLGn_TIF     (1U)          /*!< Bit field size in bits for PIT_TFLGn_TIF. */

/*! @brief Read current value of the PIT_TFLGn_TIF field. */
#define BR_PIT_TFLGn_TIF(x, n) (BITBAND_ACCESS32(HW_PIT_TFLGn_ADDR(x, n), BP_PIT_TFLGn_TIF))

/*! @brief Format value for bitfield PIT_TFLGn_TIF. */
#define BF_PIT_TFLGn_TIF(v)  ((uint32_t)((uint32_t)(v) << BP_PIT_TFLGn_TIF) & BM_PIT_TFLGn_TIF)

/*! @brief Set the TIF field to a new value. */
#define BW_PIT_TFLGn_TIF(x, n, v) (BITBAND_ACCESS32(HW_PIT_TFLGn_ADDR(x, n), BP_PIT_TFLGn_TIF) = (v))
/*@}*/

/*******************************************************************************
 * hw_pit_t - module struct
 ******************************************************************************/
/*!
 * @brief All PIT module registers.
 */
#pragma pack(1)
typedef struct _hw_pit
{
    __IO hw_pit_mcr_t MCR;                 /*!< [0x0] PIT Module Control Register */
    uint8_t _reserved0[252];
    struct {
        __IO hw_pit_ldvaln_t LDVALn;       /*!< [0x100] Timer Load Value Register */
        __I hw_pit_cvaln_t CVALn;          /*!< [0x104] Current Timer Value Register */
        __IO hw_pit_tctrln_t TCTRLn;       /*!< [0x108] Timer Control Register */
        __IO hw_pit_tflgn_t TFLGn;         /*!< [0x10C] Timer Flag Register */
    } CHANNEL[4];
} hw_pit_t;
#pragma pack()

/*! @brief Macro to access all PIT registers. */
/*! @param x PIT module instance base address. */
/*! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
 *     use the '&' operator, like <code>&HW_PIT(PIT_BASE)</code>. */
#define HW_PIT(x)      (*(hw_pit_t *)(x))

#endif /* __HW_PIT_REGISTERS_H__ */
/* EOF */
