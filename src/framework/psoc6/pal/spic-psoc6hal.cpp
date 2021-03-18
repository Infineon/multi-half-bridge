/**
 * @file        spic-psoc6hal.hpp
 * @brief       Psoc6hal PAL for the SPI cover
 * @date        Spt 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "spic-psoc6hal.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

/**
 * @brief Constructor of the PSOC6 SPIC class
 *
 * This function is setting the basics for a SPIC and the default
 * spi on Arduino which is implemented as PSOC6_SPI_0 by patching the following:
 *
 */
SPICPsoc6hal::SPICPsoc6hal() : csPin(SPICPsoc6hal::unusedPin)
{
	this->csPin   = csPin;
	this->misoPin = misoPin;
	this->mosiPin = mosiPin;
	this->sckPin  = sckPin;
}

/**
 * @brief Construct a new SPICPsoc6hal::SPICPsoc6hal object
 *
 * This function is setting the basics for a SPIC. It allows to set the
 * SPI channel and the used GPIOs if they are different from the standard GPIOs.
 *
  * @param csPin    Number of the desired ChipSelect pin
 * 
 * @attention Yet not implemented
 */
SPICPsoc6hal::SPICPsoc6hal(cyhal_gpio_t csPin)
{
	this->csPin = csPin;
}

/**
 * @brief Construct a new SPICPsoc6hal::SPICPsoc6hal object
 * 
 * This function allows to set all parameters of the SPI master.
 * 
 * @param port     SPI channel to be used
 * @param csPin    Number of the desired ChipSelect pin
 * @param speed    SPI baud setting
 * @param mode     SPI mode setting
 * @param bits     number of bits in one command
 * 
 * @attention This does not set the platform_spi_peripherals structure yet
 */
SPICPsoc6hal::SPICPsoc6hal(cyhal_gpio_t csPin, cyhal_gpio_t misoPin, cyhal_gpio_t mosiPin, cyhal_gpio_t sckPin)
{
	this->csPin   = csPin;
	this->misoPin = misoPin;
	this->mosiPin = mosiPin;
	this->sckPin  = sckPin;
}

/**
 * @brief Destructor of the PSOC6 SPIC class
 *
 */
SPICPsoc6hal::~SPICPsoc6hal()
{
	deinit();
}
/**
 * @brief Initialize the SPIC
 *
 * This function is initializing the chosen spi channel
 * with the given values for lsb,clock and mode
 *
 * @return      SPICPsoc6hal::Error_t
 */
SPICPsoc6hal::Error_t SPICPsoc6hal::init()
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_spi_init( &this->spi, this->mosiPin, this->misoPin, this->sckPin, this->csPin, NULL, 8, CYHAL_SPI_MODE_00_LSB, false);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	cyErr = cyhal_spi_set_frequency( &this->spi, SPI_FREQ_HZ);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	return err;
}

/**
 * @brief Deinitialize the SPIC
 *
 * This function is deinitializing the chosen spi channel.
 *
 * @return      SPICPsoc6hal::Error_t
 */
SPICPsoc6hal::Error_t SPICPsoc6hal::deinit()
{
	cyhal_spi_free( &this->spi );
	return OK;
}

/**
 * @brief transfers a data package via the spi bus
 *
 * @param send         address and/or command to send
 * @param received     received data from spi bus
 * @return             SPICPsoc6hal::Error_t
 */
SPICPsoc6hal::Error_t SPICPsoc6hal::transfer(uint8_t send, uint8_t &received)
{
	// sendBuffer[0] = send;
	// receiveBuffer[0] = received;
	// mtb_spi_transfer( &this->spi, &this->segment, 1);
	return OK;
}

/**
 * @brief transfers a data package via the spi bus
 *
 * @param send         address and/or command to send as 16bit
 * @param received     received data from spi bus as 16bit
 * @return             SPICPsoc6hal::Error_t
 */
SPICPsoc6hal::Error_t SPICPsoc6hal::transfer16(uint16_t send, uint16_t &received)
{
	// sendBuffer[0] = (uint8_t)((send >> 8) & 0xFF);
	// sendBuffer[1] = (uint8_t)(send & 0xFF);

	// mtb_spi_transfer( &this->spi, &this->segment, 2);
	// received = (uint16_t)(((uint16_t)receiveBuffer[0] << 8) | (receiveBuffer[1]));

	return OK;
}

#endif /** TLE94112_FRAMEWORK **/
