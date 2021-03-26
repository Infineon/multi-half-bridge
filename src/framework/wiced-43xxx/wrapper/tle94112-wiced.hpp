/**
 * @file        tle94112-wiced.hpp
 * @brief       TLE94112 Cypress WICED-43xxx API
 * @date        Mai 2020
 * @version     2.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112wiced
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_WICED_HPP_
#define TLE94112_WICED_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include <wiced_platform.h>
#include "../../../corelib/tle94112.hpp"

class Tle94112Wiced: virtual public Tle94112
{
	public:

		Tle94112Wiced(void);
		Tle94112Wiced(wiced_gpio_t csPin);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_WICED_HPP_ **/
