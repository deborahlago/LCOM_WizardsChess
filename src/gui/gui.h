#pragma once

int gui_start_window(GAME_ASSETS *game_assets);

int gui_main_menu(GAME_ASSETS *game_assets);

int gui_in_game_menu(GAME_ASSETS *game_assets);

int gui_game_window(GAME_ASSETS *game_assets, GAME_HOUSES p1_house, GAME_HOUSES p2_house, uint8 x_pos[], uint8 y_pos[]);

int gui_game_mode_sel_window(GAME_ASSETS *game_assets);

int gui_char_sel_window(GAME_ASSETS *game_assets);