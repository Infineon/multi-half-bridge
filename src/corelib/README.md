# common core library part

Everything in this folder is the common core API to all platforms. It does not 
include hardware or platform dependent structures.
Therefore hardware related parts are covered by abstraction layers, like GPIO, TIMER or SPI.

* TLE94112.hpp/cpp basic TLE94112 core library with basic shield driver
* TLE94112Motor.hpp/cpp the core motorcontroller library which runs on top of the basic shield driver
* tle91112_util.hpp/cpp basic register configuration