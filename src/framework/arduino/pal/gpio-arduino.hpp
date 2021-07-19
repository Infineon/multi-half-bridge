/**
 * @file        gpio-arduino.hpp
 * @brief       TLE94112 GPIO Arduino PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef GPIO_ARDUINO_HPP_
#define GPIO_ARDUINO_HPP_

#include "gpio.hpp"

using namespace tle94112;

/**
 * @addtogroup arduinoPal
 * @{
 */

/**
 * @brief Arduino GPIO class
 *
 */
class GPIOIno: virtual public GPIOC
{
private:
	#define     UNUSED_PIN    0xFF  /**< Unused pin */
	uint8_t     pin;
	uint8_t     mode;
	VLogic_t    logic;

public:
				GPIOIno();
				GPIOIno(uint8_t pin, uint8_t mode, VLogic_t logic);
				~GPIOIno();
	Error_t     init();
	Error_t     deinit();
	VLevel_t    read();
	Error_t     write(VLevel_t level);
	Error_t     enable();
	Error_t     disable();
};
/** @} */

#endif /** GPIO_ARDUINO_HPP_ **/