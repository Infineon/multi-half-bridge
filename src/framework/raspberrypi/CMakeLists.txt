cmake_minimum_required(VERSION 3.4...3.18)

project(multi_half_bridge_py)

set(CMAKE_CXX_FLAGS "-DTLE94112_FRAMEWORK=TLE94112_FRMWK_RPI")

set(Headers
    pal/
    wrapper/
    )

set(Sources
    pal/gpio-rpi.cpp
    pal/logger-rpi.cpp
    pal/spic-rpi.cpp
    pal/timer-rpi.cpp
    wrapper/tle94112-rpi.cpp
    wrapper/tle94112-pybind.cpp
    )

# add_subdirectory(tools/pybind11)
find_package(pybind11 REQUIRED)

pybind11_add_module(multi_half_bridge_py ${Sources} ${Headers})

# Adding RPI bcm library dependency
find_library(bcm2835_dir NAMES  libbcm2835.a)
message(STATUS ${bcm2835_dir})

add_library(bcm2835 STATIC IMPORTED)
set_target_properties(bcm2835 PROPERTIES IMPORTED_LOCATION ${bcm2835_dir})

# Required Libraries
target_link_libraries(multi_half_bridge_py PUBLIC
multi-half-bridge-corelib
bcm2835
)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(multi_half_bridge_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})