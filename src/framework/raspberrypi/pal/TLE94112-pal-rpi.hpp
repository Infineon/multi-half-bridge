/*!
 * \file        TLE94112-pal-rpi.hpp
 * \name        TLE94112-pal-rpi.hpp - Raspberry Pi Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2020 Infineon Technologies AG
 * \version     1.0.0
 * \ref         rpiPal
 *
 * SPDX-License-Identifier: MIT
 *
 */

#ifndef TLE94112_PAL_RPI_HPP_
#define TLE94112_PAL_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

/**
 * @addtogroup rpiPal
 * @{
 */

#include "../../../corelib/TLE94112.hpp"
#include "gpio-rpi.hpp"
#include "timer-rpi.hpp"
#include "spic-rpi.hpp"
#include <bcm2835.h>

/**
 * @brief represents a basic TLE94112
 *
 * This class provides a simple API for connecting and controlling motors.
 * Each motor is assigned to a Tle94112 which acts as an output driver. Calls to
 * Tle94112Motor, instances are mapped to call to Tle94112. Therefore, this
 * class does not bring new features, it does only provide further abstraction.
 *
 * @see Tle94112
 */
class TLE94112Rpi: virtual public Tle94112 
{
	protected:

		/*!
		 * \brief writes data bits to a control register of the TLE94112
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

		/*!
		 * \brief reads one byte from a status register of the TLE94112
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

		/*!
		 * \brief reads some bits from a status register of the TLE94112
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

		/*!
		 * \brief clears a status register by writing 0x00 to it
		 *
		 * \param reg status register number(mapping array index / StatusRegisters constant) of the register
		 *
		 * \see StatusRegisters
		 * \see TLE94112_NUM_STATUS_REGS
		 * \see mStatusRegAddresses
		 */
		void clearStatusReg(uint8_t reg);

};
/**
 * @}
 */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PAL_RPI_HPP_ **/