/**
 * ----------------------------------------------
 *                     main.c
 * ----------------------------------------------
 * 
 * The main file of the program, everything
 * should be linked here and declared in separated
 * files.
 */

#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char **argv) {
    SDL_Window *window = createMainWindow();
    SDL_Renderer *renderer = createRenderer(window);

    fillBackground(renderer);    
    drawBoardBackground(renderer);


    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}