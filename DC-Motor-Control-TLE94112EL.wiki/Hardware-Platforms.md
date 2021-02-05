

## Hardware and platforms
This library is designed for multiple platforms with Arduino/Genuino compatible headers and different SDKs.
The following hardware platforms are compatible and tested:

| Hardware platform | Type                | SDK                         | file marker | checked |
|:------------------|:--------------------|:----------------------------|:------------|---------|
| Arduino/Genuino   | Uno                 | Arduino IDE or PlatformIO   | -ino        | yes     |
|                   | Uno clone           | Arduino IDE                 | -ino        | yes     |
|                   | Leonardo            | Arduino IDE or PlatformIO   | -ino        |         |
| Infineon XMC      | XMC1100 Boot Kit    | Arduino IDE or PlatformIO   | -ino        | yes     |
|                   | XMC4700 Relax Kit   | Arduino IDE or PlatformIO   | -ino        | yes     |
|                   | XMC4800 Relax Kit   | Arduino IDE or PlatformIO   | -ino        |         |
| Cypress 43xxx     | CYW43907AEVAL1F     | WICED SDK                   | -wiced      | yes     |
| Cypress PSoC 6    | CY8CPROTO-062-4343W | Modus Toolbox               | -mtb        |         |

Any MCU platform which has an Arduino/Genuino port like the [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino) should
work (this is not tested) with this shield by using the default Arduino platform.

### TLE94112 pinout 

[pin out picture](https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png)
<img src="https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png" width=100%>

#### Other Infineon motor shields

See here for more motor shields from Infineon
[Infineon Shields for Arduino](https://www.infineon.com/cms/en/tools/landing/infineon-for-makers/arduino-shields/)

### Supported MCU Platforms

#### Verified MCU Boards

The library examples have been built and successfully executed on the following hardware platforms:

MCU Platforms |
---           |
[XMC1100 Boot Kit](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc11_boot_001/#ispnTab1) |
[XMC4700 Relax Kit for 5V Shields](https://www.infineon.com/cms/en/product/evaluation-boards/kit_xmc47_relax_5v_ad_v1/) |
[Arduino Uno Rev3](https://store.arduino.cc/arduino-uno-rev3) | 
[Cypress CYW943907AEVAL1F Evaluation Kit](https://www.cypress.com/documentation/development-kitsboards/cyw943907aeval1f-evaluation-kit) |

#### Other MCU platforms 

The library is developed for easy portability to any general purpose microcontroller platform including a one digital input. And optionally, an additional digital output. 
Check the circuit in the [User Manual TLE94112EL](https://www.infineon.com/dgdl/Infineon-DC_Motor_Control_Shield_with_TLE94112EL_UserManual-UM-v01_00-EN.pdf?fileId=5546d46259d9a4bf015a4755351304ac).

The supported software frameworks already allow the usage of multiple microcontroller evaluation boards. 

If still not supported, please check the [Porting Guide](Porting-Guide) to integrate the library in your custom software framework and hardware platform.

### Shield hardware limitations

Please follow the example sketches in the /examples directory in this library to learn more about the usage of the library.
For proper work of the TLE94112 the following tips may help:
* the TLE94112 works properly in the range of min 5.5V to max 40V Vbat
* the TLE94112 works properly with 3.3V on all GPIOs and on VDD, but needs the 3.3V at least on the 5V VDD pin of the Arduino header
* the max current on one half bridge is 0.9 A, if you need more you have to cascade more half bridges, see [manual](https://www.infineon.com/dgdl/Infineon-TLE94112EL-DS-v01_00-EN.pdf?fileId=5546d462576f347501579a2795837d3e) and pin out picture
* the shield can be stacked if you change the 0 \Omega resistor from R7/R8.
* there is also a hack to stack a max number of three TLE94112 (please ask if you need this)
* the first two ports can be directly used also for LEDs but with the help of right dimensioned resistors, any half bridge can be used
for LEDs or other stuff falling in the voltage and current limits of the board
* see the pinout picture for possible setups

