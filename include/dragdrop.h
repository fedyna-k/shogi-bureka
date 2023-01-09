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


// ----- Functions -----


Piece getPieceInHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board);
void dropPieceFromHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Piece _piece);


#endif