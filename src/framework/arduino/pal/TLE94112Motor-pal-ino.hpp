/*!
 * \file        Tle94112Motor-pal-ino.hpp
 * \name        Tle94112Motor-pal-ino.hpp - Arduino Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \ref         pal_arduino
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef TLE94112MOTOR_PAL_INO_HPP_
#define TLE94112MOTOR_PAL_INO_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

/**
 * @addtogroup tle94112motorinopal
 * @{
 */

#include "TLE94112-pal-ino.hpp"
#include "../../../corelib/TLE94112Motor.hpp"

/**
 * @brief represents a motor connected to a TLE94112
 * 
 * This class provides a simple API for connecting and controlling motors.
 * Each motor is assigned to a Tle94112 which acts as output driver. Calls to
 * Tle94112Motor instances are mapped to calls to Tle94112. Therefore, this
 * class does not bring new features, it does only provide further abstraction.
 *
 * @see Tle94112
 */
class TLE94112MotorIno: virtual public Tle94112Motor
{
	public:

		/**
		 * @brief function to gradually change the motors speed
		 *
		 * @param speed target speed
		 * @param slope time for a full ramp from speed=0 to speed=255
		 */
		void rampSpeed(int16_t speed, uint16_t slope);

	protected:
		/*
		* @brief private function needed by rampSpeed
		* 
		* @param speed An integer in a range from -255 to 255 to set motor speed
		*        and direction. Here the target speed.
		* @param start_speed An integer a range from -255 to 255 to set motor speed
		*        and direction. Here the source speed
		*/
		uint32_t _measureSetSpeedDuration(int16_t speed, int16_t start_speed);

		/* @brief private function needed by rampSpeed
		*
		* @param start_speed An integer a range from -255 to 255 to set motor speed
		*        and direction. Here the source speed
		* @param ramp_delta_speed a slope value how fast the speed change
		*        should raise or fall
		* @param num_steps The number of steps to raise or fall the speed
		* @param steptime The time to be needed for each step
		*/
		void _performSpeedStepping(int16_t start_speed, int16_t ramp_delta_speed, int16_t num_steps, uint16_t steptime);
};

/**
 * @}
 */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112MOTOR_PAL_INO_HPP_ **/
