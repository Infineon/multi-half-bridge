#include <TLE94112.h>
#include <Tle94112Motor.h>


// Tle94112 Object on Shiled 1
Tle94112 controller1 = Tle94112();

// Tle94112Motor Objects on controller1
Tle94112Motor motor1(controller1);


typedef struct {
  int16_t startspeed;
  int16_t endspeed;
  uint16_t slope;
} RampMeasurement_t, *RampMeasurement_p;

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

  motor1.setSpeed( testcases[index].startspeed );
  delay(100);

  uint32_t duration = millis();
  motor1.rampSpeed( testcases[index].endspeed, testcases[index].slope);
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
  // put your main code here, to run repeatedly:
  for( int i=0; i<NUM_TESTS; i++)
  {
    measureRampTime(i);
  }
}