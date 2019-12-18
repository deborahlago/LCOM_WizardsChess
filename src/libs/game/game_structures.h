#pragma once

/* INCLUDES */

#include <lcom/lcf.h>

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
#include "../../assets/characters/helga.h"
#include "../../assets/characters/rowena.h"
#include "../../assets/characters/salazar.h"

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


/* CONSTANTS */

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define GAME_ASSETS_ARR_SIZE  7


/* XPM ARRAYS */

xpm_map_t xpm_bgs[5] = { start_BG, mainMenu_BG, selectPlayer_BG, board_BG, inGameMenu_BG  };
xpm_map_t xpm_borders[2] = { left_player_board_button, right_player_board_button };
xpm_map_t xpm_btns[9] = { title, start_button, singleplayer_button, multiplayer_button, exit_button, changeGameMode_button, endGame_button, inGameMenu_button, reStartGame_button  };
xpm_map_t xpm_characters[8] = { godric_button, helga_button, rowena_button, salazar_button };
xpm_map_t xpm_logos[4] = { gryffindor_logo, hufflepuff_logo, ravenclaw_logo, slytherin_logo };
xpm_map_t xpm_pieces[12] = { whitePawn, whiteBishop, whiteHorse, whiteTower, whiteQueen, whiteKing, blackPawn, blackBishop, blackHorse, blackTower, blackQueen, blackKing };
xpm_map_t xpm_visual_fx[2] = { selectedMenu_visualFx, selectInGameMenu_visualFx };


/* STRUCTURES */

enum ASSET_TYPE {
    BTNS,
    BGS,
    PIECES,
    BORDERS,
    CHARS,
    LOGOS,
    V_FX
};

enum GAME_HOUSES {
    GRYFFINDOR,
    HUFFLEPUFF,
    RAVENCLAW,
    SLYTHERIN
};

typedef sprite {
    uint8_t* pixmap;
    int width;
    int height;
} struct;

struct GAME_ASSETS {
    sprite buttons[9];
    sprite backgrounds[5];
    sprite pieces[12];
    sprite borders[2];
    sprite characters[8];
    sprite logos[4];
    sprite visual_fx[2];
};



