  
/*!
 * \name        ledMode
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example shows how to use LED mode on output 1of the TLE94112ES.
 * \details
 * Outputs OUT1 and OUT2 are designed to optionally drive low current loads such as LEDs. The high-side
 * channels, HS1 and HS2 are equipped with a lower open load threshold detection current and shorter filter
 * time, specifically for low current loads such as LEDs.
 * Setting HS1 or HS2 in LED mode increases the RDS_ON and decreases the open load detection threshold.
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
#include <cstdio>
#include <bcm2835.h> // This library is required for the delay() function.

int main(int argc, char const *argv[])
{
  
  // Create a Tle94112Rpi instance for each motor controller.
  Tle94112Rpi controller;

  // Enable MotorController.
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS0 pin.
  controller.begin();

  // Switch output 1 off (just to be sure)


  // Clear all errors to start clean
  controller.clearErrors();

  // Set LED mode for output 1
  controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_NOPWM, false);

  delay(1000);
  controller.clearErrors();

  // Set LED mode for output 1
  controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_NOPWM, 0x01);
  // Configure PWM channel 1 for LED

  // Assign LED to PWM channel 1 and activate LED

  if (controller.getSysDiagnosis() & controller.TLE_LOAD_ERROR)
    {
      // Handle the Load error here.
      // Read open load status of this half bridge from chip
      if ( controller.getHBOpenLoad(controller.TLE_HB1) ) {
        printf("\tHB 1:\tOpen load detected. Please connect LED.\n");
      }
    }

  delay(3000);
  controller.configHB(controller.TLE_HB1, controller.TLE_FLOATING, controller.TLE_NOPWM, true);
}

#endif /** TLE94112_FRAMEWORK **/
