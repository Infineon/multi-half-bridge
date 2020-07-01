/*!
 * \file        Tle94112.cpp
 * \name        Tle94112.cpp - Arduino library to control Infineon's DC Motor Control Shield with Tle94112
 * \author      Infineon Technologies AG
 * \copyright   2019-2020 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This file has to be included in projects that use Infineon's DC Motor Control Shield with TLE94112
 * \ref         common
 *
 * SPDX-License-Identifier: MIT
 *
 */


#include "TLE94112.hpp"

#define TLE94112_STATUS_INV_MASK    (Tle94112::TLE_POWER_ON_RESET)

Tle94112::Tle94112(void)
{
	sBus = NULL;
	en = NULL;
	cs = NULL;
	timer = NULL;
}

// Tle94112::Tle94112(void* bus, uint8_t csPin)
// {
// }

Tle94112::~Tle94112()
{
	en = NULL;
	cs = NULL;
	timer = NULL;
	sBus = NULL;
}

void Tle94112::configHB(HalfBridge hb, HBState state, PWMChannel pwm)
{
	configHB(hb, state, pwm, 0);
}

void Tle94112::configHB(HalfBridge hb, HBState state, PWMChannel pwm, uint8_t activeFW)
{
	if(mEnabled == true)
	{
		configHB(static_cast<uint8_t>(hb),
					static_cast<uint8_t>(state),
					static_cast<uint8_t>(pwm),
					activeFW );
	}
}

void Tle94112::configHB(uint8_t hb, uint8_t state, uint8_t pwm, uint8_t activeFW)
{
	uint8_t reg = mHalfBridges[hb].stateReg;
	uint8_t mask = mHalfBridges[hb].stateMask;
	uint8_t shift = mHalfBridges[hb].stateShift;
	writeReg(reg, mask, shift, state);
	
	reg = mHalfBridges[hb].pwmReg;
	mask = mHalfBridges[hb].pwmMask;
	shift = mHalfBridges[hb].pwmShift;
	writeReg(reg, mask, shift, pwm);
	
	reg = mHalfBridges[hb].fwReg;
	mask = mHalfBridges[hb].fwMask;
	shift = mHalfBridges[hb].fwShift;
	writeReg(reg, mask, shift, activeFW);
}

void Tle94112::configPWM(PWMChannel pwm, PWMFreq freq, uint8_t dutyCycle)
{
	if(mEnabled == true)
	{
		configPWM(static_cast<uint8_t>(pwm),
					static_cast<uint8_t>(freq),
					dutyCycle );
	}
}

void Tle94112::configPWM(uint8_t pwm, uint8_t freq, uint8_t dutyCycle)
{
	uint8_t reg = mPwmChannels[pwm].freqReg;
	uint8_t mask = mPwmChannels[pwm].freqMask;
	uint8_t shift = mPwmChannels[pwm].freqShift;
	writeReg(reg, mask, shift, freq);
	
	reg = mPwmChannels[pwm].dcReg;
	mask = mPwmChannels[pwm].dcMask;
	shift = mPwmChannels[pwm].dcShift;
	writeReg(reg, mask, shift, dutyCycle);
}

uint8_t Tle94112::getSysDiagnosis()
{
	uint8_t ret = readStatusReg(SYS_DIAG1);
	return ret^TLE94112_STATUS_INV_MASK;
}

uint8_t Tle94112::getSysDiagnosis(DiagFlag mask)
{
	return getSysDiagnosis(static_cast<uint8_t>(mask));
}

uint8_t Tle94112::getSysDiagnosis(uint8_t mask)
{
	uint8_t ret = readStatusReg(SYS_DIAG1, mask, 0);
	return ret^(TLE94112_STATUS_INV_MASK&mask);
}

uint8_t Tle94112::getHBOverCurrent(HalfBridge hb)
{
	return getHBOverCurrent(static_cast<uint8_t>(hb));
}

uint8_t Tle94112::getHBOverCurrent(uint8_t hb)
{
	uint8_t reg = mHalfBridges[hb].ocReg;
	uint8_t mask = mHalfBridges[hb].ocMask;
	uint8_t shift = mHalfBridges[hb].ocShift;
	return readStatusReg(reg, mask, shift);
}

uint8_t Tle94112::getHBOpenLoad(HalfBridge hb)
{
	return getHBOpenLoad(static_cast<uint8_t>(hb));
}

uint8_t Tle94112::getHBOpenLoad(uint8_t hb)
{
	uint8_t reg = mHalfBridges[hb].olReg;
	uint8_t mask = mHalfBridges[hb].olMask;
	uint8_t shift = mHalfBridges[hb].olShift;
	return readStatusReg(reg, mask, shift);
}

void Tle94112::clearErrors()
{
	clearStatusReg(SYS_DIAG1);
	clearStatusReg(OP_ERROR_1_STAT);
	clearStatusReg(OP_ERROR_2_STAT);
	clearStatusReg(OP_ERROR_3_STAT);
	clearStatusReg(OP_ERROR_4_STAT);
	clearStatusReg(OP_ERROR_5_STAT);
	clearStatusReg(OP_ERROR_6_STAT);
}
