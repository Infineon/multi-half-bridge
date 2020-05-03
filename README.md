# DC-Motor-Control-TLE94112EL Library 

[![Build Status](https://travis-ci.org/Infineon/DC-Motor-Control-TLE94112EL.svg?branch=master)](https://travis-ci.org/Infineon/DC-Motor-Control-TLE94112EL)


<img src="https://github.com/Infineon/Assets/raw/master/Pictures/TLE94112EL_Shield.png" style="max-width:100%;" width="400">


Library of Infineon's [DC Motor Shield with TLE94112EL](https://www.infineon.com/cms/en/product/evaluation-boards/tle94112el_shield/) for Arduino.

## Summary
The DC motor shield is a small evaluation board equipped with TLE94112EL for use with Arduino. The TLE94112EL is capable to drive up to 6
small DC motors in parallel mode or up to 11 DC motors in cascaded mode. All outputs can drive up to 0.9A. The outputs can be used stand-alone
or combined to increase driving capability up to 3.6A. The implemented integrated [TLE94112EL](https://www.infineon.com/cms/en/product/power/motor-control-ics/intelligent-motor-control-ics/multi-half-bridge-ics/tle94112el/)
is a protected twelve-fold half-bridge driver designed especially for automotive motion control applications such as Heating, Ventilation and Air Conditioning (HVAC) flap DC motor control.

## Key Features and Benefits
* Driver with 12 half-bridge outputs to drive DC motors, resistive or inductive loads
* Driver is protected against over-temperature, over-current, over-voltage, under-voltage and enables diagnosis of over-current, over-voltage, under-voltage
* SPI interface with zero clock diagnosis
* Enhanced EMC performance
* Integrated PWM generator with 3 different frequencies (80Hz, 100Hz, 200Hz)
* Shield enables compact design for multi-motor applications
* Efficient design for multi-motor applications
* Less communication with µC through integrated PWM generator and zero clock diagnosis
* Reducing external components to meet EMC requirements
* The board is stackable if you change the position of a resistor, [see here](https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png)
* LED driver on the first half-bridge

## Target Applications:
* Multi-motor applications
* DC motors and voltage controlled bipolar stepper motors
* Toys
* HVAC systems

## Installation
For the description of library [installation](docs/Installation.md)

## Examples
For the description of the [examples](docs/Examples.md)

## Library documentation
The doxygen [library documentation](https://infineon.github.io/DC-Motor-Control-TLE94112EL/).

## Hardware
The evaluation board is designed to run on Arduino/Genuino and compatible headers
Infineon's XMC1100 Boot Kit, XMC4700 Relax Kits or XMC4800 Relax Kit are fully compatible by using the
[XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino) port and this library

## More information and links
* [Infineon Maker page](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/#overview)
* [Infineon Microcontroller](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/microcontroller-boards/)
* [Infineon Shields for Arduino](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/arduino-shields/)
* [User Manual TLE94112EL](https://www.infineon.com/dgdl/Infineon-DC_Motor_Control_Shield_with_TLE94112EL_UserManual-UM-v01_00-EN.pdf?fileId=5546d46259d9a4bf015a4755351304ac).
* [TLE94112EL datasheet](https://www.infineon.com/dgdl/Infineon-TLE94112EL-DS-v01_00-EN.pdf?fileId=5546d462576f347501579a2795837d3e)
* [TLE941xy Application Note](https://www.infineon.com/dgdl/Infineon-TLE941xy-AN-v01_00-EN-AN-v01_00-EN-AN-v01_00-EN.pdf?fileId=5546d4625b62cd8a015bc8db26c831e3).
* [Tle94112 pinout picture](https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png)
* [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino)



