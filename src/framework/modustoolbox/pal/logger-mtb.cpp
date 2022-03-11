/**
 * @file        logger-mtb.cpp
 * @brief       TLE94112 Logger ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "logger-mtb.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

#include "cy_retarget_io.h"
#include "tle94112-logger.hpp"

using namespace tle94112;

/**
 * @brief       Logger ModusToolbox HAL PAL constructor
 */
LoggerMtb::LoggerMtb()
{

}

/**
 * @brief       Logger ModusToolbox HAL PAL destructor
 */
LoggerMtb::~LoggerMtb()
{

}

/**
 * @brief       Initializes the logger ModusToolbox HAL PAL
 * @note        Serial is initialized by the ModusToolbox HAL core
 *              and begun in setup().
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t LoggerMtb::init()
{
    return tle94112::OK;
}

/**
 * @brief       Deinitializes the logger ModusToolbox HAL PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t LoggerMtb::deinit()
{
    return tle94112::OK;
}

/**
 * @brief       Writes in the logger ModusToolbox HAL PAL
 *
 * @param[in]   *logData    Pointer to the array holding the data to be logged
 * @param[in]   length      Length in bytes of the data to be written
 * @return      TLE94112 error code
 * @retval      OK always
 *
 */
Error_t LoggerMtb::write(const uint8_t * log_data, uint32_t length)
{
    uint8_t log_data_copy[length + 1 ] = {0};
    memcpy(log_data_copy, log_data, length);
    log_data_copy[length] = '\0';

    printf("%s",log_data_copy);

    return tle94112::OK;
}

/**
 * @brief       Library Logger
 */
LoggerMtb logpalmtb;

namespace tle94112
{
Logger tle_log(static_cast<LoggerPAL*>(&logpalmtb));
}

#endif /* TLE94112_LOGGER_ENABLED */