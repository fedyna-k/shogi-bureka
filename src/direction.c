/**
 * ----------------------------------------------
 *                  direction.c
 * ----------------------------------------------
 * 
 * Add direction handling
 */


#include "direction.h"
#include "constants.h"


/**
 * Get the integer representing the total offset
 * of a direction
 * @param _direction The direction object
 * @return An index describing the move
 */
char getTotalOffset(Direction _direction) {
    return _direction.dx + _direction.dy * BOARD_LENGTH;
}