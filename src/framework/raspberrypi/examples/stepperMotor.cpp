  
/*!
 * \name        stepperMotor
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
 * \details
 * The multi half bridge TLE94112ES is able to drive voltage controlled bipolar stepper motors.
 * This example shows how to control a stepper motor with the DC Motor Control HAT with TLE94112ES.
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

/* 3rd party libraries for this example */
#include <bcm2835.h> // This library is required for the delay() function.

void step(uint32_t steps) {
  for (uint32_t step = 0; step < steps; step++) {

  }
}

class BipolarStepper {
  public:
    enum direction
		{
			DIR_FORWARD = 0,
			DIR_BACKWARD
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
      if (dir == DIR_FORWARD) state++;
      if (dir == DIR_BACKWARD) state--;
      if (state < 0) state = 3;
      if (state > 3) state = 0;
    }
};

// Set 200 steps per motor revision (usual for many stepper motors).
uint16_t steps_per_rev = 200;

int main(int argc, char const *argv[])
{
  // Create a Tle94112Rpi instance for each motor controller.
  Tle94112Rpi controller;

  // Enable MotorController.
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS0 pin.
  controller.begin();

  // Clear all errors to start clean
  controller.clearErrors();

  // Create object from BipolarStepper class to control bipolar stepper motors.
  // First argument is the motor controller, following arguments are coil A high side,
  // coil A low side, coil B high side, coil B low side.
  BipolarStepper stepper(controller, controller.TLE_HB1, controller.TLE_HB5, controller.TLE_HB7, controller.TLE_HB9);

  // Turn the motor for one revision.
  for (uint16_t i = 0; i < steps_per_rev; i++) {
    stepper.fullStep(stepper.DIR_FORWARD);
    delay(1000/steps_per_rev); // Take 1000ms for one revision.
  }

  // Disable the outputs. Will release any forces from the motor.
  // REQUIRED, otherwise the motor becomes hot.
  stepper.disableOutputs();
}

#endif /** TLE94112_FRAMEWORK **/
