/*!
 * \name        directRegisterControl
 * \author      Infineon Technologies AG
 * \copyright   2025 Infineon Technologies AG
 * \brief       This example demonstrates how to control two motors via direct register setting
 * \details
 * If motors are connected to the TLE94112 on certain half bridges, than they can be controlled via direct register
 * setting which reduces greatly the overhead and allows fast motor controlling.
 * therefore the half bridges HB1 to HB4, HB5 to HB8 and HB9 to HB12 must be used together, either for controlling
 * two motors on one tuple (0.9 A), or one motor on one tuple (1.8 A).
 *
 * SPDX-License-Identifier: MIT
 *
 */

 #include <tle94112-ino.hpp>

 //! Tle94112 Object
 Tle94112Ino controller = Tle94112Ino();
 
 //! Tle94112 registers for motor 1 and 2
 uint8_t motor[2][2] = {
   {REG_ACT_1, REG_PWM_DC_1},
   {REG_ACT_3, REG_PWM_DC_3}
 };
 
 //! Tle94112 register for motor direction
 volatile uint8_t oldDirection [] = { LL_HH, HH_LL };
 
 /**
  * @brief Changes the motor direction and speed
  * The motor direction is set by the change of the High/Low switching of the motor half bridges in one register.
  * This needs some time to change the direction, so its avoided if not needed.
  * Setting the speed is done by setting the PWM register.
  *
  * @param motorNum uint8_t motor number (0 or 1)
  * @param dir uint8_t direction (HH_LL or LL_HH for forward/backward of one motor on four half bridges)
  * @param speed uint8_t speed (0-255)
  * @param errorCheck bool if true, the error register is cleared after setting the speed
  */
 void motorSet(uint8_t motorNum, uint8_t dir, uint8_t speed, bool errorCheck = false)
 {
   if (dir != oldDirection[motorNum]) {
     controller.directWriteReg(motor[motorNum][0], dir);
     oldDirection[motorNum] = dir;
   }
   controller.directWriteReg(motor[motorNum][1], speed);
   if (errorCheck) {
     controller.clearErrors();
   }
 }
 
 
 //! connect motor between halfbridge 1 and halfbridge 2
 void setup()
 {
 
   Serial.begin(9600);
   while (!Serial) {
     ; // wait for serial port to connect. Needed for native USB port only
   }
   Serial.println("TLE94112 Motor Speed Control Example");
   delay(1000);
 
   // Enable MotorController Tle94112
   // Note: Required to be done before starting to configure the motor
   controller.begin();
 
   // four half bridges and two PWM channels are used to control two motors
   controller.configHB(controller.TLE_HB1, controller.TLE_HIGH, controller.TLE_PWM1);
   controller.configHB(controller.TLE_HB2, controller.TLE_HIGH, controller.TLE_PWM1);
   controller.configHB(controller.TLE_HB3, controller.TLE_LOW,  controller.TLE_NOPWM);
   controller.configHB(controller.TLE_HB4, controller.TLE_LOW,  controller.TLE_NOPWM);
 
   controller.configHB(controller.TLE_HB9,  controller.TLE_HIGH, controller.TLE_PWM3);
   controller.configHB(controller.TLE_HB10, controller.TLE_HIGH, controller.TLE_PWM3);
   controller.configHB(controller.TLE_HB11, controller.TLE_LOW,  controller.TLE_NOPWM);
   controller.configHB(controller.TLE_HB12, controller.TLE_LOW,  controller.TLE_NOPWM);
 
   // all stop
   controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ200HZ, 0);
   controller.configPWM(controller.TLE_PWM3, controller.TLE_FREQ200HZ, 0);
   controller.clearErrors();
 
   delay(1000);
 
 }
 
 
 void loop() {
   controller.clearErrors();
 
   Serial.println("forward / backward");
   motorSet(0, HH_LL, 100);
   motorSet(1, LL_HH, 100);
   delay(1000);
 
   Serial.println(" speed up / down");
   motorSet(0, HH_LL, 255);
   motorSet(1, LL_HH, 50);
   delay(1000);
 
   Serial.println("backward / forward ");
   motorSet(0, LL_HH, 255);
   motorSet(1, HH_LL, 255);
   delay(1000);
 
 }
