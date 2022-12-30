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


#include "string.h"
#include "movemap.h"
#include "moveset.h"


// ----- Constants and structs -----


struct __s_Piece {
    String name;
    char team;
    Position position;
    Moveset moveset;
};

typedef struct __s_Piece Piece;


// ----- Functions -----


String getImageLink(Piece _piece, char _option);


#endif