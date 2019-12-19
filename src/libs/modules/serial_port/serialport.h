#pragma once

#include "../../macros/16550D.h"
#include "../timer/timer.h"

/** @defgroup UART UART
 * @{
 *
 * Functions for using the The PC's Serial Port (UART)
 */


typedef enum {
    NEWTRNM,
    CONNECTED,
    KB,
    MS,
    HP,
    SC,
    C_MSG
} serial_evt_tp;



/**
 * @brief Gets COM1 line control register
 *
 * @return Returns COM1 line control register
 */
int (sp_get_ctrl)(uint32_t *com1_ctrl_reg);

/**
 * @brief Gets COM1 line status register
 *
 * @return Returns COM1 line status register
 */
int (sp_get_status)(uint32_t *com1_st_reg);

/**
 * @brief Writes character to transmitter holding register
 *
 * @param port Address of serial port COM port
 * @param char_data Character to write
 */
int sp_write_th (uint16_t port, uint32_t char_data);

/**
 * @brief Reads character from receiver buffer register
 *
 * @param port Address of serial port COM port
 * @param cdata pointer to where character will be stored
 */
int sp_read_buffer (uint16_t port, uint8_t *cdata);

/**
 * @brief Subscribes to serial port interrupts
 */
int sp_subscribe_int ();

/**
 * @brief Unubscribes to serial port interrupts
 */
int sp_unsubscribe_int();

/**
 * @brief Enables serial port interrupts
 */
void sp_enable_int(uint32_t *char_data);

/**
 * @brief Disables serial port interrupts
 */
void sp_disable_int(uint32_t *char_data);

/**
 * @brief Status of transmitter holding register
 *
 * @returns True if the transmitter holding register is ready, 0 otherwise
 */
_Bool sp_trans_ready(uint16_t port, uint32_t *char_data);

/**
 * @brief Status of receiver buffer register
 *
 * @returns True if the receiver buffer register is ready, 0 otherwise
 */
_Bool sp_data_available(uint16_t port, uint32_t *char_data);

/**
 * @brief Sets serial port bit rate
 *
 * @param port Address of serial port COM port
 * @param rate Bit rate
 */
int sp_set_rate(uint16_t port, uint32_t rate);

/**
 * @brief Prints serial ports line control register
 *
 */
void sp_show_config();

/**
 * @brief Initializes serial port's fifo buffer
 *
 * No parity checking, interrupts on every byte
 *
 * @param port Address of serial port COM port
 */
int sp_fifo_init(uint16_t port);