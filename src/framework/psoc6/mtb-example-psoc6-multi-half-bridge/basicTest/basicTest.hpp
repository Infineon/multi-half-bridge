/*!
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     3.0.0
 * \brief       This example shows how to switch two half bridge outputs with minimal code.
 * \details
 * It will switch on two outputs (one to Vsup and one to GND), wait 3 seconds
 * and switch off both outputs (both to floating state).
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef BASICTEST_HPP_
#define BASICTEST_HPP_

extern "C"
{
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
}

/*
 * As this library works with multiple frameworks,
 * this part is needed to avoid trying to compile
 * this example from other frameworks.
 */
#include "../../../../config/tle94112-conf.hpp"
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

/* Infineon library for multi-half-bridge and motor control */
#include <tle94112-psoc6hal.hpp>
#include <tle94112-motor.hpp>

void basicTest(uint8_t bridges);

#endif /** TLE94112_FRAMEWORK **/
#endif /* BASICTEST_HPP_ */
