/*
 *	Arduino library to control Infineon's DC Motor Control Shield with TLE94112
 *
 *	The shield contains twelve independent halfbridges, 
 *	so it can drive up to 6 indipendent (+5 cascaded) bidirectional DC motor(s). 
 *	Each halfbridge provides a high-Voltage (nominal 5.5-18 V) tristate output,  
 *	which is also capable of PWM with 3 different frequencies. 
 *
 *	Have a look at the datasheet for more information. 
 */
 
/*!	\file TLE94112_conf.h
 *	\brief This file is automatically included
 */


#ifndef TLE94112_CONF_H
#define TLE94112_CONF_H

#include "Arduino.h"

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


#endif