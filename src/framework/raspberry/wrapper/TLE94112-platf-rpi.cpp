/**
 * @file        TLE94112-platf-rpi.cpp
 * @brief       TLE94112-platf-rpi.cpp Raspberry Pi Hardware Platforms
 * @date        September 2020
 * @version     1.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * @ref         tle94112rpi
 *
 * SPDX-License-Identifier: MIT
 */

#include "TLE94112-platf-rpi.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

/**
 * @brief Construct a new Tle94112Rpi::Tle94112Rpi object
 * with default pin assignment
 */
Tle94112Rpi::Tle94112Rpi(void):Tle94112()
{
	Tle94112::en = new GPIORpi(TLE94112_PIN_EN,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	Tle94112::cs = new GPIORpi(TLE94112_PIN_CS0,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	Tle94112::timer = new TimerRpi();
	Tle94112::sBus = new SPICRpi();
}

/**
 * @brief constructor with individual pin assignment
 *
 * @param csPin  pin number of the CS pin
 */
Tle94112Rpi::Tle94112Rpi(uint8_t csPin):Tle94112()
{
	Tle94112::en = new GPIORpi(TLE94112_PIN_EN,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	Tle94112::cs = new GPIORpi(csPin,  BCM2835_GPIO_FSEL_OUTP, GPIORpi::POSITIVE );
	Tle94112::timer = new TimerRpi();
	Tle94112::sBus = new SPICRpi();
}

/**
 * @brief enables and initializes the TLE94112
 * 
 */
void Tle94112Rpi::begin(void)
{
	mEnabled = false;
	Tle94112::sBus->init();
	Tle94112::en->init();
	Tle94112::en->enable();
	Tle94112::cs->init();
	Tle94112::cs->enable();
	Tle94112::timer->init();
	mEnabled = true;
	init();
}

/**
 * @brief deactivates all outputs and disables the TLE94112
 * 
 */
void Tle94112Rpi::end(void)
{
	mEnabled = false;
	Tle94112::en->disable();
	Tle94112::cs->disable();
	Tle94112::timer->stop();
	Tle94112::sBus->deinit();
}


#endif /** TLE94112_FRAMEWORK **/
