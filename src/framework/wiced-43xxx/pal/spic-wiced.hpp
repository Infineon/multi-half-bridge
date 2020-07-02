/**
 * @file        spic-wiced.hpp
 * @brief       WICED PAL for the SPI cover
 * @date        June 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */


#ifndef SPIC_WICED_HPP_
#define SPIC_WICED_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "../../../pal/spic.hpp"

/**
 * @addtogroup wicedPal
 * @{
 */


/**
 * @brief Wiced SPIC class
 *
 */
class SPICWiced: virtual public SPIC
{
private:
	uint8_t     lsb;
	uint8_t     mode;
	uint8_t     clock;
	//void        *spi;

public:
				SPICWiced();
				//SPICWiced(uint8_t pin, uint8_t mode, VLogic_t logic);
				~SPICWiced();
	Error_t     init();
	Error_t     deinit();
	Error_t     transfer(uint8_t send, uint8_t &received);
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** SPIC_WICED_HPP_ **/