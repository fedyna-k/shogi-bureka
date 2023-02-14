/**
 * ----------------------------------------------
 *                   ia.c
 * ----------------------------------------------
 * 
 * I need all the moves
 */


#include "ia.h"
#include <stdlib.h>


void resetBuffer(Position *_buffer, int _size) {
    int i;

    for (i = 0 ; i < _size ; i++) {
        _buffer[i] = -1;
    }
}


List getAllMoves(Board _board, Bool _team) {
    int i;
    int j;
    List all_moves = createEmptyList();
    Position buffer[BOARD_LENGTH * DIRECTION_COUNT_KING];

    for (i = 0 ; i < BOARD_SIZE ; i++) {
        if (_board->board_piece[i] && _board->board_piece[i]->team == _team) {
            resetBuffer(buffer, BOARD_LENGTH * DIRECTION_COUNT_KING);
            getPieceMoves(_board, _board->board_piece[i], buffer);

            j = 0;
            while (buffer[j] != -1) {
                all_moves = addList((Variant)createMove(_board->board_piece[i]->position, buffer[j]), all_moves);
                j++;
            }
        }
    }

    return all_moves;
}


void dumpMoves(List _all_moves) {
    while (_all_moves) {
        free(_all_moves->element);
        _all_moves = _all_moves->next;
    }
}


void makeRandomMove(Board _board) {
    List all_moves = getAllMoves(_board, _board->team);
    List all_moves_save = all_moves;
    int max = rand() % 20;

    // Take random move
    while (all_moves->next && max > 0) {
        all_moves = all_moves->next;
        max--;
    }

    // Make the move
    makeMove(_board, all_moves->element);

    // Dump the moves to avoid mem leaks
    dumpMoves(all_moves_save);
    _board->team = 1 - _board->team;
}


void makeTrueMove(Board _board) {
    Move best_move;
    List all_moves, save;
    Board board_save = copyBoard(_board);
    int score, best = (signed int)0x80000000, i;

    all_moves = getAllMoves(_board, 0);
    save = all_moves;

    // On parcourt les mouvs
    while (all_moves) {
        board_save = copyBoard(_board);
        makeMove(board_save, (Move)all_moves->element);

        score = makeMoveUsingAlphaBeta(board_save, 3, (signed int)0x80000000, 0x7FFFFFFF);
        if (score > best) {
            best = score;
            best_move = (Move)all_moves->element;
        }

        all_moves = all_moves->next;
    }

    makeMove(_board, best_move);
    dumpMoves(save);
    _board->team = 1 - _board->team;
}


int makeMoveUsingAlphaBeta(Board _board, int _prof, int _alpha, int _beta) {
    signed int value, alphabeta, i;
    List all_moves, save;
    Board board_save;


    // Evaluate board
    if (_prof == 0) {
        return evaluation(_board);
    }

    // Team à 1 => Joueur
    if (_board->team) {
        value = 0x7FFFFFFF; // Max int

        all_moves = getAllMoves(_board, 1);
        save = all_moves;

        // On parcourt les mouvs
        while (all_moves) {

            board_save = copyBoard(_board);

            makeMove(board_save, (Move)all_moves->element);

            board_save->team = 0;
            alphabeta = makeMoveUsingAlphaBeta(board_save, _prof - 1, _alpha, _beta);

            freeBoard(board_save);

            value = (alphabeta > value) ? value : alphabeta;

            if (_alpha >= value) {
                dumpMoves(save);
                return value;
            }

            _beta = (value > _beta) ? _beta : value;


            all_moves = all_moves->next;
        }        
    } else {
        value = (signed int)0x80000000; // Min int

        all_moves = getAllMoves(_board, 0);
        save = all_moves;

        // On parcourt les mouvs
        while (all_moves) {
            board_save = copyBoard(_board);

            makeMove(board_save, (Move)all_moves->element);

            board_save->team = 1;
            alphabeta = makeMoveUsingAlphaBeta(board_save, _prof - 1, _alpha, _beta);

            freeBoard(board_save);

            value = (alphabeta < value) ? value : alphabeta;

            if (_alpha >= value) {
                dumpMoves(save);
                return value;
            }

            _alpha = (value < _alpha) ? _alpha : value;

            all_moves = all_moves->next;
        }
    }

    dumpMoves(save);
    return value;
}

int evaluation(Board _board){
    int i, score = 0, sign;
    Piece tmp_piece;

    for (i = 0; i < BOARD_SIZE; i++){
        tmp_piece = _board->board_piece[i];
        if (tmp_piece != NULL){
            if (tmp_piece->team == 1)
                sign = -1;
            else
                sign = 1;
            score += tmp_piece->value * sign;
        }
    }

    return score;
}