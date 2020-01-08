#pragma once

/* INCLUDES */

#include <lcom/lcf.h>

#include "../macros/rtc_macros.h"
#include "../modules/mouse/mouse.h"

#include "../../assets/backgrounds/BoardBG.h"
#include "../../assets/backgrounds/InGameMenuBG.h"
#include "../../assets/backgrounds/MenuBG.h"
#include "../../assets/backgrounds/SelectPlayerBG.h"
#include "../../assets/backgrounds/StartBG.h"
#include "../../assets/backgrounds/loadingScreenBG.h"

#include "../../assets/backgrounds/victory_griff_bg.h"
#include "../../assets/backgrounds/victory_raven_bg.h"
#include "../../assets/backgrounds/victory_slyth_bg.h"
#include "../../assets/backgrounds/victory_huff_bg.h"


#include "../../assets/borders/playersleft.h"
#include "../../assets/borders/playersright.h"

#include "../../assets/buttons/ChangeGameMode.h"
#include "../../assets/buttons/InGameMenu.h"
#include "../../assets/buttons/multiplayer.h"
#include "../../assets/buttons/singleplayer.h"
#include "../../assets/buttons/ReStartGame.h"
#include "../../assets/buttons/Start.h"
#include "../../assets/buttons/End Game.h"
#include "../../assets/buttons/Title.h"
#include "../../assets/buttons/exit.h"

#include "../../assets/characters/godric.h"
#include "../../assets/characters/godricgif.h"
#include "../../assets/characters/helga.h"
#include "../../assets/characters/helgagif.h"
#include "../../assets/characters/rowena.h"
#include "../../assets/characters/rowenagif.h"
#include "../../assets/characters/salazar.h"
#include "../../assets/characters/salazargif.h"

#include "../../assets/logos/gryffindor.h"
#include "../../assets/logos/hufflepuff.h"
#include "../../assets/logos/ravenclaw.h"
#include "../../assets/logos/slytherin.h"

#include "../../assets/pieces/white/WhitePawn.h"
#include "../../assets/pieces/white/WhiteBishop.h"
#include "../../assets/pieces/white/WhiteHorse.h"
#include "../../assets/pieces/white/WhiteTower.h"
#include "../../assets/pieces/white/WhiteQueen.h"
#include "../../assets/pieces/white/WhiteKing.h"
#include "../../assets/pieces/black/BlackPawn.h"
#include "../../assets/pieces/black/BlackBishop.h"
#include "../../assets/pieces/black/BlackHorse.h"
#include "../../assets/pieces/black/BlackTower.h"
#include "../../assets/pieces/black/BlackQueen.h"
#include "../../assets/pieces/black/BlackKing.h"

#include "../../assets/numbers/0_zero.h"
#include "../../assets/numbers/1_one.h"
#include "../../assets/numbers/2_two.h"
#include "../../assets/numbers/3_three.h"
#include "../../assets/numbers/4_four.h"
#include "../../assets/numbers/5_five.h"
#include "../../assets/numbers/6_six.h"
#include "../../assets/numbers/7_seven.h"
#include "../../assets/numbers/8_eight.h"
#include "../../assets/numbers/9_nine.h"
#include "../../assets/numbers/colon.h"

#include "../../assets/time/00.h"
#include "../../assets/time/01.h"
#include "../../assets/time/02.h"
#include "../../assets/time/03.h"
#include "../../assets/time/04.h"
#include "../../assets/time/05.h"
#include "../../assets/time/06.h"
#include "../../assets/time/07.h"
#include "../../assets/time/08.h"
#include "../../assets/time/09.h"
#include "../../assets/time/10.h"
#include "../../assets/time/11.h"
#include "../../assets/time/12.h"
#include "../../assets/time/13.h"
#include "../../assets/time/14.h"
#include "../../assets/time/15.h"
#include "../../assets/time/16.h"
#include "../../assets/time/17.h"
#include "../../assets/time/18.h"
#include "../../assets/time/19.h"
#include "../../assets/time/20.h"
#include "../../assets/time/21.h"
#include "../../assets/time/22.h"
#include "../../assets/time/23.h"
#include "../../assets/time/24.h"
#include "../../assets/time/25.h"
#include "../../assets/time/26.h"
#include "../../assets/time/27.h"
#include "../../assets/time/28.h"
#include "../../assets/time/29.h"
#include "../../assets/time/30.h"
#include "../../assets/time/31.h"
#include "../../assets/time/32.h"
#include "../../assets/time/33.h"
#include "../../assets/time/34.h"
#include "../../assets/time/35.h"
#include "../../assets/time/36.h"
#include "../../assets/time/37.h"
#include "../../assets/time/38.h"
#include "../../assets/time/39.h"
#include "../../assets/time/40.h"
#include "../../assets/time/41.h"
#include "../../assets/time/42.h"
#include "../../assets/time/43.h"
#include "../../assets/time/44.h"
#include "../../assets/time/45.h"
#include "../../assets/time/46.h"
#include "../../assets/time/47.h"
#include "../../assets/time/48.h"
#include "../../assets/time/49.h"
#include "../../assets/time/50.h"
#include "../../assets/time/51.h"
#include "../../assets/time/52.h"
#include "../../assets/time/53.h"
#include "../../assets/time/54.h"
#include "../../assets/time/55.h"
#include "../../assets/time/56.h"
#include "../../assets/time/57.h"
#include "../../assets/time/58.h"
#include "../../assets/time/59.h"

#include "../../assets/visual_fx/SelectedMenu.h"
#include "../../assets/visual_fx/SelectInGameMenu.h"
#include "../../assets/visual_fx/cursor_normal.h"
#include "../../assets/visual_fx/transparent.h"


/* CONSTANTS */

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define GAME_ASSETS_ARR_SIZE     8

#define BOARD_START_X            349
#define BOARD_END_X              941
#define BOARD_START_Y            230
#define BOARD_END_Y              806


/* ENUMERATIONS */

enum ASSET_TYPE {
    BTNS,
    BGS,
    PIECES,
    BORDERS,
    CHARS,
    LOGOS,
    NUMBERS,
    V_FX
};

enum GAME_HOUSES {
    GRYFFINDOR,
    HUFFLEPUFF,
    RAVENCLAW,
    SLYTHERIN
};

enum GAME_STATE {
    START_WINDOW,
    MAIN_MENU,
    CHAR_SELECT,
    GAME_MODE_SELECT,
    PLAY_GAME,
    IN_GAME_MENU,
    RESTART_GAME,
    VICTORY
};

enum GAME_EVENT {
    TIMER,
    KEYBOARD,
    MOUSE,
    RTC
};

enum PIECE_TYPES {
    PAWN,
    BISHOP,
    KNIGHT,
    ROOK,
    QUEEN,
    KING
};

enum PIECE_ALIGNMENT {
    WHITE,
    BLACK
};

enum BOARD_CELLS {
    A1, A2, A3, A4, A5, A6, A7, A8,
    B1, B2, B3, B4, B5, B6, B7, B8,
    C1, C2, C3, C4, C5, C6, C7, C8,
    D1, D2, D3, D4, D5, D6, D7, D8,
    E1, E2, E3, E4, E5, E6, E7, E8,
    F1, F2, F3, F4, F5, F6, F7, F8,
    G1, G2, G3, G4, G5, G6, G7, G8,
    H1, H2, H3, H4, H5, H6, H7, H8
};


/* OBJECTS */

typedef struct {

    uint8_t* pixmap;

    int width;
    int height;

    uint16_t start_x;
    uint16_t start_y;

} sprite_t;

typedef struct {

    /* Mouse */

    sprite_t mouse_cursor;


    /* Backgrounds */

    sprite_t start_bg;
    sprite_t main_menu_bg;
    sprite_t player_sel_bg;
    sprite_t board_bg;
    sprite_t in_game_menu_bg;
    sprite_t victory_gryff;
    sprite_t victory_slyth;
    sprite_t victory_huff;
    sprite_t victory_raven;



    /* Buttons */

    sprite_t title;
    sprite_t start_btn;
    sprite_t singleplayer_btn;
    sprite_t multiplayer_btn;
    sprite_t exit_btn;
    sprite_t change_game_mode_btn;
    sprite_t end_game_btn;
    sprite_t in_game_menu_btn;
    sprite_t restart_game_btn;


    /* Borders */

    sprite_t left_p_border;
    sprite_t right_p_border;


    /* Logos */

    sprite_t gryff_logo;
    sprite_t huffle_logo;
    sprite_t raven_logo;
    sprite_t slyth_logo;


    /* Characters */

    sprite_t godric_img;
    sprite_t godric_title;

    sprite_t helga_img;
    sprite_t helga_title;

    sprite_t rowena_img;
    sprite_t rowena_title;

    sprite_t salazar_img;
    sprite_t salazar_title;


    /* Pieces */

    sprite_t w_pawn;
    sprite_t w_bishop;
    sprite_t w_rook;
    sprite_t w_knight;
    sprite_t w_queen;
    sprite_t w_king;

    sprite_t b_pawn;
    sprite_t b_bishop;
    sprite_t b_rook;
    sprite_t b_knight;
    sprite_t b_queen;
    sprite_t b_king;


    /* Numbers */

    sprite_t zero_num;
    sprite_t one_num;
    sprite_t two_num;
    sprite_t three_num;
    sprite_t four_num;
    sprite_t five_num;
    sprite_t six_num;
    sprite_t seven_num;
    sprite_t eight_num;
    sprite_t nine_num;
    sprite_t colon_num;


    /* Time */

    sprite_t _00_;
    sprite_t _01_;
    sprite_t _02_;
    sprite_t _03_;
    sprite_t _04_;
    sprite_t _05_;
    sprite_t _06_;
    sprite_t _07_;
    sprite_t _08_;
    sprite_t _09_;

    sprite_t _10_;
    sprite_t _11_;
    sprite_t _12_;
    sprite_t _13_;
    sprite_t _14_;
    sprite_t _15_;
    sprite_t _16_;
    sprite_t _17_;
    sprite_t _18_;
    sprite_t _19_;

    sprite_t _20_;
    sprite_t _21_;
    sprite_t _22_;
    sprite_t _23_;
    sprite_t _24_;
    sprite_t _25_;
    sprite_t _26_;
    sprite_t _27_;
    sprite_t _28_;
    sprite_t _29_;

    sprite_t _30_;
    sprite_t _31_;
    sprite_t _32_;
    sprite_t _33_;
    sprite_t _34_;
    sprite_t _35_;
    sprite_t _36_;
    sprite_t _37_;
    sprite_t _38_;
    sprite_t _39_;

    sprite_t _40_;
    sprite_t _41_;
    sprite_t _42_;
    sprite_t _43_;
    sprite_t _44_;
    sprite_t _45_;
    sprite_t _46_;
    sprite_t _47_;
    sprite_t _48_;
    sprite_t _49_;

    sprite_t _50_;
    sprite_t _51_;
    sprite_t _52_;
    sprite_t _53_;
    sprite_t _54_;
    sprite_t _55_;
    sprite_t _56_;
    sprite_t _57_;
    sprite_t _58_;
    sprite_t _59_;


    /* Visual_FX */

    sprite_t transparent;
    sprite_t transp_piece;
    sprite_t hover_main_menu;
    sprite_t hover_in_game_menu;

} game_assets_t;

typedef struct board_cell_t board_cell_t;

typedef struct {

    enum PIECE_TYPES type;
    enum PIECE_ALIGNMENT alignment;

    _Bool first_move;
    _Bool captured;
    _Bool drag;

    board_cell_t* curr_cell;

    uint16_t start_x;
    uint16_t start_y;

    uint16_t x_pos;
    uint16_t y_pos;

    uint16_t prev_x_pos;
    uint16_t prev_y_pos;

} game_piece_t;

struct board_cell_t {

    _Bool occupied;

    game_piece_t* curr_piece;

    uint16_t start_x;
    uint16_t start_y;

    uint16_t end_x;
    uint16_t end_y;

};

typedef struct {

    board_cell_t a1, a2, a3, a4, a5, a6, a7, a8;
    board_cell_t b1, b2, b3, b4, b5, b6, b7, b8;
    board_cell_t c1, c2, c3, c4, c5, c6, c7, c8;
    board_cell_t d1, d2, d3, d4, d5, d6, d7, d8;
    board_cell_t e1, e2, e3, e4, e5, e6, e7, e8;
    board_cell_t f1, f2, f3, f4, f5, f6, f7, f8;
    board_cell_t g1, g2, g3, g4, g5, g6, g7, g8;
    board_cell_t h1, h2, h3, h4, h5, h6, h7, h8;

} game_board_t;

typedef struct {

    // Game general data
    _Bool leave;
    _Bool multiplayer;
    _Bool move_made;

    rtc_time_t curr_time;
    uint32_t play_time;

    // Mouse event and positions
    struct mouse_event curr_mouse_event;

    _Bool lb, mb, rb;

    uint16_t mouse_curr_x_pos;
    uint16_t mouse_curr_y_pos;

    uint16_t mouse_prev_x_pos;
    uint16_t mouse_prev_y_pos;

    // Current state, event, time and options
    enum GAME_STATE curr_state;
    enum GAME_EVENT curr_event;

    uint8_t pressed_key;

    // Player Data
    enum GAME_HOUSES p1_house;
    enum GAME_HOUSES p2_house;

    _Bool p1_choose_char;
    _Bool p2_choose_char;

    _Bool p1_turn;
    _Bool p2_turn;

    _Bool p1_victory;
    _Bool p2_victory;

    // Timers
    uint32_t p1_ten_secs_counter;
    uint8_t p1_sec_loop_counter;

    uint32_t p2_ten_secs_counter;
    uint8_t p2_sec_loop_counter;

    uint8_t p1_f_digit_left;
    uint8_t p1_s_digit_left;
    uint8_t p1_f_digit_right;
    uint8_t p1_s_digit_right;

    uint8_t p2_f_digit_left;
    uint8_t p2_s_digit_left;
    uint8_t p2_f_digit_right;
    uint8_t p2_s_digit_right;

    uint32_t p1_timer_int_count;
    uint32_t p2_timer_int_count;

    // Board
    game_board_t board;
    board_cell_t* reverted_cell;

    // Pieces
    game_piece_t* last_played_piece;
    game_piece_t* last_captured_piece;

    uint16_t white_pieces_x_pos[16];
    uint16_t white_pieces_y_pos[16];

    uint16_t black_pieces_x_pos[16];
    uint16_t black_pieces_y_pos[16];

    // white
    game_piece_t w_pawn_1;
    game_piece_t w_pawn_2;
    game_piece_t w_pawn_3;
    game_piece_t w_pawn_4;
    game_piece_t w_pawn_5;
    game_piece_t w_pawn_6;
    game_piece_t w_pawn_7;
    game_piece_t w_pawn_8;

    game_piece_t w_bishop_l;
    game_piece_t w_bishop_r;

    game_piece_t w_knight_l;
    game_piece_t w_knight_r;

    game_piece_t w_rook_l;
    game_piece_t w_rook_r;

    game_piece_t w_queen;
    game_piece_t w_king;

    // black
    game_piece_t b_pawn_1;
    game_piece_t b_pawn_2;
    game_piece_t b_pawn_3;
    game_piece_t b_pawn_4;
    game_piece_t b_pawn_5;
    game_piece_t b_pawn_6;
    game_piece_t b_pawn_7;
    game_piece_t b_pawn_8;

    game_piece_t b_bishop_l;
    game_piece_t b_bishop_r;

    game_piece_t b_knight_l;
    game_piece_t b_knight_r;

    game_piece_t b_rook_l;
    game_piece_t b_rook_r;

    game_piece_t b_queen;
    game_piece_t b_king;

} game_state_t;

