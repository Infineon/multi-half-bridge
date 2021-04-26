/**
 * @file        tle94112-conf.hpp
 * @brief       TLE94112 Library Configuration
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_CONF_HPP_
#define TLE94112_CONF_HPP_

#include "tle94112-conf-opts.hpp"

/**
 * @addtogroup tle94112frmw
 * @{
 */

#ifndef TLE94112_FRAMEWORK
#define TLE94112_FRAMEWORK      TLE94112_FRMWK_ARDUINO
#endif

/**
 * @brief Logger enable
 */

#ifndef TLE94112_LOGGER_ENABLED
#define TLE94112_LOGGER_ENABLED      0           /**< (1) Enabled, (0) Disabled */
#endif

/**
 * @brief Enable for each module logger
 */

#if     (TLE94112_LOGGER_ENABLED == 1)

#define TLE94112_CORE_LOGGER_ENABLED     1           /**< Core module */
#define TLE94112_MOTOR_LOGGER_ENABLED    1           /**< Serial module */
#define TLE94112_REG_LOGGER_ENABLED      1           /**< Register module */
#define TLE94112_APP_LOGGER_ENABLED      1           /**< Application level module */

#endif 

#include "tle94112-conf-dfl.hpp"

/** @} */

#endif /** TLE94112_CONF_HPP_ **/
