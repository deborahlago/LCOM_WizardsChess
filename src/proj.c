#include <lcom/lcf.h>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <machine/asm.h>

#include "libs/game/game_funcs.h"


int main(int argc, char *argv[]) {
    // sets the language of LCF messages (can be either EN-US or PT-PT)
    lcf_set_language("EN-US");

    // enables to log function invocations that are being "wrapped" by LCF
    // [comment this out if you don't want/need it]
    lcf_trace_calls("/home/lcom/labs/lab5/trace.txt");

    // enables to save the output of printf function calls on a file
    // [comment this out if you don't want/need it]
    lcf_log_output("/home/lcom/labs/lab5/output.txt");

    // handles control over to LCF
    // [LCF handles command line arguments and invokes the right function]
    if (lcf_start(argc, argv))
        return 1;

    // LCF clean up tasks
    // [must be the last statement before return]
    lcf_cleanup();

    return 0;
}

int (proj_main_loop)(int argc, char *argv[]) {

    /* Enables I/O operations */

    sys_enable_iop(SELF);


    /* Load Assets */

    game_assets_t assets;

    while (true){

        printf("\nLoading...\n");

        if (game_load_assets(&assets) != EXIT_SUCCESS)
            return EXIT_FAILURE;
        else {
            printf("\nAll assets loaded successfully!\n");
            break;
        }
    }


    /* Game Start */

    // initialize game values
    game_state_t game;

    // booleans
    game.leave = false;
    game.multiplayer = false;
    game.curr_state = START_WINDOW;

    // mouse date
    game.mouse_curr_x_pos = 500;
    game.mouse_curr_y_pos = 500;

    game.lb = false;
    game.rb = false;
    game.mb = false;


    // -----------------------------------------------
    // game pieces
    uint16_t white_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    uint16_t white_pieces_y[16] = {661, 661, 661, 661, 661, 661, 661, 661, 734, 734, 734, 734, 734, 734, 734, 734};
    uint16_t black_pieces_x[16] = {347, 422, 496, 570, 644, 718, 792, 865, 496, 718, 422, 792, 347, 865, 570, 644};
    uint16_t black_pieces_y[16] = {291, 291, 291, 291, 291, 291, 291, 291, 220, 220, 220, 220, 220, 220, 220, 220};

    for (int i = 0; i < 16; i++){
        game.white_pieces_x_pos[i] = white_pieces_x[i];
        game.white_pieces_y_pos[i] = white_pieces_y[i];
        game.black_pieces_x_pos[i] = black_pieces_x[i];
        game.black_pieces_y_pos[i] = black_pieces_y[i];
    }

    //          ---- WHITE PIECES ----

    // --- white pawns
    game.w_pawn_1.captured = false;
    game.w_pawn_1.drag = false;
    game.w_pawn_1.prev_x_pos = game.white_pieces_x_pos[0];
    game.w_pawn_1.prev_y_pos = game.white_pieces_y_pos[0];
    game.w_pawn_1.x_pos = game.white_pieces_x_pos[0];
    game.w_pawn_1.y_pos = game.white_pieces_y_pos[0];

    game.w_pawn_2.captured = false;
    game.w_pawn_2.drag = false;
    game.w_pawn_2.prev_x_pos = game.white_pieces_x_pos[1];
    game.w_pawn_2.prev_y_pos = game.white_pieces_y_pos[1];
    game.w_pawn_2.x_pos = game.white_pieces_x_pos[1];
    game.w_pawn_2.y_pos = game.white_pieces_y_pos[1];

    game.w_pawn_3.captured = false;
    game.w_pawn_3.drag = false;
    game.w_pawn_3.prev_x_pos = game.white_pieces_x_pos[2];
    game.w_pawn_3.prev_y_pos = game.white_pieces_y_pos[2];
    game.w_pawn_3.x_pos = game.white_pieces_x_pos[2];
    game.w_pawn_3.y_pos = game.white_pieces_y_pos[2];

    game.w_pawn_4.captured = false;
    game.w_pawn_4.drag = false;
    game.w_pawn_4.prev_x_pos = game.white_pieces_x_pos[3];
    game.w_pawn_4.prev_y_pos = game.white_pieces_y_pos[3];
    game.w_pawn_4.x_pos = game.white_pieces_x_pos[3];
    game.w_pawn_4.y_pos = game.white_pieces_y_pos[3];

    game.w_pawn_5.captured = false;
    game.w_pawn_5.drag = false;
    game.w_pawn_5.prev_x_pos = game.white_pieces_x_pos[4];
    game.w_pawn_5.prev_y_pos = game.white_pieces_y_pos[4];
    game.w_pawn_5.x_pos = game.white_pieces_x_pos[4];
    game.w_pawn_5.y_pos = game.white_pieces_y_pos[4];

    game.w_pawn_6.captured = false;
    game.w_pawn_6.drag = false;
    game.w_pawn_6.prev_x_pos = game.white_pieces_x_pos[5];
    game.w_pawn_6.prev_y_pos = game.white_pieces_y_pos[5];
    game.w_pawn_6.x_pos = game.white_pieces_x_pos[5];
    game.w_pawn_6.y_pos = game.white_pieces_y_pos[5];

    game.w_pawn_7.captured = false;
    game.w_pawn_7.drag = false;
    game.w_pawn_7.prev_x_pos = game.white_pieces_x_pos[6];
    game.w_pawn_7.prev_y_pos = game.white_pieces_y_pos[6];
    game.w_pawn_7.x_pos = game.white_pieces_x_pos[6];
    game.w_pawn_7.y_pos = game.white_pieces_y_pos[6];

    game.w_pawn_8.captured = false;
    game.w_pawn_8.drag = false;
    game.w_pawn_8.prev_x_pos = game.white_pieces_x_pos[7];
    game.w_pawn_8.prev_y_pos = game.white_pieces_y_pos[7];
    game.w_pawn_8.x_pos = game.white_pieces_x_pos[7];
    game.w_pawn_8.y_pos = game.white_pieces_y_pos[7];

    // --- white bishops
    game.w_bishop_l.captured = false;
    game.w_bishop_l.drag = false;
    game.w_bishop_l.prev_x_pos = game.white_pieces_x_pos[8];
    game.w_bishop_l.prev_y_pos = game.white_pieces_y_pos[8];
    game.w_bishop_l.x_pos = game.white_pieces_x_pos[8];
    game.w_bishop_l.y_pos = game.white_pieces_y_pos[8];

    game.w_bishop_r.captured = false;
    game.w_bishop_r.drag = false;
    game.w_bishop_r.prev_x_pos = game.white_pieces_x_pos[9];
    game.w_bishop_r.prev_y_pos = game.white_pieces_y_pos[9];
    game.w_bishop_r.x_pos = game.white_pieces_x_pos[9];
    game.w_bishop_r.y_pos = game.white_pieces_y_pos[9];

    // --- white knights
    game.w_knight_l.captured = false;
    game.w_knight_l.drag = false;
    game.w_knight_l.prev_x_pos = game.white_pieces_x_pos[10];
    game.w_knight_l.prev_y_pos = game.white_pieces_y_pos[10];
    game.w_knight_l.x_pos = game.white_pieces_x_pos[10];
    game.w_knight_l.y_pos = game.white_pieces_y_pos[10];

    game.w_knight_r.captured = false;
    game.w_knight_r.drag = false;
    game.w_knight_r.prev_x_pos = game.white_pieces_x_pos[11];
    game.w_knight_r.prev_y_pos = game.white_pieces_y_pos[11];
    game.w_knight_r.x_pos = game.white_pieces_x_pos[11];
    game.w_knight_r.y_pos = game.white_pieces_y_pos[11];

    // --- white rook
    game.w_rook_l.captured = false;
    game.w_rook_l.drag = false;
    game.w_rook_l.prev_x_pos = game.white_pieces_x_pos[12];
    game.w_rook_l.prev_y_pos = game.white_pieces_y_pos[12];
    game.w_rook_l.x_pos = game.white_pieces_x_pos[12];
    game.w_rook_l.y_pos = game.white_pieces_y_pos[12];

    game.w_rook_r.captured = false;
    game.w_rook_r.drag = false;
    game.w_rook_r.prev_x_pos = game.white_pieces_x_pos[13];
    game.w_rook_r.prev_y_pos = game.white_pieces_y_pos[13];
    game.w_rook_r.x_pos = game.white_pieces_x_pos[13];
    game.w_rook_r.y_pos = game.white_pieces_y_pos[13];

    // --- white queen
    game.w_queen.captured = false;
    game.w_queen.drag = false;
    game.w_queen.prev_x_pos = game.white_pieces_x_pos[14];
    game.w_queen.prev_y_pos = game.white_pieces_y_pos[14];
    game.w_queen.x_pos = game.white_pieces_x_pos[14];
    game.w_queen.y_pos = game.white_pieces_y_pos[14];

    // --- white king
    game.w_king.captured = false;
    game.w_king.drag = false;
    game.w_king.prev_x_pos = game.white_pieces_x_pos[15];
    game.w_king.prev_y_pos = game.white_pieces_y_pos[15];
    game.w_king.x_pos = game.white_pieces_x_pos[15];
    game.w_king.y_pos = game.white_pieces_y_pos[15];



    //            ---- BLACK PIECES ----

    // --- black pawns
    game.b_pawn_1.captured = false;
    game.b_pawn_1.drag = false;
    game.b_pawn_1.x_pos = game.black_pieces_x_pos[0];
    game.b_pawn_1.y_pos = game.black_pieces_y_pos[0];

    game.b_pawn_2.captured = false;
    game.b_pawn_2.drag = false;
    game.b_pawn_2.x_pos = game.black_pieces_x_pos[1];
    game.b_pawn_2.y_pos = game.black_pieces_y_pos[1];

    game.b_pawn_3.captured = false;
    game.b_pawn_3.drag = false;
    game.b_pawn_3.x_pos = game.black_pieces_x_pos[2];
    game.b_pawn_3.y_pos = game.black_pieces_y_pos[2];

    game.b_pawn_4.captured = false;
    game.b_pawn_4.drag = false;
    game.b_pawn_4.x_pos = game.black_pieces_x_pos[3];
    game.b_pawn_4.y_pos = game.black_pieces_y_pos[3];

    game.b_pawn_5.captured = false;
    game.b_pawn_5.drag = false;
    game.b_pawn_5.x_pos = game.black_pieces_x_pos[4];
    game.b_pawn_5.y_pos = game.black_pieces_y_pos[4];

    game.b_pawn_6.captured = false;
    game.b_pawn_6.drag = false;
    game.b_pawn_6.x_pos = game.black_pieces_x_pos[5];
    game.b_pawn_6.y_pos = game.black_pieces_y_pos[5];

    game.b_pawn_7.captured = false;
    game.b_pawn_7.drag = false;
    game.b_pawn_7.x_pos = game.black_pieces_x_pos[6];
    game.b_pawn_7.y_pos = game.black_pieces_y_pos[6];

    game.b_pawn_8.captured = false;
    game.b_pawn_8.drag = false;
    game.b_pawn_8.x_pos = game.black_pieces_x_pos[7];
    game.b_pawn_8.y_pos = game.black_pieces_y_pos[7];

    // --- black bishops
    game.b_bishop_l.captured = false;
    game.b_bishop_l.drag = false;
    game.b_bishop_l.x_pos = game.black_pieces_x_pos[8];
    game.b_bishop_l.y_pos = game.black_pieces_y_pos[8];

    game.b_bishop_r.captured = false;
    game.b_bishop_r.drag = false;
    game.b_bishop_r.x_pos = game.black_pieces_x_pos[9];
    game.b_bishop_r.y_pos = game.black_pieces_y_pos[9];

    // --- black knights
    game.b_knight_l.captured = false;
    game.b_knight_l.drag = false;
    game.b_knight_l.x_pos = game.black_pieces_x_pos[10];
    game.b_knight_l.y_pos = game.black_pieces_y_pos[10];

    game.b_knight_r.captured = false;
    game.b_knight_r.drag = false;
    game.b_knight_r.x_pos = game.black_pieces_x_pos[11];
    game.b_knight_r.y_pos = game.black_pieces_y_pos[11];

    // --- black knights
    game.b_knight_l.captured = false;
    game.b_knight_l.drag = false;
    game.b_knight_l.x_pos = game.black_pieces_x_pos[10];
    game.b_knight_l.y_pos = game.black_pieces_y_pos[10];

    game.b_knight_r.captured = false;
    game.b_knight_r.drag = false;
    game.b_knight_r.x_pos = game.black_pieces_x_pos[11];
    game.b_knight_r.y_pos = game.black_pieces_y_pos[11];

    // --- black rooks
    game.b_rook_l.captured = false;
    game.b_rook_l.drag = false;
    game.b_rook_l.x_pos = game.black_pieces_x_pos[12];
    game.b_rook_l.y_pos = game.black_pieces_y_pos[12];

    game.b_rook_r.captured = false;
    game.b_rook_r.drag = false;
    game.b_rook_r.x_pos = game.black_pieces_x_pos[13];
    game.b_rook_r.y_pos = game.black_pieces_y_pos[13];

    // --- black queen
    game.b_queen.captured = false;
    game.b_queen.drag = false;
    game.b_queen.x_pos = game.black_pieces_x_pos[14];
    game.b_queen.y_pos = game.black_pieces_y_pos[14];

    // --- black king
    game.b_king.captured = false;
    game.b_king.drag = false;
    game.b_king.x_pos = game.black_pieces_x_pos[15];
    game.b_king.y_pos = game.black_pieces_y_pos[15];

    // ----------------------------------------------------


    // run game
    if (game_run(&assets, &game) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
