'''
 # name        errorDiagnosis
 # author      Infineon Technologies AG
 # copyright   2021 Infineon Technologies AG
 # version     1.0.0
 # brief       This example shows how to read and understand the status registers of the TLE94112.
 # details
   It will run the motor in forward direction and then read the status registers every 5 seconds. 
   It shows how to understand the status registers and which errors can appear.
   Take this example if you want to learn how to debug the TLE94112 during operation.
 
 # SPDX-License-Identifier: MIT
 '''
import multi_half_bridge_py as mhb
from time import sleep

# Tle94112 Object on Shield 1
  Controller_obj = mhb.Tle94112Rpi()

# Tle94112Motor Objects on controller
  Motor = mhb.Tle94112Motor(Controller_obj)

# Enable MotorController on all Shields and Motors
# Note: Required to be done before starting to configure the motor
# controller is set to default CS0 pin
  Controller_obj.begin()

# Connect a motor to HB1 high-side and HB5 low-side
# With two combined half bridges the motor can have up to 1.8 A
  Motor.initConnector(Motor.HIGHSIDE, Controller_obj.TLE_NOPWM, Controller_obj.TLE_HB1, Controller_obj.TLE_NOHB, Controller_obj.TLE_NOHB, Controller_obj.TLE_NOHB)
  Motor.initConnector(Motor.LOWSIDE, Controller_obj.TLE_NOPWM, Controller_obj.TLE_HB5, Controller_obj.TLE_NOHB, Controller_obj.TLE_NOHB, Controller_obj.TLE_NOHB)

# Start the motor controller
  Motor.begin()

# Run the motor
  Motor.start(255)

# Clear all errors to start clean
  Controller_obj.clearErrors()

  print("Motor active, starting loop.\n\n")

  while 1:
# Communicate with TLE94112 to get the status register SYS_DIAG1 (default)
    status = Controller_obj.getSysDiagnosis()
# The SPI error flag shows if a SPI protocol
# error is detected.
    if (status & Controller_obj.TLE_SPI_ERROR):
      print("SPI error detected!\n")

# Handle errors
'''The under voltage flag shows if a supply voltage below the lower limit is detected. All outputs are disabled when flag is set.
This error is latched and needs to be cleared manually.
'''
    if (status & Controller_obj.TLE_UNDER_VOLTAGE):
      print("Under voltage detected!\n")
      # Handle the under voltage error here.


'''
The over voltage flag shows if a supply voltage above the upper limit is detected. All outputs are disabled when flag is set.
This error is latched and needs to be cleared manually.
'''
    if (status & Controller_obj.TLE_OVER_VOLTAGE):
      print("Over voltage detected!\n")
      # Handle the over voltage error here.

'''
The over voltage flag shows if a supply voltage above the upper limit is detected. All outputs are disabled when flag is set.
This error is latched and needs to be cleared manually.
'''
    if (status & Controller_obj.TLE_POWER_ON_RESET):
      print("Power on reset detected!\n")
      # Handle the power on reset here.

'''
The pre-warning temperature flag shows that the junction temperature exceeded the temperature pre-warning threshold.
This error is latched and needs to be cleared manually.
'''
    if (status & Controller_obj.TLE_TEMP_WARNING):
      print("Junction temperature above pre-warning threshold!\n")
      # Handle the temperature warning here.
'''
The shutdown temperature flag shows that the junction temperature exceeded the shutdown temperature threshold.
All outputs are disabled when flag is set. This error is latched and needs to be cleared manually.
'''
    if (status & Controller_obj.TLE_TEMP_SHUTDOWN):
      print("Junction temperature above shutdown threshold!\n")
      # Handle the temperature shutdown here.

'''
The load error flag shows that either:
- an open load error or
- an over-current error
is detected on at least one output. The faulty output is disabled in case of an over-current error. This error is latched and needs to be
cleared manually.
'''
    if (status & Controller_obj.TLE_LOAD_ERROR):
      print("Load error detected!\n")
      # Handle the Load error here.

'''
A load error can be specified more precisely. The chip knows which kind of error occurred in which half-bridge. This can be red as follows:
'''
# For each half bridge (0 is placeholder for no half bridge)
      for halfBridge in range(1,13):
  # Read over-current status of this half bridge from chip
      oc = Controller_obj.getHBOverCurrent((Tle94112::HalfBridge)halfBridge)

  # Check for an over-current error on the low-side of this half bridge
      if (oc & Controller_obj.TLE_LOWSIDE):
        print("\tHB %u:\tOver-current detected in low-side switch.\n" + halfBridge)
  
  # Check for an over-current error on the high-side of this half bridge
      if (oc & Controller_obj.TLE_HIGHSIDE):
        print("\tHB %u:\tOver-current detected in high-side switch.\n" + halfBridge)

  # Read open load status of this half bridge from chip
      ol = Controller_obj.getHBOpenLoad((Tle94112::HalfBridge)halfBridge)

  # Check for an open load error in this half bridge
      if (ol):
        print("\tHB %u:\tOpen load detected.\n" + halfBridge)
 
  # If no error was found print a heartbeat message
    if (!status):
      print("All seems fine :-)\n")

    print("\n---\n\n")

# Clear all error flags (will clear latched errors if they do not persist)
    Controller_obj.clearErrors()

# Wait for 5 seconds
    sleep(5000)

