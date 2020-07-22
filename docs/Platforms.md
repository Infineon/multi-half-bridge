# Platforms

This library is build to support multiple microcontroller platforms.
Normally the standard Arduino/Genuino is the basic target platform which supports every original Arduino
from the ver basic UNO up to the newest evolution of the Atmega platform.
Beside this also other microcontroller based on different CPU platforms like ARM based CPUs are also supported
by the Arduino library if the platform has an Arduino port like the Infineon XMC microcontroller class.
If there is no Arduino port, than the structure of this platform library allows an easy port
into a different system by using common C/C++ structures, so that only a very few parts must
be written new. As an example of that, this library supports the Cypress WICED SDK with a minimal
amount of effort.

## Arduino/Genuino and compatibles

This is the main part of the library and it installs flawlessly for the Arduino IDE or for the PlatformIO system.
It supports the original Arduino/Genuino as well as the Infineon XMC platform:
* Arduino/Genuino UNO and Leonardo
* Infineon XMC1100 BootKit
* Infineon XMC4700 Relax Kit
* (Infineon Aurix Body Kit)

The main header files to include are the *-ino.hpp files the library src directory. For installing
please see [here](Installation.md).

## Cypress WICED SDK for 43xxx ARM based microcontroller

The Cypress WICED SDK uses a different directory structure, but this platform library can
be installed and used under the WICED SDK. Therefore you have to either clone the library from
Github or unpack the downloaded zip file under the drivers section of the WICED SDK.
Todo so see [here](Installation.md).

Please link or copy the apps directory from framework/wiced-43xxx into the apps directory of your WICED SDK.


## Directory structure schema

The structure allows direct Arduino/Genuino support as well as other platforms using the same
core library with only small changes in the platform dependent files.

```.
+- *.md
+- docs
|     +- doxyfile*
|     +- *.md
|     +- img
|          +- *.png
+- examples
|         +- arduino ino sketches
+- src
     +- arduino base lib files *-ino.hpp/cpp
     +- config
     |       +- framework conf/conf-dfl/conf-opts hpp files
     +- corelib
     |        +- common core *.hpp/*.cpp files for all platforms
     +- pal
     |    +- generic platform driver
     +- framework
                +- arduino
                |        +- pal
                |        |    +- arduino platform dependent -pal-ino.hpp/cpp files
                |        +- wrapper
                |                 +- arduino platform wrapper -wrapper.ino.hpp/cpp files
                +- wiced-43xxx
                             +- pal
                             |    +- wiced 43xxx platform dependent -pal-ino.hpp/cpp files
                             +- wrapper
                             |        |
                             |        +- wiced 43xxx platform wrapper -wrapper.ino.hpp/cpp files
                             +- apps
                                   |
                                   +- wiced 43xxx example apps
```







