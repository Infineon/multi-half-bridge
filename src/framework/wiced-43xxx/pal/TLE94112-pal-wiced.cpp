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

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "TLE94112-pal-wiced.hpp"


//SPI address commands
#define TLE94112_CMD_WRITE          0x80;
#define TLE94112_CMD_CLEAR          0x80;

#define TLE94112_STATUS_INV_MASK    (Tle94112::TLE_POWER_ON_RESET)
#define TLE94112_CS_RISETIME        2

/**
 * @addtogroup tl94112wicedhw
 */
TLE94112Wiced::TLE94112Wiced(void):Tle94112()
{
	Tle94112::en = new GPIOWiced(TLE94112_PIN_EN, OUTPUT, GPIOWiced::POSITIVE );
	Tle94112::timer = new TimerWiced();
	Tle94112::sBus = new SPICWiced();
}

// TLE94112Wiced::TLE94112Wiced(void* bus, uint8_t csPin):Tle94112()
// {
// }


void TLE94112Wiced::begin(void)
{
	begin(TLE94112_PIN_CS1);
}

void TLE94112Wiced::begin(uint8_t csPin)
{
	mEnabled = false;

	Tle94112::sBus->init();
	Tle94112::en->init();
	Tle94112::en->enable();
	Tle94112::timer->init();
	mEnabled = true;
	init();
}

void TLE94112Wiced::end(void)
{
	mEnabled = false;
	Tle94112::en->disable();
	Tle94112::timer->stop();
	Tle94112::sBus->deinit();
}

void TLE94112Wiced::writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data)
{
	uint8_t address = mCtrlRegAddresses[reg];
	uint8_t toWrite = mCtrlRegData[reg] & (~mask);
	uint8_t byte0;
	uint8_t byte1;

	toWrite |= (data << shift) & mask;
	mCtrlRegData[reg] = toWrite;

	address = address | TLE94112_CMD_WRITE
	//cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(toWrite,byte1);
	//cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);
}

uint8_t TLE94112Wiced::readStatusReg(uint8_t reg)
{
	//read the whole register
	return readStatusReg(reg, 0xFF, 0);
}

uint8_t TLE94112Wiced::readStatusReg(uint8_t reg, uint8_t mask, uint8_t shift)
{
	uint8_t address = mStatusRegAddresses[reg];
	uint8_t byte0;
	uint8_t received;

	//cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(0xFF,received);
	//cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);

	received = (received & mask) >> shift;

	return received;
}

void TLE94112Wiced::clearStatusReg(uint8_t reg)
{
	uint8_t address = mStatusRegAddresses[reg];
	uint8_t byte0;
	uint8_t byte1;

	address = address | TLE94112_CMD_CLEAR;
	//cs->disable();
	sBus->transfer(address,byte0);
	sBus->transfer(0,byte1);
	//cs->enable();
	timer->delayMilli(TLE94112_CS_RISETIME);
}

#endif /** TLE94112_FRAMEWORK **/