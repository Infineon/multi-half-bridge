### Overview

In this quick tutorial we will go through the installation for the Arduino IDE.

### Required experience

* Experience level: beginner 
* Basic computer user level
* Basic programming skills (C/C++)
* Basic soldering skills (recommended)

### Required Hardware


Name         | Picture |
---          |---      |
MCU | <img src="img/XMC4700_Relax_Kit.jpg" width="100"> or compatible|
TLE94112 |<img src="https://github.com/Infineon/Assets/raw/master/Pictures/TLE94112EL_Shield.png" style="max-width:100%;" width="100"> |
a DC Motor | <img src="img/lowres-INFIN_Icon_MotorDrivers_02.eps.png" width="100"> |
a power source | between 4V and 40V, reasonable for your motor
pin headers | solder them to the shield
Micro-USB to USB A cable |

### Required Software

* [Segger J-Link](https://www.segger.com/downloads/jlink) either for Windows or Linux
* [Arduino IDE](https://www.arduino.cc/en/main/software) either for Windows or Linux
* XMC-for-Arduino (Installed with Arduino IDE)
* this library (Installed with Arduino IDE, v2.0.0 or higher)

### Tutorial

#### Software Installation

0. **Install Arduino IDE**. If you are new to Arduino, please [download](https://www.arduino.cc/en/Main/Software) the program and install it first.

1. **Install XMC Board**. The official Arduino boards are already available in the Arduino software, but other third party boards as the Infineon XMC MCU based need to be explicitly included. Follow the instructions in the [link](https://github.com/Infineon/XMC-for-Arduino#installation-instructions) to add the XMC board family to Arduino. 

2. **Install the library**. In the Arduino IDE, go to the menu *Sketch > Include library > Library Manager*. Type **TLE94112** and install the library.

  <img src="img/ard-library-manager.png" width="500">

3. **additional** install additionally the Segger J-Link if you use an Infineon XMC1100 BootKit or XMC4700 RelaxKit.


#### Hardware Setup

The TLE94112 needs to be stacked on the mcu and due to the pin layout of the headers, this is fail save.
Then, simply connect it to the computer with the USB cable. 

#### Ready To Go!

With everything ready, now we are going to upload and run one of the library examples. 

1. **Example basicTest**

   Take the *basicTest* example from the from the *File -> Example -> TLE94112 -> basicTest' menu, connect everything and 
   compile the example. 
   Open the terminal from the IDE it will soon prompt the *TLE94112* ready message and prints out the next operation on the motor.
   If everything is connected, the motor should run up and down, forward and backward (if capable of).

2. **Select the board**. 

   For your own Sketches, once installed, you can select the motor controller board from the menu *Tools -> Board:...*.
   Check out the [Examples](Examples).

3. **Include the base driver**.

   To do so insert the following code into your Sketch. This will include the base driver and the functions which are 
   listed under [basic TLE94112 public API functions](Arduino-API).
    ```
    // Tle94112 Object on Shield 1
    Tle94112Ino controller = Tle94112Ino();
    ```

4. **Include the motor control driver**

   For extended functions on the *TLE94112* shield, use the motor control driver, which also include the functions
   listed under [TLE94112Motor public API functions](Arduino-API).
    ```
    // Tle94112 Object on Shield 1
    Tle94112Ino controller = Tle94112Ino();

    // Tle94112Motor Objects on controller
    Tle94112Motor motor(controller);
    ```