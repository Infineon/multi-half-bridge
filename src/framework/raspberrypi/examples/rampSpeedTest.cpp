/*!
 * \name        rampSpeedTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example measure the rampspeed of an attached motor with the TLE94112 shield
 * \details
 * By attaching a motor to the TLE94112 and running a testcase scenario, we can measure the
 * optimal values for the rampSpeed function. This function allows us to smoothly start, stop,
 * raise or break the motor.
 *
 * \attention A free running motor ramps very different than the same motor with load attached.
 * So you have to measure different scenarios.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "rampSpeedTest.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

// Tle94112 Object on Shield 1
Tle94112Rpi controller = Tle94112Rpi();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);

void measureRampTime(int index)
{
    printf("Test: %i\t", index);
    printf("%i -> %i\t", testcases[index].startspeed, testcases[index].endspeed);
    int32_t expected = (abs(testcases[index].endspeed - testcases[index].startspeed) * (int32_t)(testcases[index].slope)) / 255;
    printf("Expected: %d ms\n", expected);

    motor.setSpeed(testcases[index].startspeed);
    delay(100);

    uint32_t duration = bcm2835_st_read()/1000;
    motor.rampSpeed(testcases[index].endspeed, testcases[index].slope);
    duration = bcm2835_st_read()/1000 - duration;

    printf("Measured: %lu ms\n", duration);

}
int main(int argc, char const *argv[])
{
    
    printf("Init ready.\n");
    // Enable MotorController on all Shields and Motors
    // Note: Required to be done before starting to configure the motor
    // controller is set to default CS1 pin
    controller.begin();

    // Connect a motor to HB1 highside and HB5 lowside
    // With two combined halfbridges the motor can have up to 1.8 A
    // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
    motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_FREQ100HZ, controller.TLE_HB1, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB);
    motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_FREQ100HZ, controller.TLE_HB5, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB);

    // start motor
    motor.begin();

    int i = 0;
    while (i < NUM_TESTS)
    {
        measureRampTime(i);
        i++;
    } 

}


#endif /** TLE94112_FRAMEWORK **/
