### Basic API usage:

Full documentation [here](https://infineon.github.io/multi-half-bridge/).

#### Include the multi half bridge library
```
#include "tle94112-rpi.hpp"
#include "tle94112-motor.hpp"
```

#### Create an object from the `Tle94112Rpi` class
```
Tle94112Rpi controller;
```

The `Tle94112Rpi` class is used for low level communication with the motor controller. One instance per controller is needed.

#### Create an object from the `Tle94112Motor` class
```
Tle94112Motor motor(controller);
```

The `Tle94112Motor` class is abstracting and simplifying common motor control functions like start, stop and coast. One instance per motor can be used.

#### Initalize the controller
```
controller.begin();
```

#### Let your program know which half bridges your motor is connected to
```
motor.connect(motor.HIGHSIDE, controller.TLE_HB1);
motor.connect(motor.LOWSIDE, controller.TLE_HB5);
```

`motor.HIGHSIDE` is the positive polarity of the motor, while `motor.LOWSIDE` is the negative polarity side. `controller.TLE_HB[1-12]` connects the respective motor side to one of the half bridges. Multiple half bridges can be connected to one motor pole to reach a higher current limit. These should then be connected in parallel.

#### Optional: Assign a PWM channel to your motor
```
motor.setPwm(motor.LOWSIDE, controller.TLE_PWM1);
```

#### Optional: Set PWM frequency (default is 80 Hz)
```
motor.setPwmFreq(motor1.LOWSIDE, controller.TLE_FREQ100HZ);
```

If you want to change the speed of your motor using PWM, you can assign one of the three PWM channels of the controller to this motor. Please always assign the PWM channel to `motor.LOWSIDE` as the high side is active free wheeling. Available PWM frequencies are 80 Hz, 100 Hz and 200 Hz.

#### Initalize the motor
```
motor.begin();
```

#### Let the motor run forward
```
motor.start();
```

Can be called with the optional _speed_ argument, which can be any integer between -255 and 255. Negative numbers let the motor turn backwards. 0-255 sets the duty cycle to 0 - 100%.

#### Let the motor coast
```
motor.coast();
```

Disable the half bridges the motor is connected to and let it coast.

#### Brake the motor
```
motor.stop();
```

Create a connection between positive and negative motor pole. This will brake the motor. Brake force can be adjusted by passing an integer parameter between 0 and 255 to the method.

#### If PWM channel is assigned: set the speed of the motor.
```
motor.speed(127);
```

Set the speed of the motor to any integer value between -255 and 255. Negative values let the motor run backward.

#### Read and understand the error registers
```
controller.getSysDiagnosis();
```

This command reads out the error register of the multi half bridge. Please refer to example [errorDiagnosis](RPi-Examples###errorDiagnosis) to understand the meaning of the different error flags.

#### Clear error register
```
controller.clearErrors();
```

This method clears all error flags which are not persisting. Required to re-enable the outputs after a latching error like over-current or over-voltage shut them down. More information can be found in [this example](RPi-Examples###errorDiagnosis).

Find the complete documentation in the [Raspberry Pi](https://infineon.github.io/multi-half-bridge/) Doxygen docs section.