"""
# name        multipleControllers
# author      Infineon Technologies AG
# copyright   2021 Infineon Technologies AG
# version     2.1.0
# brief       This example shows how to use multiple TLE94112 controllers simultaneously.
# details
  For this example it is assumed, that two TLE94112 controllers are connected to one Raspberry Pi.
  set to CS1. On both controllers a load is connected between half bridge 1 and 5.
  This example shows, how to control both motor controllers from one Raspberry Pi.
 
# SPDX-License-Identifier: MIT

"""

import multi_half_bridge_py as mhb
from time import sleep

# Tle94112 Object for HATs 1 (CS0, default) and 2 (CS1)
controller1 = mhb.Tle94112Rpi()
PinSel = mhb.Rpi_PinSel()

controller2 = mhb.Tle94112Rpi(PinSel.TLE94112_PIN_CS1)
# Tle94112Motor Objects
motor1 = mhb.Tle94112Motor(controller1)
motor2 = mhb.Tle94112Motor(controller2)

# Connect motor1 to HB1 and HB5 of controller 1
motor1.connect(motor1.HIGHSIDE, controller1.TLE_HB1)
motor1.connect(motor1.LOWSIDE,  controller1.TLE_HB5)
motor1.setPwm(motor1.LOWSIDE, controller1.TLE_NOPWM)

# Connect motor2 to HB1 and HB5 of controller 2
motor2.connect(motor2.HIGHSIDE, controller2.TLE_HB1)
motor2.connect(motor2.LOWSIDE,  controller2.TLE_HB5)
motor2.setPwm(motor2.LOWSIDE, controller2.TLE_NOPWM)

# Begin SPI communication with controller 1
controller1.begin()

# Run motor1 (connected to controller 1)
print("Start motor on controller 1")
motor1.begin()
motor1.start(255)

sleep(2)

# Begin SPI communication with controller 2 (ends communication with controller 1)
controller2.begin()

# Run motor2
print("Start motor on controller 2")
motor2.begin()
motor2.start(255)

sleep(5)

# Stop both motors
motor2.stop(255)
controller1.begin()
motor1.stop(255)
