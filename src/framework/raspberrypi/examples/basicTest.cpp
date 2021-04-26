  
/*!
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to switch two half bridge outputs with minimal code.
 * \details
 * It will switch on two outputs (one to Vsup and one to GND), wait 3 seconds
 * and switch off both outputs (both to floating state).
 *
 * SPDX-License-Identifier: MIT
 *
 */

/*
 * As this library works with multiple frameworks,
 * this part is needed to avoid trying to compile
 * this example from other frameworks.
 */
#include "../../../config/tle94112-conf.hpp"
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

/* Infineon library for multi half bridge */
#include "tle94112-rpi.hpp"
#include "tle94112-motor.hpp"

/* 3rd party libraries for this example */
#include <bcm2835.h> // This library is required for the delay() function.

int main(int argc, char const *argv[])
{
  
  // Create a Tle94112Rpi instance for each motor controller.
  Tle94112Rpi controller;

  // Create a Tle94112Motor instance for each connected load.
  Tle94112Motor motor(controller);

  // Enable MotorController.
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS0 pin.
  controller.begin();

  // Clear all errors to start clean
  controller.clearErrors();

  // Let the library know that a load is connected to HB1 (high side)
  // and HB5 (low side).
  motor.connect(motor.HIGHSIDE, controller.TLE_HB1);
  motor.connect(motor.LOWSIDE, controller.TLE_HB5);
  motor.setPwm(motor.LOWSIDE, controller.TLE_NOPWM);
  
  // Initialize the motor.
  motor.begin();

  // Switch the load on.
  motor.start(255);

  delay(3000);

  // Switch the load off (outputs to floating state).
  motor.coast();
}

#endif /** TLE94112_FRAMEWORK **/
