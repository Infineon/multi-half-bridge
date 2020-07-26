/** 
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 shield
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 * 
 * \attention A free running motor ramps very different than the same motor with load attached.
 * So you have to measure different scenarios.
 *
 */

#ifndef BASICTEST_HPP_
#define BASICTEST_HPP_

#include "../../wrapper/TLE94112Motor-platf-wiced.hpp"
//#include <TLE94112-platf-wiced.hpp>

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include <stdlib.h>
#include <wiced.h>
#include <TLE94112-pal-wiced.hpp>
#include <TLE94112.hpp>
#include <TLE94112Motor.hpp>
#include "wiced_rtos.h"

extern "C" void application_start();

//! Select pins for speed and direction settings
#define pinDir        5
#define pinSpeed      WICED_ADC_1
#define pinSpeedTime  WICED_MQTT_DELAY_IN_MILLISECONDS

#endif /** TLE94112_FRAMEWORK **/
#endif /* BASICTEST_HPP_ */
