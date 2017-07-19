#include <TLE94112.h>


void setup() {
  int dc = 100;
  //Serial for debug output
  Serial.begin(9600);
  while(!Serial);


  //power supply voltage should be available before tle94112.begin() is called
  delay(100);
  //enable tle94112
  tle94112.begin();

  /*
  //update motor speed
  //three different frequencies are shown on oscilloscope
  tle94112.configPWM(tle94112.TLE_PWM1, tle94112.TLE_FREQ80HZ, dc);
  tle94112.configPWM(tle94112.TLE_PWM2, tle94112.TLE_FREQ100HZ, dc);
  tle94112.configPWM(tle94112.TLE_PWM3, tle94112.TLE_FREQ200HZ, dc);
  */

  //halfbridges for outputting HIGH or PWM
  tle94112.configHB(tle94112.TLE_HB1, tle94112.TLE_HIGH, tle94112.TLE_PWM1);
  tle94112.configHB(tle94112.TLE_HB2, tle94112.TLE_HIGH, tle94112.TLE_PWM2);
  tle94112.configHB(tle94112.TLE_HB3, tle94112.TLE_HIGH, tle94112.TLE_PWM3);
  tle94112.configHB(tle94112.TLE_HB4, tle94112.TLE_HIGH, tle94112.TLE_NOPWM);

  //halfbridges outputting LOW
  tle94112.configHB(tle94112.TLE_HB5, tle94112.TLE_LOW, tle94112.TLE_NOPWM);
  tle94112.configHB(tle94112.TLE_HB6, tle94112.TLE_LOW, tle94112.TLE_NOPWM);
  tle94112.configHB(tle94112.TLE_HB7, tle94112.TLE_LOW, tle94112.TLE_NOPWM);
  tle94112.configHB(tle94112.TLE_HB8, tle94112.TLE_LOW, tle94112.TLE_NOPWM);

  //halfbridges floating / inactive
  tle94112.configHB(tle94112.TLE_HB9, tle94112.TLE_FLOATING, tle94112.TLE_NOPWM);
  tle94112.configHB(tle94112.TLE_HB10, tle94112.TLE_FLOATING, tle94112.TLE_NOPWM);
  tle94112.configHB(tle94112.TLE_HB11, tle94112.TLE_FLOATING, tle94112.TLE_NOPWM);
  tle94112.configHB(tle94112.TLE_HB12, tle94112.TLE_FLOATING, tle94112.TLE_NOPWM);
}

//duty cycle
int dc = 100;

void loop() {
  
  //update dutycycle to show animation on oscilloscope
  dc = (dc + 8) % 255;

  //update motor speed
  //three different frequencies are shown on oscilloscope
  tle94112.configPWM(tle94112.TLE_PWM1, tle94112.TLE_FREQ80HZ, dc);
  tle94112.configPWM(tle94112.TLE_PWM2, tle94112.TLE_FREQ100HZ, dc);
  tle94112.configPWM(tle94112.TLE_PWM3, tle94112.TLE_FREQ200HZ, dc);
  

  //print diagnosis information
  int diagnosis = tle94112.getSysDiagnosis();
  if(diagnosis==tle94112.TLE_STATUS_OK)
  {
    Serial.println("Status: OK");
  }
  else
  {
    Serial.print("Status: Error!     ");
    Serial.println(diagnosis);
    tle94112.clearErrors();
  }

  //let LED blink to show that program is still running
  delay(400);
}
