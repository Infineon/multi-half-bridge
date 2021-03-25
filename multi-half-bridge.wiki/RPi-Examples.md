The following examples are provided for Raspberry Pi:

:warning: **Important:** Before running these examples make sure that all requirements are installed properly as explained [here](RPi-Library-Installation).

### basicTest

#### Description
This example shows how to switch two half bridge outputs with minimal code. It will switch on two outputs (one to Vsup and one to GND), wait 3 seconds and switch off both outputs (both to floating state).

#### Hardware setup

The TLE94112ES HAT needs to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking as shown in the picture. The HAT needs to be connected to a 5.5V to 20V DC power supply. A load (max. 0.9A) has to be connected to output 1 and 5 of the HAT.

<img src="img/basicTest-hw-setup.png" style="max-width:100%;" width="300">

#### :information_source: Note
Please open the example source file at `src/framework/raspberrypi/examples/basicTest.cpp` and read the comments before compiling it.

#### Compile

Change to Raspberry Pi framework folder:
```
cd src/framework/raspberrypi
```

Clean if any other example was compiled before:
```
make clean
```

Compile the example:
```
make examples/basicTest
```

Run the example:
```
sudo ../../../build/basicTest
```

:warning: **Important:** sudo (root rights) is essential to run this example. Otherwise it will fail.


### advancedTest

#### Description
 This example runs an advanced controller test with one attached motor on the controller. It is meant for one bidirectional motor, connected to **output 1 and 5** of the TLE94112. It demonstrates the following library functions:
 * Basic motor control
   * Run motor forward without PWM
   * Stop (brake) motor
   * Run motor backwards without PWM
   * Coast motor
 * Motor control with PWM
   * Run motor forward with PWM (50% duty cycle)
   * Stop (brake) motor with PWM (50% duty cycle)
 * Ramp up/down motor speed
    * Slowly ramp up duty cycle from 0% to 100%
    * Slowly ramp down duty cycle from 100% to 50%
    * Quickly ramp up duty cycle from 50% to 100%
    * Quickly ramp down duty cycle from 100% to 0%

#### Hardware setup

The TLE94112ES HAT needs to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking as shown in the picture. The HAT needs to be connected to a 5.5V to 20V DC power supply. A bidirectional DC motor (max. 0.9A) has to be connected to output 1 and 5 of the HAT.

<img src="img/basicTest-hw-setup.png" style="max-width:100%;" width="300">

#### :information_source: Note
Please open the example source file at `src/framework/raspberrypi/examples/advancedTest.cpp` and read the comments before compiling it.

#### Compile

Change to Raspberry Pi framework folder:
```
cd src/framework/raspberrypi
```

Clean if any other example was compiled before:
```
make clean
```

Compile the example:
```
make examples/advancedTest
```

Run the example:
```
sudo ../../../build/advancedTest
```

:warning: **Important:** sudo (root rights) is essential to run this example. Otherwise it will fail.


### errorDiagnosis

#### Description
This example shows how to read and understand the status registers of the TLE94112. It will run the motor in forward direction and then read the status registers every 5 seconds. It shows how to understand the status registers and which errors can appear. Take this example if you want to learn how to debug the TLE94112 during operation.

#### Hardware setup

The TLE94112ES HAT needs to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking as shown in the picture. The HAT needs to be connected to a 5.5V to 20V DC power supply. A load (max. 0.9A) has to be connected to output 1 and 5 of the HAT. If you want to trigger errors you be ready to create a short circuit between output 1 and output 5 or disconnect the load to get an open load error.

<img src="img/basicTest-hw-setup.png" style="max-width:100%;" width="300">

#### :information_source: Note
Please open the example source file at `src/framework/raspberrypi/examples/errorDiagnosis.cpp` and read the comments before compiling it.

#### :warning: Warning
This example will not terminate automatically. Use **CTRL + C** to terminate it.

#### Compile

Change to Raspberry Pi framework folder:
```
cd src/framework/raspberrypi
```

Clean if any other example was compiled before:
```
make clean
```

Compile the example:
```
make examples/errorDiagnosis
```

Run the example:
```
sudo ../../../build/errorDiagnosis
```

:warning: **Important:** sudo (root rights) is essential to run this example. Otherwise it will fail.


### multipleMotors

#### Description
This example demonstrates how to control two motors, their speed and direction with the TLE94112.

#### Hardware setup

The TLE94112ES HAT needs to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking as shown in the picture. The HAT needs to be connected to a 5.5V to 20V DC power supply. A load (max. 0.9A) has to be connected to output 1 and 5 of the HAT. Another load has to be connected between output 7 and 9.

<img src="img/multipleMotors-hw-setup.png" style="max-width:100%;" width="300">

#### :information_source: Note
Please open the example source file at `src/framework/raspberrypi/examples/multipleMotors.cpp` and read the comments before compiling it.

#### Compile

Change to Raspberry Pi framework folder:
```
cd src/framework/raspberrypi
```

Clean if any other example was compiled before:
```
make clean
```

Compile the example:
```
make examples/multipleMotors
```

Run the example:
```
sudo ../../../build/multipleMotors
```

:warning: **Important:** sudo (root rights) is essential to run this example. Otherwise it will fail.


### multipleControllers

#### Description
This example shows how to use multiple TLE94112 controllers simultaneously. For this example it is assumed that two TLE94112 controllers are connected to one Raspberry Pi. The Chip Select pin of controller 1 is set to CS0 and the Chip Select pin of controller 2 is set to CS1. On both controllers a load is connected between half bridge 1 and 5. This example shows, how to control both motor controllers from one Raspberry Pi.

#### Hardware setup

Both TLE94112ES HATs need to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking on controller 1 as shown in the picture. Another jumper needs to be placed between the middle pin and CS1 on controller 2. Both HATs needs to be connected to a 5.5V to 20V DC power supply. A load (max. 0.9A) has to be connected to output 1 and 5 of both HATs.

<img src="img/multipleControllers-hw-setup.png" style="max-width:100%;" width="300">

#### :information_source: Note
Please open the example source file at `src/framework/raspberrypi/examples/multipleControllers.cpp` and read the comments before compiling it.

#### Compile

Change to Raspberry Pi framework folder:
```
cd src/framework/raspberrypi
```

Clean if any other example was compiled before:
```
make clean
```

Compile the example:
```
make examples/multipleControllers
```

Run the example:
```
sudo ../../../build/multipleControllers
```

:warning: **Important:** sudo (root rights) is essential to run this example. Otherwise it will fail.