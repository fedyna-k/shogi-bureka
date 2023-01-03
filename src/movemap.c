/**
 * ----------------------------------------------
 *                   movemap.c
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


#include "movemap.h"
#include <assert.h>


/**
 * Check if the piece can move at the given position
 * @param _map The movemap associated with the piece
 * @param _position The current position of the piece
 */
Bool canMoveAt(MoveMap _map, Position _position){
    return _map[_position] != NULL;
}


/**
 * Get the moves given 
 */
MoveCollection getMovesAt(MoveMap _map, Position _position){
    assert(canMoveAt(_map, _position));
    return _map[_position];
}