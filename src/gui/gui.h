#pragma once

#include "../libs/game/game_structures.h"
#include "../libs/game/game_funcs.h"

#include "../libs/modules/timer/timer.h"
#include "../libs/modules/keyboard/keyboard.h"
#include "../libs/modules/mouse/mouse.h"
#include "../libs/modules/gpu/videographic.h"


int gui_start_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state);

int gui_main_menu(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state);

int gui_in_game_menu(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state);

int gui_game_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state);

int gui_game_mode_sel_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state);

int gui_char_sel_window(struct GAME_ASSETS *game_assets, struct GAME_STATE *game_state);

