# pal/arduino platform layer for arduino

Under this directory all available frameworks are listed. If you want to implement your own,
than all hardware related code goes here under a senseful directory name. Include this also
in the -conf-opt list:

* arduino includes the standard Arduino/Genuino code which also runs with all boards which have conversion library like Infineon XMC microcontroller
* wiced-43xxx includes the Cypress code for 43xxx boards and the WICED SDK
* the Cypress modus toolbox  

Other frameworks are welcomed.
