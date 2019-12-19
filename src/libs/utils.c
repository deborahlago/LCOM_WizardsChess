
#include <lcom/lcf.h>
#include <stdint.h>

#include "modules/timer/timer.h"

int (util_get_LSB)(uint16_t val, uint8_t *lsb) {

    // Handles the case of inserting invalid address (e.g NULL)
    if (!lsb) return EXIT_FAILURE;

    // Gets only the LSBs from val and sends them to *lsb
    *lsb = (uint8_t)val;

    return EXIT_SUCCESS;
}

int (util_get_MSB)(uint16_t val, uint8_t *msb) {

    // Handles the case of inserting invalid address (e.g NULL)
    if(!msb) return EXIT_FAILURE;

    printf("\nVal before: %X: \n", val);

    // Does Logical Shift Right of val's 8 most significant bits and allocates it in msb
     val >>= 8;

     printf("\nVal after: %X: \n", val);

    *msb = (uint8_t)val;

    return EXIT_SUCCESS;
}

int (util_sys_inb)(int port, uint8_t *value){

    // Creates a local temporary variable temp, reads from
    // register and passes that data into temp's address
    // Allocates the value from temp address to the pointer *value
    // and returns 0 in case of success and non-zero otherwise
    uint32_t temp;

    if (sys_inb(port, &temp) == EXIT_SUCCESS){
        *value = (uint8_t)temp;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}



