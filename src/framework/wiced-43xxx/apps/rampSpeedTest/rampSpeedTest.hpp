/** 
 * \name        rampSpeedTest
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This example measure the rampspeed of an attached motor with the TLE94112 shield
 * \details
 * By attaching a motor to the TLE94112 and running a testcase scenario, we can measure the
 * optimal values for the rampSpeed function. This function allows us to smoothly start, stop,
 * raise or break the motor.
 * 
 * \attention A free running motor ramps very different than the same motor with load attached.
 * So you have to measure different scenarios.
 *
 */

#ifndef RAMPSPEEDTEST_HPP_
#define RAMPSPEEDTEST_HPP_

//#include "../../wrapper/TLE94112Motor-platf-wiced.hpp"
#include <TLE94112Motor-platf-wiced.hpp>

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include <stdlib.h>
#include <TLE94112-platf-wiced.hpp>
#include <wiced.h>



// Tle94112Motor Objects on controller1
//TLE94112Motor motor(controller);

extern "C" void application_start();

#endif /** TLE94112_FRAMEWORK **/
#endif /* RAMPSPEEDTEST_HPP_ */
