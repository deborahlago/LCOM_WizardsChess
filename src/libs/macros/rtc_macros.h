#pragma once

/** @defgroup rtc rtc
 * @{
 *
 * Constants for programming the PC's Real Time Clock.
 */


/* RTC time struct */

typedef struct {
    uint8_t secs;		/**< @brief RTC seconds in binary format */
    uint8_t mins;		/**< @brief RTC minutes in binary format */
    uint8_t hours;	    /**< @brief RTC hours in binary format */
} rtc_time_t;


/* Access to the RTC */

#define RTC_IRQ         8        /**< @brief RTC's IRQ line */
#define READ_FAILURE    -1

#define RTC_ADDR_REG	0x70     /**< @brief Used to write the address of the register.
                                             Must be loaded with the address of the RTC register to be accessed */
#define RTC_DATA_REG	0x71     /**< @brief Used for reading/writing one byte from/to it
                                             Transfers the data to/from the RTC’s register accessed */

#define RTC_REG_A		0x0A
#define RTC_REG_B		0x0B
#define RTC_REG_C		0x0C
#define RTC_REG_D		0x0D


#define RTC_HRS			0x04
#define RTC_MIN			0x02
#define RTC_SEC			0x00
