#pragma once

/** @defgroup game functions
 * @{
 *
 * Functions for game logic and interface
 */

#include <lcom/lcf.h>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "game_structures.h"
#include "../../gui/gui.h"

#include "../modules/gpu/videographic.h"
#include "../modules/mouse/mouse.h"
#include "../modules/timer/timer.h"
#include "../modules/keyboard/keyboard.h"
#include "../modules/rtc/RTC.h"



/**
 * @brief TODO
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @return Zero on success, non-zero otherwise
 */
int game_load_assets(game_assets_t* game_assets);

/**
 * @brief Update the position of mouse cursor
 *
 * @param game_assets structure to contain all the loaded assets of the game
 */
void game_update_cursor(game_state_t* game_state);

/**
 * @brief Updates the current state of the game
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @param game_state state machine containing all current game states
 */
void game_update_state(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Main game loop. Handles interrupts and calls for game updates
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @param game_state state machine containing all current game states
 *
 * @return Zero on success, non-zero otherwise
 */
int game_run(game_assets_t* game_assets, game_state_t* game_state);

