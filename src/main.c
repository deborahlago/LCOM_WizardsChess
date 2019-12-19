#include "libs/modules/game_funcs.h"

int main(void){

    // Load Assets
    GAME_ASSETS assets;

    if (game_load_assets(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // Game Start
    if (game_run(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;


    return EXIT_SUCCESS;
}