/**
 * @file        gpio-rpi.cpp
 * @brief       TLE94112 GPIO Raspberry Pi API
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "gpio-rpi.hpp"
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

/**
 * @brief Constructor of the Raspberry Pi GPIO class
 *
 * This function sets the basics for a GPIO.
 *
 */
GPIORpi::GPIORpi() : pin(0), mode(BCM2835_GPIO_FSEL_OUTP), logic(POSITIVE)
{ 
}

/**
 * @brief Constructor of the Raspberry Pi GPIO class
 *
 * This function sets the basics for a GPIO. It allows to set the pin number,
 * mode of the pin and the logic level.
 *
 * @param[in]   pin     Number of the desired pin
 * @param[in]   mode    Defines the mode of the pin (INPUT, OUTPUT, etc.)
 * @param[in]   logic   Defines the logic level of the pin
 */
GPIORpi::GPIORpi(uint8_t pin, uint8_t mode, VLogic_t logic): pin(pin), mode(mode), logic(logic)
{
}

/**
 * @brief Initialize the GPIO
 *
 * This function initializes the chosen pin.
 *
 * @return      GPIORpi::Error_t
 */
//GPIORpi::Error_t GPIORpi::init()
Error_t GPIORpi::init()
{
	tle94112::Error_t err = tle94112::OK;
	if (bcm2835_init() <= 0)
	{
		err = tle94112::INTF_ERROR; 
	} 
	
	 bcm2835_gpio_fsel(this->pin, this->mode);

	return err;
}

/**
 * @brief Deinitialize the GPIO
 *
 * This function deinitializes the chosen pin.
 *
 * @return      GPIORpi::Error_t
 */
Error_t GPIORpi::deinit()
{
	bcm2835_close();
	return OK;
}

/**
 * @brief Read GPIO logic level
 *
 * This function reads the logic level of the chosen pin and
 * returns the logic level value.
 *
 * @return      GPIORpi::VLevel_t
 * @retval      0    = GPIO_LOW
 * @retval      1    = GPIO_HIGH
 */
GPIORpi::VLevel_t GPIORpi::read()
{
	return (VLevel_t) bcm2835_gpio_lev(this->pin);
}

/**
 * @brief Set GPIO logic level
 *
 * This functions sets the logic level of the chosen pin.
 *
 * @param[in]   level   Desired logic level of the pin
 * @return      GPIORpi::Error_t
 */
Error_t GPIORpi::write(VLevel_t level)
{
	bcm2835_gpio_write(this->pin, level);
	return OK;
}

/**
 * @brief Enable the GPIO
 *
 * This function enables the chosen pin. Depending on the chosen logic of the pin
 * it sets the right logic level of the pin.
 *
 * @return      GPIORpi::Error_t
 */
Error_t GPIORpi::enable()
{
	if(this->logic == POSITIVE){
		bcm2835_gpio_write(this->pin, GPIO_HIGH);
	}
	else if(this->logic == NEGATIVE){
		bcm2835_gpio_write(this->pin, GPIO_LOW);;
	}
	return tle94112::OK;
}

/**
 * @brief Disable the GPIO
 *
 * This function disables the chosen pin. Depending on the chosen logic of the pin
 * it sets the right logic level of the pin.
 *
 * @return      GPIOIno::Error_t
 */
Error_t GPIORpi::disable()
{
	if(this->logic == POSITIVE){
		bcm2835_gpio_write(this->pin, GPIO_LOW);
	}
	else if(this->logic == NEGATIVE){
		bcm2835_gpio_write(this->pin, GPIO_HIGH);
	}
	return tle94112::OK;
}


#endif /** TLE94112_FRAMEWORK **/



