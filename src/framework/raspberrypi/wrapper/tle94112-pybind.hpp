

#ifndef TLE94112_PYBIND_HPP_
#define TLE94112_PYBIND_HPP_

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include "../../../corelib/tle94112.hpp"
#include "../../../corelib/tle94112-motor.hpp"
#include "tle94112-rpi.hpp"
// #include <bcm2835.h>

// class Rpi_PinSel{
//     public:
//     Rpi_PinSel(){}
//     enum TlePinCS{
//         TLE94112_PIN_CS0     = RPI_V2_GPIO_P1_24,
//         TLE94112_PIN_CS1     = RPI_V2_GPIO_P1_26,
//         TLE94112_PIN_CS2     = RPI_V2_GPIO_P1_22,
//         TLE94112_PIN_CS3     = RPI_V2_GPIO_P1_15,
//         TLE94112_PIN_EN      = RPI_V2_GPIO_P1_37
//     };
    
// };

#endif /** TLE94112_FRAMEWORK **/
#endif /** TLE94112_PYBIND_HPP_ **/