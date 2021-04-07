/** 
 * @file        logger-psoc6hal.hpp
 * @brief       TLE94112 Logger PSoC6 HAL PAL 
 * @date        April 2021
 * @copyright   Copyright (c) 2020-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_PSOC6HAL_H_
#define LOGGER_PSOC6HAL_H_

#include "tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "logger.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

using namespace tle94112;

/**
 * @addtogroup psoc6Pal
 * @{
 */

class LoggerPSoC6 : public LoggerPAL
{
        public:
                        LoggerPSoC6  ();
                       ~LoggerPSoC6  (); 
            Error_t     init         ();
            Error_t     deinit       ();
            Error_t     write        (const uint8_t * log_data, uint32_t length);
};

/** @} */

/**
 * @brief Default LoggerIno
 */
extern LoggerPSoC6 logpalpsoc6;

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** TLE94112_FRAMEWORK **/
#endif /** LOGGER_PSOC6HAL_H_ **/