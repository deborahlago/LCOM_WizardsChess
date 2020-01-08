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

// RTC
extern int rtcHookId;


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
    game_assets->victory_gryff = vg_load_sprite(victory_gryff_BG);
    game_assets->victory_slyth = vg_load_sprite(victory_slyth_BG);
    game_assets->victory_huff = vg_load_sprite(victory_huff_BG);
    game_assets->victory_raven = vg_load_sprite(victory_raven_BG);


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


    /* Time */

    game_assets->_00_ = vg_load_sprite(_00);
    game_assets->_01_ = vg_load_sprite(_01);
    game_assets->_02_ = vg_load_sprite(_02);
    game_assets->_03_ = vg_load_sprite(_03);
    game_assets->_04_ = vg_load_sprite(_04);
    game_assets->_05_ = vg_load_sprite(_05);
    game_assets->_06_ = vg_load_sprite(_06);
    game_assets->_07_ = vg_load_sprite(_07);
    game_assets->_08_ = vg_load_sprite(_08);
    game_assets->_09_ = vg_load_sprite(_09);

    game_assets->_10_ = vg_load_sprite(_10);
    game_assets->_11_ = vg_load_sprite(_11);
    game_assets->_12_ = vg_load_sprite(_12);
    game_assets->_13_ = vg_load_sprite(_13);
    game_assets->_14_ = vg_load_sprite(_14);
    game_assets->_15_ = vg_load_sprite(_15);
    game_assets->_16_ = vg_load_sprite(_16);
    game_assets->_17_ = vg_load_sprite(_17);
    game_assets->_18_ = vg_load_sprite(_18);
    game_assets->_19_ = vg_load_sprite(_19);

    game_assets->_20_ = vg_load_sprite(_20);
    game_assets->_21_ = vg_load_sprite(_21);
    game_assets->_22_ = vg_load_sprite(_22);
    game_assets->_23_ = vg_load_sprite(_23);
    game_assets->_24_ = vg_load_sprite(_24);
    game_assets->_25_ = vg_load_sprite(_25);
    game_assets->_26_ = vg_load_sprite(_26);
    game_assets->_27_ = vg_load_sprite(_27);
    game_assets->_28_ = vg_load_sprite(_28);
    game_assets->_29_ = vg_load_sprite(_29);

    game_assets->_30_ = vg_load_sprite(_30);
    game_assets->_31_ = vg_load_sprite(_31);
    game_assets->_32_ = vg_load_sprite(_32);
    game_assets->_33_ = vg_load_sprite(_33);
    game_assets->_34_ = vg_load_sprite(_34);
    game_assets->_35_ = vg_load_sprite(_35);
    game_assets->_36_ = vg_load_sprite(_36);
    game_assets->_37_ = vg_load_sprite(_37);
    game_assets->_38_ = vg_load_sprite(_38);
    game_assets->_39_ = vg_load_sprite(_39);

    game_assets->_40_ = vg_load_sprite(_40);
    game_assets->_41_ = vg_load_sprite(_41);
    game_assets->_42_ = vg_load_sprite(_42);
    game_assets->_43_ = vg_load_sprite(_43);
    game_assets->_44_ = vg_load_sprite(_44);
    game_assets->_45_ = vg_load_sprite(_45);
    game_assets->_46_ = vg_load_sprite(_46);
    game_assets->_47_ = vg_load_sprite(_47);
    game_assets->_48_ = vg_load_sprite(_48);
    game_assets->_49_ = vg_load_sprite(_49);

    game_assets->_50_ = vg_load_sprite(_50);
    game_assets->_51_ = vg_load_sprite(_51);
    game_assets->_52_ = vg_load_sprite(_52);
    game_assets->_53_ = vg_load_sprite(_53);
    game_assets->_54_ = vg_load_sprite(_54);
    game_assets->_55_ = vg_load_sprite(_55);
    game_assets->_56_ = vg_load_sprite(_56);
    game_assets->_57_ = vg_load_sprite(_57);
    game_assets->_58_ = vg_load_sprite(_58);
    game_assets->_59_ = vg_load_sprite(_59);


    /* Visual FXs */

    game_assets->transparent = vg_load_sprite(transp);
    game_assets->transp_piece = vg_load_sprite(transpPiece);
    game_assets->hover_main_menu = vg_load_sprite(selectedMenu_visualFx);
    game_assets->hover_in_game_menu = vg_load_sprite(selectInGameMenu_visualFx);

    return EXIT_SUCCESS;
}


void game_data_init(game_state_t* game){
    // general game data
    game->leave = false;
    game->multiplayer = false;
    game->move_made = false;

    game->play_time = 30;

    game->curr_state = START_WINDOW;

    // mouse data
    game->mouse_curr_x_pos = 500;
    game->mouse_curr_y_pos = 500;

    game->curr_mouse_event.type = MOV;

    game->lb = false;
    game->rb = false;
    game->mb = false;

    // player data
    game->p1_timer_int_count = 0;
    game->p2_timer_int_count = 0;

    game->p1_choose_char = true;
    game->p2_choose_char = true;

    game->p1_turn = true;
    game->p2_turn = false;

    game->p1_victory = false;
    game->p2_victory = false;

    // timers
    game->p1_ten_secs_counter = 0;
    game->p1_sec_loop_counter = 4;

    game->p2_ten_secs_counter = 0;
    game->p2_sec_loop_counter = 4;

    game->p1_f_digit_left = 9 - game->play_time / 10;
    game->p1_s_digit_left = 9;
    game->p1_f_digit_right = 9;
    game->p1_s_digit_right = 9;

    game->p2_f_digit_left = 9 - game->play_time / 10;
    game->p2_s_digit_left = 9;
    game->p2_f_digit_right = 9;
    game->p2_s_digit_right = 9;


    // -----------------------------------------------

    // GAME PIECES

    game->last_played_piece = NULL;

    uint16_t white_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    uint16_t white_pieces_y[16] = {661, 661, 661, 661, 661, 661, 661, 661, 734, 734, 734, 734, 734, 734, 734, 734};
    uint16_t black_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    uint16_t black_pieces_y[16] = {291, 291, 291, 291, 291, 291, 291, 291, 220, 220, 220, 220, 220, 220, 220, 220};

    for (int i = 0; i < 16; i++){
        game->white_pieces_x_pos[i] = white_pieces_x[i];
        game->white_pieces_y_pos[i] = white_pieces_y[i];
        game->black_pieces_x_pos[i] = black_pieces_x[i];
        game->black_pieces_y_pos[i] = black_pieces_y[i];
    }

    //          ---- WHITE PIECES ----

    // --- white pawns
    game->w_pawn_1.type = PAWN;
    game->w_pawn_1.alignment = WHITE;
    game->w_pawn_1.curr_cell = &game->board.a2;
    game->w_pawn_1.first_move = true;
    game->w_pawn_1.captured = false;
    game->w_pawn_1.drag = false;
    game->w_pawn_1.prev_x_pos = game->white_pieces_x_pos[0];
    game->w_pawn_1.prev_y_pos = game->white_pieces_y_pos[0];
    game->w_pawn_1.x_pos = game->white_pieces_x_pos[0];
    game->w_pawn_1.y_pos = game->white_pieces_y_pos[0];

    game->w_pawn_2.type = PAWN;
    game->w_pawn_2.alignment = WHITE;
    game->w_pawn_2.first_move = true;
    game->w_pawn_2.curr_cell = &game->board.b2;
    game->w_pawn_2.captured = false;
    game->w_pawn_2.drag = false;
    game->w_pawn_2.prev_x_pos = game->white_pieces_x_pos[1];
    game->w_pawn_2.prev_y_pos = game->white_pieces_y_pos[1];
    game->w_pawn_2.x_pos = game->white_pieces_x_pos[1];
    game->w_pawn_2.y_pos = game->white_pieces_y_pos[1];

    game->w_pawn_3.type = PAWN;
    game->w_pawn_3.alignment = WHITE;
    game->w_pawn_3.first_move = true;
    game->w_pawn_3.curr_cell = &game->board.c2;
    game->w_pawn_3.captured = false;
    game->w_pawn_3.drag = false;
    game->w_pawn_3.prev_x_pos = game->white_pieces_x_pos[2];
    game->w_pawn_3.prev_y_pos = game->white_pieces_y_pos[2];
    game->w_pawn_3.x_pos = game->white_pieces_x_pos[2];
    game->w_pawn_3.y_pos = game->white_pieces_y_pos[2];

    game->w_pawn_4.type = PAWN;
    game->w_pawn_3.alignment = WHITE;
    game->w_pawn_4.first_move = true;
    game->w_pawn_4.curr_cell = &game->board.d2;
    game->w_pawn_4.captured = false;
    game->w_pawn_4.drag = false;
    game->w_pawn_4.prev_x_pos = game->white_pieces_x_pos[3];
    game->w_pawn_4.prev_y_pos = game->white_pieces_y_pos[3];
    game->w_pawn_4.x_pos = game->white_pieces_x_pos[3];
    game->w_pawn_4.y_pos = game->white_pieces_y_pos[3];

    game->w_pawn_5.type = PAWN;
    game->w_pawn_5.alignment = WHITE;
    game->w_pawn_5.first_move = true;
    game->w_pawn_5.curr_cell = &game->board.e2;
    game->w_pawn_5.captured = false;
    game->w_pawn_5.drag = false;
    game->w_pawn_5.prev_x_pos = game->white_pieces_x_pos[4];
    game->w_pawn_5.prev_y_pos = game->white_pieces_y_pos[4];
    game->w_pawn_5.x_pos = game->white_pieces_x_pos[4];
    game->w_pawn_5.y_pos = game->white_pieces_y_pos[4];

    game->w_pawn_6.type = PAWN;
    game->w_pawn_6.alignment = WHITE;
    game->w_pawn_6.first_move = true;
    game->w_pawn_6.curr_cell = &game->board.f2;
    game->w_pawn_6.captured = false;
    game->w_pawn_6.drag = false;
    game->w_pawn_6.prev_x_pos = game->white_pieces_x_pos[5];
    game->w_pawn_6.prev_y_pos = game->white_pieces_y_pos[5];
    game->w_pawn_6.x_pos = game->white_pieces_x_pos[5];
    game->w_pawn_6.y_pos = game->white_pieces_y_pos[5];

    game->w_pawn_7.type = PAWN;
    game->w_pawn_7.alignment = WHITE;
    game->w_pawn_7.first_move = true;
    game->w_pawn_7.curr_cell = &game->board.g2;
    game->w_pawn_7.captured = false;
    game->w_pawn_7.drag = false;
    game->w_pawn_7.prev_x_pos = game->white_pieces_x_pos[6];
    game->w_pawn_7.prev_y_pos = game->white_pieces_y_pos[6];
    game->w_pawn_7.x_pos = game->white_pieces_x_pos[6];
    game->w_pawn_7.y_pos = game->white_pieces_y_pos[6];

    game->w_pawn_8.type = PAWN;
    game->w_pawn_8.alignment = WHITE;
    game->w_pawn_8.first_move = true;
    game->w_pawn_8.curr_cell = &game->board.h2;
    game->w_pawn_8.captured = false;
    game->w_pawn_8.drag = false;
    game->w_pawn_8.prev_x_pos = game->white_pieces_x_pos[7];
    game->w_pawn_8.prev_y_pos = game->white_pieces_y_pos[7];
    game->w_pawn_8.x_pos = game->white_pieces_x_pos[7];
    game->w_pawn_8.y_pos = game->white_pieces_y_pos[7];

    // --- white bishops
    game->w_bishop_l.type = BISHOP;
    game->w_bishop_l.alignment = WHITE;
    game->w_bishop_l.first_move = true;
    game->w_bishop_l.curr_cell = &game->board.c1;
    game->w_bishop_l.captured = false;
    game->w_bishop_l.drag = false;
    game->w_bishop_l.prev_x_pos = game->white_pieces_x_pos[8];
    game->w_bishop_l.prev_y_pos = game->white_pieces_y_pos[8];
    game->w_bishop_l.x_pos = game->white_pieces_x_pos[8];
    game->w_bishop_l.y_pos = game->white_pieces_y_pos[8];

    game->w_bishop_r.type = BISHOP;
    game->w_bishop_r.alignment = WHITE;
    game->w_bishop_r.first_move = true;
    game->w_bishop_r.curr_cell = &game->board.f1;
    game->w_bishop_r.captured = false;
    game->w_bishop_r.drag = false;
    game->w_bishop_r.prev_x_pos = game->white_pieces_x_pos[9];
    game->w_bishop_r.prev_y_pos = game->white_pieces_y_pos[9];
    game->w_bishop_r.x_pos = game->white_pieces_x_pos[9];
    game->w_bishop_r.y_pos = game->white_pieces_y_pos[9];

    // --- white knights
    game->w_knight_l.type = KNIGHT;
    game->w_knight_l.alignment = WHITE;
    game->w_knight_l.first_move = true;
    game->w_knight_l.curr_cell = &game->board.b1;
    game->w_knight_l.captured = false;
    game->w_knight_l.drag = false;
    game->w_knight_l.prev_x_pos = game->white_pieces_x_pos[10];
    game->w_knight_l.prev_y_pos = game->white_pieces_y_pos[10];
    game->w_knight_l.x_pos = game->white_pieces_x_pos[10];
    game->w_knight_l.y_pos = game->white_pieces_y_pos[10];

    game->w_knight_r.type = KNIGHT;
    game->w_knight_r.alignment = WHITE;
    game->w_knight_r.first_move = true;
    game->w_knight_r.curr_cell = &game->board.g1;
    game->w_knight_r.captured = false;
    game->w_knight_r.drag = false;
    game->w_knight_r.prev_x_pos = game->white_pieces_x_pos[11];
    game->w_knight_r.prev_y_pos = game->white_pieces_y_pos[11];
    game->w_knight_r.x_pos = game->white_pieces_x_pos[11];
    game->w_knight_r.y_pos = game->white_pieces_y_pos[11];

    // --- white rook
    game->w_rook_l.type = ROOK;
    game->w_rook_l.alignment = WHITE;
    game->w_rook_l.first_move = true;
    game->w_rook_l.curr_cell = &game->board.a1;
    game->w_rook_l.captured = false;
    game->w_rook_l.drag = false;
    game->w_rook_l.prev_x_pos = game->white_pieces_x_pos[12];
    game->w_rook_l.prev_y_pos = game->white_pieces_y_pos[12];
    game->w_rook_l.x_pos = game->white_pieces_x_pos[12];
    game->w_rook_l.y_pos = game->white_pieces_y_pos[12];

    game->w_rook_r.type = ROOK;
    game->w_rook_r.alignment = WHITE;
    game->w_rook_r.first_move = true;
    game->w_rook_r.curr_cell = &game->board.h1;
    game->w_rook_r.captured = false;
    game->w_rook_r.drag = false;
    game->w_rook_r.prev_x_pos = game->white_pieces_x_pos[13];
    game->w_rook_r.prev_y_pos = game->white_pieces_y_pos[13];
    game->w_rook_r.x_pos = game->white_pieces_x_pos[13];
    game->w_rook_r.y_pos = game->white_pieces_y_pos[13];

    // --- white queen
    game->w_queen.type = QUEEN;
    game->w_queen.alignment = WHITE;
    game->w_queen.first_move = true;
    game->w_queen.curr_cell = &game->board.d1;
    game->w_queen.captured = false;
    game->w_queen.drag = false;
    game->w_queen.prev_x_pos = game->white_pieces_x_pos[14];
    game->w_queen.prev_y_pos = game->white_pieces_y_pos[14];
    game->w_queen.x_pos = game->white_pieces_x_pos[14];
    game->w_queen.y_pos = game->white_pieces_y_pos[14];

    // --- white king
    game->w_king.type = KING;
    game->w_king.alignment = WHITE;
    game->w_king.first_move = true;
    game->w_king.curr_cell = &game->board.e1;
    game->w_king.captured = false;
    game->w_king.drag = false;
    game->w_king.prev_x_pos = game->white_pieces_x_pos[15];
    game->w_king.prev_y_pos = game->white_pieces_y_pos[15];
    game->w_king.x_pos = game->white_pieces_x_pos[15];
    game->w_king.y_pos = game->white_pieces_y_pos[15];


    //            ---- BLACK PIECES ----

    // --- black pawns
    game->b_pawn_1.type = PAWN;
    game->b_pawn_1.alignment = BLACK;
    game->b_pawn_1.first_move = true;
    game->b_pawn_1.curr_cell = &game->board.h7;
    game->b_pawn_1.captured = false;
    game->b_pawn_1.drag = false;
    game->b_pawn_1.prev_x_pos = game->black_pieces_x_pos[0];
    game->b_pawn_1.prev_y_pos = game->black_pieces_y_pos[0];
    game->b_pawn_1.x_pos = game->black_pieces_x_pos[0];
    game->b_pawn_1.y_pos = game->black_pieces_y_pos[0];

    game->b_pawn_2.type = PAWN;
    game->b_pawn_2.alignment = BLACK;
    game->b_pawn_2.first_move = true;
    game->b_pawn_2.curr_cell = &game->board.g7;
    game->b_pawn_2.captured = false;
    game->b_pawn_2.drag = false;
    game->b_pawn_2.prev_x_pos = game->black_pieces_x_pos[1];
    game->b_pawn_2.prev_y_pos = game->black_pieces_y_pos[1];
    game->b_pawn_2.x_pos = game->black_pieces_x_pos[1];
    game->b_pawn_2.y_pos = game->black_pieces_y_pos[1];

    game->b_pawn_3.type = PAWN;
    game->b_pawn_3.alignment = BLACK;
    game->b_pawn_3.first_move = true;
    game->b_pawn_3.curr_cell = &game->board.f7;
    game->b_pawn_3.captured = false;
    game->b_pawn_3.drag = false;
    game->b_pawn_3.prev_x_pos = game->black_pieces_x_pos[2];
    game->b_pawn_3.prev_y_pos = game->black_pieces_y_pos[2];
    game->b_pawn_3.x_pos = game->black_pieces_x_pos[2];
    game->b_pawn_3.y_pos = game->black_pieces_y_pos[2];

    game->b_pawn_4.type = PAWN;
    game->b_pawn_4.alignment = BLACK;
    game->b_pawn_4.first_move = true;
    game->b_pawn_4.curr_cell = &game->board.e7;
    game->b_pawn_4.captured = false;
    game->b_pawn_4.drag = false;
    game->b_pawn_4.prev_x_pos = game->black_pieces_x_pos[3];
    game->b_pawn_4.prev_y_pos = game->black_pieces_y_pos[3];
    game->b_pawn_4.x_pos = game->black_pieces_x_pos[3];
    game->b_pawn_4.y_pos = game->black_pieces_y_pos[3];

    game->b_pawn_5.type = PAWN;
    game->b_pawn_5.alignment = BLACK;
    game->b_pawn_5.first_move = true;
    game->b_pawn_5.curr_cell = &game->board.d7;
    game->b_pawn_5.captured = false;
    game->b_pawn_5.drag = false;
    game->b_pawn_5.prev_x_pos = game->black_pieces_x_pos[4];
    game->b_pawn_5.prev_y_pos = game->black_pieces_y_pos[4];
    game->b_pawn_5.x_pos = game->black_pieces_x_pos[4];
    game->b_pawn_5.y_pos = game->black_pieces_y_pos[4];

    game->b_pawn_6.type = PAWN;
    game->b_pawn_6.alignment = BLACK;
    game->b_pawn_6.first_move = true;
    game->b_pawn_6.curr_cell = &game->board.c7;
    game->b_pawn_6.captured = false;
    game->b_pawn_6.drag = false;
    game->b_pawn_6.prev_x_pos = game->black_pieces_x_pos[5];
    game->b_pawn_6.prev_y_pos = game->black_pieces_y_pos[5];
    game->b_pawn_6.x_pos = game->black_pieces_x_pos[5];
    game->b_pawn_6.y_pos = game->black_pieces_y_pos[5];

    game->b_pawn_7.type = PAWN;
    game->b_pawn_7.alignment = BLACK;
    game->b_pawn_7.first_move = true;
    game->b_pawn_7.curr_cell = &game->board.b7;
    game->b_pawn_7.captured = false;
    game->b_pawn_7.drag = false;
    game->b_pawn_7.prev_x_pos = game->black_pieces_x_pos[6];
    game->b_pawn_7.prev_y_pos = game->black_pieces_y_pos[6];
    game->b_pawn_7.x_pos = game->black_pieces_x_pos[6];
    game->b_pawn_7.y_pos = game->black_pieces_y_pos[6];

    game->b_pawn_8.type = PAWN;
    game->b_pawn_8.alignment = BLACK;
    game->b_pawn_8.first_move = true;
    game->b_pawn_8.curr_cell = &game->board.a7;
    game->b_pawn_8.captured = false;
    game->b_pawn_8.drag = false;
    game->b_pawn_8.prev_x_pos = game->black_pieces_x_pos[7];
    game->b_pawn_8.prev_y_pos = game->black_pieces_y_pos[7];
    game->b_pawn_8.x_pos = game->black_pieces_x_pos[7];
    game->b_pawn_8.y_pos = game->black_pieces_y_pos[7];

    // --- black bishops
    game->b_bishop_l.type = BISHOP;
    game->b_bishop_l.alignment = BLACK;
    game->b_bishop_l.first_move = true;
    game->b_bishop_l.curr_cell = &game->board.f8;
    game->b_bishop_l.captured = false;
    game->b_bishop_l.drag = false;
    game->b_bishop_l.prev_x_pos = game->black_pieces_x_pos[8];
    game->b_bishop_l.prev_y_pos = game->black_pieces_y_pos[8];
    game->b_bishop_l.x_pos = game->black_pieces_x_pos[8];
    game->b_bishop_l.y_pos = game->black_pieces_y_pos[8];

    game->b_bishop_r.type = BISHOP;
    game->b_bishop_r.alignment = BLACK;
    game->b_bishop_r.first_move = true;
    game->b_bishop_r.curr_cell = &game->board.c8;
    game->b_bishop_r.captured = false;
    game->b_bishop_r.drag = false;
    game->b_bishop_r.prev_x_pos = game->black_pieces_x_pos[9];
    game->b_bishop_r.prev_y_pos = game->black_pieces_y_pos[9];
    game->b_bishop_r.x_pos = game->black_pieces_x_pos[9];
    game->b_bishop_r.y_pos = game->black_pieces_y_pos[9];

    // --- black knights
    game->b_knight_l.type = KNIGHT;
    game->b_knight_l.alignment = BLACK;
    game->b_knight_l.first_move = true;
    game->b_knight_l.curr_cell = &game->board.g8;
    game->b_knight_l.captured = false;
    game->b_knight_l.drag = false;
    game->b_knight_l.prev_x_pos = game->black_pieces_x_pos[10];
    game->b_knight_l.prev_y_pos = game->black_pieces_y_pos[10];
    game->b_knight_l.x_pos = game->black_pieces_x_pos[10];
    game->b_knight_l.y_pos = game->black_pieces_y_pos[10];

    game->b_knight_r.type = KNIGHT;
    game->b_knight_r.alignment = BLACK;
    game->b_knight_r.first_move = true;
    game->b_knight_r.curr_cell = &game->board.b8;
    game->b_knight_r.captured = false;
    game->b_knight_r.drag = false;
    game->b_knight_r.prev_x_pos = game->black_pieces_x_pos[11];
    game->b_knight_r.prev_y_pos = game->black_pieces_y_pos[11];
    game->b_knight_r.x_pos = game->black_pieces_x_pos[11];
    game->b_knight_r.y_pos = game->black_pieces_y_pos[11];

    // --- black rooks
    game->b_rook_l.type = ROOK;
    game->b_rook_l.alignment = BLACK;
    game->b_rook_l.first_move = true;
    game->b_rook_l.curr_cell = &game->board.h8;
    game->b_rook_l.captured = false;
    game->b_rook_l.drag = false;
    game->b_rook_l.prev_x_pos = game->black_pieces_x_pos[12];
    game->b_rook_l.prev_y_pos = game->black_pieces_y_pos[12];
    game->b_rook_l.x_pos = game->black_pieces_x_pos[12];
    game->b_rook_l.y_pos = game->black_pieces_y_pos[12];

    game->b_rook_r.type = ROOK;
    game->b_rook_r.alignment = BLACK;
    game->b_rook_r.first_move = true;
    game->b_rook_r.curr_cell = &game->board.h1;
    game->b_rook_r.captured = false;
    game->b_rook_r.drag = false;
    game->b_rook_r.prev_x_pos = game->black_pieces_x_pos[13];
    game->b_rook_r.prev_y_pos = game->black_pieces_y_pos[13];
    game->b_rook_r.x_pos = game->black_pieces_x_pos[13];
    game->b_rook_r.y_pos = game->black_pieces_y_pos[13];

    // --- black queen
    game->b_queen.type = QUEEN;
    game->b_queen.alignment = BLACK;
    game->b_queen.first_move = true;
    game->b_queen.curr_cell = &game->board.d8;
    game->b_queen.captured = false;
    game->b_queen.drag = false;
    game->b_queen.prev_x_pos = game->black_pieces_x_pos[14];
    game->b_queen.prev_y_pos = game->black_pieces_y_pos[14];
    game->b_queen.x_pos = game->black_pieces_x_pos[14];
    game->b_queen.y_pos = game->black_pieces_y_pos[14];

    // --- black king
    game->b_king.type = KING;
    game->b_king.alignment = BLACK;
    game->b_king.first_move = true;
    game->b_king.curr_cell = &game->board.e8;
    game->b_king.captured = false;
    game->b_king.drag = false;
    game->b_king.prev_x_pos = game->black_pieces_x_pos[15];
    game->b_king.prev_y_pos = game->black_pieces_y_pos[15];
    game->b_king.x_pos = game->black_pieces_x_pos[15];
    game->b_king.y_pos = game->black_pieces_y_pos[15];


    // -----------------------------------------------

    // GAME BOARD

    game->board.a1.curr_piece = &game->w_rook_l;     game->board.b1.curr_piece = &game->w_knight_l;       game->board.c1.curr_piece = &game->w_bishop_l;     game->board.d1.curr_piece = &game->w_queen;      game->board.e1.curr_piece = &game->w_king;       game->board.f1.curr_piece = &game->w_bishop_r;       game->board.g1.curr_piece = &game->w_knight_r;       game->board.h1.curr_piece = &game->w_rook_r;
    game->board.a1.occupied = true;                  game->board.b1.occupied = true;                      game->board.c1.occupied = true;                      game->board.d1.occupied = true;                  game->board.e1.occupied = true;                  game->board.f1.occupied = true;                      game->board.g1.occupied = true;                      game->board.h1.occupied = true;
    game->board.a1.start_x = 349;                    game->board.b1.start_x = 423;                        game->board.c1.start_x = 497;                        game->board.d1.start_x = 571;                    game->board.e1.start_x = 645;                    game->board.f1.start_x = 719;                        game->board.g1.start_x = 793;                        game->board.h1.start_x = 867;
    game->board.a1.start_y = 734;                    game->board.b1.start_y = 734;                        game->board.c1.start_y = 734;                        game->board.d1.start_y = 734;                    game->board.e1.start_y = 734;                    game->board.f1.start_y = 734;                        game->board.g1.start_y = 734;                        game->board.h1.start_y = 734;
    game->board.a1.end_x = 423;                      game->board.b1.end_x = 497;                          game->board.c1.end_x = 571;                          game->board.d1.end_x = 645;                      game->board.e1.end_x = 719;                      game->board.f1.end_x = 793;                          game->board.g1.end_x = 867;                          game->board.h1.end_x = 941;
    game->board.a1.end_y = 806;                      game->board.b1.end_y = 806;                          game->board.c1.end_y = 806;                          game->board.d1.end_y = 806;                      game->board.e1.end_y = 806;                      game->board.f1.end_y = 806;                          game->board.g1.end_y = 806;                          game->board.h1.end_y = 806;

    game->board.a2.curr_piece = &game->w_pawn_1;     game->board.b2.curr_piece = &game->w_pawn_2;         game->board.c2.curr_piece = &game->w_pawn_3;       game->board.d2.curr_piece = &game->w_pawn_4;     game->board.e2.curr_piece = &game->w_pawn_5;     game->board.f2.curr_piece = &game->w_pawn_6;         game->board.g2.curr_piece = &game->w_pawn_7;         game->board.h2.curr_piece = &game->w_pawn_8;
    game->board.a2.occupied = true;                  game->board.b2.occupied = true;                      game->board.c2.occupied = true;                      game->board.d2.occupied = true;                  game->board.e2.occupied = true;                  game->board.f2.occupied = true;                      game->board.g2.occupied = true;                      game->board.h2.occupied = true;
    game->board.a2.start_x = 349;                    game->board.b2.start_x = 423;                        game->board.c2.start_x = 497;                        game->board.d2.start_x = 571;                    game->board.e2.start_x = 645;                    game->board.f2.start_x = 719;                        game->board.g2.start_x = 793;                        game->board.h2.start_x = 867;
    game->board.a2.start_y = 662;                    game->board.b2.start_y = 662;                        game->board.c2.start_y = 662;                        game->board.d2.start_y = 662;                    game->board.e2.start_y = 662;                    game->board.f2.start_y = 662;                        game->board.g2.start_y = 662;                        game->board.h2.start_y = 662;
    game->board.a2.end_x = 423;                      game->board.b2.end_x = 497;                          game->board.c2.end_x = 571;                          game->board.d2.end_x = 645;                      game->board.e2.end_x = 719;                      game->board.f2.end_x = 793;                          game->board.g2.end_x = 867;                          game->board.h2.end_x = 941;
    game->board.a2.end_y = 734;                      game->board.b2.end_y = 734;                          game->board.c2.end_y = 734;                          game->board.d2.end_y = 734;                      game->board.e2.end_y = 734;                      game->board.f2.end_y = 734;                          game->board.g2.end_y = 734;                          game->board.h2.end_y = 734;

    game->board.a3.curr_piece = NULL;                game->board.b3.curr_piece = NULL;                    game->board.c3.curr_piece = NULL;                    game->board.d3.curr_piece = NULL;                game->board.e3.curr_piece = NULL;                game->board.f3.curr_piece = NULL;                    game->board.g3.curr_piece = NULL;                    game->board.h3.curr_piece = NULL;
    game->board.a3.occupied = false;                 game->board.b3.occupied = false;                     game->board.c3.occupied = false;                     game->board.d3.occupied = false;                 game->board.e3.occupied = false;                 game->board.f3.occupied = false;                     game->board.g3.occupied = false;                     game->board.h3.occupied = false;
    game->board.a3.start_x = 349;                    game->board.b3.start_x = 423;                        game->board.c3.start_x = 497;                        game->board.d3.start_x = 571;                    game->board.e3.start_x = 645;                    game->board.f3.start_x = 719;                        game->board.g3.start_x = 793;                        game->board.h3.start_x = 867;
    game->board.a3.start_y = 590;                    game->board.b3.start_y = 590;                        game->board.c3.start_y = 590;                        game->board.d3.start_y = 590;                    game->board.e3.start_y = 590;                    game->board.f3.start_y = 590;                        game->board.g3.start_y = 590;                        game->board.h3.start_y = 590;
    game->board.a3.end_x = 423;                      game->board.b3.end_x = 497;                          game->board.c3.end_x = 571;                          game->board.d3.end_x = 645;                      game->board.e3.end_x = 719;                      game->board.f3.end_x = 793;                          game->board.g3.end_x = 867;                          game->board.h3.end_x = 941;
    game->board.a3.end_y = 662;                      game->board.b3.end_y = 662;                          game->board.c3.end_y = 662;                          game->board.d3.end_y = 662;                      game->board.e3.end_y = 662;                      game->board.f3.end_y = 662;                          game->board.g3.end_y = 662;                          game->board.h3.end_y = 662;

    game->board.a4.curr_piece = NULL;                game->board.b4.curr_piece = NULL;                    game->board.c4.curr_piece = NULL;                    game->board.d4.curr_piece = NULL;                game->board.e4.curr_piece = NULL;                game->board.f4.curr_piece = NULL;                    game->board.g4.curr_piece = NULL;                    game->board.h4.curr_piece = NULL;
    game->board.a4.occupied = false;                 game->board.b4.occupied = false;                     game->board.c4.occupied = false;                     game->board.d4.occupied = false;                 game->board.e4.occupied = false;                 game->board.f4.occupied = false;                     game->board.g4.occupied = false;                     game->board.h4.occupied = false;
    game->board.a4.start_x = 349;                    game->board.b4.start_x = 423;                        game->board.c4.start_x = 497;                        game->board.d4.start_x = 571;                    game->board.e4.start_x = 645;                    game->board.f4.start_x = 719;                        game->board.g4.start_x = 793;                        game->board.h4.start_x = 867;
    game->board.a4.start_y = 518;                    game->board.b4.start_y = 518;                        game->board.c4.start_y = 518;                        game->board.d4.start_y = 518;                    game->board.e4.start_y = 518;                    game->board.f4.start_y = 518;                        game->board.g4.start_y = 518;                        game->board.h4.start_y = 518;
    game->board.a4.end_x = 423;                      game->board.b4.end_x = 497;                          game->board.c4.end_x = 571;                          game->board.d4.end_x = 645;                      game->board.e4.end_x = 719;                      game->board.f4.end_x = 793;                          game->board.g4.end_x = 867;                          game->board.h4.end_x = 941;
    game->board.a4.end_y = 590;                      game->board.b4.end_y = 590;                          game->board.c4.end_y = 590;                          game->board.d4.end_y = 590;                      game->board.e4.end_y = 590;                      game->board.f4.end_y = 590;                          game->board.g4.end_y = 590;                          game->board.h4.end_y = 590;

    game->board.a5.curr_piece = NULL;                game->board.b5.curr_piece = NULL;                    game->board.c5.curr_piece = NULL;                    game->board.d5.curr_piece = NULL;                game->board.e5.curr_piece = NULL;                game->board.f5.curr_piece = NULL;                    game->board.g5.curr_piece = NULL;                    game->board.h5.curr_piece = NULL;
    game->board.a5.occupied = false;                 game->board.b5.occupied = false;                     game->board.c5.occupied = false;                     game->board.d5.occupied = false;                 game->board.e5.occupied = false;                 game->board.f5.occupied = false;                     game->board.g5.occupied = false;                     game->board.h5.occupied = false;
    game->board.a5.start_x = 349;                    game->board.b5.start_x = 423;                        game->board.c5.start_x = 497;                        game->board.d5.start_x = 571;                    game->board.e5.start_x = 645;                    game->board.f5.start_x = 719;                        game->board.g5.start_x = 793;                        game->board.h5.start_x = 867;
    game->board.a5.start_y = 446;                    game->board.b5.start_y = 446;                        game->board.c5.start_y = 446;                        game->board.d5.start_y = 446;                    game->board.e5.start_y = 446;                    game->board.f5.start_y = 446;                        game->board.g5.start_y = 446;                        game->board.h5.start_y = 446;
    game->board.a5.end_x = 423;                      game->board.b5.end_x = 497;                          game->board.c5.end_x = 571;                          game->board.d5.end_x = 645;                      game->board.e5.end_x = 719;                      game->board.f5.end_x = 793;                          game->board.g5.end_x = 867;                          game->board.h5.end_x = 941;
    game->board.a5.end_y = 518;                      game->board.b5.end_y = 518;                          game->board.c5.end_y = 518;                          game->board.d5.end_y = 518;                      game->board.e5.end_y = 518;                      game->board.f5.end_y = 518;                          game->board.g5.end_y = 518;                          game->board.h5.end_y = 518;

    game->board.a6.curr_piece = NULL;                game->board.b6.curr_piece = NULL;                    game->board.c6.curr_piece = NULL;                    game->board.d6.curr_piece = NULL;                game->board.e6.curr_piece = NULL;                game->board.f6.curr_piece = NULL;                    game->board.g6.curr_piece = NULL;                    game->board.h6.curr_piece = NULL;
    game->board.a6.occupied = false;                 game->board.b6.occupied = false;                     game->board.c6.occupied = false;                     game->board.d6.occupied = false;                 game->board.e6.occupied = false;                 game->board.f6.occupied = false;                     game->board.g6.occupied = false;                     game->board.h6.occupied = false;
    game->board.a6.start_x = 349;                    game->board.b6.start_x = 423;                        game->board.c6.start_x = 497;                        game->board.d6.start_x = 571;                    game->board.e6.start_x = 645;                    game->board.f6.start_x = 719;                        game->board.g6.start_x = 793;                        game->board.h6.start_x = 867;
    game->board.a6.start_y = 374;                    game->board.b6.start_x = 374;                        game->board.c6.start_y = 374;                        game->board.d6.start_y = 374;                    game->board.e6.start_y = 374;                    game->board.f6.start_y = 374;                        game->board.g6.start_y = 374;                        game->board.h6.start_y = 374;
    game->board.a6.end_x = 423;                      game->board.b6.end_x = 497;                          game->board.c6.end_x = 571;                          game->board.d6.end_x = 645;                      game->board.e6.end_x = 719;                      game->board.f6.end_x = 793;                          game->board.g6.end_x = 867;                          game->board.h6.end_x = 941;
    game->board.a6.end_y = 446;                      game->board.b6.end_x = 446;                          game->board.c6.end_y = 446;                          game->board.d6.end_y = 446;                      game->board.e6.end_y = 446;                      game->board.f6.end_y = 446;                          game->board.g6.end_y = 446;                          game->board.h6.end_y = 446;

    game->board.a7.curr_piece = &game->b_pawn_8;     game->board.b7.curr_piece = &game->b_pawn_7;         game->board.c7.curr_piece = &game->b_pawn_6;         game->board.d7.curr_piece = &game->b_pawn_5;     game->board.e7.curr_piece = &game->b_pawn_4;     game->board.f7.curr_piece = &game->b_pawn_3;         game->board.g7.curr_piece = &game->b_pawn_2;         game->board.h7.curr_piece = &game->b_pawn_1;
    game->board.a7.occupied = true;                  game->board.b7.occupied = true;                      game->board.c7.occupied = true;                      game->board.d7.occupied = true;                  game->board.e7.occupied = true;                  game->board.f7.occupied = true;                      game->board.g7.occupied = true;                      game->board.h7.occupied = true;
    game->board.a7.start_x = 349;                    game->board.b7.start_x = 423;                        game->board.c7.start_x = 497;                        game->board.d7.start_x = 571;                    game->board.e7.start_x = 645;                    game->board.f7.start_x = 719;                        game->board.g7.start_x = 793;                        game->board.h7.start_x = 867;
    game->board.a7.start_y = 302;                    game->board.b7.start_y = 302;                        game->board.c7.start_y = 302;                        game->board.d7.start_y = 302;                    game->board.e7.start_y = 302;                    game->board.f7.start_y = 302;                        game->board.g7.start_y = 302;                        game->board.h7.start_y = 302;
    game->board.a7.end_x = 423;                      game->board.b7.end_x = 497;                          game->board.c7.end_x = 571;                          game->board.d7.end_x = 645;                      game->board.e7.end_x = 719;                      game->board.f7.end_x = 793;                          game->board.g7.end_x = 867;                          game->board.h7.end_x = 941;
    game->board.a7.end_y = 374;                      game->board.b7.end_y = 374;                          game->board.c7.end_y = 374;                          game->board.d7.end_y = 374;                      game->board.e7.end_y = 374;                      game->board.f7.end_y = 374;                          game->board.g7.end_y = 374;                          game->board.h7.end_y = 374;

    game->board.a8.curr_piece = &game->b_rook_r;     game->board.b8.curr_piece = &game->b_knight_r;       game->board.c8.curr_piece = &game->b_bishop_r;       game->board.d8.curr_piece = &game->b_queen;      game->board.e8.curr_piece = &game->b_king;       game->board.f8.curr_piece = &game->b_bishop_l;       game->board.g8.curr_piece = &game->b_knight_l;       game->board.h8.curr_piece = &game->b_rook_l;
    game->board.a8.occupied = true;                  game->board.b8.occupied = true;                      game->board.c8.occupied = true;                      game->board.d8.occupied = true;                  game->board.e8.occupied = true;                  game->board.f8.occupied = true;                      game->board.g8.occupied = true;                      game->board.h8.occupied = true;
    game->board.a8.start_x = 349;                    game->board.b8.start_x = 423;                        game->board.c8.start_x = 497;                        game->board.d8.start_x = 571;                    game->board.e8.start_x = 645;                    game->board.f8.start_x = 719;                        game->board.g8.start_x = 793;                        game->board.h8.start_x = 867;
    game->board.a8.start_y = 230;                    game->board.b8.start_y = 230;                        game->board.c8.start_y = 230;                        game->board.d8.start_y = 230;                    game->board.e8.start_y = 230;                    game->board.f8.start_y = 230;                        game->board.g8.start_y = 230;                        game->board.h8.start_y = 230;
    game->board.a8.end_x = 423;                      game->board.b8.end_x = 497;                          game->board.c8.end_x = 571;                          game->board.d8.end_x = 645;                      game->board.e8.end_x = 719;                      game->board.f8.end_x = 793;                          game->board.g8.end_x = 867;                          game->board.h8.end_x = 941;
    game->board.a8.end_y = 302;                      game->board.b8.end_y = 302;                          game->board.c8.end_y = 302;                          game->board.d8.end_y = 302;                      game->board.e8.end_y = 302;                      game->board.f8.end_y = 302;                          game->board.g8.end_y = 302;                          game->board.h8.end_y = 302;

    // -----------------------------------------------
}


void game_update_cursor(game_state_t* game_state){

    game_state->mouse_prev_x_pos = game_state->mouse_curr_x_pos;
    game_state->mouse_prev_y_pos = game_state->mouse_curr_y_pos;

    // Update X pos
    if (game_state->mouse_curr_x_pos + (game_state->curr_mouse_event.delta_x) < 1155){
        if (game_state->mouse_curr_x_pos + (game_state->curr_mouse_event.delta_x) > 0){
            game_state->mouse_curr_x_pos += game_state->curr_mouse_event.delta_x * 0.8;
        }
    }

    // Update Y pos
    if (game_state->mouse_curr_y_pos - (game_state->curr_mouse_event.delta_y) < 984){
        if (game_state->mouse_curr_y_pos - (game_state->curr_mouse_event.delta_y) > 0){
            game_state->mouse_curr_y_pos -= game_state->curr_mouse_event.delta_y * 0.8;
        }
    }
}

struct mouse_event game_mouse_ev_handler(struct packet* pkt, game_state_t* game_state){

    struct mouse_event curr_event;

    // Mouse movement
    if (pkt->delta_x != 0 || pkt->delta_x != 0){
        curr_event.type = MOV;
        curr_event.delta_x = pkt->delta_x;
        curr_event.delta_y = pkt->delta_y;
    }

    // Left button released
    else if (game_state->lb && !pkt->lb) curr_event.type = LB_REL;

    // Left button pressed
    else if (!game_state->lb && pkt->lb) curr_event.type = LB_PRE;

    // Right button released
    else if (game_state->rb && !pkt->rb) curr_event.type = RB_REL;

    // Right button pressed
    else if (!game_state->rb && pkt->rb) curr_event.type = RB_PRE;

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

_Bool game_mouse_within_cell(game_state_t* game_state, board_cell_t* board_cell){

    // Check board limits
    if (game_state->mouse_curr_x_pos > BOARD_START_X && game_state->mouse_curr_x_pos < BOARD_END_X){
        if (game_state->mouse_curr_y_pos > BOARD_START_Y && game_state->mouse_curr_y_pos < BOARD_END_Y){

            // Check destination cell limits
            if (game_state->mouse_curr_x_pos > board_cell->start_x && game_state->mouse_curr_x_pos < board_cell->end_x){
                if (game_state->mouse_curr_y_pos > board_cell->start_y && game_state->mouse_curr_y_pos < board_cell->end_y){

                    return true;
                }
            }
        }
    }

    return false;
}

_Bool game_straight_movement_one_cell(game_piece_t* game_piece, board_cell_t* board_cell){

    if (game_piece->first_move) {

        if (game_piece->type == PAWN) {

            if (board_cell->end_x - game_piece->curr_cell->start_x >= 74) {

                if (abs(game_piece->curr_cell->start_y - board_cell->start_y) >= 72 ||
                    abs(game_piece->curr_cell->start_y) - board_cell->start_y == (72 * 2)) {

                    return true;
                }
            }
        }
    }
    else {

        if (board_cell->end_x - game_piece->curr_cell->start_x >= 74){
            if (abs(game_piece->curr_cell->start_y - board_cell->start_y) == 72){

                return true;
            }
        }
    }

    return false;
}

_Bool game_diagonal_movement_one_cell(game_piece_t* game_piece, board_cell_t* board_cell){

    if (abs((int)game_piece->curr_cell->start_x - (int)board_cell->start_x) >= 74){
        if (abs((int)game_piece->curr_cell->start_y - (int)board_cell->start_y) >= 72){

            return true;
        }
    }

    return false;
}

_Bool game_valid_movement(game_state_t* game_state, game_piece_t* game_piece, board_cell_t* new_pos, board_cell_t* board_cell){


    if (game_mouse_within_cell(game_state, board_cell)){

        if (!board_cell->occupied){

            new_pos->start_x = board_cell->start_x;
            new_pos->start_y = board_cell->start_y;

            game_piece->curr_cell->occupied = false;
            board_cell->occupied = true;

            board_cell->curr_piece = game_piece;
            game_piece->curr_cell = board_cell;
            game_state->reverted_cell = board_cell;

            return true;
        }
        else {

            if (game_piece->alignment != board_cell->curr_piece->alignment){

                new_pos->start_x = board_cell->start_x;
                new_pos->start_y = board_cell->start_y;

                game_piece->curr_cell->occupied = false;

                board_cell->curr_piece->captured = true;
                game_state->last_captured_piece = board_cell->curr_piece;

                board_cell->curr_piece = game_piece;
                game_piece->curr_cell = board_cell;
                game_state->reverted_cell = board_cell;

                return true;
            }
        }
    }

    return false;
}

_Bool game_valid_move(game_state_t* game_state, game_piece_t* game_piece, board_cell_t* new_pos){

    /*
    switch (game_piece->type){
        case PAWN: {

            break;
        }
        case BISHOP: {

            break;
        }
        case KNIGHT: {

            break;
        }
        case ROOK: {

            break;
        }
        case QUEEN: {

            break;
        }
        case KING: {

            break;
        }
    }
    */

    /* AAA */

    // A1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a1))
        return true;

    // A2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a2))
        return true;

    // A3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a3))
        return true;

    // A4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a4))
        return true;

    // A5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a5))
        return true;

    // A6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a6))
        return true;

    // A7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a7))
        return true;

    // A8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.a8))
        return true;


    /* BBB */

    // B1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b1))
        return true;

    // B2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b2))
        return true;

    // B3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b3))
        return true;

    // B4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b4))
        return true;

    // B5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b5))
        return true;

    // B6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b6))
        return true;

    // B7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b7))
        return true;

    // B8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.b8))
        return true;


    /* CCC */

    // C1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c1))
        return true;

    // C2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c2))
        return true;

    // C3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c3))
        return true;

    // C4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c4))
        return true;

    // C5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c5))
        return true;

    // C6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c6))
        return true;

    // C7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c7))
        return true;

    // C8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.c8))
        return true;


    /* DDD */

    // D1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d1))
        return true;

    // D2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d2))
        return true;

    // D3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d3))
        return true;

    // D4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d4))
        return true;

    // D5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d5))
        return true;

    // D6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d6))
        return true;

    // D7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d7))
        return true;

    // D8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.d8))
        return true;


    /* EEE */

    // E1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e1))
        return true;

    // E2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e2))
        return true;

    // E3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e3))
        return true;

    // E4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e4))
        return true;

    // E5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e5))
        return true;

    // E6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e6))
        return true;

    // E7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e7))
        return true;

    // E8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.e8))
        return true;


    /* FFF */

    // F1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f1))
        return true;

    // F2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f2))
        return true;

    // F3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f3))
        return true;

    // F4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f4))
        return true;

    // F5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f5))
        return true;

    // F6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f6))
        return true;

    // F7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f7))
        return true;

    // F8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.f8))
        return true;


    /* GGG */

    // G1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g1))
        return true;

    // G2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g2))
        return true;

    // G3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g3))
        return true;

    // G4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g4))
        return true;

    // G5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g5))
        return true;

    // G6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g6))
        return true;

    // G7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g7))
        return true;

    // G8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.g8))
        return true;


    /* HHH */

    // H1
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h1))
        return true;

    // H2
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h2))
        return true;

    // H3
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h3))
        return true;

    // H4
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h4))
        return true;

    // H5
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h5))
        return true;

    // H6
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h6))
        return true;

    // H7
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h7))
        return true;

    // H8
    if (game_valid_movement(game_state, game_piece, new_pos, &game_state->board.h8))
        return true;

    return false;
}

void game_drag_piece(game_state_t* game_state, game_piece_t* game_piece){

    game_piece->prev_x_pos = game_piece->x_pos;
    game_piece->prev_y_pos = game_piece->y_pos;

    game_piece->x_pos = game_state->mouse_curr_x_pos;
    game_piece->y_pos = game_state->mouse_curr_y_pos;
}

void game_drop_piece(game_state_t* game_state, game_piece_t* game_piece){

    board_cell_t new_pos;

    if (game_valid_move(game_state, game_piece, &new_pos)){

        game_piece->x_pos = new_pos.start_x;
        game_piece->y_pos = new_pos.start_y;

        game_state->move_made = true;

        if (game_piece->first_move)
            game_piece->first_move = false;

        game_state->last_played_piece = game_piece;

        if (game_state->w_king.captured){
            game_state->p2_victory = true;
            game_state->curr_state = VICTORY;
        }

        else if (game_state->b_king.captured){
            game_state->p1_victory = true;
            game_state->curr_state = VICTORY;
        }

    }
    else {
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

                    game_state->pressed_key = 0;

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

                            // Multi player
                            if (game_elem_clicked(game_assets->singleplayer_btn, game_state)){
                                game_state->multiplayer = true;
                                game_state->curr_state = CHAR_SELECT;
                            }

                            // Single player
                            /*
                            else if (game_elem_clicked(game_assets->multiplayer_btn, game_state))
                                game_state->curr_state = CHAR_SELECT;
                            */

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
                    rtc_read_time(&game_state->curr_time);
                    printf("main_menu h --->  %d\n", game_state->curr_time.hours);
                    printf("main_menu m --->  %d\n", game_state->curr_time.mins);
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
                        case LB_PRE: {

                            if (!game_state->multiplayer){

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
                            }
                            else {

                                if (game_state->p1_choose_char){

                                    // Choose Gryffindor
                                    if (game_elem_clicked(game_assets->godric_img, game_state)){
                                        game_state->p1_house = GRYFFINDOR;
                                        game_state->p1_choose_char = false;
                                        game_state->curr_state = CHAR_SELECT;
                                    }

                                    // Choose Hufflepuff
                                    else if (game_elem_clicked(game_assets->helga_img, game_state)){
                                        game_state->p1_house = HUFFLEPUFF;
                                        game_state->p1_choose_char = false;
                                        game_state->curr_state = CHAR_SELECT;
                                    }

                                    // Choose Ravenclaw
                                    else if (game_elem_clicked(game_assets->rowena_img, game_state)){
                                        game_state->p1_house = RAVENCLAW;
                                        game_state->p1_choose_char = false;
                                        game_state->curr_state = CHAR_SELECT;
                                    }

                                    // Choose Slytherin
                                    else if (game_elem_clicked(game_assets->salazar_img, game_state)){
                                        game_state->p1_house = SLYTHERIN;
                                        game_state->p1_choose_char = false;
                                        game_state->curr_state = CHAR_SELECT;
                                    }
                                }

                                else if (game_state->p2_choose_char){

                                    // Choose Gryffindor
                                    if (game_elem_clicked(game_assets->godric_img, game_state)){
                                        game_state->p2_house = GRYFFINDOR;
                                        game_state->p2_choose_char = false;
                                        game_state->curr_state = PLAY_GAME;
                                    }

                                        // Choose Hufflepuff
                                    else if (game_elem_clicked(game_assets->helga_img, game_state)){
                                        game_state->p2_house = HUFFLEPUFF;
                                        game_state->p2_choose_char = false;
                                        game_state->curr_state = PLAY_GAME;
                                    }

                                        // Choose Ravenclaw
                                    else if (game_elem_clicked(game_assets->rowena_img, game_state)){
                                        game_state->p2_house = RAVENCLAW;
                                        game_state->p2_choose_char = false;
                                        game_state->curr_state = PLAY_GAME;
                                    }

                                        // Choose Slytherin
                                    else if (game_elem_clicked(game_assets->salazar_img, game_state)){
                                        game_state->p2_house = SLYTHERIN;
                                        game_state->p2_choose_char = false;
                                        game_state->curr_state = PLAY_GAME;
                                    }
                                }
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

                    // Update game timers
                    uint32_t secs_elapsed;

                    if (game_state->p1_turn){

                        // Update p1 timer
                        game_state->p1_timer_int_count++;
                        secs_elapsed = game_state->p1_timer_int_count/60;

                        if (game_state->p1_timer_int_count % 30 == 0){
                            game_state->p1_ten_secs_counter++;

                            uint8_t mins_elapsed = ceil(secs_elapsed/60.0);

                            game_state->p1_s_digit_right = game_state->p1_ten_secs_counter - 1;
                            game_state->p1_f_digit_right = game_state->p1_sec_loop_counter;
                            game_state->p1_s_digit_left = 9 - ((game_state->play_time - mins_elapsed) % 10);
                            game_state->p1_f_digit_left = 9 - ((game_state->play_time - mins_elapsed) / 10);

                            if (game_state->p1_ten_secs_counter == 10){
                                game_state->p1_ten_secs_counter = 0;
                                game_state->p1_sec_loop_counter++;

                                if (game_state->p1_sec_loop_counter == 9)
                                    game_state->p1_sec_loop_counter = 4;
                            }
                        }

                        if (secs_elapsed == game_state->play_time*60){
                            if (game_state->p2_timer_int_count/60 < game_state->play_time*60)
                                game_state->p2_victory = true;
                        }
                    }
                    else if (game_state->p2_turn){

                        // Update p2 timer
                        game_state->p2_timer_int_count++;
                        secs_elapsed = game_state->p2_timer_int_count/60;

                        if (game_state->p2_timer_int_count % 30 == 0){
                            game_state->p2_ten_secs_counter++;

                            uint8_t mins_elapsed = ceil(secs_elapsed/60.0);

                            game_state->p2_s_digit_right = game_state->p2_ten_secs_counter - 1;
                            game_state->p2_f_digit_right = game_state->p2_sec_loop_counter;
                            game_state->p2_s_digit_left = 9 - ((game_state->play_time - mins_elapsed) % 10);
                            game_state->p2_f_digit_left = 9 - ((game_state->play_time - mins_elapsed) / 10);

                            if (game_state->p2_ten_secs_counter == 10){
                                game_state->p2_ten_secs_counter = 0;
                                game_state->p2_sec_loop_counter++;

                                if (game_state->p2_sec_loop_counter == 9)
                                    game_state->p2_sec_loop_counter = 4;
                            }
                        }

                        if (secs_elapsed == game_state->play_time){
                            if (game_state->p2_timer_int_count/60 < game_state->play_time*60)
                                game_state->p2_victory = true;
                        }
                    }

                    gui_game_window(game_assets, game_state);

                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);

                            /* WHITE PIECES DRAG */

                            if (game_state->w_pawn_1.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_1);

                            else if (game_state->w_pawn_2.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_2);

                            else if (game_state->w_pawn_3.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_3);

                            else if (game_state->w_pawn_4.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_4);

                            else if (game_state->w_pawn_5.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_5);

                            else if (game_state->w_pawn_6.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_6);

                            else if (game_state->w_pawn_7.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_7);

                            else if (game_state->w_pawn_8.drag)
                                game_drag_piece(game_state, &game_state->w_pawn_8);

                            else if (game_state->w_bishop_l.drag)
                                game_drag_piece(game_state, &game_state->w_bishop_l);

                            else if (game_state->w_bishop_r.drag)
                                game_drag_piece(game_state, &game_state->w_bishop_r);

                            else if (game_state->w_knight_l.drag)
                                game_drag_piece(game_state, &game_state->w_knight_l);

                            else if (game_state->w_knight_r.drag)
                                game_drag_piece(game_state, &game_state->w_knight_r);

                            else if (game_state->w_rook_l.drag)
                                game_drag_piece(game_state, &game_state->w_rook_l);

                            else if (game_state->w_rook_r.drag)
                                game_drag_piece(game_state, &game_state->w_rook_r);

                            else if (game_state->w_queen.drag)
                                game_drag_piece(game_state, &game_state->w_queen);

                            else if (game_state->w_king.drag)
                                game_drag_piece(game_state, &game_state->w_king);

                            else {}


                            /* BLACK PIECES DRAG */

                            if (game_state->b_pawn_1.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_1);

                            else if (game_state->b_pawn_2.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_2);

                            else if (game_state->b_pawn_3.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_3);

                            else if (game_state->b_pawn_4.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_4);

                            else if (game_state->b_pawn_5.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_5);

                            else if (game_state->b_pawn_6.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_6);

                            else if (game_state->b_pawn_7.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_7);

                            else if (game_state->b_pawn_8.drag)
                                game_drag_piece(game_state, &game_state->b_pawn_8);

                            else if (game_state->b_bishop_l.drag)
                                game_drag_piece(game_state, &game_state->b_bishop_l);

                            else if (game_state->b_bishop_r.drag)
                                game_drag_piece(game_state, &game_state->b_bishop_r);

                            else if (game_state->b_knight_l.drag)
                                game_drag_piece(game_state, &game_state->b_knight_l);

                            else if (game_state->b_knight_r.drag)
                                game_drag_piece(game_state, &game_state->b_knight_r);

                            else if (game_state->b_rook_l.drag)
                                game_drag_piece(game_state, &game_state->b_rook_l);

                            else if (game_state->b_rook_r.drag)
                                game_drag_piece(game_state, &game_state->b_rook_r);

                            else if (game_state->b_queen.drag)
                                game_drag_piece(game_state, &game_state->b_queen);

                            else if (game_state->b_king.drag)
                                game_drag_piece(game_state, &game_state->b_king);

                            else {}

                            break;
                        }
                        case LB_PRE: {

                            game_update_pieces_start_pos(game_state);

                            if (!game_state->move_made){

                                if (game_state->p1_turn){

                                    /* WHITE PIECES CLICK */

                                    if (game_piece_clicked(&game_state->w_pawn_1, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_1.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_2, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_2.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_3, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_3.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_4, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_4.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_5, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_5.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_6, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_6.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_7, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_7.drag = true;

                                    else if (game_piece_clicked(&game_state->w_pawn_8, game_assets->w_pawn, game_state))
                                        game_state->w_pawn_8.drag = true;

                                    else if (game_piece_clicked(&game_state->w_bishop_l, game_assets->w_bishop, game_state))
                                        game_state->w_bishop_l.drag = true;

                                    else if (game_piece_clicked(&game_state->w_bishop_r, game_assets->w_bishop, game_state))
                                        game_state->w_bishop_r.drag = true;

                                    else if (game_piece_clicked(&game_state->w_knight_l, game_assets->w_knight, game_state))
                                        game_state->w_knight_l.drag = true;

                                    else if (game_piece_clicked(&game_state->w_knight_r, game_assets->w_knight, game_state))
                                        game_state->w_knight_r.drag = true;

                                    else if (game_piece_clicked(&game_state->w_rook_l, game_assets->w_rook, game_state))
                                        game_state->w_rook_r.drag = true;

                                    else if (game_piece_clicked(&game_state->w_rook_r, game_assets->w_rook, game_state))
                                        game_state->w_rook_r.drag = true;

                                    else if (game_piece_clicked(&game_state->w_queen, game_assets->w_queen, game_state))
                                        game_state->w_queen.drag = true;

                                    else if (game_piece_clicked(&game_state->w_king, game_assets->w_king, game_state))
                                        game_state->w_king.drag = true;

                                    else {}
                                }

                                else if (game_state->p2_turn){

                                    /* BLACK PIECES CLICK */

                                    if (game_piece_clicked(&game_state->b_pawn_1, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_1.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_2, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_2.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_3, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_3.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_4, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_4.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_5, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_5.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_6, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_6.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_7, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_7.drag = true;

                                    else if (game_piece_clicked(&game_state->b_pawn_8, game_assets->b_pawn, game_state))
                                        game_state->b_pawn_8.drag = true;

                                    else if (game_piece_clicked(&game_state->b_bishop_l, game_assets->b_bishop, game_state))
                                        game_state->b_bishop_l.drag = true;

                                    else if (game_piece_clicked(&game_state->b_bishop_r, game_assets->b_bishop, game_state))
                                        game_state->b_bishop_r.drag = true;

                                    else if (game_piece_clicked(&game_state->b_knight_l, game_assets->b_knight, game_state))
                                        game_state->b_knight_l.drag = true;

                                    else if (game_piece_clicked(&game_state->b_knight_r, game_assets->b_knight, game_state))
                                        game_state->b_knight_r.drag = true;

                                    else if (game_piece_clicked(&game_state->b_rook_l, game_assets->b_rook, game_state))
                                        game_state->b_rook_r.drag = true;

                                    else if (game_piece_clicked(&game_state->b_rook_r, game_assets->b_rook, game_state))
                                        game_state->b_rook_r.drag = true;

                                    else if (game_piece_clicked(&game_state->b_queen, game_assets->b_queen, game_state))
                                        game_state->b_queen.drag = true;

                                    else if (game_piece_clicked(&game_state->b_king, game_assets->b_king, game_state))
                                        game_state->b_king.drag = true;

                                    else {}
                                }
                            }

                            break;
                        }
                        case LB_REL: {

                            /* WHITE PIECES DROP */

                            if (game_state->w_pawn_1.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_1, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_1.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_1);
                                }
                            }
                            else if (game_state->w_pawn_2.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_2, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_2.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_2);
                                }
                            }
                            else if (game_state->w_pawn_3.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_3, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_3.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_3);
                                }
                            }
                            else if (game_state->w_pawn_4.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_4, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_4.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_4);
                                }
                            }
                            else if (game_state->w_pawn_5.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_5, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_5.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_5);
                                }
                            }
                            else if (game_state->w_pawn_6.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_6, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_6.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_6);
                                }
                            }
                            else if (game_state->w_pawn_7.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_7, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_7.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_7);
                                }
                            }
                            else if (game_state->w_pawn_8.drag){
                                if (!game_piece_clicked(&game_state->w_pawn_8, game_assets->w_pawn, game_state)) {
                                    game_state->w_pawn_8.drag = false;
                                    game_drop_piece(game_state, &game_state->w_pawn_8);
                                }
                            }
                            else if (game_state->w_bishop_l.drag){
                                if (!game_piece_clicked(&game_state->w_bishop_l, game_assets->w_bishop, game_state)) {
                                    game_state->w_bishop_l.drag = false;
                                    game_drop_piece(game_state, &game_state->w_bishop_l);
                                }
                            }
                            else if (game_state->w_bishop_r.drag){
                                if (!game_piece_clicked(&game_state->w_bishop_r, game_assets->w_bishop, game_state)) {
                                    game_state->w_bishop_r.drag = false;
                                    game_drop_piece(game_state, &game_state->w_bishop_r);
                                }
                            }
                            else if (game_state->w_knight_l.drag){
                                if (!game_piece_clicked(&game_state->w_knight_l, game_assets->w_knight, game_state)) {
                                    game_state->w_knight_l.drag = false;
                                    game_drop_piece(game_state, &game_state->w_knight_l);
                                }
                            }
                            else if (game_state->w_knight_r.drag){
                                if (!game_piece_clicked(&game_state->w_knight_r, game_assets->w_knight, game_state)) {
                                    game_state->w_knight_r.drag = false;
                                    game_drop_piece(game_state, &game_state->w_knight_r);
                                }
                            }
                            else if (game_state->w_rook_l.drag){
                                if (!game_piece_clicked(&game_state->w_rook_l, game_assets->w_rook, game_state)) {
                                    game_state->w_rook_l.drag = false;
                                    game_drop_piece(game_state, &game_state->w_rook_l);
                                }
                            }
                            else if (game_state->w_rook_r.drag){
                                if (!game_piece_clicked(&game_state->w_rook_r, game_assets->w_rook, game_state)) {
                                    game_state->w_rook_r.drag = false;
                                    game_drop_piece(game_state, &game_state->w_rook_r);
                                }
                            }
                            else if (game_state->w_queen.drag){
                                if (!game_piece_clicked(&game_state->w_queen, game_assets->w_queen, game_state)) {
                                    game_state->w_queen.drag = false;
                                    game_drop_piece(game_state, &game_state->w_queen);
                                }
                            }
                            else if (game_state->w_king.drag){
                                if (!game_piece_clicked(&game_state->w_king, game_assets->w_king, game_state)) {
                                    game_state->w_king.drag = false;
                                    game_drop_piece(game_state, &game_state->w_king);
                                }
                            }
                            else {}


                            /* BLACK PIECES DROP */

                            if (game_state->b_pawn_1.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_1, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_1.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_1);
                                }
                            }
                            else if (game_state->b_pawn_2.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_2, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_2.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_2);
                                }
                            }
                            else if (game_state->b_pawn_3.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_3, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_3.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_3);
                                }
                            }
                            else if (game_state->b_pawn_4.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_4, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_4.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_4);
                                }
                            }
                            else if (game_state->b_pawn_5.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_5, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_5.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_5);
                                }
                            }
                            else if (game_state->b_pawn_6.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_6, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_6.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_6);
                                }
                            }
                            else if (game_state->b_pawn_7.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_7, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_7.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_7);
                                }
                            }
                            else if (game_state->b_pawn_8.drag){
                                if (!game_piece_clicked(&game_state->b_pawn_8, game_assets->b_pawn, game_state)) {
                                    game_state->b_pawn_8.drag = false;
                                    game_drop_piece(game_state, &game_state->b_pawn_8);
                                }
                            }
                            else if (game_state->b_bishop_l.drag){
                                if (!game_piece_clicked(&game_state->b_bishop_l, game_assets->b_bishop, game_state)) {
                                    game_state->b_bishop_l.drag = false;
                                    game_drop_piece(game_state, &game_state->b_bishop_l);
                                }
                            }
                            else if (game_state->b_bishop_r.drag){
                                if (!game_piece_clicked(&game_state->b_bishop_r, game_assets->b_bishop, game_state)) {
                                    game_state->b_bishop_r.drag = false;
                                    game_drop_piece(game_state, &game_state->b_bishop_r);
                                }
                            }
                            else if (game_state->b_knight_l.drag){
                                if (!game_piece_clicked(&game_state->b_knight_l, game_assets->b_knight, game_state)) {
                                    game_state->b_knight_l.drag = false;
                                    game_drop_piece(game_state, &game_state->b_knight_l);
                                }
                            }
                            else if (game_state->b_knight_r.drag){
                                if (!game_piece_clicked(&game_state->b_knight_r, game_assets->b_knight, game_state)) {
                                    game_state->b_knight_r.drag = false;
                                    game_drop_piece(game_state, &game_state->b_knight_r);
                                }
                            }
                            else if (game_state->b_rook_l.drag){
                                if (!game_piece_clicked(&game_state->b_rook_l, game_assets->b_rook, game_state)) {
                                    game_state->b_rook_l.drag = false;
                                    game_drop_piece(game_state, &game_state->b_rook_l);
                                }
                            }
                            else if (game_state->b_rook_r.drag){
                                if (!game_piece_clicked(&game_state->b_rook_r, game_assets->b_rook, game_state)) {
                                    game_state->b_rook_r.drag = false;
                                    game_drop_piece(game_state, &game_state->b_rook_r);
                                }
                            }
                            else if (game_state->b_queen.drag){
                                if (!game_piece_clicked(&game_state->b_queen, game_assets->b_queen, game_state)) {
                                    game_state->b_queen.drag = false;
                                    game_drop_piece(game_state, &game_state->b_queen);
                                }
                            }
                            else if (game_state->b_king.drag){
                                if (!game_piece_clicked(&game_state->b_king, game_assets->b_king, game_state)) {
                                    game_state->b_king.drag = false;
                                    game_drop_piece(game_state, &game_state->b_king);
                                }
                            }
                            else {}


                            /* MENU BUTTON */

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

                    break;
                }
                case KEYBOARD: {

                    if (game_state->pressed_key == KBC_SPACE_KEY_MAKECODE){
                        if (game_state->move_made){

                            if (game_state->p1_turn){
                                game_state->p1_turn = false;
                                game_state->p2_turn = true;
                            }
                            else {
                                game_state->p1_turn = true;
                                game_state->p2_turn = false;
                            }

                            game_state->move_made = false;
                        }
                    }
                    else if (game_state->pressed_key == KBC_LEFT_KEY_BREAKCODE){
                        game_state->last_played_piece->x_pos = game_state->last_played_piece->start_x;
                        game_state->last_played_piece->y_pos = game_state->last_played_piece->start_y;

                        game_state->move_made = false;
                        game_state->reverted_cell->occupied = false;
                        game_state->last_captured_piece->captured = false;
                    }

                    game_state->pressed_key = 0;

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
                            if (game_elem_clicked(game_assets->end_game_btn, game_state)){
                                game_data_init(game_state);
                                game_state->curr_state = MAIN_MENU;
                            }

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

                    game_state->pressed_key = 0;

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

            game_data_init(game_state);

            // --- return to play
            game_state->curr_state = PLAY_GAME;

            break;
        }
        case VICTORY: {

            switch (game_state->curr_event){
                case TIMER: {
                    gui_victory_screen(game_assets, game_state);
                    break;
                }
                case MOUSE: {

                    switch (game_state->curr_mouse_event.type){
                        case MOV: {
                            game_update_cursor(game_state);
                            break;
                        }
                        case LB_REL: {

                            break;
                        }
                        default: {
                            game_update_cursor(game_state);
                            break;
                        }
                    }

                }
                case KEYBOARD: {

                    if (game_state->pressed_key == KBC_ENTER_KEY_MAKECODE){
                        game_data_init(game_state);
                        game_state->curr_state = MAIN_MENU;
                    }

                    if (game_state->pressed_key == KBC_ESC_KEY_MAKECODE){
                        game_data_init(game_state);
                        game_state->curr_state = MAIN_MENU;
                    }

                    game_state->pressed_key = 0;

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


    // rtc subscription
    uint8_t rtcBitNum = RTC_IRQ;
    int rtcIrqSet = BIT(rtcBitNum);

    _Bool rtcIrqSetIsValid = rtc_subscribe_int(&rtcBitNum) == EXIT_SUCCESS;


    if (mouse_enable_data_report(&stByte) != PS2_WRITE_CMD_ERR){

        if (timerIrqSetIsValid && kbcIrqSetIsValid && mouseIrqSetIsValid && rtcIrqSetIsValid){

            rtc_enable_int();

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


                            // RTC interrupt handling

                            if (msg.m_notify.interrupts & rtcIrqSet) {

                                // UPDATE
                                game_state->curr_event = RTC;
                                game_update_state(game_assets, game_state);
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

            rtc_unsubscribe_int();
            kbc_unsubscribe_int();
            timer_unsubscribe_int();

            rtc_disable_int();
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


