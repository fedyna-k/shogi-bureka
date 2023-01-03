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

    fillBackground(renderer);    
    drawBoardBackground(renderer);

    /*----------------------- BY HAND TO MAKE THE BOARD LOOK COOL ------------------------*/

    // BAD TEAM

    drawPiece(renderer, (Piece){setString(""), texture_array[11], 1, 0, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[9], 1, 1, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[7], 1, 2, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[6], 1, 3, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[1], 1, 4, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[6], 1, 5, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[7], 1, 6, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[9], 1, 7, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[11], 1, 8, NULL});

    drawPiece(renderer, (Piece){setString(""), texture_array[2], 1, 10, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[4], 1, 16, NULL});

    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 18, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 19, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 20, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 21, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 22, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 23, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 24, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 25, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 1, 26, NULL});

    // GOOD TEAM

    drawPiece(renderer, (Piece){setString(""), texture_array[11], 0, 80, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[9], 0, 79, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[7], 0, 78, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[6], 0, 77, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[0], 0, 76, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[6], 0, 75, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[7], 0, 74, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[9], 0, 73, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[11], 0, 72, NULL});

    drawPiece(renderer, (Piece){setString(""), texture_array[2], 0, 70, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[4], 0, 64, NULL});

    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 62, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 61, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 60, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 59, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 58, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 57, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 56, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 55, NULL});
    drawPiece(renderer, (Piece){setString(""), texture_array[13], 0, 54, NULL});



    /*-------------------------------------------------------------------------------------*/


    SDL_RenderPresent(renderer);
    SDL_Delay((int)10e3);

    freePiecesTextures(texture_array);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}