/** 
 * @file        TLE94112-platf-wiced.cpp
 * @brief       TLE94112 Cypress WICED-43xxx Hardware Platforms
 * @date        Mai 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "TLE94112-platf-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

/**
 * @addtogroup tl94112wicedhw
 */
TLE94112Wiced::TLE94112Wiced(void):Tle94112()
{
	Tle94112::en = new GPIOWiced(TLE94112_PIN_EN, OUTPUT, GPIOWiced::POSITIVE );
	Tle94112::timer = new TimerWiced();
	Tle94112::sBus = new SPICWiced();
}

// TLE94112Wiced::TLE94112Wiced(void* bus, uint8_t csPin):Tle94112()
// {
// }


void TLE94112Wiced::begin(void)
{
	begin(TLE94112_PIN_CS1);
}

void TLE94112Wiced::begin(uint8_t csPin)
{
	mEnabled = false;

	Tle94112::sBus->init();
	Tle94112::en->init();
	Tle94112::en->enable();
	Tle94112::timer->init();
	mEnabled = true;
	init();
}

void TLE94112Wiced::end(void)
{
	mEnabled = false;
	Tle94112::en->disable();
	Tle94112::timer->stop();
	Tle94112::sBus->deinit();
}


/**
 * @}
 */

#endif /** TLE94112_PLATF_WICED_HPP_ **/