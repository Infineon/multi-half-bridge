/**
 * @file        gpio.hpp
 * @brief       TLE94112 GPIO Platform Abstraction Layer
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef GPIOC_HPP_
#define GPIOC_HPP_

#include <stdint.h>
#include "tle94112-types.hpp"

namespace tle94112
{

/**
 * @addtogroup pal
 * @{
 */

class GPIOC
{
	public:

		/**
		 * @name   Interrupt event
		 * @{
		 */
		enum IntEvent_t
		{
			INT_FALLING_EDGE   = 0,     /**< Interrupt on falling edge */
			INT_RISING_EDGE    = 1,     /**< Interrupt on rising edge */
		};
		/** @} */

		/**
		 * @name    Voltage level
		 * @{
		 */
		enum VLevel_t
		{
			GPIO_LOW   = 0,        /**< Level low */
			GPIO_HIGH  = 1         /**< Level high */
		};
		/** @} */

		/**
		 * @name    Voltage logic
		 * @{
		 */
		enum VLogic_t
		{
			NEGATIVE = 1,       /**< Negative logic. 0 on voltage level high, 1 on voltage low */
			POSITIVE = 2,       /**< Positive logic. 1 on voltage level high, 0 on voltage low */
		};
		/** @} */

		/**
		 * @brief       Initializes the GPIO
		 * @return      GPIO error code
		 * @retval      OK if success
		 * @retval      INIT_ERROR if initialization error
		 */
		virtual Error_t        init        () = 0;

		/**
			 * @brief       Deinitializes the GPIO
			 * @return      GPIO error code
			 * @retval      OK if success
			 * @retval      INIT_ERROR if deinitialization error
		 */
		virtual Error_t       deinit      () = 0;

		/**
		 * @brief       Reads the GPIO voltage level
		 * @return      GPIO voltage level
		 * @retval      GPIO_LOW if voltage low
		 * @retval      GPIO_HIGH if voltage high
		 */
		virtual VLevel_t       read        () = 0;

		/**
		 * @brief       Writes the GPIO output voltage level
		 * @param[in]   level  Voltage level
		 * @return      GPIO error code
		 * @retval      OK if success
		 * @retval      WRITE_ERROR if write error
		 */
		virtual Error_t        write       (VLevel_t level) = 0;

		/**
		 * @brief       Enables the GPIO output according to the GPIO logic
		 *              - Low if negative
		 *              - High if positive
		 * @return      GPIO interrupt event
		 * @retval      OK if success
		 * @retval      WRITE_ERROR if write error
		 */
		virtual Error_t        enable      () = 0;

		/**
		 * @brief       Disables the GPIO output according to the GPIO logic
		 *              - Low if positive
		 *              - High if negative
		 * @return      GPIO error code
		 * @retval      OK if success
		 * @retval      WRITE_ERROR if write error
		 */
		virtual Error_t        disable     () = 0;

		Error_t checkErrorStatus();

	private:
		Error_t errorStatus;

};

/** @} */

}

#endif /** GPIOC_HPP_ **/
