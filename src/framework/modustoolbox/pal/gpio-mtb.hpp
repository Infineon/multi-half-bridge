/**
 * @file        gpio-mtb.hpp
 * @brief       TLE94112 GPIO ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef GPIO_MTB_HPP_
#define GPIO_MTB_HPP_

#include <stdint.h>
#include "cyhal_system.h"
#include "cyhal_gpio.h"
#include "gpio.hpp"

using namespace tle94112;

/**
 * @addtogroup mtbPal
 * @{
 */

/**
 * @brief ModusToolbox GPIO wrapper class
 */
class GPIOMtb : virtual public GPIOC
{
	private:
		cyhal_gpio_t                pin;                                 /**< Pin number */
		cyhal_gpio_direction_t      dir;                                 /**< Pin direction */
		cyhal_gpio_drive_mode_t     driveMode;                           /**< Pin drive mode */
		VLogic_t                    logic;                               /**< Pin logic */

	public:
		static const cyhal_gpio_t   unusedPin = CYHAL_NC_PIN_VALUE;      /**< Unused pin */

					GPIOMtb(cyhal_gpio_t              pin,
							cyhal_gpio_direction_t    dir,
							cyhal_gpio_drive_mode_t   driveMode,
							VLogic_t                  logic);
					~GPIOMtb();
		Error_t     init();
		Error_t     deinit();
		VLevel_t    read();
		Error_t     write(VLevel_t level);
		Error_t     enable();
		Error_t     disable();
};

/** @} */

#endif /** GPIO_MTB_HPP_ **/