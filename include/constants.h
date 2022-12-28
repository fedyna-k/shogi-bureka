/**
 * ----------------------------------------------
 *                   constants.h
 * ----------------------------------------------
 * 
 * All constants are defined in this header file.
 * 
 * You may include this file in every source file
 * that uses these constants in order to make the
 * code more readable and easier to change.
 */


#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__


// ----- Board constants -----


#define BOARD_LENGTH    9
#define BOARD_SIZE      81


// ----- Sprites -----


#define SPRITE_DIRECTORY    "sprites"
#define CHESS_SPRITES       "chess-like"
#define JAPANESE_SPRITES    "japanese"


// ----- Pieces -----


#define DIRECTION_NUMBER    8
#define MAX_SLIDING_LENGTH  9

/**
 * Movement type count :
 * - King   : 8
 * - Bishop : 4
 * - Rook   : 4
 * - Horse  : 8
 * - Dragon : 8
 * - Golden : 6
 * - Silver : 5
 * - Knight : 2
 * - Lance  : 1
 * - Pawn   : 1
 */
#define MOVEMENT_TYPE_COUNT 10

/**
 * King :
 * x x x
 * x A x
 * x x x
 */
#define DIRECTION_COUNT_KING    8

/**
 * Bishop :
 * \ . /
 * . A .
 * / . \
 */
#define DIRECTION_COUNT_BISHOP  4

/**
 * Rook :
 * . | .
 * - A -
 * . | .
 */
#define DIRECTION_COUNT_ROOK    4

/**
 * Horse :
 * \ x /
 * x A x
 * / x \
 */
#define DIRECTION_COUNT_HORSE   8

/**
 * Dragon :
 * x | x
 * - A -
 * x | x
 */
#define DIRECTION_COUNT_DRAGON  8

/**
 * Golden :
 * x x x
 * x A x
 * . x .
 */
#define DIRECTION_COUNT_GOLDEN  6

/**
 * Silver :
 * x x x
 * . A .
 * x . x
 */
#define DIRECTION_COUNT_SILVER  5

/**
 * Knight :
 * o . o
 * . . .
 * . A .
 */
#define DIRECTION_COUNT_KNIGHT  2

/**
 * Lance :
 * . | .
 * . A .
 * . . .
 */
#define DIRECTION_COUNT_LANCE   1

/**
 * Pawn :
 * . x .
 * . A .
 * . . .
 */
#define DIRECTION_COUNT_PAWN    1


#endif