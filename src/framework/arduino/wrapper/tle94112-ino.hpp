/**
 * @file        tle94112-ino.hpp
 * @brief       TLE94112 Arduino API
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_INO_HPP_
#define TLE94112_INO_HPP_

#include "tle94112.hpp"
#include "tle94112-platf-ino.hpp"

/**
 * @addtogroup inoApi
 * @{
 */

/**
 * @brief Arduino Tle94112Ino constructor
 *
 */
class Tle94112Ino: virtual public Tle94112
{
	public:
		Tle94112Ino(void);
		Tle94112Ino(uint8_t csPin);
};
/** @} */

#endif /** TLE94112_INO_HPP_ **/