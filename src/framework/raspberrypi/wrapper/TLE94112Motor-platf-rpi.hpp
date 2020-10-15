/**
 * @file        TLE94112Motor-platf-rpi.hpp
 * @brief       TLE94112Motor-platf-rpi.hpp Raspberry Pi Hardware Platforms
 * @date        September 2020
 * @version     1.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112MOTOR_PLATF_RPI_HPP_
#define TLE94112MOTOR_PLATF_RPI_HPP_

#include "TLE94112-platf-rpi.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../corelib/TLE94112Motor.hpp"

/**
 * @addtogroup platfRpi
 * @{
 */

class Tle94112MotorRpi: virtual public Tle94112Motor
{
};

/**
 * @}
 */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112MOTOR_PLATF_RPI_HPP_ **/