/**
 * @file        gpio-rpi.hpp
 * @brief       TLE94112 GPIO Raspberry Pi API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef GPIO_RPI_HPP_
#define GPIO_RPI_HPP_

#include "gpio.hpp"
#include <bcm2835.h>

using namespace tle94112;

/**
 * @addtogroup rpiPal
 * @{
 */


/**
 * @brief Raspberry Pi GPIO class
 *
 */
class GPIORpi: virtual public GPIOC
{
private:
	uint8_t     pin;
	uint8_t     mode;
	VLogic_t    logic;

public:
				GPIORpi();
				GPIORpi(uint8_t pin, uint8_t mode, VLogic_t logic);
				~GPIORpi(){};
	Error_t     init();
	Error_t     deinit();
	VLevel_t    read();
	Error_t     write(VLevel_t level);
	Error_t     enable();
	Error_t     disable();
};
/** @} */

#endif /** GPIO_RPI_HPP_ **/