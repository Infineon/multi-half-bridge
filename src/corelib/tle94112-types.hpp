
/** 
 * @file        tle94112-types.hpp
 * @brief       TLE94112 Types
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_TYPES_HPP_
#define TLE94112_TYPES_HPP_

namespace tle94112
{

    /**
    * @addtogroup tle94112api
    * @{
    */

    /**
    * @name   Error codes
    * @{
    */
    enum Error_t
    {
        OK          =  0,    /**< No error */
        INTF_ERROR  = -1,    /**< Interface error */
        CONF_ERROR  = -2,    /**< Configuration error */
        READ_ERROR  = -3,    /**< Read error */
        WRITE_ERROR = -4,    /**< Write error */
    };
    /** @} */

    /** @} */
}

#endif /** TLE94112_TYPES_HPP_ **/
