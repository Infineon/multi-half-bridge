/**
 * @file        timer-psoc6hal.hpp
 * @brief       TLE94112 Timer PSoC6 HAL PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TIMER_PSOC6HAL_HPP_
#define TIMER_PSOC6HAL_HPP_

#include "cyhal_system.h"
#include "cyhal_timer.h"
#include "timer.hpp"

using namespace tle94112;

/**
 * @addtogroup psoc6Pal
 * @{
 */

/**
 * @brief psoc6 timer wrapper
 *
 */
class TimerPsoc6hal: virtual public Timer
{
	public:
		TimerPsoc6hal();
		~TimerPsoc6hal();
		Error_t init();
		Error_t deinit();
		Error_t start();
		Error_t elapsed(uint32_t &elapsed);
		Error_t stop();
		Error_t delayMilli(uint32_t timeout);
		Error_t delayMicro(uint32_t timeout);

	private:
		cyhal_timer_t     timerHandle;  /**< Timer handle */
		cyhal_timer_cfg_t timerConf;    /**< Timer configuration handle */
};

/** @} */

#endif /** TIMER_PSOC6HAL_HPP_ **/