#include "spic-rpi.hpp"

#if (TLE94112_FRAMEWORK == TLE94112_FRMWK_RPI)

#include <bcm2835.h>
#include <stdio.h>
// #include "SPI.h"

#define EN RPI_V2_GPIO_P1_37


int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
// Use for testing
       // bcm2835_set_debug(1);

  if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    } 
 
    if (!bcm2835_spi_begin())
    {
      printf("bcm2835_spi_begin failed. Are you running as root??\n");
      return 1;
    }
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_LSBFIRST);      // The default
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);                   // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_16);    // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      // The default
    bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      // The default

    // Set Enable Pin to high 
    bcm2835_gpio_fsel(EN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(EN, HIGH);

    // Delay to make sure EN is high before sending SPI message 
    bcm2835_delay(500);

    // Send a some bytes to the slave and simultaneously read 
    // some bytes back from the slave
    // Most SPI devices expect one or 2 bytes of command, after which they will send back
    // some data. In such a case you will have the command bytes first in the buffer,
    // followed by as many 0 bytes as you expect returned data bytes. After the transfer, you 
    // Can the read the reply bytes from the buffer.
    // If you tie MISO to MOSI, you should read back what was sent.
    
    char buf[] = { 0x80, 0x40, 0x08, 0x02 }; // Data to send

    bcm2835_spi_transfern(buf, sizeof(buf));
    // buf will now be filled with the data that was read from the slave
    printf("Read from SPI: %02X  %02X  %02X  %02X \n", buf[0], buf[1], buf[2], buf[3]);

    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}

#endif /** SPIC_RPI_HPP_ **/