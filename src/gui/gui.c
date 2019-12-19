
/* INCLUDES */

#include "gui.h"

#include "../libs/game/game_funcs.h"

#include "../libs/modules/timer/timer.h"
#include "../libs/modules/keyboard/keyboard.h"
#include "../libs/modules/mouse/mouse.h"
#include "../libs/modules/gpu/videographic.h"

/* START WINDOW */

int gui_start_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state)
{

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[0], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[0], 458, 102); // title
    vg_render_sprite(game_assets->buttons[1], 883, 870); // start button

    return EXIT_SUCCESS;
}

/* MAIN MENU */

int gui_main_menu(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state)
{

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[1], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[2], 872, 510); // multi player button
    vg_render_sprite(game_assets->buttons[3], 871, 580); // single player button
    vg_render_sprite(game_assets->buttons[4], 907, 644); // exit button

    /* INTERRUPT LOOPS */

    return EXIT_SUCCESS;
}

/* IN GAME MENU */

int gui_in_game_menu(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state)
{

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[4], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[8], 435, 310); // re-start game button
    vg_render_sprite(game_assets->buttons[5], 367, 470); // change game mode button
    vg_render_sprite(game_assets->buttons[6], 490, 628); // end game button

    return EXIT_SUCCESS;
}

/* GAME WINDOW */

int gui_game_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state)
{

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[3], 0, 0);

    // BTNS
    vg_render_sprite(game_assets->buttons[7], 0, 0); // in-game menu button

    // BORDERS
    vg_render_sprite(game_assets->borders[0], 221, 591); // left player border
    vg_render_sprite(game_assets->borders[1], 1059, 0);  // right player border

    // LOGOS
    vg_render_sprite(game_assets->logos[game_state->p1_house], 32, 806);      // player 1 house logo
    vg_render_sprite(game_assets->logos[game_state->p2_house], 1136, 239); // player 2 house logo

    //
    // Game Logic To implement
    //

    /* TIMERS */

    /* PIECES */

    // WHITE
    vg_render_sprite(game_assets->pieces[0], 347, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 422, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 496, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 570, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 644, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 718, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 792, 661); // pawn
    vg_render_sprite(game_assets->pieces[0], 865, 661); // pawn
    vg_render_sprite(game_assets->pieces[1], 496, 734); // left bishop
    vg_render_sprite(game_assets->pieces[1], 718, 734); // right bishop
    vg_render_sprite(game_assets->pieces[2], 422, 734); // left horse
    vg_render_sprite(game_assets->pieces[2], 792, 734); // right horse
    vg_render_sprite(game_assets->pieces[3], 347, 734); // left rook
    vg_render_sprite(game_assets->pieces[3], 865, 734); // right rook
    vg_render_sprite(game_assets->pieces[4], 570, 734); // queen
    vg_render_sprite(game_assets->pieces[5], 644, 734); // king

    // BLACK
    vg_render_sprite(game_assets->pieces[6], 347, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 422, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 496, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 570, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 644, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 718, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 792, 291);  // pawn
    vg_render_sprite(game_assets->pieces[6], 865, 291);  // pawn
    vg_render_sprite(game_assets->pieces[7], 496, 220);  // left bishop
    vg_render_sprite(game_assets->pieces[7], 718, 220);  // right bishop
    vg_render_sprite(game_assets->pieces[8], 422, 220);  // left horse
    vg_render_sprite(game_assets->pieces[8], 792, 220);  // right horse
    vg_render_sprite(game_assets->pieces[9], 347, 220); // left rook
    vg_render_sprite(game_assets->pieces[9], 865, 220); // right rook
    vg_render_sprite(game_assets->pieces[10], 570, 220); // queen
    vg_render_sprite(game_assets->pieces[11], 644, 220); // king

    return EXIT_SUCCESS;
}

/* GAME MODE SELECTION */

int gui_game_mode_sel_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state)
{

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    return EXIT_SUCCESS;
}

/* CHARACTER SELECTION */

int gui_char_sel_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state)
{

    /* RENDER VISUALS */

    vg_init(VBE_MODE_11BH);
    vg_reset_frame();

    // BG
    vg_render_sprite(game_assets->backgrounds[2], 0, 0);

    // CHARACTERS

    // 1.) Godric
    vg_render_sprite(game_assets->characters[0], 0, 63);    // character sprite
    vg_render_sprite(game_assets->characters[1], 349, 143); // character name

    // 2.) Helga
    vg_render_sprite(game_assets->characters[2], 0, 574);   // character sprite
    vg_render_sprite(game_assets->characters[3], 349, 821); // character name

    // 3.) Rowena
    vg_render_sprite(game_assets->characters[4], 960, 574); // character sprite
    vg_render_sprite(game_assets->characters[5], 753, 821); // character name

    // 4.) Salazar
    vg_render_sprite(game_assets->characters[6], 960, 63);  // character sprite
    vg_render_sprite(game_assets->characters[7], 753, 143); // character name

    return EXIT_SUCCESS;
}


