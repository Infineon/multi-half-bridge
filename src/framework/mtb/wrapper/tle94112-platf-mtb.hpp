/**
 * @file        TLE94112-platf-mtb.hpp
 * @brief       TLE94112-platf-mtb.hpp Cypress MTB-43xxx Hardware Platforms
 * @date        Mai 2020
 * @version     2.0.0
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_MTB_HPP_
#define TLE94112_PLATF_MTB_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_MTB)

#include <wiced_platform.h>
#include "../../../corelib/tle94112.hpp"

/**
 * @addtogroup platfMtb
 * @{
 */

/*!
 * Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS1     WICED_GPIO_7

/*!
 * Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to remove the 0 Ohm resistor R7 and solder it to R8
 */
#define TLE94112_PIN_CS2     WICED_GPIO_17

/*!
 * Standard TLE94112 enable pin
 */
#define TLE94112_PIN_EN      WICED_GPIO_36

class Tle94112Wiced: virtual public TLE94112
{
	public:

		//! \brief standard constructor with default pin assignment
		Tle94112Wiced(void);

		/*! \brief constructor with individual pin assignment
		 *
		 * \param bus a void pointer to the object representing the SPI class
		 * \param csPin  pin number of the CS pin
		 */
		Tle94112Wiced(void* bus, uint8_t csPin);

		//! \brief enables and initializes the TLE94112
		void begin(void);

		/*! \brief constructor with individual pin assignment
		 *
		 * \param csPin  pin number of the CS pin
		 */
		void begin(uint8_t csPin);

		//! \brief deactivates all outputs and disables the TLE94112
		void end(void);

};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PLATF_MTB_HPP_ **/
