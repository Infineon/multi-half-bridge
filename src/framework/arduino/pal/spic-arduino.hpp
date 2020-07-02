/**
 * @file        spic-arduino.hpp
 * @brief       Arduino PAL for the SPI cover
 * @date        June 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_ARDUINO_HPP_
#define SPIC_ARDUINO_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

#include <Arduino.h>
#include "SPI.h"
#include "../../../pal/spic.hpp"

/**
 * @addtogroup arduinoPal
 * @{
 */


/**
 * @brief Arduino SPIC class
 *
 */
class SPICIno: virtual public SPIC
{
private:
	uint8_t     lsb;
	uint8_t     mode;
	uint8_t     clock;
	SPIClass    *spi;

public:
				SPICIno();
				//SPICIno(uint8_t pin, uint8_t mode, VLogic_t logic);
				~SPICIno();
	Error_t     init();
	Error_t     deinit();
	Error_t     transfer(uint8_t send, uint8_t &received);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** SPIC_ARDUINO_HPP_ **/