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
#define TLE94112_CMD_WRITE			0x80;
#define TLE94112_CMD_CLEAR			0x80;

#define TLE94112_STATUS_INV_MASK	(Tle94112::TLE_POWER_ON_RESET)
#define TLE94112_CS_RISETIME		2

void TLE94112Wiced::begin(void)
{
	wiced_spi_device_t SPI;
	SPI.port = WICED_SPI_1;
	SPI.chip_select = TLE94112_PIN_CS1;
	SPI.speed = 2000;
	SPI.mode = SPI_LSB_FIRST;
	SPI.bits = 16;

	begin(SPI, TLE94112_PIN_CS1, TLE94112_PIN_EN);

}

void TLE94112Wiced::begin(wiced_spi_device_t &bus, uint8_t cs, uint8_t en)
{
	wiced_result_t error = WICED_SUCCESS;

	mEnabled = FALSE;
	mBus = &bus;
	mCsPin = cs;
	mEnPin = en;

	error = wiced_spi_init(mBus);
	if ( error != WICED_SUCCESS )
	{
	}

	// pinMode(mEnPin, OUTPUT);
	// pinMode(mCsPin, OUTPUT);
	// digitalWrite(mCsPin, HIGH);
	// digitalWrite(mEnPin, HIGH);

	mEnabled = TRUE;
	init();
}

void TLE94112Wiced::end(void)
{
	mEnabled = FALSE;

//	digitalWrite(mCsPin, HIGH);
//	digitalWrite(mEnPin, LOW);

}

void TLE94112Wiced::writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data)
{
	uint8_t address = mCtrlRegAddresses[reg];
	uint8_t toWrite = mCtrlRegData[reg] & (~mask);
	toWrite |= (data << shift) & mask;
	mCtrlRegData[reg] = toWrite;

	address = address | TLE94112_CMD_WRITE;
//	digitalWrite(mCsPin, LOW);
	uint8_t byte0 = mBus->transfer(address);
	uint8_t byte1 = mBus->transfer(toWrite);
//	digitalWrite(mCsPin, HIGH);
//	delay(TLE94112_CS_RISETIME);
}

uint8_t TLE94112Wiced::readStatusReg(uint8_t reg)
{
	//read the whole register
	return readStatusReg(reg, 0xFF, 0);
}

uint8_t TLE94112Wiced::readStatusReg(uint8_t reg, uint8_t mask, uint8_t shift)
{
	uint8_t address = mStatusRegAddresses[reg];

//	digitalWrite(mCsPin, LOW);
	uint8_t byte0 = SPI.transfer(address);
	uint8_t received = SPI.transfer(0xFF);	//send dummy byte while receiving
//	digitalWrite(mCsPin, HIGH); 
//	delay(TLE94112_CS_RISETIME);
	
	received = (received & mask) >> shift;

	return received;
}

void TLE94112Wiced::clearStatusReg(uint8_t reg)
{
	uint8_t address = mStatusRegAddresses[reg];

	address = address | TLE94112_CMD_CLEAR;
//	digitalWrite(mCsPin, LOW);
	uint8_t byte0 = mBus->transfer(address);
	uint8_t byte1 = mBus->transfer(0);	//clear register by writing 0x00
//	digitalWrite(mCsPin, HIGH);
//	delay(TLE94112_CS_RISETIME);
}

#endif /** TLE94112_FRAMEWORK **/