#ifndef __PIECE_H__
#define __PIECE_H__

#include "string.h"

typedef char Position;

typedef struct zPiece {
    String name;
    char team;
    Position position;
    Moveset moveset;
} Piece;

#endif