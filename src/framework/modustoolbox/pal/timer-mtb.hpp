/**
 * @file        timer-mtb.hpp
 * @brief       TLE94112 Timer ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TIMER_MTB_HPP_
#define TIMER_MTB_HPP_

#include "cyhal_system.h"
#include "cyhal_timer.h"
#include "timer.hpp"

using namespace tle94112;

/**
 * @addtogroup mtbPal
 * @{
 */

/**
 * @brief MoudusToolbox timer wrapper
 *
 */
class TimerMtb: virtual public Timer
{
	public:
		TimerMtb();
		~TimerMtb();
		Error_t init();
		Error_t deinit();
		Error_t start();
		Error_t elapsed(uint32_t &elapsed);
		Error_t stop();
		Error_t delayMilli(uint32_t timeout);
		Error_t delayMicro(uint32_t timeout);

	private:
					 cyhal_timer_t     timerHandle; /**< Timer handle */
		static const cyhal_timer_cfg_t timerConf;  	/**< Timer configuration handle */
};

/** @} */

#endif /** TIMER_MTB_HPP_ **/