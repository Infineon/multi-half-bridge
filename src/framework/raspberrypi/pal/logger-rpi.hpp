/** 
 * @file        logger-rpi.hpp
 * @brief       TLE94112 Logger Raspberry Pi PAL 
 * @date        April 2021
 * @copyright   Copyright (c) 2020-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_RPI_H_
#define LOGGER_RPI_H_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "logger.hpp"

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

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** TLE94112_FRAMEWORK **/
#endif /** LOGGER_RPI_H_ **/