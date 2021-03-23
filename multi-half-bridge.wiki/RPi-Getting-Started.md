### Overview

In this quick tutorial we will go through one of the C++ Multi Half Bridge examples available for the TLE94112 and the Raspberry Pi.

### Required experience

* Experience level: moderate
* Basic linux user level
* Basic programming skills (C/C++)

### Required Hardware

Name         | Picture |
---          |---      |
[DC Motor Control HAT with TLE94112ES](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112es_rpi_hat) | <img src="https://github.com/Infineon/Assets/raw/master/Pictures/tle94112_hat_Raspberry_Pi.png" width=100>
[Compatible]() Raspberry Pi |
8GB+ microSD card for Raspberry Pi |
5.5V - 20V power supply with > 15W |
Compatible DC motor


### Required Software

* [Raspberry Pi OS](https://www.raspberrypi.org/downloads/raspberry-pi-os/) or similar
* git
* [bcm2835 library](https://www.airspayce.com/mikem/bcm2835/)
* build-essential
* Infineon multi-half-bridge library (this library)

### Tutorial

#### Hardware Setup

The [DC Motor Control HAT with TLE94112ES](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112es_rpi_hat) follows the Raspberry Pi [HAT specification](https://github.com/raspberrypi/hats) and can be stacked onto any 40-pin Raspberry Pi.

* Stack the DC Motor Control HAT onto the Raspberry Pi.
* Connect a 5.5 to 20V power supply to the Vcc and GND pin of the DC Motor Control HAT
* Connect a DC Motor or another load of your choice to output 1 and 5 of the controller

**Note** :warning: : Make sure to connect the power supply **only** to the designated inputs of your DC Motor Control HAT and that it **doesn't exceed 20V**. Otherwise your hardware can be damaged.

#### Raspberry Pi setup

Set up Raspberry Pi with Raspberry Pi OS or similar OS.
Check [this page](https://www.raspberrypi.org/downloads/) for instructions.

You can access your Raspberry Pi either using a monitor and a keyboard or using SSH in a headless setup as described [here](https://www.raspberrypi.org/documentation/configuration/wireless/headless.md).

Now insert the microSD card into your Raspberry Pi and turn on the power supply to boot it up. The Raspberry Pi will be powered by the DC Motor Control HAT.

#### Software Installation

Check out [this section](RPi-Library-Installation) for details on installation of this multi half bridge library.

#### Ready To Go!

With everything ready, now we are going to run one of the library examples.

##### Change into the Raspberry Pi framework folder.
```
cd multi-half-bridge/src/framework/raspberrypi
```

##### Compile the example code.
```
make examples/basicTest
```

##### Run the example code.
```
../../../build/basicTest
```

Your load is now switched on and off by the DC Motor Control HAT.

Check out [this section](RPi-Examples) for more examples.