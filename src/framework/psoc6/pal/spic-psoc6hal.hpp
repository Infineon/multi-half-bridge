/**
 * @file        spic-psoc6hal.hpp
 * @brief       PSOC6 PAL for the SPI cover
 * @date        Spt 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_PSOC6_HPP_
#define SPIC_PSOC6_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "../../../pal/spic.hpp"
#include "cyhal_gpio.h"
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"

/**
 * @addtogroup mtbPal
 * @{
 */

#define SPI_FREQ_HZ         (1000000UL)
class SPICPsoc6hal: virtual public SPIC
{
	private:
		cyhal_gpio_t         csPin;
		cyhal_gpio_t         misoPin;
		cyhal_gpio_t         mosiPin;
		cyhal_gpio_t         sckPin;
		cyhal_spi_t          spi;

		uint8_t sendBuffer[5];
		uint8_t receiveBuffer[5];
		bool spiSetting = false;

	public:
		SPICPsoc6hal();
		SPICPsoc6hal(cyhal_gpio_t csPin, cyhal_gpio_t misoPin, cyhal_gpio_t mosiPin, cyhal_gpio_t sckPin);
		~SPICPsoc6hal();
		Error_t     init();
		Error_t     deinit();
		Error_t     transfer(uint8_t send, uint8_t &received);
		Error_t     transfer16(uint16_t send, uint16_t &received);

		static const cyhal_gpio_t   unusedPin = CYHAL_NC_PIN_VALUE;      /**< Unused pin */

};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** SPIC_PSOC6_HPP_ **/
