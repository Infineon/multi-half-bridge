/** 
 * @file        logger-psoc6hal.cpp
 * @brief       TLE94112 Logger PSoC6 HAL PAL 
 * @date        April 2021
 * @copyright   Copyright (c) 2020-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#include "logger-psoc6hal.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#if (TLE94112_LOGGER_ENABLED == 1)

#include "cy_retarget_io.h"
#include "tle94112-logger.hpp"

using namespace tle94112;

/**
 * @brief Logger PSoC6 HAL PAL constructor
 */
LoggerPSoC6::LoggerPSoC6()
{

}

/**
 * @brief Logger PSoC6 HAL PAL destructor
 */
LoggerPSoC6::~LoggerPSoC6()
{

}

/**
 * @brief       Initializes the logger PSoC6 HAL PAL 
 * @note        Serial is initialized by the PSoC6 HAL core 
 *              and begun in setup().
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t  LoggerPSoC6::init()
{
  return tle94112::OK;
}

/**
 * @brief       Deinitializes the logger PSoC6 HAL PAL
 * @return      TLE94112 error code
 * @retval      OK always
 */
Error_t   LoggerPSoC6::deinit()
{
  return tle94112::OK;
} 

/**
 * @brief       Writes in the logger PSoC6 HAL PAL
 * 
 * @note        RETARGETTING IS DONE IN MAIN... THIS COULD BE ALSO ADDED TO INIT...
 * 
 * @param[in]   *logData    Pointer to the array holding the data to be logged
 * @param[in]   length      Length in bytes of the data to be written 
 * @return      TLE94112 error code
 * @retval      OK always
 * 
 */
Error_t   LoggerPSoC6::write(const uint8_t * log_data, uint32_t length)
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
LoggerPSoC6 logpalpsoc6;

namespace tle94112
{
Logger    tle_log(static_cast<LoggerPAL*>(&logpalpsoc6));
}

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** TLE94112_FRAMEWORK **/