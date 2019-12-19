#pragma once

#include "../libs/game/game_structures.h"

int gui_start_window(struct GAME_ASSETS *game_assets);

int gui_main_menu(struct GAME_ASSETS *game_assets);

int gui_in_game_menu(struct GAME_ASSETS *game_assets);

int gui_game_window(struct GAME_ASSETS *game_assets, enum GAME_HOUSES p1_house, enum GAME_HOUSES p2_house, uint8_t x_pos[], uint8_t y_pos[]);

int gui_game_mode_sel_window(struct GAME_ASSETS *game_assets);

int gui_char_sel_window(struct GAME_ASSETS *game_assets);

