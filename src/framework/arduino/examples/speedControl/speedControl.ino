/*!
 * \name        speedControl
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example demonstrates how to control the speed of motor by using the PWM units of the TLE94112 shield
 * \details
 * Ramping the speed of the motor up and down by using PWM signals.
 * The TLE94112 has three separate PWM units which can be attached to any combination
 * of halfbridges. So try out to change the TLE_PWM1 to TLE_PWM2 or TLE_PWM3 to see this.
 * You can change the motor direction by changing the HIGH/LOW status of the halfbridges
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include <tle94112-ino.hpp>

//! Tle94112 Object
Tle94112Ino controller = Tle94112Ino();

//! connect motor between halfbridge 1 and halfbridge 2
void setup() 
{
  // Enable MotorController Tle94112
  // Note: Required to be done before starting to configure the motor
  controller.begin();
}


void loop() {

  /* Configure the motor to use PWM with a duty cycle of 0% and forward direction. */
  controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ80HZ, 0);
  controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_PWM1);
  controller.configHB(controller.TLE_HB2, controller.TLE_LOW, controller.TLE_NOPWM);

  /* Ramp up duty cycle from 0% to 100%. */
  for (uint8_t speed = 0; speed < 255; speed++)
  {
    controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ80HZ, speed);
    delay(10);
  }

  /* Configure the motor to use PWM with a duty cycle of 0% and backward direction. */
  controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ80HZ, 0);
  controller.configHB(controller.TLE_HB1, controller.TLE_LOW, controller.TLE_NOPWM);
  controller.configHB(controller.TLE_HB2, controller.TLE_HIGH, controller.TLE_PWM1);

  /* Ramp up duty cycle from 0% to 100%. */
  for (uint8_t speed = 0; speed < 255; speed++)
  {
    controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ80HZ, 255-speed);
    delay(10);
  }

}