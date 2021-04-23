/*!
 * \name        errorDiagnosis
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to read and understand the status registers of the TLE94112.
 * \details
 * It will run the motor in forward direction and then read the status registers every 5 seconds. 
 * It shows how to understand the status registers and which errors can appear.
 * Take this example if you want to learn how to debug the TLE94112 during operation.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef ERRORDIAGNOSIS_HPP_
#define ERRORDIAGNOSIS_HPP_

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
#include <tle94112-motor.hpp>

void errorDiagnosis(uint8_t bridges);

#endif /** TLE94112_FRAMEWORK **/
#endif /* ERRORDIAGNOSIS_HPP_ */
