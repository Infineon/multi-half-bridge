#include <TLE94112.h>

// Tle94112 Object
Tle94112 controller = Tle94112();

#define pinDir    5
#define pinSpeed  A0
//connect motor between halfbridge 1 and halfbridge 2


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