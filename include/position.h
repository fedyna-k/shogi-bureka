/**
 * ----------------------------------------------
 *                  position.h
 * ----------------------------------------------
 * 
 * Encoding and function for positions in-game.
 */


#ifndef __POSITION_H__
#define __POSITION_H__


// ----- Dependancy -----


#include "direction.h"
#include "bool.h"


// ----- Constants and structs -----


typedef char Position;


// ----- Functions -----


Bool isValidPosition(Position _new);
char getX(Position _pos);
char getY(Position _pos);
Position nextPosition(Position _old, Direction _direction);


#endif