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
 * @brief Loads all game sprites into game_assets object
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @return Zero on success, non-zero otherwise
 */
int game_load_assets(game_assets_t* game_assets);

/**
 * @brief Initializes all game data
 *
 * @param game game structure containing all game data and states
 */
void game_data_init(game_state_t* game);

/**
 * @brief Updates the position of mouse cursor
 *
 * @param game_state current state of game data
 */
void game_update_cursor(game_state_t* game_state);

/**
 * @brief Handles and updates the latest mouse event
 *
 * @param pkt latest assembled mouse packet
 *
 * @param game_state current state of game data
 *
 * @return Returns the update mouse event struct
 */
struct mouse_event game_mouse_ev_handler(struct packet* pkt, game_state_t* game_state);

/**
 * @brief Checks if a game element (i.e. a button or an interactable) has been clicked on
 *
 * @param game_sprite Element to be clicked
 *
 * @param game_state current state of game data, used to get the state of current mouse position
 *
 * @return Returns true if click happened within the element's area, otherwise returns false
 */
_Bool game_elem_clicked(sprite_t game_sprite, game_state_t* game_state);

/**
 * @brief Checks if a game piece has been clicked on
 *
 * @param game_piece Game piece to check click
 *
 * @param game_sprite sprite of the piece to check width and height
 *
 * @param game_state current state of game data, used to get the state of current mouse position
 *
 * @return Returns true if click happened within the element's area, otherwise returns false
 */
_Bool game_piece_clicked(game_piece_t* game_piece,  sprite_t game_sprite, game_state_t* game_state);

/**
 * @brief Updates the start position of every piece in the game board
 *
 * @param game_state Current state of game data. Used to get each pieces start and current position
 */
void game_update_pieces_start_pos(game_state_t* game_state);

/**
 * @brief Checks whether current mouse position is within a boar cell area
 *
 * @param game_state current state of game data
 *
 * @return Returns true if mouse position is within cell, false otherwise
 */
_Bool game_mouse_within_cell(game_state_t* game_state, board_cell_t* board_cell);

/**
 * @brief Checks whether straight movement has occurred upon pawn or king movement attempt
 *
 * @param game_state current state of game data
 *
 * @param game_piece piece to be moved
 *
 * @param board_cell cell of the board to where pawn is to attempt movement
 *
 * @return Returns true if straight movement has occurred , false otherwise
 */
_Bool game_straight_movement_one_cell(game_piece_t* game_piece, board_cell_t* board_cell);

/**
 * @brief Checks whether diagonal movement has occurred upon pawn or king movement attempt
 *
 * @param game_state current state of game data
 *
 * @param game_piece piece to be moved
 *
 * @param board_cell cell of the board to where pawn is to attempt movement
 *
 * @return Returns true if straight movement has occurred , false otherwise
 */
_Bool game_diagonal_movement_one_cell(game_piece_t* game_piece, board_cell_t* board_cell);

/**
 * @brief Checks whether pawn movement was valid
 *
 * @param game_state current state of game data
 *
 * @param game_piece Game piece to be moved
 *
 * @param new_pos Address of temporary board cell that is to store the new render start positions
 *
 * @param board_cell cell to move piece to
 *
 * @return Returns true if position is valid, false otherwise
 */
_Bool game_valid_movement(game_state_t* game_state, game_piece_t* game_piece, board_cell_t* new_pos, board_cell_t* board_cell);

/**
 * @brief Checks whether the piece's new position is a valid one
 *
 * @param game_state current state of game data
 *
 * @param game_piece Game piece to be moved
 *
 * @param new_pos Address of temporary board cell that is to store the new render start positions
 *
 * @return Returns true if position is valid, false otherwise
 */
_Bool game_valid_move(game_state_t* game_state, game_piece_t* game_piece, board_cell_t* new_pos);

/**
 * @brief Drags piece around the board updating game piece position upon position movement
 *
 * @param game_state current state of game data
 *
 * @param game_piece Game piece to be moved
 */
void game_drag_piece(game_state_t* game_state, game_piece_t* game_piece);

/**
 * @brief Drops piece in a game cell if it is a valid one
 *
 * @param game_piece Game piece to be moved
 *
 */
void game_drop_piece(game_state_t* game_state, game_piece_t* game_piece);

/**
 * @brief Updates the current state of the game
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @param game_state current state of game data
 */
void game_update_state(game_assets_t* game_assets, game_state_t* game_state);

/**
 * @brief Main game loop. Handles interrupts and calls for game updates
 *
 * @param game_assets structure to contain all the loaded assets of the game
 *
 * @param game_state current state of game data
 *
 * @return Zero on success, non-zero otherwise
 */
int game_run(game_assets_t* game_assets, game_state_t* game_state);

