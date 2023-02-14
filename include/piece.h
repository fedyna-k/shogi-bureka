/**
 * ----------------------------------------------
 *                     piece.h
 * ----------------------------------------------
 * 
 * Encoding for the piece.
 */


#ifndef __PIECE_H__
#define __PIECE_H__


// ----- Dependancy -----


#include <SDL.h>
#include <stdlib.h>
#include "bool.h"
#include "string.h"
#include "movemap.h"
#include "moveset.h"


// ----- Constants and structs -----


struct __s_Piece {
    String name;
    SDL_Texture *texture;
    Bool team;
    Bool is_promoted;
    Position position;
    Moveset moveset;
    int value;
};

typedef struct __s_Piece * Piece;


// ----- Functions -----

void copyPiece(Piece _dest, Piece _src);

#endif