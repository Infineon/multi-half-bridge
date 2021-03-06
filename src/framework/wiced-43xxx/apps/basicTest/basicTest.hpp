/**
 * \name        basicTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \brief       This example runs a basic controller test with one attached motor on the TLE94112 shield
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 * Take this example as a first test when starting with this shield.
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

#endif /* BASICTEST_HPP_ */
