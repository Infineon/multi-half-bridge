# Getting Started with Python framework on Raspberry Pi

This page explains how to install and use the Python wrapper for the multi half bridge library with the TLE94112ES HAT for Raspberry Pi.

## Overview

### Required experience
* Experience level: Moderate
* Basic linux user level
* Basic programming skills: Python

### Required Hardware

Name         | Picture |
---          |---      |
[DC Motor Control HAT with TLE94112ES](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112es_rpi_hat) | <img src="https://github.com/Infineon/Assets/raw/master/Pictures/tle94112_hat_Raspberry_Pi.png" width=100>
[Compatible](RPi-Library-Installation###Compatibility) Raspberry Pi |
8GB+ microSD card for Raspberry Pi |
5.5V - 20V power supply with > 15W |
Compatible DC motor

### Required Software

* [Raspberry Pi OS](https://www.raspberrypi.org/downloads/raspberry-pi-os/) or similar
* git
* [bcm2835 library](https://www.airspayce.com/mikem/bcm2835/)
* [pybind11 library](https://pybind11.readthedocs.io/en/stable/basics.html)
* python3 (tested with python3.7)
* pip (for easy installation)
* build-essential
* Infineon multi-half-bridge library (this library)

## Tutorial

### Hardware Setup

The TLE94112ES HAT needs to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking as shown in the picture. 

<img src="img/basicTest-hw-setup.png" style="max-width:100%;" width="300">

The [DC Motor Control HAT with TLE94112ES](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112es_rpi_hat) follows the Raspberry Pi [HAT specification](https://github.com/raspberrypi/hats) and can be stacked onto any 40-pin Raspberry Pi.

* Stack the DC Motor Control HAT onto the Raspberry Pi.
* Connect a 5.5 to 20V power supply to the Vcc and GND pin of the DC Motor Control HAT
* Connect a DC Motor or another load of your choice to output 1 and 5 of the controller

**Note** :warning: : Make sure to connect the power supply **only** to the designated inputs of your DC Motor Control HAT and that it **doesn't exceed 20V**. Otherwise your hardware can be damaged.

### Raspberry Pi setup

Set up Raspberry Pi with Raspberry Pi OS or similar OS.
Check [this page](https://www.raspberrypi.org/downloads/) for instructions.

You can access your Raspberry Pi either using a monitor and a keyboard or using SSH in a headless setup as described [here](https://www.raspberrypi.org/documentation/configuration/wireless/headless.md).

Now insert the microSD card into your Raspberry Pi and turn on the power supply to boot it up. The Raspberry Pi will be powered by the DC Motor Control HAT.

### Library installation
This library can be installed easily using `pip`. If you do not have `pip` installed please do so by typing
```
sudo apt-get install python3-pip
```
into the command line of your Raspberry Pi. Afterwards you can install the Infineon multi half bridge library by typing
```
sudo pip3 install infineon-mhb
```

### Clone the repository 
Once the library is installed clone the [multi half bridge repository](https://www.github.com/infineon/multi-half-bridge). 
```
git clone https://github.com/Infineon/multi-half-bridge.git
```
Navigate to the example folder
```
cd multi-half-bridge/src/framework/raspberrypi/examples_py
```
 and execute the examples from the terminal:
```
sudo python3 basicTest.py
```