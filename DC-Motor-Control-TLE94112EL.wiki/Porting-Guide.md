
Porting the library to a new software development framework and hardware platform entails the implementation of the corresponding GPIO and TIMER PAL classes. 
In the following sections, some additional explanations and hints are provided:

## Framework PAL Implementation

Implement the abstract PAL interface for you framework. The **GPIO class**, **Timer class** and **SPIC class** are mandatory.

The Doxygen comments on the *"src/pal/gpio.hpp"*, *"src/pal/timer.hpp"* and *"src/pal/spic.hpp"* describe the required behavior of each function of the [PAL Interface](PAL-Interface). 

Consider the existing framework implementations as reference examples for you design: *"/src/framework/sample_fmwk/pal"*. Some of the functions are optional depending on your framework and intended usage of the library. 

That is the case of *init()* and *deinit()*, which take care of the hardware peripherals init/deinitialization. If this is done in your main application (or somewhere else outside the library), there is no need of delegating such initialization to the Hall Switch library. The definition of these functions can just be a return with the success return code.

## Framework API Wrapper

The framework API wrapper implementation is optional, it is meant to ease the usage. Mostly the main help is to avoid the creation of the GPIO, Timer and SPI object instances for the developer. 

To illustrate this approach, it is easier to evaluate a concrete implementation of the Arduino Wrapper implementation *"src/TLE94112-ino.hpp/cpp"* (these files should be located under *"src/framework/arduino/wrapper/"*. More info [here](Source-Tree-Structure#warning-exceptions)):

1. Adapt the constructor arguments to those used for platform class creation (GPIO, Timer and SPI) in the new framework, using the native data types and structures. Hide what can be already defined for that platform and provide as much abstraction and simplicity as possible.

    For example, the core library of the base constructor is defined like this:

    ```
    Tle94112(void* bus, uint8_t csPin);
    ```

    is wrapped for Arduino like this:

    ```
    Tle94112Ino(SPIClass &bus, uint8_t csPin);
    ```

    While it does not seems to simplify much in number of arguments, an Arduino developer can simply pass the pin number as argument, and does not need to deal with the (probably unknown) GPIO classes, neither specify further GPIO configuration as the mode (input, output, pull-up..), positive/negative logic, etc. 

    As for the constructor, the same philosophy can apply to other functions of the public API. In case of Arduino, as a hobbyist and makers environment, clarity and simplicity might prevail over configurability and functionality. Therefore, the [wrapper API](Arduino-API) further hides, group or eliminate certain functionalities. 
     
    For each ecosystem and framework, any other criteria can be chosen, hopefully matching as well its code conventions, implantation principles and paradigms.  

The following part does not apply to the *TLE9412* library as it is not used here but the framework concept allows
such definitions. So this part is only here for completeness. Please refer to other Infineon framework libraries like the *Hall Switch*
or the *High-Side Switch* which use this concept.

2. Define structs with the hardware configuration parameters pre-configured for the ported stacked eval kit based hardware platforms. 
For existing hardware peripheral break-out boards and shields hardware connections with the base MCU evaluation boards, the GPIO ports (and the timer instances) might be are already fixed.

    A constructor accepting as argument these predefined configuration can make life even easier to the library users.

    Considering again the Arduino API as example, a Hall Switch constructor is provided which accepts *PlatformIno_t* structs:

    ```
    HallSwitchIno(PlatformIno_t hwPlatf,
                  HallSwitch::CBack_t    cBack = NULL);
    ``` 
    Then, in *"src/frawework/Arduino/wrapper/hall-platf-ino.hpp"* some hardware platforms (the validated ones) are already provided:

    ```
    extern PlatformIno_t TLE4964_3M_S2Go_XMC2Go;        /**< TLE4964 3M Shield 2Go + XMC2Go Stack */

    extern PlatformIno_t TLE4964_3M_S2Go_ArduinoUno;    /**< TLE4964 3M Shield 2Go + MyIoT + Arduino Uno Form Factor */

    extern PlatformIno_t TLE4922_2GoKit;                /**< TLE4922 Kit 2Go  */
    ```
    Its definition can be found in the corresponding .cpp file.
