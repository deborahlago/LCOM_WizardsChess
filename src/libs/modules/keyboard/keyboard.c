#include <lcom/lcf.h>
#include "keyboard.h"


/* Globals */

// Kernel
uint32_t kernelCallsCount = 0;
uint8_t scancode;

// Interrupt Subscription
int kbcHookId;


int (kbc_sys_inb)(int port, uint8_t *value){

    kernelCallsCount++;

    if (util_sys_inb(port, value) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int (kbc_read_st_byte)(uint8_t *st_byte){

    if (kbc_sys_inb(KBC_STATUS_REG, st_byte) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int (kbc_read_out_buf)(uint8_t *out_buf_data){

    if (kbc_sys_inb(KBC_OUT_BUF, out_buf_data) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


void (kbc_ih)(){

    // Variable initialization for status byte
    // and output buffer data
    uint8_t stByte;
    uint8_t outBuf;

    // Checks for successful read on status byte then
    // reads the status byte and updates stByte's value
    if (kbc_read_st_byte(&stByte) == EXIT_SUCCESS){

        // Checks if the output buffer is full
        // If it's full, the data is available for reading
        if ((stByte & KBC_ST_OUT_BUF_FULL) == KBC_ST_OUT_BUF_FULL){

            // Reads the data from the output buffer
            // and checks if the reading was done successfully
            if (kbc_read_out_buf(&outBuf) == EXIT_SUCCESS){

                // Checks for parity our timeout errors
                // If there are none, updates the scancode value
                if ((stByte & KBC_ST_ERRS) == KBC_ST_NO_ERRS)
                    scancode = outBuf;
            }
        }
    }
}


int (kbc_subscribe_int)(uint8_t *bit_no){
    kbcHookId = *bit_no;

    // Calls the sys_irqsetpolicy() kernel passing IRQ_REENABLE and also IRQ_EXCLUSIVE
    // so that the standard Minix 3 KBC Interrupt Handler will not be notified of the
    // occurrence of KBC Interrupts
    if (sys_irqsetpolicy(KBC_IRQ, (IRQ_REENABLE|IRQ_EXCLUSIVE), &kbcHookId) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int (kbc_unsubscribe_int)(){

    // Disables further interrupts and unsubscribes a previous subscription
    // of the interrupt notification associated with the specified hook_id
    // returned by kbc_subscribe_int
    if (sys_irqdisable(&kbcHookId) == EXIT_SUCCESS)
        return sys_irqrmpolicy(&kbcHookId);

    return EXIT_FAILURE;
}


_Bool (kbc_two_byte_scancode)(uint8_t scancode_byte){
    return scancode_byte == KBC_SCANCODE_TWO_BYTE_CHECK;
}


uint8_t *(kbc_split_bytes)(uint16_t half_word){
    static uint8_t arr[2];

    arr[0] = (uint8_t)(half_word);
    arr[1] = (uint8_t)(half_word >> 8);

    return arr;
}


_Bool (kbc_is_make_code)(uint8_t byte){
    return !(byte & KBC_BREAK_CODE_CHECK);
}


int (kbc_parse_inst)(int kbc_reg, uint8_t kbc_inst, uint8_t *st_byte){

    _Bool inBufFull;

    // Loops while the input buffer is full
    while (true){

        // Checks for successful read on status byte
        // reads the status byte and updates stByte's value
        if (kbc_read_st_byte(st_byte) == EXIT_SUCCESS){

            inBufFull = (*st_byte & KBC_ST_IN_BUF_FULL) == KBC_ST_IN_BUF_FULL;

            // If the input buffer is no longer full write the instruction
            // in the desired register
            if (!inBufFull){
                if (sys_outb(kbc_reg, kbc_inst) == EXIT_SUCCESS)
                    return EXIT_SUCCESS;
            }

            // Armor for loop life span
            tickdelay(micros_to_ticks(KBD_SCAN_DURATION));
        }
    }

    return EXIT_FAILURE;
}


uint8_t kbc_cmd_byte_enable_flags(uint8_t cmd_byte, uint8_t flags){
    return cmd_byte | flags;
}


uint8_t kbc_cmd_byte_disable_flags(uint8_t cmd_byte, uint8_t flags){
    return cmd_byte ^ flags;
}


int (kbc_write_cmd)(uint8_t kbc_cmd, uint8_t *st_byte){

    uint8_t cmdOut;

    /* KBC_WRITE_CMD */
    if (kbc_cmd == KBC_WRITE_CMD){

        // Get the command byte from the status register
        if (kbc_parse_inst(KBC_STATUS_REG, KBC_READ_CMD, st_byte) == EXIT_SUCCESS){

            // Gets the kbc command return value from the output buffer
            if (kbc_sys_inb(KBC_OUT_BUF, &cmdOut) == EXIT_SUCCESS){

                // Parses the kbc command to the command register
                if (kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte) == EXIT_SUCCESS){

                    // Parses the command read from the output buffer to the
                    // input buffer and returns success
                    uint8_t flags = KBC_CMD_BYTE_ENABLE_KBD_INTERRUPT;
                    uint8_t transfCmdByte = kbc_cmd_byte_enable_flags(cmdOut, flags);

                    if (kbc_parse_inst(KBC_IN_BUF, transfCmdByte, st_byte) == EXIT_SUCCESS)
                        return EXIT_SUCCESS;
                }
            }
        }

        return EXIT_FAILURE;
    }

    /* KBC_CMD_CHECK_CONTROLLER */
    else if (kbc_cmd == KBC_CMD_CHECK_CONTROLLER){

        // Parses the kbc command to the command register
        if (kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte) == EXIT_SUCCESS){

            if (kbc_sys_inb(KBC_OUT_BUF, &cmdOut) == EXIT_SUCCESS) {
                return cmdOut == KBC_SELF_TEST_OK ? EXIT_SUCCESS : EXIT_FAILURE;
            }
        }

        return EXIT_FAILURE;
    }

    /* KBC_CMD_CHECK_KBD_INTERFACE */
    else if (kbc_cmd == KBC_CMD_CHECK_KBD_INTERFACE){

        return kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte);
    }

    /* KBC_CMD_ENABLE_KBD_INTERFACE */
    else if (kbc_cmd == KBC_CMD_ENABLE_KBD_INTERFACE){

        if (kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte) == EXIT_SUCCESS){
            printf("Keyboard Enabled");
            return EXIT_SUCCESS;
        }

        return EXIT_FAILURE;
    }

    /* KBC_CMD_DISABLE_KBD_INTERFACE */
    else if (kbc_cmd == KBC_CMD_DISABLE_KBD_INTERFACE){

        if (kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte) == EXIT_SUCCESS){
            printf("Keyboard Disabled");
            return EXIT_SUCCESS;
        }

        return EXIT_FAILURE;
    }

    /* KBC_CMD_CHECK_MOUSE_INTERFACE */
    else if (kbc_cmd == KBC_CMD_CHECK_MOUSE_INTERFACE){

        return kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte);
    }

    /* KBC_CMD_ENABLE_MOUSE */
    else if (kbc_cmd == KBC_CMD_ENABLE_MOUSE){

        if (kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte) == EXIT_SUCCESS){
            printf("Mouse Enabled");
            return EXIT_SUCCESS;
        }

        return EXIT_FAILURE;
    }

    /* KBC_CMD_DISABLE_MOUSE */
    else if (kbc_cmd == KBC_CMD_DISABLE_MOUSE){

        if (kbc_parse_inst(KBC_CMD_REG, kbc_cmd, st_byte) == EXIT_SUCCESS){
            printf("Mouse Disabled");
            return EXIT_SUCCESS;
        }

        return EXIT_FAILURE;
    }

    /* KBC_CMD_WRITE_BYTE */
    else if (kbc_cmd == KBC_CMD_WRITE_BYTE){

        // Get the command byte from the status register
        if (kbc_parse_inst(KBC_CMD_REG, KBC_CMD_WRITE_BYTE, st_byte) == EXIT_SUCCESS)
            return EXIT_SUCCESS;

        return EXIT_FAILURE;
    }
    else {

        printf("Invalid Command!");
        return EXIT_FAILURE;
    }

}

