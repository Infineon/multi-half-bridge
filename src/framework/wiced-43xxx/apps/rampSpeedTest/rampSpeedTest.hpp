/**
 * \name        rampSpeedTest
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
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

#include <stdlib.h>
#include <wiced.h>
#include <tle94112-platf-wiced.hpp>
#include <tle94112-wiced.hpp>
#include <tle94112-motor.hpp>
#include "wiced_rtos.h"

extern "C" void application_start();

// a structure with the measured values
typedef struct {
  int16_t startspeed;
  int16_t endspeed;
  uint16_t slope;
} RampMeasurement_t, *RampMeasurement_p;

// lets define an array with different tests
#define NUM_TESTS 6
RampMeasurement_t testcases[NUM_TESTS] = {
  { 0,    255,  5000 },
  { 255,  200,  10000 },
  { 200,  0,    500 },
  { 0,    -255, 10 },
  { -255, 255,  3000 },
  { 255,  0,    1000 }
};

#endif /* RAMPSPEEDTEST_HPP_ */