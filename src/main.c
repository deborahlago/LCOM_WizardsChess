#include "libs/game/game_structures.h"
#include "libs/modules/game_funcs.h"

int main(void){

    // Load Assets
    GAME_ASSETS assets;

    if (loadAssets(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // Game Start
    if (runGame(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;


    return EXIT_SUCCESS;
}