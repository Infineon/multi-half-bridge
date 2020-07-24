/*!
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 shield
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 *
 * \attention A free running motor ramps very different than the same motor with load attached.
 * So you have to measure different scenarios.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "basicTest.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include <stdlib.h>
#include <wiced.h>
#include <TLE94112-pal-wiced.hpp>
#include <TLE94112.hpp>
#include <TLE94112Motor.hpp>
#include "wiced_time.h"
#include "wiced_rtos.h"

// Tle94112 Object on Shield 1
Tle94112Wiced controller = Tle94112Wiced();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);


void setup()
{
		// Enable MotorController on all Shields and Motors
		// Note: Required to be done before starting to configure the motor
		// controller1 is set to default CS1 pin
		WPRINT_APP_INFO(("[TLE94112] : setup begin -> %u\n", 0));
		controller.begin();
		WPRINT_APP_INFO(("[TLE94112] : controller begin -> %u\n", 1));

		//-motor-high current motor between out1/out2 = HB1/HB2 and out3/out4 = HB3/HB4

		// Connect motor to HB1/HB2 highside and HB3/HB4 lowside
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
	motor.coast();
	wiced_rtos_delay_milliseconds(1000);

	// max forward/backward
	WPRINT_APP_INFO(("max forward/backward\n"));
	motor.start(255);
	wiced_rtos_delay_milliseconds(1000);
	motor.coast();
	wiced_rtos_delay_milliseconds(1000);
	motor.start(-255);
	wiced_rtos_delay_milliseconds(1000);
	motor.coast();
	wiced_rtos_delay_milliseconds(1000);

	// ramp ripple forward/backward
	WPRINT_APP_INFO(("ramp ripple forward/backward\n"));
	motor.start(255);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(0,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.start(-255);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(0,5000);
	wiced_rtos_delay_milliseconds(1000);

	// ramp up/down forward
	WPRINT_APP_INFO(("ramp up/down forward\n"));
	motor.start(50); // start above 0 to allow motor to start
	motor.rampSpeed(255,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(100,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(255,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(0,5000);

	// ramp up/down backward
	WPRINT_APP_INFO(("ramp up/down backward\n"));
	motor.start(50);
	motor.rampSpeed(-255,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(-100,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(-255,5000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(0,5000);

	// ramp transient
	WPRINT_APP_INFO(("ramp transient\n"));
	motor.rampSpeed(-255,1000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(255,1000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(-255,1000);
	wiced_rtos_delay_milliseconds(1000);
	motor.rampSpeed(0,1000);
	wiced_rtos_delay_milliseconds(1000);

	// stop and coast
	WPRINT_APP_INFO(("stop and coast\n"));
	motor.stop(255);
	wiced_rtos_delay_milliseconds(1000);
	motor.coast();
	wiced_rtos_delay_milliseconds(1000);
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
