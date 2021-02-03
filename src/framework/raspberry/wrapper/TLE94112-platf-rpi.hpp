/**
 * @file        TLE94112-pal-rpi.hpp
 * @brief       TLE94112-pal-rpi.hpp Raspberry Pi Hardware Platforms
 * @date        September 2020
 * @version     1.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112rpi
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_RPI_HPP_
#define TLE94112_PLATF_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include <bcm2835.h>
#include "../pal/TLE94112-pal-rpi.hpp"
/**
 * @addtogroup rpiPal
 * @{
 *
 * @brief Raspberry Pi Hardware Platform Pins
 */

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS0     RPI_V2_GPIO_P1_24

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to change the position of the Jumper
 */
#define TLE94112_PIN_CS1     RPI_V2_GPIO_P1_26
#define TLE94112_PIN_CS2     RPI_V2_GPIO_P1_22
#define TLE94112_PIN_CS3     RPI_V2_GPIO_P1_15

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN      RPI_V2_GPIO_P1_37

class Tle94112Rpi: virtual public TLE94112Rpi
{
	public:
		Tle94112Rpi(void);
		Tle94112Rpi(uint8_t csPin);
		void begin(void);
		void end(void);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PLATF_RPI_HPP_ **/