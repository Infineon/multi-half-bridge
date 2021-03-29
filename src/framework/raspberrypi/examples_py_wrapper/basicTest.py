"""
 #  name        basicTest
 #  author      Infineon Technologies AG
 #  copyright   2020 Infineon Technologies AG
 #  version     2.0.0
 #  brief       This example runs a basic controller test with one attached motor on the TLE94112 HAT for Raspberry Pi
 #  details
    It will run the motor in forward and backward direction if the motor
    is able to run in both directions. Otherwise it will only run in on direction.
    Take this example as a first test when starting with this shield.
 
 # SPDX-License-Identifier: MIT
 
 """


import multi_half_bridge_py as MHBP
from time import sleep
 # Tle94112 Object on Shield 1
TleRpi_obj = MHBP.Tle94112Rpi()

 #Tle94112Motor Objects on controller
TleMotor_obj = MHBP.Tle94112Motor(TleRpi_obj)

  #Connect a motor to HB1/HB2 highside and HB3/HB4 lowside
  # With two combined halfbridges the motor can have up to 1.8 A
  # IMPORTANT connect PWM to Lowside as higside is active Free wheeling
TleMotor_obj.initconnector(MHBP.HIGHSIDE, MHBP.TLE_NOPWM, MHBP.TLE_HB1, MHBP.TLE_NOHB, MHBP.TLE_NOHB, MHBP.TLE_NOHB)
TleMotor_obj.initConnector(MHBP.LOWSIDE,  MHBP.TLE_PWM1,  MHBP.TLE_HB5, MHBP.TLE_NOHB, MHBP.TLE_NOHB, MHBP.TLE_NOHB)

print("Init ready")

 # coast the notor
TleMotor_obj.coast()
sleep(1000)

 # max forward and backward

print("max forward and backward")

TleMotor_obj.start(255)
sleep(1000)
TleMotor_obj.coast()
sleep(1000)
TleMotor_obj.start(-255)
sleep(1000)
TleMotor_obj.coast()
sleep(1000)

 #ramp ripple forward and backward

print(" ramp ripple  forward and backward")

#Start max forward
TleMotor_obj.start(255) 
sleep(1000)

# Ramp down to 0
TleMotor_obj.rampSpeed(0, 5000)
sleep(1000)

#Start max backward
TleMotor_obj.start(-255) 
sleep(1000)

# Ramp down to 0
TleMotor_obj.rampSpeed(0, 5000)
sleep(1000)


#ramp up/dpwn forward
print("ramp up/dpwn forward")
#Start above 0 to allow motor to start
TleMotor_obj.start(50) 

# Ramp up to max
TleMotor_obj.rampSpeed(255, 5000)
sleep(1000)
# Ramp down 
TleMotor_obj.rampSpeed(100, 5000)
sleep(1000)
# Ramp up to max
TleMotor_obj.rampSpeed(255, 5000)
sleep(1000)
# Ramp down to 0 
TleMotor_obj.rampSpeed(0, 5000)
sleep(1000)

# ramp transient with a change in rotation direction
print("ramp transient")
# Ramp down to min
TleMotor_obj.rampSpeed(-255, 1000)
sleep(1000)
# Ramp up to max 
TleMotor_obj.rampSpeed(255, 1000)
sleep(1000)
# Ramp down to min
TleMotor_obj.rampSpeed(-255, 1000)
sleep(1000)
# Ramp down to 0 
TleMotor_obj.rampSpeed(0, 1000)
sleep(1000)

# stop and coast
printf("Stop and coast")
# Stop and hold wiith max force
TleMotor_obj.stop(255)
sleep(1000)
TleMotor_obj.coast()
sleep(1000)