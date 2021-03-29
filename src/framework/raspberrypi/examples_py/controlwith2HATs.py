  
"""
 # name        controlwith2HATs
 # author      Infineon Technologies AG
 # copyright   2020 Infineon Technologies AG
 # version     2.0.0
 # brief       This example runs a basic controller test with one attached motor on the TLE94112 HAT for Raspberry Pi
 # details
   It will run the motor in forward and backward direction if the motor
   is able to run in both directions. Otherwise it will only run in on direction.
   Take this example as a first test when starting with this shield.
 
 # SPDX-License-Identifier: MIT
"""

import multi_half_bridge_py as mhb
from time import sleep


  
# Tle94112 Object for HATs 1 (CS0, default) and 2 (CS1)
Controller_obj1 = mhb.Tle94112Rpi()
Controller_obj2 = mhb.Tle94112Rpi(TLE94112_PIN_CS1)

# Tle94112Motor Objects
Motor1 = mhb.Tle94112Motor(Controller_obj1)
Motor2 = mhb.Tle94112Motor(Controller_obj2)

# Connect Motor1 to HB1 and HB5 of controller 1
Motor1.connect(Motor1.HIGHSIDE, Controller_obj1.TLE_HB1)
Motor1.connect(Motor1.LOWSIDE,  Controller_obj1.TLE_HB5)

# Connect Motor2 to HB1 and HB5 of controller 2
Motor2.connect(Motor2.HIGHSIDE, Controller_obj2.TLE_HB1)
Motor2.connect(Motor2.LOWSIDE,  Controller_obj2.TLE_HB5)

# Begin SPI communication with controller 1
Controller_obj1.begin()

# Run Motor1
print("Run motor1...\n")
Motor1.begin()
Motor1.start(1)

sleep(2000)

# Begin SPI communication with controller 2 (ends communication with controller 1)
Controller_obj2.begin()

# Run motor2
print("Run motor2...\n")
Motor2.begin()
Motor2.start(1)

sleep(5000)

# Stop both motors
Motor2.stop(1)
Controller_obj1.begin()
Motor1.stop(1)
