/*!
 * \file        Tle94112-pal-wiced.hpp
 * \name        Tle94112-pal-wiced.hpp - Cypress Hardware Abstraction Layer
 * \author      Infineon Technologies AG
 * \copyright   2019 Infineon Technologies AG
 * \version     1.5.0
 * \ref         pal_wiced_43xxx
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

#ifndef TLE94112_WICED_HPP_
#define TLE94112_WICED_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

/**
 * @addtogroup tle94112wicedpal
 * @{
 */

#include "../../../corelib/TLE94112.hpp"
#include <gpio-wiced.hpp>
#include <timer-wiced.hpp>
#include <spic-wiced.hpp>
#include <platform.h>
#include <wiced_platform.h>

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
class TLE94112Wiced: virtual public Tle94112
{
	protected:

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
		
		/*! \brief	reads one byte from a status register of the TLE94112
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

};

/**
 * @}
 */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_WICED_HPP_ **/
