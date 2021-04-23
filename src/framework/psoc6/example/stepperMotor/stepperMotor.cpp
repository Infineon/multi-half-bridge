/*!
 * \name        stepperMotor
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
 * \details
 * The multi half bridge TLE94112ES is able to drive voltage controlled bipolar stepper motors.
 * This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
 *
 * SPDX-License-Identifier: MIT
 */

#include "stepperMotor.hpp"

class BipolarStepper {
  public:
    enum direction
		{
			FORWARD = 0,
			BACKWARD
		};
    Tle94112 *mDriver;
    Tle94112::HalfBridge hb_a1, hb_a2, hb_b1, hb_b2;
    int8_t state = 0;
    BipolarStepper(Tle94112 &mDriver, Tle94112::HalfBridge a1, Tle94112::HalfBridge a2, Tle94112::HalfBridge b1, Tle94112::HalfBridge b2) {
      this->mDriver = &mDriver;
      hb_a1 = a1;
      hb_a2 = a2;
      hb_b1 = b1;
      hb_b2 = b2;
    }
    void disableOutputs() {
      mDriver->configHB(hb_a1, mDriver->TLE_FLOATING, mDriver->TLE_NOPWM);
      mDriver->configHB(hb_a2, mDriver->TLE_FLOATING, mDriver->TLE_NOPWM);
      mDriver->configHB(hb_b1, mDriver->TLE_FLOATING, mDriver->TLE_NOPWM);
      mDriver->configHB(hb_b2, mDriver->TLE_FLOATING, mDriver->TLE_NOPWM);
    }
    void fullStep(BipolarStepper::direction dir) {
      switch(state) {
        case 0:
          mDriver->configHB(hb_a1, mDriver->TLE_HIGH, mDriver->TLE_NOPWM);
          mDriver->configHB(hb_a2, mDriver->TLE_LOW, mDriver->TLE_NOPWM);
          break;
        case 1:
          mDriver->configHB(hb_b1, mDriver->TLE_HIGH, mDriver->TLE_NOPWM);
          mDriver->configHB(hb_b2, mDriver->TLE_LOW, mDriver->TLE_NOPWM);
          break;
        case 2:
          mDriver->configHB(hb_a2, mDriver->TLE_HIGH, mDriver->TLE_NOPWM);
          mDriver->configHB(hb_a1, mDriver->TLE_LOW, mDriver->TLE_NOPWM);
          break;
        case 3:
          mDriver->configHB(hb_b2, mDriver->TLE_HIGH, mDriver->TLE_NOPWM);
          mDriver->configHB(hb_b1, mDriver->TLE_LOW, mDriver->TLE_NOPWM);
          break;
      }
      if (dir == FORWARD) state++;
      if (dir == BACKWARD) state--;
      if (state < 0) state = 3;
      if (state > 3) state = 0;
    }
};

// Set 200 steps per motor revolution (usual for many stepper motors).
// Please change if your motor has a different number of steps per revolution.
uint16_t steps_per_rev = 200;

void stepperMotor()
{
	printf("[multi-half-bridge] : setup begin\n");

	/* pointer to the multi-half-bridge controller */
	Tle94112Psoc6hal controller;

	// Enable MotorController.
	// Note: Required to be done before starting to configure the motor
	// controller is set to default CS0 pin.
	printf("[multi-half-bridge] : controller begin\n");
	controller.begin();

	// Clear all errors to start clean
	controller.clearErrors();

	// Create object from BipolarStepper class to control bipolar stepper motors.
	// First argument is the motor controller, following arguments are coil A high side,
	// coil A low side, coil B high side, coil B low side.
	printf("[multi-half-bridge] : set bipolar stepper\n");
	BipolarStepper stepper(controller, controller.TLE_HB1, controller.TLE_HB5, controller.TLE_HB7, controller.TLE_HB9);

	// Turn the motor for one revolution.
	for (uint16_t i = 0; i < steps_per_rev; i++) {
		stepper.fullStep(stepper.FORWARD);
		cyhal_system_delay_ms(1000/steps_per_rev); // Take 1000ms for one revolution.
	}

	// Disable the outputs. Will release any forces from the motor.
	// REQUIRED, otherwise the motor becomes hot.
	printf("[multi-half-bridge] : set output to floating\n");
	stepper.disableOutputs();
}
