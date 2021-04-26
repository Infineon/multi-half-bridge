/*!
 * \name        halfBridge
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to control the independent half bridges of the multi half bridge ICs.
 * \details
 * The example shows how to control the half bridges to switch generic loads.
 *
 * SPDX-License-Identifier: MIT
 */

#include "halfBridge.hpp"

/*
 * As this library works with multiple frameworks,
 * this part is needed to avoid trying to compile
 * this example from other frameworks.
 */
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

void halfBridge()
{
	printf("[multi-half-bridge] : setup begin\n");

	/* pointer to the multi-half-bridge controller */
	Tle94112Psoc6hal controller;

	// controller is set to default CS0 pin.
	printf("[multi-half-bridge] : controller begin\n");
	controller.begin();

	// Clear all errors to start clean
	controller.clearErrors();

	// Set PWM channel 1 to 200 KHz and 50% duty cycle.
	controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ200HZ, 127);

	// Set half bridge 1 to high (V_bat) without PWM.
	controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_NOPWM);

	// Set half bridge 5 to low (GND) and connect it to PWM channel 1.
	controller.configHB(controller.TLE_HB5, controller.TLE_LOW, controller.TLE_PWM1);
	printf("[multi-half-bridge] : set half bridge 5 to low (GND) and connect it to PWM channel 1\n");

	cyhal_system_delay_ms(3000);

	// Set PWM channel 1 to 100% duty cycle.
	printf("[multi-half-bridge] : set PWM channel 1 to full duty cycle\n");
	controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ200HZ, 127);

	cyhal_system_delay_ms(3000);

	// Set both outputs to floating.
	printf("[multi-half-bridge] : set both outputs to floating\n");
	controller.configHB(controller.TLE_HB1, controller.TLE_FLOATING, controller.TLE_NOPWM);
	controller.configHB(controller.TLE_HB5, controller.TLE_FLOATING, controller.TLE_NOPWM);
}

#endif /** TLE94112_FRAMEWORK **/