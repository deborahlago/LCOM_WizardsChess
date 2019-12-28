#pragma once

#include "../../macros/ps2.h"
#include "../keyboard/keyboard.h"

typedef enum {
    INIT,
    DRAW_1st_LINE,
    PAUSE,
    DRAW_2nd_LINE
} mouse_states;

typedef enum {
    LB_PRE,
    RB_PRE,
    LB_REL,
    RB_REL,
    OTHER,
    MOV
} mouse_ev_type;

struct mouse_event {
    int16_t delta_x, delta_y;
    mouse_states state;
    mouse_ev_type type;
};


/**
 * @brief TODO
 *
 */
struct mouse_event* (mouse_event_handler)(struct packet *pkt);

/**
 * @brief TODO
 *
 */
void mouse_state_machine(struct mouse_event* curr_ev, uint8_t x_len, uint8_t tol);

/**
 * @brief Handles mouse interruptions
 *
 */
void (mouse_ih)();

/**
 * @brief Subscribes and enables Mouse interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (mouse_subscribe_int)(uint8_t *bit_no);


/**
 * @brief Disables and unsubscribes Mouse interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (mouse_unsubscribe_int)();


/**
 * @brief Writes a new mouse command using the KBC controller
 *
 * @param arg Argument to be passed to the command
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (mouse_write_cmd)(uint8_t arg, uint8_t *st_byte);


/**
 * @brief Sets the mouse's default values
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_set_defaults)(uint8_t *st_byte);


/**
 * @brief Resets the mouse
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_reset)(uint8_t *st_byte);


/**
 * @brief TODO
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_resend)(uint8_t *st_byte);


/**
 * @brief TODO
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_st_req)(uint8_t *st_byte);


/**
 * @brief Requests a packet from the mouse (remote mode)
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_request_packet)(uint8_t *st_byte);


/**
 * @brief Enables the mouse's stream mode data reporting
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_enable_data_report)(uint8_t *st_byte);


/**
 * @brief Disables the mouse's stream mode data reporting
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_disable_data_report)(uint8_t *st_byte);


/**
 * @brief Sets the mouse mode to stream mode
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_stream_mode)(uint8_t *st_byte);


/**
 * @brief Sets the Mouse mode to remote mode
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_remote_mode)(uint8_t *st_byte);


/**
 * @brief Activates mouse acceleration mode
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_accel_mode)(uint8_t *st_byte);


/**
 * @brief Activates mouse linear mode
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_linear_mode)(uint8_t *st_byte);


/**
 * @brief TODO
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_resolution)(uint8_t *st_byte);


/**
 * @brief TODO
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns the acknowledgement byte from the mouse or -1 upon failure
 */
int (mouse_sampling_rate)(uint8_t *st_byte);


/**
 * @brief Populates each element of the packet array with the corresponding packet byte
 *
 * @return Returns 0 on success, non zero otherwise;
 */
int (mouse_parse_packet_byte)();


/**
 * @brief Assembles the packet struct
 *
 * @return Returns 0 on success, non zero otherwise
 */
int (mouse_assemble_packet)();


/**
 * @brief Reads a packet byte from the output buffer (remote mode)
 *
 * @param packet_byte Empty address to contain the value of the read packet byte
 *
 * @return Returns 0 on success and non-zero otherwise
 */
int (mouse_read_packet_byte)(uint8_t *packet_byte);


/**
 * @brief Fetches the aknowledgement byte
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Returns 0 on success and non-zero otherwise
 */
int (mouse_fetch_data)(uint8_t *st_byte, int max_tries);
