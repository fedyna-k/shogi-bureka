#ifndef __MOVEMAP_H__
#define __MOVEMAP_H__

#include "moveset.h"
#include "bool.h"
#include "position.h"
#include "listes.h"

typedef char *** MoveMap;
typedef char Moveset;

Bool canMoveAt(MoveMap map, Position position);
List getMovesAt(MoveMap map, Position position);

#endif