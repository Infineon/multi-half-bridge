The *src/config* sources provides the C-macro level library configuration.

Through defines configuration the different modules of the library are conditionally compiled. Thus, only the code needed is added to the binary. The main selectable parameters are:

- **Software Framework**. ```#ifdef/#ifndef``` guards are added to all source files for the framework specific sources. Through of the ```#define``` parameters, the development framework can be selected. 


## Config Files

The configuration folder includes 3 files:

* *tle94112-opts.hpp*. All the library configuration macro define options.
* *tle94112-conf.hpp*. This is the actual configuration file. 
* *tle94112-config-dfl.hpp*. This is the default configuration. This file is included (```#include```) in *tle94112-conf.hpp*. If any optional parameter is not defined, then the default value will be set in this file. If any user selectable mandatory configuration is not set, an error will be thrown during compilation, requesting the definition of such parameter.
