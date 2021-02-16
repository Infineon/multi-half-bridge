/*!
 * \file        TLE94112-ino.hpp
 * \name        TLE94112-ino.hpp - Arduino library to control Infineon's DC Motor Control Shield with Tle94112
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \ref         tle94112ino
 * \version     2.0.0
 * \brief       This is a Arduino platform file use Infineon's DC Motor Control Shield with TLE94112 with
 *              Arduino/Genuino, Infineon XMC microcontroller or compatible boards.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef TLE94112_INO_HPP_
#define TLE94112_INO_HPP_

#include "config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

/**
 * @addtogroup inoApi
 * @{
 */

#include "corelib/TLE94112.hpp"
#include "framework/arduino/wrapper/TLE94112-platf-ino.hpp"

/**
 * @class Tle94112Ino
 *
 * @brief represents the TLE94112 base class
 *
 * This file exists only for compatibility with the Arduino setup.
 * 
 */

/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_INO_HPP_ **/
