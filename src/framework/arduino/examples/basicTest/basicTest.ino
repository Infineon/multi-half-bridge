/*!
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 shield
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 * Take this example as a first test when starting with this shield.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include <tle94112-ino.hpp>
#include <tle94112-motor-ino.hpp>
#include "SPI.h"

// Tle94112 Object on Shield 1
Tle94112Ino controller = Tle94112Ino();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);

void setup()
{
  // Switch on communications
  Serial.begin(115200);
  while (!Serial)
  {};

  // Enable MotorController on all Shields and Motors
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS1 pin
  controller.begin();

  // Connect a motor to HB1/HB2 highside and HB3/HB4 lowside
  // With two combined halfbridges the motor can have up to 1.8 A
  // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
  motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
  motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);

  // start the motor controller
  motor.begin();

  // end the setup function
  Serial.println("Init ready");
}

void loop()
{
  // coast the motor
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
  motor.start(255); // start max forward
  delay(1000);
  motor.rampSpeed(0, 5000); // ramp down to 0
  delay(1000);
  motor.start(-255); // start max backward
  delay(1000);
  motor.rampSpeed(0, 5000); // ramp down to 0
  delay(1000);

  // ramp up/down forward
  Serial.println("ramp up/down forward");
  motor.start(50); // start above 0 to allow motor to start
  motor.rampSpeed(255, 5000); // ramp up to max
  delay(1000);
  motor.rampSpeed(100, 5000); // ramp down
  delay(1000);
  motor.rampSpeed(255, 5000); // ramp up to max
  delay(1000);
  motor.rampSpeed(0, 5000); // ramp down to 0

  // ramp up/down backward
  Serial.println("ramp up/down backward");
  motor.start(50); // start above 0 to allow motor to start
  motor.rampSpeed(-255, 5000); // ramp up to min
  delay(1000);
  motor.rampSpeed(-100, 5000); // ramp up
  delay(1000);
  motor.rampSpeed(-255, 5000); // ramp up to min
  delay(1000);
  motor.rampSpeed(0, 5000); // ramp up to 0

  // ramp transient with a change in rotation direction
  Serial.println("ramp transient");
  motor.rampSpeed(-255, 1000); // ramp down to min
  delay(1000);
  motor.rampSpeed(255, 1000); // ramp up to max
  delay(1000);
  motor.rampSpeed(-255, 1000); // ramp down to min
  delay(1000);
  motor.rampSpeed(0, 1000); // ramp up to 0
  delay(1000);

  // stop and coast
  Serial.println("stop and coast");
  motor.stop(255); // stop and hold with max force
  delay(1000);
  motor.coast();
  delay(1000);
}
