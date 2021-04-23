/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the Empty PSoC6 Application
*              for ModusToolbox.
*
* Related Document: See README.md
*
*
*******************************************************************************
* (c) 2019-2020, Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* ("Software"), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries ("Cypress") and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software ("EULA").
*
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress's integrated circuit products.
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
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer of such
* system or application assumes all risk of such use and in doing so agrees to
* indemnify Cypress against all liability.
*******************************************************************************/

/*
 * As this library works with multiple frameworks,
 * this part is needed to avoid trying to compile
 * this example from other frameworks.
 */
#include "../../../../config/tle94112-conf.hpp"
#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_PSOC6)

extern "C"
{
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
}

#include "basicTest/basicTest.hpp"
#include "advancedTest/advancedTest.hpp"
#include "errorDiagnosis/errorDiagnosis.hpp"
#include "halfBridge/halfBridge.hpp"
#include "ledMode/ledMode.hpp"
#include "stepperMotor/stepperMotor.hpp"
#include "multipleControllers/multipleControllers.hpp"
#include "multipleMotors/multipleMotors.hpp"


// Select the number of connected half-bridges to be used
// If only two half-bridges are used (one high, one low) than a motor with only 0.9A can be used,
// otherwise the controller will signal an over-current error.
// If you motor or application needs more, than multiple half-bridges can be connected.
// If you choose four half-bridges, than 1.8A can be reached.
// The following settings are possible:
// - 2U two half-bridges with 0.9A are used, which is sufficient for small motors. This is the default setting
// - 4U with 1.8A, which is sufficient for bigger motors like most computer fans
#define TWO_BRIDGES                 2U
#define FOUR_BRIDGES                4U
#define MULTI_HALF_BRIDGES          TWO_BRIDGES

//!< This is a list of all examples which are covered with here.
enum examples_t
{
	BASICTEST            = 1,      //!< \brief basicTest just starts and stops a motor */
	ADVANCEDTEST,                  //!< \brief advanceTest runs a motor up and down */
	ERRORDIAGNOSIS,                //!< \brief errorDiagnosis shows the use of the error registers */
	HALFBRIDGE,                    //!< \brief halfBridge shows the use of only the controller library
	LEDMODE,                       //!< \brief ledMode shows how to lower the sensitivity for open load detection
	STEPPERMOTOR,                  //!< \brief stepperMotor shows how to drive voltage controlled bipolar stepper motors
	MULTIPLECONTROLLERS,           //!< \brief multipleControllers shows how to implement stacked shields */
	MULTIPLEMOTORS                 //!< \brief multipleMotors shows how to use more than one motor */
};

//!> Select the example which is compiled. There are a number of different examples defined which can be switched here.
#define EXAMPLE                     STEPPERMOTOR

int main(void)
{
	cy_rslt_t result;

	/* Initialize the device and board peripherals */
	result = cybsp_init();
	if (result != CY_RSLT_SUCCESS)
	{
		__disable_irq();
		CY_ASSERT(0);
	}

	/* Initialize console log output */
	result = cy_retarget_io_init( CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX,
								  CY_RETARGET_IO_BAUDRATE);
	if (result != CY_RSLT_SUCCESS)
	{
		__disable_irq();
		CY_ASSERT(0);
	}

	/* enable interrupts, this is important for starting SPI */
	__enable_irq();

	/* which example should run */
	switch (EXAMPLE) {
		case BASICTEST:
			printf("\n[multi-half-bridge] : compiled example -> basicTest\n");
			basicTest(MULTI_HALF_BRIDGES);
			break;
		case ADVANCEDTEST:
			printf("\n[multi-half-bridge] : compiled example -> advancedTest\n");
			advancedTest(MULTI_HALF_BRIDGES);
			break;
		case ERRORDIAGNOSIS:
			printf("\n[multi-half-bridge] : compiled example -> errorDiagnosis\n");
			errorDiagnosis(MULTI_HALF_BRIDGES);
			break;
		case HALFBRIDGE:
			printf("\n[multi-half-bridge] : compiled example -> halfBridge\n");
			halfBridge();
			break;
		case LEDMODE:
			printf("\n[multi-half-bridge] : compiled example -> ledMode\n");
			ledMode();
			break;
		case STEPPERMOTOR:
			printf("\n[multi-half-bridge] : compiled example -> stepperMotor\n");
			stepperMotor();
			break;
		case MULTIPLEMOTORS:
			printf("\n[multi-half-bridge] : compiled example -> multipleMotors\n");
			multipleMotors(MULTI_HALF_BRIDGES);
			break;
		case MULTIPLECONTROLLERS:
			printf("\n[multi-half-bridge] : compiled example -> multipleControllers\n");
			// Yet not tested
			multipleControllers(MULTI_HALF_BRIDGES);
			break;
	}

}

#endif /** TLE94112_FRAMEWORK **/
