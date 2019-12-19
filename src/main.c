#include "libs/game/game_funcs.h"

int main(void)
{

    // Load Assets
    GAME_ASSETS assets;

    if (game_load_assets(&assets) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // Game Start
    GAME_STATE game_state;

    game_state->p1_house = GRYFFINDOR;
    game_state->p2_house = SLYTHERIN;

    game_state->curr_window = 4;

    game_state->white_pieces_x_pos = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    game_state->white_pieces_y_pos = {661, 661, 661, 661, 661, 661, 661, 661, 734, 734, 734, 734, 734, 734, 734, 734};
    game_state->black_pieces_x_pos = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    game_state->black_pieces_y_pos = {291, 291, 291, 291, 291, 291, 291, 291, 220, 220, 220, 220, 220, 220, 220, 220};

    game_state->mouse_x_pos = 0;
    game_state->mouse_y_pos = 0;

    
    if (game_run(&assets, &game_state) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
