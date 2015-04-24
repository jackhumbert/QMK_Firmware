/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2014, STMicroelectronics
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#include "sleep_api.h"

#if DEVICE_SLEEP

#include "cmsis.h"

#if defined(TARGET_STM32F070RB)
void sleep(void)
{
    TIM_HandleTypeDef TimMasterHandle;

    TimMasterHandle.Instance = TIM1;

    // Disable HAL tick and us_ticker update interrupts
    __HAL_TIM_DISABLE_IT(&TimMasterHandle, (TIM_IT_CC2 | TIM_IT_UPDATE));

    // Request to enter SLEEP mode
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);

    // Enable HAL tick and us_ticker update interrupts
    __HAL_TIM_ENABLE_IT(&TimMasterHandle, (TIM_IT_CC2 | TIM_IT_UPDATE));
}

#elif defined(TARGET_STM32F030R8) || defined (TARGET_STM32F051R8)
void sleep(void)
{
    // Stop HAL systick
    HAL_SuspendTick();
    // Request to enter SLEEP mode
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
    // Restart HAL systick
    HAL_ResumeTick();
}

#else
static TIM_HandleTypeDef TimMasterHandle;

void sleep(void)
{
    TimMasterHandle.Instance = TIM2;

    // Disable HAL tick interrupt
    __HAL_TIM_DISABLE_IT(&TimMasterHandle, TIM_IT_CC2);

    // Request to enter SLEEP mode
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);

    // Enable HAL tick interrupt
    __HAL_TIM_ENABLE_IT(&TimMasterHandle, TIM_IT_CC2);
}
#endif

#if defined(TARGET_STM32F030R8) || defined (TARGET_STM32F051R8)
void deepsleep(void)
{
    // Request to enter STOP mode with regulator in low power mode
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);

    HAL_InitTick(TICK_INT_PRIORITY);

    // After wake-up from STOP reconfigure the PLL
    SetSysClock();

    HAL_InitTick(TICK_INT_PRIORITY);
}

#else
void deepsleep(void)
{
    // Request to enter STOP mode with regulator in low power mode
    HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);

    // After wake-up from STOP reconfigure the PLL
    SetSysClock();
}
#endif

#endif
