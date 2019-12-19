#include "libs/game/game_funcs.h"

int main(void){

    // Load Assets
    GAME_ASSETS assets;

    if (game_load_assets(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // Game Start
    GAME_STATE game_state;

    if (game_run(&assets, &game_state) != EXIT_SUCCESS)
        return EXIT_FAILURE;


    return EXIT_SUCCESS;
}