/*!
 * \file        tle94112-wiced.cpp
 * \name        TLE94112 Cypress WICED-43xxx API
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     2.0.0
 * \ref         tle94112wiced
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "tle94112-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "tle94112-platf-wiced.hpp"
#include "../pal/gpio-wiced.hpp"
#include "../pal/spic-wiced.hpp"
#include "../pal/timer-wiced.hpp"

/**
 * @brief Construct a new Tle94112Wiced::Tle94112 Wiced object
 * with default pin assignment
 */
Tle94112Wiced::Tle94112Wiced(void):Tle94112()
{
	Tle94112::en = new GPIOWiced(TLE94112_PIN_EN, OUTPUT_PUSH_PULL, GPIOWiced::POSITIVE );
	Tle94112::cs = new GPIOWiced(TLE94112_PIN_CS1, OUTPUT_PUSH_PULL, GPIOWiced::POSITIVE );
	Tle94112::timer = new TimerWiced();
	Tle94112::sBus = new SPICWiced();
}


/**
 * @brief constructor with individual pin assignment
 *
 * @param csPin  pin number of the CS pin
 */
Tle94112Wiced::Tle94112Wiced(wiced_gpio_t csPin):Tle94112()
{
	Tle94112::en = new GPIOWiced(TLE94112_PIN_EN, OUTPUT_PUSH_PULL, GPIOWiced::POSITIVE );
	Tle94112::cs = new GPIOWiced(csPin, OUTPUT_PUSH_PULL, GPIOWiced::POSITIVE );
	Tle94112::timer = new TimerWiced();
	Tle94112::sBus = new SPICWiced();
}

#endif /** TLE94112_FRAMEWORK **/