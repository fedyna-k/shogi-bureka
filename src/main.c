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
#include <time.h>


int main (int argc, char **argv) {
    SDL_Window *window = createMainWindow();
    SDL_Renderer *renderer = createRenderer(window);
    SDL_Texture **texture_array = generatePiecesTextures(renderer, 0);
    Board test_board = createNewBoard();
    String beginning_board = setString("lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL ");
    int team;

    fillBackground(renderer);    
    drawBoardBackground(renderer);

    // Choose starting at random
    srand(time(NULL));
    team = rand() % 2;

    initBoard(test_board, texture_array, concat(beginning_board, setString(team ? "w" : "b")));

    drawBoard(renderer, test_board);    

    SDL_RenderPresent(renderer);
    SDL_Delay((int)3e3);

    freePiecesTextures(texture_array);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}