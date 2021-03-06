/**
 * @file        spic-wiced.hpp
 * @brief       TLE94112 SPI WICED PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_WICED_HPP_
#define SPIC_WICED_HPP_

#include "spic.hpp"
#include <platform.h>
#include <wiced_platform.h>

using namespace tle94112;

/**
 * @addtogroup wicedPal
 * @{
 */

/**
 * @brief Wiced SPIC class
 *
 */
class SPICWiced: virtual public SPIC
{
	private:
		wiced_gpio_t         csPin;
		wiced_gpio_t         misoPin;
		wiced_gpio_t         mosiPin;
		wiced_gpio_t         sckPin;

		wiced_spi_t          port;
		wiced_spi_device_t   spi;
		uint8_t     lsb;
		uint8_t     mode;
		uint8_t     clock;

		uint8_t sendBuffer[2];
		uint8_t receiveBuffer[2];
		bool spiSetting = false;

		//* @brief Definition of the SPI-Segment which contains the data for the communication
		wiced_spi_message_segment_t segment;

	public:
		SPICWiced();
		SPICWiced(wiced_spi_t port, wiced_gpio_t csPin);
		SPICWiced(wiced_spi_t port, wiced_gpio_t csPin, uint8_t speed, uint8_t mode, uint8_t bits);
		~SPICWiced();
		Error_t     init();
		Error_t     deinit();
		Error_t     transfer(uint8_t send, uint8_t &received);
		Error_t     transfer16(uint16_t send, uint16_t &received);

};
/** @} */

#endif /** SPIC_WICED_HPP_ **/