"""
 #  name        control2Motors
 #  author      Infineon Technologies AG
 #  copyright   2020 Infineon Technologies AG
 #  version     2.0.0
 #  brief       This example demonstrates how to control two motors, their speed and direction with the TLE94112 shield.
 #  details
	By attaching a Tle94112 controller object to two Tle94112Motor objects, we can generate
 	an easy to handle motor object for each motor. We can easily attach this motor object
 	two any of the halfbridges and to any of the PWM units. This is done in the setup part.
 	Keep in mind that you have to initialize the Tle94112 controller and each motor object,
 	which is done in the setup function.
 	After that we can take the motor start, stop and setSpeed function to easily control
 	each motor.
	
#	attention
	Motors have depending on their size a very big latency until a motor has
	fully started or is stopped to 0. Specially the time between a start and stop and vice versa
	is much higher than the processing speed of any microcontroller. This is solved in this example
	with the delay command, but there are better solutions than that.
	These delays are needed because a direct switch between start and stop will lead to high currents
	and the TLE94112 will signal an overcurrent.

 # 	SPDX-License-Identifier: MIT
 
 """

import multi_half_bridge_py as mhb
from time import sleep

# Tle94112 Object on Shield 1
controller = mhb.Tle94112Rpi()

# Tle94112Motor Objects
motor1 = mhb.Tle94112Motor(controller)
motor2 = mhb.Tle94112Motor(controller)

# Enable MotorController Tle94112
# Note: Required to be done before starting to configure the motor
controller.begin()

# Clear all errors to start clean
controller.clearErrors()

# Connect motor1 to HB1 and HB5
motor1.connect(motor1.HIGHSIDE, controller.TLE_HB1)
motor1.connect(motor1.LOWSIDE,  controller.TLE_HB5)

# Drive HB1 with signal from PWM1
# Note: This allows to control the speed of the motor
motor1.setPwm(motor1.HIGHSIDE, controller.TLE_PWM1)

# Connect motor2 to HB7 and HB9
motor2.connect(motor2.HIGHSIDE, controller.TLE_HB7)
motor2.connect(motor2.LOWSIDE,  controller.TLE_HB9)

# Drive HB2 with signal from PWM2
# Note: This allows to control the speed of the motor
motor2.setPwm(motor2.HIGHSIDE, controller.TLE_PWM2)

# When configuration is done, call begin to start operating the motors
motor1.begin()
motor2.begin()

# Start the motor1 forward on half speed
print("Start motor 1 on 50% duty cycle \n")
motor1.start(127)
sleep(2)
# Start the motor2 forward on half speed
print("Start motor 2 on 50% duty cycle \n")
motor2.start(127)
sleep(2)

# Accelerate motor1 to full speed
print("Accelerate motor 1 to 100% duty cycle \n")
motor1.setSpeed(255)
sleep(2)
# Accelerate motor2 to full speed
print("Accelerate motor 2 to 100% duty cycle \n")
motor2.setSpeed(255)
sleep(2)

# Stop both motors
print("Stop both motors \n")
motor1.stop(255)
motor2.stop(255)