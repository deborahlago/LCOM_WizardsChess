#include "game_funcs.h"

/* Globals */

// KBC
extern int kbcHookId;
extern uint32_t kernelCallsCount;
extern uint8_t scancode;

// TIMER 0
extern int timerHookId;
extern uint64_t timerIntCounter;

// PS/2
extern int ps2HookId;
extern uint8_t pktByte;
extern int pktCounter;
extern struct packet pkt;
extern _Bool gestureComplete;


/* Functions */

int game_load_assets(game_assets_t* game_assets){

    /* Mouse */

    game_assets->mouse_cursor = vg_load_sprite(cursor_normal);

    /* Backgrounds */

    game_assets->start_bg = vg_load_sprite(start_BG);
    game_assets->main_menu_bg = vg_load_sprite(mainMenu_BG);
    game_assets->player_sel_bg = vg_load_sprite(selectPlayer_BG);
    game_assets->board_bg = vg_load_sprite(board_BG);
    game_assets->in_game_menu_bg = vg_load_sprite(inGameMenu_BG);


    /* Buttons */

    game_assets->title = vg_load_sprite(title);
    game_assets->title.start_x = 458;
    game_assets->title.start_y = 102;

    game_assets->start_btn = vg_load_sprite(start_button);
    game_assets->start_btn.start_x = 500;
    game_assets->start_btn.start_y = 720;

    game_assets->singleplayer_btn = vg_load_sprite(singleplayer_button);
    game_assets->singleplayer_btn.start_x = 871;
    game_assets->singleplayer_btn.start_y = 580;

    game_assets->multiplayer_btn = vg_load_sprite(multiplayer_button);
    game_assets->multiplayer_btn.start_x = 872;
    game_assets->multiplayer_btn.start_y = 510;

    game_assets->exit_btn = vg_load_sprite(exit_button);
    game_assets->exit_btn.start_x = 907;
    game_assets->exit_btn.start_y = 644;

    game_assets->change_game_mode_btn = vg_load_sprite(changeGameMode_button);
    game_assets->change_game_mode_btn.start_x = 367;
    game_assets->change_game_mode_btn.start_y = 470;

    game_assets->end_game_btn = vg_load_sprite(endGame_button);
    game_assets->end_game_btn.start_x = 490;
    game_assets->end_game_btn.start_y = 628;

    game_assets->in_game_menu_btn = vg_load_sprite(inGameMenu_button);
    game_assets->in_game_menu_btn.start_x = 0;
    game_assets->in_game_menu_btn.start_y = 0;

    game_assets->restart_game_btn = vg_load_sprite(reStartGame_button);
    game_assets->restart_game_btn.start_x = 435;
    game_assets->restart_game_btn.start_y = 310;


    /* Borders */

    game_assets->left_p_border = vg_load_sprite(left_player_board_button);
    game_assets->left_p_border.start_x = 0;
    game_assets->left_p_border.start_y = 591;

    game_assets->right_p_border = vg_load_sprite(right_player_board_button);
    game_assets->right_p_border.start_x = 1059;
    game_assets->right_p_border.start_y = 0;


    /* Logos */

    game_assets->gryff_logo = vg_load_sprite(gryffindor_logo);
    game_assets->huffle_logo = vg_load_sprite(hufflepuff_logo);
    game_assets->raven_logo = vg_load_sprite(ravenclaw_logo);
    game_assets->slyth_logo = vg_load_sprite(slytherin_logo);


    /* Characters */

    game_assets->godric_img = vg_load_sprite(godric_gif_img);
    game_assets->godric_img.start_x = 0;
    game_assets->godric_img.start_y = 63;

    game_assets->godric_title = vg_load_sprite(godric_button);
    game_assets->godric_title.start_x = 349;
    game_assets->godric_title.start_y = 143;

    game_assets->helga_img = vg_load_sprite(helga_gif_img);
    game_assets->helga_img.start_x = 0;
    game_assets->helga_img.start_y = 574;

    game_assets->helga_title = vg_load_sprite(helga_button);
    game_assets->helga_title.start_x = 349;
    game_assets->helga_title.start_y = 821;

    game_assets->rowena_img = vg_load_sprite(rowena_gif_img);
    game_assets->rowena_img.start_x = 960;
    game_assets->rowena_img.start_y = 574;

    game_assets->rowena_title = vg_load_sprite(rowena_button);
    game_assets->rowena_title.start_x = 753;
    game_assets->rowena_title.start_y = 821;

    game_assets->salazar_img = vg_load_sprite(salazar_gif_img);
    game_assets->salazar_img.start_x = 960;
    game_assets->salazar_img.start_y = 63;

    game_assets->salazar_title = vg_load_sprite(salazar_button);
    game_assets->salazar_title.start_x = 753;
    game_assets->salazar_title.start_y = 143;


    /* Pieces */

    game_assets->w_pawn = vg_load_sprite(whitePawn);
    game_assets->w_bishop = vg_load_sprite(whiteBishop);
    game_assets->w_knight = vg_load_sprite(whiteHorse);
    game_assets->w_rook = vg_load_sprite(whiteTower);
    game_assets->w_queen = vg_load_sprite(whiteQueen);
    game_assets->w_king = vg_load_sprite(whiteKing);

    game_assets->b_pawn = vg_load_sprite(blackPawn);
    game_assets->b_bishop = vg_load_sprite(blackBishop);
    game_assets->b_knight = vg_load_sprite(blackHorse);
    game_assets->b_rook = vg_load_sprite(blackTower);
    game_assets->b_queen = vg_load_sprite(blackQueen);
    game_assets->b_king = vg_load_sprite(blackKing);


    /* Numbers */

    game_assets->zero_num = vg_load_sprite(zero_xpm);
    game_assets->one_num = vg_load_sprite(one_xpm);
    game_assets->two_num = vg_load_sprite(two_xpm);
    game_assets->three_num = vg_load_sprite(three_xpm);
    game_assets->four_num = vg_load_sprite(four_xpm);
    game_assets->five_num = vg_load_sprite(five_xpm);
    game_assets->six_num = vg_load_sprite(six_xpm);
    game_assets->seven_num = vg_load_sprite(seven_xpm);
    game_assets->eight_num = vg_load_sprite(eight_xpm);
    game_assets->nine_num = vg_load_sprite(nine_xpm);
    game_assets->colon_num = vg_load_sprite(colon_xpm);


    /* Visual FXs */

    game_assets->transparent = vg_load_sprite(transp);
    game_assets->transp_piece = vg_load_sprite(transpPiece);
    game_assets->hover_main_menu = vg_load_sprite(selectedMenu_visualFx);
    game_assets->hover_in_game_menu = vg_load_sprite(selectInGameMenu_visualFx);

    return EXIT_SUCCESS;
}

void game_update_cursor(game_state_t* game_state){

    game_state->mouse_prev_x_pos = game_state->mouse_curr_x_pos;
    game_state->mouse_prev_y_pos = game_state->mouse_curr_y_pos;

    // Update X pos
    if (game_state->mouse_curr_x_pos + (game_state->curr_mouse_event.delta_x*0.6) > 1280)
        game_state->mouse_curr_x_pos = 1270;
    else if (game_state->mouse_curr_x_pos + (game_state->curr_mouse_event.delta_x*0.6) < 0)
        game_state->mouse_curr_x_pos = 10;
    else
        game_state->mouse_curr_x_pos += game_state->curr_mouse_event.delta_x * 0.6;


    // Update Y pos
    if (game_state->mouse_curr_y_pos - (game_state->curr_mouse_event.delta_y*0.6) > 1014)
        game_state->mouse_curr_y_pos = 1014;
    else if (game_state->mouse_curr_y_pos - (game_state->curr_mouse_event.delta_y*0.6) < 0)
        game_state->mouse_curr_y_pos = 10;
    else
        game_state->mouse_curr_y_pos -= game_state->curr_mouse_event.delta_y * 0.6;
}

struct mouse_event game_mouse_ev_handler(struct packet* pkt, game_state_t* game_state){

    struct mouse_event curr_event;

    // Left button released
    if (game_state->lb && !pkt->lb) curr_event.type = LB_REL;

    // Left button pressed
    else if (!game_state->lb && pkt->lb) curr_event.type = LB_PRE;

    // Right button released
    else if (game_state->rb && !pkt->rb) curr_event.type = RB_REL;

    // Right button pressed
    else if (!game_state->rb && pkt->rb) curr_event.type = RB_PRE;

    // Mouse movement
    else if (pkt->delta_x != 0 || pkt->delta_x != 0){
        curr_event.type = MOV;
        curr_event.delta_x = pkt->delta_x;
        curr_event.delta_y = pkt->delta_y;
    }

        // Middle button pressed
    else if (game_state->mb && !pkt->mb) curr_event.type = OTHER;

        // Middle button released
    else if (!game_state->mb && pkt->mb) curr_event.type = OTHER;

        // Other scenarios
    else curr_event.type = OTHER;


    // Update mouse button values
    game_state->lb = pkt->lb;
    game_state->rb = pkt->rb;
    game_state->mb = pkt->mb;

    return curr_event;
}

_Bool game_elem_clicked(sprite_t game_sprite, game_state_t* game_state){

    if (game_state->mouse_curr_x_pos > game_sprite.start_x  && game_state->mouse_curr_x_pos < (game_sprite.start_x + game_sprite.width)){
        if (game_state->mouse_curr_y_pos > game_sprite.start_y  && game_state->mouse_curr_y_pos < (game_sprite.start_y + game_sprite.height)){
            return true;
        }
    }

    return false;
}

_Bool game_piece_clicked(game_piece_t* game_piece, sprite_t game_sprite, game_state_t* game_state){

    if (game_state->mouse_curr_x_pos > game_piece->start_x  && game_state->mouse_curr_x_pos < (game_piece->start_x + game_sprite.width)){
        if (game_state->mouse_curr_y_pos > game_piece->start_y  && game_state->mouse_curr_y_pos < (game_piece->start_y + game_sprite.height)){
            return true;
        }
    }

    return false;
}

void game_update_pieces_start_pos(game_state_t* game_state){

    /* WHITE PIECES */

    // Pawns
    game_state->w_pawn_1.start_x = game_state->w_pawn_1.x_pos;
    game_state->w_pawn_1.start_y = game_state->w_pawn_1.y_pos;

    game_state->w_pawn_2.start_x = game_state->w_pawn_2.x_pos;
    game_state->w_pawn_2.start_y = game_state->w_pawn_2.y_pos;

    game_state->w_pawn_3.start_x = game_state->w_pawn_3.x_pos;
    game_state->w_pawn_3.start_y = game_state->w_pawn_3.y_pos;

    game_state->w_pawn_4.start_x = game_state->w_pawn_4.x_pos;
    game_state->w_pawn_4.start_y = game_state->w_pawn_4.y_pos;

    game_state->w_pawn_5.start_x = game_state->w_pawn_5.x_pos;
    game_state->w_pawn_5.start_y = game_state->w_pawn_5.y_pos;

    game_state->w_pawn_6.start_x = game_state->w_pawn_6.x_pos;
    game_state->w_pawn_6.start_y = game_state->w_pawn_6.y_pos;

    game_state->w_pawn_7.start_x = game_state->w_pawn_7.x_pos;
    game_state->w_pawn_7.start_y = game_state->w_pawn_7.y_pos;

    game_state->w_pawn_8.start_x = game_state->w_pawn_8.x_pos;
    game_state->w_pawn_8.start_y = game_state->w_pawn_8.y_pos;

    // Bishops
    game_state->w_bishop_l.start_x = game_state->w_bishop_l.x_pos;
    game_state->w_bishop_l.start_y = game_state->w_bishop_l.y_pos;

    game_state->w_bishop_r.start_x = game_state->w_bishop_r.x_pos;
    game_state->w_bishop_r.start_y = game_state->w_bishop_r.y_pos;

    // Knights
    game_state->w_knight_l.start_x = game_state->w_knight_l.x_pos;
    game_state->w_knight_l.start_y = game_state->w_knight_l.y_pos;

    game_state->w_knight_r.start_x = game_state->w_knight_r.x_pos;
    game_state->w_knight_r.start_y = game_state->w_knight_r.y_pos;

    // Rooks
    game_state->w_rook_l.start_x = game_state->w_rook_l.x_pos;
    game_state->w_rook_l.start_y = game_state->w_rook_l.y_pos;

    game_state->w_rook_r.start_x = game_state->w_rook_r.x_pos;
    game_state->w_rook_r.start_y = game_state->w_rook_r.y_pos;

    // King and Queen
    game_state->w_queen.start_x = game_state->w_queen.x_pos;
    game_state->w_queen.start_y = game_state->w_queen.y_pos;

    game_state->w_king.start_x = game_state->w_king.x_pos;
    game_state->w_king.start_y = game_state->w_king.y_pos;


    /* BLACK PIECES */

    // Pawns
    game_state->b_pawn_1.start_x = game_state->b_pawn_1.x_pos;
    game_state->b_pawn_1.start_y = game_state->b_pawn_1.y_pos;

    game_state->b_pawn_2.start_x = game_state->b_pawn_2.x_pos;
    game_state->b_pawn_2.start_y = game_state->b_pawn_2.y_pos;

    game_state->b_pawn_3.start_x = game_state->b_pawn_3.x_pos;
    game_state->b_pawn_3.start_y = game_state->b_pawn_3.y_pos;

    game_state->b_pawn_4.start_x = game_state->b_pawn_4.x_pos;
    game_state->b_pawn_4.start_y = game_state->b_pawn_4.y_pos;

    game_state->b_pawn_5.start_x = game_state->b_pawn_5.x_pos;
    game_state->b_pawn_5.start_y = game_state->b_pawn_5.y_pos;

    game_state->b_pawn_6.start_x = game_state->b_pawn_6.x_pos;
    game_state->b_pawn_6.start_y = game_state->b_pawn_6.y_pos;

    game_state->b_pawn_7.start_x = game_state->b_pawn_7.x_pos;
    game_state->b_pawn_7.start_y = game_state->b_pawn_7.y_pos;

    game_state->b_pawn_8.start_x = game_state->b_pawn_8.x_pos;
    game_state->b_pawn_8.start_y = game_state->b_pawn_8.y_pos;

    // Bishops
    game_state->b_bishop_l.start_x = game_state->b_bishop_l.x_pos;
    game_state->b_bishop_l.start_y = game_state->b_bishop_l.y_pos;

    game_state->b_bishop_r.start_x = game_state->b_bishop_r.x_pos;
    game_state->b_bishop_r.start_y = game_state->b_bishop_r.y_pos;

    // Knights
    game_state->b_knight_l.start_x = game_state->b_knight_l.x_pos;
    game_state->b_knight_l.start_y = game_state->b_knight_l.y_pos;

    game_state->b_knight_r.start_x = game_state->b_knight_r.x_pos;
    game_state->b_knight_r.start_y = game_state->b_knight_r.y_pos;

    // Rooks
    game_state->b_rook_l.start_x = game_state->b_rook_l.x_pos;
    game_state->b_rook_l.start_y = game_state->b_rook_l.y_pos;

    game_state->b_rook_r.start_x = game_state->b_rook_r.x_pos;
    game_state->b_rook_r.start_y = game_state->b_rook_r.y_pos;

    // King and Queen
    game_state->b_queen.start_x = game_state->b_queen.x_pos;
    game_state->b_queen.start_y = game_state->b_queen.y_pos;

    game_state->b_king.start_x = game_state->b_king.x_pos;
    game_state->b_king.start_y = game_state->b_king.y_pos;
}

void game_drag_piece(game_state_t* game_state, game_piece_t* game_piece){

    game_piece->prev_x_pos = game_piece->x_pos;
    game_piece->prev_y_pos = game_piece->y_pos;

    game_piece->x_pos = game_state->mouse_curr_x_pos;
    game_piece->y_pos = game_state->mouse_curr_y_pos;
}

void game_drop_piece(game_state_t* game_state, game_piece_t* game_piece){

    if (true){
        game_piece->x_pos = game_piece->start_x;
        game_piece->y_pos = game_piece->start_y;
    }
}

void game_update_state(game_assets_t* game_assets, game_state_t* game_state){

    switch (game_state->curr_state){
        case START_WINDOW: {

            switch (game_state->curr_event){
                case TIMER: {
                    gui_start_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);
                            break;
                        }
                        case LB_REL: {

                            if (game_elem_clicked(game_assets->start_btn, game_state))
                                game_state->curr_state = MAIN_MENU;

                            break;
                        }
                        default: {
                            game_update_cursor(game_state);
                            break;
                        }
                    }

                }
                case KEYBOARD: {

                    if (game_state->pressed_key == KBC_ENTER_KEY_MAKECODE)
                        game_state->curr_state = MAIN_MENU;

                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case MAIN_MENU: {

            switch (game_state->curr_event){
                case TIMER: {
                    gui_main_menu(game_assets, game_state);
                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);
                            break;
                        }
                        case LB_REL: {

                            // Single player
                            if (game_elem_clicked(game_assets->singleplayer_btn, game_state))
                                game_state->curr_state = CHAR_SELECT;

                            // Multiplayer
                            else if (game_elem_clicked(game_assets->multiplayer_btn, game_state)){
                                game_state->multiplayer = true;
                                game_state->curr_state = CHAR_SELECT;
                            }

                            // Exit
                            else if (game_elem_clicked(game_assets->exit_btn, game_state))
                                game_state->leave = true;

                            break;
                        }
                        default: {
                            game_update_cursor(game_state);
                            break;
                        }
                    }

                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case CHAR_SELECT: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_char_sel_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);
                            break;
                        }
                        case LB_REL: {

                            // Choose Gryffindor
                            if (game_elem_clicked(game_assets->godric_img, game_state)){
                                game_state->p1_house = GRYFFINDOR;
                                game_state->curr_state = PLAY_GAME;
                            }

                            // Choose Hufflepuff
                            else if (game_elem_clicked(game_assets->helga_img, game_state)){
                                game_state->p1_house = HUFFLEPUFF;
                                game_state->curr_state = PLAY_GAME;
                            }

                            // Choose Ravenclaw
                            else if (game_elem_clicked(game_assets->rowena_img, game_state)){
                                game_state->p1_house = RAVENCLAW;
                                game_state->curr_state = PLAY_GAME;
                            }

                            // Choose Slytherin
                            else if (game_elem_clicked(game_assets->salazar_img, game_state)){
                                game_state->p1_house = SLYTHERIN;
                                game_state->curr_state = PLAY_GAME;
                            }

                            break;
                        }
                        default: {
                            game_update_cursor(game_state);
                            break;
                        }
                    }

                    break;
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case GAME_MODE_SELECT: {
            break;
        }
        case PLAY_GAME: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_game_window(game_assets, game_state);
                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);

                            while (game_state->w_pawn_1.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_1);


                            break;
                        }
                        case LB_PRE: {

                            game_update_pieces_start_pos(game_state);

                            /* WHITE PIECES */
                            if (game_piece_clicked(&game_state->w_pawn_1, game_assets->w_pawn, game_state))
                                game_state->w_pawn_1.drag = true;


                            /* BLACK PIECES */

                        }
                        case LB_REL: {

                            /* WHITE PIECES */
                            if (game_state->w_pawn_1.drag == true){
                                game_state->w_pawn_1.drag = false;
                                game_drop_piece(game_state, &game_state->w_pawn_1);
                            }

                            /* BLACK PIECES */


                            // In-game menu
                            if (game_elem_clicked(game_assets->in_game_menu_btn, game_state))
                                game_state->curr_state = IN_GAME_MENU;

                            break;
                        }
                        default: {
                            game_update_cursor(game_state);
                            break;
                        }
                    }
                }
                case KEYBOARD: {
                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case IN_GAME_MENU: {

            switch (game_state->curr_event) {
                case TIMER: {
                    gui_in_game_menu(game_assets, game_state);
                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);
                            break;
                        }
                        case LB_REL: {

                            // Re-start Game
                            if (game_elem_clicked(game_assets->restart_game_btn, game_state))
                                game_state->curr_state = RESTART_GAME;

                            // End Game
                            if (game_elem_clicked(game_assets->end_game_btn, game_state))
                                game_state->curr_state = MAIN_MENU;

                            break;
                        }
                        default: {
                            game_update_cursor(game_state);
                            break;
                        }
                    }
                }
                case KEYBOARD: {
                    if (game_state->pressed_key == KBC_ESC_KEY_BREAKCODE)
                        game_state->curr_state = PLAY_GAME;

                    break;
                }
                case RTC: {
                    break;
                }
                default: {
                    break;
                }
            }

            break;
        }
        case RESTART_GAME: {

            // Reset pieces position
            uint16_t white_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
            uint16_t white_pieces_y[16] = {661, 661, 661, 661, 661, 661, 661, 661, 734, 734, 734, 734, 734, 734, 734, 734};
            uint16_t black_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
            uint16_t black_pieces_y[16] = {291, 291, 291, 291, 291, 291, 291, 291, 220, 220, 220, 220, 220, 220, 220, 220};

            for (int i = 0; i < 16; i++){
                game_state->white_pieces_x_pos[i] = white_pieces_x[i];
                game_state->white_pieces_y_pos[i] = white_pieces_y[i];
                game_state->black_pieces_x_pos[i] = black_pieces_x[i];
                game_state->black_pieces_y_pos[i] = black_pieces_y[i];
            }


            //          ---- WHITE PIECES ----

            // --- white pawns
            game_state->w_pawn_1.captured = false;
            game_state->w_pawn_1.x_pos = game_state->white_pieces_x_pos[0];
            game_state->w_pawn_1.y_pos = game_state->white_pieces_y_pos[0];

            game_state->w_pawn_2.captured = false;
            game_state->w_pawn_2.x_pos = game_state->white_pieces_x_pos[1];
            game_state->w_pawn_2.y_pos = game_state->white_pieces_y_pos[1];

            game_state->w_pawn_3.captured = false;
            game_state->w_pawn_3.x_pos = game_state->white_pieces_x_pos[2];
            game_state->w_pawn_3.y_pos = game_state->white_pieces_y_pos[2];

            game_state->w_pawn_4.captured = false;
            game_state->w_pawn_4.x_pos = game_state->white_pieces_x_pos[3];
            game_state->w_pawn_4.y_pos = game_state->white_pieces_y_pos[3];

            game_state->w_pawn_5.captured = false;
            game_state->w_pawn_5.x_pos = game_state->white_pieces_x_pos[4];
            game_state->w_pawn_5.y_pos = game_state->white_pieces_y_pos[4];

            game_state->w_pawn_6.captured = false;
            game_state->w_pawn_6.x_pos = game_state->white_pieces_x_pos[5];
            game_state->w_pawn_6.y_pos = game_state->white_pieces_y_pos[5];

            game_state->w_pawn_7.captured = false;
            game_state->w_pawn_7.x_pos = game_state->white_pieces_x_pos[6];
            game_state->w_pawn_7.y_pos = game_state->white_pieces_y_pos[6];

            game_state->w_pawn_8.captured = false;
            game_state->w_pawn_8.x_pos = game_state->white_pieces_x_pos[7];
            game_state->w_pawn_8.y_pos = game_state->white_pieces_y_pos[7];

            // --- white bishops
            game_state->w_bishop_l.captured = false;
            game_state->w_bishop_l.x_pos = game_state->white_pieces_x_pos[8];
            game_state->w_bishop_l.y_pos = game_state->white_pieces_y_pos[8];

            game_state->w_bishop_r.captured = false;
            game_state->w_bishop_r.x_pos = game_state->white_pieces_x_pos[9];
            game_state->w_bishop_r.y_pos = game_state->white_pieces_y_pos[9];

            // --- white knights
            game_state->w_knight_l.captured = false;
            game_state->w_knight_l.x_pos = game_state->white_pieces_x_pos[10];
            game_state->w_knight_l.y_pos = game_state->white_pieces_y_pos[10];

            game_state->w_knight_r.captured = false;
            game_state->w_knight_r.x_pos = game_state->white_pieces_x_pos[11];
            game_state->w_knight_r.y_pos = game_state->white_pieces_y_pos[11];

            // --- white rook
            game_state->w_rook_l.captured = false;
            game_state->w_rook_l.x_pos = game_state->white_pieces_x_pos[12];
            game_state->w_rook_l.y_pos = game_state->white_pieces_y_pos[12];

            game_state->w_rook_r.captured = false;
            game_state->w_rook_r.x_pos = game_state->white_pieces_x_pos[13];
            game_state->w_rook_r.y_pos = game_state->white_pieces_y_pos[13];

            // --- white queen
            game_state->w_queen.captured = false;
            game_state->w_queen.x_pos = game_state->white_pieces_x_pos[14];
            game_state->w_queen.y_pos = game_state->white_pieces_y_pos[14];

            // --- white king
            game_state->w_king.captured = false;
            game_state->w_king.x_pos = game_state->white_pieces_x_pos[15];
            game_state->w_king.y_pos = game_state->white_pieces_y_pos[15];


            //            ---- BLACK PIECES ----

            // --- black pawns
            game_state->b_pawn_1.captured = false;
            game_state->b_pawn_1.x_pos = game_state->black_pieces_x_pos[0];
            game_state->b_pawn_1.y_pos = game_state->black_pieces_y_pos[0];

            game_state->b_pawn_2.captured = false;
            game_state->b_pawn_2.x_pos = game_state->black_pieces_x_pos[1];
            game_state->b_pawn_2.y_pos = game_state->black_pieces_y_pos[1];

            game_state->b_pawn_3.captured = false;
            game_state->b_pawn_3.x_pos = game_state->black_pieces_x_pos[2];
            game_state->b_pawn_3.y_pos = game_state->black_pieces_y_pos[2];

            game_state->b_pawn_4.captured = false;
            game_state->b_pawn_4.x_pos = game_state->black_pieces_x_pos[3];
            game_state->b_pawn_4.y_pos = game_state->black_pieces_y_pos[3];

            game_state->b_pawn_5.captured = false;
            game_state->b_pawn_5.x_pos = game_state->black_pieces_x_pos[4];
            game_state->b_pawn_5.y_pos = game_state->black_pieces_y_pos[4];

            game_state->b_pawn_6.captured = false;
            game_state->b_pawn_6.x_pos = game_state->black_pieces_x_pos[5];
            game_state->b_pawn_6.y_pos = game_state->black_pieces_y_pos[5];

            game_state->b_pawn_7.captured = false;
            game_state->b_pawn_7.x_pos = game_state->black_pieces_x_pos[6];
            game_state->b_pawn_7.y_pos = game_state->black_pieces_y_pos[6];

            game_state->b_pawn_8.captured = false;
            game_state->b_pawn_8.x_pos = game_state->black_pieces_x_pos[7];
            game_state->b_pawn_8.y_pos = game_state->black_pieces_y_pos[7];

            // --- black bishops
            game_state->b_bishop_l.captured = false;
            game_state->b_bishop_l.x_pos = game_state->black_pieces_x_pos[8];
            game_state->b_bishop_l.y_pos = game_state->black_pieces_y_pos[8];

            game_state->b_bishop_r.captured = false;
            game_state->b_bishop_r.x_pos = game_state->black_pieces_x_pos[9];
            game_state->b_bishop_r.y_pos = game_state->black_pieces_y_pos[9];

            // --- black knights
            game_state->b_knight_l.captured = false;
            game_state->b_knight_l.x_pos = game_state->black_pieces_x_pos[10];
            game_state->b_knight_l.y_pos = game_state->black_pieces_y_pos[10];

            game_state->b_knight_r.captured = false;
            game_state->b_knight_r.x_pos = game_state->black_pieces_x_pos[11];
            game_state->b_knight_r.y_pos = game_state->black_pieces_y_pos[11];

            // --- black knights
            game_state->b_knight_l.captured = false;
            game_state->b_knight_l.x_pos = game_state->black_pieces_x_pos[10];
            game_state->b_knight_l.y_pos = game_state->black_pieces_y_pos[10];

            game_state->b_knight_r.captured = false;
            game_state->b_knight_r.x_pos = game_state->black_pieces_x_pos[11];
            game_state->b_knight_r.y_pos = game_state->black_pieces_y_pos[11];

            // --- black rooks
            game_state->b_rook_l.captured = false;
            game_state->b_rook_l.x_pos = game_state->black_pieces_x_pos[12];
            game_state->b_rook_l.y_pos = game_state->black_pieces_y_pos[12];

            game_state->b_rook_r.captured = false;
            game_state->b_rook_r.x_pos = game_state->black_pieces_x_pos[13];
            game_state->b_rook_r.y_pos = game_state->black_pieces_y_pos[13];

            // --- black queen
            game_state->b_queen.captured = false;
            game_state->b_queen.x_pos = game_state->black_pieces_x_pos[14];
            game_state->b_queen.y_pos = game_state->black_pieces_y_pos[14];

            // --- black king
            game_state->b_king.captured = false;
            game_state->b_king.x_pos = game_state->black_pieces_x_pos[15];
            game_state->b_king.y_pos = game_state->black_pieces_y_pos[15];

            // ----------------------------------------------------

            game_state->curr_state = PLAY_GAME;

        }
        default: {
            break;
        }
    }
}

int game_run(game_assets_t* game_assets, game_state_t* game_state){

    vg_init(VBE_MODE_11BH);

    uint8_t stByte;

    uint32_t totalFrames = sys_hz() / 30;    // 30fps
    uint16_t frameCounter = 0;

    // timer subscription
    uint8_t timerBitNum = TIMER0_IRQ;
    int timerIrqSet = BIT(timerBitNum);

    _Bool timerIrqSetIsValid = timer_subscribe_int(&timerBitNum) == EXIT_SUCCESS;

    // keyboard subscription
    uint8_t kbcBitNum = KBC_IRQ;
    int kbcIrqSet = BIT(kbcBitNum);

    _Bool kbcIrqSetIsValid = kbc_subscribe_int(&kbcBitNum) == EXIT_SUCCESS;

    // mouse subscription
    uint32_t packetsGenerated = 0;
    uint8_t mouseBitNum = PS2_IRQ;
    int mouseIrqSet = BIT(mouseBitNum);

    _Bool mouseIrqSetIsValid = mouse_subscribe_int(&mouseBitNum) == EXIT_SUCCESS;


    if (mouse_enable_data_report(&stByte) != PS2_WRITE_CMD_ERR){

        if (timerIrqSetIsValid && kbcIrqSetIsValid && mouseIrqSetIsValid){

            int request;
            int ipcStatus;
            message msg;

            uint8_t scancodeArr[2];
            scancodeArr[0] = 0;

            _Bool scancodeHasTwoBytes = false;

            // Interrupt loop
            while (true) {

                request = driver_receive(ANY, &msg, &ipcStatus);
                if (request == EXIT_SUCCESS) {
                    if (is_ipc_notify(ipcStatus)) {
                        if (_ENDPOINT_P(msg.m_source) == HARDWARE) {

                            // KBC interrupt handling

                            if (msg.m_notify.interrupts & kbcIrqSet) {

                                kbc_ih();

                                if (kbc_two_byte_scancode(scancode)) {
                                    scancodeArr[1] = scancode;
                                    scancodeHasTwoBytes = true;
                                    continue;
                                }
                                else scancodeArr[0] = scancode;

                                if (scancodeHasTwoBytes) scancodeHasTwoBytes = false;

                                // UPDATE
                                game_state->curr_event = KEYBOARD;
                                game_state->pressed_key = scancodeArr[0];
                                game_update_state(game_assets, game_state);

                            }


                            // Timer interrupt handling

                            if (msg.m_notify.interrupts & timerIrqSet) {
                                timer_ih();
                                frameCounter++;

                                if (frameCounter == totalFrames) {

                                    timerIntCounter = 0;
                                    frameCounter = 0;

                                    // UPDATE
                                    game_state->curr_event = TIMER;
                                    game_update_state(game_assets, game_state);
                                }
                            }


                            // Mouse interrupt handling

                            if (msg.m_notify.interrupts & mouseIrqSet){
                                
                                mouse_ih();
                                mouse_parse_packet_byte();

                                if (pktCounter == 3){
                                    mouse_assemble_packet();
                                    game_state->curr_mouse_event = game_mouse_ev_handler(&pkt, game_state);

                                    pktCounter = 0;
                                    timerIntCounter = 0;
                                    packetsGenerated++;

                                    // UPDATE
                                    game_state->curr_event = MOUSE;
                                    game_update_state(game_assets, game_state);
                                }


                            }
                        }
                    }
                }
                else {
                    printf("driver_receive failed with: %d", request);
                    continue;
                }

                if (game_state->leave) break;

            }

            kbc_unsubscribe_int();
            timer_unsubscribe_int();
            timer_set_frequency(0, sys_hz());

            vg_exit();
        }
        else {
            printf("INVALID_IRQ");
            vg_exit();
            return EXIT_FAILURE;
        }
    }
    else printf("COULD NOT ENABLE MOUSE DATA REPORTING!");

    return EXIT_SUCCESS;

}
