/**
 * @file        logger-rpi.cpp
 * @brief       TLE94112 Logger Raspberry Pi PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "logger-rpi.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

#include <stdio.h>
#include <string.h>
#include "tle94112-logger.hpp"

using namespace tle94112;

/**
 * @brief Logger Raspberry Pi PAL constructor
 */
LoggerRpi::LoggerRpi()
{

}

/**
 * @brief Logger Raspberry Pi PAL destructor
 */
LoggerRpi::~LoggerRpi()
{

}

/**
 * @brief       Initializes the logger Raspberry Pi PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t  LoggerRpi::init()
{
  return tle94112::OK;
}

/**
 * @brief       Deinitializes the logger Raspberry Pi PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t   LoggerRpi::deinit()
{
  return tle94112::OK;
}

/**
 * @brief       Writes in the logger Raspberry Pi PAL
 *
 * @param[in]   *logData    Pointer to the array holding the data to be logged
 * @param[in]   length      Length in bytes of the data to be written
 * @return      TLE94112 error code
 * @retval      OK always
 *
 */
Error_t   LoggerRpi::write(const uint8_t * log_data, uint32_t length)
{
  uint8_t log_data_copy[length + 1 ] = {0};
  memcpy(log_data_copy, log_data, length);
  log_data_copy[length] = '\0';

  printf("%s",log_data_copy);

  return tle94112::OK;
}

/**
 * @brief Library Logger
 */
LoggerRpi logpalrpi;

namespace tle94112
{
Logger    tle_log(static_cast<LoggerPAL*>(&logpalrpi));
}

#endif /* TLE94112_LOGGER_ENABLED */