/**
 * ----------------------------------------------
 *                   ia.h
 * ----------------------------------------------
 * 
 * Shogi IA
 */


#ifndef __IA_H__
#define __IA_H__


// ----- Dependancy -----


#include "board.h"


// ----- Constants and structs -----



// ----- Functions -----

void resetBuffer(Position *_buffer, int _size);
List getAllMoves(Board _board, Bool _team);
void dumpMoves(List _all_moves);
void makeRandomMove(Board _board);
void makeTrueMove(Board _board);
int makeMoveUsingAlphaBeta(Board _board, int _prof, int _alpha, int _beta);
int evaluation(Board _board);


#endif