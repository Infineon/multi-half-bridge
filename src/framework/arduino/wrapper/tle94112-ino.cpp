/**
 * @file        tle94112-ino.cpp
 * @brief       TLE94112 Arduino API
 * @date        Mai 2020
 * @version     2.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "../../../tle94112-ino.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

#include "tle94112-platf-ino.hpp"
#include "../pal/gpio-arduino.hpp"
#include "../pal/spic-arduino.hpp"
#include "../pal/timer-arduino.hpp"

/**
 * @brief Construct a new Tle94112Ino:: Tle94112Ino object
 * with default pin assignment
 */
Tle94112Ino::Tle94112Ino(void):Tle94112()
{
	Tle94112::en = new GPIOIno( TLE94112_PIN_EN,  OUTPUT, GPIOIno::POSITIVE );
	Tle94112::cs = new GPIOIno( TLE94112_PIN_CS1, OUTPUT, GPIOIno::POSITIVE );
	Tle94112::timer = new TimerIno();
	Tle94112::sBus  = new SPICIno();
}

/**
 * @brief constructor with individual pin assignment
 *
 * @param csPin  pin number of the CS pin
 */
Tle94112Ino::Tle94112Ino(uint8_t csPin):Tle94112()
{
	Tle94112::en = new GPIOIno( TLE94112_PIN_EN, OUTPUT, GPIOIno::POSITIVE );
	Tle94112::cs = new GPIOIno( csPin, OUTPUT, GPIOIno::POSITIVE );
	Tle94112::timer = new TimerIno();
	Tle94112::sBus  = new SPICIno();
}

#endif /** TLE94112_FRAMEWORK **/
