"""
# name        advancedTest
# author      Infineon Technologies AG
# copyright   2021 Infineon Technologies AG
# version     1.0.0
# brief       This example runs an advanced controller test with one attached motor on the TLE94112ES HAT for Raspberry Pi.
# details
    This example is meant for one bidirectional motor, connected to
    output 1 and 5 of the TLE94112ES HAT for Raspberry Pi.
    It demonstrates the following library functions:
        Basic motor control
            - Run motor forward without PWM
            - Stop (brake) motor
            - Run motor backwards without PWM
            - Coast motor
        Motor control with PWM
            - Run motor forward with PWM (50% duty cycle)
            - Stop (brake) motor with PWM (50% duty cycle)
        Ramp up/down motor speed
            - Slowly ramp up duty cycle from 0% to 100%
            - Slowly ramp down duty cycle from 100% to 50%
            - Quickly ramp up duty cycle from 50% to 100%
            - Quickly ramp down duty cycle from 100% to 0%
 
# SPDX-License-Identifier: MIT

"""
# Define a fixed delay
DELAY = 3

import multi_half_bridge_py as mhb
from time import sleep

# Tle94112 object on Shield 1
controller = mhb.Tle94112Rpi()

# Tle94112Motor object on controller
motor = mhb.Tle94112Motor(controller)

# Enable MotorController on all shields and motors
# !!Note!! Required to be done before starting to configure the motor
# controllere is set to default CS0 pin
controller.begin()

# Clear all errors to start clean
controller.clearErrors()

# Let the library know that a load is connected to HB1 (high side)
# and HB5 (low side)
motor.connect(motor.HIGHSIDE, controller.TLE_HB1)
motor.connect(motor.LOWSIDE, controller.TLE_HB5)

# !!IMPORTANT!!: Connect PWM to low side as high side is active free wheeling
motor.setPwm(motor.LOWSIDE, controller.TLE_PWM1)

# Start the motor controller
motor.begin()

# BASIC MOTOR CONTROL
print("\n--- BASIC MOTOR CONTROL ---\n")
sleep(DELAY)

# Run motor forward without PWM (full speed)
print("- Run Motor forward without PWM (full speed)")
motor.start(255)
sleep(DELAY)

# Stop (brake) motor without PWM (full force)
print("- Stop (brake) motor without PWM (full force)")
motor.stop(255)
sleep(DELAY)

# Run motor backwards without PWM
print("- Run motor backwards without PWM")
motor.start(-255)
sleep(DELAY)

# Coast motor
print("- Coast motor \n")
motor.coast()
sleep(DELAY)

# MOTOR CONTROLL WITH PWM
print("\n--- MOTOR CONTROLL WITH PWM ---\n")
sleep(DELAY)

# Run motor forward with PWM (50% duty cycle)
print("- Run motor forward with PWM (50% duty cycle)")
motor.start(127)        # 0.5 * 255 ~= 127
sleep(DELAY)

# Change duty cycle to 25%
print("- Change duty cycle to 25%")
motor.setSpeed(64)      # 0.25 * 255 ~= 64
sleep(DELAY)

# Stop (brake) motor with PWM (50% duty cycle)
print("- Stop (brake) motor with PWM (50% duty cycle)")
motor.stop(127)
sleep(DELAY)

# RAMP UP/DOWN MOTOR SPEED
print("\n--- RAMP UP/DOWN MOTOR SPEED ---\n")
sleep(DELAY)

# Slowly ramp up duty cycle from 0% to 100%
print("- Slowly ramp up duty cycle from 0% to 100%")
motor.rampSpeed(255, 20000)
sleep(DELAY)

# Slowly ramp down duty cycle from 100% to 25%
print("- Slowly ramp down duty cycle from 100% to 25%")
motor.rampSpeed(64, 20000)
sleep(DELAY)

# Quickly ramp up duty cycle from 25% to 100%
print("- Quickly ramp up duty cycle from 25% to 100%")
motor.rampSpeed(255, 5000)
sleep(DELAY)

# Quickly ramp down duty cycle from 100% to 0%
print("- Quickly ramp down duty cycle from 100% to 0%")
motor.rampSpeed(0, 5000)

# Coast motor
print("- Coast motor")
motor.coast()

print("\n--- END ---")