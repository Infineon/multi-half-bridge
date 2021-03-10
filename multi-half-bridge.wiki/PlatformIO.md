## Introduction

If you are new to PlatformIO, download and install first Visual Studio Code and the PlatformIO plugin. Please follow the instructions on the [official website](https://docs.platformio.org/en/latest/ide/pioide.html). Then go through [this tutorial](https://diyprojects.io/install-ide-platformio-extension-visual-studio-code-vscode-windows-32-bit-linux/#.XOVQP44zYnI) to get started with PlatformIO in VSCode and create a new project. 

## Library Installation 

With the project created, now the library and its dependencies can be configured in the ***Platform.ini* Project File**. This file, located in the project root folder, includes one (or several) building environments *[env:__]*.

In the *environment* section, the platform, board, and framework are specified. PlatformIO will take care of downloading and installing all dependencies.

In the following example, we use the XMC1100 Evaluation Kit (only available for Arduino):

```
[env:xmc1100_xmc2go]
platform = infineonxmc
board = xmc1100_xmc2go
framework = arduino

lib_deps =
# Using a library name
multi-half-bridge

# Using the repository URL
    https://github.com/Infineon/multi-half-bridge.git#master
```
You can also simply take the platformio.ini file from the main *TLE94112* repo. This file includes all settings for using
this library with 
