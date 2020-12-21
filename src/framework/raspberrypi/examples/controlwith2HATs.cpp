  
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

#include "../../../config/tle94112-conf.hpp"


#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "controlwith2HATs.hpp"

int main(int argc, char const *argv[])
{

  
  // Tle94112 Object on Shield 1
Tle94112Rpi controller1 = Tle94112Rpi();
Tle94112Rpi controller2 = Tle94112Rpi(TLE94112_PIN_CS1);

// Tle94112Motor Objects
Tle94112Motor motor1(controller2);
Tle94112Motor motor2(controller1);

    // Enable MotorController Tle94112
    // Note: Required to be done before starting to configure the motor
    printf("Controller setup\n");
    controller1.begin();
    controller2.begin();
    printf("Controller begin\n");

    // Connect motor1 to HB1 and HB5
    motor1.connect(motor1.HIGHSIDE, controller2.TLE_HB1);
    motor1.connect(motor1.LOWSIDE,  controller2.TLE_HB5);

    motor2.connect(motor2.HIGHSIDE, controller1.TLE_HB1);
    motor2.connect(motor2.LOWSIDE,  controller1.TLE_HB5);

    // Drive HB1 with signal from PWM1
    // Note: This allows to control the speed of the motor
    motor1.setPwm(motor1.HIGHSIDE, controller2.TLE_PWM1);
    motor2.setPwm(motor2.HIGHSIDE, controller1.TLE_PWM1);
    // Set PWM Frequency, default is 80 Hz
    motor1.setPwmFreq(motor1.HIGHSIDE, controller2.TLE_FREQ100HZ);
    motor2.setPwmFreq(motor2.HIGHSIDE, controller1.TLE_FREQ100HZ);
    // Connect motor2 to HB2 and HB4


    // Drive HB2 with signal from PWM2
    // Note: This allows to control the speed of the motor

    //when configuration is done, call begin to start operating the motors
    printf("Motor begin\n");
    motor1.begin();
    motor2.begin();
    printf("All ready\n");

    // start the motor1 forwards on half speed
    motor1.start(127);
    // start the motor2 backwards on half speed
    motor2.start(127);
    delay(5000);

    // accelerate motor1 to full speed
    motor1.setSpeed(255);
    // stop motor2
    motor2.setSpeed(255);
    delay(1000);

    // reduce speed of motor1
    motor1.setSpeed(127);
    motor2.setSpeed(127);
    delay(1000);
    // let motor1 turn backwards on half speed
    motor1.setSpeed(-127);
    motor2.setSpeed(-127);
    delay(5000);
    // accelerate motor1 to full speed backwards
    motor1.setSpeed(-255);
    motor2.setSpeed(-255);
    delay(5000);

    // stop motor1, you can use the parameter to set the force which stops and holds them.
    // standard and maximum is 255
    motor1.stop(255);
    motor2.stop(255);
    delay(5000);
}

#endif /** TLE94112_FRAMEWORK **/