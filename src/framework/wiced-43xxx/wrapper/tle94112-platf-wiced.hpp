/**
 * @file        tle94112-platf-wiced.hpp
 * @brief       TLE94112 WICED Hardware Platforms
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_WICED_HPP_
#define TLE94112_PLATF_WICED_HPP_

#include <wiced_platform.h>

/**
 * @addtogroup platfWiced
 * @{
 */

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS1     WICED_GPIO_7

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to remove the 0 Ohm resistor R7 and solder it to R8
 */
#define TLE94112_PIN_CS2     WICED_GPIO_17

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN      WICED_GPIO_36

/** @} */

#endif /** TLE94112_PLATF_WICED_HPP_ **/