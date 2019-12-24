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

#include "../../assets/visual_fx/SelectedMenu.h"
#include "../../assets/visual_fx/SelectInGameMenu.h"

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


/* CONSTANTS */

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define GAME_ASSETS_ARR_SIZE 8


/* XPM ARRAYS */

extern xpm_map_t xpm_bgs[5];
extern xpm_map_t xpm_borders[2];
extern xpm_map_t xpm_btns[9];
extern xpm_map_t xpm_characters[8];
extern xpm_map_t xpm_logos[4];
extern xpm_map_t xpm_pieces[12];
extern xpm_map_t xpm_visual_fx[2];
extern xpm_map_t xpm_numbers[11];


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

enum GAME_HOUSES
{
    GRYFFINDOR,
    HUFFLEPUFF,
    RAVENCLAW,
    SLYTHERIN
};

struct Sprite {
    uint8_t *pixmap;
    int width;
    int height;
};

struct GAME_ASSETS {
    struct Sprite buttons[9];
    struct Sprite backgrounds[5];
    struct Sprite pieces[12];
    struct Sprite borders[2];
    struct Sprite characters[8];
    struct Sprite logos[4];
    struct Sprite visual_fx[2];
    struct Sprite numbers[11];
};

struct GAME_STATE {

    _Bool leave;

    // Mouse clicks and deltas
    _Bool left_click;
    _Bool right_click;

    uint16_t mouse_x_pos;
    uint16_t mouse_y_pos;

    // Current time, window and options
    rtc_time_t curr_time;
    uint8_t curr_window;

    uint8_t pressed_key;
    uint8_t pressable_pos[2];

    uint8_t clicked_pos[2];

    // Player characters
    enum GAME_HOUSES p1_house;
    enum GAME_HOUSES p2_house;

    // Board pieces
    uint16_t white_pieces_x_pos[16];
    uint16_t white_pieces_y_pos[16];

    uint16_t black_pieces_x_pos[16];
    uint16_t black_pieces_y_pos[16];

    // Game functions to execute
    int (*switch_window)(struct GAME_ASSETS*, struct GAME_STATE*);
    int (*capture_animation)(struct GAME_ASSETS*, struct GAME_STATE*);

};

