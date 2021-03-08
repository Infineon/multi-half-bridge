/**
 * @file        tle94112-rpi.hpp
 * @brief       TLE94112 Raspberry Pi API
 * @date        September 2020
 * @version     1.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112rpi
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_RPI_HPP_
#define TLE94112_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../corelib/tle94112.hpp"

class Tle94112Rpi: virtual public Tle94112
{
	public:
		Tle94112Rpi(void);
		Tle94112Rpi(uint8_t csPin);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_RPI_HPP_ **/