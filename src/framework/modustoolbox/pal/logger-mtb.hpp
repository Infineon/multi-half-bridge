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

/**
 * @brief       ModusToolbox Logger wrapper class
 * 
 * @details     The logger class uses printf() for logging. In the context 
 *              of the ModusToolbox evaluation boards, the retarget-io library
 *              can be used to set as standard output to a UART port.
 *              
 *              Make sure that the retarget-io library is added to your project,
 *              and the enable it in your the main() in the application:
 *                           
 *              @code
 *              #include "cy_retarget_io.h"
 *              //...
 *              int main(void)
 *              {
 *                  cy_rslt_t result;
 * 
 *                  // ... bsp and os initialization
 * 
 *                  result = cy_retarget_io_init( CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX,
 *                                                CY_RETARGET_IO_BAUDRATE);
 *                  if (result != CY_RSLT_SUCCESS)
 *                  {
 *                      __disable_irq();
 *                      CY_ASSERT(0);
 *                  }
 *
 *                  //... rest of main
 *              } 
 *              @endcode
 * 
 *              More information in https://github.com/Infineon/retarget-io.
 */
class LoggerMtb : public LoggerPAL
{
    public:
                   LoggerMtb();
                  ~LoggerMtb();
        Error_t    init     ();
        Error_t    deinit   ();
        Error_t    write    (const uint8_t * log_data, uint32_t length);
};

/** @} */

/**
 * @brief Default LoggerMtb
 */
extern LoggerMtb logpalmtb;

#endif /* TLE94112_LOGGER_ENABLED */
#endif /** LOGGER_MTB_HPP_ **/