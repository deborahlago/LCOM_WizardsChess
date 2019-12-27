#pragma once

#include <lcom/lcf.h>

#include "../libs/game/game_structures.h"
#include "../libs/game/game_funcs.h"

#include "../libs/modules/timer/timer.h"
#include "../libs/modules/keyboard/keyboard.h"
#include "../libs/modules/mouse/mouse.h"
#include "../libs/modules/gpu/videographic.h"


int gui_start_window(game_assets_t* game_assets, game_state_t* game_state);

int gui_main_menu(game_assets_t* game_assets, game_state_t* game_state);

int gui_in_game_menu(game_assets_t* game_assets, game_state_t* game_state);

int gui_game_window(game_assets_t* game_assets, game_state_t* game_state);

int gui_game_mode_sel_window(game_assets_t* game_assets, game_state_t* game_state);

int gui_char_sel_window(game_assets_t* game_assets, game_state_t* game_state);

