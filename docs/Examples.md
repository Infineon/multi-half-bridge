# Examples

## List of examples
To run this examples use either the Arduino IDE or something similar like the [PlatformIO](https://platformio.org/platformio-ide?utm_source=github&utm_medium=xmc-for-arduino) module for [code](https://code.visualstudio.com/) or [atom](https://atom.io/)
* examples/basicTest/rampTest.ino - runs a basic controller and shield test with one motor attached in forward and backward direction and with speed ramping.
* examples/control2Motors/control2Motors.ino - This examples show how to control more than one motor.
* examples/rampSpeedTest/rampSpeedTest.ino - Ramps a motor which is connected to two half bridges up and down in forward and backward direction.
* examples/speedControl/speedControl.ino - Show how to control a motor only with the basic library.
* 
* all Arduino sketches are also available for the other included platforms. See below the src/framework/PLATFORM directory.

## DIY-projects
* there are two Lego robots using the TLE94112 shields for controlling motors.
 * a [Infineons Lego omiwheel driving robot](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/diy-projects/) 
 * a [INfineons Lego six axes robot](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/diy-projects/)


## examples

### basicTest
It will run the motor in forward and backward direction if the motor
is able to run in both directions. Otherwise it will only run in on direction.

As this example is available for each supported platform, use it as a first test
when starting with this shield. I will show you how to:
* implement the pointer to the shield driver and the motor controller driver
* start a motor in both directions with different speed
* stop the motor with or without a holding force
* coast the motor, which means that there is no current between high- and low side and the motor runs with active free wheeling
* ramp the motor speed up and down


### rampSpeedTest
By attaching a motor to the TLE94112 and running a test case scenario, we can measure the
optimal values for the rampSpeed function. This function allows us to smoothly start, stop,
raise or break the motor.

Keep in mind that a free running motor ramps very different than the same motor with load attached.
So you have to measure the optimal ramp speed with different scenarios and load attached to the motor.

This example will show how to:
* implement the pointer to the shield driver and the motor controller driver
* start a motor in both directions with different speed
* ramp the motor speed up and down
* measure the motor ramping time to calibrate the motor speed ramping


### control2Motors
This example demonstrates how to control two motors, their speed and direction with the TLE94112 shield.

By attaching a Tle94112 controller object to two Tle94112Motor objects, we can generate
an easy to handle motor object for each motor. We can easily attach this motor object
two any of the halfbridges and to any of the PWM units. This is done in the setup part.
Keep in mind that you have to initialize the Tle94112 controller and each motor object,
which is done in the setup function.
After that we can take the motor start, stop and setSpeed function to easily control each motor.

Motors have depending on their size a very big latency until a motor has
fully started or is stopped to 0. Specially the time between a start and stop and vice versa
is much higher than the processing speed of any microcontroller. This is solved in this example
with the delay command, but there are better solutions than that.
These delays are needed because a direct switch between start and stop will lead to high currents
and the TLE94112 will signal an overcurrent.

This example will show how to:
* attach two motors on the shield and drive them independently
* exchanging the motor direction
* using the setSpeed command


### speedControl
This example demonstrates how to control the speed of motor by using the PWM units of the TLE94112 shield

Attaching a potentiometer on an analog input pin, which will than control the
setting of the TLE94112 internal PWM unit and therefore the speed of the motor.
The TLE94112 has three separate PWM units which can be attached to any combination
of halfbridges. So try out to change the TLE_PWM1 to TLE_PWM2 or TLE_PWM3 to see this.
You can change the motor direction by changing the HIGH/LOW status of the halfbridges

This example will show how to:
* setup the basic shield driver without the motor controller library
* to use the internal TLE94112 PWM units for changing the speed of motor

See this picture for the hardware setup.
