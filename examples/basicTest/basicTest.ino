/*!
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.4.1
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 shield
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include <TLE94112-ino.hpp>
#include <TLE94112Motor-ino.hpp>
#include "SPI.h"

// Tle94112 Object on Shield 1
Tle94112Ino controller = Tle94112Ino();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);

void setup()
{
  Serial.begin(115200); // Switch on communications
  while (!Serial)
  {
  };

  // Enable MotorController on all Shields and Motors
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS1 pin
  controller.begin();

  //-Motor1-high current motor between out1/out2 = HB1/HB2 and out3/out4 = HB3/HB4

  // Connect motor to HB1/HB2 highside and HB3/HB4 lowside
  // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
  motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
  motor.initConnector(motor.LOWSIDE, controller.TLE_PWM1, controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);

  // start motor
  motor.begin();

  Serial.println("Init ready");
}

void loop()
{

  motor.coast();
  delay(1000);

  // max forward/backward
  Serial.println("max forward/backward");
  motor.start(255);
  delay(1000);
  motor.coast();
  delay(1000);
  motor.start(-255);
  delay(1000);
  motor.coast();
  delay(1000);

  // ramp ripple forward/backward
  Serial.println("ramp ripple forward/backward");
  motor.start(255);
  delay(1000);
  motor.rampSpeed(0, 5000);
  delay(1000);
  motor.start(-255);
  delay(1000);
  motor.rampSpeed(0, 5000);
  delay(1000);

  // ramp up/down forward
  Serial.println("ramp up/down forward");
  motor.start(50); // start above 0 to allow motor to start
  motor.rampSpeed(255, 5000);
  delay(1000);
  motor.rampSpeed(100, 5000);
  delay(1000);
  motor.rampSpeed(255, 5000);
  delay(1000);
  motor.rampSpeed(0, 5000);

  // ramp up/down backward
  Serial.println("ramp up/down backward");
  motor.start(50);
  motor.rampSpeed(-255, 5000);
  delay(1000);
  motor.rampSpeed(-100, 5000);
  delay(1000);
  motor.rampSpeed(-255, 5000);
  delay(1000);
  motor.rampSpeed(0, 5000);

  // ramp transient
  Serial.println("ramp transient");
  motor.rampSpeed(-255, 1000);
  delay(1000);
  motor.rampSpeed(255, 1000);
  delay(1000);
  motor.rampSpeed(-255, 1000);
  delay(1000);
  motor.rampSpeed(0, 1000);
  delay(1000);

  // stop and coast
  Serial.println("stop and coast");
  motor.stop(255);
  delay(1000);
  motor.coast();
  delay(1000);
}
