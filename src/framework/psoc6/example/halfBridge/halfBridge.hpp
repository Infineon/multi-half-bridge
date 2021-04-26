/*!
 * \name        halfBridge
 * \author      Infineon Technologies AG
 * \copyright   2021 Infineon Technologies AG
 * \brief       This example shows how to control the independent half bridges of the multi half bridge ICs.
 * \details
 * The example shows how to control the half bridges to switch generic loads.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef HALFBRIDGE_HPP_
#define HALFBRIDGE_HPP_

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

/* Infineon library for multi-half-bridge */
#include <tle94112-psoc6hal.hpp>

void halfBridge();

#endif /** TLE94112_FRAMEWORK **/
#endif /* HALFBRIDGE_HPP_ */
