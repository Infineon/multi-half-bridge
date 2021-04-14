#############################################
# Makefile for CYPRESS WICED WICED 43xxx ####
#############################################
# Include library folder in "libraries/drivers/sensors".
# Add lib to demo or snipped to the makefile
# variable $(NAME)_COMPONENTS += libraries/drivers/sensors

NAME := Lib_multi-half-bridge

GLOBAL_DEFINES   := TLE94112_FRAMEWORK=TLE94112_FRMWK_WICED

GLOBAL_INCLUDES  := src/config \
					src/corelib \
					src/pal \
					src/framework/wiced-43xxx/pal \
					src/framework/wiced-43xxx/wrapper

$(NAME)_SOURCES  := src/corelib/tle94112.cpp \
					src/corelib/tle94112-motor.cpp \
					src/corelib/tle94112-logger.cpp \
					src/pal/gpio.cpp \
					src/pal/spic.cpp \
					src/framework/wiced-43xxx/pal/gpio-wiced.cpp \
					src/framework/wiced-43xxx/pal/logger-wiced.cpp \
					src/framework/wiced-43xxx/pal/timer-wiced.cpp \
					src/framework/wiced-43xxx/pal/spic-wiced.cpp \
					src/framework/wiced-43xxx/wrapper/tle94112-wiced.cpp \

VALID_PLATFORMS := CYW943907AEVAL1F