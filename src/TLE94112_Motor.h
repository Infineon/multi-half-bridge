#ifndef TLE94112_MOTOR_H
#define TLE94112_MOTOR_H

#include "TLE94112.h"

#define TLE94112_CONNECTOR_SIZE		6

class Tle94112Motor
{
public:
	
	enum eMode
	{
		COAST, 
		FORWARD,
		BACKWARD,
		STOP
	};
	enum ePolarity
	{
		LOWSIDE,
		HIGHSIDE
	};
	
	Tle94112Motor(Tle94112 &driver, Tle94112::PWMChannel channel);
	~Tle94112Motor();
	void begin(void);
	void end(void);
	
	void connect(Tle94112::HalfBridge connector, ePolarity pol);
	void setPwmFreq(Tle94112::PWMFreq freq);
	void stop(uint8_t force=255);
	void coast();
	void start(int16_t speed);
	void setSpeed(int16_t speed);
	int16_t getSpeed(void);
	
private:
	Tle94112 *mDriver;
	Tle94112::PWMChannel mChannel;
	Tle94112::PWMFreq mPWMfreq;
	uint8_t mNumHighside;
	uint8_t mNumLowside;
	Tle94112::HalfBridge mHbHighside[TLE94112_CONNECTOR_SIZE];
	Tle94112::HalfBridge mHbLowside[TLE94112_CONNECTOR_SIZE];
	uint8_t mActiveFW;
	eMode mMode;
	uint8_t mSpeed;
	uint8_t mEnabled;
	
};

#endif