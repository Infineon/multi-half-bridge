/** 
 * @file        TLE94112-platf-wiced.hpp
 * @brief       TLE94112 Cypress WICED-43xxx Hardware Platforms
 * @date        Mai 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_WICED_HPP_
#define TLE94112_PLATF_WICED_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "../pal/TLE94112-pal-wiced.hpp"

/**
 * @addtogroup tl94112wicedhw
 * @{
 * 
 * @brief WICED Hardware Platform
 */
typedef struct
{
    wiced_gpio_t EN;       /**< Power on pin for the shield*/
    wiced_gpio_t CS1;      /**< Chipselect pin for first shield, default setting */
    wiced_gpio_t CS2;      /**< Chipselect pin for second shield, change resistor on board, default setting */
    wiced_gpio_t CS3;      /**< Chipselect pin  for third shield, experimental */
}PlatformWICED_t;

extern PlatformWICED_t TLE94112_SHIELD_PINS;   /**< TLE94112 Shield */


/** 
 * @}
 */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PLATF_WICED_HPP_ **/