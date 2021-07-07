/**
 * @file        logger-arduino.hpp
 * @brief       TLE94112 Logger Arduino PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_ARDUINO_H_
#define LOGGER_ARDUINO_H_

#include "tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_ARDUINO)

#include "logger.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

using namespace tle94112;

/**
 * @addtogroup arduinoPal
 * @{
 */

class LoggerIno : public LoggerPAL
{
        public:
                        LoggerIno    ();
                       ~LoggerIno    ();
            Error_t     init         ();
            Error_t     deinit       ();
            Error_t     write        (const uint8_t * log_data, uint32_t length);
};

/** @} */

/**
 * @brief Default LoggerIno
 */
extern LoggerIno logpalino;

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** TLE94112_FRAMEWORK **/
#endif /** LOGGER_ARDUINO_H_ **/