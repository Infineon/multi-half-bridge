/**
 * @file        gpio.cpp
 * @brief       PAL of the GPIO
 * @date        May 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "gpio.hpp"

using namespace tle94112;

<<<<<<< HEAD
GPIOC::Error_t GPIOC::checkErrorStatus()
=======
Error_t GPIOC::checkErrorStatus()
>>>>>>> 989f37cd9726f4152a93e2693d99d231b43dc1db
{
	return errorStatus;
}