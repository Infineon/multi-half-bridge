/**
 * @file        gpio-rpi.hpp
 * @brief       Raspberry Pi PAL for the GPIO
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef GPIO_RPI_HPP_
#define GPIO_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../corelib/tle94112.hpp"
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

#endif /** TLE94112_FRAMEWORK **/
#endif /** GPIO_RPI_HPP_ **/
