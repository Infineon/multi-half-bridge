#include <TLE94112.h>
#include <TLE94112_Motor.h>

// The TLE94112 has only got 3 PWM channels
// There is no one left for motor4
// This means, we cannot control its speed
Tle94112Motor motor1(tle94112, tle94112.TLE_PWM1);
Tle94112Motor motor2(tle94112, tle94112.TLE_PWM2);
Tle94112Motor motor3(tle94112, tle94112.TLE_PWM3);
Tle94112Motor motor4(tle94112, tle94112.TLE_NOPWM);


void setup()
{
  // call begin for the TLE94112 firs
  tle94112.begin();
  // motor1 is connected to 2 halfbridges on each side
  motor1.connect(tle94112.TLE_HB1, motor1.HIGHSIDE);
  motor1.connect(tle94112.TLE_HB2, motor1.HIGHSIDE);
  motor1.connect(tle94112.TLE_HB3, motor1.LOWSIDE);
  motor1.connect(tle94112.TLE_HB4, motor1.LOWSIDE);

  // motor2 is only connected on its highside connector
  // the lowside connector is not connected to the TLE94112. 
  // The library assumes it is connected to ground. 
  // This means, the motor can only run forward
  motor2.connect(tle94112.TLE_HB5, motor2.HIGHSIDE);

  // motor3 is only connected on its lowside connector
  // the highside connector is not connected to the TLE94112. 
  // The library assumes it is connected to Vbat
  // This means, the motor can only run forward
  motor3.connect(tle94112.TLE_HB6, motor3.HIGHSIDE);

  // motor4 is connected to 1 halfbridge on each side
  motor4.connect(tle94112.TLE_HB7, motor4.HIGHSIDE);
  motor4.connect(tle94112.TLE_HB8, motor4.LOWSIDE);

  //change the motors PWM frequency (just in case you will ever need it...)
  motor3.setPwmFreq(tle94112.TLE_FREQ80HZ);

  //when configuration is done, call begin to start operating the motors
  motor1.begin();
  motor2.begin();
  motor3.begin();
  motor4.begin();
  //after calling begin(), the motors are coasting. 
  
}



void loop()
{
  // start the motor and let it run backwards on half speed
  motor1.start(-127);
  //motors 2 and 3 can only run forward. If you let them run backward, they will stop instead
  motor2.start(127);
  motor3.start(-127);
  //motor 4 can not be controlled by PWM. It can only coast, stop and run with full speed. 
  motor4.start(127);

  delay(5000);

  //accelerate motor1 to full speed
  motor1.setSpeed(-255);
  //set motor2 free
  motor2.coast();
  //let motor4 actively break (it will stop much faster than motor2)
  motor4.stop();

  delay(5000);

  //stop all motors (you can use the parameter to set the force which stops and holds them. standard and maximum is 255)
  motor1.stop(255);
  motor2.stop(20);
  motor3.stop(127);
  motor4.stop(127);

  delay(5000);

  //motor1 and motor4 can also run the other way
  motor1.start(127);
  motor4.start(-127);

  delay(5000);

  //ok, that was enough
  motor1.stop();
  motor4.stop();

  delay(5000);
}
