/*!
 * \name        multipleControllers
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to use multiple TLE94112 controllers simultaneously.
 * \details
 * For this example it is assumed, that two TLE94112 controllers are connected to one microcontroller.
 * The resistor R7 on the board has to be open and R8 closed with 0Ohm for shield 1 and
 * R7 closed with 0Ohm, R8 open for shield 2. Also connect the chip select pin for the second board as set in
 * tle94112-platf-psoc6hal.hpp.
 * On both controllers a load is connected between half bridge 1 and 5.
 * This example shows, how to control both motor controllers from one Raspberry Pi.
 *
 * \attention THIS EXAMPLE NEEDS TWO STACKED MULTI_HALF_BRIDGES WITH SEPERATE CHIPSELECT PINS
 *
 * SPDX-License-Identifier: MIT
 */

/* Infineon library for multi-half-bridge and motor control */
#include "multipleControllers.hpp"

void multipleControllers(uint8_t bridges) {
	printf("[multi-half-bridge] : setup begin\n");

	// Tle94112 Object for HATs 1 (CS0, default) and 2 (CS1)
	Tle94112Psoc6hal controller1 = Tle94112Psoc6hal();
	Tle94112Psoc6hal controller2 = Tle94112Psoc6hal(TLE94112_PIN_CS2);

	// Tle94112Motor Objects
	Tle94112Motor motor1(controller1);
	Tle94112Motor motor2(controller2);

	// Enable MotorController Tle94112
	// Note: Required to be done before starting to configure the motor
	// Begin SPI communication with controller 1
	printf("[multi-half-bridge] : controller 1 begin\n");
	controller1.begin();

	// Clear all errors to start clean
	controller1.clearErrors();

	// Connect motor1 to HB1 and HB5 of controller 1
	motor1.connect(motor1.HIGHSIDE, controller1.TLE_HB1);
	motor1.connect(motor1.LOWSIDE, controller1.TLE_HB5);
	motor1.setPwm(motor1.LOWSIDE, controller1.TLE_NOPWM);
	printf("[multi-half-bridge] : motor init 1 on shield 1, with 2 half-bridges\n");

	// Begin SPI communication with controller 2 (ends communication with controller 1)
	printf("[multi-half-bridge] : controller 2 begin\n");
	controller2.begin();

	// Clear all errors to start clean
	controller2.clearErrors();

	// Connect motor2 to HB1 and HB5 of controller 2
	motor2.connect(motor2.HIGHSIDE, controller2.TLE_HB1);
	motor2.connect(motor2.LOWSIDE, controller2.TLE_HB5);
	motor2.setPwm(motor2.LOWSIDE, controller2.TLE_NOPWM);
	printf("[multi-half-bridge] : motor init 2 on shield 2, with 2 half-bridges\n");

	for (;;) {

		// Run motor 1 (connected to controller 1)
		printf("Start motor on controller 1.\n");
		motor1.begin();
		motor1.start(255);

		cyhal_system_delay_ms(2000);

		// Run motor 2 (connected to controller 2)
		printf("Start motor on controller 2.\n");
		motor2.begin();
		motor2.start(255);

		cyhal_system_delay_ms(5000);

		// Stop both motors
		printf("Stop both motors.\n");
		motor2.stop(255);
		motor1.stop(255);

	}
}
