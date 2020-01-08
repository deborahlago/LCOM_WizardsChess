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

    game_assets_t assets;

    while (true){

        sprite_t loading_screen = vg_load_sprite(loadingScreen_BG);

        vg_init(VBE_MODE_11BH);
        vg_render_sprite(loading_screen, 0, 0);
        vg_double_buffering();

        if (game_load_assets(&assets) != EXIT_SUCCESS)
            return EXIT_FAILURE;
        else {
            vg_exit();
            break;
        }
    }


    /* Game Start */

    // initialize game values
    game_state_t game;

    game_data_init(&game);

    // run game
    if (game_run(&assets, &game) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
