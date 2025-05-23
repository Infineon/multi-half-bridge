/** 
 * @file        tle94112.cpp
 * @brief       TLE94112 Core API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 * @details 	This library includes the basic common functions to controll the TLE94112 registers
 * 
 * SPDX-License-Identifier: MIT
 */


#include "tle94112.hpp"
#include "tle94112-logger.hpp"

using namespace tle94112;

/*! \brief SPI address commands */
#define TLE94112_CMD_WRITE          0x80;
#define TLE94112_CMD_CLEAR          0x80;

#define TLE94112_STATUS_INV_MASK    (Tle94112::TLE_POWER_ON_RESET)

/*! \brief time in milliseconds to wait for chipselect signal raised */
#define TLE94112_CS_RISETIME        2

/*! \brief micro rise time to wait for chipselect signal raised */
#define TLE94112_CS_MICRO_RISETIME  250


Tle94112::Tle94112(void)
{
	sBus = NULL;
	en = NULL;
	cs = NULL;
	timer = NULL;
}

Tle94112::Tle94112(SPIC * sBus, GPIOC * cs, GPIOC * en, Timer * timer)
:sBus(sBus), cs(cs), en(en), timer(timer)
{
	
}

Tle94112::~Tle94112()
{
	en = NULL;
	cs = NULL;
	timer = NULL;
	sBus = NULL;
}

void Tle94112::begin(void)
{	
	mEnabled = false;

    TLE94112_LOG_INIT();
    TLE94112_LOG_MSG(__FUNCTION__);

	if (nullptr != sBus)
	{	
		Tle94112::sBus->init();	
	}

	if (nullptr != en)
	{ 
		Tle94112::en->init();
		Tle94112::en->enable();
	}

	if (nullptr != cs)
	{
		Tle94112::cs->init();
		Tle94112::cs->enable();
	}

	if (nullptr != timer)
	{
		Tle94112::timer->init();
	}

	mEnabled = true;
	init();
}

void Tle94112::end(void)
{
	mEnabled = false;

    TLE94112_LOG_MSG(__FUNCTION__);

	if (nullptr != en)
	{
		Tle94112::en->disable();
	}

	if (nullptr != cs)
	{
		Tle94112::cs->disable();
	}

	if (nullptr != timer)
	{
		Tle94112::timer->stop();
	}
	
	if(nullptr != sBus)
	{
		Tle94112::sBus->deinit();
	}

    TLE94112_LOG_DEINIT();	
}

void Tle94112::configHB(HalfBridge hb, HBState state, PWMChannel pwm)
{
	configHB(hb, state, pwm, 0);
}

void Tle94112::configHB(HalfBridge hb, HBState state, PWMChannel pwm, uint8_t activeFW)
{
	_configHB(static_cast<uint8_t>(hb),static_cast<uint8_t>(state),static_cast<uint8_t>(pwm),activeFW );
}

void Tle94112::_configHB(uint8_t hb, uint8_t state, uint8_t pwm, uint8_t activeFW)
{

    TLE94112_LOG_MSG(__FUNCTION__);

	writeReg(mHalfBridges[hb].stateReg, mHalfBridges[hb].stateMask, mHalfBridges[hb].stateShift, state);
	writeReg(mHalfBridges[hb].pwmReg,   mHalfBridges[hb].pwmMask,   mHalfBridges[hb].pwmShift,   pwm);
	writeReg(mHalfBridges[hb].fwReg,    mHalfBridges[hb].fwMask,    mHalfBridges[hb].fwShift,    activeFW);
}

void Tle94112::configPWM(PWMChannel pwm, PWMFreq freq, uint8_t dutyCycle)
{
	_configPWM(static_cast<uint8_t>(pwm),static_cast<uint8_t>(freq),dutyCycle );
}

void Tle94112::_configPWM(uint8_t pwm, uint8_t freq, uint8_t dutyCycle)
{

    TLE94112_LOG_MSG(__FUNCTION__);

	writeReg(mPwmChannels[pwm].freqReg, mPwmChannels[pwm].freqMask, mPwmChannels[pwm].freqShift, freq);
	writeReg(mPwmChannels[pwm].dcReg,   mPwmChannels[pwm].dcMask,   mPwmChannels[pwm].dcShift,   dutyCycle);
}

uint8_t Tle94112::setLedMode(HalfBridge hb, uint8_t active)
{	
	// Check if half bridge is either 1 or 2, the others do not
	// support LED mode.
	if (hb == Tle94112::TLE_HB1) {
		// Set LED mode on HB1: Set bit D0 of FW_OL_CTRL register (cp. TLE94112ES datasheet p. 51).
		writeReg(FW_OL_CTRL, 0x01, 0, active);
	} else if (hb == Tle94112::TLE_HB2) {
		// Set LED mode on HB2: Set bit D1 of FW_OL_CTRL register (cp. TLE94112ES datasheet p. 51).
		writeReg(FW_OL_CTRL, 0x02, 1, active);
	} else return 1;

	return 0;
}

uint8_t Tle94112::getSysDiagnosis()
{
	TLE94112_LOG_MSG(__FUNCTION__);

	uint8_t ret = readStatusReg(SYS_DIAG1);
	return ret^TLE94112_STATUS_INV_MASK;
}

uint8_t Tle94112::getSysDiagnosis(DiagFlag mask)
{
	return getSysDiagnosis(static_cast<uint8_t>(mask));
}

uint8_t Tle94112::getSysDiagnosis(uint8_t mask)
{
    TLE94112_LOG_MSG(__FUNCTION__);

	uint8_t ret = readStatusReg(SYS_DIAG1, mask, 0);
	return ret^(TLE94112_STATUS_INV_MASK&mask);
}

uint8_t Tle94112::getHBOverCurrent(HalfBridge hb)
{
	return _getHBOverCurrent(static_cast<uint8_t>(hb));
}

uint8_t Tle94112::_getHBOverCurrent(uint8_t hb)
{
    TLE94112_LOG_MSG(__FUNCTION__);

	return readStatusReg(mHalfBridges[hb].ocReg, mHalfBridges[hb].ocMask, mHalfBridges[hb].ocShift);
}

uint8_t Tle94112::getHBOpenLoad(HalfBridge hb)
{
	return _getHBOpenLoad(static_cast<uint8_t>(hb));
}

uint8_t Tle94112::_getHBOpenLoad(uint8_t hb)
{
	TLE94112_LOG_MSG(__FUNCTION__);

	return readStatusReg(mHalfBridges[hb].olReg, mHalfBridges[hb].olMask, mHalfBridges[hb].olShift);
}

void Tle94112::clearErrors()
{
    TLE94112_LOG_MSG(__FUNCTION__);

	clearStatusReg(SYS_DIAG1);
	clearStatusReg(OP_ERROR_1_STAT);
	clearStatusReg(OP_ERROR_2_STAT);
	clearStatusReg(OP_ERROR_3_STAT);
	clearStatusReg(OP_ERROR_4_STAT);
	clearStatusReg(OP_ERROR_5_STAT);
	clearStatusReg(OP_ERROR_6_STAT);
}

void Tle94112::init(void)
{
    TLE94112_LOG_MSG(__FUNCTION__);

	//!< initial control register configuration
	mCtrlRegAddresses[HB_ACT_1_CTRL]    = REG_ACT_1;
	mCtrlRegAddresses[HB_ACT_2_CTRL]    = REG_ACT_2;
	mCtrlRegAddresses[HB_ACT_3_CTRL]    = REG_ACT_3;
	mCtrlRegAddresses[HB_MODE_1_CTRL]   = REG_MODE_1;
	mCtrlRegAddresses[HB_MODE_2_CTRL]   = REG_MODE_2;
	mCtrlRegAddresses[HB_MODE_3_CTRL]   = REG_MODE_3;
	mCtrlRegAddresses[PWM_CH_FREQ_CTRL] = REG_PWM_CH_FREQ;
	mCtrlRegAddresses[PWM1_DC_CTRL]     = REG_PWM_DC_1;
	mCtrlRegAddresses[PWM2_DC_CTRL]     = REG_PWM_DC_2;
	mCtrlRegAddresses[PWM3_DC_CTRL]     = REG_PWM_DC_3;
	mCtrlRegAddresses[FW_OL_CTRL]       = REG_FW_OL;
	mCtrlRegAddresses[FW_CTRL]          = REG_FW_CTRL;
	mCtrlRegData[HB_ACT_1_CTRL]         = 0;
	mCtrlRegData[HB_ACT_2_CTRL]         = 0;
	mCtrlRegData[HB_ACT_3_CTRL]         = 0;
	mCtrlRegData[HB_MODE_1_CTRL]        = 0;
	mCtrlRegData[HB_MODE_2_CTRL]        = 0;
	mCtrlRegData[HB_MODE_3_CTRL]        = 0;
	mCtrlRegData[PWM_CH_FREQ_CTRL]      = 0;
	mCtrlRegData[PWM1_DC_CTRL]          = 0;
	mCtrlRegData[PWM2_DC_CTRL]          = 0;
	mCtrlRegData[PWM3_DC_CTRL]          = 0;
	mCtrlRegData[FW_OL_CTRL]            = 0;
	mCtrlRegData[FW_CTRL]               = 0;

	//!< status register configuration
	mStatusRegAddresses[SYS_DIAG1]       = REG_SYS_DIAG;
	mStatusRegAddresses[OP_ERROR_1_STAT] = REG_ERR1;
	mStatusRegAddresses[OP_ERROR_2_STAT] = REG_ERR2;
	mStatusRegAddresses[OP_ERROR_3_STAT] = REG_ERR3;
	mStatusRegAddresses[OP_ERROR_4_STAT] = REG_ERR4;
	mStatusRegAddresses[OP_ERROR_5_STAT] = REG_ERR5;
	mStatusRegAddresses[OP_ERROR_6_STAT] = REG_ERR6;

	//!< bit masking for all halfbridges
	mHalfBridges[TLE_NOHB] = { HB_ACT_1_CTRL, 0x00, 0, HB_MODE_1_CTRL, 0x00, 0, FW_OL_CTRL, 0x00, 0, OP_ERROR_1_STAT, 0x00, 0, OP_ERROR_4_STAT, 0x00, 0 };
	mHalfBridges[TLE_HB1]  = { HB_ACT_1_CTRL, 0x03, 0, HB_MODE_1_CTRL, 0x03, 0, FW_OL_CTRL, 0x04, 2, OP_ERROR_1_STAT, 0x03, 0, OP_ERROR_4_STAT, 0x03, 0 };
	mHalfBridges[TLE_HB2]  = { HB_ACT_1_CTRL, 0x0C, 2, HB_MODE_1_CTRL, 0x0C, 2, FW_OL_CTRL, 0x08, 3, OP_ERROR_1_STAT, 0x0C, 2, OP_ERROR_4_STAT, 0x0C, 2 };
	mHalfBridges[TLE_HB3]  = { HB_ACT_1_CTRL, 0x30, 4, HB_MODE_1_CTRL, 0x30, 4, FW_OL_CTRL, 0x10, 4, OP_ERROR_1_STAT, 0x30, 4, OP_ERROR_4_STAT, 0x30, 4 };
	mHalfBridges[TLE_HB4]  = { HB_ACT_1_CTRL, 0xC0, 6, HB_MODE_1_CTRL, 0xC0, 6, FW_OL_CTRL, 0x20, 5, OP_ERROR_1_STAT, 0xC0, 6, OP_ERROR_4_STAT, 0xC0, 6 };
	mHalfBridges[TLE_HB5]  = { HB_ACT_2_CTRL, 0x03, 0, HB_MODE_2_CTRL, 0x03, 0, FW_OL_CTRL, 0x40, 6, OP_ERROR_2_STAT, 0x03, 0, OP_ERROR_5_STAT, 0x03, 0 };
	mHalfBridges[TLE_HB6]  = { HB_ACT_2_CTRL, 0x0C, 2, HB_MODE_2_CTRL, 0x0C, 2, FW_OL_CTRL, 0x80, 7, OP_ERROR_2_STAT, 0x0C, 2, OP_ERROR_5_STAT, 0x0C, 2 };
	mHalfBridges[TLE_HB7]  = { HB_ACT_2_CTRL, 0x30, 4, HB_MODE_2_CTRL, 0x30, 4, FW_CTRL,    0x01, 0, OP_ERROR_2_STAT, 0x30, 4, OP_ERROR_5_STAT, 0x30, 4 };
	mHalfBridges[TLE_HB8]  = { HB_ACT_2_CTRL, 0xC0, 6, HB_MODE_2_CTRL, 0xC0, 6, FW_CTRL,    0x02, 1, OP_ERROR_2_STAT, 0xC0, 6, OP_ERROR_5_STAT, 0xC0, 6 };
	mHalfBridges[TLE_HB9]  = { HB_ACT_3_CTRL, 0x03, 0, HB_MODE_3_CTRL, 0x03, 0, FW_CTRL,    0x04, 2, OP_ERROR_3_STAT, 0x03, 0, OP_ERROR_6_STAT, 0x03, 0 };
	mHalfBridges[TLE_HB10] = { HB_ACT_3_CTRL, 0x0C, 2, HB_MODE_3_CTRL, 0x0C, 2, FW_CTRL,    0x08, 3, OP_ERROR_3_STAT, 0x0C, 2, OP_ERROR_6_STAT, 0x0C, 2 };
	mHalfBridges[TLE_HB11] = { HB_ACT_3_CTRL, 0x30, 4, HB_MODE_3_CTRL, 0x30, 4, FW_CTRL,    0x10, 4, OP_ERROR_3_STAT, 0x30, 4, OP_ERROR_6_STAT, 0x30, 4 };
	mHalfBridges[TLE_HB12] = { HB_ACT_3_CTRL, 0xC0, 6, HB_MODE_3_CTRL, 0xC0, 6, FW_CTRL,    0x20, 5, OP_ERROR_3_STAT, 0xC0, 6, OP_ERROR_6_STAT, 0xC0, 6 };

	//!< bit masking for all pwm channels
	mPwmChannels[TLE_NOPWM] = { PWM_CH_FREQ_CTRL, 0x00, 0, 0, 0x00, 0}; //dummy channel for NOPWM
	mPwmChannels[TLE_PWM1]  = { PWM_CH_FREQ_CTRL, 0x03, 0, PWM1_DC_CTRL, 0xFF, 0};
	mPwmChannels[TLE_PWM2]  = { PWM_CH_FREQ_CTRL, 0x0C, 2, PWM2_DC_CTRL, 0xFF, 0};
	mPwmChannels[TLE_PWM3]  = { PWM_CH_FREQ_CTRL, 0x30, 4, PWM3_DC_CTRL, 0xFF, 0};

}


void Tle94112::directWriteReg(uint8_t reg, uint8_t data)
{
	TLE94112_LOG_MSG(__FUNCTION__);
	
	uint8_t address = reg | TLE94112_CMD_WRITE;
	uint8_t byte0;
	uint8_t byte1;

	cs->disable();
	sBus->transfer(address, byte0);
	sBus->transfer(data, byte1);
	cs->enable();
	timer->delayMicro(TLE94112_CS_MICRO_RISETIME);
}

void Tle94112::writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data)
{
	uint8_t address = mCtrlRegAddresses[reg];
	uint8_t toWrite = mCtrlRegData[reg] & (~mask);
	uint8_t byte0;
	uint8_t byte1;

    TLE94112_LOG_MSG(__FUNCTION__);

	toWrite |= (data << shift) & mask;
	mCtrlRegData[reg] = toWrite;

	address = address | TLE94112_CMD_WRITE
	cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(toWrite,byte1);
	cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);
}

uint8_t Tle94112::readStatusReg(uint8_t reg)
{
	//read the whole register
	return readStatusReg(reg, 0xFF, 0);
}

uint8_t Tle94112::readStatusReg(uint8_t reg, uint8_t mask, uint8_t shift)
{
	uint8_t address = mStatusRegAddresses[reg];
	uint8_t byte0;
	uint8_t received;

    TLE94112_LOG_MSG(__FUNCTION__);

	cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(0xFF,received);
	cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);

	received = (received & mask) >> shift;

	return received;
}

void Tle94112::clearStatusReg(uint8_t reg)
{
	uint8_t address = mStatusRegAddresses[reg];
	uint8_t byte0;
	uint8_t byte1;

    TLE94112_LOG_MSG(__FUNCTION__);

	address = address | TLE94112_CMD_CLEAR;
	cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(0,byte1);
	cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);
}
