/**
 * @file        spic.cpp
 * @brief       TLE94112 SPI Platform Abstraction Layer
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_HPP_
#define SPIC_HPP_

#include <stdint.h>
#include "tle94112-types.hpp"

namespace tle94112
{

/**
 * @addtogroup pal
 * @{
 */

class SPIC
{
	public:

		/**
		 * @brief       Initializes the SPIC
		 * @return      SPIC error code
		 * @retval      OK if success
		 * @retval      INIT_ERROR if initialization error
		 */
		virtual Error_t        init        () = 0;

		/**
		 * @brief       Deinitializes the SPIC
		 * @return      SPIC error code
		 * @retval      OK if success
		 * @retval      INIT_ERROR if deinitialization error
		 */
		virtual Error_t       deinit      () = 0;

		/**
		 * @brief           Send/receives data from SPI bus
		 * @param send      address or command to send
		 * @param received  data from SPI bus
		 * @return          SPIC error code
		 * @retval          OK if success
		 * @retval          INIT_ERROR if transfer fails
		 */
		virtual Error_t       transfer(uint8_t send, uint8_t &received) = 0;

		/**
		 * @brief           Send/receives data from SPI bus
		 * @param send      address or command to send
		 * @param received  data from SPI bus
		 * @return          SPIC error code
		 * @retval          OK if success
		 * @retval          INIT_ERROR if transfer fails
		 */
		virtual Error_t       transfer16(uint16_t send, uint16_t &received) = 0;

		Error_t checkErrorStatus();

		private:
		Error_t errorStatus;

};

/** @} */

}

#endif /** SPIC_HPP_ **/
