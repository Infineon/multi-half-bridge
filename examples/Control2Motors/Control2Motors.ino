#include <TLE94112.h>
#include <Tle94112Motor.h>

// Tle94112 Object
Tle94112 controller = Tle94112();

// Tle94112Motor Objects
Tle94112Motor motor1(controller);
Tle94112Motor motor2(controller);


void setup()
{
  // Enable MotorController Tle94112
  // Note: Required to be done before starting to configure the motor
  controller.begin();
  
  // Connect motor1 to HB1 and HB3
  motor1.connect(motor1.HIGHSIDE, controller.TLE_HB1);
  motor1.connect(motor1.LOWSIDE, controller.TLE_HB3);

  // Drive HB1 with signal from PWM1
  // Note: This allows to control the speed of the motor
  motor1.setPwm(motor1.HIGHSIDE, controller.TLE_PWM1);

  // Set PWM Frequency, default is 80 Hz
  motor1.setPwmFreq(motor1.HIGHSIDE, controller.TLE_FREQ100HZ);
   
  // Connect motor2 to HB2 and HB4
  motor2.connect(motor2.HIGHSIDE, controller.TLE_HB2);
  motor2.connect(motor2.LOWSIDE, controller.TLE_HB4);

  // Drive HB2 with signal from PWM2
  // Note: This allows to control the speed of the motor
  motor2.setPwm(motor2.HIGHSIDE, controller.TLE_PWM2);

  //when configuration is done, call begin to start operating the motors
  motor1.begin();
  motor2.begin();
  
  //after calling begin(), the motors are coasting. 
}



void loop()
{
  // start the motor1 forwards on half speed
  motor1.start(127);
  // start the motor3 backwards on half speed
  motor2.start(-127);

  delay(5000);

  // accelerate motor1 to full speed
  motor1.setSpeed(255);
  // stop motor2
  motor2.stop();

  delay(5000);

  // reduce speed of motor1
  motor1.setSpeed(127);
  
  delay(1000);
  
  // let motor1 turn backwards on half speed
  motor1.setSpeed(-127);
  
  delay(1000);
  
  // accelerate motor1 to full speed backwards
  motor1.setSpeed(-255);
  
  delay(5000);

  //stop motor1 (you can use the parameter to set the force which stops and holds them. standard and maximum is 255)
  motor1.stop(255);

  delay(5000);
}