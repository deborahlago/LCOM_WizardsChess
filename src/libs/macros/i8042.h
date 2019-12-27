#pragma once


#include <lcom/lcf.h>


/** @defgroup i8042 i8042
 * @{
 *
 * Constants for programming the i8042 kbc.
 */


#define KBC_IRQ              1        /**< @brief IRQ Line responsible for handling the keyboard's interruption requests */
#define KBD_SCAN_DURATION    20000    /**< @brief Time in miliseconds for the scan duration */


/* KBC Registers */

#define KBC_STATUS_REG    0x64    /**< @brief Keyboard controller status register */
#define KBC_CMD_REG       0x64    /**< @brief Keyboard controller command register */
#define KBC_OUT_BUF       0x60    /**< @brief Output buffer register */
#define KBC_IN_BUF        0x60    /**< @brief Input buffer register */


/* Scancodes */

#define KBC_ESC_KEY_MAKECODE              0x01      /**< @brief Makecode of Esc Key */
#define KBC_ESC_KEY_BREAKCODE             0x81      /**< @brief Breakcode of Esc Key */
#define KBC_ENTER_KEY_MAKECODE            0x1C      /**< @brief Makecode of Enter Key */
#define KBC_ENTER_KEY_BREAKCODE           0x9C      /**< @brief Breakcode of Enter Key */
#define KBC_SPACE_KEY_MAKECODE            0x39      /**< @brief Makecode of Space Key */
#define KBC_SPACE_KEY_BREAKCODE           0xB9      /**< @brief Breakcode of Space Key */
#define KBC_UP_KEY_MAKECODE               0x48      /**< @brief Makecode of Up Key */
#define KBC_UP_KEY_BREAKCODE              0xC8      /**< @brief Breakcode of Up Key */
#define KBC_DOWN_KEY_MAKECODE             0x50      /**< @brief Makecode of Down Key */
#define KBC_DOWN_KEY_BREAKCODE            0xD0      /**< @brief Breakcode of Down Key */
#define KBC_LEFT_KEY_MAKECODE             0x4B      /**< @brief Makecode of Left Key */
#define KBC_LEFT_KEY_BREAKCODE            0xCB      /**< @brief Breakcode of Left Key */
#define KBC_RIGHT_KEY_MAKECODE            0x4D      /**< @brief Makecode of Right Key */
#define KBC_RIGHT_KEY_BREAKCODE           0xCD      /**< @brief Breakcode of Right Key */

#define KBC_SCANCODE_TWO_BYTE_CHECK     0xE0      /**< @brief Check for first byte of two byte scancode */
#define KBC_BREAK_CODE_CHECK            BIT(7)    /**< @brief Check for makecode */


/* Status Register */

#define KBC_ST_PARITY_ERR       BIT(7)      /**< @brief Partity error bitmask */
#define KBC_ST_TIMEOUT_ERR      BIT(6)      /**< @brief Timeout error bitmask */
#define KBC_ST_AUX              BIT(5)      /**< @brief Mouse data bitmask */
#define KBC_ST_INH_FLAG         BIT(4)      /**< @brief Inhibit flag bitmask. 0 if keyboard is inhibited */
#define KBC_ST_A2               BIT(3)      /**< @brief A2 input line bitmask. 0 data byte; 1 command byte */
#define KBC_ST_SYS              BIT(2)      /**< @brief System flag bitmask. 0 if system in power-on reset; 1 if system already initialized */
#define KBC_ST_IN_BUF_FULL      BIT(1)      /**< @brief Full input buffer bitmask */
#define KBC_ST_OUT_BUF_FULL     BIT(0)      /**< @brief Full output buffer bitmask */

#define KBC_ST_ERRS             (KBC_ST_PARITY_ERR | KBC_ST_TIMEOUT_ERR | KBC_ST_AUX)    /**< @brief Parity and Timeout errors bitmask */
#define KBC_ST_NO_ERRS          0x00                                                     /**< @brief Keyboard controller status no errors occured bitmask */


/* KBC Commands */

// They should be WRITTEN at address 0x64 and if there are arguments needed,
// they should be WRITTEN at address 0x60
//
// Any Return values should be READ from address 0x60 (OUT_BUF)

// KBC

#define KBC_READ_CMD        0x20     /**< @brief Used to allow Keyboard Controller Command Byte to be read */
#define KBC_WRITE_CMD       0x60     /**< @brief Keyboard-Related KBC Commands */
#define KBC_SELF_TEST_OK    0x55     /**< @brief Symbolizes self test OK */

#define KBC_CMD_CHECK_CONTROLLER         0xAA     /**< @brief Used to check if the kbc is OK or if there's some error */
#define KBC_CMD_CHECK_KBD_INTERFACE      0xAB     /**< @brief Used to check the keyboard's interface */
#define KBC_CMD_ENABLE_KBD_INTERFACE     0xAE     /**< @brief Used to enable the keyboard's interface */
#define KBC_CMD_DISABLE_KBD_INTERFACE    0xAD     /**< @brief Used to disable the keyboard's interface */


// MOUSE

#define KBC_CMD_DISABLE_MOUSE            0xA7    /**< @brief Used to disable the mouse interface */
#define KBC_CMD_ENABLE_MOUSE             0xA8    /**< @brief Used to enable the mouse interface */
#define KBC_CMD_CHECK_MOUSE_INTERFACE    0xA9    /**< @brief Used to allow check mouse interface status. Returns 0, if OK */
#define KBC_CMD_WRITE_BYTE               0xD4    /**< @brief Used to command the KBC to forward its argument to the mouse without any interpretation */

/* KBC Command Byte Format */

#define KBC_CMD_BYTE_DISABLE_MOUSE               BIT(5)     /**< @brief Disables mouse */
#define KBC_CMD_BYTE_DISABLE_KBD_INTERFACE       BIT(4)     /**< @brief Disables keyboard interface */
#define KBC_CMD_BYTE_ENABLE_MOUSE_INTERRUPT      BIT(1)     /**< @brief Enable interrupts on the output buffer from the mouse  */
#define KBC_CMD_BYTE_ENABLE_KBD_INTERRUPT        BIT(0)     /**< @brief Enable interrupts on the output buffer from the keyboard */

