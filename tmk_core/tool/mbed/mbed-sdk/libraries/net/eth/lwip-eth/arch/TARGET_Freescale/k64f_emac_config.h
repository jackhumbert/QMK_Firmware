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
#ifndef K64F_EMAC_CONFIG_H__
#define K64F_EMAC_CONFIG_H__
 
#define ENET_RX_RING_LEN              (16)
#define ENET_TX_RING_LEN              (8)
#define ENET_RX_LARGE_BUFFER_NUM      (0)
#define ENET_RX_BUFFER_ALIGNMENT      (16)  
#define ENET_TX_BUFFER_ALIGNMENT      (16)
#define ENET_BD_ALIGNMENT             (16)
#define ENET_MII_CLOCK                (2500000L)
#define RX_BUF_ALIGNMENT              (16)
#define TX_BUF_ALIGNMENT              (8)
#define BOARD_DEBUG_ENET_INSTANCE     (0)
#define BOARD_DEBUG_ENET_INSTANCE_ADDR (ENET_BASE)

#define ENET_ETH_MAX_FLEN             (1522) // recommended size for a VLAN frame

#if defined(__cplusplus)
extern "C" {
#endif

int phy_link_status(void);

#if defined(__cplusplus)
}
#endif

#endif // #define K64F_EMAC_CONFIG_H__

