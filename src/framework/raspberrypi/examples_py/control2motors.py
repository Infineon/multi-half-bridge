"""
 #  name        control2Motors
 #  author      Infineon Technologies AG
 #  copyright   2020 Infineon Technologies AG
 #  version     2.0.0
 #  brief       This example demonstrates how to control two motors, their speed and direction with the TLE94112 shield.
 #  details
    '''By attaching a Tle94112 controller object to two Tle94112Motor objects, we can generate
    an easy to handle motor object for each motor. We can easily attach this motor object
 	two any of the halfbridges and to any of the PWM units. This is done in the setup part.
 	Keep in mind that you have to initialize the Tle94112 controller and each motor object,
 	which is done in the setup function.
 	After that we can take the motor start, stop and setSpeed function to easily control
 	each motor.'''
 
 # SPDX-License-Identifier: MIT
 
 """

import multi_half_bridge_py as mhb
from time import sleep

# Tle94112 Object on Shield 1
Controller_obj = mhb.Tle94112Rpi()

# Tle94112Motor Objects on controller
Motor1 = mhb.Tle94112Motor(Controller_obj)
Motor2 = mhb.Tle94112Motor(Controller_obj)

# Enable MotorController Tle94112
# Note: Required to be done before starting to configure the motor
print("Controller setup\n")
Controller_obj.begin()
print("Controller begin\n")

# Connect motor1 to HB1 and HB5
Motor1.connect(Motor1.HIGHSIDE, Controller_obj.TLE_HB1)
Motor1.connect(Motor1.LOWSIDE,  Controller_obj.TLE_HB5)

# Drive HB1 with signal from PWM1
# Note: This allows to control the speed of the motor
Motor1.setPwm(Motor1.HIGHSIDE, Controller_obj.TLE_PWM1)

# Set PWM Frequency, default is 80 Hz
Motor1.setPwmFreq(Motor1.HIGHSIDE, Controller_obj.TLE_FREQ100HZ)

# Connect motor2 to HB7 and HB9
Motor2.connect(Motor2.HIGHSIDE, Controller_obj.TLE_HB7)
Motor2.connect(Motor2.LOWSIDE,  Controller_obj.TLE_HB9)

# Drive HB2 with signal from PWM2
# Note: This allows to control the speed of the motor
Motor2.setPwm(Motor2.HIGHSIDE, Controller_obj.TLE_PWM2)

# When configuration is done, call begin to start operating the motors
print("Motor begin\n")
Motor1.begin()
Motor2.begin()
print("All ready\n")

# Start the Motor1 forwards on half speed
Motor1.start(127)
# Start the Motor2 backwards on half speed
Motor2.start(-127)
sleep(5000)

# Accelerate Motor1 to full speed
Motor1.setSpeed(255)
# Stop Motor2
Motor2.stop()
sleep(5000)

# Reduce speed of Motor1
Motor1.setSpeed(127)
sleep(1000)

# Let Motor1 turn backwards on half speed
Motor1.setSpeed(-127)
sleep(5000)

# Accelerate motor1 to full speed backwards
Motor1.setSpeed(-255)
sleep(5000)

# Stop motor1, you can use the parameter to set the force which stops and holds them.
# standard and maximum is 255
Motor1.stop(255)
sleep(5000)


