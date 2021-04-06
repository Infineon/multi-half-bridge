
/*!
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     3.0.0
 * \brief       This example shows how to switch two half bridge outputs with minimal code.
 * \details
 * It will switch on two outputs (one to Vsup and one to GND), wait 3 seconds
 * and switch off both outputs (both to floating state).
 *
 * SPDX-License-Identifier: MIT
 *
 */

/* Infineon library for multi-half-bridge and motor control */
#include "basicTest.hpp"

void basicTest(uint8_t bridges)
{

	/* pointer to the multi-half-bridge controller */
	Tle94112Psoc6hal controller = Tle94112Psoc6hal();

	/* pointer to the motor controller */
	Tle94112Motor motor(controller);

	printf("[multi-half-bridge] : setup begin\n");
	// Enable MotorController.
	// Note: Required to be done before starting to configure the motor

	// controller is set to default CS0 pin.
	controller.begin();
	printf("[multi-half-bridge] : controller begin\n");

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

	// Initialize the motor.
	motor.begin();
	printf("[multi-half-bridge] : motor begin\n");

	// Switch the load on.
	motor.start(255);

	cyhal_system_delay_ms(3000);

	// Switch the load off (outputs to floating state).
	motor.coast();
	printf("[multi-half-bridge] : motor stop\n");
}

