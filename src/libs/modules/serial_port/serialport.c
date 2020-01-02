#include "serialport.h"

/* Globals */

int uartCom1HookId;
int uartCom2HookId;


void (sp_get_ctrl)(uint32_t *com1_ctrl_reg){

    if (sys_inb((UART_COM1_ADDR + UART_LINE_CTRL), &conf) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


void (sp_get_status)(uint32_t *com1_st_reg){

    if (sys_inb((UART_COM1_ADDR + UART_LINE_STATUS), &lsr) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int sp_write_th (uint16_t port, uint32_t char_data){

    if (sys_outb(port, char_data) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int sp_read_buffer (uint16_t port, uint8_t *char_data){

    if (util_sys_inb(port, char_data) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;

}


int sp_subscribe_int (){

    if (sys_irqsetpolicy(UART_COM1_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, &uartCom1HookId) == EXIT_SUCCESS){

        if (sys_irqsetpolicy(UART_COM2_IRQ, IRQ_REENABLE | IRQ_EXCLUSIVE, &uartCom2HookId) == EXIT_SUCCESS)
            return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}


int sp_unsubscribe_int(){

    if (sys_irqrmpolicy(&uartCom1HookId) == EXIT_SUCCESS){

        if (sys_irqrmpolicy(&uartCom2HookId) == EXIT_SUCCESS)
            return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}


void sp_enable_int(uint32_t *char_data){

    // com1
    sys_inb(UART_COM1_ADDR + UART_IH_ENABLE, char_data);
    cdata |= 0x03;

    sys_outb(UART_COM1_ADDR + UART_IH_ENABLE, *char_data);


    // com2
    sys_inb(UART_COM2_ADDR + UART_IH_ENABLE, char_data);
    cdata |= 0x03;

    sys_outb(UART_COM2_ADDR + UART_IH_ENABLE, *char_data);
}


void sp_disable_int(uint32_t *char_data){

    // com1
    sys_inb(UART_COM1_ADDR + 1, char_data);
    cdata &= 0xFE;

    sys_outb(UART_COM1_ADDR + 1, *char_data);


    // com2
    sys_inb(UART_COM2_ADDR + 1, char_data);
    cdata &= 0xFE;

    sys_outb(UART_COM2_ADDR + 1, *char_data);
}


_Bool sp_trans_ready(uint16_t port, uint32_t *char_data){

    sys_inb((port + UART_INT_ID), char_data);
    uint8_t origin = (*char_data & UART_INT_ORIGIN);

    return origin == 2;
}


_Bool sp_data_available(uint16_t port, uint32_t *char_data){

    sys_inb((port + UART_INT_ID), char_data);
    uint8_t origin = (*char_data & UART_INT_ORIGIN);

    return origin == 4;
}


int sp_set_rate(uint16_t port, uint32_t rate){

    uint32_t lineCtrl = 0;
    uint32_t outLineCtrl = 0;
    uint32_t div = UART_RATE / rate;

    if (sys_inb((port + UART_LINE_CTRL) , &lineCtrl) == EXIT_SUCCESS){

        outLineCtrl = lineCtrl | DLAB;

        if (sys_outb((port + UART_LINE_CTRL ), outLineCtrl) == EXIT_SUCCESS){

            if (sys_outb((port + UART_DL_LSB ), (div & 0xFF)) == EXIT_SUCCESS){

                if (sys_outb((port + UART_DL_MSB ), (div >> 8)) == EXIT_SUCCESS){

                    if (sys_outb((port + UART_LINE_CTRL ), lineCtrl) == EXIT_SUCCESS)
                        return EXIT_SUCCESS;
                }
            }
        }
    }

    return EXIT_FAILURE;
}


void sp_show_config (){

    uint32_t lineCtrl;
    uint32_t IER;
    uint32_t outLineCtrl;
    uint32_t msb, lsb, rate;

    if (sys_inb((UART_COM1_ADDR + SP_LINE_CTRL), &lineCtrl) == EXIT_SUCCESS)
        printf("\nLINE CTRL REG:%X\n", lineCtrl);

    else printf("\nError occurred -> LINE CTRL REG (1)\n");


    if (sys_inb(UART_COM1_ADDR + SP_IH_ENABLE, &IER) == EXIT_SUCCESS)
        printf("INTERRUPT ENABLE REG:%X\n", IER);

    else printf("\nError occurred -> INTERRUPT ENABLE REG\n");


    outLineCtrl = lineCtrl | DLAB;
    if (sys_outb((UART_COM1_ADDR + UART_LINE_CTRL), outLineCtrl) == EXIT_SUCCESS){

        if (sys_inb ((UART_COM1_ADDR + UART_DL_LSB ), &lsb) == EXIT_SUCCESS){

            if (sys_inb ((UART_COM1_ADDR + UART_DL_MSB ), &msb) == EXIT_SUCCESS){

                rate =  msb << 8;
                rate += lsb;

                printf("DIVISOR LATCH:%X  RATE:%d\n", rate, SP_RATE/rate);
                outLineCtrl = 0;
            }
        }
    }
    else printf("\nError occurred -> DIVISOR LATCH\n");



    if (sys_inb((UART_COM1_ADDR + UART_LINE_CTRL), &outLineCtrl) == EXIT_SUCCESS)
        printf("LINE CTRL REG:%X\n", outLineCtrl);

    else printf("\nError occurred -> LINE CTRL REG (2)\n");


    if (sys_outb((UART_COM1_ADDR + UART_LINE_CTRL ), lineCtrl) == EXIT_SUCCESS){

        if (sys_inb((UART_COM1_ADDR + UART_LINE_CTRL), &outLineCtrl) == EXIT_SUCCESS)
            printf("LINE CTRL REG:%X\n", outLineCtrl);
    }
    else printf("\nError occurred -> LINE CTRL REG (3)\n");

}

int sp_fifo_init(uint16_t port){

    uint32_t reg;

    if (sys_inb((port + UART_FIFO_CTRL), &reg) == EXIT_SUCCESS){
        reg |= (BIT(0) | BIT(1) | BIT(2));
        reg &= ~(BIT(7) | BIT(6));

        if (sys_outb((port + UART_FIFO_CTRL), reg) == EXIT_SUCCESS)
            return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}