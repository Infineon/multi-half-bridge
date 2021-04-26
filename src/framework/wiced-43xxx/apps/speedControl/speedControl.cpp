/*!
 * \name        speedControl
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \brief       This example demonstrates how to control the speed of motor by using the PWM units of the TLE94112 shield
 * \details
 * Attaching a potentiometer on an analog input pin, which will than control the
 * setting of the TLE94112 internal PWM unit and therefore the speed of the motor.
 * The TLE94112 has three separate PWM units which can be attached to any combination
 * of halfbridges. So try out to change the TLE_PWM1 to TLE_PWM2 or TLE_PWM3 to see this.
 * You can change the motor direction by changing the HIGH/LOW status of the halfbridges
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "speedControl.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

// Tle94112 Object on Shield 1
Tle94112Wiced controller = Tle94112Wiced();

void setup()
{
    // Enable MotorController on all Shields and Motors
    // Note: Required to be done before starting to configure the motor
    // controller1 is set to default CS1 pin
    WPRINT_APP_INFO(("[TLE94112] : setup begin -> %u\n", 0));
    controller.begin();
    WPRINT_APP_INFO(("[TLE94112] : controller begin -> %u\n", 1));

    wiced_gpio_init(pinDir, INPUT_PULL_UP);
    wiced_adc_init( pinSpeed, pinSpeedTime );
}

void loop()
{
    // get desired direction from digital pin
    wiced_bool_t dir = wiced_gpio_input_get(pinDir);
    if(dir == true)
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
    uint16_t dc; // = analogRead(pinSpeed) >> 2;
    wiced_adc_take_sample(pinSpeed,&dc);
    dc = dc >> 2;

    // update motor speed
    controller.configPWM(controller.TLE_PWM1, controller.TLE_FREQ80HZ, dc);
}



/******************************************************
 *               Function Definitions
 ******************************************************/

void application_start( )
{
  wiced_result_t      result;

  /* Initialize the device */
  result = wiced_init();
  if (result != WICED_SUCCESS)
  {
    return;
  }

  setup();

  while(1)
  {
    loop();
  }
}

#endif /** TLE94112_FRAMEWORK **/
