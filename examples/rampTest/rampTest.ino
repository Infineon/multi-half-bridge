/*!
 * \name        rampTest
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.4.1
 * \brief
 * This example to run a motor with the rampSpeed function
 * \details
 * This example also demonstrats how to attach a bigger motor on 4 halfbridges with a total 
 * current of 1.8 A. Originally designed to test Lego (R) Powerfunktions or Mindstorm motors,
 * this sketch can be used to simply run a motor smoothly with different speeds
 * in different directions.
 *
 */

#include <TLE94112.h>
#include <Tle94112Motor.h>
/*
 ============================================================================
 Name        : Lego Robot III
 Author      : Dr. Olaf Filies, Marcus Gordon Filies
 Version     : 0.9
 Description : ramping the motor speed of a high current motor
 ============================================================================
 */

// Tle94112 Object on Shield 1
Tle94112 controller1 = Tle94112();

// Tle94112Motor Objects on controller1
Tle94112Motor motor1(controller1);


void setup() {
  Serial.begin(115200);     // Switch on communications
  Serial.println("Init ready");

  // Enable MotorController on all Shields and Motors
  // Note: Required to be done before starting to configure the motor
  // controller1 is set to default CS1 pin
  controller1.begin();

  //-Motor1-high current motor between out1/out2 = HB1/HB2 and out3/out4 = HB3/HB4-------------------
 
  // Connect motor1 to HB1/HB2 highside and HB3/HB4 lowside
  // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
  motor1.initConnector(motor1.HIGHSIDE, controller1.TLE_NOPWM, controller1.TLE_HB1, controller1.TLE_HB2, controller1.TLE_NOHB, controller1.TLE_NOHB);
  motor1.initConnector(motor1.LOWSIDE, controller1.TLE_PWM1, controller1.TLE_HB3, controller1.TLE_HB4, controller1.TLE_NOHB, controller1.TLE_NOHB);

  // start motor1
  motor1.begin();
}

void loop() {

  motor1.coast();
  delay(1000);

// max forward/backward
  Serial.println("max forward/backward");
  motor1.start(255);
  delay(1000);
  motor1.coast();
  delay(1000);
  motor1.start(-255);
  delay(1000);
  motor1.coast();
  delay(1000);

// ramp ripple forward/backward    
  Serial.println("ramp ripple forward/backward");
  motor1.start(255);
  delay(1000);
  motor1.rampSpeed(0,5000);
  delay(1000);
  motor1.start(-255);
  delay(1000);
  motor1.rampSpeed(0,5000);
  delay(1000);

// ramp up/down forward
  Serial.println("ramp up/down forward");
  motor1.start(50); // start above 0 to allow motor to start
  motor1.rampSpeed(255,5000);
  delay(1000);
  motor1.rampSpeed(100,5000);
  delay(1000);
  motor1.rampSpeed(255,5000);
  delay(1000);
  motor1.rampSpeed(0,5000);
  
// ramp up/down backward
  Serial.println("ramp up/down backward");
  motor1.start(50);
  motor1.rampSpeed(-255,5000);
  delay(1000);
  motor1.rampSpeed(-100,5000);
  delay(1000);
  motor1.rampSpeed(-255,5000);
  delay(1000);
  motor1.rampSpeed(0,5000);

// ramp transient
  Serial.println("ramp transient");
  motor1.rampSpeed(-255,1000);
  delay(1000);
  motor1.rampSpeed(255,1000);
  delay(1000);
  motor1.rampSpeed(-255,1000);
  delay(1000);
  motor1.rampSpeed(0,1000);
  delay(1000);

// stop and coast
  Serial.println("stop and coast");
  motor1.stop(255);
  delay(1000);
  motor1.coast();
  delay(1000);
  

}
