#include <lcom/lcf.h>
#include <lcom/timer.h>

#include <stdint.h>
#include "timer.h"


/* Globals */

int timerHookId = 0;
uint64_t timerIntCounter = 0;


/* Useful Functions */

_Bool(timer_is_valid)(uint8_t timer){
    return timer >= 0 && timer <= 2;
}


int (util_sys_outb)(int port, uint8_t value){

    uint32_t temp = value;
    return sys_outb(port, temp) == EXIT_SUCCESS ? EXIT_SUCCESS : EXIT_FAILURE;
}


uint16_t (get_selected_timer)(uint8_t timer){
    return timer != 0 ? timer != 1 ? TIMER_2 : TIMER_1 : TIMER_0;
}


uint8_t (get_timer_bits)(uint8_t timer){
    return timer != 0 ? timer != 1 ? TIMER_SEL2 : TIMER_SEL1 : TIMER_SEL0;
}


uint8_t (assemble_instruction)(uint8_t timer, enum rb_command_list cmd, uint8_t st){
    uint8_t instruction;
    switch (cmd){
        case GET_CONF:
            instruction = (TIMER_RB_CMD | TIMER_RB_COUNT_ | TIMER_RB_SEL(timer));
            break;

        case SET_FREQ:
            instruction = (get_timer_bits(timer) | TIMER_LSB_MSB | (st & COUNTING_MODE_BITMASK) | (st & BCD_BITMASK));
            break;

        case SET_FREQ_SQUARE:
            instruction = (get_timer_bits(timer) | TIMER_LSB_MSB | (st & TIMER_SQR_WAVE) | (st & TIMER_BIN));
            break;

        default:
            return EXIT_FAILURE;
    }
    return instruction;
}



/* Timer Functions */

int (timer_set_frequency)(uint8_t timer, uint32_t freq) {

    if (timer_is_valid(timer)){

        // Checks for valid frequency
        //
        // The Intel 82C54 provides three independent 16-bit counters,
        // each capable of handling clock inputs up to 10 MHz. Meaning the maximum
        // value we can represent for the frequency input is 2^16 - 1, which equals 65 535.
        // Since the frequency of the Clock input of all timers is 1 193 181 Hz,
        // and since the frequency is given by the expression TIMER_FREQ/freq, which needs
        // to be lower than 65 535:
        //
        // (1 193 181 / freq) <= 65 536 <=> freq >= 18,2065
        //
        // if the argument `freq` is less than 18,2065,
        // the result would be bigger than 65 535 (2^16-1),
        // otherwise producing an overflow error.
        // So the valid interval for freq would be: [18.2065; 65 536]
        _Bool validFrequency = (freq >= MIN_FREQ) && (freq <= TIMER_FREQ);

        if (validFrequency){

            // Get timer configuration, if the function returns a success, proceed :)
            uint8_t status;
            if (timer_get_conf(timer, &status) == EXIT_SUCCESS){

                // Assembles the control word saving the state of the 4 LSBs
                // (mode and BCD/binary) of the timer's configuration.
                uint8_t ctrlWord = assemble_instruction(timer, SET_FREQ, status);

                if (util_sys_outb(TIMER_CTRL, ctrlWord) == EXIT_SUCCESS) {

                    /* Change timer frequency */

                    // Calculate the new frequency
                    uint16_t newTimerFreq = TIMER_FREQ / freq;

                    // Get selected timer and parse the least and most
                    // significant bits from that timer's configuration
                    uint8_t newFreqLsb;
                    uint8_t newFreqMsb;

                    uint16_t selectedTimer = get_selected_timer(timer);
                    util_get_LSB(newTimerFreq, &newFreqLsb);
                    util_get_MSB(newTimerFreq, &newFreqMsb);

                    // Write the real timer frequency's most and least significant bits
                    // into memory, thus changing the operating frequency of the selected timer
                    if (util_sys_outb(selectedTimer, newFreqLsb) == EXIT_SUCCESS){
                        if (util_sys_outb(selectedTimer, newFreqMsb) == EXIT_SUCCESS)
                            return EXIT_SUCCESS;
                    }
                }
            }
        }
    }

    return EXIT_FAILURE;
}


int (timer_set_square)(uint8_t timer, uint32_t freq){

    _Bool validFrequency = (freq >= MIN_FREQ) && (freq <= TIMER_FREQ);

    if (validFrequency){

        // Get timer configuration, if the function returns a success, proceed :)
        uint8_t status;
        if (timer_get_conf(timer, &status) == EXIT_SUCCESS){

            // Assembles the control word saving the state of the 4 LSBs
            // (mode and BCD/binary) of the timer's configuration.
            uint8_t ctrlWord = assemble_instruction(timer, SET_FREQ_SQUARE, status);

            if (util_sys_outb(TIMER_CTRL, ctrlWord) == EXIT_SUCCESS) {

                /* Change timer frequency */

                // Calculate the new frequency
                uint16_t newTimerFreq = TIMER_FREQ / freq;

                // Get selected timer and parse the least and most
                // significant bits from that timer's configuration
                uint8_t newFreqLsb;
                uint8_t newFreqMsb;

                uint16_t selectedTimer = get_selected_timer(timer);
                util_get_LSB(newTimerFreq, &newFreqLsb);
                util_get_MSB(newTimerFreq, &newFreqMsb);

                // Write the real timer frequency's most and least significant bits
                // into memory, thus changing the operating frequency of the selected timer
                if (util_sys_outb(selectedTimer, newFreqLsb) == EXIT_SUCCESS){
                    if (util_sys_outb(selectedTimer, newFreqMsb) == EXIT_SUCCESS)
                        return EXIT_SUCCESS;
                }
            }
        }
    }

    return EXIT_FAILURE;
}


int (timer_subscribe_int)(uint8_t *bit_no) {

    timerHookId = *bit_no;

    // Calls the sys_irqsetpolicy() kernel passing IRQ_REENABLE
    // so that the generic interrupt handler will acknowledge the interrupt,
    // ouput the EOI command to the PIC thus enabling further interrupts on
    // the corresponding IRQ line
    if (sys_irqsetpolicy(TIMER0_IRQ, IRQ_REENABLE, &timerHookId) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int (timer_unsubscribe_int)() {

    // Disables further interrupts and unsubscribes a previous subscription
    // of the interrupt notification associated with the specified hook_id
    // returned by timer_subscribe_int
    if (sys_irqdisable(&timerHookId) == EXIT_SUCCESS){
        return sys_irqrmpolicy(&timerHookId);
    }

    return EXIT_FAILURE;
}


void (timer_ih)() {
    timerIntCounter++;
}


int (timer_get_conf)(uint8_t timer, uint8_t *st) {

    if (timer_is_valid(timer)) {

        // Assembles the Read-Back Command and writes it to the control register,
        // if it cannot be written to the control register returns failure
        //
        // The Read-Back Command has the following structure: 1110XXX0
        uint8_t readBackCmd = assemble_instruction(timer, GET_CONF, 0);
        if (util_sys_outb(TIMER_CTRL, readBackCmd) == EXIT_SUCCESS){

            /* Fetch the timer status */

            // Get the selected timer and read status value from that timer
            // and store it in the timerSt address
            return util_sys_inb(get_selected_timer(timer), st);
        }
    }

    return EXIT_FAILURE;
}


int (timer_display_conf)(uint8_t timer, uint8_t st, enum timer_status_field field) {

    if (timer_is_valid(timer)){

        // Parses configuration data from st using defined bit masks
        uint8_t stCounterInit = (st & COUNTER_INIT_BITMASK);
        uint8_t stProgMode = (st & COUNTING_MODE_BITMASK);
        uint8_t stBcd = (st & BCD_BITMASK);

        // Instantiates timer_status_field_val object
        union timer_status_field_val stFieldVal;

        // Determines what to do depending on the value gotten from field
        switch (field){
            case tsf_all:
                stFieldVal.byte = st;
                break;
            case tsf_initial:
                if (stCounterInit == BIT_4_BITMASK)
                    stFieldVal.in_mode = LSB_only;

                else if (stCounterInit == BIT_5_BITMASK)
                    stFieldVal.in_mode = MSB_only;

                else if (stCounterInit == COUNTER_INIT_BITMASK)
                    stFieldVal.in_mode = MSB_after_LSB;

                else stFieldVal.in_mode = INVAL_val;

                break;
            case tsf_mode:
                // Converts stProgMode into their correspondent decimal value
                stProgMode >>= 1;

                // Handles exceptional cases
                if (stProgMode == 6) stFieldVal.count_mode = 2;
                else if (stProgMode == 7) stFieldVal.count_mode = 3;
                else stFieldVal.count_mode = stProgMode;

                break;
            case tsf_base:
                stFieldVal.bcd = stBcd == BCD_BITMASK;
                break;
            default:
                return EXIT_FAILURE;
        }

        return timer_print_config(timer, field, stFieldVal);
    }

    return EXIT_FAILURE;
}




