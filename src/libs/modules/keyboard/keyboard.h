#pragma once

#include "../../macros/i8042.h"
#include "../../macros/i8254.h"


/* Functions */

/** @defgroup keyboard kbc
 * @{
 *
 * Functions for using the i8042 kbc
 */


/**
 * @brief Increments the util_sys_inb kernel calls counter variable and
 *        reads data from a register using kernel sys_inb function call,
 *        placing that data on a 1 byte memory address reserved for it.
 *
 *
 * @param port register address to be read from
 *
 * @param value memory address where to place the data in
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_sys_inb)(int port, uint8_t *value);


/**
 * @brief Reads and stores the status register content
 *
 * @param st_byte address of memory to store the status data
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_read_st_byte)(uint8_t *st_byte);


/**
 * @brief Reads and stores the data from the output buffer
 *
 * @param byte address of memory from where to store the data to
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_read_out_buf)(uint8_t *out_buf_data);


/**
 * @brief Subscribes and enables Keyboard interrupts
 *
 * @param bit_no address of memory to be initialized with the
 *        bit number to be set in the mask returned upon an interrupt
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_subscribe_int)(uint8_t *bit_no);


/**
 * @brief Unsubscribes Keyboard interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_unsubscribe_int)();


/**
 * @brief Checks if the scancode is composed of two bytes
 *
 * @param scancode_first_byte first byte of the generated scancode
 *
 * @return Returns true or false
 */
_Bool (kbc_two_byte_scancode)(uint8_t scancode_byte);


/**
 * @brief Splits a two byte scancode into sections of a byte each
 *
 * @param two_byte_scancode The generated scancode
 *
 * @return Returns an array containing the scancode bytes as its elements
 */
uint8_t *(kbc_split_bytes)(uint16_t half_word);


/**
 * @brief Checks if scancode is a makecode
 *
 * @param byte The most significant half of the scancode
 *
 * @return Returns true if it's a makecode, false otherwise
 */
_Bool (kbc_is_make_code)(uint8_t byte);


/**
 * @brief Parses the kbc instruction to the desired register
 *
 * @param kbc_reg Register where to parse the instruction to
 *
 * @param kbc_inst Instruction to be parsed
 *
 * @param st_byte Address of memory where to read the value of status byte to
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_parse_inst)(int kbc_reg, uint8_t kbc_inst, uint8_t *st_byte);


/**
 * @brief Transforms the command byte by enabling flags
 *
 * @param cmd_byte Command read from the output buffer
 *
 * @param flags Flag bitmask
 *
 * @return Returns the transformed command byte
 */
uint8_t kbc_cmd_byte_enable_flags(uint8_t cmd_byte, uint8_t flags);


/**
 * @brief Transforms the command byte by disabling flags
 *
 * @param cmd_byte Command read from the output buffer
 *
 * @param flags Flag bitmask
 *
 * @return Returns the transformed command byte
 */
uint8_t kbc_cmd_byte_disable_flags(uint8_t cmd_byte, uint8_t flags);


/**
 * @brief Writes Command to the keyboard or mouse using the kbc controller
 *
 * @param kbc_cmd Command to be written
 *
 * @param st_byte Address of memory to parse the status byte into
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (kbc_write_cmd)(uint8_t kbc_cmd, uint8_t *st_byte);

