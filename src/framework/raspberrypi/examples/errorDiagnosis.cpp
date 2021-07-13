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
 *
 */

/* Infineon library for multi half bridge */
#include "tle94112-rpi.hpp"
#include "tle94112-motor.hpp"

/* 3rd party libraries for this example */
#include <cstdio>
#include <bcm2835.h>

int main(int argc, char const *argv[])
{

  // Tle94112 Object on Shield 1
  Tle94112Rpi controller;

  // Tle94112Motor Objects on controller
  Tle94112Motor motor(controller);

  // Enable MotorController on all Shields and Motors
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS0 pin
  controller.begin();

  // Connect a motor to HB1 high-side and HB5 low-side
  // With two combined half bridges the motor can have up to 1.8 A
  motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB);
  motor.initConnector(motor.LOWSIDE, controller.TLE_NOPWM, controller.TLE_HB5, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB);

  // start the motor controller
  motor.begin();

  // run the motor
  motor.start(255);

  // Clear all errors to start clean
  controller.clearErrors();

  printf("Motor active, starting loop.\n\n");

  while (1)
  {

    // Communicate with TLE94112 to get the status register SYS_DIAG1 (default)
    uint8_t status = controller.getSysDiagnosis();

    /**
     * The SPI error flag shows if a SPI protocol
     * error is detected.
    */
    if (status & controller.TLE_SPI_ERROR)
    {
      printf("SPI error detected!\n");
      // Handle the SPI error here.
    }

    /**
     * The under voltage flag shows if a supply
     * voltage below the lower limit is detected.
     *
     * All outputs are disabled when flag is set.
     *
     * This error is latched and needs to be
     * cleared manually.
    */
    if (status & controller.TLE_UNDER_VOLTAGE)
    {
      printf("Under voltage detected!\n");
      // Handle the under voltage error here.
    }

    /**
     * The over voltage flag shows if a supply
     * voltage above the upper limit is detected.
     *
     * All outputs are disabled when flag is set.
     *
     * This error is latched and needs to be
     * cleared manually.
    */
    if (status & controller.TLE_OVER_VOLTAGE)
    {
      printf("Over voltage detected!\n");
      // Handle the over voltage error here.
    }

    /**
     * The over voltage flag shows if a supply
     * voltage above the upper limit is detected.
     *
     * All outputs are disabled when flag is set.
     *
     * This error is latched and needs to be
     * cleared manually.
    */
    if (status & controller.TLE_POWER_ON_RESET)
    {
      printf("Power on reset detected!\n");
      // Handle the power on reset here.
    }

    /**
     * The pre-warning temperature flag shows that
     * the junction temperature exceeded the
     * temperature pre-warning threshold.
     *
     * This error is latched and needs to be
     * cleared manually.
    */
    if (status & controller.TLE_TEMP_WARNING)
    {
      printf("Junction temperature above pre-warning threshold!\n");
      // Handle the temperature warning here.
    }

    /**
     * The shutdown temperature flag shows that
     * the junction temperature exceeded the
     * shutdown temperature threshold.
     *
     * All outputs are disabled when flag is set.
     *
     * This error is latched and needs to be
     * cleared manually.
    */
    if (status & controller.TLE_TEMP_SHUTDOWN)
    {
      printf("Junction temperature above shutdown threshold!\n");
      // Handle the temperature shutdown here.
    }

    /**
     * The load error flag shows that either
     * - an open load error or
     * - an over-current error
     * is detected on at least one output.
     *
     * The faulty output is disabled in case
     * of an over-current error.
     *
     * This error is latched and needs to be
     * cleared manually.
    */
    if (status & controller.TLE_LOAD_ERROR)
    {
      printf("Load error detected!\n");
      // Handle the Load error here.

      /**
      * A load error can be specified more precisely.
      * The chip knows which kind of error occurred in
      * which half-bridge. This can be red as follows:
      */

      // For each half bridge (0 is placeholder for no half bridge)
      for (uint8_t halfBridge = 1; halfBridge <= 12; halfBridge++)
      {

        // Read over-current status of this half bridge from chip
        uint8_t oc = controller.getHBOverCurrent((Tle94112::HalfBridge)halfBridge);

        // Check for an over-current error on the low-side of this half bridge
        if (oc & controller.TLE_LOWSIDE)
        {
          printf("\tHB %u:\tOver-current detected in low-side switch.\n", halfBridge);
        }

        // Check for an over-current error on the high-side of this half bridge
        if (oc & controller.TLE_HIGHSIDE)
        {
          printf("\tHB %u:\tOver-current detected in high-side switch.\n", halfBridge);
        }

        // Read open load status of this half bridge from chip
        uint8_t ol = controller.getHBOpenLoad((Tle94112::HalfBridge)halfBridge);

        // Check for an open load error in this half bridge
        if (ol)
        {
          printf("\tHB %u:\tOpen load detected.\n", halfBridge);
        }
      }
    }

    // If no error was found print a heartbeat message
    if (!status)
    {
      printf("All seems fine :-)\n");
    }

    printf("\n---\n\n");

    // Clear all error flags (will clear latched errors if they do not persist)
    controller.clearErrors();

    // Wait for 5 seconds
    delay(5000);
  }
}