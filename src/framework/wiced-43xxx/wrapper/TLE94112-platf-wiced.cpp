/*!
 * \file        TLE94112-platf-wiced.cpp
 * \name        TLE94112-platf-wiced.cpp - Cypress Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     2.0.0
 * \ref         tle94112wiced
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "TLE94112-platf-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

Tle94112Wiced::Tle94112Wiced(void):Tle94112()
{
	Tle94112Wiced(TLE94112_PIN_CS1);
}

Tle94112Wiced::Tle94112Wiced(wiced_gpio_t csPin):Tle94112()
{
	Tle94112::en = new GPIOWiced(TLE94112_PIN_EN, OUTPUT_PUSH_PULL, GPIOWiced::POSITIVE );
	Tle94112::cs = new GPIOWiced(csPin, OUTPUT_PUSH_PULL, GPIOWiced::POSITIVE );
	Tle94112::timer = new TimerWiced();
	Tle94112::sBus = new SPICWiced();
}

void Tle94112Wiced::begin(void)
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

void Tle94112Wiced::end(void)
{
	mEnabled = false;
	Tle94112::en->disable();
	Tle94112::cs->disable();
	Tle94112::timer->stop();
	Tle94112::sBus->deinit();
}

#endif /** TLE94112_FRAMEWORK **/
