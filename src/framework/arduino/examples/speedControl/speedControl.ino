/*!
 * \name        speedControl
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example demonstrates how to control the speed of motor by using the PWM units of the TLE94112 shield
 * \details
 * Attaching a potentiometer on an analog input pin, which will than control the
 * setting of the TLE94112 internal PWM unit and therefore the speed of the motor.
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

//! Select pins for speed and direction settings
#define pinDir    5
#define pinSpeed  A0

//! connect motor between halfbridge 1 and halfbridge 2
void setup() 
{
  // Enable MotorController Tle94112
  // Note: Required to be done before starting to configure the motor
  controller.begin();

  pinMode(pinDir, INPUT);
  pinMode(pinSpeed, INPUT);
}


void loop() {
  // get desired direction from digital pin
  uint8_t dir = digitalRead(pinDir);
  if(dir == HIGH)
  {
    controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_PWM1);
    controller.configHB(controller.TLE_HB2, controller.TLE_LOW, controller.TLE_NOPWM);
  }
  else
  {
    controller.configHB(controller.TLE_HB1, controller.TLE_LOW, controller.TLE_NOPWM);
    controller.configHB(controller.TLE_HB2, controller.TLE_HIGH, controller.TLE_PWM1);
  }

  // get desired motor speed from analog input
  uint8_t dc = analogRead(pinSpeed) >> 2;

  // update motor speed
  controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ80HZ, dc);
}
