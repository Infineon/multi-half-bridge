/*!
 * \file 		TLE94112_conf.cpp
 * \name        TLE94112_conf.cpp - automatically included library
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


#include "tle94112_conf.h"
#include "TLE94112.h"

void Tle94112::init(void)
{
	//!< initial control register configuration
	mCtrlRegAddresses[static_cast<int>(Tle94112::HB_ACT_1_CTRL)] 	= 0x03;
	mCtrlRegData[HB_ACT_1_CTRL] 		= 0;
	mCtrlRegAddresses[HB_ACT_2_CTRL] 	= 0x43;
	mCtrlRegData[HB_ACT_2_CTRL] 		= 0;
	mCtrlRegAddresses[HB_ACT_3_CTRL] 	= 0x23;
	mCtrlRegData[HB_ACT_3_CTRL] 		= 0;
	mCtrlRegAddresses[HB_MODE_1_CTRL] 	= 0x63;
	mCtrlRegData[HB_MODE_1_CTRL] 		= 0;
	mCtrlRegAddresses[HB_MODE_2_CTRL] 	= 0x13;
	mCtrlRegData[HB_MODE_2_CTRL] 		= 0;
	mCtrlRegAddresses[HB_MODE_3_CTRL] 	= 0x53;
	mCtrlRegData[HB_MODE_3_CTRL] 		= 0;
	mCtrlRegAddresses[PWM_CH_FREQ_CTRL] = 0x33;
	mCtrlRegData[PWM_CH_FREQ_CTRL] 		= 0;
	mCtrlRegAddresses[PWM1_DC_CTRL] 	= 0x73;
	mCtrlRegData[PWM1_DC_CTRL] 			= 0;
	mCtrlRegAddresses[PWM2_DC_CTRL] 	= 0x0B;
	mCtrlRegData[PWM2_DC_CTRL] 			= 0;
	mCtrlRegAddresses[PWM3_DC_CTRL] 	= 0x4B;
	mCtrlRegData[PWM3_DC_CTRL] 			= 0;
	mCtrlRegAddresses[FW_OL_CTRL] 		= 0x2B;
	mCtrlRegData[FW_OL_CTRL] 			= 0;
	mCtrlRegAddresses[FW_CTRL] 			= 0x6B;
	mCtrlRegData[FW_CTRL] 				= 0;
	
	//!< status register configuration
	mStatusRegAddresses[SYS_DIAG1]			= 0x1B;
	mStatusRegAddresses[OP_ERROR_1_STAT]	= 0x5B;
	mStatusRegAddresses[OP_ERROR_2_STAT]	= 0x3B;
	mStatusRegAddresses[OP_ERROR_3_STAT]	= 0x7B;
	mStatusRegAddresses[OP_ERROR_4_STAT]	= 0x07;
	mStatusRegAddresses[OP_ERROR_5_STAT]	= 0x47;
	mStatusRegAddresses[OP_ERROR_6_STAT]	= 0x27;
	
	//!< bit masking for all halfbridges
	mHalfBridges[TLE_NOHB] = { HB_ACT_1_CTRL, 0x00, 0, HB_MODE_1_CTRL, 0x00, 0, FW_OL_CTRL, 0x00, 0, OP_ERROR_1_STAT, 0x00, 0, OP_ERROR_4_STAT, 0x00, 0 };
	mHalfBridges[TLE_HB1] = { HB_ACT_1_CTRL, 0x03, 0, HB_MODE_1_CTRL, 0x03, 0, FW_OL_CTRL, 0x04, 2, OP_ERROR_1_STAT, 0x03, 0, OP_ERROR_4_STAT, 0x03, 0 };
	mHalfBridges[TLE_HB2] = { HB_ACT_1_CTRL, 0x0C, 2, HB_MODE_1_CTRL, 0x0C, 2, FW_OL_CTRL, 0x08, 3, OP_ERROR_1_STAT, 0x0C, 2, OP_ERROR_4_STAT, 0x0C, 2 };
	mHalfBridges[TLE_HB3] = { HB_ACT_1_CTRL, 0x30, 4, HB_MODE_1_CTRL, 0x30, 4, FW_OL_CTRL, 0x10, 4, OP_ERROR_1_STAT, 0x30, 4, OP_ERROR_4_STAT, 0x30, 4 };
	mHalfBridges[TLE_HB4] = { HB_ACT_1_CTRL, 0xC0, 6, HB_MODE_1_CTRL, 0xC0, 6, FW_OL_CTRL, 0x20, 5, OP_ERROR_1_STAT, 0xC0, 6, OP_ERROR_4_STAT, 0xC0, 6 };
	mHalfBridges[TLE_HB5] = { HB_ACT_2_CTRL, 0x03, 0, HB_MODE_2_CTRL, 0x03, 0, FW_OL_CTRL, 0x40, 6, OP_ERROR_2_STAT, 0x03, 0, OP_ERROR_5_STAT, 0x03, 0 };
	mHalfBridges[TLE_HB6] = { HB_ACT_2_CTRL, 0x0C, 2, HB_MODE_2_CTRL, 0x0C, 2, FW_OL_CTRL, 0x80, 7, OP_ERROR_2_STAT, 0x0C, 2, OP_ERROR_5_STAT, 0x0C, 2 };
	mHalfBridges[TLE_HB7] = { HB_ACT_2_CTRL, 0x30, 4, HB_MODE_2_CTRL, 0x30, 4, FW_CTRL, 0x01, 0, OP_ERROR_2_STAT, 0x30, 4, OP_ERROR_5_STAT, 0x30, 4 };
	mHalfBridges[TLE_HB8] = { HB_ACT_2_CTRL, 0xC0, 6, HB_MODE_2_CTRL, 0xC0, 6, FW_CTRL, 0x02, 1, OP_ERROR_2_STAT, 0xC0, 6, OP_ERROR_5_STAT, 0xC0, 6 };
	mHalfBridges[TLE_HB9] = { HB_ACT_3_CTRL, 0x03, 0, HB_MODE_3_CTRL, 0x03, 0, FW_CTRL, 0x04, 2, OP_ERROR_3_STAT, 0x03, 0, OP_ERROR_6_STAT, 0x03, 0 };
	mHalfBridges[TLE_HB10] = { HB_ACT_3_CTRL, 0x0C, 2, HB_MODE_3_CTRL, 0x0C, 2, FW_CTRL, 0x08, 3, OP_ERROR_3_STAT, 0x0C, 2, OP_ERROR_6_STAT, 0x0C, 2 };
	mHalfBridges[TLE_HB11] = { HB_ACT_3_CTRL, 0x30, 4, HB_MODE_3_CTRL, 0x30, 4, FW_CTRL, 0x10, 4, OP_ERROR_3_STAT, 0x30, 4, OP_ERROR_6_STAT, 0x30, 4 };
	mHalfBridges[TLE_HB12] = { HB_ACT_3_CTRL, 0xC0, 6, HB_MODE_3_CTRL, 0xC0, 6, FW_CTRL, 0x20, 5, OP_ERROR_3_STAT, 0xC0, 6, OP_ERROR_6_STAT, 0xC0, 6 };
	
	//!< bit masking for all pwm channels
	mPwmChannels[TLE_NOPWM] = { PWM_CH_FREQ_CTRL, 0x00, 0, 0, 0x00, 0};	//dummy channel for NOPWM
	mPwmChannels[TLE_PWM1] = { PWM_CH_FREQ_CTRL, 0x03, 0, PWM1_DC_CTRL, 0xFF, 0};
	mPwmChannels[TLE_PWM2] = { PWM_CH_FREQ_CTRL, 0x0C, 2, PWM2_DC_CTRL, 0xFF, 0};
	mPwmChannels[TLE_PWM3] = { PWM_CH_FREQ_CTRL, 0x30, 4, PWM3_DC_CTRL, 0xFF, 0};
	
}
