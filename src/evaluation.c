#include "evaluation.h"

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
}