
#include "tle94112-pybind.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include <pybind11/pybind11.h>

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(multi_half_bridge_py, m) {

// Wrapper for Tle94112 class
    py::class_<Tle94112>(m,"Tle94112")                      
        .def(py::init<>());
        
// Wrapping variables that are arguements to member functions and are defined as enum
    py::enum_<Tle94112::PWMChannel>(m, "PWMChannel")
        .value("TLE_NOPWM", Tle94112::PWMChannel::TLE_NOPWM)
        .value("TLE_PWM1", Tle94112::PWMChannel::TLE_PWM1)
        .value("TLE_PWM2", Tle94112::PWMChannel::TLE_PWM2)
        .value("TLE_PWM3", Tle94112::PWMChannel::TLE_PWM3)
        .export_values();

    py::enum_<Tle94112::HalfBridge>(m, "HalfBridge")
        .value("TLE_NOHB", Tle94112::HalfBridge::TLE_NOHB)
        .value("TLE_HB1", Tle94112::HalfBridge::TLE_HB1)
        .value("TLE_HB2", Tle94112::HalfBridge::TLE_HB2)
        .value("TLE_HB3", Tle94112::HalfBridge::TLE_HB3)
        .value("TLE_HB4", Tle94112::HalfBridge::TLE_HB4)
        .value("TLE_HB5", Tle94112::HalfBridge::TLE_HB5)
        .value("TLE_HB6", Tle94112::HalfBridge::TLE_HB6)
        .value("TLE_HB7", Tle94112::HalfBridge::TLE_HB7)
        .value("TLE_HB8", Tle94112::HalfBridge::TLE_HB8)
        .value("TLE_HB9", Tle94112::HalfBridge::TLE_HB9)
        .value("TLE_HB10", Tle94112::HalfBridge::TLE_HB10)
        .value("TLE_HB611", Tle94112::HalfBridge::TLE_HB11)
        .value("TLE_HB12", Tle94112::HalfBridge::TLE_HB12)
        .export_values();
    
// Wrapper for child Tle94112Rpi class
    py::class_<Tle94112Rpi, Tle94112>(m, "Tle94112Rpi")     
        .def(py::init<>());

// Wrapper for Tle94112Motor class 
    py::class_<Tle94112Motor> tle94112motor(m, "Tle94112Motor");        
        tle94112motor.def(py::init<Tle94112 &>())
        .def("start", &Tle94112Motor::start, "Start fn")
        
        // Define function as below in case of overloaded functions
        .def("initConnector", static_cast<void (Tle94112Motor::*)(Tle94112Motor::ePolarity,Tle94112::PWMChannel,Tle94112::HalfBridge,Tle94112::HalfBridge,Tle94112::HalfBridge,Tle94112::HalfBridge)>(&Tle94112Motor::initConnector), "initConnector function with no frequency arg");
        //...... Define all members of Tle94112Motor used in framework/raspberrypi/examples here

    py::enum_<Tle94112Motor::ePolarity>(m, "ePolarity")
        .value("LOWSIDE", Tle94112Motor::ePolarity::LOWSIDE)
        .value("HIGHSIDE", Tle94112Motor::ePolarity::HIGHSIDE)
        .export_values();
          

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
#endif /** TLE94112_FRAMEWORK **/