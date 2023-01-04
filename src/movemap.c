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

// Returns an array with the directions in which the piece passed in parameters can move (no mater its position)
Direction * getDirections(int team, String piece_name){
    Direction * directions;
    if (team == 0){
        if (isEqualString(piece_name, setString("Roi"))){
            directions = malloc(DIRECTION_COUNT_KING * sizeof(Direction));
            directions[0] = TOP_LEFT;
            directions[1] = TOP;
            directions[2] = TOP_RIGHT;
            // A CONTINUER -------------------------------------------------------------
            // ---------------------------------------------------------------------------
        }
    }
}

// Generate the MoveMap of the piece in the team passed in parameters
MoveMap generateMoveMap(int team, String piece_name){
    // Initialisation of Movemap (empty array of *Lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(List *));
    // Empty array to temporarly put positions to put them in the right order in lists
    int * tmp = malloc(BOARD_LENGTH * sizeof(int));
    int position;

    for (position = 0; position < BOARD_SIZE; position++){
        // TO DO
    }
}