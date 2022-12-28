/**
 * ----------------------------------------------
 *                   moveset.c
 * ----------------------------------------------
 * 
 * Encoding of a moveset which is given to a piece
 */


#include "moveset.h"


/**
 * Return the movemap corresponding to the good team
 * @param _set The moveset of a piece type
 * @param _team The team of the piece
 * @return The corresponding movemap
 */
MoveMap getMoveMap(Moveset _set, char _team) {
    if (_team) {
        return _set->first_team;
    } else {
        return _set->second_team;
    }
}