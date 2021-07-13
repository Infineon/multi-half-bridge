/**
 * @file        tle94112-platf-ino.hpp
 * @brief       TLE94112 Arduino Hardware Platforms
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_INO_HPP_
#define TLE94112_PLATF_INO_HPP_

#if defined(ARDUINO_AVR_UNO) || defined(XMC1100_Boot_Kit) || defined(XMC4700_Relax_Kit) /**< Arduino Uno, XMC1100 Boot Kit or XMC4700 Relax Kit */

/**
 * @addtogroup platfIno
 * @{
 */

 /**
 * @brief Arduino Hardware Platform Pins
 *
 * This class provides a simple API for connecting the TLE94112 shield via SPI.
 * The 12 halfbridges, the PWM units and the registers are set and controlled
 * from the library.
 */

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS1     10

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to remove the 0 Ohm resistor R7 and solder it to R8
 */
#define TLE94112_PIN_CS2     9

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN      8

/** @} */

#endif /** #ifdef **/
#endif /** TLE94112_PLATF_INO_HPP_ **/
