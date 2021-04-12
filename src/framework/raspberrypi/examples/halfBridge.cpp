  
/*!
 * \name        halfBridge
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example shows how to control the independent half bridges of the multi half bridge ICs.
 * \details
 * The example shows how to control the half bridges to switch generic loads.
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

/* 3rd party libraries for this example */
#include <bcm2835.h> // This library is required for the delay() function.

int main(int argc, char const *argv[])
{
  // Create a Tle94112Rpi instance for each motor controller.
  Tle94112Rpi controller;

  // Enable MotorController.
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS0 pin.
  controller.begin();

  // Clear all errors to start clean
  controller.clearErrors();

  // Set PWM channel 1 to 200 KHz and 50% duty cycle.
  controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ200HZ, 127);

  // Set half bridge 1 to high (V_bat) without PWM.
  controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_NOPWM);

  // Set half bridge 5 to low (GND) and connect it to PWM channel 1.
  controller.configHB(controller.TLE_HB5, controller.TLE_LOW, controller.TLE_PWM1);

  delay(3000);

  // Set PWM channel 1 to 100% duty cycle.
  controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ200HZ, 127);

  delay(3000);

  // Set both outputs to floating.
  controller.configHB(controller.TLE_HB1, controller.TLE_FLOATING, controller.TLE_NOPWM);
  controller.configHB(controller.TLE_HB5, controller.TLE_FLOATING, controller.TLE_NOPWM);
}

#endif /** TLE94112_FRAMEWORK **/
