/** 
 * @file        spic.hpp
 * @brief       TLE94112 SPI Platform Abstraction Layer
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "spic.hpp"

using namespace tle94112;

Error_t SPIC::checkErrorStatus()
{
	return errorStatus;
}
