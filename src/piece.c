/**
 * ----------------------------------------------
 *                     piece.c
 * ----------------------------------------------
 * 
 * Encoding for the piece.
 */

#include "piece.h"

void copyPiece(Piece _dest, Piece _src) {
    /*if (*_dest == NULL) {
        *_dest = (Piece)malloc(sizeof(struct __s_Piece));
    }*/
    if (_src) {
        (_dest)->is_promoted = _src->is_promoted;
        (_dest)->moveset = _src->moveset;
        (_dest)->name = _src->name;
        (_dest)->position = _src->position;
        (_dest)->team = _src->team;
        (_dest)->texture = _src->texture;
        (_dest)->value = _src->value;
    }
}