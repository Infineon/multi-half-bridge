/**
 * @file        gpio-psoc6hal.cpp
 * @brief       TLE94112 GPIO PSoC6 HAL PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "../../../config/tle94112-conf.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

#include "gpio-psoc6hal.hpp"

/**
 * @brief       GPIO PSoC6 HAL constructor
 *
 * @param[in]   pin         GPIO pin number
 * @param[in]   dir         GPIO direction
 * @param[in]   driverMode  GPIO driver mode
 * @param[in]   logic       Voltage logic
 */
GPIOPsoc6hal::GPIOPsoc6hal( cyhal_gpio_t              pin,
							cyhal_gpio_direction_t    dir,
							cyhal_gpio_drive_mode_t   driveMode,
							VLogic_t                  logic)
		: pin(pin), dir(CYHAL_GPIO_DIR_OUTPUT), driveMode(CYHAL_GPIO_DRIVE_NONE), logic(GPIOC::VLogic_t::POSITIVE)
{
	this->pin = pin;
	this->dir = dir;
	this->driveMode = driveMode;
	this->logic = logic;
}

/**
 * @brief GPIO PSOC6 destructor
 */
GPIOPsoc6hal::~GPIOPsoc6hal()
{
	disable();
	deinit();
}

/**
 * @brief   Initializes the PSOC6 GPIO
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  ERROR if initialization error
 */
inline Error_t GPIOPsoc6hal::init()
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_gpio_init(this->pin, this->dir, this->driveMode, 0);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	return err;
}

/**
 * @brief   Initializes the PSOC6 GPIO
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  ERROR if deinitialization error
 */
inline Error_t GPIOPsoc6hal::deinit()
{
	cyhal_gpio_free(this->pin);

	return OK;
}

/**
 * @brief       Reads the PSOC6 GPIO voltage level
 * @return      GPIO voltage level
 * @retval      GPIO_LOW if voltage low
 * @retval      GPIO_HIGH if voltage high
 */
inline GPIOPsoc6hal::VLevel_t GPIOPsoc6hal::read()
{
	return (VLevel_t) (VLevel_t) cyhal_gpio_read(this->pin);
}

/**
 * @brief       Writes the PSOC6 GPIO output voltage level
 * @param[in]   level  Voltage level
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline Error_t GPIOPsoc6hal::write(VLevel_t level)
{
	cyhal_gpio_write(this->pin, level);

	return OK;
}

/**
 * @brief       Enables the PSOC6 output according to the GPIO logic
 *              - Low if negative
 *              - High if positive
 * @return      GPIO interrupt event
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline Error_t GPIOPsoc6hal::enable()
{
	if(this->logic == POSITIVE)
	{
		cyhal_gpio_write(this->pin, GPIO_HIGH);
	}
	else if(this->logic == NEGATIVE)
	{
		cyhal_gpio_write(this->pin, GPIO_LOW);
	}
	return OK;
}

/**
 * @brief       Disables the PSOC6 output according to the GPIO logic
 *              - Low if positive
 *              - High if negative
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline Error_t GPIOPsoc6hal::disable()
{
	if(this->logic == POSITIVE)
	{
		cyhal_gpio_write(this->pin, GPIO_LOW);
	}
	else if(this->logic == NEGATIVE)
	{
		cyhal_gpio_write(this->pin, GPIO_HIGH);
	}
	return OK;
}

#endif /** TLE94112_FRAMEWORK **/
