/*!
 * \file        Tle94112-pal-wiced.h
 * \name        Tle94112-pal-wiced.h - Cypress Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \ref         pal_wiced_43xxx
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "TLE94112-pal-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

//SPI address commands
#define TLE94112_CMD_WRITE          0x80;
#define TLE94112_CMD_CLEAR          0x80;

#define TLE94112_STATUS_INV_MASK    (Tle94112::TLE_POWER_ON_RESET)
#define TLE94112_CS_RISETIME        2

/**
 * @addtogroup tl94112wicedhw
 */

void Tle94112::writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data)
{
	uint8_t address = mCtrlRegAddresses[reg];
	uint8_t toWrite = mCtrlRegData[reg] & (~mask);
	uint8_t byte0;
	uint8_t byte1;

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

	address = address | TLE94112_CMD_CLEAR;
	cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(0,byte1);
	cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);
}

#endif /** TLE94112_FRAMEWORK **/
