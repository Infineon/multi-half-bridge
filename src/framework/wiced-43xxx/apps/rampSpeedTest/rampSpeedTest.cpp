/*!
 * \name        rampSpeedTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.5.0
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

#include "../../../../config/tle94112-conf.hpp"
#include "rampSpeedTest.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

// Tle94112 Object on Shield 1
Tle94112Wiced controller = Tle94112Wiced();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);


void measureRampTime(int index)
{
    int32_t expected = (abs(testcases[index].endspeed - testcases[index].startspeed) * (int32_t)(testcases[index].slope)) / 255;
    WPRINT_APP_INFO(("Test %i:\t", index));
    WPRINT_APP_INFO(("%i -> ", testcases[index].startspeed));
    WPRINT_APP_INFO(("%i  \t", testcases[index].endspeed));
    WPRINT_APP_INFO(("Expected: %i ms\n", expected));

    motor.setSpeed( testcases[index].startspeed );

    wiced_time_t startTime;
    wiced_time_t endTime;

    wiced_rtos_delay_milliseconds(100);
    wiced_time_get_time( &startTime );

    motor.rampSpeed( testcases[index].endspeed, testcases[index].slope);

    wiced_time_get_time( &endTime );

    WPRINT_APP_INFO(("Measured: %u ms\n", (uint32_t)(endTime - startTime)));
}

void setup()
{
    // Enable MotorController on all Shields and Motors
    // Note: Required to be done before starting to configure the motor
    // controller1 is set to default CS1 pin
    WPRINT_APP_INFO(("[TLE94112] : setup begin -> %u\n", 0));
    controller.begin();
    WPRINT_APP_INFO(("[TLE94112] : controller begin -> %u\n", 1));

    // Connect a motor to HB1/HB2 highside and HB3/HB4 lowside
    // With two combined halfbridges the motor can have up to 1.8 A
    // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
    motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
    motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);
    WPRINT_APP_INFO(("[TLE94112] : motor init -> %u\n", 2));

    // start motor
    motor.begin();
    WPRINT_APP_INFO(("[TLE94112] : motor begin -> %u\n", 3));
}

void loop()
{
    // put your main code here, to run repeatedly:
    for( int i=0; i<NUM_TESTS; i++)
    {
      measureRampTime(i);
    }
}



/******************************************************
 *               Function Definitions
 ******************************************************/

void application_start( )
{
    wiced_result_t      result;

    /* Initialize the device */
    result = wiced_init();
    if (result != WICED_SUCCESS)
    {
        return;
    }

    setup();

    while(1)
    {
        loop();
    }
}

#endif /** TLE94112_FRAMEWORK **/
