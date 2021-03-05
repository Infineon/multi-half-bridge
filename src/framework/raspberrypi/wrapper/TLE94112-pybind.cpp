#include <pybind11/pybind11.h>
#include "../pal/Python_import.hpp"
#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;
PYBIND11_MODULE(multi_half_bridge_py, m){
    m.def("delay", &delay, "Wrapper for delay function");

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}


