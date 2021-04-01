/*!
 * \name        multipleControllers
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     2.1.0
 * \brief       This example shows how to use multiple TLE94112 controllers simultaneously.
 * \details
 * For this example it is assumed, that two TLE94112 controllers are connected to one microcontroller.
 * The resistor R7 on the board has to be open and R8 closed with 0Ohm for shield 1 and
 * R7 closed with 0Ohm, R8 open for shield 2. Also connect the chip select pin for the second board as set in
 * tle94112-platf-psoc6hal.hpp.
 * On both controllers a load is connected between half bridge 1 and 5.
 * This example shows, how to control both motor controllers from one Raspberry Pi.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef MULTIPLECONTROLLERS_HPP_
#define MULTIPLECONTROLLERS_HPP_

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

void multipleControllers(uint8_t bridges);

#endif /** TLE94112_FRAMEWORK **/
#endif /* MULTIPLECONTROLLERS_HPP_ */
