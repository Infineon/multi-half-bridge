'''
 # name        errorDiagnosis
 # author      Infineon Technologies AG
 # copyright   2021 Infineon Technologies AG
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
controller = mhb.Tle94112Rpi()

# Tle94112motor Objects on controller
motor = mhb.Tle94112Motor(controller)

# Enable motorController on all Shields and motors
# Note: Required to be done before starting to configure the motor
# controller is set to default CS0 pin
controller.begin()

# Connect a motor to HB1 high-side and HB5 low-side
# With two combined half bridges the motor can have up to 1.8 A
motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB)
motor.initConnector(motor.LOWSIDE, controller.TLE_NOPWM, controller.TLE_HB5, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB)

# Start the motor controller
motor.begin()

# Run the motor
motor.start(255)

# Clear all errors to start clean
controller.clearErrors()

print("Motor active, starting loop.\n")

while 1:
  # Communicate with TLE94112 to get the status register SYS_DIAG1 (default)
  status = controller.getSysDiagnosis()
  # The SPI error flag shows if a SPI protocol
  # error is detected.
  if (status & controller.TLE_SPI_ERROR):
    print("SPI error detected!")

  # Handle errors
  '''The under voltage flag shows if a supply voltage below the lower limit is detected. All outputs are disabled when flag is set.
  This error is latched and needs to be cleared manually.
  '''
  if (status & controller.TLE_UNDER_VOLTAGE):
    print("Under voltage detected!")
    # Handle the under voltage error here.


  '''
  The over voltage flag shows if a supply voltage above the upper limit is detected. All outputs are disabled when flag is set.
  This error is latched and needs to be cleared manually.
  '''
  if (status & controller.TLE_OVER_VOLTAGE):
    print("Over voltage detected!")
    # Handle the over voltage error here.

  '''
  The over voltage flag shows if a supply voltage above the upper limit is detected. All outputs are disabled when flag is set.
  This error is latched and needs to be cleared manually.
  '''
  if (status & controller.TLE_POWER_ON_RESET):
    print("Power on reset detected!")
    # Handle the power on reset here.

  '''
  The pre-warning temperature flag shows that the junction temperature exceeded the temperature pre-warning threshold.
  This error is latched and needs to be cleared manually.
  '''
  if (status & controller.TLE_TEMP_WARNING):
    print("Junction temperature above pre-warning threshold!")
    # Handle the temperature warning here.
  '''
  The shutdown temperature flag shows that the junction temperature exceeded the shutdown temperature threshold.
  All outputs are disabled when flag is set. This error is latched and needs to be cleared manually.
  '''
  if (status & controller.TLE_TEMP_SHUTDOWN):
    print("Junction temperature above shutdown threshold!")
    # Handle the temperature shutdown here.

  '''
  The load error flag shows that either:
  - an open load error or
  - an over-current error
  is detected on at least one output. The faulty output is disabled in case of an over-current error. This error is latched and needs to be
  cleared manually.
  '''
  if (status & controller.TLE_LOAD_ERROR):
    print("Load error detected!")
    # Handle the Load error here.

    '''
    A load error can be specified more precisely. The chip knows which kind of error occurred in which half-bridge. This can be red as follows:
    '''
    # For each half bridge (0 is placeholder for no half bridge)
    for halfBridge in range(1,13):
      if (halfBridge==1):
        hb_val = controller.TLE_HB1
      if (halfBridge==2):
        hb_val = controller.TLE_HB2
      if (halfBridge==3):
        hb_val = controller.TLE_HB3
      if (halfBridge==4):
        hb_val = controller.TLE_HB4
      if (halfBridge==5):
        hb_val = controller.TLE_HB5
      if (halfBridge==6):
        hb_val = controller.TLE_HB6
      if (halfBridge==7):
        hb_val = controller.TLE_HB7
      if (halfBridge==8):
        hb_val = controller.TLE_HB8
      if (halfBridge==9):
        hb_val = controller.TLE_HB9
      if (halfBridge==10):
        hb_val = controller.TLE_HB10
      if (halfBridge==11):
        hb_val = controller.TLE_HB11
      if (halfBridge==12):
        hb_val = controller.TLE_HB12
      # Read over-current status of this half bridge from chip
      oc = controller.getHBOverCurrent(hb_val)

      # Check for an over-current error on the low-side of this half bridge
      if (oc & controller.TLE_LOWSIDE):
        print("\tHB" + hb_val + "\tOver-current detected in low-side switch." + halfBridge)
  
      # Check for an over-current error on the high-side of this half bridge
      if (oc & controller.TLE_HIGHSIDE):
        print("\tHB" + hb_val + "\tOver-current detected in high-side switch." + halfBridge)

      # Read open load status of this half bridge from chip
      ol = controller.getHBOpenLoad(hb_val)

      # Check for an open load error in this half bridge
      if (ol):
        print("\tHB" + hb_val + "\tOpen load detected." + halfBridge)
 
  # If no error was found print a heartbeat message
  if (status==0):
    print("All seems fine :-)")

  print("\n---\n")

  # Clear all error flags (will clear latched errors if they do not persist)
  controller.clearErrors()

  # Wait for 5 seconds
  sleep(5)