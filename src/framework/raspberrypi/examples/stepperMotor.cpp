  
/*!
 * \name        stepperMotor
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
 * \details
 * The multi half bridge TLE94112ES is able to drive voltage controlled bipolar stepper motors.
 * This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
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
  Tle94112Motor a(controller);
  Tle94112Motor b(controller);

  // Enable MotorController.
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS0 pin.
  controller.begin();

  // Clear all errors to start clean
  controller.clearErrors();

  // Let the library know that the stepper motor is connected to:
  // OUT1: A1
  // OUT5: A2
  // OUT7: B1
  // OUT9: B2
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
