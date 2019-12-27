#pragma once

/* INCLUDES */

#include <lcom/lcf.h>

#include "../macros/rtc_macros.h"

#include "../../assets/backgrounds/BoardBG.h"
#include "../../assets/backgrounds/InGameMenuBG.h"
#include "../../assets/backgrounds/MenuBG.h"
#include "../../assets/backgrounds/SelectPlayerBG.h"
#include "../../assets/backgrounds/StartBG.h"

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

#include "../../assets/visual_fx/SelectedMenu.h"
#include "../../assets/visual_fx/SelectInGameMenu.h"
#include "../../assets/visual_fx/cursor_normal.h"
#include "../../assets/visual_fx/transparent.h"


/* CONSTANTS */

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define GAME_ASSETS_ARR_SIZE 8


/* STRUCTURES */

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
    IN_GAME_MENU
};

enum GAME_EVENT {
    TIMER,
    KEYBOARD,
    MOUSE,
    RTC
};

typedef struct {
    uint8_t* pixmap;
    int width;
    int height;
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


    /* Visual_FX */

    sprite_t transparent;
    sprite_t hover_main_menu;
    sprite_t hover_in_game_menu;

} game_assets_t;

typedef struct {

    _Bool leave;

    // Mouse clicks and deltas
    _Bool left_click;
    _Bool right_click;

    uint16_t mouse_curr_x_pos;
    uint16_t mouse_curr_y_pos;

    uint16_t mouse_prev_x_pos;
    uint16_t mouse_prev_y_pos;

    // Current state, event, time and options
    enum GAME_STATE curr_state;
    enum GAME_EVENT curr_event;

    rtc_time_t curr_time;

    uint8_t pressed_key;
    uint8_t pressable_pos[2];

    uint8_t clicked_pos[2];

    // Player houses
    enum GAME_HOUSES p1_house;
    enum GAME_HOUSES p2_house;

    // Board pieces
    uint16_t white_pieces_x_pos[16];
    uint16_t white_pieces_y_pos[16];

    uint16_t black_pieces_x_pos[16];
    uint16_t black_pieces_y_pos[16];

    // Game functions to execute
    // int (*update_window)(game_assets_t*, game_state_t*);
    // int (*capture_animation)(game_assets_t*, game_state_t*);

} game_state_t;

