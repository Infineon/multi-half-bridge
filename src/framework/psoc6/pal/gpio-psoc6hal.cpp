/**
 * @file        gpio-psoc6hal.hpp
 * @brief       PSOC6 PAL for the GPIO
 * @date        Spt 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "gpio-psoc6hal.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

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
inline GPIOPsoc6hal::Error_t GPIOPsoc6hal::init()
{
	Error_t err = OK;

	cy_rslt_t cyErr = cyhal_gpio_init(pin, dir, driveMode, 0);
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
inline GPIOPsoc6hal::Error_t GPIOPsoc6hal::deinit()
{
	cyhal_gpio_free(pin);

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
	return (VLevel_t) (VLevel_t) cyhal_gpio_read(pin);
}

/**
 * @brief       Writes the PSOC6 GPIO output voltage level
 * @param[in]   level  Voltage level
 * @return      GPIO error code
 * @retval      OK if success
 * @retval      ERROR if error
 */
inline GPIOPsoc6hal::Error_t GPIOPsoc6hal::write(VLevel_t level)
{
	cyhal_gpio_write(pin, level);

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
inline GPIOPsoc6hal::Error_t GPIOPsoc6hal::enable()
{
	if(logic == POSITIVE)
	{
		cyhal_gpio_write(pin, GPIO_HIGH);
	}
	else if(logic == NEGATIVE)
	{
		cyhal_gpio_write(pin, GPIO_LOW);
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
inline GPIOPsoc6hal::Error_t GPIOPsoc6hal::disable()
{
	if(logic == POSITIVE)
	{
		cyhal_gpio_write(pin, GPIO_LOW);
	}
	else if(logic == NEGATIVE)
	{
		cyhal_gpio_write(pin, GPIO_HIGH);
	}
	return OK;
}

#endif /** TLE94112_FRAMEWORK **/
