/**
 * ----------------------------------------------
 *                     move.h
 * ----------------------------------------------
 * 
 * Encoding of a move as a simple struct storing
 * two positions. Allows to pass which move to
 * do for the AI.
 */


#ifndef __MOVE_H__
#define __MOVE_H__


// ----- Dependancy -----


#include "position.h"


// ----- Constants and structs -----


#define MOVE_SIZE sizeof(struct __s_Move)

struct __s_Move {
    Position starting_square;
    Position ending_square;
};

typedef struct __s_Move *Move;


// ----- Functions -----


Move createMove(Position _start, Position _end);


#endif