# Getting Started with Python framework on Raspberry pi

In this quick tutorial we will go through the step by step to get started with the Raspberry pi and TLE112EL shield.

## Required experience
* Experience level : Moderate
* Basic linux user level
* Basic programming skills : Python


### Required Hardware

Name         | Picture |
---          |---      |
[DC Motor Control HAT with TLE94112ES](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112es_rpi_hat) | <img src="https://github.com/Infineon/Assets/raw/master/Pictures/tle94112_hat_Raspberry_Pi.png" width=100>
[Compatible](RPi-Library-Installation###Compatibility) Raspberry Pi |
8GB+ microSD card for Raspberry Pi |
5.5V - 20V power supply with > 15W |
Compatible DC motor

### Supported Platforms

| Platform | Compatible |
| --- |:---:|
| Raspberry Pi 4 Mod. B | :heavy_check_mark: |
| Raspberry Pi 3 Mod. B+ | :heavy_check_mark: |
| Raspberry Pi 3 Mod. B | :heavy_check_mark: |
| Raspberry Pi 3 Mod. A+ | :heavy_check_mark: |
| Raspberry Pi Zero | :heavy_check_mark: |  |
| Raspberry Pi Zero W(H) | :heavy_check_mark: |
| Raspberry Pi 2 Mod. B v1.2 | :heavy_check_mark: |
| Raspberry Pi 2 Mod. B | :heavy_check_mark: |
| Raspberry Pi 1 Mod. B+ | :heavy_check_mark: |
| Raspberry Pi 1 Mod. B | :x: |
| Rapsberry Pi 1 Mod. A+ |:heavy_check_mark: |
| Raspberry Pi 1 Mod. A | :x: |

### Required Software

* [Raspberry Pi OS](https://www.raspberrypi.org/downloads/raspberry-pi-os/) or similar
* git
* [bcm2835 library](https://www.airspayce.com/mikem/bcm2835/)
* [pybind11 library](https://pybind11.readthedocs.io/en/stable/basics.html)
* python3 or above (recomended)
* updated pip module
* build-essential
* Infineon multi-half-bridge library (this library)

### Prepare Raspberry pi

**You can this step, if you already have Raspberry pi OS installed on your compatible Raspberry Pi.**

* Download Raspberry pi OS from [here](https://www.raspberrypi.org/downloads/raspbian/)
* Unzip Raspbian and flash the image to an SD card. [Here](https://www.raspberrypi.org/documentation/installation/installing-images/) you find a step-by-step tutorial.

### Hardware Setup

The TLE94112ES HAT needs to be stacked onto a [compatible](RPi-Library-Installation###Compatibility) Raspberry Pi. A jumper needs to be placed between the middle pin and the CS0 marking as shown in the picture. 

<img src="https://bitbucket.vih.infineon.com/projects/XFPL/repos/multi-half-bridge/browse/multi-half-bridge.wiki/img/basicTest-hw-setup.png?at=refs%2Fheads%2Ffeature%2Fdocu-update&raw=" style="max-width:100%;" width="300">

The [DC Motor Control HAT with TLE94112ES](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112es_rpi_hat) follows the Raspberry Pi [HAT specification](https://github.com/raspberrypi/hats) and can be stacked onto any 40-pin Raspberry Pi.

* Stack the DC Motor Control HAT onto the Raspberry Pi.
* Connect a 5.5 to 20V power supply to the Vcc and GND pin of the DC Motor Control HAT
* Connect a DC Motor or another load of your choice to output 1 and 5 of the controller

**Note** :warning: : Make sure to connect the power supply **only** to the designated inputs of your DC Motor Control HAT and that it **doesn't exceed 20V**. Otherwise your hardware can be damaged.

### Library installation
Library can be installed by giving the command for pip installable from terminal. Recommended to used command in with sudo.
```
pip3 install .............
```

