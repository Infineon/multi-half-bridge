cmake_minimum_required(VERSION 3.4...3.18)

project(multi_half_bridge_py)

set(Headers
    pal/
    wrapper/
    )

set(Sources
    pal/gpio-rpi.cpp
    pal/spic-rpi.cpp
    pal/timer-rpi.cpp
    pal/TLE94112-pal-rpi.cpp
    wrapper/TLE94112-platf-rpi.cpp
    wrapper/TLE94112-pybind.cpp
    )

add_subdirectory(tools/pybind11)


pybind11_add_module(multi_half_bridge_py ${Sources} ${Headers})

# Required Libraries
target_link_libraries(multi_half_bridge_py PUBLIC
multi-half-bridge-corelib
)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(multi_half_bridge_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})