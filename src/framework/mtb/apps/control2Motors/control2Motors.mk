NAME := App_control2Motors

$(NAME)_SOURCES    := control2Motors.cpp

$(NAME)_INCLUDES += ./

$(NAME)_COMPONENTS := drivers/motor-control/TLE94112

VALID_PLATFORMS	:= CYW943907AEVAL1F