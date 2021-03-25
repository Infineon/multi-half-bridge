# Multi Half Bridge Library

## Supported Products

### TLE94112EL / TLE94112ES 12-fold half bridge

<img src="https://www.infineon.com/export/sites/default/_images/product/power/motor_control_ics/TLE94112ES_TSDSO-24-51_Combi.jpg_1867607890.jpg" style="max-width:100%;" width="200">

#### Summary
The TLE94112ES is a protected twelve-fold half-bridge driver designed especially for automotive motion control applications such as Heating, Ventilation and Air Conditioning (HVAC) flap DC motor control.

#### Key Features and Benefits
* Driver with 12 half-bridge outputs to drive DC motors, resistive or inductive loads
* Driver is protected against over-temperature, over-current, over-voltage, under-voltage and enables diagnosis of over-current, over-voltage, under-voltage
* SPI interface with zero clock diagnosis
* Integrated PWM generator with 3 different frequencies (80Hz, 100Hz, 200Hz)
* LED driver on the first half-bridge
* Reducing external components to meet EMC requirements
* Efficient design for multi-motor applications

#### Target Applications:
* Multi-motor applications
* DC motors and voltage controlled bipolar stepper motors
* Monostable and bistable relays
* LEDs
* HVAC systems

## Supported Frameworks

<table>
    <tr>
        <td><img src="https://github.com/infineon/multi-half-bridge/wiki/img/arduino-logo.png" width=200></td>
        <td><img src="https://github.com/infineon/multi-half-bridge/wiki/img/wiced-logo.png" width=200></td>
        <td><img src="https://github.com/infineon/multi-half-bridge/wiki/img/rpi-logo.png" width=200></td>
        <td><img src="https://github.com/infineon/multi-half-bridge/wiki/img/cross-platform.png" width=200></td>
    </tr>
    <tr>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/Arduino-API">Arduino API</a></td>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/WICED-API">WICED API</a></td>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/RPi-API">RPi API</a></td>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/TLE94112-API/">TLE94112 API</a><br><a href="https://github.com/Infineon/multi-half-bridge/wiki/TLE94112Motor-API">TLE94112Motor API</a></td>
    </tr>
    <tr>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/Ino-Getting-Started">Getting Started</a></td>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/CW-Getting-Started">Getting Started</a></td>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/RPi-Getting-Started">Getting Started</a></td>
        <td style="text-align: center"><a href="https://github.com/Infineon/multi-half-bridge/wiki/Porting-Guide">Porting Guide</a></td>
    </tr>
</table>

## Available Boards

### DC Motor Control Shield for Arduino
Equipped with TLE94112EL. Compatible with Arduino Uno or similar 3.3V or 5V logic Arduino Uno form-factor boards.
<img src="https://github.com/Infineon/Assets/raw/master/Pictures/TLE94112EL_Shield.png" style="max-width:100%;" width="400">

#### More Information
* [Getting started & examples](https://github.com/Infineon/multi-half-bridge/wiki/Ino-Getting-Started)
* [Product Page](https://www.infineon.com/cms/de/product/evaluation-boards/tle94112el_shield/)
* [Board User's Manual](https://www.infineon.com/dgdl/Infineon-DC_Motor_Control_Shield_with_TLE94112EL_UserManual-UM-v01_00-EN.pdf?fileId=5546d46259d9a4bf015a4755351304ac)

### DC Motor Control HAT for Raspberry Pi
Equipped with TLE94112ES and TLS4125D0EP V50. Compatible with Raspberry Pi 4B, 3B+, 3B, 3A+, 2B v1.2, 2B, 1B+, 1A+, Zero, Zero W.
<img src="https://github.com/Infineon/Assets/raw/master/Pictures/tle94112_hat_Raspberry_Pi.png" style="max-width:100%;" width="400">

#### More Information
* [Getting started & examples](https://github.com/Infineon/multi-half-bridge/wiki/RPi-Getting-Started)
* [Product Page](https://www.infineon.com/raspTLE94112ES)
* [Quick Start Guide](https://www.infineon.com/dgdl/Infineon-DC-Motor-Shield-with-TLE94112-Quick-Start-Guide-GettingStarted-v01_00-EN.pdf?fileId=5546d46277fc7439017840334b1b2219)
* [Board User's Manual](https://www.infineon.com/dgdl/Infineon-DC-Motor-Shield-with-TLE94112-User-Manual-UserManual-v01_00-EN.pdf?fileId=5546d46277fc743901783fec6bf220b7)

## More Information and Links
* [Infineon Maker page](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/#overview)
* [Infineon Microcontroller](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/microcontroller-boards/)
* [Infineon Shields for Arduino](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/arduino-shields/)
* [TLE941xy SPI Application Note](https://www.infineon.com/dgdl/Infineon-TLE941xy-AN-v01_00-EN-AN-v01_00-EN-AN-v01_00-EN.pdf?fileId=5546d4625b62cd8a015bc8db26c831e3)
* [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino)
* [WICED Studio](https://community.cypress.com/community/software-forums/wiced-wifi/wiced-wifi-documentation)
* [Cypress Evaluation Kit CYW43907AEVAL1F](https://www.cypress.com/CYW943907AEVAL1F)

### License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.