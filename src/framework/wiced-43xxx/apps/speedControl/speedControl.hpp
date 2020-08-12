
/*!
 * \name        speedControl
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     2.0.0
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

#include "../../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include <stdlib.h>
#include <wiced.h>
#include <TLE94112-platf-wiced.hpp>
#include <TLE94112-pal-wiced.hpp>
#include <TLE94112.hpp>
#include <TLE94112Motor.hpp>
#include "wiced_rtos.h"

extern "C" void application_start();

//! Select pins for speed and direction settings
#define pinDir        WICED_GPIO_12
#define pinSpeed      WICED_ADC_1
#define pinSpeedTime  2

#endif /** TLE94112_FRAMEWORK **/
#endif /* BASICTEST_HPP_ */
