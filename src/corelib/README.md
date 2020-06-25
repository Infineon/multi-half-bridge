# Common library part

Everything in this folder is the common core API to all platforms. It does not 
include Hardware or platform dependent structures.
Therefore hardware related parts are covers by abstraction layers, like GPIO, TIMER or SPI.

* TLE94112.hpp/cpp basic TLE94112 library with the hardware abstraction layer
* TLE94112Motor.hpp/cpp the motorcontroller library with the abstraction layer
* tle91112_util.hpp/cpp basic register configuration