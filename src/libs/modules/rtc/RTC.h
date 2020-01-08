#pragma once

#include <lcom/lcf.h>
#include <stdint.h>

#include "../../macros/rtc_macros.h"
#include "../timer/timer.h"


/** @defgroup RTC RTC
 * @{
 *
 * Functions for using the PC's Real Time Clock
 */


/**
 * @brief Subscribes to RTC interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int rtc_subscribe_int(uint8_t* bit_no);

/**
 * @brief Unsubscribes to RTC interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int rtc_unsubscribe_int();

/**
 * @brief Enables Updated-ended RTC interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
void rtc_enable_int();

/**
 * @brief Disables Updated-ended RTC interrupts
 *
 * @return Return 0 upon success and non-zero otherwise
 */
void rtc_disable_int();


/**
 * @brief Converts number from BCD to binary
 *
 * @param date BCD number to be converted
 *
 * @returns Returns binary format
 */
uint8_t rtc_bcd_to_bin(uint8_t date);

/**
 * @brief Reads from a RTC register
 *
 * @param port Address of register to be read
 *
 * @returns Returns data from register
 */
uint8_t rtc_read_reg(uint32_t port);

/**
 * @brief Writes to a RTC register
 *
 * @param port Address of register to be written to
 *
 * @param data Data to write on register
 */
void rtc_write_data(uint32_t port, uint32_t data);

/**
 * @brief Reads RTC's hours, minutes and seconds and saves it on the RTC time struct
 *
 * @param timer RTC time struct
 */
void rtc_read_time(rtc_time_t *time);


