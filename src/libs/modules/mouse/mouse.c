#include "mouse.h"

/* Globals */

// Interrupt Subscription
int ps2HookId;

// Mouse Packet
struct packet pkt;

uint8_t pktByte;
int pktCounter = 0;

_Bool gestureComplete;


int (mouse_subscribe_int)(uint8_t *bit_no){
    ps2HookId = *bit_no;

    // Calls the sys_irqsetpolicy() kernel passing IRQ_REENABLE and also IRQ_EXCLUSIVE
    // so that the standard Minix 3 PS/2 Interrupt Handler will not be notified of the
    // occurrence of PS/2 Interrupts
    if (sys_irqsetpolicy(PS2_IRQ, (IRQ_REENABLE|IRQ_EXCLUSIVE), &ps2HookId) == EXIT_SUCCESS)
        return EXIT_SUCCESS;

    return EXIT_FAILURE;
}


int (mouse_unsubscribe_int)(){

    // Disables further interrupts and unsubscribes a previous subscription
    // of the interrupt notification associated with the specified hook_id
    // returned by mouse_subscribe_int
    if (sys_irqdisable(&ps2HookId) == EXIT_SUCCESS)
        return sys_irqrmpolicy(&ps2HookId);

    return EXIT_FAILURE;
}


void (mouse_ih)(){

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
                // If there are none, updates the packet byte value
                if ((stByte & (KBC_ST_PARITY_ERR | KBC_ST_TIMEOUT_ERR)) == KBC_ST_NO_ERRS)
                    pktByte = outBuf;
            }
        }
    }
}


int (mouse_write_cmd)(uint8_t arg, uint8_t* st_byte){

    // Allows for command to be passed and written to the PS/2 controller
    if (kbc_write_cmd(KBC_CMD_WRITE_BYTE, st_byte) == EXIT_SUCCESS){

        if (arg == PS2_CMD_READ_DATA){

            if (kbc_parse_inst(KBC_OUT_BUF, PS2_CMD_READ_DATA, st_byte) == EXIT_SUCCESS){

                uint8_t value;
                if (kbc_read_out_buf(&value) == EXIT_SUCCESS){
                    _Bool isAcknowlegmentByte = (value == PS2_ACKOWLEDGED || value == PS2_NOT_ACKOWLEDGED || value == PS2_ACKNOWLEDGMENT_ERROR);

                    if (isAcknowlegmentByte)
                        return (int)value;
                }
            }
        }

        else {

            if (kbc_parse_inst(KBC_IN_BUF, arg, st_byte) == EXIT_SUCCESS){

                uint8_t value;
                if (kbc_read_out_buf(&value) == EXIT_SUCCESS){
                    _Bool isAcknowlegmentByte = (value == PS2_ACKOWLEDGED || value == PS2_NOT_ACKOWLEDGED || value == PS2_ACKNOWLEDGMENT_ERROR);

                    if (isAcknowlegmentByte)
                        return (int)value;
                }
            }
        }
    }

    return PS2_WRITE_CMD_ERR;
}


int (mouse_set_defaults)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_DEFAULTS, st_byte);
}

int (mouse_reset)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_RESET, st_byte);
}

int (mouse_resend)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_RESEND, st_byte);
}

int (mouse_st_req)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_STATUS_REQUEST, st_byte);
}

int (mouse_request_packet)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_READ_DATA, st_byte);
}

int (mouse_enable_data_report)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_ENABLE_DATA_REPORTING, st_byte);
}

int (mouse_disable_data_report)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_DISABLE_DATA_REPORTING, st_byte);
}

int (mouse_stream_mode)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_STREAM_MODE, st_byte);
}

int (mouse_remote_mode)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_REMOTE_MODE, st_byte);
}

int (mouse_accel_mode)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_ACCEL_MODE, st_byte);
}

int (mouse_linear_mode)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_LINEAR_MODE, st_byte);
}

int (mouse_resolution)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_RESOLUTION, st_byte);
}

int (mouse_sampling_rate)(uint8_t *st_byte){
    return mouse_write_cmd(PS2_CMD_SET_SAMPLING_RATE, st_byte);
}


int (mouse_parse_packet_byte)(){

    if (pktCounter == 0){
        _Bool pktIsSynched = (pktByte & PS2_PKT_SYNCHED);

        if (pktIsSynched){
            pkt.bytes[0] = pktByte;
            pktCounter++;
        }

        return EXIT_FAILURE;
    }

    else if (pktCounter == 1){
        pkt.bytes[1] = pktByte;
        pktCounter++;
    }

    else {
        pkt.bytes[2] = pktByte;
        pktCounter++;
    }

    return EXIT_SUCCESS;
}


uint16_t mouse_x_twos_cmp_to_bin(uint8_t byte){
    uint16_t tmp = byte;
    return (BIT(4) & pkt.bytes[0]) ? tmp - 256 : byte;
}

uint16_t mouse_y_twos_cmp_to_bin(uint8_t byte){
    uint16_t tmp = byte;
    return (BIT(5) & pkt.bytes[0]) ? tmp - 256 : byte;
}


int (mouse_assemble_packet)(){

    pkt.lb = BIT(0) & pkt.bytes[0];
    pkt.rb = BIT(1) & pkt.bytes[0];
    pkt.mb = BIT(2) & pkt.bytes[0];

    pkt.x_ov = BIT(6) & pkt.bytes[0];
    pkt.y_ov = BIT(7) & pkt.bytes[0];

    pkt.delta_x = mouse_x_twos_cmp_to_bin(pkt.bytes[1]);
    pkt.delta_y = mouse_y_twos_cmp_to_bin(pkt.bytes[2]);

    return EXIT_SUCCESS;
}


int (mouse_read_packet_byte)(uint8_t *packet_byte){
    uint8_t stByte;
    _Bool outBufFull;

    // Loops while the input buffer is full
    while (true){

        // Checks for successful read on status byte
        // reads the status byte and updates status byte's value
        if (kbc_read_st_byte(&stByte) == EXIT_SUCCESS){

            outBufFull = (stByte & KBC_ST_OUT_BUF_FULL) == KBC_ST_OUT_BUF_FULL;

            // If the input buffer is no longer full write the instruction
            // in the desired register
            if (outBufFull){
                if ((stByte & (KBC_ST_PARITY_ERR | KBC_ST_TIMEOUT_ERR)) == KBC_ST_NO_ERRS){
                    if (kbc_read_out_buf(packet_byte) == EXIT_SUCCESS)
                        return EXIT_SUCCESS;
                }
            }

            // Armor for loop life span
            tickdelay(micros_to_ticks(KBD_SCAN_DURATION));
        }
    }

    return EXIT_FAILURE;
}


int (mouse_fetch_data)(uint8_t *st_byte, int max_tries){
    int res;
    int n = 0;

    uint8_t aknByte = 0;

    while (aknByte != PS2_ACKOWLEDGED){

        res = mouse_request_packet(st_byte);

        if (res != PS2_WRITE_CMD_ERR){
            aknByte = (uint8_t)res;
            return EXIT_SUCCESS;
        }

        n++;
        if (n == max_tries) break;
    }

    return EXIT_FAILURE;
}

struct mouse_event* (mouse_event_handler)(struct packet* pkt){

    static struct mouse_event curr_event;
    static _Bool lb = false, mb = false, rb = false;

    // Left button released
    if (lb && !pkt->lb) curr_event.type = LB_REL;

    // Left button pressed
    else if (!lb && pkt->lb) curr_event.type = LB_PRE;

    // Right button released
    else if (rb && !pkt->rb) curr_event.type = RB_REL;

    // Left button pressed
    else if (!rb && pkt->rb) curr_event.type = RB_PRE;

    // Mouse movement
    else if (pkt->delta_x != 0 || pkt->delta_x != 0){
            curr_event.type = MOV;
            curr_event.delta_x = pkt->delta_x;
            curr_event.delta_y = pkt->delta_y;
    }

    // Middle button pressed
    else if (mb && !pkt->mb) curr_event.type = OTHER;

    // Middle button released
    else if (!mb && pkt->mb) curr_event.type = OTHER;

    // Other scenarios
    else curr_event.type = OTHER;


    // Update mouse button values
    lb = pkt->lb;
    rb = pkt->rb;
    mb = pkt->mb;

    return &curr_event;
}


void mouse_state_machine(struct mouse_event* curr_ev, uint8_t x_len, uint8_t tol){

    static mouse_states mouseState = INIT;
    static int x_mov, y_mov;

    mouse_ev_type eventType = curr_ev->type;

    int16_t currDeltaX = curr_ev->delta_x;
    int16_t currDeltaY = curr_ev->delta_y;

    x_mov += currDeltaX;
    y_mov += currDeltaY;

    switch(mouseState){
        case INIT:
            printf("State: INIT \n");

            if (eventType == LB_PRE){

                // Draw the first line if LB is pressed
                mouseState = DRAW_1st_LINE;

                // Resets x and y movement
                x_mov = 0;
                y_mov = 0;
            }
            break;

        case DRAW_1st_LINE:
            printf("State: DRAW_1st_LINE \n");

            if(eventType == MOV){

                // Update x and y movement and keep the same state
                // when only movement occurs
                mouseState = DRAW_1st_LINE;


                _Bool xMovBackward = (currDeltaX < 0);
                _Bool yMovBackward = (currDeltaY < 0);
                _Bool xNotWithinTolerance = (abs(currDeltaX) > tol);
                _Bool yNotWithinTolerance = (abs(currDeltaY) > tol);

                if (xMovBackward && xNotWithinTolerance) mouseState = INIT;
                if (yMovBackward && yNotWithinTolerance) mouseState = INIT;

            }

            // LB released
            else if (eventType == LB_REL){

                printf("xmov: %d xlen: %d ymov: %d", x_mov, x_len, y_mov);

                if((abs(y_mov) > abs(x_mov)) && (x_mov >= x_len)){

                    // End of the first line - vertice point
                    mouseState = PAUSE;

                    // Resets x and y movement
                    x_mov = 0;
                    y_mov = 0;
                }
                else mouseState = INIT;
            }
            break;

        case PAUSE:
            printf("State: PAUSE \n");

            if (eventType == MOV){

                // Keeps the same state and increasing x and y movement
                // if there is only mouse movement
                if( y_mov > tol || x_mov > tol)
                    mouseState = INIT;
            }

            else if (eventType == RB_PRE){
                // Draws the 2nd line if the RB is pressed
                mouseState = DRAW_2nd_LINE;

                // Resets x and y movement
                x_mov = 0;
                y_mov = 0;
            }

            else if (eventType == LB_PRE){

                // If the left button is pressed, we are drawing the first line
                mouseState = DRAW_1st_LINE;

                // Resets x and y movement
                x_mov = 0;
                y_mov = 0;
            }

            break;

        case DRAW_2nd_LINE:
            printf("State: DRAW_2nd_LINE \n");

            if(eventType == MOV){
                // Keeps the same state and increasing x and y movement
                // if there is only mouse movement
                mouseState = DRAW_2nd_LINE;

                _Bool xMovBackward = currDeltaX < 0;
                _Bool yMovForward = currDeltaY > 0;
                _Bool xNotWithinTolerance = abs(currDeltaX) > tol;
                _Bool yNotWithinTolerance = abs(currDeltaY) > tol;

                if (xMovBackward && xNotWithinTolerance) mouseState = INIT;
                if (yMovForward && yNotWithinTolerance) mouseState = INIT;
            }

            // RB released
            else if(eventType == RB_REL){

                _Bool minXValue = x_mov >= x_len;
                _Bool slopeLargerThanOne = abs(y_mov) > abs(x_mov);

                printf("minXVal: %d\n", minXValue);
                printf("slopeLargerThanOne: %d\n", slopeLargerThanOne);

                if(slopeLargerThanOne && minXValue){

                    // Resets x and y movement
                    x_mov = 0;
                    y_mov = 0;

                    // 2nd line was drawn - gesture was successfully complete
                    gestureComplete = true;
                }
                else mouseState = INIT;
            }
            break;

        default:
            break;
    }
}
