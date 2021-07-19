/**
 * @file        logger-wiced.cpp
 * @brief       TLE94112 Logger WICED PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "logger-wiced.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

#include <stdio.h>
#include <string.h>
#include "wwd_debug.h"
#include "tle94112-logger.hpp"

using namespace tle94112;

/**
 * @brief Logger WICED PAL constructor
 */
LoggerWiced::LoggerWiced()
{

}

/**
 * @brief Logger WICED PAL destructor
 */
LoggerWiced::~LoggerWiced()
{

}

/**
 * @brief       Initializes the logger WICED PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t  LoggerWiced::init()
{
  return tle94112::OK;
}

/**
 * @brief       Deinitializes the logger WICED PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t   LoggerWiced::deinit()
{
  return tle94112::OK;
}

/**
 * @brief       Writes in the logger WICED PAL
 *
 * @param[in]   *logData    Pointer to the array holding the data to be logged
 * @param[in]   length      Length in bytes of the data to be written
 * @return      TLE94112 error code
 * @retval      OK always
 *
 */
Error_t   LoggerWiced::write(const uint8_t * log_data, uint32_t length)
{
  uint8_t log_data_copy[length + 1 ] = {0};
  memcpy(log_data_copy, log_data, length);
  log_data_copy[length] = '\0';

  WPRINT_MACRO(("%s",log_data_copy));

  return tle94112::OK;
}

/**
 * @brief Library Logger
 */
LoggerWiced logpalwic;

namespace tle94112
{
Logger    tle_log(static_cast<LoggerPAL*>(&logpalwic));
}

#endif /* TLE94112_LOGGER_ENABLED */