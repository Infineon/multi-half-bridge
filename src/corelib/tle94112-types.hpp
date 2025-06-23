
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

    #define REG_ACT_1               0x03
    #define REG_ACT_2               0x43
    #define REG_ACT_3               0x23

    #define REG_MODE_1              0x63
    #define REG_MODE_2              0x13
    #define REG_MODE_3              0x53

    #define REG_PWM_CH_FREQ         0x33

    #define REG_PWM_DC_1            0x73
    #define REG_PWM_DC_2            0x0B
    #define REG_PWM_DC_3            0x4B

    #define REG_SYS_DIAG            0x1B
    #define REG_ERR1                0x5B
    #define REG_ERR2                0x3B
    #define REG_ERR3                0x7B
    #define REG_ERR4                0x07
    #define REG_ERR5                0x47
    #define REG_ERR6                0x27

    #define REG_FW_OL               0x2B
    #define REG_FW_CTRL             0x6B

    #define HL_HL                   0b10011001
    #define HL_LH                   0b10010110
    #define LH_HL                   0b01101001
    #define LH_LH                   0b01100110

    #define HH_LL                   0b10100101
    #define LL_HH                   0b01011010

    /** @} */

    /** @} */
}

#endif /** TLE94112_TYPES_HPP_ **/
