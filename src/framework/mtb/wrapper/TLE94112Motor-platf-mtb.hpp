/**
 * @file        TLE94112Motor-platf-mtb.hpp
 * @brief       TLE94112Motor-platf-mtb.hpp Cypress MTB-43xxx Hardware Platforms
 * @date        Mai 2020
 * @version     2.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112MOTOR_PLATF_MTB_HPP_
#define TLE94112MOTOR_PLATF_MTB_HPP_

#include "TLE94112-platf-mtb.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_MTB)

#include "../../../corelib/TLE94112Motor.hpp"

/**
 * @addtogroup platfMtb
 * @{
 */

class Tle94112MotorMtb: virtual public Tle94112Motor
{
};

/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112MOTOR_PLATF_MTB_HPP_ **/
