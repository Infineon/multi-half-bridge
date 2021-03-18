/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Empty PSoC6 Application
*              for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* (c) 2019-2020, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

#include "../../../../config/tle94112-conf.hpp"
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)


extern "C"
{
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "app_config.h"
}
#include <tle94112-platf-psoc6hal.hpp>
#include <tle94112.hpp>
#include <tle94112-motor.hpp>
#include "gpio-psoc6hal.hpp"
#include "spic-psoc6hal.hpp"
#include "timer-psoc6hal.hpp"

// Tle94112 Object on Shield 1
Tle94112Psoc6hal controller = Tle94112Psoc6hal();

// Tle94112Motor Objects on controller
Tle94112Motor motor(controller);


//void setup()
//{
    // // Enable MotorController on all Shields and Motors
    // // Note: Required to be done before starting to configure the motor
    // // controller1 is set to default CS1 pin
    // WPRINT_APP_INFO(("[TLE94112] : setup begin -> %u\n", 0));
    // controller.begin();
    // WPRINT_APP_INFO(("[TLE94112] : controller begin -> %u\n", 1));

    //  // Connect a motor to HB1/HB2 highside and HB3/HB4 lowside
    // // With two combined halfbridges the motor can have up to 1.8 A
    // // IMPORTANT connect PWM to Lowside as higside is active Free wheeling
    // motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_HB2, controller.TLE_NOHB, controller.TLE_NOHB);
    // motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_HB3, controller.TLE_HB4, controller.TLE_NOHB, controller.TLE_NOHB);
    // WPRINT_APP_INFO(("[TLE94112] : motor init -> %u\n", 2));

    // // start the motor controller
    // motor.begin();
    // WPRINT_APP_INFO(("[TLE94112] : motor begin -> %u\n", 3));
//}
//
//void loop()
//{
    // coast the motor
    // motor.coast();
    // wiced_rtos_delay_milliseconds(1000);

    // // max forward/backward
    // WPRINT_APP_INFO(("max forward/backward\n"));
    // motor.start(255);
    // wiced_rtos_delay_milliseconds(1000);
    // motor.coast();
    // wiced_rtos_delay_milliseconds(1000);
    // motor.start(-255);
    // wiced_rtos_delay_milliseconds(1000);
    // motor.coast();
    // wiced_rtos_delay_milliseconds(1000);

    // // ramp ripple forward/backward
    // WPRINT_APP_INFO(("ramp ripple forward/backward\n"));
    // motor.start(255); // start max forward
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(0,5000); // ramp down to 0
    // wiced_rtos_delay_milliseconds(1000);
    // motor.start(-255); // start max backward
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(0,5000); // ramp up to 0
    // wiced_rtos_delay_milliseconds(1000);

    // // ramp up/down forward
    // WPRINT_APP_INFO(("ramp up/down forward\n"));
    // motor.start(50); // start above 0 to allow motor to start
    // motor.rampSpeed(255,5000); // ramp up to max
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(100,5000); // ramp down
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(255,5000); // ramp up to max
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(0,5000); // ramp down to 0

    // // ramp up/down backward
    // WPRINT_APP_INFO(("ramp up/down backward\n"));
    // motor.start(50);
    // motor.rampSpeed(-255,5000); // ramp down to min
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(-100,5000); // ramp up
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(-255,5000); // ramp down to min
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(0,5000); // ramp up to 0

    // // ramp transient with a change in rotation direction
    // WPRINT_APP_INFO(("ramp transient\n"));
    // motor.rampSpeed(-255,1000); // ramp down to min
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(255,1000); // ramp up to max
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(-255,1000); // ramp down to min
    // wiced_rtos_delay_milliseconds(1000);
    // motor.rampSpeed(0,1000); // ramp up to 0
    // wiced_rtos_delay_milliseconds(1000);

    // // stop and coast
    // WPRINT_APP_INFO(("stop and coast\n"));
    // motor.stop(255); // stop and hold with max force
    // wiced_rtos_delay_milliseconds(1000);
    // motor.coast();
    // wiced_rtos_delay_milliseconds(1000);
//}

/*******************************************************************************
* Function Name: handle_error
********************************************************************************
* Summary:
* User defined error handling function
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void handle_error(void)
{
     /* Disable all interrupts. */
    __disable_irq();

    CY_ASSERT(0);
}

int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init();

    if (result != CY_RSLT_SUCCESS)
    {
        handle_error();
    }

    result = cy_retarget_io_init( CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX,
                                  CY_RETARGET_IO_BAUDRATE);

    if (result != CY_RSLT_SUCCESS)
    {
        handle_error();
    }

    result = cyhal_gpio_init( CYBSP_USER_LED, CYHAL_GPIO_DIR_OUTPUT,
                              CYHAL_GPIO_DRIVE_STRONG, CYBSP_LED_STATE_OFF);

    if (result != CY_RSLT_SUCCESS)
    {
        handle_error();
    }

    //setup();

    while(1)
    {
        //loop();
    }
}

#endif /** TLE94112_FRAMEWORK **/
