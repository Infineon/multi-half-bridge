Welcome to the **TLE94112 DC motor control C++ library** docs!

This software enables the usage of Infineon DC-Motor-Control-TLE94112EL shield in embedded systems and applications.
You can find all the related information in this wiki.

### TLE94112EL

The DC motor shield is a small evaluation board equipped with TLE94112EL for use with Arduino. The TLE94112EL is capable to drive up to 6
small DC motors in parallel mode or up to 11 DC motors in cascaded mode. All outputs can drive up to 0.9A. The outputs can be used stand-alone
or combined to increase driving capability up to 3.6A. The implemented integrated [TLE94112EL](https://www.infineon.com/cms/en/product/power/motor-control-ics/intelligent-motor-control-ics/multi-half-bridge-ics/tle94112el/)
is a protected twelve-fold half-bridge driver designed especially for automotive motion control applications such as Heating, Ventilation and Air Conditioning (HVAC) flap DC motor control.

<img src="https://github.com/Infineon/Assets/raw/master/Pictures/TLE94112EL_Shield.png" style="max-width:100%;" width="400">

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
* The board is stackabel if you change the position of a resistor, [see here](https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png)
* LED driver on the first half-bridge

## Target Applications:
* Multi-motor applications
* DC motors and voltage controlled bipolar stepper motors
* Toys
* HVAC systems


### Features

* Basic register driver as well as motor controller library
* Supported software frameworks
    * Arduino
    * Infineon XMC1100 BootKit, XMC4700 RelaxKit
    * Cypress WICED 43xxx

### Wiki Sections

<table>
    <tr>
        <td><b>1. Home</b></td>
        <td> </td>
    </tr>
    <tr>
        <td><a href="Library-Details"><b>2. Library Details</b></td>
        <td>Library architecture, general API and usage information</td>
    </tr>
    <tr>
        <td><a href="Hardware-Platforms"><b>3. Hardware Platforms</b></a></td>
        <td>List of supported microcontroller platforms</td>
    </tr>
    <tr>
        <td><a href="Software-Frameworks"><b>4. Software Frameworks</b></td>
        <td>List of supported embedded software frameworks and specific APIs</td>
    </tr>
    <tr>
        <td><a href="Related-Links"><b>5. Examples</b></a></td>
        <td>Description of the library examples</td>
    </tr>
    <tr>
        <td><a href="Related-Links"><b>6. Related Links</b></a></td>
        <td>Useful links related to this repository</td>
    </tr>
</table>
