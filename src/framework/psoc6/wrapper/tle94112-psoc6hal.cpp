/**
 * @file        tle94112-psoc6hal.cpp
 * @brief       TLE94112 PSoC6 HAL API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "tle94112-psoc6hal.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "spic-psoc6hal.hpp"
#include "gpio-psoc6hal.hpp"
#include "timer-psoc6hal.hpp"

/**
 * @brief Construct a new Tle94112Psoc6::Tle94112Psoc6 object
 * This constructor calls with default pinsetting for the PSCO6
 * board. Keep in mind that we do not set the chipselect pin with
 * the SPI class, as we need a constant signal during multiple transfers.
 * 
 */
Tle94112Psoc6hal::Tle94112Psoc6hal(void):Tle94112()
{
	Tle94112::en = new GPIOPsoc6hal(TLE94112_PIN_EN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::cs = new GPIOPsoc6hal(TLE94112_PIN_CS1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::timer = new TimerPsoc6hal();
	Tle94112::sBus = new SPICPsoc6hal(SPICPsoc6hal::unusedPin,KIT_SPI_MASTER_MISO,KIT_SPI_MASTER_MOSI,KIT_SPI_MASTER_SCLK);
}

/**
 * @brief Construct a new Tle94112Psoc6::Tle94112Psoc6 object
 * This constructor calls with default pinsetting for the PSCO6 SPI
 * except for the chip select pin. Keep in mind that we do not set the chipselect pin with
 * the SPI class, as we need a constant signal during multiple transfers.
 * 
 * @param csPin   chipselect pin for the wrapping GPIO
 */
Tle94112Psoc6hal::Tle94112Psoc6hal(cyhal_gpio_t csPin):Tle94112()
{
	Tle94112::en = new GPIOPsoc6hal(TLE94112_PIN_EN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::cs = new GPIOPsoc6hal(csPin, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOPsoc6hal::POSITIVE );
	Tle94112::timer = new TimerPsoc6hal();
	Tle94112::sBus = new SPICPsoc6hal(SPICPsoc6hal::unusedPin,KIT_SPI_MASTER_MISO,KIT_SPI_MASTER_MOSI,KIT_SPI_MASTER_SCLK);
}

/**
 * @brief Construct a new Tle94112Psoc6hal::Tle94112Psoc6hal object
 * For PSOC HAL setups with different than the usual pinsettings.
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
