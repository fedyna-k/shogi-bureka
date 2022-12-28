/**
 * ----------------------------------------------
 *                     move.c
 * ----------------------------------------------
 * 
 * Encoding of a move as a simple struct storing
 * two positions. Allows to pass which move to
 * do for the AI.
 */


#include <stdio.h>
#include <stdlib.h>
#include "move.h"
#include "position.h"


/**
 * Create a Move object and return it
 * @param _start The starting square of the move
 * @param _end The ending square of the move
 * @return The new move initialized
 * 
 * @example
 * createMove(42, 33) // returns the corresponding Move object
 */
Move createMove(Position _start, Position _end) {
    Move new_move;
    new_move.starting_square = _start;
    new_move.ending_square = _end;
    
    return new_move;
}