# DC-Motor-Control-TLE94112EL Library 
<img src="https://github.com/Infineon/Assets/blob/master/Pictures/TLE94112EL_Shield.png" width="400">

Library of Infineon's [DC Motor Shield with TLE94112EL](https://www.infineon.com/cms/en/product/productType.html?productType=5546d46259d9a4bf015a369885a95505) for Arduino.

## Summary
The DC motor shield is a small evaluation board equipped with TLE94112EL for use with Arduino. The TLE94112EL is capable to drive up to 6 small DC motors in parallel mode or up to 11 DC motors in cascaded mode. All outputs can drive up to 0.9A. The outputs can be used stand-alone or combined to increase driving capability up to 3.6A. The implemented integrated [TLE94112EL](https://www.infineon.com/cms/en/product/power/motor-control-and-gate-driver-ics/intelligent-motor-control-ics/multi-half-bridge-driver/TLE94112EL/productType.html?productType=5546d46254e133b4015538ca99e552a1) is a protected twelve-fold half-bridge driver designed especially for automotive motion control applications such as Heating, Ventilation and Air Conditioning (HVAC) flap DC motor control.

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

## Target Applications:
* Multi-motor applications
* DC motors and voltage controlled bipolar stepper motors
* Toys
* HVAC systems

## Installation
First of all, please download this repository from GitHub by clicking on the following field in the [releases](https://github.com/Infineon/DC-Motor-Control-TLE94112EL/releases) of this repository or directly [here](https://github.com/Infineon/DC-Motor-Control-TLE94112EL/releases/download/V0.1.0/DC-Motor-Control-TLE94112EL.zip):

![Download Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/DL_DC_Mot_Rel-TLE94112EL.png)

To install the DC motor control library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in the Arduino IDE and navigate to the downloaded .ZIP file of this repository release. The library will be installed in your Arduino sketch folder in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **TLE94112**.

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Usage
Please follow the example sketches in the /examples directory in this library to learn more about the usage of the library.

## Board Information, Datasheet and Additional Information
A PDF summarizing the features and layout of the DC motor control shield is stored on the Infineon homepage [here](https://www.infineon.com/dgdl/Infineon-DC_Motor_Control_Shield_with_TLE94112EL_UserManual-UM-v01_00-EN.pdf?fileId=5546d46259d9a4bf015a4755351304ac).
The datasheet for the TLE94112EL can be found here [TLE94112EL Datasheet](https://www.infineon.com/dgdl/Infineon-TLE94112EL-DS-v01_00-EN.pdf?fileId=5546d462576f347501579a2795837d3e) while the respective application note is located here [TLE941xy Application Note](https://www.infineon.com/dgdl/Infineon-TLE941xy-AN-v01_00-EN-AN-v01_00-EN-AN-v01_00-EN.pdf?fileId=5546d4625b62cd8a015bc8db26c831e3).
