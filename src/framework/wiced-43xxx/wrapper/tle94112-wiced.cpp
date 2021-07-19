/**
 * @file        tle94112-wiced.hpp
 * @brief       TLE94112 WICED API
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "tle94112-wiced.hpp"
#include "tle94112-platf-wiced.hpp"
#include "gpio-wiced.hpp"
#include "spic-wiced.hpp"
#include "timer-wiced.hpp"

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