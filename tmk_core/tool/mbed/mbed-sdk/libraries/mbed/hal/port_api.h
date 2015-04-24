/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_PORTMAP_H
#define MBED_PORTMAP_H

#include "device.h"

#if DEVICE_PORTIN || DEVICE_PORTOUT

#ifdef __cplusplus
extern "C" {
#endif

typedef struct port_s port_t;

PinName port_pin(PortName port, int pin_n);

void port_init (port_t *obj, PortName port, int mask, PinDirection dir);
void port_mode (port_t *obj, PinMode mode);
void port_dir  (port_t *obj, PinDirection dir);
void port_write(port_t *obj, int value);
int  port_read (port_t *obj);

#ifdef __cplusplus
}
#endif
#endif

#endif
