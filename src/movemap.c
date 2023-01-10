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
    return _map[(int)_position] != NULL;
}


/**
 * Get the moves given 
 */
MoveCollection getMovesAt(MoveMap _map, Position _position){
    assert(canMoveAt(_map, _position));
    return _map[(int)_position];
}


/*
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
/*
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
*/

// Movemap rewritten :
// 1 Movemap per piece -------------------------------------------------

/**
 * Get the movemap of Pawns
 * @param team - The team of pawns
*/
MoveMap getPawnMovemap(int team){
    Position position;
    Position next;
    Direction direction;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    if (team == 0) {
        direction = BOTTOM;
    }
    else{
        direction = TOP;
    }

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_PAWN * sizeof(List));
        movemap[position] = createEmptyList();

        // Set the position to test
        next = nextPosition(position, BOTTOM);
        // Adds the position to the list if it exists
        if (next != -1){
            movemap[position] = addList((Variant)next, movemap[position]);
        }
    }

    return movemap;
}

/**
 * Get the movemap of Kings
*/
MoveMap getKingMovemap() {
    Position position;
    Position next;
    Direction directions[DIRECTION_COUNT_KING] = {TOP_LEFT, TOP, TOP_RIGHT, RIGHT, BOTTOM_RIGHT, BOTTOM, BOTTOM_LEFT, LEFT};
    int i;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_KING * sizeof(List));
        
        for (i = 0; i < 8; i++){
            movemap[position][i] = createEmptyList();
            next = nextPosition(position, directions[i]);
            if (next != -1) {
                movemap[position] = addList((Variant)next, movemap[position][i]);
            }
        }
    }

    return movemap;
}

/**
 * Get the movemap of the Knight
 * @param team - The team of the knight
*/
MoveMap getKnightMovemap(int team) {
    Position position;
    Position next;
    int i;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_KNIGHT * sizeof(List));
        
        if (team == 0) {
            movemap[position][0] = createEmptyList();
            next = nextPosition(position, KNIGHT_BL);
            if (next != -1){
                movemap[position] = addList((Variant)next, movemap[position][0]);
            }
            movemap[position][1] = createEmptyList();
            next = nextPosition(position, KNIGHT_BR);
            if (next != -1){
                movemap[position] = addList((Variant)next, movemap[position][1]);
            }
        }
        else{
            movemap[position][0] = createEmptyList();
            next = nextPosition(position, KNIGHT_TL);
            if (next != -1){
                movemap[position] = addList((Variant)next, movemap[position][0]);
            }
            movemap[position][1] = createEmptyList();
            next = nextPosition(position, KNIGHT_TR);
            if (next != -1){
                movemap[position] = addList((Variant)next, movemap[position][1]);
            }
        }
    }

    return movemap;
}

/**
 * Get the movemap of Lance
 * @param team - The team of lance
*/
MoveMap getLanceMovemap(int team){
    Position position, next;
    Direction direction;
    Position tmp_tab_positions[BOARD_LENGTH]; // array to stock positions to reverse the order in the list
    int counter;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    // Define the direction in which the lance moves
    if (team == 0) {
        direction = TOP;
    }
    else{
        direction = BOTTOM;
    }

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_LANCE * sizeof(List));
        movemap[position] = createEmptyList();

        // Fill the tmp array
        counter = 0;
        next = nextPosition(position, direction);
        while (counter < BOARD_LENGTH || next != -1) {
            tmp_tab_positions[counter] = next;
            counter++;
            next = nextPosition(next, direction);
        }

        // Fill the list
        while (counter >= 0) {
            movemap[position] = addList(tmp_tab_positions[counter], movemap[position]);
            counter--;
        }
    }

    return movemap;
}

/**
 * Get the movemap of Bishops
*/
MoveMap getBishopMovemap() {
    Position position;
    Position next;
    Direction directions[DIRECTION_COUNT_BISHOP] = {TOP_LEFT, TOP_RIGHT, BOTTOM_RIGHT, BOTTOM_LEFT};
    int i;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(List*));

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_BISHOP * sizeof(List));
        
        // Each direction
        i = 0;
        while (i < 4) {
            movemap[position][i] = createEmptyList();
            next = nextPosition(position, directions[i]);
            // Explore the direction until it gets out of the board
            while (next != -1) {
                movemap[position][i] = addList(next, movemap[position][i]);
                next = nextPosition(next, directions[i]);
            }
            i++;
        }
    }

    return movemap;
}

/**
 * Get the movemap of Rooks
*/
MoveMap getRookMovemap() {
    Position position;
    Position next;
    Direction directions[DIRECTION_COUNT_ROOK] = {TOP, RIGHT, BOTTOM, LEFT};
    int i;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(List*));

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_ROOK * sizeof(List));
        
        // Each direction
        i = 0;
        while (i < 4) {
            movemap[position][i] = createEmptyList();
            next = nextPosition(position, directions[i]);
            // Explore the direction until it gets out of the board
            while (next != -1) {
                movemap[position][i] = addList(next, movemap[position][i]);
                next = nextPosition(next, directions[i]);
            }
            i++;
        }
    }

    return movemap;
}

/**
 * Get the movemap of Golden pieces
 * @param team - The team of the pieces
*/
MoveMap getGoldenMovemap(int team) {
    Position position;
    Position next;
    Direction directions[DIRECTION_COUNT_GOLDEN];
    int i;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    if (team == 0) {
        directions[0] = TOP;
        directions[1] = RIGHT;
        directions[2] = BOTTOM_RIGHT;
        directions[3] = BOTTOM;
        directions[4] = BOTTOM_LEFT;
        directions[5] = LEFT;     
    }
    else{
        directions[0] = TOP_LEFT;
        directions[1] = TOP;
        directions[2] = TOP_RIGHT;
        directions[3] = RIGHT;
        directions[4] = BOTTOM;
        directions[5] = LEFT; 
    }

    for (position = 0; position < BOARD_SIZE; position++){
        // Array of lists of positions
        movemap[position] = malloc(DIRECTION_COUNT_GOLDEN * sizeof(List));
        
        // Fill it, if can't move in a direction : empty list
        for (i = 0; i < DIRECTION_COUNT_GOLDEN; i++){
            movemap[position][i] = createEmptyList();
            next = nextPosition(position, directions[i]);
            if (next != -1) {
                movemap[position] = addList((Variant)next, movemap[position][i]);
            }
        }
    }

    return movemap;
}

/**
 * Get the movemap of Silver General
 * @param team - The team of the Silver General
*/
MoveMap getSilverMovemap(int team) {
    Position position;
    Position next;
    Direction directions[DIRECTION_COUNT_SILVER];
    int i;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    if (team == 0) {
        directions[0] = TOP_LEFT;
        directions[1] = TOP_RIGHT;
        directions[2] = BOTTOM_RIGHT;
        directions[3] = BOTTOM;
        directions[4] = BOTTOM_LEFT;  
    }
    else{
        directions[0] = TOP_LEFT;
        directions[1] = TOP;
        directions[2] = TOP_RIGHT;
        directions[3] = BOTTOM_RIGHT;
        directions[4] = BOTTOM_LEFT;
    }

    for (position = 0; position < BOARD_SIZE; position++){
        // Array of lists of positions
        movemap[position] = malloc(DIRECTION_COUNT_SILVER * sizeof(List));
        
        // Fill it, if can't move in a direction : empty list
        for (i = 0; i < DIRECTION_COUNT_GOLDEN; i++){
            movemap[position][i] = createEmptyList();
            next = nextPosition(position, directions[i]);
            if (next != -1) {
                movemap[position] = addList((Variant)next, movemap[position][i]);
            }
        }
    }

    return movemap;
}

/**
 * Get the movemap of Dragons
*/
MoveMap getDragonMovemap(){
    Position position;
    Position next;
    Direction direction;
    // Initialisation of movemap (empty array of an array of lists)
    MoveMap movemap = malloc(BOARD_SIZE * sizeof(MoveCollection));

    for (position = 0; position < BOARD_SIZE; position++){
        movemap[position] = malloc(DIRECTION_COUNT_PAWN * sizeof(List));
        // movemap[position] = createEmptyList();

        // // Set the position to test
        // next = nextPosition(position, BOTTOM);
        // // Adds the position to the list if it exists
        // if (next != -1){
        //     movemap[position] = addList((Variant)next, movemap[position]);
        // }


        // A FAIRE ------------------------------------------------------------
    }

    return movemap;
}