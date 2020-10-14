/**
 * @file        spic-rpi.cpp
 * @brief       Raspberry Pi PAL for the SPI cover
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "spic-rpi.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

/**
 * @brief Constructor of the Raspberry Pi SPIC class
 *
 * This function is setting the basics for a SPIC and the default spi.
 *
 */
SPICRpi::SPICRpi() : lsb(BCM2835_SPI_BIT_ORDER_LSBFIRST), mode(BCM2835_SPI_MODE1), clock(BCM2835_SPI_CLOCK_DIVIDER_16)
{
		//fehlt noch miso, mosi, sck, cs infos 
}

/**
 * @brief Construct a new SPICRpi::SPICRpi object of the Raspberry Pi SPIC class
 * 
 * This function sets some basic SPI modes for the default SPI port.
 * 
 * @param lsb    lowside (LSB) or highside (MSB) mode
 * @param mode   SPI mode
 * @param clock  SPI clock divider
 */
SPICRpi::SPICRpi(uint8_t lsb, uint8_t mode, uint8_t clock) : lsb(BCM2835_SPI_BIT_ORDER_LSBFIRST), mode(BCM2835_SPI_MODE1), clock(BCM2835_SPI_CLOCK_DIVIDER_16)
{	
	this->lsb = lsb;
	this->mode = mode;
	this->clock = clock;
	// fehlt noch die Übergabe der miso, mosi, sck und cs informationen -> über bcm library? Wie?
	
}

/**
 * @brief Construct a new SPICRpi::SPICRpi object of the Raspberry Pi SPIC class
 *
 * This function sets all pins for a given SPI port, allowing a free setting
 * of the SPI interface
 *
 * @param port     SPI port if not default
 * @param csPin    chipselect pin for the SPI port
 * @param misoPin  miso pin number
 * @param mosiPin  mosi pin number
 * @param sckPin   systemclock pin number
 */
SPICRpi::SPICRpi(uint8_t csPin, uint8_t misoPin, uint8_t mosiPin, uint8_t sckPin) : lsb(BCM2835_SPI_BIT_ORDER_LSBFIRST), mode(BCM2835_SPI_MODE1), clock(BCM2835_SPI_CLOCK_DIVIDER_16)
{
	this->csPin = csPin;
	this->misoPin = misoPin;
	this->mosiPin = mosiPin;
	this->sckPin = sckPin;
	// fehlt noch miso, mosi, sck, cs
}

/**
 * @brief Initialize the SPIC
 *
 * This function is initializing the chosen spi channel
 * with the given values for lsb,clock and mode
 *
 * @return      SPICRpi::Error_t
 */
SPICRpi::Error_t SPICRpi::init()
{
	bcm2835_spi_begin(); 
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_LSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_16);    // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // The default  
	return OK;
}

/**
 * @brief Deinitialize the SPIC
 *
 * This function is deinitializing the chosen spi channel.
 *
 * @return      SPICRpi::Error_t
 */
SPICRpi::Error_t SPICRpi::deinit()
{
	bcm2835_spi_end();
	return OK;
}

/**
 * @brief transfers a data package via the spi bus
 *
 * @param send         address and/or command to send
 * @param received     received data from spi bus
 * @return             SPICRpi::Error_t
 */
SPICRpi::Error_t SPICRpi::transfer(uint8_t send, uint8_t &received)
{
	received = bcm2835_spi_transfer(send);
	return OK;
}

/**
 * @brief transfers a data package via the spi bus with 16 bit length
 *
 * @param send         address and/or command to send
 * @param received     received data from spi bus
 * @return             SPICRpi::Error_t
 */
SPICRpi::Error_t SPICRpi::transfer16(uint16_t send, uint16_t &received)
{
	uint8_t data_out_msb = (uint8_t)((send >> 8) & 0xFF);
	uint8_t data_out_lsb = (uint8_t)(send & 0xFF);

	uint8_t data_in_msb = bcm2835_spi_transfer(data_out_msb);
	uint8_t data_in_lsb = bcm2835_spi_transfer(data_out_lsb);

	received = (uint16_t)(((uint16_t)data_in_msb << 8) | (data_in_lsb));
	return OK;
}

#endif /** TLE94112_FRAMEWORK **/
