#pragma once

/** @defgroup 16550D 16550D UART
 * @{
 *
 * Constants for programming the The PC's Serial Port (UART).
 */

#define UART_COM1_IRQ     4
#define UART_COM2_IRQ     3

#define UART_COM1_ADDR    0x3F8
#define UART_COM2_ADDR    0x2F8

#define UART_IH_ENABLE       1
#define UART_INT_ID          2
#define UART_FIFO_CTRL    2
#define UART_LINE_CTRL       3
#define UART_LINE_STATUS     5
#define UART_INT_ORIGIN      0x0E

#define UART_DLAB           0x80
#define UART_DL_LSB         0
#define UART_DL_MSB         1
#define UART_STOP_BITS_2    0x04
#define UART_PARITY_EVEN    0x18
#define UART_WORD_LEN_8     0x03
#define UART_RATE           115200

#define UART_FIFO_INIT     0x07
#define UART_FIFO_READY    0x01
#define UART_TX_READY      0x20
#define UART_RX_READY      0x01


