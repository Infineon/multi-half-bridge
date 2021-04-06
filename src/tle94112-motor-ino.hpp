/*!
 * \file        tle94112-motor-ino.hpp
 * \name        TLE94112Motor-ino.hpp - optionally include library
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     2.0.0
 * \ref         tle94112ino
 * \brief       This file can optionally be included in projects that use an Infineon
 *              DC Motor Control Shield with TLE94112
 *              It provides a higher abstraction for controlling motors with the TLE94112
 *              acting as an output driver
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef TLE94112MOTOR_INO_HPP_
#define TLE94112MOTOR_INO_HPP_

#include "config/tle94112-conf.hpp"

/**
 * @addtogroup inoApi
 * @{
 */

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

#include "tle94112-ino.hpp"
#include "corelib/tle94112-motor.hpp"

/**
 * @class Tle94112MotorIno
 *
 * @brief represents a motor connected to a TLE94112
 *
 * This file exists only for compatibility with the Arduino setup.
 * 
 * @see Tle94112
 */;

/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112MOTOR_INO_HPP_ **/
