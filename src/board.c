/**
 * ----------------------------------------------
 *                  board.c
 * ----------------------------------------------
 * 
 * define the function for the board of the game
 */

#include "board.h"

Board createNewBoard(){
    Board res;
    res.board_piece = malloc(sizeof(Piece) * BOARD_SIZE);
    res.first_player_hand = createEmptyList();
}