#include "TLE94112_Motor.h"

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE  1
#endif

#define TLE94112_MAX_SPEED	255


Tle94112Motor::Tle94112Motor(Tle94112 &driver, Tle94112::PWMChannel channel)
{
	mDriver = &driver;
	mChannel = channel;
	mNumHighside = 0;
	mNumLowside = 0;
	mPWMfreq = Tle94112::TLE_FREQ200HZ;
	mSpeed = 0;
	mActiveFW = FALSE;
	mMode = COAST;
	mEnabled = FALSE;
}

Tle94112Motor::~Tle94112Motor()
{
	end();
}
	
void Tle94112Motor::begin(void)
{
	mDriver->configPWM(mChannel, mPWMfreq, mSpeed);
	mEnabled = TRUE;
	coast();
}

void Tle94112Motor::end(void)
{
	coast();
	mEnabled = FALSE;
}

void Tle94112Motor::connect(Tle94112::HalfBridge connector, ePolarity pol)
{
	if(mEnabled == FALSE)
	{
		if(pol==LOWSIDE && mNumLowside<TLE94112_CONNECTOR_SIZE)
		{
			mHbLowside[mNumLowside] = connector;
			mNumLowside++;
			mDriver->configHB(connector, Tle94112::TLE_FLOATING, mChannel, mActiveFW);
		}
		if(pol==HIGHSIDE && mNumHighside<TLE94112_CONNECTOR_SIZE)
		{
			mHbHighside[mNumHighside] = connector;
			mNumHighside++;
			mDriver->configHB(connector, Tle94112::TLE_FLOATING, mChannel, mActiveFW);
		}
	}
}

void Tle94112Motor::setPwmFreq(Tle94112::PWMFreq freq)
{
	if(mEnabled == FALSE)
	{
		mPWMfreq = freq;
		mDriver->configPWM(mChannel, freq, 0);
	}
}

void Tle94112Motor::stop(uint8_t force)
{
	uint8_t i;
	if(mEnabled == TRUE)
	{
		//set all outputs floating to avoid short-circuits
		coast();
		mMode = STOP;
		mSpeed = force;
		if(mNumHighside==0)
		{
			// highside is constantly connected to high. 
			// also connect lowside to high to stop motor
			for(i = 0; i<mNumLowside; i++)
			{
				mDriver->configHB(mHbLowside[i], Tle94112::TLE_HIGH, mChannel, mActiveFW);
			}
		}
		else
		{
			// connect all motor pins to low
			for(i = 0; i<mNumHighside; i++)
			{
				mDriver->configHB(mHbHighside[i], Tle94112::TLE_LOW, mChannel, mActiveFW);
			}
			for(i = 0; i<mNumLowside; i++)
			{
				mDriver->configHB(mHbLowside[i], Tle94112::TLE_LOW, mChannel, mActiveFW);
			}
		}
		// set dutycycle depending on parameter force
		// higher force lets the motor stop quicker
		mDriver->configPWM(mChannel, mPWMfreq, mSpeed);
	}
}

void Tle94112Motor::coast()
{
	if(mEnabled == TRUE)
	{
		uint8_t i;
		mSpeed = 0;
		mMode = COAST;
		mDriver->configPWM(mChannel, mPWMfreq, mSpeed);
		for(i = 0; i<mNumHighside; i++)
		{
			mDriver->configHB(mHbHighside[i], Tle94112::TLE_FLOATING, mChannel, mActiveFW);
		}
		for(i = 0; i<mNumLowside; i++)
		{
			mDriver->configHB(mHbLowside[i], Tle94112::TLE_FLOATING, mChannel, mActiveFW);
		}
	}
}

void Tle94112Motor::start(int16_t speed)
{
	setSpeed(speed);
}

void Tle94112Motor::setSpeed(int16_t speed)
{
	uint8_t i;
	if(mEnabled == TRUE)
	{
		mSpeed = speed;
		if(speed == 0)
		{
			coast();
		}
		else if(speed > 0)
		{
			mSpeed = (speed>TLE94112_MAX_SPEED) ? TLE94112_MAX_SPEED : speed;
			if(mMode != FORWARD)
			{
				//change configuration to running forward
				coast(); //set all outputs to HIGH-IMPEDANCE to avoid short-circuits
				mMode = FORWARD;
				for(i = 0; i<mNumHighside; i++)
				{
					mDriver->configHB(mHbHighside[i], Tle94112::TLE_HIGH, mChannel, mActiveFW);
				}
				for(i = 0; i<mNumLowside; i++)
				{
					mDriver->configHB(mHbLowside[i], Tle94112::TLE_LOW, mChannel, mActiveFW);
				}
			}
			mDriver->configPWM(mChannel, mPWMfreq, mSpeed);
		}
		else if(speed<0 && mNumHighside>0 && mNumLowside>0)
		{
			// backward is only available if highside and lowside are connected to the TLE
			mSpeed = (speed < -TLE94112_MAX_SPEED) ? TLE94112_MAX_SPEED : -speed;
			if(mMode != BACKWARD)
			{
				//change configuration to running backward
				coast(); //set all outputs to HIGH-IMPEDANCE to avoid short-circuits
				mMode = BACKWARD;
				for(i = 0; i<mNumHighside; i++)
				{
					mDriver->configHB(mHbHighside[i], Tle94112::TLE_LOW, mChannel, mActiveFW);
				}
				for(i = 0; i<mNumLowside; i++)
				{
					mDriver->configHB(mHbLowside[i], Tle94112::TLE_HIGH, mChannel, mActiveFW);
				}
			}
			mDriver->configPWM(mChannel, mPWMfreq, mSpeed);
		}
		else
		{
			// backward desired but not available: assume user wants to break instead
			stop((uint8_t)(-speed));
		}
	}
}

int16_t Tle94112Motor::getSpeed(void)
{
	if(mEnabled == TRUE)
	{
		switch(mMode)
		{
			case FORWARD: return mSpeed;
			case BACKWARD: return (-1)*mSpeed;
			default: return 0;
		}
		return mSpeed;
	}
}
