# 1 "C:\\Users\\ederjuli\\AppData\\Local\\Temp\\tmp9j3m8pr3"
#include <Arduino.h>
# 1 "C:/Users/ederjuli/Documents/Projects/2010-PiHAT-TLE94112/dc-motor-control-tle94112el/examples/basicTest/basicTest.ino"
# 16 "C:/Users/ederjuli/Documents/Projects/2010-PiHAT-TLE94112/dc-motor-control-tle94112el/examples/basicTest/basicTest.ino"
#include <tle94112-ino.hpp>
#include <tle94112-motor-ino.hpp>
#include "SPI.h"


Tle94112Ino controller = Tle94112Ino();


Tle94112Motor motor(controller);
void setup();
void loop();
#line 26 "C:/Users/ederjuli/Documents/Projects/2010-PiHAT-TLE94112/dc-motor-control-tle94112el/examples/basicTest/basicTest.ino"
void setup()
{

  Serial.begin(115200);
  while (!Serial)
  {};




  controller.begin();




  motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
  motor.initConnector(motor.LOWSIDE, controller.TLE_PWM1, controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);


  motor.begin();


  Serial.println("Init ready");
}

void loop()
{

  motor.coast();
  delay(1000);


  Serial.println("max forward/backward");
  motor.start(255);
  delay(1000);
  motor.coast();
  delay(1000);
  motor.start(-255);
  delay(1000);
  motor.coast();
  delay(1000);


  Serial.println("ramp ripple forward/backward");
  motor.start(255);
  delay(1000);
  motor.rampSpeed(0, 5000);
  delay(1000);
  motor.start(-255);
  delay(1000);
  motor.rampSpeed(0, 5000);
  delay(1000);


  Serial.println("ramp up/down forward");
  motor.start(50);
  motor.rampSpeed(255, 5000);
  delay(1000);
  motor.rampSpeed(100, 5000);
  delay(1000);
  motor.rampSpeed(255, 5000);
  delay(1000);
  motor.rampSpeed(0, 5000);


  Serial.println("ramp up/down backward");
  motor.start(50);
  motor.rampSpeed(-255, 5000);
  delay(1000);
  motor.rampSpeed(-100, 5000);
  delay(1000);
  motor.rampSpeed(-255, 5000);
  delay(1000);
  motor.rampSpeed(0, 5000);


  Serial.println("ramp transient");
  motor.rampSpeed(-255, 1000);
  delay(1000);
  motor.rampSpeed(255, 1000);
  delay(1000);
  motor.rampSpeed(-255, 1000);
  delay(1000);
  motor.rampSpeed(0, 1000);
  delay(1000);


  Serial.println("stop and coast");
  motor.stop(255);
  delay(1000);
  motor.coast();
  delay(1000);
}