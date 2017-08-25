/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       i2c sam21r master to arduino slave application
 *
 * @author      Erle
 *
 * @}
 */

#include <stdio.h>
#include <string.h>
#include "periph/i2c.h"



int main(void)
{
    char *i2c_message = "This is the i2c working I want to know if increases de signal in the bus";
    uint8_t charLength = strlen(i2c_message);

    puts("I2C Master App");

    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    if (i2c_init_master(I2C_0, I2C_SPEED_FAST) == 0) {
        printf("Trying to send message \"%s\" with length %d\n", i2c_message, charLength);
        if (i2c_write_bytes(I2C_0, 8, i2c_message, charLength) == charLength) {
                printf("I2C message successfully sent!\n");
        } else {
                printf("I2C message not sent!\n");
        }
    } else {
        printf("Error while initializing I2C interface\n");
    }

    return 0;
}
