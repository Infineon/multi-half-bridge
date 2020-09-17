#include <stdint.h>
#include <stdio.h>
#include "../../../config/tle94112-conf.hpp"
#include <TLE94112-platf-rpi.hpp>
#include <TLE94112-pal-rpi.hpp>
#include <TLE94112.hpp>
#include <TLE94112Motor.hpp>

/**
 * Raspberry Pi TLE94112 Example
 * 
 */

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

Tle94112Rpi controller = Tle94112Rpi();

Tle94112Motor motor(controller);

int main() {
	return 0;
}

#endif