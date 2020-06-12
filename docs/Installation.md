# Installation

## Integration of library for Arduino IDO
Please download the required repository from GitHub by clicking on the following field in the latest [release](https://github.com/Infineon/DC-Motor-Control-TLE94112EL/releases) of this repository:

![Download Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Releases_Generic.jpg)

To install the TLE94112 motor control library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in
the Arduino IDE and navigate to the downloaded .ZIP file of this repository. The library will be installed in your Arduino sketch folder
in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **TLE94112**.

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Integration of library for PlatformIO

### Installation of XMC
If you use any Infineon XMC microcontroller like the XMC1100 Boot Kit or the XMC4700 Relax Kit, than you must also
install the [XMC-for-Arduino library from here](https://github.com/Infineon/XMC-for-Arduino).

## Integration of library for Cypress WICED SDK

Copy this library into your WICED SDK under /43xxx_WiFi/libraries/drivers/motor-control/TLE94112 and
copy or link the src/framework/wiced-43xxx/apps directory into the WICED SDK apps directory.