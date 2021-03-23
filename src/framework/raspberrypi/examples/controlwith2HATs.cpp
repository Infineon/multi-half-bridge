  
/*!
 * \name        controlwith2HATs
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     2.0.0
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 HAT for Raspberry Pi
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 * Take this example as a first test when starting with this shield.
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
#include "tle94112-platf-rpi.hpp"

/* 3rd party libraries for this example */
#include <cstdio>
#include <bcm2835.h>

int main(int argc, char const *argv[])
{
  
    // Tle94112 Object for HATs 1 (CS0, default) and 2 (CS1)
    Tle94112Rpi controller1 = Tle94112Rpi();
    Tle94112Rpi controller2 = Tle94112Rpi(TLE94112_PIN_CS1);

    // Tle94112Motor Objects
    Tle94112Motor motor1(controller1);
    Tle94112Motor motor2(controller2);

    // Connect motor1 to HB1 and HB5 of controller 1
    motor1.connect(motor1.HIGHSIDE, controller1.TLE_HB1);
    motor1.connect(motor1.LOWSIDE,  controller1.TLE_HB5);

    // Connect motor2 to HB1 and HB5 of controller 2
    motor2.connect(motor2.HIGHSIDE, controller2.TLE_HB1);
    motor2.connect(motor2.LOWSIDE,  controller2.TLE_HB5);

    // Begin SPI communication with controller 1
    controller1.begin();

    // Run motor1
    printf("Run motor1...\n");
    motor1.begin();
    motor1.start(1);

    delay(2000);

    // Begin SPI communication with controller 2 (ends communication with controller 1)
    controller2.begin();

    // Run motor2
    printf("Run motor2...\n");
    motor2.begin();
    motor2.start(1);

    delay(5000);

    // Stop both motors
    motor2.stop(1);
    controller1.begin();
    motor1.stop(1);
}

#endif /** TLE94112_FRAMEWORK **/