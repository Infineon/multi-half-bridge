cmake_minimum_required(VERSION 3.12.4)  

# Arduino Library Template 
set(mhbcore multi-half-bridge-corelib)

project(${mhbcore} CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
set(CMAKE_C_OUTPUT_EXTENSION_REPLACE ON)

# Search for include Files
include_directories(
    src/config
    src/corelib
    src/pal
)

# Header & Source Files
set(Headers
    src/config
    src/corelib
    src/pal
    )

set(Sources
    src/corelib/tle94112-logger.cpp
    src/corelib/tle94112.cpp
    src/corelib/tle94112-motor.cpp
    src/pal/gpio.cpp
    src/pal/spic.cpp
    )

# Add Library
add_library(${mhbcore} ${Sources} ${Headers})

# Currently only using this target for rasbperry pi host
if (CMAKE_HOST_UNIX)
    # Add directory
    add_subdirectory(src/framework/raspberrypi)
endif()

# If the googletest library is in the project folder
if (EXISTS ${CMAKE_SOURCE_DIR}/googletest)
    # Coverage Flags
    set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage -DMHB_ENABLED=0 -DTLE94112_LOGGER_ENABLED=0")
    set(CMAKE_C_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

    # Enable Testing with CTest
    enable_testing()

    # Add GoogleTest 
    add_subdirectory(googletest)
    # Add Tests Folder
    add_subdirectory(test/unit)
endif()
