/** 
 * @file        gpio.cpp
 * @brief       TLE94112 GPIO Platform Abstraction Layer
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "gpio.hpp"

using namespace tle94112;

Error_t GPIOC::checkErrorStatus()
{
	return errorStatus;
}
