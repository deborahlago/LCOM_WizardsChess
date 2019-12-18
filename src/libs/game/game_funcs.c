#include "game_funcs.h"



int game_load_assets(GAME_ASSETS* game_assets){

    if (vg_load_sprites(game_assets, xpm_btns, ARRAY_SIZE(xpm_btns), BTNS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_bgs, ARRAY_SIZE(xpm_bgs), BGS)  != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_pieces, ARRAY_SIZE(xpm_pieces), PIECES) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_borders, ARRAY_SIZE(xpm_borders), BORDERS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_characters, ARRAY_SIZE(xpm_characters), CHARS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_logos, ARRAY_SIZE(xpm_logos), LOGOS) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    if (vg_load_sprites(game_assets, xpm_visual_fx, ARRAY_SIZE(xpm_visual_fx), V_FX) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}


/* GAME LOOP */

int game_run(GAME_ASSETS* game_assets){

}


