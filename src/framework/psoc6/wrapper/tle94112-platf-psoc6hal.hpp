/**
 * @file        TLE94112-platf-psoc6hal.hpp
 * @brief       TLE94112-platf-psoc6hal.hpp Cypress PSOC6 Hardware Platforms
 * @date        Mai 2020
 * @version     2.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_MTB_HPP_
#define TLE94112_PLATF_MTB_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "../../../corelib/tle94112.hpp"
#include "spic-psoc6hal.hpp"
#include "gpio-psoc6hal.hpp"
#include "timer-psoc6hal.hpp"


/**
 * @addtogroup platfMtb
 * @{
 */

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS1     (P5_6)

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to remove the 0 Ohm resistor R7 and solder it to R8
 */
#define TLE94112_PIN_CS2     (P5_7)

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN      (P5_3)

class Tle94112Psoc6hal: virtual public Tle94112
{
	public:

		Tle94112Psoc6hal(void);
		Tle94112Psoc6hal(cyhal_gpio_t csPin);

};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PLATF_PCOS6_HPP_ **/
