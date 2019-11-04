# Installation

## Integration of Library
Please download the required repository from GitHub by clicking on the following field in the latest [release](https://github.com/Infineon/DC-Motor-Control-TLE94112EL/releases) of this repository:

![Download Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Releases_Generic.jpg)

To install the TLE94112 motor control library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in
the Arduino IDE and navigate to the downloaded .ZIP file of this repository. The library will be installed in your Arduino sketch folder
in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **TLE94112**.

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Usage
Please follow the example sketches in the /examples directory in this library to learn more about the usage of the library.
For proper work of the TLE94112 the following tips may help:
* the TLE94112 works properly in the range of min 5.5V to max 40V Vbat
* the max current on one half bridge is 0.9 A, if you need more you have to cascade more half bridges, see [manual](https://www.infineon.com/dgdl/Infineon-TLE94112EL-DS-v01_00-EN.pdf?fileId=5546d462576f347501579a2795837d3e) and pin out picture
* the shield is stackable if you change the 0 \Omega resistor from R7/R8. There is also a hack to stack a max number of three TLE94112 (please ask if you need this)
* the first two ports can be directly used also for LEDs but with the help of right dimensioned resistors, any half bridge can be used
for LEDs or other stuff falling in the voltage and current limits of the board
* there is a handy [pin out picture](https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png)
<img src="https://raw.githubusercontent.com/infineon/assets/master/Pictures/TLE94112_Arduino_Shield_Pin_out.png" width=100%>

## Installation of XMC
If you use any Infineon XMC microcontroller like the XMC1100 Boot Kit or the XMC4700 Relax Kit, than you must also
install the [XMC-for-Arduino library from here](https://github.com/Infineon/XMC-for-Arduino).

