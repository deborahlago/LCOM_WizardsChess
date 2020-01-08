#pragma once



/** @defgroup gui gui
 * @{
 *
 * Functions for graphical user interface rendering
 */


#include <lcom/lcf.h>

#include "../libs/game/game_structures.h"
#include "../libs/game/game_funcs.h"

#include "../libs/modules/timer/timer.h"
#include "../libs/modules/keyboard/keyboard.h"
#include "../libs/modules/mouse/mouse.h"
#include "../libs/modules/gpu/videographic.h"

/**
 * @brief Renders the game's initial window and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_start_window(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Renders the game's main menu screen and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_main_menu(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Renders the game's in game menu screen and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_in_game_menu(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Renders the game window and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_game_window(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Renders the game's game mode selection window and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_game_mode_sel_window(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Renders the game's character selection window and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_char_sel_window(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Renders the game's victory screen and all of its elements
 *
 * @param game_assets structure that contains all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
int gui_victory_screen(game_assets_t* game_assets, game_state_t* game_state);

