/**
 * @file        logger-rpi.hpp
 * @brief       TLE94112 Logger Raspberry Pi PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_RPI_HPP_
#define LOGGER_RPI_HPP_

#include "logger.hpp"
#include "tle94112-logger.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

using namespace tle94112;

/**
 * @addtogroup rpiPal
 * @{
 */

class LoggerRpi : public LoggerPAL
{
        public:
                        LoggerRpi    ();
                       ~LoggerRpi    ();
            Error_t     init         ();
            Error_t     deinit       ();
            Error_t     write        (const uint8_t * log_data, uint32_t length);
};

/** @} */

/**
 * @brief Default LoggerRpi
 */
extern LoggerRpi logpalrpi;

#endif /** TLE94112_LOGGER_ENABLED */
#endif /** LOGGER_RPI_HPP_ **/