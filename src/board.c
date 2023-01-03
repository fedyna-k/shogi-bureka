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

    // Copy data
    res->board_piece = copy(board->board_piece);
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
Board makeMove(Board board, Move move){
    Board res = copyBoard(board);

    res->board_piece[move.ending_square] = board->board_piece[move.starting_square];
    res->board_piece[move.starting_square] = NULL;

    return board;
}