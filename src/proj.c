#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <machine/asm.h>

#include "libs/game/game_funcs.h"


int main(int argc, char *argv[]) {
    // sets the language of LCF messages (can be either EN-US or PT-PT)
    lcf_set_language("EN-US");

    // enables to log function invocations that are being "wrapped" by LCF
    // [comment this out if you don't want/need it]
    lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

    // enables to save the output of printf function calls on a file
    // [comment this out if you don't want/need it]
    lcf_log_output("/home/lcom/labs/lab5/output.txt");

    // handles control over to LCF
    // [LCF handles command line arguments and invokes the right function]
    if (lcf_start(argc, argv))
        return 1;

    // LCF clean up tasks
    // [must be the last statement before return]
    lcf_cleanup();

    return 0;
}

int (proj_main_loop)(int argc, char *argv[]) {

    /* Enables I/O operations */
    sys_enable_iop(SELF);


    /* Load Assets */
    struct GAME_ASSETS assets;

    if (game_load_assets(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;


    /* Game Start */
    struct GAME_STATE game;

    game.leave = false;
    game.curr_window = 0;

    uint16_t white_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    uint16_t white_pieces_y[16] = {661, 661, 661, 661, 661, 661, 661, 661, 734, 734, 734, 734, 734, 734, 734, 734};
    uint16_t black_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    uint16_t black_pieces_y[16] = {291, 291, 291, 291, 291, 291, 291, 291, 220, 220, 220, 220, 220, 220, 220, 220};

    for (int i = 0; i < 16; i++){
        game.white_pieces_x_pos[i] = white_pieces_x[i];
        game.white_pieces_y_pos[i] = white_pieces_y[i];
        game.black_pieces_x_pos[i] = black_pieces_x[i];
        game.black_pieces_y_pos[i] = black_pieces_y[i];
    }

    game.mouse_x_pos = 883;
    game.mouse_y_pos = 870;

    
    if (game_run(&assets, &game) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
