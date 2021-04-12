  
/*!
 * \name        ledMode
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example shows how to use LED mode on output 1 of the TLE94112ES.
 * \details
 * Outputs OUT1 and OUT2 are designed to optionally drive low current loads such as LEDs. The high-side
 * channels, HS1 and HS2 are equipped with a lower open load threshold detection current and shorter filter
 * time, specifically for low current loads such as LEDs.
 * Setting HS1 or HS2 in LED mode increases the RDS_ON and decreases the open load detection threshold.
 * This example enables LED mode on output 1 of the TLE94112ES and subsequently reads out the current status
 * of the open load error register. If an LED is connected and LED mode is enabled, the error register should
 * be empty, else an open load error will occur.
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

  // Clear all errors to start clean
  controller.clearErrors();

  // disable LED mode for output 1
  controller.setLedMode(controller.TLE_HB1, 0);
  controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_NOPWM);

  delay(1000);

  // Enable LED mode for output 1
  // The following line lowers the sensitivity for open load detection.
  // Comment it to get an open load error when using small loads like LEDs.
  controller.setLedMode(controller.TLE_HB1, 1);

  // Clear previous errors
  controller.clearErrors();

  if (controller.getSysDiagnosis() & controller.TLE_LOAD_ERROR)
    {
      // Handle the Load error here.
      // Read open load status of this half bridge from chip
      if ( controller.getHBOpenLoad(controller.TLE_HB1) ) {
        printf("\tHB 1:\tOpen load detected. Please connect LED.\n");
      }
    }

  delay(3000);

  // Turn LED off
  controller.configHB(controller.TLE_HB1, controller.TLE_FLOATING, controller.TLE_NOPWM);
}

#endif /** TLE94112_FRAMEWORK **/
