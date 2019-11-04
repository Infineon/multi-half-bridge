/*!
 * \file 		Tle94112.h
 * \name        Tle94112.h - Arduino library to control Infineon's DC Motor Control Shield with Tle94112
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.4.1
 * \brief 		This file has to be included in projects that use Infineon's DC Motor Control Shield with TLE94112      
 * \details
 * The Infineon TLE94112EL DC motor controller shield is able to handle 6 motors with a max. current of 0.9 A
 * independently and additional 5 motors cascaded. The twelve half-bridges can be arranged also together,
 * so that 3 motors with 1.8 A current or one motor with 3.6 A can be used. Each half bridge can
 * provide a high-Voltage (nominal 5.5-18 V) tristate output and max. input voltage of 40V. It is also
 * capable of PWM with 3 different frequencies for controlling the speed of each motor.
 * Have a look at the datasheet for more information.
 * 
 * This library include the basic functions to access the half-bridges.
 *
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

#ifndef TLE94112_H
#define TLE94112_H

#include "Arduino.h"
#include "SPI.h"
#include "Wire.h"
#include "./util/tle94112_conf.h"

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE  1
#endif

/*! \brief the number of halfbridges on a TLE94112
 *
 *	\see mHalfBridges
 *	\see HalfBridge
 */
#define TLE94112_NUM_HB 			13

/*! \brief the number of pwm modes for a halfbridge (including no pwm)
 *
 *	\see mPwmChannels
 *	\see PWMChannel
 */
#define TLE94112_NUM_PWM			4

/*! \brief the number of control registers in a TLE94112
 *
 *	\see CtrlRegisters
 *	\see mCtrlRegAddresses
 *	\see mCtrlRegData
 */
#define TLE94112_NUM_CTRL_REGS		12

/*! \brief the number of status registers in a TLE94112
 *
 *	\see StatusRegisters
 *	\see mStatusRegAddresses
 *	\see mStatusRegData
 */
#define TLE94112_NUM_STATUS_REGS	7

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS1			10

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to remove the 0 Ohm resistor R7 and solder it to R8
 */
#define TLE94112_PIN_CS2			9

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN				8

//!	\brief	Class that represents a TLE94112
class Tle94112
{
	public:
		//! \brief enum for the halfbridges on a TLE94112
		enum HalfBridge
		{
			TLE_NOHB = 0, TLE_HB1, TLE_HB2, TLE_HB3, TLE_HB4, TLE_HB5, TLE_HB6, 
			TLE_HB7, TLE_HB8, TLE_HB9, TLE_HB10, TLE_HB11, TLE_HB12
		};
		
		//! \brief enum for the PWM channels of a halfbridge on TLE94112
		enum PWMChannel
		{
			TLE_NOPWM = 0, TLE_PWM1, TLE_PWM2, TLE_PWM3
		};
		
		//! \brief enum for the output states of a halfbridge
		enum HBState
		{
			TLE_FLOATING = 0b00, TLE_LOW = 0b01, TLE_HIGH = 0b10
		};
		
		//! \brief enum for the frequencies of a PWM channel
		enum PWMFreq
		{
			TLE_FREQOFF = 0b00, TLE_FREQ80HZ, TLE_FREQ100HZ, TLE_FREQ200HZ 
		};
		
		//! \brief enum for the flags in the register SYS_DIAG1
		enum DiagFlag
		{
			TLE_SPI_ERROR = 0x80,
			TLE_LOAD_ERROR = 0x40,
			TLE_UNDER_VOLTAGE = 0x20,
			TLE_OVER_VOLTAGE = 0x10,
			TLE_POWER_ON_RESET = 0x08,
			TLE_TEMP_SHUTDOWN = 0x04,
			TLE_TEMP_WARNING = 0x02
		};
		//! \brief Reference value of Status Register
		static const uint8_t TLE_STATUS_OK = 0U;
		
		//! \brief standard constructor with default pin assignment
		Tle94112();
		
		//! \brief enables and initializes the TLE94112
		void begin(void);
		
		/*! \brief constructor with individual pin assignment
		 *
		 *	\param bus	a SPIClass object
		 *  \param cs	pin number of the CS pin
		 * 	\param en	pin number of the ENABLE pin
		 */
		void begin(SPIClass &bus, uint8_t cs, uint8_t en);
		
		//! \brief deactivates all outputs and disables the TLE94112
		void end(void);
		
		/*! \brief sets the output state and the PWM channel for a halfbridge (only for passive freewheeling)
		 *
		 *	\param hb		halfbridge which will be configured
		 *	\param state	sets the output voltage to high, low or floating
		 *	\param pwm		selects a PWM channel for PWM output
		 *
		 *	\see	HalfBridge
		 *	\see	HBState
		 *	\see	PWMChannel
		 */
		void configHB(HalfBridge hb, HBState state, PWMChannel pwm);
		
		/*! \brief sets the output state and the PWM channel for a halfbridge (allows active freewheeling)
		 *
		 *	\param hb		halfbridge which will be configured
		 *	\param state	sets the output voltage to high, low or floating
		 *	\param pwm		selects a PWM channel for PWM output
		 *	\param activeFW	1 for active freewheeling
		 *					0 for passive freewheeling (default)
		 *
		 *	\see	HalfBridge
		 *	\see	HBState
		 *	\see	PWMChannel
		 */
		void configHB(HalfBridge hb, HBState state, PWMChannel pwm, uint8_t activeFW);
		
		/*! \brief sets the frequency and duty cycle for a PWM channel
		 *
		 *	\param pwm			PWM channel which will be configured
		 *	\param freq			selects the PWM output frequency
		 *	\param dutyCycle	a value from 0 to 255 which sets the dutyCycle
		 *
		 *	\see	PWMChannel
		 *	\see	PWMFreq
		 */
		void configPWM(PWMChannel pwm, PWMFreq freq, uint8_t dutyCycle);
		
		/*! \brief returns a diagnosis value for error detection
		 *
		 *	\return 0 if everything is ok
		 *			non-zero value if errors occurred
		 */
		uint8_t getSysDiagnosis();
		
		/*! \brief shows if errors of a specific type have occurred
		 *
		 *	\param mask	mask to filter for a specific flag
		 *
		 *	\return 	0 if everything is ok
		 *				non-zero value on error condition
		 *
		 *	\see DiagFlag
		 */
		uint8_t getSysDiagnosis(DiagFlag mask);
		
		/*! \brief shows if errors of a specific type have occurred
		 *
		 *	\param mask	mask to filter for one or more specific flags
		 *				this can be a disjunction of DiagFlag values
		 *
		 *	\return 	0 if everything is ok
		 *				non-zero value on error condition
		 *
		 *	\see DiagFlag
		 */
		uint8_t getSysDiagnosis(uint8_t mask);
		
		/*! \brief gets the overcurrent error flag bit for a specific halfbridge
		 *
		 *	\param halfbridge	halfbridge thats overcurrent flag will be returned
		 *
		 *	\return 1 if there HalfBridge was shut down because of an overcurrent
		 *			0 otherwise
		 */
		uint8_t getHBOverCurrent(HalfBridge hb);
		
		/*! \brief gets the openload error flag bit for a specific halfbridge
		 *
		 *	\param halfbridge	halfbridge thats openload flag will be returned
		 *
		 *	\return 1 if there HalfBridge detected an open load
		 *			0 otherwise
		 */
		uint8_t getHBOpenLoad(HalfBridge hb);
		
		//! \brief clears all clearable error flags
		void clearErrors();
	
	private:
		//! \brief enum for the control registers in a TLE94112
		enum CtrlRegisters 
		{
			HB_ACT_1_CTRL = 0,
			HB_ACT_2_CTRL,
			HB_ACT_3_CTRL,
			HB_MODE_1_CTRL,
			HB_MODE_2_CTRL,
			HB_MODE_3_CTRL,
			PWM_CH_FREQ_CTRL, 
			PWM1_DC_CTRL, 
			PWM2_DC_CTRL,
			PWM3_DC_CTRL,
			FW_OL_CTRL,
			FW_CTRL
		};
		
		//! \brief enum for the control registers in a TLE94112
		enum StatusRegisters 
		{
			SYS_DIAG1 = 0,
			OP_ERROR_1_STAT, 
			OP_ERROR_2_STAT, 
			OP_ERROR_3_STAT,
			OP_ERROR_4_STAT,
			OP_ERROR_5_STAT,
			OP_ERROR_6_STAT
		};
		
		//! \brief indicates if TLE94112LE is enabled
		uint8_t mEnabled;
		//! \brief pointer to the SPIClass object representing the bus
		SPIClass *mBus;
		//! \brief pin number of the CS pin
		uint8_t mCsPin;
		//! \brief pin number on the EN pin
		uint8_t mEnPin;
		//! \brief array of register locations for halfbridges
		HalfBridge_t mHalfBridges[TLE94112_NUM_HB];
		//! \brief array of register locations for PWM channels
		PWMchannel_t mPwmChannels[TLE94112_NUM_PWM];
		//! \brief mapping array for control register addresses
		uint8_t mCtrlRegAddresses[TLE94112_NUM_CTRL_REGS];
		//! \brief mirror array for control register data
		uint8_t mCtrlRegData[TLE94112_NUM_CTRL_REGS]; 
		//! \brief mapping array for status register addresses
		uint8_t mStatusRegAddresses[TLE94112_NUM_STATUS_REGS];
		
		//! \brief initializes this object, automatically called by begin()
		void init(void);
		
		/*! \brief	sets the output state and the PWM channel for a halfbridge
		 *			automatically called by the public version of configHB
		 *
		 *	\param hb		halfbridge which will be configured
		 *	\param state	sets the output voltage to high, low or floating
		 *	\param pwm		selects a PWM channel for PWM output
		 *	\param activeFW	1 for active freewheeling
		 *					0 for passive freewheeling (default)
		 */
		void configHB(uint8_t hb, uint8_t state, uint8_t pwm, uint8_t activeFW);
		
		/*! \brief	sets the frequency and duty cycle for a PWM channel
					automatically called by the public version of configPWM
		 *
		 *	\param pwm			PWM channel which will be configured
		 *	\param freq			selects the PWM output frequency
		 *	\param dutyCycle	a value from 0 to 255 which sets the dutyCycle
		 */
		void configPWM(uint8_t pwm, uint8_t freq, uint8_t dutyCycle);
		
		/*! \brief	gets the overcurrent error flag bit for a specific halfbridge
		 * 			automatically called by the public version of getHBOverCurrent
		 *
		 *	\param halfbridge	halfbridge thats overcurrent flag will be returned
		 *
		 *	\return 1 if there HalfBridge was shut down because of an overcurrent
		 *			0 otherwise
		 */
		uint8_t getHBOverCurrent(uint8_t hb);
		
		/*! \brief	gets the openload error flag bit for a specific halfbridge
		 *			automatically called by the public version of getHBOpenLoad
		 *
		 *	\param halfbridge	halfbridge thats openload flag will be returned
		 *
		 *	\return 1 if there HalfBridge detected an open load
		 *			0 otherwise
		 */
		uint8_t getHBOpenLoad(uint8_t hb);
		
		/*! \brief	writes data bits to a control register of the TLE94112
		 *
		 *	\param reg		control register number(mapping array index / CtrlRegisters constant) of the register
		 *	\param mask		mask for the bits that have to be written
		 *	\param shift	data will be shifted left by this amount before masking. This is for the bit alignment of data
		 *	\param data		the data byte that has to be written. It will be shifted and masked before
		 *
		 *	\see CtrlRegisters
		 *	\see TLE94112_NUM_CTRL_REGS
		 *	\see mCtrlRegAddresses
		 *	\see mCtrlRegData
		 */
		void writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data);
		
		/*! \brief	reads one byte from a status register of the TLE94112
		 *
		 *	\param reg	status register number(mapping array index / StatusRegisters constant) of the register
		 *
		 *	\return 	data byte that has been read
		 *
		 *	\see StatusRegisters
		 *	\see TLE94112_NUM_STATUS_REGS
		 *	\see mStatusRegAddresses
		 */
		uint8_t readStatusReg(uint8_t reg);
		
		/*! \brief	reads some bits from a status register of the TLE94112
		 *
		 *	\param reg		status register number(mapping array index / StatusRegisters constant) of the register
		 *	\param mask		mask for the bits that have to be read
		 *	\param shift	data will be shifted right by this amount after masking. This is for the bit alignment of data
		 *
		 *	\return 		data bits that have been read (after masking and shifting)
		 *
		 *	\see StatusRegisters
		 *	\see TLE94112_NUM_STATUS_REGS
		 *	\see mStatusRegAddresses
		 */
		uint8_t readStatusReg(uint8_t reg, uint8_t mask, uint8_t shift);
		
		/*! \brief	clears a status register by writing 0x00 to it
		 *
		 *	\param reg	status register number(mapping array index / StatusRegisters constant) of the register
		 *	
		 *	\see StatusRegisters
		 *	\see TLE94112_NUM_STATUS_REGS
		 *	\see mStatusRegAddresses
		 */
		void clearStatusReg(uint8_t reg);
};

#endif
