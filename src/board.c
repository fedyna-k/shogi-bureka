/**
 * ----------------------------------------------
 *                  board.c
 * ----------------------------------------------
 * 
 * define the function for the board of the game
 */

#include "board.h"

// Functions ------------------------------------


// Create an empty board
Board createNewBoard(){
    Board res = malloc(sizeof(struct __s_Board));

    // Values
    res->board_piece = malloc(sizeof(struct __s_Piece) * BOARD_SIZE);
    res->first_player_hand = createEmptyList();
    res->second_player_hand = createEmptyList();
    res->score = 0;
    res->team = 0;

    return res;
}

// Copy the board
Board copyBoard(Board board){
    Board res = createNewBoard();
    int i = 0;

    // Copy data
    res->board_piece = malloc(BOARD_SIZE * sizeof(Piece));
    for (i = 0; i < BOARD_SIZE; i++){
        res->board_piece[i] = board->board_piece[i];    
    }
    res->first_player_hand = board->first_player_hand;
    res->second_player_hand = board->second_player_hand;
    res->score = res->score;
    res->hash_key = board->hash_key;
    res->team = board->team;

    return res;
}


// Free the board
void freeBoard(Board board){
    freeList(board->board_piece);
    free(board);
}


// Returns a board with a move in parameter made
void makeMove(Board board, Move move){
    board->board_piece[move.starting_square]->position = move.ending_square;
    board->board_piece[move.ending_square] = board->board_piece[move.starting_square];
    board->board_piece[move.starting_square] = NULL;
}

// Drop the piece 'piece' at the position indicated by move (ending square = position)
void dropPiece(Board board, Move move, Piece piece) {
    if (canDropAt(board, piece, move.ending_square)){
        piece->position = move.ending_square;
        board->board_piece[piece->position] = piece;
    }
}

// Returns a bool indicating if we can drop the piece 'piece' at the position 'position'
Bool canDropAt(Board board, Piece piece, Position position) {
    int pawn;
    // The piece can't be placed if :
    // If a piece is already at this place
    if (board->board_piece[position] != NULL) {
        return 0;
    }
    // The piece wouldn't be able to move if placed here
    if (piece->team == 0){
        if (isEmptyList(getMovesAt(piece->moveset->first_team, position))){
            return 0;
        }
    }
    else{
        if (isEmptyList(getMovesAt(piece->moveset->second_team, position))){
            return 0;
        }
    }
    // Conditions for dropping a pawn
    if (isEqualString(piece->name, setString("Pion"))){
        // A pawn can not be placed on the same row as another non promoted pawn    
        // Creates a binary number with 1 for the column of the position and 0 on the others
        pawn = 1 << (BOARD_LENGTH - position %BOARD_LENGTH - 1);
        if (piece->team == 0){
            if ((board->first_player_pawn & pawn)){
                return 0;
            }
        }
        else{
            if ((board->second_player_pawn & pawn)){
                return 0;
            }
        }

        // A pawn can not be dropped in front of the king to check mate
        // TO DO------------------------------------------------------------
    }

    // If these conditions are not met, the piece can be placed at this position
    return 1;
}