/**
 * @file        tle94112-mtb.cpp
 * @brief       TLE94112 ModusToolbox HAL API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "tle94112-mtb.hpp"
#include "spic-mtb.hpp"
#include "gpio-mtb.hpp"
#include "timer-mtb.hpp"

/**
 * @brief Construct a new Tle94112Mtb object
 * For ModusToolbox HAL setups with different than the usual pinsettings.
 *
 * @param csPin   chipselect pin for the wrapping GPIO
 * @param misoPin miso pin for the SPIC
 * @param mosiPin mosi pin for the SPIC
 * @param sckPin  system clock pin for the SPIC
 */
Tle94112Mtb::Tle94112Mtb(cyhal_gpio_t csPin, cyhal_gpio_t misoPin, cyhal_gpio_t mosiPin, cyhal_gpio_t sckPin)
:Tle94112()
{
	Tle94112::en = new GPIOMtb(TLE94112_PIN_EN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOMtb::POSITIVE);
	Tle94112::cs = new GPIOMtb(csPin, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOMtb::POSITIVE);
	Tle94112::timer = new TimerMtb();
	Tle94112::sBus = new SPICMtb(SPICMtb::unusedPin, misoPin, mosiPin, sckPin);
}

/**
 * @brief Construct a new Tle94112Mtb object
 * This constructor calls with default pinsetting for the MCU
 * board. Keep in mind that we do not set the chipselect pin with
 * the SPI class, as we need a constant signal during multiple transfers.
 *
 */
Tle94112Mtb::Tle94112Mtb(void)
:Tle94112()
{
	Tle94112::en = new GPIOMtb(TLE94112_PIN_EN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOMtb::POSITIVE );
	Tle94112::cs = new GPIOMtb(TLE94112_PIN_CS1, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOMtb::POSITIVE );
	Tle94112::timer = new TimerMtb();
	Tle94112::sBus = new SPICMtb(SPICMtb::unusedPin,KIT_SPI_MASTER_MISO,KIT_SPI_MASTER_MOSI,KIT_SPI_MASTER_SCLK);
}

/**
 * @brief Construct a new Tle94112Mtb object
 * This constructor calls with default pinsetting for the SPI
 * except for the chip select pin. Keep in mind that we do not set the chipselect pin with
 * the SPI class, as we need a constant signal during multiple transfers.
 *
 * @param csPin   chipselect pin for the wrapping GPIO
 */
Tle94112Mtb::Tle94112Mtb(cyhal_gpio_t csPin)
:Tle94112()
{
	Tle94112::en = new GPIOMtb(TLE94112_PIN_EN, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOMtb::POSITIVE );
	Tle94112::cs = new GPIOMtb(csPin, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, GPIOMtb::POSITIVE );
	Tle94112::timer = new TimerMtb();
	Tle94112::sBus = new SPICMtb(SPICMtb::unusedPin,KIT_SPI_MASTER_MISO,KIT_SPI_MASTER_MOSI,KIT_SPI_MASTER_SCLK);
}
