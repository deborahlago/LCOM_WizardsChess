#pragma once

#include <lcom/lcf.h>

/** @defgroup ps2 ps/2
 * @{
 *
 * Constants for programming the ps/2 protocol.
 */


#define PS2_IRQ    12    /**< @brief IRQ Line responsible for handling the mouses's interruption requests */


/* PS/2 COMMANDS */

#define PS2_CMD_RESET                     0xFF    /**< @brief Mouse Reset */
#define PS2_CMD_RESEND                    0xFE    /**< @brief For serial communications errors */
#define PS2_CMD_SET_DEFAULTS              0xF6    /**< @brief Set default values */
#define PS2_CMD_DISABLE_DATA_REPORTING    0xF5    /**< @brief In stream mode, should be sent before any other command */
#define PS2_CMD_ENABLE_DATA_REPORTING     0xF4    /**< @brief In stream mode only */
#define PS2_CMD_SET_SAMPLING_RATE         0xF3    /**< @brief Sets state sampling rate */
#define PS2_CMD_SET_REMOTE_MODE           0xF0    /**< @brief Send data on request only */
#define PS2_CMD_READ_DATA                 0xEB    /**< @brief Send data packet request */
#define PS2_CMD_SET_STREAM_MODE           0xEA    /**< @brief Send data on events */
#define PS2_CMD_STATUS_REQUEST            0xE9    /**< @brief Get mouse configuration (3 bytes) */
#define PS2_CMD_SET_RESOLUTION            0xE8    /**< @brief TODO */
#define PS2_CMD_SET_ACCEL_MODE            0xE7    /**< @brief Acceleration mode */
#define PS2_CMD_SET_LINEAR_MODE           0xE6    /**< @brief Linear mode */

#define PS2_WRITE_CMD_ERR   -1    /**< @brief Error code for writting PS/2 command */

/* PS/2 ACKNOWLEDGMENT */

#define PS2_ACKOWLEDGED             0xFA   /**< @brief Describes valid byte */
#define PS2_NOT_ACKOWLEDGED         0xFE   /**< @brief Describes invalid byte */
#define PS2_ACKNOWLEDGMENT_ERROR    0xFC   /**< @brief Describes second consecutive invalid byte */


/* PS/2 PACKETS */

#define PS2_PKT_SYNCHED    BIT(3)    /**< @brief Used to check if the first byte of the packet is set */

#define PS2_PKT_MOUSELB    BIT(0)    /**< @brief TODO */
#define PS2_PKT_MOUSERB    BIT(1)    /**< @brief TODO */
#define PS2_PKT_MOUSEMB    BIT(2)    /**< @brief TODO */
#define PS2_PKT_XSIGN      BIT(4)    /**< @brief TODO */
#define PS2_PKT_YSIGN      BIT(5)    /**< @brief TODO */
#define PS2_PKT_XOVF       BIT(6)    /**< @brief TODO */
#define PS2_PKT_YOVF       BIT(7)    /**< @brief TODO */

