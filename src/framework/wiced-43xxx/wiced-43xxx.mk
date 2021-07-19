#############################################
# Makefile for CYPRESS WICED WICED 43xxx ####
#############################################
# Include library folder in "libraries/drivers/sensors".
# Add lib to demo or snipped to the makefile
# variable $(NAME)_COMPONENTS += libraries/drivers/sensors

NAME := Lib_multi-half-bridge

GLOBAL_DEFINES   := TLE94112_FRAMEWORK=TLE94112_FRMWK_WICED

GLOBAL_INCLUDES  := ../../config \
					../../corelib \
					../../pal \
					pal \
					wrapper

$(NAME)_SOURCES  := ../../corelib/tle94112.cpp \
					../../corelib/tle94112-motor.cpp \
					../../corelib/tle94112-logger.cpp \
					../../pal/gpio.cpp \
					../../pal/spic.cpp \
					pal/gpio-wiced.cpp \
					pal/logger-wiced.cpp \
					pal/timer-wiced.cpp \
					pal/spic-wiced.cpp \
					wrapper/tle94112-wiced.cpp

VALID_PLATFORMS := CYW943907AEVAL1F