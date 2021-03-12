/******************************************************************************
* File Name: app_config.h
*
* Description: This file defines aliases for SPI pins depending on the SPI mode.
*
*******************************************************************************
* (c) 2020, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, translation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death (“High Risk Product”). By
* including Cypress’s product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_
#include "resource_map.h"

/* This code example requires two SPI ports, one as master and the other one 
 * as slave. Set the SPI_MODE macro depending on the kit. Some kits support two 
 * SPI ports which you can configure in SPI_MODE_BOTH whereas some support only
 * one port in which case you can configure the kit in either SPI_MODE_MASTER or 
 * SPI_MODE_SLAVE. See README.md to know more on the kit specific configuration.
 */
#define SPI_MODE_BOTH    0
#define SPI_MODE_MASTER  1
#define SPI_MODE_SLAVE   2

#define SPI_MODE SPI_MODE_BOTH

#if ((SPI_MODE == SPI_MODE_BOTH) || (SPI_MODE == SPI_MODE_MASTER))
    #define mSPI_MOSI               KIT_SPI_MASTER_MOSI
    #define mSPI_MISO               KIT_SPI_MASTER_MISO
    #define mSPI_SCLK               KIT_SPI_MASTER_SCLK
    #define mSPI_SS                 KIT_SPI_MASTER_SS
#endif

#if ((SPI_MODE == SPI_MODE_BOTH) || (SPI_MODE == SPI_MODE_SLAVE))
    #define sSPI_MOSI               KIT_SPI_SLAVE_MOSI
    #define sSPI_MISO               KIT_SPI_SLAVE_MISO
    #define sSPI_SCLK               KIT_SPI_SLAVE_SCLK
    #define sSPI_SS                 KIT_SPI_SLAVE_SS
#endif


#if (SPI_MODE == SPI_MODE_BOTH)
    #if defined (TARGET_CYW9P62S1_43012EVB_01) || defined (TARGET_CY8CPROTO_062S3_4343W)
        #warning For the current TARGET, this example requires the SPI_MODE macro to be configured either in SPI_MODE_MASTER or SPI_MODE_SLAVE, not in SPI_MODE_BOTH.
    #endif
#endif

#endif /* APP_CONFIG_H_ */
