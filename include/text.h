/**
 * ----------------------------------------------
 *                  text.h
 * ----------------------------------------------
 * 
 * File that handles text blitting on screen
 */


#ifndef __TEXT_H__
#define __TEXT_H__


// ----- Dependancy -----


#include <time.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "constants.h"
#include "bool.h"


// ----- Constants and structs -----


#define TIMER_SIZE 64
#define PLAYER_TEXT_SIZE 32


// ----- Functions -----


void blitThinText(SDL_Renderer *_renderer, const char *_text, int _x, int _y, int _size);
void blitText(SDL_Renderer *_renderer, const char *_text, int _x, int _y, int _size);
void blitTimerAndPlayer(SDL_Renderer *_renderer, const char *_text, Bool _team);


#endif