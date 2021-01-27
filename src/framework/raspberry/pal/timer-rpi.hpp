/**
 * @file        timer-rpi.hpp
 * @brief       Raspberry Pi Timer PAL
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TIMER_RPI_HPP_
#define TIMER_RPI_HPP_

#include "../../../config/tle94112-conf.hpp"
#include <bcm2835.h>

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../pal/timer.hpp"

/**
 * @addtogroup rpiPal
 * @{
 */

class TimerRpi: virtual public Timer
{
	public:
		TimerRpi();
		~TimerRpi();
		Error_t init();
		Error_t deinit();
		Error_t start();
		Error_t elapsed(uint32_t &elapsed); 
		Error_t stop();
		Error_t delayMilli(uint32_t timeout);
		Error_t delayMicro(uint32_t timeout);

	private:
		uint32_t startTime; 
};
/** @} */

#endif /** TLE94112_FRAMEWORK **/
#endif /** TIMER_RPI_HPP_ **/