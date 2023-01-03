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
    SDL_Texture **texture_array = generatePiecesTextures(renderer, 0);
    Board test_board = createNewBoard();

    fillBackground(renderer);    
    drawBoardBackground(renderer);

    initBoard(test_board, texture_array, setString("lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL"));

    drawBoard(renderer, test_board);    

    SDL_RenderPresent(renderer);
    SDL_Delay((int)10e3);

    freePiecesTextures(texture_array);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}