/**
 * @file        tle94112-rpi.hpp
 * @brief       TLE94112 Raspberry Pi API
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112rpi
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_RPI_HPP_
#define TLE94112_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../corelib/tle94112.hpp"
#include <bcm2835.h>

class Tle94112Rpi: virtual public Tle94112
{
	public:
		Tle94112Rpi(void);
		Tle94112Rpi(uint8_t csPin);

        /**
         * @brief This enum is used to expose the CS-Pins of the
         * Raspberry-Pi to the Pybind11 wrapper.
         */
		enum TlePinCS{
        TLE94112_PIN_CS0     = RPI_V2_GPIO_P1_24,
        TLE94112_PIN_CS1     = RPI_V2_GPIO_P1_26,
        TLE94112_PIN_CS2     = RPI_V2_GPIO_P1_22,
        TLE94112_PIN_CS3     = RPI_V2_GPIO_P1_15,
        TLE94112_PIN_EN      = RPI_V2_GPIO_P1_37
    };
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_RPI_HPP_ **/