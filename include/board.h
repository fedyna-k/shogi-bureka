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


#endif