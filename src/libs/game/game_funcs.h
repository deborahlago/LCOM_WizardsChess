#pragma once

#include "game_structures.h"

#include "../modules/gpu/videographic.h"
#include "../modules/mouse/mouse.h"
#include "../modules/timer/timer.h"
#include "../modules/keyboard/keyboard.h"
#include "../modules/rtc/RTC.h"



int game_load_assets(GAME_ASSETS* game_assets);

int game_run(GAME_ASSETS* game_assets, GAME_STATE* game_state);