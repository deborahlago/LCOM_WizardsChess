#pragma once

/** @defgroup video graphics
 * @{
 *
 * Functions for using the The PC's Video Card in Graphics Mode
 */

#include <stdbool.h>
#include <stdint.h>
#include <machine/int86.h>
#include <sys/mman.h>
#include <math.h>

#include "../../macros/i8042.h"
#include "../../macros/i8254.h"
#include "../../macros/VBE.h"

#include "../timer/timer.h"
#include "../keyboard/keyboard.h"
#include "read_xpm.h"
#include "../../game/game_structures.h"


/* Globals */

static unsigned int H_RES, V_RES, BITS_PER_PIXEL;
static uint8_t *ptrToGpuVAddr;


/* Data Structures */

enum key_press {
    ESC,
    ENTER
};

enum vbe_function {
    LINEAR_FRAME_BUFFER,
    VBE_MODE
};


/* Functions */

/**
 * @brief Initializes the video module in graphics mode.
 *        Uses the VBE INT 0x10 interface to set the desired graphics mode using a linear frame buffer.
 *        Maps VRAM to the process' address space and, if OK initializes static global variables with the
 *        resolution of the screen, and the color depth (i.e the no. of bits per pixel).
 *
 *        HRES VRES MEMORYMODEL BITSPERPIXEL + VRAMPHYSICALADDRESS
 *
 *        1. Initially, you should call function vbe_get_mode_info() provided by the LCF, to get this information.
 *        2. Later, you can implement your own version of this function.
 *
 * @param mode VBE mode to set
 *
 * @return Virtual address VRAM was mapped to. NULL, upon failure.
 */
void* (vg_init)(uint16_t mode);


/**
 * @brief TODO
 *
 * @param key_breakcode breakcode of the pressed keyboard key
 *
 */
void (vg_exit_gfx_on_key_press)(uint8_t key_breakcode);


/**
 * @brief TODO
 *
 * @param x TODO
 * @param y TODO
 * @param color TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (vg_draw_point)(uint16_t x, uint16_t y, uint32_t color);


/**
 * @brief TODO
 *
 * @param x TODO
 * @param y TODO
 * @param len TODO
 * @param color TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (vg_draw_hline)(uint16_t x, uint16_t y, uint16_t len, uint32_t color);


/**
 * @brief TODO
 *
 * @param x TODO
 * @param y TODO
 * @param width TODO
 * @param height TODO
 * @param color TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (vg_draw_rectangle)(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint32_t color);


/**
 * @brief Resets the current frame screen to it's original state
 *
 */
int (vg_reset_frame)();


/**
 * @brief Loads a xpm, converts it into a sprite and stores the sprite on the correct game_assets array
 *
 * @param game_assets structure to contain all the game sprites
 *
 * @param xpm_arr[] array of xpms to be loaded
 *
 * @param arr_size size of the array
 *
 * @param asset_type type of the sprite (i.e. button, background, etc...)
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int vg_load_sprites(GAME_ASSETS* game_assets, xpm_map_t* xpm_arr[], size_t arr_size, ASSET_TYPE asset_type);


/**
 * @brief Renders a sprite on screen off of a xpm file
 *
 * @param xpm TODO
 *
 * @param x TODO
 *
 * @param y TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int vg_render_xpm(xpm_map_t xpm, uint16_t x, uint16_t y);


/**
 * @brief Renders a sprite on screen off of a xpm file
 *
 * @param sp TODO
 *
 * @param x TODO
 *
 * @param y TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int vg_render_sprite(sprite sp, uint16_t x, uint16_t y);



/**
 * @brief Remove a given sprite from screen
 *
 * @param xpm TODO
 *
 * @param x TODO
 *
 * @param y TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
void (vg_rm_xpm)(xpm_map_t xpm, uint16_t x, uint16_t y);


/**
 * @brief Remove a given sprite from screen
 *
 * @param sp TODO
 *
 * @param x TODO
 *
 * @param y TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (vg_rm_sprite)(sprite sp, uint16_t x, uint16_t y);



/**
 * @brief
 *
 * @param xpm TODO
 *
 * @param xi TODO
 *
 * @param xf TODO
 *
 * @param yi TODO
 *
 * @param yf TODO
 *
 * @param speed TODO
 *
 * @param fr_rate TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (vg_keyframe_transition_xpm)(xpm_map_t xpm, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate);


/**
 * @brief
 *
 * @param sp TODO
 *
 * @param xi TODO
 *
 * @param xf TODO
 *
 * @param yi TODO
 *
 * @param yf TODO
 *
 * @param speed TODO
 *
 * @param fr_rate TODO
 *
 * @return Return 0 upon success and non-zero otherwise
 */
int (vg_keyframe_transition)(sprite sp, uint16_t xi, uint16_t yi, uint16_t xf, uint16_t yf, int16_t speed, uint8_t fr_rate);


