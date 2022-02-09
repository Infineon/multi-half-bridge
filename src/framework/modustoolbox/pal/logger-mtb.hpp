/**
 * @file        logger-mtb.hpp
 * @brief       TLE94112 Logger ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_MTB_HPP_
#define LOGGER_MTB_HPP_

#include "logger.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

using namespace tle94112;

/**
 * @addtogroup mtbPal
 * @{
 */

class LoggerMtb : public LoggerPAL
{
        public:
                        LoggerMtb  ();
                       ~LoggerMtb  ();
            Error_t     init         ();
            Error_t     deinit       ();
            Error_t     write        (const uint8_t * log_data, uint32_t length);
};

/** @} */

/**
 * @brief Default LoggerMtb
 */
extern LoggerMtb logpalmtb;

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** LOGGER_MTB_HPP_ **/