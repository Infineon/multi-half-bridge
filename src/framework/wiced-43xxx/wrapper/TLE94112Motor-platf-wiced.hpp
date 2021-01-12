/**
 * @file        TLE94112Motor-platf-wiced.hpp
 * @brief       TLE94112Motor-platf-wiced.hpp Cypress WICED-43xxx Hardware Platforms
 * @date        Mai 2020
 * @version     2.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112wiced
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112MOTOR_PLATF_WICED_HPP_
#define TLE94112MOTOR_PLATF_WICED_HPP_

#include "TLE94112-platf-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "../../../corelib/TLE94112Motor.hpp"

/**
 * @addtogroup platfWiced
 *
 * This class provides a simple API for connecting and controlling motors.
 * Each motor is assigned to a Tle94112 which acts as output driver. Calls to
 * Tle94112Motor instances are mapped to calls to Tle94112. Therefore, this
 * class does not bring new features, it does only provide further abstraction.
 *
 * @{
 */

class Tle94112MotorWiced: public Tle94112Motor
{
};

/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112MOTOR_PLATF_WICED_HPP_ **/
