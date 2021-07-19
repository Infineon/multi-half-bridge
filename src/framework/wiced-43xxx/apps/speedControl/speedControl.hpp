
/*!
 * \name        speedControl
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
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

#ifndef BASICTEST_HPP_
#define BASICTEST_HPP_

#include <stdlib.h>
#include <wiced.h>
#include <tle94112-platf-wiced.hpp>
#include <tle94112-wiced.hpp>
#include <tle94112-motor.hpp>
#include "wiced_rtos.h"

extern "C" void application_start();

//! Select pins for speed and direction settings
#define pinDir        WICED_GPIO_12
#define pinSpeed      WICED_ADC_1
#define pinSpeedTime  2

#endif /* BASICTEST_HPP_ */
