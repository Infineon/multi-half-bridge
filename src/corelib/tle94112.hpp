/**
 * @file        tle94112.hpp
 * @brief       TLE94112 Core API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 * @details 	This library includes the basic common functions to controll the TLE94112 registers
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_HPP_
#define TLE94112_HPP_

#include <stdint.h>
#include <stdlib.h>
#include "timer.hpp"
#include "gpio.hpp"
#include "spic.hpp"

using namespace tle94112;

/**
 * \addtogroup tle94112api
 * @{
 */

/*! \brief the number of halfbridges on a TLE94112 (including no halfbridge)
 *
 * \see mHalfBridges
 * \see HalfBridge
 */
#define TLE94112_NUM_HB             13

/*! \brief the number of pwm modes for a halfbridge (including no pwm)
 *
 * \see mPwmChannels
 * \see PWMChannel
 */
#define TLE94112_NUM_PWM            4

/*! \brief the number of control registers in a TLE94112
 *
 * \see CtrlRegisters
 * \see mCtrlRegAddresses
 * \see mCtrlRegData
 */
#define TLE94112_NUM_CTRL_REGS      12

/*! \brief the number of status registers in a TLE94112
 *
 * \see StatusRegisters
 * \see mStatusRegAddresses
 * \see mStatusRegData
 */
#define TLE94112_NUM_STATUS_REGS    7

/**
 * @brief represents a basic TLE94112
 *
 * This class provides a simple API for connecting and controlling motors.
 * Each motor is assigned to a Tle94112 which acts as output driver. Calls to
 * Tle94112Motor instances are mapped to calls to Tle94112. Therefore, this
 * class does not bring new features, it does only provide further abstraction.
 *
 * @see Tle94112
 */
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

		//! \brief enum for the overcurrent states of a halfbridge
		enum HBOCState
		{
			TLE_NONE = 0b00, TLE_LOWSIDE = 0b01, TLE_HIGHSIDE = 0b10
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

		//! \brief constructor with pal instances
		Tle94112(SPIC * sBus, GPIOC * cs, GPIOC * en, Timer * timer);

		//! \brief standard destructor switches shield off
		~Tle94112();

		//! \brief enables and initializes the TLE94112
		void begin(void);

		//! \brief deactivates all outputs and disables the TLE94112
		void end(void);

		/*! \brief sets the output state and the PWM channel for a halfbridge (only for passive freewheeling)
		 *
		 * \param hb    halfbridge which will be configured
		 * \param state sets the output voltage to high, low or floating
		 * \param pwm   selects a PWM channel for PWM output
		 *
		 * \see HalfBridge
		 * \see HBState
		 * \see PWMChannel
		 */
		void configHB(HalfBridge hb, HBState state, PWMChannel pwm);

		/*! \brief sets the output state and the PWM channel for a halfbridge (allows active freewheeling)
		 *
		 * \param hb       halfbridge which will be configured
		 * \param state    sets the output voltage to high, low or floating
		 * \param pwm      selects a PWM channel for PWM output
		 * \param activeFW 1 for active freewheeling
		 *                 0 for passive freewheeling (default)
		 *
		 * \see HalfBridge
		 * \see HBState
		 * \see PWMChannel
		 */
		void configHB(HalfBridge hb, HBState state, PWMChannel pwm, uint8_t activeFW);

		/*! \brief sets the frequency and duty cycle for a PWM channel
		 *
		 * \param pwm       PWM channel which will be configured
		 * \param freq      selects the PWM output frequency
		 * \param dutyCycle a value from 0 to 255 which sets the dutyCycle
		 *
		 * \see PWMChannel
		 * \see PWMFreq
		 */
		void configPWM(PWMChannel pwm, PWMFreq freq, uint8_t dutyCycle);

		/*! \brief sets LED mode on compatible half bridges (half bridge 1 or 2 of TLE94112)
		 *
		 * \param hb		compatible half bridge to set LED mode
		 * \param active	LED mode active (1) or inactive (0)
		 *
		 * \see HalfBridge
		 *
		 * \return	0 if everything is ok
		 * 			1 if half bridge does not support LED mode
		 */
		uint8_t setLedMode(HalfBridge hb, uint8_t active);

		/*! \brief returns a diagnosis value for error detection
		 *
		 * \return 0 if everything is ok
		 *         non-zero value if errors occurred
		 */
		uint8_t getSysDiagnosis();

		/*! \brief shows if errors of a specific type have occurred
		 *
		 * \param mask mask to filter for a specific flag
		 *
		 * \return 0 if everything is ok
		 *         non-zero value on error condition
		 *
		 * \see DiagFlag
		 */
		uint8_t getSysDiagnosis(DiagFlag mask);

		/*! \brief shows if errors of a specific type have occurred
		 *
		 * \param mask mask to filter for one or more specific flags
		 *             this can be a disjunction of DiagFlag values
		 *
		 * \return 0 if everything is ok
		 *         non-zero value on error condition
		 *
		 * \see DiagFlag
		 */
		uint8_t getSysDiagnosis(uint8_t mask);

		/*! \brief gets the overcurrent error flag bit for a specific halfbridge
		 *
		 * \param hb halfbridge thats overcurrent flag will be returned
		 *
		 * \return 1 if there HalfBridge was shut down because of an overcurrent
		 *         0 otherwise
		 */
		uint8_t getHBOverCurrent(HalfBridge hb);

		/*! \brief gets the openload error flag bit for a specific halfbridge
		 *
		 * \param hb halfbridge thats openload flag will be returned
		 *
		 * \return 1 if there HalfBridge detected an open load
		 *         0 otherwise
		 */
		uint8_t getHBOpenLoad(HalfBridge hb);

		//! \brief clears all clearable error flags
		void clearErrors();

		/*! \brief writes data bits directly to a register of the TLE94112
		 *
		 * \param reg   address of the register to be written to.
		 * \param data  the data byte that has to be written.
		 *
		 * \see mCtrlRegAddresses
		 * \see mCtrlRegData
		 */
		void directWriteReg(uint8_t reg, uint8_t data);

		/*! \brief reads one byte from a status register of the TLE94112
		 *
		 * \param reg status register number(mapping array index / StatusRegisters constant) of the register
		 *
		 * \return data byte that has been read
		 *
		 * \see StatusRegisters
		 * \see TLE94112_NUM_STATUS_REGS
		 * \see mStatusRegAddresses
		 */
		uint8_t readStatusReg(uint8_t reg);

		SPIC     *sBus;      //<! \brief SPI cover class as representation of the SPI bus
		GPIOC    *cs;        //<! \brief shield enable GPIO to switch chipselect on/off
		GPIOC    *en;        //<! \brief shield enable GPIO to switch shield on/off
		Timer    *timer;     //<! \brief timer for delay settings

	protected:

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

		//! \brief enum for the status registers in a TLE94112
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

		//! \brief struct containing register locations for a single halfbridge
		typedef struct
		{
			uint8_t stateReg;
			uint8_t stateMask;
			uint8_t stateShift;
			uint8_t pwmReg;
			uint8_t pwmMask;
			uint8_t pwmShift;
			uint8_t fwReg;
			uint8_t fwMask;
			uint8_t fwShift;
			uint8_t ocReg;
			uint8_t ocMask;
			uint8_t ocShift;
			uint8_t olReg;
			uint8_t olMask;
			uint8_t olShift;
		} HalfBridge_t;

		//! \brief struct containing register locations for a single PWM channel
		typedef struct
		{
			uint8_t freqReg;
			uint8_t freqMask;
			uint8_t freqShift;
			uint8_t dcReg;
			uint8_t dcMask;
			uint8_t dcShift;
		} PWMchannel_t;


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

		/*! \brief sets the output state and the PWM channel for a halfbridge
		 *         automatically called by the public version of configHB
		 *
		 * \param hb       halfbridge which will be configured
		 * \param state    sets the output voltage to high, low or floating
		 * \param pwm      selects a PWM channel for PWM output
		 * \param activeFW 1 for active freewheeling
		 *                 0 for passive freewheeling (default)
		 */
		void _configHB(uint8_t hb, uint8_t state, uint8_t pwm, uint8_t activeFW);

		/*! \brief sets the frequency and duty cycle for a PWM channel
		 *         automatically called by the public version of configPWM
		 *
		 * \param pwm       PWM channel which will be configured
		 * \param freq      selects the PWM output frequency
		 * \param dutyCycle a value from 0 to 255 which sets the dutyCycle
		 */
		void _configPWM(uint8_t pwm, uint8_t freq, uint8_t dutyCycle);

		/*! \brief gets the overcurrent error flag bit for a specific halfbridge
		 *         automatically called by the public version of getHBOverCurrent
		 *
		 * \param hb halfbridge thats overcurrent flag will be returned
		 *
		 * \return 1 if there HalfBridge was shut down because of an overcurrent
		 *         0 otherwise
		 */
		uint8_t _getHBOverCurrent(uint8_t hb);

		/*! \brief gets the openload error flag bit for a specific halfbridge
		 *         automatically called by the public version of getHBOpenLoad
		 *
		 * \param hb halfbridge thats openload flag will be returned
		 *
		 * \return 1 if there HalfBridge detected an open load
		 *         0 otherwise
		 */
		uint8_t _getHBOpenLoad(uint8_t hb);

		/*! \brief writes data bits to a control register of the TLE94112
		 *
		 * \param reg   control register number(mapping array index / CtrlRegisters constant) of the register
		 * \param mask  mask for the bits that have to be written
		 * \param shift data will be shifted left by this amount before masking. This is for the bit alignment of data
		 * \param data  the data byte that has to be written. It will be shifted and masked before
		 *
		 * \see CtrlRegisters
		 * \see TLE94112_NUM_CTRL_REGS
		 * \see mCtrlRegAddresses
		 * \see mCtrlRegData
		 */
		void writeReg(uint8_t reg, uint8_t mask, uint8_t shift, uint8_t data);

		/*! \brief reads some bits from a status register of the TLE94112
		 *
		 * \param reg   status register number(mapping array index / StatusRegisters constant) of the register
		 * \param mask  mask for the bits that have to be read
		 * \param shift data will be shifted right by this amount after masking. This is for the bit alignment of data
		 *
		 * \return data bits that have been read (after masking and shifting)
		 *
		 * \see StatusRegisters
		 * \see TLE94112_NUM_STATUS_REGS
		 * \see mStatusRegAddresses
		 */
		uint8_t readStatusReg(uint8_t reg, uint8_t mask, uint8_t shift);

		/*! \brief clears a status register by writing 0x00 to it
		 *
		 * \param reg status register number(mapping array index / StatusRegisters constant) of the register
		 *
		 * \see StatusRegisters
		 * \see TLE94112_NUM_STATUS_REGS
		 * \see mStatusRegAddresses
		 */
		void clearStatusReg(uint8_t reg);

		uint8_t mEnabled;    //<! \brief indicates if TLE94112LE is enabled

};

/** @} */

#endif /** TLE94112_HPP_ **/
