#include <TLE94112.h>

#define pinDir    5
#define pinSpeed  A1
//connect motor between halfbridge 1 and halfbridge 2


void setup() {
  //power supply voltage should be available before tle94112.begin() is called
  delay(100);
  //enable tle94112
  tle94112.begin();

  pinMode(pinDir, INPUT);
  pinMode(pinSpeed, INPUT);
}


void loop() {
  //get desired direction from digital pin
  int dir = digitalRead(pinDir);
  if(dir == HIGH)
  {
    tle94112.configHB(tle94112.TLE_HB1, tle94112.TLE_HIGH, tle94112.TLE_PWM1);
    tle94112.configHB(tle94112.TLE_HB2, tle94112.TLE_LOW, tle94112.TLE_NOPWM);
  }
  else
  {
    tle94112.configHB(tle94112.TLE_HB1, tle94112.TLE_LOW, tle94112.TLE_NOPWM);
    tle94112.configHB(tle94112.TLE_HB2, tle94112.TLE_HIGH, tle94112.TLE_PWM1);
  }
  
  //get desired motor speed from analog input
  int dc = analogRead(pinSpeed) >> 2;
  //update motor speed
  tle94112.configPWM(tle94112.TLE_PWM1, tle94112.TLE_FREQ80HZ, dc);
}