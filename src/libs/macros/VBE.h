#pragma once

/** @defgroup VBE VBE
 * @{
 *
 * Constants for programming the VESA BIOS EXTENSION (VBE).
 */


/* Access to BIOS via SW interrupt instructions */

#define VBE_SW_VIDEO_CARD       0X10    /**< @brief  SW interrupt instruction for the video card */
#define VBE_SW_PC_CONFIC        0X11    /**< @brief  SW interrupt instruction for the PC configuration */
#define VBE_SW_MEMORY_CONFIG    0x12    /**< @brief  SW interrupt instruction for the memory configuration */
#define VBE_SW_KEYBOARD         0X16    /**< @brief  SW interrupt instruction for the keyboard */


/* BIOS Functions */

#define VBE_SYS_INFO          0x00    /**< @brief  Returns general system level information, including an OEM identification string.
                                                   The function also returns a pointer to the supported VBE and OEM modes.*/
#define VBE_SUP_MODE_INFO     0x01    /**< @brief  Returns additional information about each supported mode. */
#define VBE_CURR_MODE         0x03    /**< @brief  Returns the current VBE mode*/


/* Graphics Modes */

#define VBE_MODE_100H   0x100   /**< @brief  7-bit mode: - ; Resolution:  640x400 ; Colors: 256; */
#define VBE_MODE_101H   0x101   /**< @brief  7-bit mode: - ; Resolution:  640x400 ; Colors: 256; */
#define VBE_MODE_102H   0x102   /**< @brief  7-bit mode: 0x6A ; Resolution: 800x600; Colors: 16; */
#define VBE_MODE_103H   0x103   /**< @brief  7-bit mode: - ; Resolution: 800x600; Colors: 256; */
#define VBE_MODE_104H   0x104   /**< @brief  7-bit mode: - ; Resolution: 1024x768; Colors: 16; */
#define VBE_MODE_105H   0x105   /**< @brief  7-bit mode: - ; Resolution: 1024x768; Colors: 256; */
#define VBE_MODE_106H   0x106   /**< @brief  7-bit mode: - ; Resolution: 1280x1024; Colors: 16; */
#define VBE_MODE_107H   0x107   /**< @brief  7-bit mode: - ; Resolution: 1280x1024; Colors: 256; */
#define VBE_MODE_113H   0x113   /**< @brief  7-bit mode: - ; Resolution: 800x600; Colors: 32K; */
#define VBE_MODE_114H   0x114   /**< @brief  7-bit mode: - ; Resolution: 800x600; Colors: 64K; */
#define VBE_MODE_115H   0x115   /**< @brief  7-bit mode: - ; Resolution: 800x600; Colors: 16.8M; */
#define VBE_MODE_116H   0x116   /**< @brief  7-bit mode: - ; Resolution: 1024x768; Colors: 32K; */
#define VBE_MODE_117H   0x117   /**< @brief  7-bit mode: - ; Resolution: 1024x768; Colors: 64K; */
#define VBE_MODE_118H   0x118   /**< @brief  7-bit mode: - ; Resolution: 1024x768; Colors: 16.8M; */
#define VBE_MODE_119H   0x119   /**< @brief  7-bit mode: - ; Resolution: 1280x1024; Colors: 32K; */
#define VBE_MODE_11AH   0x11a   /**< @brief  7-bit mode: - ; Resolution: 1280x1024; Colors: 64K; */
#define VBE_MODE_11BH   0x11b   /**< @brief  7-bit mode: - ; Resolution: 1280x1024; Colors: 16.8M; */


/* VBE Functions */

#define VBE_FUNC_CONTROLLER_INFO_AX       0x4F00
#define VBE_FUNC_MODE_INFO_AX             0x4F01
#define VBE_FUNC_SET_MODE_AX              0x4F02
#define VBE_FUNC_CURRENT_MODE_AX          0x4F03

#define VBE_FUNC_RETURN_SUCCESS_AX        0x004F
#define VBE_FUNC_RETURN_FAILCALL_AX       0x014F
#define VBE_FUNC_RETURN_HW_NOTSUPP_AX     0x024F
#define VBE_FUNC_RETURN_INVALID_VM_AX     0x034F
#define VBE_FUNC_SUPPORTED_AX             0x4F4F

#define VBE_INT_INTERFACE                 0x10

#define SET_LINEAR_FRAME_BUFFER     BIT(14)
#define SET_VBE_MODE                BIT(15)

