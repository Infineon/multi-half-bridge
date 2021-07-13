/**
 * @file        logger-arduino.cpp
 * @brief       TLE94112 Logger Arduino PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "logger-arduino.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

#include <Arduino.h>
#include "tle94112-logger.hpp"

using namespace tle94112;

/**
 * @brief Logger Arduino PAL constructor
 */
LoggerIno::LoggerIno()
{

}

/**
 * @brief Logger Arduino PAL destructor
 */
LoggerIno::~LoggerIno()
{

}

/**
 * @brief       Initializes the logger Arduino PAL
 * @note        Serial is initialized by the Arduino core
 *              and begun in setup().
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t  LoggerIno::init()
{
  return tle94112::OK;
}

/**
 * @brief       Deinitializes the logger Arduino PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t   LoggerIno::deinit()
{
  return tle94112::OK;
}

/**
 * @brief       Writes in the logger Arduino PAL
 * @param[in]   *logData    Pointer to the array holding the data to be logged
 * @param[in]   length      Length in bytes of the data to be written
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t   LoggerIno::write(const uint8_t * log_data, uint32_t length)
{
  String str = (char*)log_data;

  for(uint32_t i=0; i< length; i++) {
    Serial.print(str.charAt(i));
  }

  return tle94112::OK;
}

/**
 * @brief Library Logger
 */
LoggerIno logpalino;

namespace tle94112
{
Logger    tle_log(static_cast<LoggerPAL*>(&logpalino));
}

#endif /* TLE94112_LOGGER_ENABLED */