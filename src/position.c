/**
 * ----------------------------------------------
 *                  position.c
 * ----------------------------------------------
 * 
 * Encoding and function for positions in-game.
 */


#include "position.h"
#include "constants.h"


/**
 * Check if a position is in board
 * @param _new The new position to test
 * @return A bool telling if the position is in board
 */
Bool isValidPosition(Position _new) {
    return _new >= 0 && _new < BOARD_SIZE;
}


/**
 * Gets the X coordinate of a position
 * @param _pos The position
 * @return The X coordinate 
 */
char getX(Position _pos) {
    return _pos % BOARD_LENGTH;
}


/**
 * Gets the Y coordinate of a position
 * @param _pos The position
 * @return The Y coordinate 
 */
char getY(Position _pos) {
    return _pos / BOARD_LENGTH;
}


/**
 * Compute the next position given a direction
 * If the next position is not valid, return -1
 * @param _old The starting square
 * @param _direction The direction given to the function
 * @return The new square index, -1 if not valid
 */
Position nextPosition(Position _old, Direction _direction) {
    Position next = _old + getTotalOffset(_direction);
    char dx, dy;

    // return -1 if the position is not valid
    if (!isValidPosition(next)) {
        return -1;
    }

    // Quick check on positions to make sure
    // we did not abuse torus topology
    dx = getX(next) - getX(_old);
    dy = getY(next) - getY(_old);
    if (dx != _direction.dx || dy != _direction.dy) {
        return -1;
    }

    return next;
}