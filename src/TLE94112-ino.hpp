/*!
 * \file        Tle94112-ino.hpp
 * \name        Tle94112-ino.hpp - Arduino library to control Infineon's DC Motor Control Shield with Tle94112
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.5.0
 * \brief       This is a Arduino platform file use Infineon's DC Motor Control Shield with TLE94112 with
 *              Arduino/Genuino, Infineon XMC microcontroller or compatible boards.
 * \ref         platform_ard
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef TLE94112_INO_HPP_
#define TLE94112_INO_HPP_

#include "config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

/**
 * @addtogroup tle94112api
 * @{
 */

#include "corelib/TLE94112.hpp"
#include "framework/arduino/wrapper/TLE94112-platf-ino.hpp"

/**
 * @class Tle94112Ino
 *
 * @brief represents the TLE94112 base class
 *
 * This class provides a simple API for connecting the TLE94112 shield via SPI.
 * The 12 halfbridges, the PWM units and the registers are set and controlled
 * from the library.
 *
 */

class Tle94112Ino: virtual public TLE94112Ino
{
	public:
		//! \brief standard constructor with default pin assignment
		Tle94112Ino(void);

		/*!
		 * \brief constructor with individual pin assignment
		 *
		 * \param bus    void pointer to the object representing the SPI class
		 * \param csPin  pin number of the CS pin
		 */
		Tle94112Ino(void* bus, uint8_t csPin);

		//! \brief enables and initializes the TLE94112
		void begin(void);

		//! \brief deactivates all outputs and disables the TLE94112
		void end(void);

};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_INO_HPP_ **/
