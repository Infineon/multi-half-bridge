/**
 * @file        timer-rpi.hpp
 * @brief       TLE94112 Timer Raspberry Pi PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TIMER_RPI_HPP_
#define TIMER_RPI_HPP_

#include <bcm2835.h>
#include "timer.hpp"

using namespace tle94112;

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

#endif /** TIMER_RPI_HPP_ **/