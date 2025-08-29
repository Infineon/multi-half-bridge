cmake_minimum_required(VERSION 3.12.4)

# Set the correct module path
set(CMAKE_MODULE_PATH  "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")

# Define variables that would come from root CMakeLists.txt
set(mhbcore multi-half-bridge-corelib)

# Project name and languages
project(${mhbcore} CXX C)



# Manually add Pybind11 path if not found automatically is needed to find pybind11
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

# List source files
set(Sources
    pal/gpio-rpi.cpp
    pal/logger-rpi.cpp
    pal/spic-rpi.cpp
    pal/timer-rpi.cpp
    wrapper/tle94112-rpi.cpp
    wrapper/tle94112-pybind.cpp
)

# Add library
#add_library(${mhbcore} ${Sources})

# pybind11 integration
find_package(pybind11 REQUIRED)


pybind11_add_module(multi_half_bridge_py ${Sources} ${Headers})


# Add Raspberry Pi bcm library dependency
find_library(bcm2835_dir NAMES libbcm2835.a)
message(STATUS ${bcm2835_dir})

add_library(bcm2835 STATIC IMPORTED)
set_target_properties(bcm2835 PROPERTIES IMPORTED_LOCATION ${bcm2835_dir})

# Link libraries
target_link_libraries(multi_half_bridge_py PUBLIC
    bcm2835
    cap
)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(multi_half_bridge_py PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})