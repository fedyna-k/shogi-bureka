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


// ----- Functions -----


Piece getPieceInHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board);
Move dropPieceFromHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Piece _piece);


#endif