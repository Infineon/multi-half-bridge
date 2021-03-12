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
 * 
 */
Tle94112Psoc6::Tle94112Psoc6(void):Tle94112()
{
	Tle94112::en = new GPIOPsoc6hal(TLE94112_PIN_EN, OUTPUT_PUSH_PULL, GPIOPsoc6hal::POSITIVE );
	Tle94112::cs = new GPIOPsoc6hal(TLE94112_PIN_CS1, OUTPUT_PUSH_PULL, GPIOPsoc6hal::POSITIVE );
	Tle94112::timer = new TimerPsoc6hal();
	Tle94112::sBus = new SPICPsoc6hal();
}

Tle94112Psoc6hal::Tle94112Psoc6hal(void* bus, uint8_t csPin):Tle94112()
{
}

#endif /** TLE94112_FRAMEWORK **/
