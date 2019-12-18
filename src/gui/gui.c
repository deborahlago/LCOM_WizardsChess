
/* INCLUDES */

#include "gui.h"

#include "../libs/game/game_funcs.h"

#include "../libs/modules/timer/timer.h"
#include "../libs/modules/keyboard/keyboard.h"
#include "../libs/modules/mouse/mouse.h"
#include "../libs/modules/gpu/videographic.h"



/* START WINDOW */

int gui_start_window(GAME_ASSETS* game_assets){

    // BG
    vg_render_sprite(game_assets->backgrounds[0], , );

    // BTNS
    vg_render_sprite(game_assets->buttons[0], , );      // title
    vg_render_sprite(game_assets->buttons[1], , );      // start button

    return EXIT_SUCCESS;
}


/* MAIN MENU */

int gui_main_menu(GAME_ASSETS* game_assets){

    // BG
    vg_render_sprite(game_assets->backgrounds[1], , );

    // BTNS
    vg_render_sprite(game_assets->buttons[2], , );      // multi player button
    vg_render_sprite(game_assets->buttons[3], , );      // single player button
    vg_render_sprite(game_assets->buttons[4], , );      // exit button

    return EXIT_SUCCESS;
}


/* IN GAME MENU */

int gui_in_game_menu(GAME_ASSETS* game_assets){

    // BG
    vg_render_sprite(game_assets->backgrounds[4], , );

    // BTNS
    vg_render_sprite(game_assets->buttons[8], , );      // re-start game button
    vg_render_sprite(game_assets->buttons[5], , );      // change game mode button
    vg_render_sprite(game_assets->buttons[6], , );      // end game button

    return EXIT_SUCCESS;
}


/* GAME WINDOW */

int gui_game_window(GAME_ASSETS* game_assets, GAME_HOUSES p1_house, GAME_HOUSES p2_house){

    /* BG */

    vg_render_sprite(game_assets->backgrounds[3], , );


    /* BTNS */

    vg_render_sprite(game_assets->buttons[7], , );      // in-game menu button


    /* BORDERS */

    vg_render_sprite(game_assets->borders[0], , );      // left player border
    vg_render_sprite(game_assets->borders[1], , );      // right player border


    /* LOGOS */

    vg_render_sprite(game_assets->logo[p1_house], , );         // player 1 house logo
    vg_render_sprite(game_assets->borders[p2_house], , );      // player 2 house logo



    //
    // Game Logic To implement
    //

    /* TIMERS */


    /* PIECES */

    // WHITE
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[0], , );      // pawn
    vg_render_sprite(game_assets->pieces[2], , );      // left bishop
    vg_render_sprite(game_assets->pieces[2], , );      // right bishop
    vg_render_sprite(game_assets->pieces[3], , );      // left horse
    vg_render_sprite(game_assets->pieces[3], , );      // right horse
    vg_render_sprite(game_assets->pieces[4], , );      // left rook
    vg_render_sprite(game_assets->pieces[4], , );      // right rook
    vg_render_sprite(game_assets->pieces[5], , );      // queen
    vg_render_sprite(game_assets->pieces[6], , );      // king

    // BLACK
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[7], , );       // pawn
    vg_render_sprite(game_assets->pieces[8], , );       // left bishop
    vg_render_sprite(game_assets->pieces[8], , );       // right bishop
    vg_render_sprite(game_assets->pieces[9], , );       // left horse
    vg_render_sprite(game_assets->pieces[9], , );       // right horse
    vg_render_sprite(game_assets->pieces[10], , );      // left rook
    vg_render_sprite(game_assets->pieces[10], , );      // right rook
    vg_render_sprite(game_assets->pieces[11], , );      // queen
    vg_render_sprite(game_assets->pieces[12], , );      // king

    return EXIT_SUCCESS;
}


/* GAME MODE SELECTION */

int gui_game_mode_sel_window(GAME_ASSETS* game_assets){



    return EXIT_SUCCESS;
}


/* CHARACTER SELECTION */

int gui_char_sel_window(GAME_ASSETS* game_assets){

    /* BG */

    vg_render_sprite(game_assets->backgrounds[2], , );


    /* CHARACTERS */

    // Godric
    vg_render_sprite(game_assets->characters[0], , );      // character sprite
    vg_render_sprite(game_assets->characters[1], , );      // character name

    // Helga
    vg_render_sprite(game_assets->characters[2], , );      // character sprite
    vg_render_sprite(game_assets->characters[3], , );      // character name

    // Rowena
    vg_render_sprite(game_assets->characters[4], , );      // character sprite
    vg_render_sprite(game_assets->characters[5], , );      // character name

    // Salazar
    vg_render_sprite(game_assets->characters[6], , );      // character sprite
    vg_render_sprite(game_assets->characters[7], , );      // character name



    return EXIT_SUCCESS;
}

