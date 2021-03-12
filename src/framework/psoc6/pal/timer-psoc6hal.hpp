/**
 * @file        timer-psoc6hal.hpp
 * @brief       PSOC6 Timer PAL
 * @date        Spt 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TIMER_PSOC6_HPP_
#define TIMER_PSOC6_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "../../../pal/timer.hpp"
#include <cyhal_system.h>

/**
 * @addtogroup mtbPal
 * @{
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

#endif /** TLE94112_FRAMEWORK **/
#endif /** TIMER_PSOC6_HPP_ **/
