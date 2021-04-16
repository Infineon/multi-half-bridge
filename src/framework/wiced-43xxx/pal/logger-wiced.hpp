/** 
 * @file        logger-wiced.hpp
 * @brief       TLE94112 Logger WICED PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_WICED_H_
#define LOGGER_WICED_H_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

#include "logger.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

using namespace tle94112;

/**
 * @addtogroup wicedPal
 * @{
 */

class LoggerWiced : public LoggerPAL
{
        public:
                        LoggerWiced  ();
                       ~LoggerWiced  (); 
            Error_t     init         ();
            Error_t     deinit       ();
            Error_t     write        (const uint8_t * log_data, uint32_t length);
};

/** @} */

/**
 * @brief Default LoggerWiced
 */
extern LoggerWiced logpalwic;

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** TLE94112_FRAMEWORK **/
#endif /** LOGGER_WICED_H_ **/