/*!
 * \file 		Tle94112Motor.h
 * \name        Tle94112Motor.h - optionally include library
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.4.1
 * \brief 		This file can optionally be included in projects that use Infineon's 
 * 				DC Motor Control Shield with TLE94112
 * 				It provides a higher abstraction for controlling motors with the TLE94112 
 * 				acting as an output driver
 * \details
 * The Infineon TLE94112EL DC motor controller shield is able to handle 6 motors with a max. current of 0.9 A
 * independently and additional 5 motors cascaded. The twelve half-bridges can be arranged also together,
 * so that 3 motors with 1.8 A current or one motor with 3.6 A can be used. Each half bridge can
 * provide a high-Voltage (nominal 5.5-18 V) tristate output and max. input voltage of 40V. It is also
 * capable of PWM with 3 different frequencies for controlling the speed of each motor.
 * Have a look at the datasheet for more information.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef TLE94112MOTOR_H
#define TLE94112MOTOR_H

#include "TLE94112.h"


/**
 * @brief maximum number of Tle94112 outputs per motor connector
 * 
 * When this is changed, also the function signature and implementation of 
 * Tle94112Motor::initConnector has to be changed. 
 * 
 * @see Tle94112Motor::initConnector
 */
#define TLE94112MOTOR_MAX_CONNECTORS 4

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
class Tle94112Motor
{
public:
	
	/**
	 * @brief Enum to select polarity of a motor connector
	 */
	enum ePolarity
	{
		LOWSIDE = 0,
		HIGHSIDE 
	};
	
	/**
	 * @brief Construct a new Tle94112Motor object
	 * 
	 * After constructing, the motor must be configured. You can use functions 
	 * initConnector(), connect(), disconnect(), setPwm(), setPwmFreq() and 
	 * setActiveFreeWheeling() for configuration. 
	 * Call begin() to finish configuration and enable motor controls. 
	 * 
	 * @param driver Tle94112 instance acting as a driver
	 */
	Tle94112Motor(Tle94112 &driver);

	/**
	 * @brief Destroy the Tle94112Motor object
	 */
	~Tle94112Motor();

	/**
	 * @brief finishes configuration and enables motor controls
	 * 
	 * For controlling the motor, you can use the functions start(), stop(), 
	 * coast(), setSpeed(), getSpeed() and rampSpeed()
	 * Call end() to get back to configuration mode. After calling end() and 
	 * changing configuration, you can get back to controlling mode by calling 
	 * begin()
	 * 
	 * @see end
	 */
	void begin(void);

	/**
	 * @brief disables motor controls and switches back to configuration mode
	 * 
	 * If necessary, you can call end() and change the configuration settings 
	 * at any point of time. This might be useful when sharing PWM channels 
	 * between several motors. Configuration changes to motors are not allowed 
	 * while controls are active!
	 * Call begin() again when the configuration changes are done to enable 
	 * motor controls again. 
	 * 
	 * @see begin
	 */
	void end(void);
	
	/**
	 * @brief configures most important settings for one motor connector
	 * 
	 * Call this function twice to setup motor configuration for both the 
	 * + and - connector of the motor. If there is no setup for one polarity, 
	 * the library assumes that the motor is constantly connected to + or -. 
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param channel PWM channel assigned to this connector
	 * @param out1 halfbridge output 1 of 4 assigned to this connector
	 * @param out2 halfbridge output 2 of 4 assigned to this connector
	 * @param out3 halfbridge output 3 of 4 assigned to this connector
	 * @param out4 halfbridge output 4 of 4 assigned to this connector
	 */
	void initConnector(Tle94112Motor::ePolarity pol,
		Tle94112::PWMChannel channel, 
		Tle94112::HalfBridge out1, 
		Tle94112::HalfBridge out2, 
		Tle94112::HalfBridge out3, 
		Tle94112::HalfBridge out4);
	
	/**
	 * @brief configures most important settings for one motor connector
	 * 
	 * Call this function twice to setup motor configuration for both the 
	 * + and - connector of the motor. If there is no setup for one polarity, 
	 * the library assumes that the motor is constantly connected to + or -. 
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param channel PWM channel assigned to this connector
	 * @param freq optional PWM frequency setting
	 * @param out1 halfbridge output 1 of 4 assigned to this connector
	 * @param out2 halfbridge output 2 of 4 assigned to this connector
	 * @param out3 halfbridge output 3 of 4 assigned to this connector
	 * @param out4 halfbridge output 4 of 4 assigned to this connector
	 */
	void initConnector(Tle94112Motor::ePolarity,
		Tle94112::PWMChannel channel, 
		Tle94112::PWMFreq freq, 
		Tle94112::HalfBridge out1, 
		Tle94112::HalfBridge out2, 
		Tle94112::HalfBridge out3, 
		Tle94112::HalfBridge out4);

	/**
	 * @brief connects a single halfbridge output to a motor connector
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param connector halfbridge output to be assigned to this motor
	 */
	void connect(Tle94112Motor::ePolarity pol, Tle94112::HalfBridge connector);

	/**
	 * @brief disconnects a single halfbridge output from a motor connector
	 * 
	 * @param connector halfbridge output to be removed from this motor
	 */
	void disconnect(Tle94112::HalfBridge connector);

	/**
	 * @brief Sets the PWM channel to be used for a motor connector
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param channel PWM channel to be used
	 */
	void setPwm(Tle94112Motor::ePolarity pol, Tle94112::PWMChannel channel);

	/**
	 * @brief Sets the PWM channel and frequency for a motor connector
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param channel PWM channel to be used
	 * @param freq PWM frequency selection
	 */
	void setPwm(Tle94112Motor::ePolarity pol, Tle94112::PWMChannel channel, 
			Tle94112::PWMFreq freq);

	/**
	 * @brief Sets the PWM frequency for driving a motor connector
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param freq PWM frequency selection
	 */
	void setPwmFreq(Tle94112Motor::ePolarity pol, Tle94112::PWMFreq freq);

	/**
	 * @brief Enables or disables active freewheeling
	 * 
	 * Default is FALSE i.e. passive freewheeling. 
	 * Depending on your application circuit, active freewheeling may lead to 
	 * electrical problems. Do not change this setting unless you know what 
	 * you are doing. 
	 * 
	 * @param pol Polarity of the motor connector to be configured
	 * @param active_fw TRUE/FALSE to enable/disable active freewheeling
	 */
	void setActiveFreeWheeling(Tle94112Motor::ePolarity pol, uint8_t active_fw);

	/**
	 * @brief actively breaks the motor to stop it
	 * 
	 * @param force higher force lets the motor stop quicker, maximum is 255
	 */
	void stop(uint8_t force=255);

	/**
	 * @brief releases the motor without driving or active breaking
	 */
	void coast();

	/**
	 * @brief starts the motor with a certain speed in a certain direction
	 * 
	 * The behaviour of this function depends on the way the motor is connected 
	 * to the Tle94112. Motors which have just one connector assigned to the 
	 * Tle94112 cannot run in reverse direction and break instead if a negative 
	 * speed value is passed. 
	 * Motors without PWM assigned cannot run at a certain speed. They can just 
	 * coast, run and break. Speed values greater or smaller than 0 are treated 
	 * like -255 or 255, respectively. 
	 * 
	 * @param speed An integer in a range from -255 to 255 to set motor speed and direction
	 */
	void start(int16_t speed);

	/**
	 * @brief equivalent to start()
	 * 
	 * This function is fully equivalent to start(), but it is intended to be 
	 * used if the motor is already running. (Distinguishing between these two 
	 * functions helps improving the readability of your code)
	 * The behaviour of this function depends on the way the motor is connected 
	 * to the Tle94112. Motors which have just one connector assigned to the 
	 * Tle94112 cannot run in reverse direction and break instead if a negative 
	 * speed value is passed. 
	 * Motors without PWM assigned cannot run at a certain speed. They can just 
	 * coast, run and break. Speed values greater or smaller than 0 are treated 
	 * like -255 or 255, respectively. 
	 * 
	 * @param speed An integer in a range from -255 to 255 to set motor speed and direction
	 * @see start
	 */
	void setSpeed(int16_t speed);

	/**
	 * @brief Returns the motor's current speed setting
	 * 
	 * @return int16_t the motor's current speed setting
	 */
	int16_t getSpeed(void);

	/**
	 * @brief function to gradually change the motors speed
	 * 
	 * @param speed target speed
	 * @param slope time for a full ramp from speed=0 to speed=255
	 */
	void rampSpeed(int16_t speed, uint16_t slope);
	
private:


	//! @brief enum for motor operation modes
	enum eMode
	{
		COAST, 
		FORWARD,
		BACKWARD,
		STOP
	};

	//! @brief struct representing one motor connector
	typedef struct
	{
		Tle94112::HalfBridge halfbridges[TLE94112MOTOR_MAX_CONNECTORS];
		Tle94112::PWMChannel channel;
		Tle94112::PWMFreq freq;
		uint8_t active_fw;
	} Connector_t, *Connector_p;

	//! @brief array of motor connectors
	Connector_t mConnectors[2] =
	{
		{
			.halfbridges = {Tle94112::TLE_NOHB, 
					Tle94112::TLE_NOHB, 
					Tle94112::TLE_NOHB, 
					Tle94112::TLE_NOHB}, 
			.channel = Tle94112::TLE_NOPWM, 
			.freq = Tle94112::TLE_FREQ80HZ, 
			.active_fw = FALSE 
		},
		{
			.halfbridges = {Tle94112::TLE_NOHB, 
					Tle94112::TLE_NOHB, 
					Tle94112::TLE_NOHB, 
					Tle94112::TLE_NOHB}, 
			.channel = Tle94112::TLE_NOPWM, 
			.freq = Tle94112::TLE_FREQ80HZ, 
			.active_fw = FALSE 
		}
	};

	//! @brief Tle94112 instance acting as output driver
	Tle94112 *mDriver;

	//! @brief current operation mode
	eMode mMode;

	//! @brief flag indicating if motor controls are enabled
	uint8_t mEnabled;

	//! @brief value of the current motor speed
	uint8_t mSpeed;
	
	//! 

	/*
	 * @brief private function needed by rampSpeed
	 * 
	 * @param speed An integer in a range from -255 to 255 to set motor speed
	 *    and direction. Here the target speed.
	 * @param start_speed An integer a range from -255 to 255 to set motor speed
	 *    and direction. Here the source speed
	 */
	uint32_t measureSetSpeedDuration(int16_t speed, int16_t start_speed);

	/* @brief private function needed by rampSpeed
	 *
	 * @param start_speed An integer a range from -255 to 255 to set motor speed
	 *    	and direction. Here the source speed
	 * @param ramp_delta_speed a slope value how fast the speed change 
	 * 		should raise or fall
	 * @param num_steps The number of steps to raise or fall the speed
	 * @param steptime The time to be needed for each step
	 */
	void performSpeedStepping(int16_t start_speed, int16_t ramp_delta_speed, 
			int16_t num_steps, uint16_t steptime);
};

#endif //TLE94112MOTOR_H
