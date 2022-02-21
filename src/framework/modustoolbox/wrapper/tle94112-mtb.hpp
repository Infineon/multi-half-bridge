/**
 * @file        tle94112-mtb.hpp
 * @brief       TLE94112 ModusToolbox HAL API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_MTB_HPP_
#define TLE94112_MTB_HPP_

#include "tle94112.hpp"
#include "tle94112-platf-mtb.hpp"
#include "cyhal_gpio.h"

/**
 * @addtogroup mtbApi
 * @{
 */
class Tle94112Mtb: virtual public Tle94112
{
	public:

		Tle94112Mtb(void);
		Tle94112Mtb(cyhal_gpio_t csPin);
		Tle94112Mtb(cyhal_gpio_t csPin,cyhal_gpio_t misoPin,cyhal_gpio_t mosiPin,cyhal_gpio_t sckPin);

};

/** @} */

#endif /** TLE94112_MTB_HPP_ **/
