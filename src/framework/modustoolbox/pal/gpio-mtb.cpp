/**
 * @file        gpio-mtb.cpp
 * @brief       TLE94112 GPIO ModusToolbox HAL PAL
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "gpio-mtb.hpp"

/**
 * @brief       GPIO ModusToolbox HAL constructor
 *
 * @param[in]   pin         GPIO pin number
 * @param[in]   dir         GPIO direction
 * @param[in]   driveMode   GPIO driver mode
 * @param[in]   logic       Voltage logic
 */
GPIOMtb::GPIOMtb( cyhal_gpio_t              pin,
				  cyhal_gpio_direction_t    dir,
				  cyhal_gpio_drive_mode_t   driveMode,
				  VLogic_t                  logic)
		: pin(pin), dir(dir), driveMode(driveMode), logic(logic)
{

}

/**
 * @brief GPIO ModusToolbox destructor
 */
GPIOMtb::~GPIOMtb()
{
	disable();
	deinit();
}

/**
 * @brief   Initializes the ModusToolbox GPIO
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  ERROR if initialization error
 */
inline Error_t GPIOMtb::init()
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_gpio_init(this->pin, this->dir, this->driveMode, 0);
	if(CY_RSLT_SUCCESS != cyErr)
		err = INTF_ERROR;

	return err;
}

/**
 * @brief   Initializes the ModusToolbox GPIO
 * @return  GPIO error code
 * @retval  OK if success
 * @retval  ERROR if deinitialization error
 */
inline Error_t GPIOMtb::deinit()
{
	cyhal_gpio_free(this->pin);

	return OK;
}

/**
 * @brief       Reads the ModusToolbox GPIO voltage level
 * @return      GPIO voltage level
 * @retval      GPIO_LOW if voltage low
 * @retval      GPIO_HIGH if voltage high
 */
inline GPIOMtb::VLevel_t GPIOMtb::read()
{
	return (VLevel_t) (VLevel_t) cyhal_gpio_read(this->pin);
}

/**
 * @brief       Writes the ModusToolbox GPIO output voltage level
 * @param[in]   level  Voltage level
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline Error_t GPIOMtb::write(VLevel_t level)
{
	cyhal_gpio_write(this->pin, level);

	return OK;
}

/**
 * @brief       Enables the ModusToolbox output according to the GPIO logic
 *              - Low if negative
 *              - High if positive
 * @return      GPIO interrupt event
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline Error_t GPIOMtb::enable()
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
 * @brief       Disables the ModusToolbox output according to the GPIO logic
 *              - Low if positive
 *              - High if negative
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline Error_t GPIOMtb::disable()
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