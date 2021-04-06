/*!
 * \name        advancedTest
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example runs an advanced controller test with one attached motor on the TLE94112ES HAT for Raspberry Pi.
 * \details
 * This example is meant for one bidirectional motor, connected to
 * output 1 and 5 of the TLE94112ES HAT for Raspberry Pi.
 * It demonstrates the following library functions:
 * * Basic motor control
 *   - Run motor forward without PWM
 *   - Stop (brake) motor
 *   - Run motor backwards without PWM
 *   - Coast motor
 * * Motor control with PWM
 *   - Run motor forward with PWM (50% duty cycle)
 *   - Stop (brake) motor with PWM (50% duty cycle)
 * * Ramp up/down motor speed
 *   - Slowly ramp up duty cycle from 0% to 100%
 *   - Slowly ramp down duty cycle from 100% to 50%
 *   - Quickly ramp up duty cycle from 50% to 100%
 *   - Quickly ramp down duty cycle from 100% to 0%
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef ADVANCEDTEST_HPP_
#define ADVANCEDTEST_HPP_

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

#define DELAY      3000

void advancedTest(uint8_t bridges);

#endif /** TLE94112_FRAMEWORK **/
#endif /* ADVANCEDTEST_HPP_ */
