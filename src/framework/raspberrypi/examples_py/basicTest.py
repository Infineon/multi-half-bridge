import multi_half_bridge_py as mhb
from time import sleep

# Tle94112 object on Shield 1
controller = mhb.Tle94112Rpi()

# Tle94112Motor objects on controller
motor = mhb.Tle94112Motor(controller)

# Enable MotorController on all Shields and Motors
# Note: Required to be done before starting to configure the motor
# controller is set to default CS0 pin
controller.begin()

# Connect a motor to HB1/HB2 highside and HB3/HB4 lowside
# With two combined halfbridges the motor can have up to 1.8 A
# IMPORTANT connect PWM to Lowside as highside is active Free wheeling
motor.initConnector(motor.HIGHSIDE, controller.TLE_NOPWM, controller.TLE_HB1, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB)
motor.initConnector(motor.LOWSIDE,  controller.TLE_PWM1,  controller.TLE_HB5, controller.TLE_NOHB, controller.TLE_NOHB, controller.TLE_NOHB)

# Start the motor controller
motor.begin()

print("Init ready\n")

# Coast the motor
motor.coast()
# Sleep for one second
sleep(1)

print("max forward/backward\n")
motor.start(255)

sleep(1)
motor.coast()
sleep(1)
motor.start(-255)
sleep(1)
motor.coast()

# Ramp up/down forward
motor.start(50)                 # Start above 0 allow motor to start
motor.rampSpeed(255, 5000)      # Ramp up to maximal speed (forward)
sleep(1)
motor.rampSpeed(100, 5000)      # Ramp down
sleep(1)
motor.rampSpeed(255, 5000)      # Ramp up to maximal speed (forward) again
sleep(1)
motor.rampSpeed(0, 5000)        # Ramp down to zero

# Ramp up/down backward
print("ramp up/down backward\n")
motor.start(50)                 # Start above 0 allow motor to start
motor.rampSpeed(-255, 5000)     # Ramp up to maximal speed (backward)
sleep(1)
motor.rampSpeed(-100, 5000)     # Ramp down
sleep(1)
motor.rampSpeed(-255, 5000)     # Ramp up to maximal speed (backward) again
sleep(1)
motor.rampSpeed(0, 5000)        # Ramp down to 0

# Ramp transient with a change in rotation direction
print("ramp transient\n")
motor.rampSpeed(-255, 5000)     # Ramp up to maximal speed (backward)
sleep(1)
motor.rampSpeed(255, 5000)      # Ramp up to maximal speed (forward)
sleep(1)
motor.rampSpeed(-255, 5000)     # Ramp up to maximal speed (backward) again
sleep(1)    
motor.rampSpeed(0, 1000)        # Ramp down to zero
sleep(1)

# Stop and coast
print("stop and coast\n")
motor.stop(255)                 # Stop and hold with maximal force
sleep(1)
motor.coast()
sleep(1)





