/** 
 * @file        TLE94112-platf-wiced.cpp
 * @brief       TLE94112 Cypress WICED-43xxx Hardware Platforms
 * @date        Mai 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "TLE94112-platf-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

/**
 * @addtogroup tl94112wicedhw
 */

/**
 *  TLE94112 Shield pins for CYW943907AEVAL1F Eval Kit
 */
PlatformWICED_t TLE94112_Shield_Pins =
{
    .EN  = WICED_GPIO_8,
    .CS1 = WICED_GPIO_10,
    .CS2 = WICED_GPIO_9,
    .CS3 = 0,
};

/**
 * @}
 */

#endif /** TLE94112_PLATF_WICED_HPP_ **/