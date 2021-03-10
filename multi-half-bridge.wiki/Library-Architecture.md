The *Tle94112* library follows the architecture pattern shown in the stack diagram:

<img src="img/ifx-gen-arch.png" width=350>

The monolithic *core library* can be universally integrated across any low level peripheral drivers,
embedded operating system, and middleware of each software framework.

The reusability and interoperability is achieved by defining a Platform Abstraction Layer (PAL)
interface which is implemented by each framework for its specific hardware abstraction layer and 
operating system resources APIs.

Additionally, the *core library* API is accommodated and adapted to the particularities of each software
framework. The framework API wrappers intend to harmonize the *core library* API with that of the 
software development framework in which it is integrated, making it easier for the users already 
familiarized with the development framework.

The support for the multiple hardware platforms is then provided by each development framework.

The specific *Tle94112* library modules are depicted more specifically below:

<img src="img/tle94112-arch.png" width=370>

In the next sections, the information of the main architecture modules for the *Tle94112* 
library is extended.

## Core Library

The *core library* contains all the library logic and high level functionalities of the sensor
peripheral. The *core library* remains C++ agnostic by interacting with the specific platform (and framework) 
through a *Platform Abstraction Layer* interface. No other dependencies than standard C/C++ modules 
and the PAL are found in these sources. 

Additionally to the *Tle94112* class, a *Tle94112Motor* class extends the functionality with easy to use
functions allowing a to control a motor commands like start, top, coast, etc. . 

These code sources can be found under *"src/corelib"*. 

The core lib API provides access to all *Tle94112* functionalities given the 
instances to the required PAL instances. Find more information in the [Tle94112 API](TLE94112-API) and [TLE94112Motor API](TLE94112Motor-API) sections. 

## Platform Abstraction Layer (PAL) Interface

The *Platform Abstraction Layer Interface* is implemented via abstract C++ classes declaring all 
the necessary platform resources and functionalities that need to be provided by the specific
framework-platform implementation. 

The simple *Tle94112* specifies in its PAL modules a *GPIO class*, a *Timer class* and *SPI class*. 
Its implementation is located in the *"src/pal"* folder.

The PAL interfaces functions, behavior description and implementation details, can be 
found in the [PAL Interface](PAL-Interface) section.

## Framework PAL

The PAL interfaces is defined for each embedded software framework through its low level peripheral 
drivers and operating system resources APIs. The **GPIO**, **Timer** and **SPI** interface abstract classes are
inherited and defined in this layer. 

The *"src/framework/sample_fmwk/pal"* folder contains the pal implementation for the particular framework.

Find more information about the supported software development frameworks in the [Software Frameworks](Software-Frameworks) section.

## Framework API Wrapper

The idea behind this layer is to adapt the library in order to comply with the programming conventions
of the integrated programming framework or ecosystem. 

Operating system libraries, low level driver of hardware peripherals (digital input/outputs, PWM, analog 
conversion, etc.) or other middleware resources are implemented for each development framework 
following certain patterns for functions, parameters, and primitive types. 

At these level, certain platform functionalities required by *Tle94112* can be already defined and adapted 
to the API available resources: functions prototypes, framework core libraries, low level driver HAL, 
programming patterns, and even framework feel and look aspects.

The frameworks wrapper API files are located in the *"src/framework/sample_fmwk/wrapper"* folders.

Find more information about each software development frameworks API in the [Software Frameworks](Software-Frameworks) section.

### Predefined Hardware Platforms

Given a particular hardware platform and development software framework, most of the resources and its
configuration can be already determined by default. This part of the framework API just define some 
pre configured instances for common and officially supported evaluation kits based configuration. 

These instances are available in the *"src/framework/sample_fmwk/wrapper/zzz-platf-xxx.hpp/cpp"*
source files. 

Check out the supported ones in the [Hardware Platforms](Hardware-Platforms) section.



