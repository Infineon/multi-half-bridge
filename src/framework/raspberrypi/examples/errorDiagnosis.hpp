/*!
 * \name        errorDiagnosis
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \version     1.0.0
 * \brief       This example shows how to read and understand the status registers of the TLE94112.
 * \details
 * It will run the motor in forward direction and then read the status registers every 5 seconds. 
 * It shows how to understand the status registers and which errors can appear.
 * Take this example if you want to learn how to debug the TLE94112 during operation.
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef BASICTEST_HPP_
#define BASICTEST_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../wrapper/TLE94112-platf-rpi.hpp"
#include "../wrapper/TLE94112Motor-platf-rpi.hpp"

#endif /** TLE94112_FRAMEWORK **/
#endif /* BASICTEST_HPP_ */
