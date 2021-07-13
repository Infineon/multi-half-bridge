/**
 * @file        tle94112-wiced.cpp
 * @brief       TLE94112 WICED API
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef TLE94112_WICED_HPP_
#define TLE94112_WICED_HPP_

#include <wiced_platform.h>
#include "tle94112.hpp"

/**
 * @addtogroup wicedApi
 * @{
 */

class Tle94112Wiced: virtual public Tle94112
{
	public:

		Tle94112Wiced(void);
		Tle94112Wiced(wiced_gpio_t csPin);
};
/** @} */

#endif /** TLE94112_WICED_HPP_ **/