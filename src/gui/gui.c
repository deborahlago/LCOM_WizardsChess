
/* INCLUDES */

#include "gui.h"


/* START WINDOW */

int gui_start_window(game_assets_t* game_assets, game_state_t* game_state){

    /* RENDER VISUALS */

    // BG
    vg_render_sprite(game_assets->start_bg, 0, 0);

    // BTNS
    vg_render_sprite(game_assets->title, 458, 102);        // title
    vg_render_sprite(game_assets->start_btn, 500, 720);    // start button

    // MOUSE
    vg_render_sprite(game_assets->transparent, game_state->mouse_prev_x_pos, game_state->mouse_prev_y_pos);
    vg_render_sprite(game_assets->mouse_cursor, game_state->mouse_curr_x_pos, game_state->mouse_curr_y_pos);

    return EXIT_SUCCESS;
}


/* MAIN MENU */

int gui_main_menu(game_assets_t* game_assets, game_state_t* game_state){

    /* RENDER VISUALS */

    // BG
    vg_render_sprite(game_assets->main_menu_bg, 0, 0);

    // BTNS
    vg_render_sprite(game_assets->singleplayer_btn, 872, 510);      // single player button
    vg_render_sprite(game_assets->multiplayer_btn, 871, 580);       // multiplayer button
    vg_render_sprite(game_assets->exit_btn, 907, 644);              // exit button

    // MOUSE
    vg_render_sprite(game_assets->transparent, game_state->mouse_prev_x_pos, game_state->mouse_prev_y_pos);
    vg_render_sprite(game_assets->mouse_cursor, game_state->mouse_curr_x_pos, game_state->mouse_curr_y_pos);

    return EXIT_SUCCESS;
}


/* IN GAME MENU */

int gui_in_game_menu(game_assets_t* game_assets, game_state_t* game_state){

    /* RENDER VISUALS */

    // BG
    vg_render_sprite(game_assets->in_game_menu_bg, 0, 0);

    // BTNS
    vg_render_sprite(game_assets->restart_game_btn, 435, 310);        // re-start game button
    vg_render_sprite(game_assets->change_game_mode_btn, 367, 470);    // change game mode button
    vg_render_sprite(game_assets->end_game_btn, 490, 628);            // end game button

    // MOUSE
    vg_render_sprite(game_assets->transparent, game_state->mouse_prev_x_pos, game_state->mouse_prev_y_pos);
    vg_render_sprite(game_assets->mouse_cursor, game_state->mouse_curr_x_pos, game_state->mouse_curr_y_pos);

    return EXIT_SUCCESS;
}


/* GAME WINDOW */

int gui_game_window(game_assets_t* game_assets, game_state_t* game_state){

    /* RENDER VISUALS */

    // BG
    vg_render_sprite(game_assets->board_bg, 0, 0);

    // BTNS
    vg_render_sprite(game_assets->in_game_menu_btn, 0, 0);    // in-game menu button

    // BORDERS
    vg_render_sprite(game_assets->left_p_border, 0, 591);     // left player border
    vg_render_sprite(game_assets->right_p_border, 1059, 0);     // right player border

    // LOGOS
    // player 1 house logo
    switch (game_state->p1_house){
        case GRYFFINDOR: {
            vg_render_sprite(game_assets->gryff_logo, 32, 806);
            break;
        }
        case HUFFLEPUFF: {
            vg_render_sprite(game_assets->huffle_logo, 32, 806);
            break;
        }
        case RAVENCLAW: {
            vg_render_sprite(game_assets->raven_logo, 32, 806);
            break;
        }
        case SLYTHERIN: {
            vg_render_sprite(game_assets->slyth_logo, 32, 806);
            break;
        }
        default: {
            break;
        }
    }

    // player 2 house logo
    switch (game_state->p2_house){
        case GRYFFINDOR: {
            vg_render_sprite(game_assets->gryff_logo, 1136, 239);
            break;
        }
        case HUFFLEPUFF: {
            vg_render_sprite(game_assets->huffle_logo, 1136, 239);
            break;
        }
        case RAVENCLAW: {
            vg_render_sprite(game_assets->raven_logo, 1136, 239);
            break;
        }
        case SLYTHERIN: {
            vg_render_sprite(game_assets->slyth_logo, 1136, 239);
            break;
        }
        default: {
            break;
        }
    }


    /* TIMERS */

    /* PIECES */

    // WHITE
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[0], game_state->white_pieces_y_pos[0]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[1], game_state->white_pieces_y_pos[1]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[2], game_state->white_pieces_y_pos[2]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[3], game_state->white_pieces_y_pos[3]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[4], game_state->white_pieces_y_pos[4]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[5], game_state->white_pieces_y_pos[5]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[6], game_state->white_pieces_y_pos[6]);        // pawn
    vg_render_sprite(game_assets->w_pawn, game_state->white_pieces_x_pos[7], game_state->white_pieces_y_pos[7]);        // pawn
    vg_render_sprite(game_assets->w_bishop, game_state->white_pieces_x_pos[8], game_state->white_pieces_y_pos[8]);      // left bishop
    vg_render_sprite(game_assets->w_bishop, game_state->white_pieces_x_pos[9], game_state->white_pieces_y_pos[9]);      // right bishop
    vg_render_sprite(game_assets->w_knight, game_state->white_pieces_x_pos[10], game_state->white_pieces_y_pos[10]);    // left knight
    vg_render_sprite(game_assets->w_knight, game_state->white_pieces_x_pos[11], game_state->white_pieces_y_pos[11]);    // right knight
    vg_render_sprite(game_assets->w_rook, game_state->white_pieces_x_pos[12], game_state->white_pieces_y_pos[12]);      // left rook
    vg_render_sprite(game_assets->w_rook, game_state->white_pieces_x_pos[13], game_state->white_pieces_y_pos[13]);      // right rook
    vg_render_sprite(game_assets->w_queen, game_state->white_pieces_x_pos[14], game_state->white_pieces_y_pos[14]);     // queen
    vg_render_sprite(game_assets->w_king, game_state->white_pieces_x_pos[15], game_state->white_pieces_y_pos[15]);      // king

    // BLACK
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[0], game_state->black_pieces_y_pos[0]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[1], game_state->black_pieces_y_pos[1]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[2], game_state->black_pieces_y_pos[2]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[3], game_state->black_pieces_y_pos[3]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[4], game_state->black_pieces_y_pos[4]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[5], game_state->black_pieces_y_pos[5]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[6], game_state->black_pieces_y_pos[6]);        // pawn
    vg_render_sprite(game_assets->b_pawn, game_state->black_pieces_x_pos[7], game_state->black_pieces_y_pos[7]);        // pawn
    vg_render_sprite(game_assets->b_bishop, game_state->black_pieces_x_pos[8], game_state->black_pieces_y_pos[8]);      // left bishop
    vg_render_sprite(game_assets->b_bishop, game_state->black_pieces_x_pos[9], game_state->black_pieces_y_pos[9]);      // right bishop
    vg_render_sprite(game_assets->b_knight, game_state->black_pieces_x_pos[10], game_state->black_pieces_y_pos[10]);    // left knight
    vg_render_sprite(game_assets->b_knight, game_state->black_pieces_x_pos[11], game_state->black_pieces_y_pos[11]);    // right knight
    vg_render_sprite(game_assets->b_rook, game_state->black_pieces_x_pos[12], game_state->black_pieces_y_pos[12]);      // left rook
    vg_render_sprite(game_assets->b_rook, game_state->black_pieces_x_pos[13], game_state->black_pieces_y_pos[13]);      // right rook
    vg_render_sprite(game_assets->b_queen, game_state->black_pieces_x_pos[14], game_state->black_pieces_y_pos[14]);     // queen
    vg_render_sprite(game_assets->b_king, game_state->black_pieces_x_pos[15], game_state->black_pieces_y_pos[15]);      // king

    // MOUSE
    vg_render_sprite(game_assets->transparent, game_state->mouse_prev_x_pos, game_state->mouse_prev_y_pos);
    vg_render_sprite(game_assets->mouse_cursor, game_state->mouse_curr_x_pos, game_state->mouse_curr_y_pos);

    return EXIT_SUCCESS;
}


/* GAME MODE SELECTION */

int gui_game_mode_sel_window(game_assets_t* game_assets, game_state_t* game_state){

    /* RENDER VISUALS */

    return EXIT_SUCCESS;
}


/* CHARACTER SELECTION */

int gui_char_sel_window(game_assets_t* game_assets, game_state_t* game_state){

    /* RENDER VISUALS */

    // BG
    vg_render_sprite(game_assets->player_sel_bg, 0, 0);

    // CHARACTERS

    // 1.) Godric
    vg_render_sprite(game_assets->godric_img, 0, 63);           // character sprite
    vg_render_sprite(game_assets->godric_title, 349, 143);      // character name

    // 2.) Helga
    vg_render_sprite(game_assets->helga_img, 0, 574);           // character sprite
    vg_render_sprite(game_assets->helga_title, 349, 821);       // character name

    // 3.) Rowena
    vg_render_sprite(game_assets->rowena_img, 960, 574);        // character sprite
    vg_render_sprite(game_assets->rowena_title, 753, 821);      // character name

    // 4.) Salazar
    vg_render_sprite(game_assets->salazar_img, 960, 63);        // character sprite
    vg_render_sprite(game_assets->salazar_title, 753, 143);     // character name

    // MOUSE
    vg_render_sprite(game_assets->transparent, game_state->mouse_prev_x_pos, game_state->mouse_prev_y_pos);
    vg_render_sprite(game_assets->mouse_cursor, game_state->mouse_curr_x_pos, game_state->mouse_curr_y_pos);

    return EXIT_SUCCESS;
}


