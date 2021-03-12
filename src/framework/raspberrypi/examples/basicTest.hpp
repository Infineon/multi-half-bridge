/**
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     2.0.0
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 shield
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 * Take this example as a first test when starting with this shield.
 *
 */

#ifndef BASICTEST_HPP_
#define BASICTEST_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include <cstdio>
#include <bcm2835.h>
#include "../wrapper/tle94112-rpi.hpp"
#include "../../../corelib/tle94112-motor.hpp"

#endif /** TLE94112_FRAMEWORK **/
#endif /* BASICTEST_HPP_ */
