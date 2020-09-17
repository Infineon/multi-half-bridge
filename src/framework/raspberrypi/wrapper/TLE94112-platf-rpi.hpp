/**
 * @file        TLE94112-platf-rpi.hpp
 * @brief       TLE94112-platf-rpi.hpp Raspberry Pi Hardware Platforms
 * @date        September 2020
 * @version     1.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_RPI_HPP_
#define TLE94112_PLATF_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../pal/TLE94112-pal-rpi.hpp"

/**
 * @addtogroup platfRpi
 * @{
 *
 * @brief Raspberry Pi Hardware Platform Pins
 */

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS0     24

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to change the position of the Jumper
 */
#define TLE94112_PIN_CS1     7
#define TLE94112_PIN_CS2     25
#define TLE94112_PIN_CS3     22

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN      26

/**
 * @}
 */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PLATF_INO_HPP_ **/