
/*!
 * \name        multipleControllers
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to use multiple TLE94112 controllers simultaneously.
 * \details
 * For this example it is assumed, that two TLE94112 controllers are connected to one Raspberry Pi.
 * The Chip Select pin of controller 1 is set to CS0 and the Chip Select pin of controller 2 is
 * set to CS1. On both controllers a load is connected between half bridge 1 and 5.
 * This example shows, how to control both motor controllers from one Raspberry Pi.
 *
 * SPDX-License-Identifier: MIT
 *
 */

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
    Tle94112Rpi controller1;
    Tle94112Rpi controller2(TLE94112_PIN_CS1);

    // Tle94112Motor Objects
    Tle94112Motor motor1(controller1);
    Tle94112Motor motor2(controller2);

    // Connect motor1 to HB1 and HB5 of controller 1
    motor1.connect(motor1.HIGHSIDE, controller1.TLE_HB1);
    motor1.connect(motor1.LOWSIDE,  controller1.TLE_HB5);
    motor1.setPwm(motor1.LOWSIDE, controller1.TLE_NOPWM);

    // Connect motor2 to HB1 and HB5 of controller 2
    motor2.connect(motor2.HIGHSIDE, controller2.TLE_HB1);
    motor2.connect(motor2.LOWSIDE,  controller2.TLE_HB5);
    motor2.setPwm(motor2.LOWSIDE, controller2.TLE_NOPWM);

    // Begin SPI communication with controller 1
    controller1.begin();

    // Run motor 1 (connected to controller 1)
    printf("Start motor on controller 1.\n");
    motor1.begin();
    motor1.start(255);

    delay(2000);

    // Begin SPI communication with controller 2 (ends communication with controller 1)
    controller2.begin();

    // Run motor 2 (connected to controller 2)
    printf("Start motor on controller 2.\n");
    motor2.begin();
    motor2.start(255);

    delay(5000);

    // Stop both motors
    printf("Stop both motors.\n");
    motor2.stop(255);
    controller1.begin();
    motor1.stop(255);
}