/**
 * ----------------------------------------------
 *                     piece.h
 * ----------------------------------------------
 * 
 * Encoding for the piece.
 */


#ifndef __BOARD_H__
#define __BOARD_H__


// ----- Dependancy -----


#include <SDL.h>
#include "piece.h"
#include "move.h"
#include "bigint.h"
#include "stack.h"
#include "constants.h"


// ----- Constants and structs -----

struct __s_Board {
    Piece * board_piece;
    List first_player_hand;
    List second_player_hand;
    double score;
    BigInt hash_key;
    Bool team;
};

typedef struct __s_Board * Board;


// ----- Functions -----


Board createNewBoard();
Board copyBoard(Board board);
void freeBoard(Board board);
Board makeMove(Board board, Move move);
void generatePiece(char _symbol, Piece _piece, SDL_Texture **_textures, Bool _is_promoted);
void initBoard(Board _board, SDL_Texture **_textures, String _SFEN);


#endif