#pragma once

#include <lcom/lcf.h>


#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define GAME_ASSETS_ARR_SIZE  7



enum ASSET_TYPE {
    BTNS,
    BGS,
    PIECES,
    BORDERS,
    CHARS,
    LOGOS,
    V_FX
};


typedef sprite {
    uint8_t* pixmap;
    int width;
    int height;
} struct;


struct GAME_ASSETS {
    sprite buttons[6];
    sprite backgrounds[4];
    sprite pieces[12];
    sprite borders[2];
    sprite characters[4];
    sprite logos[4];
    sprite visual_fx[1];
};



