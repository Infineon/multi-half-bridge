/*!
 * \name        stepperMotor
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
 * \details
 * The multi half bridge TLE94112ES is able to drive voltage controlled bipolar stepper motors.
 * This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef STEPPERMOTOR_HPP_
#define STEPPERMOTOR_HPP_

/*
 * As this library works with multiple frameworks,
 * this part is needed to avoid trying to compile
 * this example from other frameworks.
 */
#include "../../../../config/tle94112-conf.hpp"
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

extern "C"
{
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
}

/* Infineon library for multi-half-bridge and motor control */
#include <tle94112-psoc6hal.hpp>

void stepperMotor();

#endif /** TLE94112_FRAMEWORK **/
#endif /* STEPPERMOTOR_HPP_ */
