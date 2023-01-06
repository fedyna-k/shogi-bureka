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
    // 1D array representing the board
    Piece * board_piece;
    // Lists of player's pieces
    List first_player_hand;
    List second_player_hand;
    // Score
    double score;
    // Hashkey
    BigInt hash_key;
    // Boolean indicating the team currently playing : 0 for player 1, 1 for player 2
    Bool team;
    // Binary numbers of BOARD_LENGTH bits. 1 means a pawn is in the column of the bit i, 0 means there is no pawn
    int first_player_pawn;
    int second_player_pawn;
};

typedef struct __s_Board * Board;


// ----- Functions -----


Board createNewBoard();
Board copyBoard(Board board);
void freeBoard(Board board);
void makeMove(Board board, Move move);
void dropPiece(Board board, Move move, Piece piece);
Bool canDropAt(Board board, Piece piece, Position position);
void generatePiece(char _symbol, Piece _piece, SDL_Texture **_textures, Bool _is_promoted);
void initBoard(Board _board, SDL_Texture **_textures, String _SFEN);


#endif