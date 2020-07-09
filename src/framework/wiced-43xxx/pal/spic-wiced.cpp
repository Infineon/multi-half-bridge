/**
 * @file        SPIC-arduino.hpp
 * @brief       Arduino PAL for the SPI cover
 * @date        June 2020
 * @copyright   Copyright (c) 2019-2020 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#include "spic-wiced.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_WICED)

/**
 * @brief Constructor of the WICED SPIC class
 *
 * This function is setting the basics for a SPIC and the default spi.
 *
 */
SPICWiced::SPICWiced() : pin(WICED_GPIO_22), port(WICED_SPI_1)
{
	wiced_spi_device_t SPI = {
		.port = port,
		.chip_select = pin,
		.speed = 1000000,
		.mode = (SPI_CLOCK_RISING_EDGE | SPI_CLOCK_IDLE_LOW | SPI_NO_DMA | SPI_LSB_FIRST | SPI_CS_ACTIVE_LOW),
		.bits = 8,
	};
	SPICWiced(&SPI);
}

/**
 * @brief Constructor of the WICED SPIC class
 *
 * This function is setting the basics for a SPIC. It allows to set the
 * SPI channel and the chipselect pin number.
 *
 * @param[in]   port    SPI channel to be used
 * @param[in]   pin     Number of the desired pin
 */
SPICWiced::SPICWiced(wiced_spi_t port, wiced_gpio_t pin): pin(pin), port(port)
{
	wiced_spi_device_t SPI = {
		.port = port,
		.chip_select = pin,
		.speed = 1000000,
		.mode = (SPI_CLOCK_RISING_EDGE | SPI_CLOCK_IDLE_LOW | SPI_NO_DMA | SPI_LSB_FIRST | SPI_CS_ACTIVE_LOW),
		.bits = 8,
	};
	SPICWiced(&SPI);
}

/**
 * @brief Constructor of the WICED SPIC class
 *
 * This function is setting the basics for a SPIC. It allows to set the pin number,
 * mode of the pin and the logic level.
 *
 * @param[in]   pin     Number of the desired pin
 * @param[in]   mode    Defines the mode of the pin (INPUT, OUTPUT, etc.)
 * @param[in]   logic   Defines the logic level of the pin
 */
SPICWiced::SPICWiced(wiced_spi_device_t *SPI)
{
	this->spi = SPI;
}

/**
 * @brief Initialize the SPIC
 *
 * This function is initializing the chosen spi channel
 * with the given values for lsb,clock and mode
 *
 * @return      SPICWiced::Error_t
 */
SPICWiced::Error_t SPICWiced::init()
{
	wiced_spi_init( &spi );
	return OK;
}

/**
 * @brief Deinitialize the SPIC
 *
 * This function is deinitializing the chosen spi channel.
 *
 * @return      SPICWiced::Error_t
 */
SPICWiced::Error_t SPICWiced::deinit()
{
	wiced_spi_deinit( &spi );
	return OK;
}

/**
 * @brief transfers a data package via the spi bus
 *
 * @param send         address and/or command to send
 * @param received     received data from spi bus
 * @return             SPICWiced::Error_t
 */
SPICWiced::Error_t SPICWiced::transfer(uint8_t send, uint8_t &received)
{
	segment->sendBuffer = send;
	segment->receiveBuffer = received;
	wiced_spi_transfer(&spi, &segment, 1);
	return OK;
}

#endif /** TLE94112_FRAMEWORK **/