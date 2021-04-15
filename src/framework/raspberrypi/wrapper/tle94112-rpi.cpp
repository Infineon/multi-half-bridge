/**
 * @file        tle94112-rpi.cpp
 * @brief       TLE94112 Raspberry Pi API
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112rpi
 *
 * SPDX-License-Identifier: MIT
 */

#include "tle94112-rpi.hpp"


#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "tle94112-platf-rpi.hpp"
#include "../pal/gpio-rpi.hpp"
#include "../pal/spic-rpi.hpp"
#include "../pal/timer-rpi.hpp"
#include <cstdio>

/**
 * @brief Construct a new Tle94112Rpi::Tle94112Rpi object
 * with default pin assignment
 */
Tle94112Rpi::Tle94112Rpi(void):Tle94112(new SPICRpi(), new GPIORpi(TLE94112_PIN_CS0,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE), new GPIORpi(TLE94112_PIN_EN,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE), new TimerRpi())
{
	// Tle94112::en = new GPIORpi(TLE94112_PIN_EN,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	// Tle94112::cs = new GPIORpi(TLE94112_PIN_CS0,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	// Tle94112::timer = new TimerRpi();
	// Tle94112::sBus = new SPICRpi();
}

/**
 * @brief constructor with individual pin assignment
 *
 * @param csPin  pin number of the CS pin
 */
Tle94112Rpi::Tle94112Rpi(uint8_t csPin)
{
	Tle94112::en = new GPIORpi(TLE94112_PIN_EN,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	Tle94112::cs = new GPIORpi(csPin,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	Tle94112::timer = new TimerRpi();
	Tle94112::sBus = new SPICRpi();
}

#endif /** TLE94112_FRAMEWORK **/