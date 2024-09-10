cmake_minimum_required(VERSION 3.12.4)

# Project name and languages
set(mhbcore multi-half-bridge-corelib)
project(${mhbcore} CXX C)

# Compiler settings
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)

# Manually add Pybind11 path if not found automatically
if (NOT DEFINED PYBIND11_INCLUDE_DIRS)
    find_package(pybind11 REQUIRED)
    set(PYBIND11_INCLUDE_DIRS ${pybind11_INCLUDE_DIRS})
endif()

# Include directories
include_directories(
    ../../config/
    ../../corelib/
    ../../pal/
    pal/
    wrapper/
    ${PYBIND11_INCLUDE_DIRS}
)

# Set header and source files
set(Headers
    pal/
    wrapper/
)

set(Sources
    # List source files
    ../../corelib/tle94112-logger.cpp
    ../../corelib/tle94112.cpp
    ../../corelib/tle94112-motor.cpp
    ../../pal/gpio.cpp
    ../../pal/spic.cpp
    pal/gpio-rpi.cpp
    pal/logger-rpi.cpp
    pal/spic-rpi.cpp
    pal/timer-rpi.cpp
    wrapper/tle94112-rpi.cpp
    wrapper/tle94112-pybind.cpp
)

# Add library
add_library(${mhbcore} ${Sources})

# pybind11 integration
find_package(pybind11 REQUIRED)

pybind11_add_module(multi_half_bridge_py
    pal/gpio-rpi.cpp
    pal/logger-rpi.cpp
    pal/spic-rpi.cpp
    pal/timer-rpi.cpp
    wrapper/tle94112-rpi.cpp
    wrapper/tle94112-pybind.cpp
)

# Add Raspberry Pi bcm library dependency
find_library(bcm2835_dir NAMES libbcm2835.a)
message(STATUS ${bcm2835_dir})

add_library(bcm2835 STATIC IMPORTED)
set_target_properties(bcm2835 PROPERTIES IMPORTED_LOCATION ${bcm2835_dir})

# Link libraries
target_link_libraries(multi_half_bridge_py PUBLIC
    ${mhbcore}
    bcm2835
)

# Compile definitions
if (DEFINED EXAMPLE_VERSION_INFO)
    target_compile_definitions(multi_half_bridge_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
endif()

# Test integration
if (EXISTS ${CMAKE_SOURCE_DIR}/googletest)
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -DMHB_ENABLED=0 -DTLE94112_LOGGER_ENABLED=0")
    set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

    enable_testing()
    add_subdirectory(googletest)
    add_subdirectory(test/unit)
endif()
