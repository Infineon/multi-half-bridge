  
/*!
 * \name        advancedTest
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example runs an advanced controller test with one attached motor on the TLE94112ES HAT for Raspberry Pi.
 * \details
 * This example is meant for one bidirectional motor, connected to
 * output 1 and 5 of the TLE94112ES HAT for Raspberry Pi.
 * It demonstrates the following library functions:
 * * Basic motor control
 *   - Run motor forward without PWM
 *   - Stop (brake) motor
 *   - Run motor backwards without PWM
 *   - Coast motor
 * * Motor control with PWM
 *   - Run motor forward with PWM (50% duty cycle)
 *   - Stop (brake) motor with PWM (50% duty cycle)
 * * Ramp up/down motor speed
 *   - Slowly ramp up duty cycle from 0% to 100%
 *   - Slowly ramp down duty cycle from 100% to 50%
 *   - Quickly ramp up duty cycle from 50% to 100%
 *   - Quickly ramp down duty cycle from 100% to 0%
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

#define DELAY 3000

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

 // Let the library know that a load is connected to HB1 (high side)
 // and HB5 (low side).
 motor.connect(motor.HIGHSIDE, controller.TLE_HB1);
 motor.connect(motor.LOWSIDE,  controller.TLE_HB5);

 // IMPORTANT: connect PWM to low side as high side is active free wheeling.
 motor.setPwm(motor.LOWSIDE, controller.TLE_PWM1);

 // start the motor controller
 motor.begin();

 /** BASIC MOTOR CONTROL. */
 printf("\n--- BASIC MOTOR CONTROL ---\n\n");
 delay(DELAY);
 
 // Run motor forward without PWM (full speed).
 printf("- Run motor forward without PWM (full speed).\n");
 motor.start(255);
 delay(DELAY);
 
 // Stop (brake) motor without PWM (full force).
 printf("- Stop (brake) motor without PWM (full force).\n");
 motor.stop(255);
 delay(DELAY);

 // Run motor backwards without PWM.
 printf("- Run motor backwards without PWM.\n");
 motor.start(-255);
 delay(DELAY);

 // Coast motor.
 printf("- Coast motor.\n");
 motor.coast();
 delay(DELAY);

 /** MOTOR CONTROL WITH PWM. */
 printf("\n--- MOTOR CONTROL WITH PWM ---\n\n");
 delay(DELAY);

 // Run motor forward with PWM (50% duty cycle).
 printf("- Run motor forward with PWM (50%% duty cycle).\n");
 motor.start(127); // 0.5 * 255 ~= 127
 delay(DELAY);

// Change duty cycle to 25%.
printf("- Change duty cycle to 25%%.\n");
 motor.setSpeed(64); // 0.25 * 255 ~= 64
 delay(DELAY);

 // Stop (brake) motor with PWM (50% duty cycle).
 printf("- Stop (brake) motor with PWM (50%% duty cycle).\n");
 motor.stop(127);
 delay(DELAY);

 /** RAMP UP/DOWN MOTOR SPEED. */
 printf("\n--- RAMP UP/DOWN MOTOR SPEED ---\n\n");
 delay(DELAY);

 // Slowly ramp up duty cycle from 0% to 100%.
 printf("- Slowly ramp up duty cycle from 0%% to 100%.\n");
 motor.rampSpeed(255, 20000);
 delay(DELAY);

 // Slowly ramp down duty cycle from 100% to 25%.
 printf("- Slowly ramp down duty cycle from 100%% to 25%%.\n");
 motor.rampSpeed(64, 20000);
 delay(DELAY);

 // Quickly ramp up duty cycle from 25% to 100%.
 printf("- Quickly ramp up duty cycle from 25%% to 100%%.\n");
 motor.rampSpeed(255, 5000);
 delay(DELAY);

 // Quickly ramp down duty cycle from 100% to 0%.
 printf("- Quickly ramp down duty cycle from 100%% to 0%%.\n");
 motor.rampSpeed(0, 5000);

 // Coast motor.
 printf("- Coast motor.\n");
 motor.coast();

 printf("\n--- END ---\n");

}
#endif /** TLE94112_FRAMEWORK **/