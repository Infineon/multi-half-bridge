/*!
 * \file        Tle94112Motor-ard.cpp
 * \name        Tle94112Motor-ard.cpp - Arduino Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \ref         pal_arduino
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "TLE94112Motor-pal-wiced.hpp"


void Tle94112Motor::rampSpeed(int16_t speed, uint16_t slope)
{
	int16_t start_speed = getSpeed();
	if (mEnabled == TRUE && speed != start_speed)
	{
		uint32_t duration = _measureSetSpeedDuration(speed, start_speed);
		//mDriver->clearErrors();
		// calc full ramp deltas
		int16_t ramp_delta_speed = speed - start_speed;
		uint16_t ramp_delta_time = (slope * abs(ramp_delta_speed)) / TLE94112_MAX_SPEED;
		// calc step deltas
		int16_t num_steps = ramp_delta_time / duration - 1;
		uint16_t steptime = 0;
		// correction of step deltas for very flat ramps
		if (abs(ramp_delta_speed) < num_steps)
		{
			num_steps = abs(ramp_delta_speed);
			steptime = ramp_delta_time / abs(ramp_delta_speed) - duration;
		}
		_performSpeedStepping(start_speed, ramp_delta_speed, num_steps,steptime);
		//mDriver->clearErrors();
	}
}

uint32_t Tle94112Motor::_measureSetSpeedDuration(int16_t speed, int16_t start_speed)
{
	if(start_speed == 0)
	{
		// changing direction is additional effort
		// don't let this have an effect on the setSpeed duration measurement
		start_speed = SIGNUM(speed);
		setSpeed(start_speed);
	}
	uint32_t duration = millis();
	setSpeed(start_speed);
//	duration = millis() - duration;
	return duration;
}

void Tle94112Motor::_performSpeedStepping(int16_t start_speed,
	int16_t ramp_delta_speed, int16_t num_steps, uint16_t steptime)
{
//	uint32_t Timer = millis(); //!> none blocking delay
	if(num_steps > 0)
	{
		// normal ramp loop
		for(uint16_t i=1u; i<=num_steps; i++)
		{
			setSpeed(start_speed + ( (i*ramp_delta_speed) / num_steps ) );
			if (steptime > 0u)
			{
				while((millis() - Timer) < steptime ){}
			}
		}
	}
	else
	{
		// special case for very steep ramps
		setSpeed(start_speed+ramp_delta_speed);
	}
}

#endif /** TLE94112_FRAMEWORK **/