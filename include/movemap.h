/**
 * ----------------------------------------------
 *                   movemap.h
 * ----------------------------------------------
 * 
 * Encoding of a movemap for a given piece in a
 * given team
 * 
 * A movemap is a 2D array of lists that can
 * access positions given the following pattern :
 *
 *  MOVEMAP[start][direction_index] = first_move
 *  first_move->next = NULL <=> plus de mouvments
 * 
 * If a piece has no movement at a given position
 * We store a NULL pointer in MOVEMAP[start].
 */


#ifndef __MOVEMAP_H__
#define __MOVEMAP_H__


// ----- Dependancy -----


#include <stdio.h>
#include "bool.h"
#include "position.h"
#include "lists.h"


// ----- Constants and structs -----


typedef List **MoveMap;
typedef List *MoveCollection;


// ----- Functions -----


Bool canMoveAt(MoveMap _map, Position _position);
MoveCollection getMovesAt(MoveMap _map, Position _position);

#endif