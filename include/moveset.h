/**
 * ----------------------------------------------
 *                   moveset.h
 * ----------------------------------------------
 * 
 * Encoding of a moveset which is given to a piece
 */


#ifndef __MOVESET_H__
#define __MOVESET_H__


// ----- Dependancy -----


#include "movemap.h"
#include "position.h"


// ----- Constants and structs -----


struct __s_Moveset {
    char direction_number;
    MoveMap first_team;
    MoveMap second_team;
};

typedef struct __s_Moveset *Moveset;


// ----- Functions -----


MoveMap getMoveMap(Moveset _set, char _team);


#endif