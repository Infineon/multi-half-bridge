NAME := App_control2Motors

$(NAME)_SOURCES    := control2Motors.cpp

$(NAME)_INCLUDES += ./

$(NAME)_COMPONENTS := drivers/motor-control/multi-half-bridge/src/framework/wiced-43xxx

VALID_PLATFORMS	:= CYW943907AEVAL1F