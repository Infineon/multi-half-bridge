/*!
 * \file        Tle94112-pal-ino.cpp
 * \name        Tle94112-pal-ino.cpp - Arduino library to control Infineon's DC Motor Control Shield with Tle94112
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This file has to be included in projects that use Infineon's DC Motor Control Shield with TLE94112
 * \ref         pal_arduino
 *
 * SPDX-License-Identifier: MIT
 *
 */


#include "TLE94112-pal-ino.hpp"

//SPI address commands
#define TLE94112_CMD_WRITE          0x80;
#define TLE94112_CMD_CLEAR          0x80;

#define TLE94112_STATUS_INV_MASK    (Tle94112::TLE_POWER_ON_RESET)
#define TLE94112_CS_RISETIME        2

void Tle94112::begin(void)
{
	begin(&SPI, TLE94112_PIN_CS1, TLE94112_PIN_EN);
}

void Tle94112::begin(void* bus, uint8_t cs, uint8_t en)
{
	SPIClass *mBus = reinterpret_cast<SPIClass*>(bus);

	mEnabled = FALSE;
	mCsPin = cs;
	mEnPin = en;

	mEnabled = TRUE;
	mBus->begin();
	mBus->setBitOrder(LSBFIRST);
	mBus->setClockDivider(SPI_CLOCK_DIV16);
	mBus->setDataMode(SPI_MODE1);
	pinMode(mEnPin, OUTPUT);
	pinMode(mCsPin, OUTPUT);
	digitalWrite(mCsPin, HIGH);
	digitalWrite(mEnPin, HIGH);
	init();
}

void Tle94112::end(void)
{
	mEnabled = FALSE;
	digitalWrite(mCsPin, HIGH);
	digitalWrite(mEnPin, LOW);
}

void Tle94112::writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data)
{
	SPIClass *mBus = reinterpret_cast<SPIClass*>(mBus);

	uint8_t address = mCtrlRegAddresses[reg];
	uint8_t toWrite = mCtrlRegData[reg] & (~mask);
	toWrite |= (data << shift) & mask;
	mCtrlRegData[reg] = toWrite;
	
	address = address | TLE94112_CMD_WRITE
	digitalWrite(mCsPin, LOW);
	uint8_t byte0 = mBus->transfer(address);
	uint8_t byte1 = mBus->transfer(toWrite);
	digitalWrite(mCsPin, HIGH);
	delay(TLE94112_CS_RISETIME);
}

uint8_t Tle94112::readStatusReg(uint8_t reg)
{
	//read the whole register
	return readStatusReg(reg, 0xFF, 0);
}

uint8_t Tle94112::readStatusReg(uint8_t reg, uint8_t mask, uint8_t shift)
{
	uint8_t address = mStatusRegAddresses[reg];

	digitalWrite(mCsPin, LOW);
	uint8_t byte0 = SPI.transfer(address);
	uint8_t received = SPI.transfer(0xFF); //send dummy byte while receiving
	digitalWrite(mCsPin, HIGH); 
	delay(TLE94112_CS_RISETIME);

	received = (received & mask) >> shift;
	
	return received;
}

void Tle94112::clearStatusReg(uint8_t reg)
{
	SPIClass *mBus = reinterpret_cast<SPIClass*>(mBus);

	uint8_t address = mStatusRegAddresses[reg];

	address = address | TLE94112_CMD_CLEAR;
	digitalWrite(mCsPin, LOW);
	uint8_t byte0 = mBus->transfer(address);
	uint8_t byte1 = mBus->transfer(0); //clear register by writing 0x00
	digitalWrite(mCsPin, HIGH);
	delay(TLE94112_CS_RISETIME);
}

