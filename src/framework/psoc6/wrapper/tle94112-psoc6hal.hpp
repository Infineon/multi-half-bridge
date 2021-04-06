/**
 * @file        tle94112-psoc6hal.hpp
 * @brief       tle94112-psoc6hal.hpp Cypress PSOC6 Hardware wrapper
 * @date        Mai 2020
 * @version     2.0.1
 * @copyright   Copyright (c) 2021 Infineon Technologies AG
 * @ref         tle94112psoc6hal
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PSOC6HAL_HPP_
#define TLE94112_PSOC6HAL_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "../../../corelib/tle94112.hpp"
#include "tle94112-platf-psoc6hal.hpp"
#include "spic-psoc6hal.hpp"
#include "gpio-psoc6hal.hpp"
#include "timer-psoc6hal.hpp"

/**
 * @addtogroup psoc6Pal
 * @{
 */
class Tle94112Psoc6hal: virtual public Tle94112
{
	public:

		Tle94112Psoc6hal(void);
		Tle94112Psoc6hal(cyhal_gpio_t csPin);
		Tle94112Psoc6hal(cyhal_gpio_t csPin,cyhal_gpio_t misoPin,cyhal_gpio_t mosiPin,cyhal_gpio_t sckPin);

};

/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PCOS6HAL_HPP_ **/
