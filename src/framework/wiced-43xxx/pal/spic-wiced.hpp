/**
 * @file        spic-wiced.hpp
 * @brief       WICED PAL for the SPI cover
 * @date        June 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_WICED_HPP_
#define SPIC_WICED_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "../../../pal/spic.hpp"
#include <platform.h>
#include <wiced_platform.h>

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
	wiced_gpio_t         pin;
	wiced_spi_t          port;
	wiced_spi_device_t   *spi;

	uint8_t sendBuffer[2];
	uint8_t receiveBuffer[2];

	/**
	 * @brief Definition of the SPI-Segment which contains the data for the communication
	 */
	wiced_spi_message_segment_t segment = {
		.tx_buffer = sendBuffer,
		.rx_buffer = receiveBuffer,
		.length = 2,
	};

public:
				SPICWiced();
				SPICWiced(wiced_spi_t port, wiced_gpio_t pin);
				SPICWiced(wiced_spi_device_t *SPI);
				~SPICWiced();
	Error_t     init();
	Error_t     deinit();
	Error_t     transfer(uint8_t send, uint8_t &received);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** SPIC_WICED_HPP_ **/
