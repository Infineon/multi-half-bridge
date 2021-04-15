/*!
 * \name        multipleMotors
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example demonstrates how to control two motors, their speed and direction with the TLE94112.
 *
 * \details
 * By attaching a Tle94112 controller object to two Tle94112Motor objects, we can generate
 * an easy to handle motor object for each motor. We can easily attach this motor object
 * two any of the halfbridges and to any of the PWM units. This is done in the setup part.
 * Keep in mind that you have to initialize the Tle94112 controller and each motor object,
 * which is done in the setup function.
 * After that we can take the motor start, stop and setSpeed function to easily control
 * each motor.
 *
 * \attention Motors have depending on their size a very big latency until a motor has
 * fully started or is stopped to 0. Specially the time between a start and stop and vice versa
 * is much higher than the processing speed of any microcontroller. This is solved in this example
 * with the delay command, but there are better solutions than that.
 * These delays are needed because a direct switch between start and stop will lead to high currents
 * and the TLE94112 will signal an overcurrent.
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
#include <cstdio>
#include <bcm2835.h>

int main(int argc, char const *argv[])
{
    // Tle94112 Object on Shield 1
    Tle94112Rpi controller;

    // Tle94112Motor Objects
    Tle94112Motor motor1(controller);
    Tle94112Motor motor2(controller);

    // Enable MotorController Tle94112
    // Note: Required to be done before starting to configure the motor
    controller.begin();

    // Clear all errors to start clean
    controller.clearErrors();

    // Connect motor1 to HB1 and HB5
    motor1.connect(motor1.HIGHSIDE, controller.TLE_HB1);
    motor1.connect(motor1.LOWSIDE,  controller.TLE_HB5);

    // Drive HB1 with signal from PWM1
    // Note: This allows to control the speed of the motor
    motor1.setPwm(motor1.LOWSIDE, controller.TLE_PWM1);

    // Connect motor2 to HB7 and HB9
    motor2.connect(motor2.HIGHSIDE, controller.TLE_HB7);
    motor2.connect(motor2.LOWSIDE,  controller.TLE_HB9);

    // Drive HB2 with signal from PWM2
    // Note: This allows to control the speed of the motor
    motor2.setPwm(motor2.LOWSIDE, controller.TLE_PWM2);

    //when configuration is done, call begin to start operating the motors
    motor1.begin();
    motor2.begin();

    // start the motor1 forward on half speed
    printf("Start motor 1 on 50%% duty cycle.\n");
    motor1.start(127);
    delay(2000);
    // start the motor2 forward on half speed
    printf("Start motor 2 on 50%% duty cycle.\n");
    motor2.start(127);
    delay(2000);

    // accelerate motor1 to full speed
    printf("Accelerate motor 1 to 100%% duty cycle.\n");
    motor1.setSpeed(255);
    delay(2000);

    // accelerate motor2 to full speed
    printf("Accelerate motor 2 to 100%% duty cycle.\n");
    motor2.setSpeed(255);
    delay(2000);

    // stop both motors
    printf("Stop both motors.\n");
    motor1.stop();
    motor2.stop();
}

#endif /** TLE94112_FRAMEWORK **/
