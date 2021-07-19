/**
 * @file        logger.hpp
 * @brief       TLE94112 Logger Platform Abstraction Layer
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef LOGGER_HPP_
#define LOGGER_HPP_

#include "tle94112-conf.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

#include <stdint.h>
#include "../corelib/tle94112-types.hpp"

namespace tle94112
{

/**
 * @addtogroup pal
 * @{
 */

class LoggerPAL
{
    public:

        /**
         * @brief       Initializes the Logger interface
         * @return      TLE94112 error code
         * @retval      OK if success
         * @retval      INTF_ERROR if error
         */
        virtual Error_t     init    () = 0;

        /**
         * @brief       Deinitializes the logger interface
         * @return      TLE94112 error code
         * @retval      OK if success
         * @retval      INTF_ERROR if error
         */
        virtual Error_t     deinit  () = 0;

        /**
         * @brief       Writes in the logger interface
         * @param[in]   *logData    Pointer to the array holding the data to be logged
         * @param[in]   length      Length in bytes of the data to be written
         * @return      TLE94112 error code
         * @retval      OK if success
         * @retval      INTF_ERROR if error
         */
        virtual Error_t     write   (const uint8_t * logData, uint32_t length) = 0;
};

/** @} */

}

#endif /* TLE94112_LOGGER_ENABLED */
#endif /**< LOGGER_HPP_ */