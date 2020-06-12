/*!
 * \file        Tle94112-ino.cpp
 * \name        Tle94112.in0.cpp - Arduino library to control Infineon's DC Motor Control Shield with Tle94112
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This file has to be included in projects that use Infineon's DC Motor Control Shield with TLE94112
 * \ref         platform_ard
 * \details
 * The Infineon TLE94112EL DC motor controller shield is able to handle 6 motors with a max. current of 0.9 A
 * independently and additional 5 motors cascaded. The twelve half-bridges can be arranged also together,
 * so that 3 motors with 1.8 A current or one motor with 3.6 A can be used. Each half bridge can
 * provide a high-Voltage (nominal 5.5-18 V) tristate output and max. input voltage of 40V. It is also
 * capable of PWM with 3 different frequencies for controlling the speed of each motor.
 * Have a look at the datasheet for more information.
 * - This library include the basic functions to access the half-bridges.
 * - Have a look at the datasheet for more information. 
 */


#include <TLE94112-ino.hpp>

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

Tle94112Ino::Tle94112Ino(void):Tle94112()
{
}

#endif /** TLE94112_FRAMEWORK **/