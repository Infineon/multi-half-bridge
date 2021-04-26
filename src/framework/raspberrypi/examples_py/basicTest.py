"""
# name        basicTest
# author      Infineon Technologies AG
# copyright   2021 Infineon Technologies AG
# brief       This example shows how to switch two half bridge outputs with minimal code.
# details
    It will switch on two outputs (one to Vsup and one to GND), wait 3 seconds
    and switch off both outputs (both to floating state).

# SPDX-License-Identifier: MIT

"""

import multi_half_bridge_py as mhb
from time import sleep

# Create a Tle94112Rpi instance for each motor controller
controller = mhb.Tle94112Rpi()

# Create a Tle94112Motor instance for each connected load
motor = mhb.Tle94112Motor(controller)

# Enable MotorController
# Note: Required to be done before starting to configure the motor
# controller is set to default CS0 pin
controller.begin()

# Clear all errors to start clean
controller.clearErrors()

# Let the library know that a load is connected to HB1 (high side)
# and HB5 (low side).
motor.connect(motor.HIGHSIDE, controller.TLE_HB1)
motor.connect(motor.LOWSIDE, controller.TLE_HB5)
motor.setPwm(motor.LOWSIDE, controller.TLE_NOPWM)

# Initialize the motor
motor.begin()

# Switch the load on
motor.start(255)

sleep(3)

# Switch the load off (set outputs to floating state)
motor.coast()