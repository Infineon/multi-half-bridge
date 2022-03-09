/**
 * @file        spic-mtb.hpp
 * @brief       TLE94112 SPI ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef SPIC_MTB_HPP_
#define SPIC_MTB_HPP_

#include "cyhal.h"
#include "spic.hpp"

using namespace tle94112;

/**
 * @addtogroup mtbPal
 * @{
 */

/**
 * @brief ModusToolbox SPIC class
 *
 */
#define SPI_FREQ_HZ         (1000000UL)
class SPICMtb: virtual public SPIC
{
	private:
		cyhal_gpio_t	csPin;
		cyhal_gpio_t	misoPin;
		cyhal_gpio_t 	mosiPin;
		cyhal_gpio_t 	sckPin;
		cyhal_spi_t  	spi;

		uint8_t 		sendBuffer[2];
		uint8_t 		receiveBuffer[2];

	public:
	
					SPICMtb 	(cyhal_gpio_t csPin, cyhal_gpio_t misoPin, cyhal_gpio_t mosiPin, cyhal_gpio_t sckPin);
					~SPICMtb	();
		Error_t     init		();
		Error_t     deinit		();
		Error_t     transfer	(uint8_t send, uint8_t &received);
		Error_t     transfer16	(uint16_t send, uint16_t &received);

		static const cyhal_gpio_t   unusedPin = CYHAL_NC_PIN_VALUE;      /**< Unused pin */

};

/** @} */

#endif /** SPIC_MTB_HPP_ **/