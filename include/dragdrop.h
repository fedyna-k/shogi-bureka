/**
 * ----------------------------------------------
 *                   dragdrop.h
 * ----------------------------------------------
 * 
 * Drag and drop mechanics for game pieces
 */


#ifndef __DRAGDROP_H_
#define __DRAGDROP_H_


// ----- Dependancy -----


#include "board.h"
#include "graphics.h"
#include "move.h"
#include "bool.h"


// ----- Functions -----


Piece getPieceInHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Position *_piece_moves);
Move dropPieceFromHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Piece _piece, Position *_piece_moves);


#endif