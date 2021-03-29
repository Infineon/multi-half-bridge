/*!
 * \file        TLE94112-platf-mtb.cpp
 * \name        TLE94112-platf-mtb.cpp - Cypress Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     2.0.0
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "tle94112-platf-psoc6hal.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

/**
 * @brief Construct a new Tle94112Psoc6::Tle94112Psoc6 object
 * This constructor can not set the SPI pins until there are macros.
 */
Tle94112Psoc6hal::Tle94112Psoc6hal(void):Tle94112()
{
	Tle94112::en = new GPIOPsoc6hal(TLE94112_PIN_EN,  CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::cs = new GPIOPsoc6hal(TLE94112_PIN_CS1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::timer = new TimerPsoc6hal();
	Tle94112::sBus = new SPICPsoc6hal(SPICPsoc6hal::unusedPin,KIT_MISO,KIT_MOSI,KIT_SCK);
}

/**
 * @brief Construct a new Tle94112Psoc6hal::Tle94112Psoc6hal object
 * For PSOC HAL setups it is yet the only working constructor as there
 * are no default macro settings for SPI pins.
 * 
 * @param csPin   chipselect pin for the wrapping GPIO
 * @param misoPin miso pin for the SPIC
 * @param mosiPin mosi pin for the SPIC
 * @param sckPin  system clock pin for the SPIC
 */
Tle94112Psoc6hal::Tle94112Psoc6hal(cyhal_gpio_t csPin,cyhal_gpio_t misoPin,cyhal_gpio_t mosiPin,cyhal_gpio_t sckPin):Tle94112()
{
	Tle94112::en = new GPIOPsoc6hal(TLE94112_PIN_EN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::cs = new GPIOPsoc6hal(csPin, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::timer = new TimerPsoc6hal();
	Tle94112::sBus = new SPICPsoc6hal(SPICPsoc6hal::unusedPin,misoPin,mosiPin,sckPin);
}

#endif /** TLE94112_FRAMEWORK **/
