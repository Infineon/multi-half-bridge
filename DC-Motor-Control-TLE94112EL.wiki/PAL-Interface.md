The interaction with the hardware and platform resources is abstracted from the core library by the definition of a platform abstraction interface. 

For this shield, the platform resources that need to be provided are:

* **GPIO**. Digital input and output ports.
* **Timer**. A timer for speed calculation related functionalities. 
* **SPIC**. A SPI class interface related functionalities. 

The PAL interfaces are implemented as C++ pure virtual classes.

### GPIO PAL API

* init()
* deinit()
* enableInt()
* disableInt()
* intEvent()
* read()
* write()
* enable()
* disable()

Find the complete specification for each function of the GPIO PAL interface in the [PAL Interface](https://infineon.github.io/DC-Motor-Control-TLE94112EL/d7/dde/classGPIO.html
) Doxygen docs section.

### Timer PAL API

* init()
* deinit()
* start()
* elapsed()
* stop()
* delay()
* delayMilli()
* delayMicro()

Find the complete specification for each function of the Timer PAL interface in the [PAL Interface](https://infineon.github.io/DC-Motor-Control-TLE94112EL/dc/dea/classTimer.html) Doxygen docs section.

### SPIC PAL API

* init()
* deinit()
* transfer()
* transfer16()

Find the complete specification for each function of the SPI interface in the [PAL Interface](https://infineon.github.io/DC-Motor-Control-TLE94112EL/d7/db9/classSPIC.html) Doxygen docs section.

