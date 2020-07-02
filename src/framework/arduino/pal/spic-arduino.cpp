/**
 * @file        SPIC-arduino.hpp
 * @brief       Arduino PAL for the SPI cover
 * @date        June 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "spic-arduino.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

/**
 * @brief Constructor of the Arduino SPIC class
 *
 * This function is setting the basics for a SPIC and the default spi.
 *
 */
SPICIno::SPICIno() : lsb(LSBFIRST), mode(SPI_MODE1), clock(SPI_CLOCK_DIV16)
{
	spi = &SPI;
}

// /**
//  * @brief Constructor of the Arduino SPIC class
//  *
//  * This function is setting the basics for a SPIC. It allows to set the pin number,
//  * mode of the pin and the logic level.
//  *
//  * @param[in]   pin     Number of the desired pin
//  * @param[in]   mode    Defines the mode of the pin (INPUT, OUTPUT, etc.)
//  * @param[in]   logic   Defines the logic level of the pin
//  */
// SPICIno::SPICIno(uint8_t pin, uint8_t mode, VLogic_t logic): pin(pin), mode(mode), logic(logic)
// {

// }

/**
 * @brief Initialize the SPIC
 *
 * This function is initializing the chosen spi channel
 * with the given values for lsb,clock and mode
 *
 * @return      SPICIno::Error_t
 */
SPICIno::Error_t SPICIno::init()
{
	spi->begin();
	spi->setBitOrder(this->lsb);
	spi->setClockDivider(this->clock);
	spi->setDataMode(this->mode);
	return OK;
}

/**
 * @brief Deinitialize the SPIC
 *
 * This function is deinitializing the chosen spi channel.
 *
 * @return      SPICIno::Error_t
 */
SPICIno::Error_t SPICIno::deinit()
{
	spi->end();
	return OK;
}

/**
 * @brief transfers a data package via the spi bus
 *
 * @param send         address and/or command to send
 * @param received     received data from spi bus
 * @return             SPICIno::Error_t
 */
SPICIno::Error_t SPICIno::transfer(uint8_t send, uint8_t &received)
{
	received = spi->transfer(send);
	return OK;
}

#endif /** TLE94112_FRAMEWORK **/



