
#include "tle94112-pybind.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include <pybind11/pybind11.h>
//#include "tle94112-platf-rpi.hpp"
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

template <typename... Args>
using overload_cast_ = pybind11::detail::overload_cast_impl<Args...>;

PYBIND11_MODULE(multi_half_bridge_py, m) {

// Wrapper for Tle94112 class
    py::class_<Tle94112> tle94112(m,"Tle94112");

    tle94112.def(py::init<>())
        .def("begin", &Tle94112::begin, "Begin function")
        .def("end", &Tle94112::end, "End function")
        .def("configHB", overload_cast_<Tle94112::HalfBridge,Tle94112::HBState,Tle94112::PWMChannel>()(&Tle94112::configHB), "Config-HB function")
        .def("configHB", overload_cast_<Tle94112::HalfBridge,Tle94112::HBState,Tle94112::PWMChannel, uint8_t>()(&Tle94112::configHB), "Config-HB function with active free-wheeling")
        .def("configPWM", &Tle94112::configPWM, "Config PWM function")
        .def("getSysDiagnosis",overload_cast_<>()(&Tle94112::getSysDiagnosis), "System-Diagnosis function")
        .def("getSysDiagnosis",overload_cast_<Tle94112::DiagFlag>()(&Tle94112::getSysDiagnosis), "System-Diagnosis function with mask")
        .def("getSysDiagnosis",overload_cast_<uint8_t>()(&Tle94112::getSysDiagnosis), "System-Diagnosis function with mask")
        .def("getHBOverCurrent", &Tle94112::getHBOverCurrent, "Get Half-Bridge over current")
        .def("getHBOpenload", &Tle94112::getHBOpenLoad, "Get Half-Bridge open load")
        .def("clearErrors", &Tle94112::clearErrors, "Clear errors function");
        
// Wrapping variables that are arguements to member functions and are defined as enum
    py::enum_<Tle94112::HalfBridge>(tle94112, "HalfBridge", py::arithmetic())
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
    
    py::enum_<Tle94112::PWMChannel>(tle94112, "PWMChannel", py::arithmetic())
        .value("TLE_NOPWM", Tle94112::PWMChannel::TLE_NOPWM)
        .value("TLE_PWM1", Tle94112::PWMChannel::TLE_PWM1)
        .value("TLE_PWM2", Tle94112::PWMChannel::TLE_PWM2)
        .value("TLE_PWM3", Tle94112::PWMChannel::TLE_PWM3)
        .export_values();

    py::enum_<Tle94112::HBState>(tle94112, "HBState", py::arithmetic())
        .value("TLE_FLOATING", Tle94112::HBState::TLE_FLOATING)
        .value("TLE_LOW", Tle94112::HBState::TLE_LOW)
        .value("TLE_HIGH", Tle94112::HBState::TLE_HIGH)
        .export_values();

    py::enum_<Tle94112::HBOCState>(tle94112, "HBOCState", py::arithmetic())
        .value("TLE_NONE", Tle94112::HBOCState::TLE_NONE)    
        .value("TLE_LOWSIDE", Tle94112::HBOCState::TLE_LOWSIDE)
        .value("TLE_HIGHSIDE", Tle94112::HBOCState::TLE_HIGHSIDE)
        .export_values();

    py::enum_<Tle94112::PWMFreq>(tle94112, "PWMFreq", py::arithmetic())
        .value("TLE_FREQOFF", Tle94112::PWMFreq::TLE_FREQOFF)
        .value("TLE_FREQ80HZ", Tle94112::PWMFreq::TLE_FREQ80HZ)
        .value("TLE_FREQ100HZ", Tle94112::PWMFreq::TLE_FREQ100HZ)
        .value("TLE_FREQ200HZ", Tle94112::PWMFreq::TLE_FREQ200HZ)
        .export_values();

    py::enum_<Tle94112::DiagFlag>(tle94112, "DiagFlag", py::arithmetic())
        .value("TLE_SPI_ERROR", Tle94112::DiagFlag::TLE_SPI_ERROR)
        .value("TLE_LOAD_ERROR", Tle94112::DiagFlag::TLE_LOAD_ERROR)
        .value("TLE_UNDER_VOLTAGE", Tle94112::DiagFlag::TLE_UNDER_VOLTAGE)
        .value("TLE_OVER_VOLTAGE", Tle94112::DiagFlag::TLE_OVER_VOLTAGE)
        .value("TLE_POWER_ON_RESET", Tle94112::DiagFlag::TLE_POWER_ON_RESET)
        .value("TLE_TEMP_SHUTDOWN", Tle94112::DiagFlag::TLE_TEMP_SHUTDOWN)
        .value("TLE_TEMP_WARNING", Tle94112::DiagFlag::TLE_TEMP_WARNING)
        .export_values();

// Wrapper for child Tle94112Rpi class
    py::class_<Tle94112Rpi, Tle94112> tle94112rpi(m, "Tle94112Rpi", py::multiple_inheritance());

    tle94112rpi.def(py::init<>())
        .def(py::init<uint8_t>());

    py::enum_<Tle94112Rpi::TlePinCS>(tle94112rpi, "TlePinCS")
        .value("TLE94112_PIN_CS0", Tle94112Rpi::TlePinCS::TLE94112_PIN_CS0)
        .value("TLE94112_PIN_CS1", Tle94112Rpi::TlePinCS::TLE94112_PIN_CS1)
        .value("TLE94112_PIN_CS2", Tle94112Rpi::TlePinCS::TLE94112_PIN_CS2)
        .value("TLE94112_PIN_CS3", Tle94112Rpi::TlePinCS::TLE94112_PIN_CS3)
        .value("TLE94112_PIN_EN", Tle94112Rpi::TlePinCS::TLE94112_PIN_EN)
        .export_values();
        
// Wrapper for Tle94112Motor class 
    py::class_<Tle94112Motor> tle94112motor(m, "Tle94112Motor");

    tle94112motor.def(py::init<Tle94112 &>(), py::keep_alive<1, 2>())
        .def("begin", &Tle94112Motor::begin, "Begin function")
        .def("end", &Tle94112Motor::end, "End function")
        // Define function as below in case of overloaded functions
        // The overload_cast_ needs the defined template to work (see top of the file)
        .def("initConnector", overload_cast_<Tle94112Motor::ePolarity,Tle94112::PWMChannel,Tle94112::HalfBridge,Tle94112::HalfBridge,Tle94112::HalfBridge,Tle94112::HalfBridge>()(&Tle94112Motor::initConnector), "initConnector without default frequency")
        .def("initConnector", overload_cast_<Tle94112Motor::ePolarity,Tle94112::PWMChannel,Tle94112::PWMFreq,Tle94112::HalfBridge,Tle94112::HalfBridge,Tle94112::HalfBridge,Tle94112::HalfBridge>()(&Tle94112Motor::initConnector), "initConnector with configurable frequency")
        .def("connect", &Tle94112Motor::connect, "Connect function")
        .def("disconnect", &Tle94112Motor::disconnect, "Disconnect function")
        .def("setPwm", overload_cast_<Tle94112Motor::ePolarity,Tle94112::PWMChannel>()(&Tle94112Motor::setPwm), "Set the PWM with default PWM-frequency")
        .def("setPwm", overload_cast_<Tle94112Motor::ePolarity,Tle94112::PWMChannel,Tle94112::PWMFreq>()(&Tle94112Motor::setPwm), "Set the PWM with configurable PWM")
        .def("setPwmFreq", &Tle94112Motor::setPwmFreq, "Set-PWM-Frequency function")
        .def("setActiveFreeWheeling", &Tle94112Motor::setActiveFreeWheeling, "Set-Active-Free-Wheeling function")
        .def("coast", &Tle94112Motor::coast, "Coast function")
        .def("stop", &Tle94112Motor::stop, "Stop function")
        .def("start", &Tle94112Motor::start, "Start function")
        .def("setSpeed", &Tle94112Motor::setSpeed, "Set-Speed function")
        .def("getSpeed", &Tle94112Motor::getSpeed, "Get-Speed function")
        .def("rampSpeed", &Tle94112Motor::rampSpeed, "Ramp-Speed function");

    py::enum_<Tle94112Motor::ePolarity>(tle94112motor, "ePolarity", py::arithmetic())
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