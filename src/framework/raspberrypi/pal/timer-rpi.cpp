/**
 * @file        timer-rpi.cpp
 * @brief       Raspberry Pi Timer Platform Abstraction Layer
 * @date        September 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "timer-rpi.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

using namespace tle94112;

/**
 * @brief Constructor of the Raspberry Pi Timer class
 *
 */
TimerRpi::TimerRpi()
{
}

/**
 * @brief Destructor of the Raspberry Pi Timer class
 *
 */
TimerRpi::~TimerRpi()
{
}

/**
 * @brief Initialization of the Timer
 *
 * This function initializes the Timer and sets
 * the elapsed time to zero.
 *
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::init()
{
	startTime = 0;
	return OK;
}

/**
 * @brief Deinitialize the Timer
 *
 * This function deinitializes the Timer and also
 * resets the elapsed time to variable.
 *
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::deinit()
{
	startTime = 0;
	return OK;
}

/**
 * @brief Start the timer
 *
 * This function starts the timer.
 *
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::start()
{
	startTime = bcm2835_st_read()/1000;
	return OK;
}

/**
 * @brief Calculate the elapsed time
 *
 * This function calculates the elapsed time since the
 * start of the timer. The value stored in the given variable
 * is in milliseconds.
 *
 * @param[in]   &elapsed                Address of a value where the elapsed time should be stored
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::elapsed(uint32_t &elapsed)
{
	elapsed = bcm2835_st_read()/1000 - startTime;
	return OK;
}

/**
 * @brief Stop the timer
 *
 * This function stops the timer and resets the
 * start time variable.
 *
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::stop()
{
	startTime = 0;
	return OK;
}

/**
 * @brief Time delay
 *
 * This function causes a desired delay of the application.
 * The input value is given in milliseconds.
 *
 * @param[in]   timeout                 Desired timeout in ms
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::delayMilli(uint32_t timeout)
{
	bcm2835_delay(timeout);
	return OK;
}

/**
 * @brief Time delay
 *
 * This function causes a desired delay of the application.
 * The input value is given in microseconds.
 *
 * @param[in]   timeout                 Desired timeout in us
 * @return      TimerRpi::Error_t
 */
Error_t TimerRpi::delayMicro(uint32_t timeout) 
{
	bcm2835_delayMicroseconds(timeout);
	return OK;
}

#endif /** TLE94112_FRAMEWORK **/
