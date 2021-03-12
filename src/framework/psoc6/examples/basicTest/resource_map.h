/******************************************************************************
* File Name: resource_map.h
*
* Description: This file defines the SPI pin map for all the supported kits.
*
*******************************************************************************
* (c) 2019-2020, Cypress Semiconductor Corporation. All rights reserved.
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

#ifndef RESOURCE_MAP_H_
#define RESOURCE_MAP_H_
#include "cybsp.h"

#if defined (TARGET_CY8CPROTO_063_BLE)      
    #define KIT_SPI_MASTER_MOSI               (P9_0)
    #define KIT_SPI_MASTER_MISO               (P9_1)
    #define KIT_SPI_MASTER_SCLK               (P9_2)
    #define KIT_SPI_MASTER_SS                 (P9_3)
#elif defined (TARGET_CY8CPROTO_062S3_4343W)
    #define KIT_SPI_MASTER_MOSI               (P5_0)
    #define KIT_SPI_MASTER_MISO               (P5_1)
    #define KIT_SPI_MASTER_SCLK               (P11_2)
    #define KIT_SPI_MASTER_SS                 (P11_3)
#elif defined (TARGET_CY8CKIT_062_BLE) || defined (TARGET_CYW9P62S1_43438EVB_01) || \
    defined (TARGET_CY8CKIT_062_WIFI_BT) || defined (TARGET_CY8CKIT_062S2_43012) || \
    defined (TARGET_CYW9P62S1_43012EVB_01) || defined (TARGET_CY8CKIT_064B0S2_4343W)
    #define KIT_SPI_MASTER_MOSI               CYBSP_SPI_MOSI
    #define KIT_SPI_MASTER_MISO               CYBSP_SPI_MISO
    #define KIT_SPI_MASTER_SCLK               CYBSP_SPI_CLK
    #define KIT_SPI_MASTER_SS                 CYBSP_SPI_CS
#elif  defined (TARGET_CY8CPROTO_062_4343W)                                                
    #define KIT_SPI_MASTER_MOSI               (P6_0)
    #define KIT_SPI_MASTER_MISO               (P6_1)
    #define KIT_SPI_MASTER_SCLK               (P6_2)
    #define KIT_SPI_MASTER_SS                 (P6_3)
#else
    #error Unsupported kit. Define pins for SPI master.
#endif

#if defined (TARGET_CY8CPROTO_062_4343W)                    
    #define KIT_SPI_SLAVE_MOSI               (P9_0)
    #define KIT_SPI_SLAVE_MISO               (P9_1)
    #define KIT_SPI_SLAVE_SCLK               (P9_2)
    #define KIT_SPI_SLAVE_SS                 (P9_3)
#elif defined (TARGET_CY8CPROTO_062S3_4343W)
    #define KIT_SPI_SLAVE_MOSI               (P5_0)
    #define KIT_SPI_SLAVE_MISO               (P5_1)
    #define KIT_SPI_SLAVE_SCLK               (P11_2)
    #define KIT_SPI_SLAVE_SS                 (P11_3)
#elif defined (TARGET_CYW9P62S1_43012EVB_01)
    #define KIT_SPI_SLAVE_MOSI               CYBSP_SPI_MOSI
    #define KIT_SPI_SLAVE_MISO               CYBSP_SPI_MISO
    #define KIT_SPI_SLAVE_SCLK               CYBSP_SPI_CLK
    #define KIT_SPI_SLAVE_SS                 CYBSP_SPI_CS
#elif defined (TARGET_CY8CKIT_062_BLE) || defined (TARGET_CY8CKIT_062_WIFI_BT) || \
    defined (TARGET_CY8CPROTO_063_BLE) || defined (TARGET_CY8CKIT_062S2_43012) || \
    defined (TARGET_CYW9P62S1_43438EVB_01) || defined (TARGET_CY8CKIT_064B0S2_4343W)
    #define KIT_SPI_SLAVE_MOSI               (P10_0)
    #define KIT_SPI_SLAVE_MISO               (P10_1)
    #define KIT_SPI_SLAVE_SCLK               (P10_2)
    #define KIT_SPI_SLAVE_SS                 (P10_3)
#else
    #error Unsupported kit. Define pins for SPI Slave.
#endif

#endif /* RESOURCE_MAP_H_ */
