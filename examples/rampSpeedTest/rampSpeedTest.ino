/*!
 * \name        rampSpeedTest
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This example measure the rampspeed of an attached motor with the TLE94112 shield
 * \details
 * By attaching a motor to the TLE94112 and running a testcase scenario, we can measure the
 * optimal values for the rampSpeed function. This function allows us to smoothly start, stop,
 * raise or break the motor.
 * 
 * \attention A free running motor ramps very different than the same motor with load attached.
 * So you have to measure different scenarios.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include <TLE94112-ino.hpp>
#include <TLE94112Motor-ino.hpp>


// Tle94112 Object on Shield 1
Tle94112 controller = Tle94112();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);

// a structure with the measured values
typedef struct {
  int16_t startspeed;
  int16_t endspeed;
  uint16_t slope;
} RampMeasurement_t, *RampMeasurement_p;

// lets define an array with different tests
#define NUM_TESTS 6
RampMeasurement_t testcases[NUM_TESTS] = {
  { 0,    255,  5000 },
  { 255,  200,  10000 },
  { 200,  0,    500 },
  { 0,    -255, 10 },
  { -255, 255,  3000 },
  { 255,  0,    1000 }
};


void measureRampTime(int index)
{
  Serial.print("Test ");
  Serial.print(index);
  Serial.print(": \t");
  Serial.print(testcases[index].startspeed);
  Serial.print(" -> ");
  Serial.print(testcases[index].endspeed);
  int32_t expected = (abs(testcases[index].endspeed - testcases[index].startspeed) * (int32_t)(testcases[index].slope)) / 255;
  Serial.print(" \tExpected: ");
  Serial.print(expected);
  Serial.println(" ms");

  motor.setSpeed( testcases[index].startspeed );
  delay(100);

  uint32_t duration = millis();
  motor.rampSpeed( testcases[index].endspeed, testcases[index].slope);
  duration = millis() - duration;

  Serial.print("Measured: ");
  Serial.print(duration);
  Serial.println(" ms");
}


void setup() {
  Serial.begin(115200);     // Switch on comunication
  Serial.println("Init ready");

  // Enable MotorController on all Shields and Motors
  // Note: Required to be done before starting to configure the motor
  // controller is set to default CS1 pin
  controller.begin();

  //-Motor1-high current motor between out1/out2 = HB1/HB2 and out3/out4 = HB3/HB4

  // Connect motor to HB1/HB2 highside and HB3/HB4 lowside
  // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
  motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_FREQ100HZ,controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
  motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_FREQ100HZ,controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);

  // start motor
  motor.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  for( int i=0; i<NUM_TESTS; i++)
  {
    measureRampTime(i);
  }
}
