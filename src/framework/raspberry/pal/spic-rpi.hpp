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
#include <bcm2835.h>
#include <cstdio>


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
