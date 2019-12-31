
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
            vg_render_sprite(game_assets->gryff_logo, 32, 806);
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
            vg_render_sprite(game_assets->slyth_logo, 1136, 239);
            break;
        }
    }


    /* TIMERS */



    /* PIECES */

    // --- WHITE
    if (!game_state->w_pawn_1.captured){
        // vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_1.prev_x_pos, game_state->w_pawn_1.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_1.x_pos, game_state->w_pawn_1.y_pos);                  // pawn 1
    }
    /*
    if (!game_state->w_pawn_2.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_2.prev_x_pos, game_state->w_pawn_2.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_2.x_pos, game_state->w_pawn_2.y_pos);                  // pawn 2
    }
    if (!game_state->w_pawn_3.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_3.prev_x_pos, game_state->w_pawn_3.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_3.x_pos, game_state->w_pawn_3.y_pos);                  // pawn 3
    }
    if (!game_state->w_pawn_4.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_4.prev_x_pos, game_state->w_pawn_4.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_4.x_pos, game_state->w_pawn_4.y_pos);                  // pawn 4
    }
    if (!game_state->w_pawn_5.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_5.prev_x_pos, game_state->w_pawn_5.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_5.x_pos, game_state->w_pawn_5.y_pos);                  // pawn 5
    }
    if (!game_state->w_pawn_6.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_6.prev_x_pos, game_state->w_pawn_6.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_6.x_pos, game_state->w_pawn_6.y_pos);                  // pawn 6
    }
    if (!game_state->w_pawn_7.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_7.prev_x_pos, game_state->w_pawn_7.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_7.x_pos, game_state->w_pawn_7.y_pos);                  // pawn 7
    }
    if (!game_state->w_pawn_8.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_pawn_8.prev_x_pos, game_state->w_pawn_8.prev_y_pos);
        vg_render_sprite(game_assets->w_pawn, game_state->w_pawn_8.x_pos, game_state->w_pawn_8.y_pos);                  // pawn 8
    }

    if (!game_state->w_bishop_l.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_bishop_l.prev_x_pos, game_state->w_bishop_l.prev_y_pos);
        vg_render_sprite(game_assets->w_bishop, game_state->w_bishop_l.x_pos, game_state->w_bishop_l.y_pos);            // left bishop
    }
    if (!game_state->w_bishop_r.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_bishop_r.prev_x_pos, game_state->w_bishop_r.prev_y_pos);
        vg_render_sprite(game_assets->w_bishop, game_state->w_bishop_r.x_pos, game_state->w_bishop_r.y_pos);            // right bishop
    }

    if (!game_state->w_knight_l.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_knight_l.prev_x_pos, game_state->w_knight_l.prev_y_pos);
        vg_render_sprite(game_assets->w_knight, game_state->w_knight_l.x_pos, game_state->w_knight_l.y_pos);            // left knight
    }
    if (!game_state->w_knight_r.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_knight_r.prev_x_pos, game_state->w_knight_r.prev_y_pos);
        vg_render_sprite(game_assets->w_knight, game_state->w_knight_r.x_pos, game_state->w_knight_r.y_pos);            // right knight
    }

    if (!game_state->w_rook_l.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_rook_l.prev_x_pos, game_state->w_rook_l.prev_y_pos);
        vg_render_sprite(game_assets->w_rook, game_state->w_rook_l.x_pos, game_state->w_rook_l.y_pos);                  // left rook
    }
    if (!game_state->w_rook_r.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_rook_r.prev_x_pos, game_state->w_rook_r.prev_y_pos);
        vg_render_sprite(game_assets->w_rook, game_state->w_rook_r.x_pos, game_state->w_rook_r.y_pos);                  // right rook
    }

    if (!game_state->w_queen.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_queen.prev_x_pos, game_state->w_queen.prev_y_pos);
        vg_render_sprite(game_assets->w_queen, game_state->w_queen.x_pos, game_state->w_queen.y_pos);                   // queen
    }
    if (!game_state->w_king.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->w_king.prev_x_pos, game_state->w_king.prev_y_pos);
        vg_render_sprite(game_assets->w_king, game_state->w_king.x_pos, game_state->w_king.y_pos);                      // king
    }


    // --- BLACK
    if (!game_state->b_pawn_1.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_1.prev_x_pos, game_state->b_pawn_1.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_1.x_pos, game_state->b_pawn_1.y_pos);                  // pawn 1
    }
    if (!game_state->b_pawn_2.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_2.prev_x_pos, game_state->b_pawn_2.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_2.x_pos, game_state->b_pawn_2.y_pos);                  // pawn 2
    }
    if (!game_state->b_pawn_3.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_3.prev_x_pos, game_state->b_pawn_3.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_3.x_pos, game_state->b_pawn_3.y_pos);                  // pawn 3
    }
    if (!game_state->b_pawn_4.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_4.prev_x_pos, game_state->b_pawn_4.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_4.x_pos, game_state->b_pawn_4.y_pos);                  // pawn 4
    }
    if (!game_state->b_pawn_5.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_5.prev_x_pos, game_state->b_pawn_5.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_5.x_pos, game_state->b_pawn_5.y_pos);                  // pawn 5
    }
    if (!game_state->b_pawn_6.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_6.prev_x_pos, game_state->b_pawn_6.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_6.x_pos, game_state->b_pawn_6.y_pos);                  // pawn 6
    }
    if (!game_state->b_pawn_7.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_7.prev_x_pos, game_state->b_pawn_7.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_7.x_pos, game_state->b_pawn_7.y_pos);                  // pawn 7
    }
    if (!game_state->b_pawn_8.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_pawn_8.prev_x_pos, game_state->b_pawn_8.prev_y_pos);
        vg_render_sprite(game_assets->b_pawn, game_state->b_pawn_8.x_pos, game_state->b_pawn_8.y_pos);                  // pawn 8
    }

    if (!game_state->b_bishop_l.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_bishop_l.prev_x_pos, game_state->b_bishop_l.prev_y_pos);
        vg_render_sprite(game_assets->b_bishop, game_state->b_bishop_l.x_pos, game_state->b_bishop_l.y_pos);            // left bishop
    }
    if (!game_state->b_bishop_r.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_bishop_r.prev_x_pos, game_state->b_bishop_r.prev_y_pos);
        vg_render_sprite(game_assets->b_bishop, game_state->b_bishop_r.x_pos, game_state->b_bishop_r.y_pos);            // right bishop
    }

    if (!game_state->b_knight_l.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_knight_l.prev_x_pos, game_state->b_knight_l.prev_y_pos);
        vg_render_sprite(game_assets->b_knight, game_state->b_knight_l.x_pos, game_state->b_knight_l.y_pos);            // left knight
    }
    if (!game_state->b_knight_r.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_knight_r.prev_x_pos, game_state->b_knight_r.prev_y_pos);
        vg_render_sprite(game_assets->b_knight, game_state->b_knight_r.x_pos, game_state->b_knight_r.y_pos);            // right knight
    }

    if (!game_state->b_rook_l.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_rook_l.prev_x_pos, game_state->b_rook_l.prev_y_pos);
        vg_render_sprite(game_assets->b_rook, game_state->b_rook_l.x_pos, game_state->b_rook_l.y_pos);                  // left rook
    }
    if (!game_state->b_rook_r.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_rook_r.prev_x_pos, game_state->b_rook_r.prev_y_pos);
        vg_render_sprite(game_assets->b_rook, game_state->b_rook_r.x_pos, game_state->b_rook_r.y_pos);                  // right rook
    }

    if (!game_state->b_queen.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_queen.prev_x_pos, game_state->b_queen.prev_y_pos);
        vg_render_sprite(game_assets->b_queen, game_state->b_queen.x_pos, game_state->b_queen.y_pos);                   // queen
    }
    if (!game_state->b_king.captured){
        vg_render_sprite(game_assets->transp_piece, game_state->b_king.prev_x_pos, game_state->b_king.prev_y_pos);
        vg_render_sprite(game_assets->b_king, game_state->b_king.x_pos, game_state->b_king.y_pos);                      // king
    }
    */

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


