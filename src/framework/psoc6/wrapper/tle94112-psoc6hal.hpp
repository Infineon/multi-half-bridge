/**
 * @file        tle94112-psoc6hal.hpp
 * @brief       TLE94112 PSoC6 HAL API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
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
 * @addtogroup psoc6Api
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
