
/* INCLUDES */

#include "gui.h"


/* START WINDOW */

int gui_start_window(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[0], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[0], 458, 102);    // title
    vg_render_sprite(game_assets->buttons[1], 883, 870);    // start button

    return EXIT_SUCCESS;
}


/* MAIN MENU */

int gui_main_menu(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[1], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[2], 872, 510);    // multi player button
    vg_render_sprite(game_assets->buttons[3], 871, 580);    // single player button
    vg_render_sprite(game_assets->buttons[4], 907, 644);    // exit button

    /* INTERRUPT LOOPS */

    return EXIT_SUCCESS;
}


/* IN GAME MENU */

int gui_in_game_menu(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[4], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[8], 435, 310);    // re-start game button
    vg_render_sprite(game_assets->buttons[5], 367, 470);    // change game mode button
    vg_render_sprite(game_assets->buttons[6], 490, 628);    // end game button

    return EXIT_SUCCESS;
}


/* GAME WINDOW */

int gui_game_window(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[3], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[7], 0, 0);    // in-game menu button

    // BORDERS
    vg_render_sprite(game_assets->borders[0], 221, 591);    // left player border
    vg_render_sprite(game_assets->borders[1], 1059, 0);     // right player border

    // LOGOS
    vg_render_sprite(game_assets->logos[game_state->p1_house], 32, 806);        // player 1 house logo
    vg_render_sprite(game_assets->logos[game_state->p2_house], 1136, 239);      // player 2 house logo

    //
    // Game Logic To implement
    //

    /* TIMERS */

    /* PIECES */

    // WHITE
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[0], game_state->white_pieces_y_pos[0]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[1], game_state->white_pieces_y_pos[1]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[2], game_state->white_pieces_y_pos[2]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[3], game_state->white_pieces_y_pos[3]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[4], game_state->white_pieces_y_pos[4]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[5], game_state->white_pieces_y_pos[5]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[6], game_state->white_pieces_y_pos[6]);       // pawn
    vg_render_sprite(game_assets->pieces[0], game_state->white_pieces_x_pos[7], game_state->white_pieces_y_pos[7]);       // pawn
    vg_render_sprite(game_assets->pieces[1], game_state->white_pieces_x_pos[8], game_state->white_pieces_y_pos[8]);       // left bishop
    vg_render_sprite(game_assets->pieces[1], game_state->white_pieces_x_pos[9], game_state->white_pieces_y_pos[9]);       // right bishop
    vg_render_sprite(game_assets->pieces[2], game_state->white_pieces_x_pos[10], game_state->white_pieces_y_pos[10]);     // left horse
    vg_render_sprite(game_assets->pieces[2], game_state->white_pieces_x_pos[11], game_state->white_pieces_y_pos[11]);     // right horse
    vg_render_sprite(game_assets->pieces[3], game_state->white_pieces_x_pos[12], game_state->white_pieces_y_pos[12]);     // left rook
    vg_render_sprite(game_assets->pieces[3], game_state->white_pieces_x_pos[13], game_state->white_pieces_y_pos[13]);     // right rook
    vg_render_sprite(game_assets->pieces[4], game_state->white_pieces_x_pos[14], game_state->white_pieces_y_pos[14]);     // queen
    vg_render_sprite(game_assets->pieces[5], game_state->white_pieces_x_pos[15], game_state->white_pieces_y_pos[15]);     // king

    // BLACK
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[0], game_state->black_pieces_y_pos[0]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[1], game_state->black_pieces_y_pos[1]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[2], game_state->black_pieces_y_pos[2]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[3], game_state->black_pieces_y_pos[3]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[4], game_state->black_pieces_y_pos[4]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[5], game_state->black_pieces_y_pos[5]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[6], game_state->black_pieces_y_pos[6]);       // pawn
    vg_render_sprite(game_assets->pieces[6], game_state->black_pieces_x_pos[7], game_state->black_pieces_y_pos[7]);       // pawn
    vg_render_sprite(game_assets->pieces[7], game_state->black_pieces_x_pos[8], game_state->black_pieces_y_pos[8]);       // left bishop
    vg_render_sprite(game_assets->pieces[7], game_state->black_pieces_x_pos[9], game_state->black_pieces_y_pos[9]);       // right bishop
    vg_render_sprite(game_assets->pieces[8], game_state->black_pieces_x_pos[10], game_state->black_pieces_y_pos[10]);     // left horse
    vg_render_sprite(game_assets->pieces[8], game_state->black_pieces_x_pos[11], game_state->black_pieces_y_pos[11]);     // right horse
    vg_render_sprite(game_assets->pieces[9], game_state->black_pieces_x_pos[12], game_state->black_pieces_y_pos[12]);     // left rook
    vg_render_sprite(game_assets->pieces[9], game_state->black_pieces_x_pos[13], game_state->black_pieces_y_pos[13]);     // right rook
    vg_render_sprite(game_assets->pieces[10], game_state->black_pieces_x_pos[14], game_state->black_pieces_y_pos[14]);    // queen
    vg_render_sprite(game_assets->pieces[11], game_state->black_pieces_x_pos[15], game_state->black_pieces_y_pos[15]);    // king

    return EXIT_SUCCESS;
}


/* GAME MODE SELECTION */

int gui_game_mode_sel_window(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    return EXIT_SUCCESS;
}


/* CHARACTER SELECTION */

int gui_char_sel_window(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state){

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[2], 0, 0);

    // CHARACTERS

    // 1.) Godric
    vg_render_sprite(game_assets->characters[0], 0, 63);        // character sprite
    vg_render_sprite(game_assets->characters[1], 349, 143);     // character name

    // 2.) Helga
    vg_render_sprite(game_assets->characters[2], 0, 574);       // character sprite
    vg_render_sprite(game_assets->characters[3], 349, 821);     // character name

    // 3.) Rowena
    vg_render_sprite(game_assets->characters[4], 960, 574);     // character sprite
    vg_render_sprite(game_assets->characters[5], 753, 821);     // character name

    // 4.) Salazar
    vg_render_sprite(game_assets->characters[6], 960, 63);      // character sprite
    vg_render_sprite(game_assets->characters[7], 753, 143);     // character name

    return EXIT_SUCCESS;
}


