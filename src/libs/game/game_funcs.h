#pragma once

/** @defgroup game functions
 * @{
 *
 * Functions for game logic and interface
 */

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
int game_load_assets(struct GAME_ASSETS* game_assets);


/**
 * @brief TODO
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @param game_state state machine containing all current game states
 *
 * @return Zero on success, non-zero otherwise
 */
int game_run(struct GAME_ASSETS* game_assets, struct GAME_STATE* game_state);

