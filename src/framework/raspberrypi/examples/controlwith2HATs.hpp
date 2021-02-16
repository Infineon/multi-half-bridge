/**
 * \name        controlwith2HATs
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     2.0.0
 * \brief       This example runs motor1 attached to one TLE94112 HAT and motor2 attached 
 * \details
 * It will run the motor in forward and backward direction if the motor
 * is able to run in both directions. Otherwise it will only run in on direction.
 * Take this example as a first test when starting with this shield.
 *
 */

#ifndef TWOHATS_HPP_
#define TWOHATS_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../wrapper/TLE94112-platf-rpi.hpp"
#include "../wrapper/TLE94112Motor-platf-rpi.hpp"

#endif /** TLE94112_FRAMEWORK **/
#endif /* BASICTEST_HPP_ */