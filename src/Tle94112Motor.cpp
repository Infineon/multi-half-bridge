#include "Tle94112Motor.h"

#define TLE94112_MAX_SPEED	255

#ifndef SIGNUM
#define SIGNUM(x) ( (x > 0) - (x < 0) )
#endif

Tle94112Motor::Tle94112Motor(Tle94112 &driver)
{
	mDriver = &driver;
	mMode = COAST;
	mEnabled = FALSE;
	mSpeed = 0u;
}

Tle94112Motor::~Tle94112Motor()
{
	end();
}

void Tle94112Motor::begin(void)
{
	mEnabled = TRUE;
	coast();
}

void Tle94112Motor::end(void)
{
	coast();
	mEnabled = FALSE;
}

void Tle94112Motor::initConnector(Tle94112Motor::ePolarity pol,
		Tle94112::PWMChannel channel, 
		Tle94112::HalfBridge out1, 
		Tle94112::HalfBridge out2, 
		Tle94112::HalfBridge out3, 
		Tle94112::HalfBridge out4)
{
	initConnector(pol,channel, Tle94112::TLE_FREQ80HZ, out1, out2, out3, out4);
}

void Tle94112Motor::initConnector(Tle94112Motor::ePolarity pol,
		Tle94112::PWMChannel channel, 
		Tle94112::PWMFreq freq, 
		Tle94112::HalfBridge out1, 
		Tle94112::HalfBridge out2, 
		Tle94112::HalfBridge out3, 
		Tle94112::HalfBridge out4)
{
	Tle94112::HalfBridge outputs[TLE94112MOTOR_MAX_CONNECTORS]
		 = {out1, out2, out3, out4};
	if(mEnabled == FALSE)
	{
		mConnectors[pol].channel = channel;
		mConnectors[pol].freq = freq;
		mConnectors[pol].active_fw = FALSE;
		for(uint8_t i=0; i<TLE94112MOTOR_MAX_CONNECTORS; i++)
		{
			mConnectors[pol].halfbridges[i] = outputs[i];
		}
		mConnectors[pol].channel = channel;
	}
}

void Tle94112Motor::connect(Tle94112Motor::ePolarity pol, 
		Tle94112::HalfBridge connector)
{
	if(mEnabled == FALSE)
	{
		for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
		{
			if(mConnectors[pol].halfbridges[idx] == Tle94112::TLE_NOHB)
			{
				mConnectors[pol].halfbridges[idx] = connector;
				break;
			}
		}
	}
}

void Tle94112Motor::disconnect(Tle94112::HalfBridge connector)
{
	if(mEnabled == FALSE)
	{
		for(uint8_t pol = 0u; pol<2u; pol++)
		{
			for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
			{
				if(connector == mConnectors[pol].halfbridges[idx])
				{
					mConnectors[pol].halfbridges[idx] = Tle94112::TLE_NOHB;
				}
			}
		}
	}
}

void Tle94112Motor::setPwm(Tle94112Motor::ePolarity pol, 
		Tle94112::PWMChannel channel)
{
	if(mEnabled == FALSE)
	{
		mConnectors[pol].channel = channel;
	}
}

void Tle94112Motor::setPwm(Tle94112Motor::ePolarity pol, 
		Tle94112::PWMChannel channel, Tle94112::PWMFreq freq)
{
	if(mEnabled == FALSE)
	{
		mConnectors[pol].channel = channel;
		mConnectors[pol].freq = freq;
	}
}

void Tle94112Motor::setPwmFreq(Tle94112Motor::ePolarity pol, 
		Tle94112::PWMFreq freq)
{
	if(mEnabled == FALSE)
	{
		mConnectors[pol].freq = freq;
	}
}

void Tle94112Motor::setActiveFreeWheeling(Tle94112Motor::ePolarity pol, 
		uint8_t active_fw)
{
	if(mEnabled == FALSE)
	{
		mConnectors[pol].active_fw = active_fw;
	}
}

void Tle94112Motor::coast()
{
	if(mEnabled == TRUE)
	{
		mMode = COAST;
		mSpeed = 0u;
		for(uint8_t pol = 0u; pol<2u; pol++)
		{
			for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
			{
				mDriver->configHB(mConnectors[pol].halfbridges[idx], 
						Tle94112::TLE_FLOATING, 
						mConnectors[pol].channel, 
						mConnectors[pol].active_fw);
			}
		}
	}
	mDriver->clearErrors();
}

void Tle94112Motor::stop(uint8_t force)
{
	uint8_t numHighside = 0u;
	if(mEnabled == TRUE)
	{
		//set all outputs floating to avoid short-circuits
		coast();
		mMode = STOP;
		mSpeed = force;
		// set dutycycle depending on parameter force
		// higher force lets the motor stop quicker
		mDriver->configPWM(mConnectors[HIGHSIDE].channel, 
				mConnectors[HIGHSIDE].freq, force);
		mDriver->configPWM(mConnectors[LOWSIDE].channel, 
				mConnectors[LOWSIDE].freq, force);
		//connect highside pins to low
		for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
		{
			Tle94112::HalfBridge hb = mConnectors[HIGHSIDE].halfbridges[idx];
			if(hb != Tle94112::TLE_NOHB) {
				numHighside++;
				mDriver->configHB(hb, 
						Tle94112::TLE_LOW, 
						mConnectors[HIGHSIDE].channel, 
						mConnectors[HIGHSIDE].active_fw);
			}
		}
		if(numHighside == 0u)
		{
			// highside is constantly connected to high. 
			// also connect lowside to high to stop motor
			for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
			{
				mDriver->configHB(mConnectors[LOWSIDE].halfbridges[idx], 
						Tle94112::TLE_HIGH, 
						mConnectors[LOWSIDE].channel, 
						mConnectors[LOWSIDE].active_fw);
			}
		}
		else
		{
			// connect all motor pins to low
			for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
			{
				mDriver->configHB(mConnectors[LOWSIDE].halfbridges[idx], 
						Tle94112::TLE_LOW, 
						mConnectors[LOWSIDE].channel, 
						mConnectors[LOWSIDE].active_fw);
			}
		}
	}
}

void Tle94112Motor::start(int16_t speed)
{
	setSpeed(speed);
}

void Tle94112Motor::setSpeed(int16_t speed)
{
	if(mEnabled == TRUE)
	{
		if(speed == 0)
		{
			coast();
		}
		else if(speed > 0)
		{
			mSpeed = static_cast<uint8_t>(speed);
			mDriver->configPWM(mConnectors[HIGHSIDE].channel, 
					mConnectors[HIGHSIDE].freq, mSpeed);
			mDriver->configPWM(mConnectors[LOWSIDE].channel, 
					mConnectors[LOWSIDE].freq, mSpeed);
			if(mMode != FORWARD)
			{
				//change configuration to running forward
				//set all outputs to HIGH-IMPEDANCE to avoid short-circuits
				coast(); 
				mMode = FORWARD;
				mSpeed = static_cast<uint8_t>(speed);
				for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
				{
					mDriver->configHB(mConnectors[HIGHSIDE].halfbridges[idx], 
							Tle94112::TLE_HIGH, 
							mConnectors[HIGHSIDE].channel, 
							mConnectors[HIGHSIDE].active_fw);
					mDriver->configHB(mConnectors[LOWSIDE].halfbridges[idx], 
							Tle94112::TLE_LOW, 
							mConnectors[LOWSIDE].channel, 
							mConnectors[LOWSIDE].active_fw);
				}
			}
		}
		else	// speed < 0
		{
			mSpeed = static_cast<uint8_t>(-speed);
			mDriver->configPWM(mConnectors[HIGHSIDE].channel, 
					mConnectors[HIGHSIDE].freq, mSpeed);
			mDriver->configPWM(mConnectors[LOWSIDE].channel, 
					mConnectors[LOWSIDE].freq, mSpeed);
			if(mMode != BACKWARD)
			{
				//change configuration to running backward
				//set all outputs to HIGH-IMPEDANCE to avoid short-circuits
				coast();
				mMode = BACKWARD;
				mSpeed = static_cast<uint8_t>(-speed);
				for(uint8_t idx = 0u; idx < TLE94112MOTOR_MAX_CONNECTORS; idx++)
				{
					mDriver->configHB(mConnectors[HIGHSIDE].halfbridges[idx], 
							Tle94112::TLE_LOW, 
							mConnectors[HIGHSIDE].channel, 
							mConnectors[HIGHSIDE].active_fw);
					mDriver->configHB(mConnectors[LOWSIDE].halfbridges[idx], 
							Tle94112::TLE_HIGH, 
							mConnectors[LOWSIDE].channel, 
							mConnectors[LOWSIDE].active_fw);
				}
			}
		}
	}
}

int16_t Tle94112Motor::getSpeed(void)
{
	int16_t ret=0;
	if(mMode == FORWARD) 
	{
		ret += mSpeed;
	}
	if(mMode == BACKWARD)
	{
		ret -= mSpeed;
	}
	return ret;
}


uint32_t Tle94112Motor::measureSetSpeedDuration(int16_t speed, 
		int16_t start_speed)
{
	if(start_speed == 0) {
		// changing direction is additional effort
		// don't let this have an effect on the setSpeed duration measurement
		start_speed = SIGNUM(speed);
		setSpeed(start_speed);
	}
	uint32_t duration = millis();
	setSpeed(start_speed);
	duration = millis() - duration;
	return duration;
}

void Tle94112Motor::performSpeedStepping(int16_t start_speed, 
		int16_t ramp_delta_speed, int16_t num_steps, uint16_t steptime) 
{
	if(num_steps > 0) {
		// normal ramp loop
		for(uint16_t i=1u; i<=num_steps; i++)
		{
			setSpeed(start_speed + ( (i*ramp_delta_speed) / num_steps ) );
			if( steptime > 0u )
			{
				delay(steptime);
			}
		}
	}
	else
	{
		// special case for very steep ramps
		setSpeed(start_speed+ramp_delta_speed);
	}
}


void Tle94112Motor::rampSpeed(int16_t speed, uint16_t slope)
{
	int16_t start_speed = getSpeed();
	if(mEnabled == TRUE && speed != start_speed)
	{
		uint32_t duration = measureSetSpeedDuration(speed, start_speed);
		// calc full ramp deltas
		int16_t ramp_delta_speed = speed - start_speed;
		uint16_t ramp_delta_time
				= (slope * abs(ramp_delta_speed)) / TLE94112_MAX_SPEED;
		// calc step deltas
		int16_t num_steps = ramp_delta_time / duration - 1;
		uint16_t steptime = 0;
		// correction of step deltas for very flat ramps
		if(abs(ramp_delta_speed) < num_steps)
		{
			num_steps = abs(ramp_delta_speed);
			steptime = ramp_delta_time / abs(ramp_delta_speed) - duration;
		}
		performSpeedStepping(start_speed, ramp_delta_speed, num_steps, steptime);
	}
}
