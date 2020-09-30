/**
 * @file        spic-rpi.hpp
 * @brief       Raspberry Pi PAL for the SPI cover
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_RPI_HPP_
#define SPIC_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../pal/spic.hpp"
// #include <Arduino.h>
// #include "SPI.h"
/*	The following #define wrapper around the inclusion of bcm2835.h
*	is necessary to prevent double decleration of the C function
*	bcm2835_delayMicroseconds, because it is also defined in
*	wiringPi.h. This solution by datenwolf is taken from:
*	https://stackoverflow.com/a/6940389/6692732 [1]
*	There might arise additional errors in the link process. The
*	solution to those is not yet implemented, see [1].
*	[1] is licensed under CC BY-SA 3.0.
*/
#define	bcm2835_delayMicroseconds bcm2835_delayMicroseconds_alt
#include <bcm2835.h>
#undef bcm2835_delayMicroseconds
#include <wiringPi.h>
#include <wiringPiSPI.h>

/**
 * @addtogroup rpiPal
 * @{
 */


/**
 * @brief Raspberry Pi SPIC class
 *
 */
class SPICRpi: virtual public SPIC
{
	private:
		uint8_t     csPin;
		uint8_t     misoPin;
		uint8_t     mosiPin;
		uint8_t     sckPin;
		uint8_t     lsb;
		uint8_t     mode;
		uint8_t     clock;
		uint8_t		channel;
		uint32_t	speed; 

	public:
					SPICRpi();
					SPICRpi(uint8_t lsb, uint8_t mode, uint8_t clock);
					SPICRpi(uint8_t csPin, uint8_t misoPin, uint8_t mosiPin, uint8_t sckPin);
					~SPICRpi();
		Error_t     init();
		Error_t     deinit();
		Error_t     transfer(uint8_t send, uint8_t &received);
		Error_t     transfer16(uint16_t send, uint16_t &received);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** SPIC_RPI_HPP_ **/
