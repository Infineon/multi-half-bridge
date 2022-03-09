/**
 * @file        timer-mtb.cpp
 * @brief       TLE94112 Timer ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "timer-mtb.hpp"

/**
 * @brief ModusToolbox Timer configuration
 */

/**
 * @brief Constructor of the ModusToolbox Timer class
 *
 */
TimerMtb::TimerMtb()
{
}

/**
 * @brief Destructor of the ModusToolbox Timer class
 *
 */
TimerMtb::~TimerMtb()
{
}

/**
 * @brief Initialization of the Timer
 *
 * This function is initializing the Timer and sets
 * the elapsed time to zero.
 *
 * @return      Error_t
 */
Error_t TimerMtb::init()
{
	Error_t err = OK;

	const cyhal_timer_cfg_t timerConf = 
	{
		.is_continuous = false,
		.direction     = CYHAL_TIMER_DIR_UP,
		.is_compare    = false,
		.period        = 0xFFFFFFFFUL,
		.compare_value = 0,
		.value         = 0
	};


	do
	{
		cy_rslt_t cyErr = cyhal_timer_init(&timerHandle, NC, NULL);
		if(CY_RSLT_SUCCESS != cyErr)
		{
			err = INTF_ERROR;
			break;
		}

		cyErr = cyhal_timer_configure(&timerHandle, &timerConf);
		if(CY_RSLT_SUCCESS != cyErr)
		{
			err = INTF_ERROR;
			break;
		}

		cyErr = cyhal_timer_set_frequency(&timerHandle, 1000);
		if(CY_RSLT_SUCCESS != cyErr)
		{
			err = INTF_ERROR;
		}
	} while (0);

	return err;
}

/**
 * @brief Deinitialize the Timer
 *
 * This function deinitialize the Timer and also
 * resets the elapsed time variable.
 *
 * @return      Error_t
 */
Error_t TimerMtb::deinit()
{
	cyhal_timer_free(&timerHandle);
	return OK;
}

/**
 * @brief Start the timer
 *
 * This function is starting the timer.
 *
 * @return      Error_t
 */
Error_t TimerMtb::start()
{
	Error_t err = OK;

	do
	{
		cy_rslt_t cyErr = cyhal_timer_reset(&timerHandle);
		if(CY_RSLT_SUCCESS != cyErr)
		{
			err = INTF_ERROR;
			break;
		}

		cyErr = cyhal_timer_start(&timerHandle);
		if(CY_RSLT_SUCCESS != cyErr)
		{
			err = INTF_ERROR;
		}
	} while (0);

	return err;
}

/**
 * @brief Calculate the elapsed time
 *
 * This function is calculating the elapsed time since the
 * start of the timer. The value stored in the given variable
 * is in milliseconds.
 *
 * @param[in]   &elapsed                Address of a value where the elapsed time should be stored
 * @return      Error_t
 */
Error_t TimerMtb::elapsed(uint32_t &elapsed)
{
	elapsed = cyhal_timer_read(&timerHandle);
	return OK;
}

/**
 * @brief Stop the timer
 *
 * This function stops the timer and resets the
 * start time variable.
 *
 * @return      Error_t
 */
Error_t TimerMtb::stop()
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_timer_stop(&timerHandle);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	return err;
}

/**
 * @brief Time delay
 *
 * This function is causing a desired delay of the application.
 * The input value is given in milliseconds.
 *
 * @param[in]   timeout                 Desired timeout in ms
 * @return      Error_t
 */
Error_t TimerMtb::delayMilli(uint32_t timeout)
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_system_delay_ms(timeout);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	return err;
}

/**
 * @brief Time delay
 *
 * This function is causing a desired delay of the application.
 * The input value is given in microseconds.
 *
 * @param[in]   timeout                 Desired timeout in us
 * @return      Error_t
 */
Error_t TimerMtb::delayMicro(uint32_t timeout)
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_system_delay_us(timeout);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	return err;
}
