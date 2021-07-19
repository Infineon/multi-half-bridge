/**
 * @file        tle94112-logger.hpp
 * @brief       TLE94112 Logger
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_LOGGER_HPP_
#define TLE94112_LOGGER_HPP_

#include "tle94112-conf.hpp"

#if (TLE94112_LOGGER_ENABLED == 1)

#include <stdint.h>
#include "logger.hpp"

namespace tle94112
{

class Logger
{
    public:

                Logger              ();
                Logger              (LoggerPAL *logpal);
               ~Logger              ();
        void    init                ();
        void    deinit              ();
        void    print               (const char * format,
                                     ...);
        void    printfModule        (const char * format,
                                     const char * module,
                                     const char * color,
                                     ...);
        void    printModuleHex      (const uint8_t  * array,
                                           uint32_t   length,
                                     const char     * module,
                                     const char     * color);

    private:
        LoggerPAL * logpal;
};

/**
 * @brief Library logger
 */
extern Logger tle_log;

/**
 * Logger colors options
 */
#define TLE94112_LOGGER_COLOR_RED                  "\x1b[31m"
#define TLE94112_LOGGER_COLOR_GREEN                "\x1b[32m"
#define TLE94112_LOGGER_COLOR_YELLOW               "\x1b[33m"
#define TLE94112_LOGGER_COLOR_BLUE                 "\x1b[34m"
#define TLE94112_LOGGER_COLOR_MAGENTA              "\x1b[35m"
#define TLE94112_LOGGER_COLOR_CYAN                 "\x1b[36m"
#define TLE94112_LOGGER_COLOR_LIGHT_GREY           "\x1b[90m"
#define TLE94112_LOGGER_COLOR_LIGHT_RED            "\x1b[91m"
#define TLE94112_LOGGER_COLOR_LIGHT_GREEN          "\x1b[92m"
#define TLE94112_LOGGER_COLOR_LIGHT_YELLOW         "\x1b[93m"
#define TLE94112_LOGGER_COLOR_LIGHT_BLUE           "\x1b[94m"
#define TLE94112_LOGGER_COLOR_LIGHT_MAGENTA        "\x1b[95m"
#define TLE94112_LOGGER_COLOR_LIGHT_CYAN           "\x1b[96m"
#define TLE94112_LOGGER_COLOR_DEFAULT              "\x1b[0m"

/**
 * @brief TLE94112 logger module
 */

/**
 *  Logger color for different error types
 */
#define TLE94112_LOGGER_ERROR_COLOR               TLE94112_LOGGER_COLOR_RED
#define TLE94112_LOGGER_WARNING_COLOR             TLE94112_LOGGER_COLOR_YELLOW


#define TLE94112_LOG_INIT()\
{\
    tle_log.init();\
}

#define TLE94112_LOG_DEINIT()\
{\
    tle_log.deinit();\
}

/**
 * @brief TLE94112 core logger module
 */
#if (TLE94112_CORE_LOGGER_ENABLED == 1)

#define TLE94112_LOGGER_SERVICE               "[tle94112]        : "
#define TLE94112_LOGGER_COLOR                 TLE94112_LOGGER_COLOR_GREEN

#define TLE94112_LOG_MSG(str)\
{\
    tle_log.printfModule(str, TLE94112_LOGGER_SERVICE, TLE94112_LOGGER_COLOR);\
}

#define TLE94112_LOG_RETURN(ret)\
{\
    if( 0 > ret)\
    {\
        tle_log.printfModule("fail with return code %i", TLE94112_LOGGER_SERVICE, TLE94112_LOGGER_ERROR_COLOR, ret);\
    }\
    else\
    {\
        tle_log.printfModule("pass", TLE94112_LOGGER_SERVICE, TLE94112_LOGGER_COLOR);\
    }\
}

#else

#define TLE94112_LOG_MSG(str)                 {   }
#define TLE94112_LOG_RETURN(ret)              {   }

#endif /* TLE94112_CORE_LOGGER_ENABLED */

/**
 * @brief TLE94112 motor logger module
 */
#if (TLE94112_MOTOR_LOGGER_ENABLED == 1)

#define TLE94112_MOTOR_LOGGER_SERVICE               "[tle94112 motor]  : "
#define TLE94112_MOTOR_LOGGER_COLOR                 TLE94112_LOGGER_COLOR_BLUE

#define TLE94112_MOTOR_LOG_MSG(str)\
{\
    tle_log.printfModule(str, TLE94112_MOTOR_LOGGER_SERVICE, TLE94112_MOTOR_LOGGER_COLOR);\
}

#define TLE94112_MOTOR_LOG_RETURN(ret)\
{\
    if( 0 > ret)\
    {\
        tle_log.printfModule("fail with return code %i", TLE94112_MOTOR_LOGGER_SERVICE, TLE94112_LOGGER_ERROR_COLOR, ret);\
    }\
    else\
    {\
        tle_log.printfModule("pass", TLE94112_MOTOR_LOGGER_SERVICE, TLE94112_MOTOR_LOGGER_COLOR);\
    }\
}

#else

#define TLE94112_MOTOR_LOG_MSG(str)                 {   }
#define TLE94112_MOTOR_LOG_RETURN(ret)              {   }

#endif /* TLE94112_MOTOR_LOGGER_ENABLED */

/**
 * @brief TLE94112 Register module
 */
#if (TLE94112_REG_LOGGER_ENABLED == 1)

#define TLE94112_REG_LOGGER_SERVICE               "[tle94112 reg]    : "
#define TLE94112_REG_LOGGER_COLOR                 TLE94112_LOGGER_COLOR_GREEN

#define TLE94112_REG_LOG_MSG(str)\
{\
    tle_log.printfModule(str, TLE94112_REG_LOGGER_SERVICE, TLE94112_REG_LOGGER_COLOR);\
}

#define TLE94112_REG_LOG_RETURN(ret)\
{\
    if( 0 > ret)\
    {\
        tle_log.printfModule("fail with return code %i", TLE94112_REG_LOGGER_SERVICE, TLE94112_LOGGER_ERROR_COLOR, ret);\
    }\
    else\
    {\
        tle_log.printfModule("pass", TLE94112_REG_LOGGER_SERVICE, TLE94112_REG_LOGGER_COLOR);\
    }\
}

#define TLE94112_REG_VALUE_HEX(addr_ptr)\
{\
    tle_log.printModuleHex(addr_ptr, 1, TLE94112_REG_LOGGER_SERVICE, TLE94112_REG_LOGGER_COLOR);\
}

#define TLE94112_REG_BITF_VALUE(map, addr, bitf)\
{\
    tle_log.printfModule("%x :: 0x%02x -> bfield 0x%02x", TLE94112_REG_LOGGER_SERVICE, TLE94112_REG_LOGGER_COLOR, addr, map[addr], bitf);\
}

#define TLE94112_REG_MAP_HEX(map, length, addr)\
{\
    tle_log.print("%s%s", TLE94112_REG_LOGGER_COLOR, TLE94112_REG_LOGGER_SERVICE);\
    tle_log.print("%x :: 0x%02x\r\n", 0, map[0]);\
    for(uint8_t i = 1; i < length; i++)\
    {\
        tle_log.print("%17x :: ", i);\
        tle_log.print("0x%02x", map[i]);\
        if(i == addr)\
            tle_log.print("<---");\
            	                    \
        tle_log.print("\r\n");\
    }\
    tle_log.print("%s", TLE94112_LOGGER_COLOR_DEFAULT);\
}

#else

#define TLE94112_REG_VALUE_HEX(addr_ptr)          {   }
#define TLE94112_REG_BITF_VALUE(map, addr, bitf)  {   }
#define TLE94112_REG_MAP_HEX(map, length, addr)   {   }


#endif /* TLE94112_REG_LOGGER_ENABLED */

/**
 * @brief TLE94112 Application module
 */
#if (TLE94112_APP_LOGGER_ENABLED == 1)

/**
 *  Logger color for different error types
 */
#define TLE94112_APP_LOGGER_ERROR_COLOR               TLE94112_LOGGER_COLOR_RED
#define TLE94112_APP_LOGGER_WARNING_COLOR             TLE94112_LOGGER_COLOR_YELLOW


#define TLE94112_APP_LOGGER_SERVICE               "[tle94112 app]    : "
#define TLE94112_APP_LOGGER_COLOR                 TLE94112_LOGGER_COLOR_MAGENTA

#define TLE94112_APP_LOG_MSG(str)\
{\
    tle_log.printfModule(str, TLE94112_APP_LOGGER_SERVICE, TLE94112_APP_LOGGER_COLOR);\
}

#define TLE94112_APP_LOG_VAR(str, var)\
{\
    tle_log.printfModule(str, TLE94112_APP_LOGGER_SERVICE, TLE94112_APP_LOGGER_COLOR, var);\
}\

#define TLE94112_APP_LOG_RETURN(ret)\
{\
    if( 0 > ret)\
    {\
        tle_log.printfModule("fail with return code %i", TLE94112_APP_LOGGER_SERVICE, TLE94112_APP_LOGGER_ERROR_COLOR, ret);\
    }\
    else\
    {\
        tle_log.printfModule("pass", TLE94112_APP_LOGGER_SERVICE, TLE94112_APP_LOGGER_COLOR);\
    }\
}

#else

#define TLE94112_APP_LOG_MSG(str)        {}
#define TLE94112_APP_LOG_VAR(str, var)   {}
#define TLE94112_APP_LOG_RETURN(ret)     {}

#endif /* TLE94112_APP_LOGGER_ENABLED */

}

#else

/**
 * Logger not enabled. All macros are empty.
 */

#define TLE94112_LOG_INIT()                       {   }
#define TLE94112_LOG_DEINIT()                     {   }

#define TLE94112_LOG_MSG(str)                     {   }
#define TLE94112_LOG_RETURN(ret)                  {   }

#define TLE94112_MOTOR_LOG_MSG(str)               {   }
#define TLE94112_MOTOR_LOG_RETURN(ret)            {   }

#define TLE94112_REG_BITF_VALUE(map, addr, bitf)  {   }
#define TLE94112_REG_MAP_HEX(map, length, addr)   {   }

#define TLE94112_APP_LOG_MSG(str)                 {   }
#define TLE94112_APP_LOG_VAR(str, var)            {   }
#define TLE94112_APP_LOG_RETURN(ret)              {   }

#endif /* TLE94112_LOGGER_ENABLED */

#endif /* TLE94112_LOGGER_HPP_ */