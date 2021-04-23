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

/* Infineon library for multi-half-bridge and motor control */
#include "advancedTest.hpp"

void advancedTest(uint8_t bridges)
{

	/* pointer to the multi-half-bridge controller */
	Tle94112Psoc6hal controller;

	/* pointer to the motor controller */
	Tle94112Motor motor(controller);

	printf("[multi-half-bridge] : setup begin\n");
	// Enable MotorController on all Shields and Motors
	// Note: Required to be done before starting to configure the motor
	// controller is set to default CS0 pin
	controller.begin();

	// Clear all errors to start clean
	controller.clearErrors();

	switch (bridges) {
		case 2U:
			// Let the library know that a load is connected to HB1 (high side)
			// and HB5 (low side).
			motor.connect(motor.HIGHSIDE, controller.TLE_HB1);
			motor.connect(motor.LOWSIDE, controller.TLE_HB5);
			motor.setPwm(motor.LOWSIDE, controller.TLE_NOPWM);
			break;
		case 4U:
			// Connect a motor to HB1/HB2 highside and HB3/HB4 lowside
			// With two combined halfbridges the motor can have up to 1.8 A
			// IMPORTANT connect PWM to Lowside as highside is active Free wheeling
			// This is an alternative setup for motors which needs more current
			motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
			motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);
			break;
	}
	printf("[multi-half-bridge] : motor init with -> with %u half-bridges\n", bridges);

	// start the motor controller
	motor.begin();
	printf("[multi-half-bridge] : motor begin\n");


	for (;;)
	{

		/** BASIC MOTOR CONTROL. */
		printf("\n--- BASIC MOTOR CONTROL ---\n\n");
		cyhal_system_delay_ms(DELAY);

		// Run motor forward without PWM (full speed).
		printf("- Run motor forward without PWM (full speed).\n");
		motor.start(255);
		cyhal_system_delay_ms(DELAY);

		// Stop (brake) motor without PWM (full force).
		printf("- Stop (brake) motor without PWM (full force).\n");
		motor.stop(255);
		cyhal_system_delay_ms(DELAY);

		// Run motor backwards without PWM.
		printf("- Run motor backwards without PWM.\n");
		motor.start(-255);
		cyhal_system_delay_ms(DELAY);

		// Coast motor.
		printf("- Coast motor.\n");
		motor.coast();
		cyhal_system_delay_ms(DELAY);

		/** MOTOR CONTROL WITH PWM. */
		printf("\n--- MOTOR CONTROL WITH PWM ---\n\n");
		cyhal_system_delay_ms(DELAY);

		// Run motor forward with PWM (50% duty cycle).
		printf("- Run motor forward with PWM (50%% duty cycle).\n");
		motor.start(127); // 0.5 * 255 ~= 127
		cyhal_system_delay_ms(DELAY);

		// Change duty cycle to 25%.
		printf("- Change duty cycle to 25%%.\n");
		motor.setSpeed(64); // 0.25 * 255 ~= 64
		cyhal_system_delay_ms(DELAY);

		// Stop (brake) motor with PWM (50% duty cycle).
		printf("- Stop (brake) motor with PWM (50%% duty cycle).\n");
		motor.stop(127);
		cyhal_system_delay_ms(DELAY);

		/** RAMP UP/DOWN MOTOR SPEED. */
		printf("\n--- RAMP UP/DOWN MOTOR SPEED ---\n\n");
		cyhal_system_delay_ms(DELAY);

		// Slowly ramp up duty cycle from 0% to 100%.
		printf("- Slowly ramp up duty cycle from 0%% to 100%%.\n");
		motor.rampSpeed(255, 20000);
		cyhal_system_delay_ms(DELAY);

		// Slowly ramp down duty cycle from 100% to 25%.
		printf("- Slowly ramp down duty cycle from 100%% to 25%%.\n");
		motor.rampSpeed(64, 20000);
		cyhal_system_delay_ms(DELAY);

		// Quickly ramp up duty cycle from 25% to 100%.
		printf("- Quickly ramp up duty cycle from 25%% to 100%%.\n");
		motor.rampSpeed(255, 5000);
		cyhal_system_delay_ms(DELAY);

		// Quickly ramp down duty cycle from 100% to 0%.
		printf("- Quickly ramp down duty cycle from 100%% to 0%%.\n");
		motor.rampSpeed(0, 5000);

		// Coast motor.
		printf("- Coast motor.\n");
		motor.coast();

		printf("\n--- END ---\n");

	}

}
