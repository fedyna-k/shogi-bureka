/**
 * ----------------------------------------------
 *                   graphics.c
 * ----------------------------------------------
 * 
 * Graphic functions for shogi gameplay
 */


#include "graphics.h"
#include <stdio.h>


void createMainWindow(void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *screen;
    
    screen = SDL_CreateWindow("Shogi Breaker", 0, 0, 1, 1, SDL_WINDOW_FULLSCREEN);
    SDL_Delay(5000);
}