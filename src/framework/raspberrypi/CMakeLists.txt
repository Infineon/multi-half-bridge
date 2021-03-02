cmake_minimum_required(VERSION 3.4...3.18)

project(multi-half-bridge-py)

set(Headers
    pal/
    )

set(Sources
    pal/gpio-rpi.cpp
    pal/spic-rpi.cpp
    pal/timer-rpi.cpp
    pal/TLE94112-pal-rpi.cpp
    )

add_subdirectory(tools/pybind11)
pybind11_add_module(multi-half-bridge-py ${Sources} ${Headers})

# Required Libraries
target_link_libraries(multi-half-bridge-py PUBLIC
    multi-half-bridge-corelib
)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(multi-half-bridge-py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})