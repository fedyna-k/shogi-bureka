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


int getNumberDirections(String piece_name){
    if (isEqualString(piece_name, setString("Pion"))){
        return DIRECTION_COUNT_PAWN;
    }
    if (isEqualString(piece_name, setString("Pion d'or")) || isEqualString(piece_name, setString("Lancier d'or"))
        || isEqualString(piece_name, setString("General d'or")) || isEqualString(piece_name, setString("Cavalier d'or"))
        || isEqualString(piece_name, setString("General d'argent d'or"))) {
        return DIRECTION_COUNT_GOLDEN;
    }
    if (isEqualString(piece_name, setString("Cavalier"))) {
        return DIRECTION_COUNT_KNIGHT;
    }
    if (isEqualString(piece_name, setString("Tour"))) {
        return DIRECTION_COUNT_ROOK;
    }
    if (isEqualString(piece_name, setString("Fou"))) {
        return DIRECTION_COUNT_BISHOP;
    }
    if (isEqualString(piece_name, setString("Dragon"))) {
        return DIRECTION_COUNT_DRAGON;
    }
    if (isEqualString(piece_name, setString("Horse"))) {
        return DIRECTION_COUNT_HORSE;
    }
    if (isEqualString(piece_name, setString("Roi"))){
        return DIRECTION_COUNT_KING;
    }
}

/* Returns an array with the directions in which the piece passed in parameters can move (no mater its position)
    The directions start from the top-left and turn clockwise
*/
Direction * getDirections(int team, String piece_name){
    Direction * directions;
    if (team == 1){
        // Pawn an Lance can only move forward
        if (isEqualString(piece_name, setString("Pion")) || isEqualString(piece_name, setString("Lancier"))){
            directions = malloc(DIRECTION_COUNT_PAWN * sizeof(Direction));
            directions[0] = TOP;
            return directions;
        }
        // Golden pieces
        if (isEqualString(piece_name, setString("Pion d'or")) || isEqualString(piece_name, setString("Lancier d'or"))
            || isEqualString(piece_name, setString("General d'or")) || isEqualString(piece_name, setString("Cavalier d'or"))
            || isEqualString(piece_name, setString("General d'argent d'or"))) {
            directions = malloc(DIRECTION_COUNT_GOLDEN * sizeof(Direction));
            directions[0] = TOP_LEFT;
            directions[1] = TOP;
            directions[2] = TOP_RIGHT;
            directions[3] = RIGHT;
            directions[4] = BOTTOM;
            directions[5] = LEFT;
            return directions;
        }
        // Knight
        if (isEqualString(piece_name, setString("Cavalier"))){
            directions = malloc(DIRECTION_COUNT_KNIGHT * sizeof(Direction));
            directions[0] = KNIGHT_TL;
            directions[1] = KNIGHT_TR;
            return directions;
        }
        // Rook
        if (isEqualString(piece_name, setString("Tour"))){
            directions = malloc(DIRECTION_COUNT_ROOK * sizeof(Direction));
            directions[0] = TOP;
            directions[2] = RIGHT;
            directions[3] = BOTTOM;
            directions[4] = LEFT;
            return directions;
        }
        // Bishop
        if (isEqualString(piece_name, setString("Fou"))){
            directions = malloc(DIRECTION_COUNT_BISHOP * sizeof(Direction));
            directions[0] = TOP_LEFT;
            directions[1] = TOP_RIGHT;
            directions[2] = BOTTOM_RIGHT;
            directions[3] = BOTTOM_LEFT;
            return directions;
        }
        // Dragon
        if (isEqualString(piece_name, setString("Dragon"))){
            directions = malloc(DIRECTION_COUNT_DRAGON * sizeof(Direction));
            directions[0] = TOP_LEFT;
            directions[1] = TOP;
            directions[2] = TOP_RIGHT;
            directions[3] = RIGHT;
            directions[4] = BOTTOM_RIGHT;
            directions[5] = BOTTOM;
            directions[6] = BOTTOM_LEFT;
            directions[7] = LEFT;
            return directions;
        }
        // Horse
        if (isEqualString(piece_name, setString("Horse"))){
            directions = malloc(DIRECTION_COUNT_HORSE * sizeof(Direction));
            directions[0] = TOP_LEFT;
            directions[1] = TOP;
            directions[2] = TOP_RIGHT;
            directions[3] = RIGHT;
            directions[4] = BOTTOM_RIGHT;
            directions[5] = BOTTOM;
            directions[6] = BOTTOM_LEFT;
            directions[7] = LEFT;
            return directions;
        }
        // King
        if (isEqualString(piece_name, setString("Roi"))){
            directions = malloc(DIRECTION_COUNT_KING * sizeof(Direction));
            directions[0] = TOP_LEFT;
            directions[1] = TOP;
            directions[2] = TOP_RIGHT;
            directions[3] = RIGHT;
            directions[4] = BOTTOM_RIGHT;
            directions[5] = BOTTOM;
            directions[6] = BOTTOM_LEFT;
            directions[7] = LEFT;
            return directions;
        }
    }
}

// Generate the MoveMap of the piece in the team passed in parameters
MoveMap generateMoveMap(int team, String piece_name){
    // Initialisation of Movemap (empty array of *Lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(List *));
    // Empty array to temporarly put positions to put them in the right order in lists
    int * tmp = malloc(BOARD_LENGTH * sizeof(int));
    int position, i, dir_index, tmp;
    Direction * directions = getDirections(team, piece_name);
    int num_directions = getNumberDirections(piece_name);

    if (!(isEqualString(piece_name, setString("Dragon")) || isEqualString(piece_name, setString("Horse")))){
        for (position = 0; position < BOARD_SIZE; position++){
            // Create lists of all moves. 1 list = 1 direction
            movemap[position] = malloc(num_directions * sizeof(List));
            i = 0;
            while (i < num_directions) {
                // Create the list of mouvements in the ith direction
                movemap[position][i] = createEmptyList();
                dir_index = directions[i].dx  + directions[i].dy * BOARD_LENGTH;
                tmp = position + dir_index;
                if (isEqualString(piece_name, setString("Tour")) || isEqualString(piece_name, setString("Fou"))) {
                    while (tmp >= 0 && tmp < BOARD_SIZE){
                        movemap[position][i] = addList(tmp, movemap[position]);
                        tmp += dir_index;
                    }
                }
                else{
                    if (tmp >= 0 && tmp < BOARD_SIZE){
                        movemap[position][i] = addList(tmp, movemap[position]);
                    }
                }
                
                
                i++;
            }
        }
    }
    else{
        for (position = 0; position < BOARD_SIZE; position++){
            // Create lists of all moves. 1 list = 1 direction
            movemap[position] = malloc(num_directions * sizeof(List));
            i = 0;
            while (i < num_directions) {
                // Create the list of mouvements in the ith direction
                movemap[position][i] = createEmptyList();
                dir_index = directions[i].dx  + directions[i].dy * BOARD_LENGTH;
                tmp = position + dir_index;

                if (isEqualString(piece_name, setString("Dragon")) && (i % 2) == 0) {
                    while (tmp >= 0 && tmp < BOARD_SIZE){
                        movemap[position][i] = addList(tmp, movemap[position]);
                        tmp += dir_index;
                    }
                }
                else {
                    if (isEqualString(piece_name, setString("Horse")) && (i % 2) != 0) {
                        while (tmp >= 0 && tmp < BOARD_SIZE){
                            movemap[position][i] = addList(tmp, movemap[position]);
                            tmp += dir_index;
                        }
                    }
                    else {
                        if (tmp >= 0 && tmp < BOARD_SIZE){
                            movemap[position][i] = addList(tmp, movemap[position]);
                        }
                    }
                }
                
                
                i++;
            }
        }
    }
}