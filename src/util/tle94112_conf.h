/*!
 * \file 		TLE94112_conf.h
 * \name        TLE94112_conf.h - automatically included library
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.4.1
 * \brief 		This file can optionally be included in projects that use Infineon's 
 * 				DC Motor Control Shield with TLE94112
 * 				It provides a higher abstraction for controlling motors with the TLE94112 
 * 				acting as an output driver
 * 
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef TLE94112_CONF_H
#define TLE94112_CONF_H

#include "Arduino.h"

//! \brief struct containing register locations for a single halfbridge
typedef struct
{
	uint8_t stateReg;
	uint8_t stateMask;
	uint8_t stateShift;
	uint8_t pwmReg;
	uint8_t pwmMask;
	uint8_t pwmShift;
	uint8_t fwReg;
	uint8_t fwMask;
	uint8_t fwShift;
	uint8_t ocReg;
	uint8_t ocMask;
	uint8_t ocShift;
	uint8_t olReg;
	uint8_t olMask;
	uint8_t olShift;
} HalfBridge_t;

//! \brief struct containing register locations for a single PWM channel
typedef struct 
{
	uint8_t freqReg;
	uint8_t freqMask;
	uint8_t freqShift;
	uint8_t dcReg;
	uint8_t dcMask;
	uint8_t dcShift;
} PWMchannel_t;

#endif