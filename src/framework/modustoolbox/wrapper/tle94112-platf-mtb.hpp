/**
 * @file        tle94112-platf-mtb.hpp
 * @brief       TLE94112 ModusToolbox Hardware Platforms
 * @copyright   Copyright (c) 2019-2021 Infineon Technologies AG
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef TLE94112_PLATF_MTB_HPP_
#define TLE94112_PLATF_MTB_HPP_

/**
 * @addtogroup mtbPlatf
 * @{
 */

/**
 * @brief Different SPI pinsettings for different ModusToolbox supported boards
 *
 */
#ifndef defined (KIT_SPI_MASTER_MOSI) || defined (KIT_SPI_MASTER_MISO) || \
		defined (KIT_SPI_MASTER_SCLK) || defined (KIT_SPI_MASTER_SS)

#if defined (TARGET_CY8CKIT_062_BLE) || defined (TARGET_CYW9P62S1_43438EVB_01) || \
	defined (TARGET_CY8CKIT_062_WIFI_BT) || defined (TARGET_CY8CKIT_062S2_43012) || \
	defined (TARGET_CYW9P62S1_43012EVB_01) || defined (TARGET_CY8CKIT_064B0S2_4343W)
	#define KIT_SPI_MASTER_MOSI               (CYBSP_SPI_MOSI)
	#define KIT_SPI_MASTER_MISO               (CYBSP_SPI_MISO)
	#define KIT_SPI_MASTER_SCLK               (CYBSP_SPI_CLK)
	#define KIT_SPI_MASTER_SS                 (CYBSP_SPI_CS)
#elif defined (TARGET_CY8CPROTO_063_BLE)
	#define KIT_SPI_MASTER_MOSI               (P9_0)
	#define KIT_SPI_MASTER_MISO               (P9_1)
	#define KIT_SPI_MASTER_SCLK               (P9_2)
	#define KIT_SPI_MASTER_SS                 (P9_3)
#elif defined (TARGET_CY8CPROTO_062S3_4343W)
	#define KIT_SPI_MASTER_MOSI               (P5_0)
	#define KIT_SPI_MASTER_MISO               (P5_1)
	#define KIT_SPI_MASTER_SCLK               (P11_2)
	#define KIT_SPI_MASTER_SS                 (P11_3)
#elif  defined (TARGET_CY8CPROTO_062_4343W)
	#define KIT_SPI_MASTER_MOSI               (P6_0)
	#define KIT_SPI_MASTER_MISO               (P6_1)
	#define KIT_SPI_MASTER_SCLK               (P6_2)
	#define KIT_SPI_MASTER_SS                 (P6_3)
#else
	#error Unsupported kit. Define pins for SPI master.
#endif

#endif

/**
 * @brief Standard chip select pin for first TLE94112 shield
 */
#define TLE94112_PIN_CS1     KIT_SPI_MASTER_SS

/**
 * @brief Standard chip select pin for second TLE94112 shield
 * To use a second shield with different CS pin you have
 * to remove the 0 Ohm resistor R7 and solder it to R8
 */
#ifndef TLE94112_PIN_CS2
#define TLE94112_PIN_CS2     (P5_6)
#endif /** TLE94112_PIN_CS2 */

/**
 * @brief Standard TLE94112 enable pin
 */
#ifndef TLE94112_PIN_EN
#define TLE94112_PIN_EN      (P5_7)
#endif /** TLE94112_PIN_EN */

/** @} */

#endif /** TLE94112_PLATF_MTB_HPP_ **/