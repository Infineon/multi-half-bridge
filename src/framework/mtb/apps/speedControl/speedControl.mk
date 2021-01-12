NAME := App_speedControl

$(NAME)_SOURCES    := speedControl.cpp

$(NAME)_INCLUDES += ./

$(NAME)_COMPONENTS := drivers/motor-control/TLE94112

VALID_PLATFORMS	:= CYW943907AEVAL1F