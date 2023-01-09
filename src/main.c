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
#include "dragdrop.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (int argc, char **argv) {
    SDL_Window *window = createMainWindow();
    SDL_Renderer *renderer = createRenderer(window);
    SDL_Texture **texture_array = generatePiecesTextures(renderer, 0);
    Board board = createNewBoard();
    String beginning_board = setString("lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL ");
    int team, mainloop = 1;
    SDL_Event event;
    Piece piece_in_hand = NULL;
    int mousex, mousey;

    // Choose starting at random
    srand(time(NULL));
    team = rand() % 2;

    initBoard(board, texture_array, concat(beginning_board, setString(team ? "w" : "b")));

    while (mainloop) {
        fillBackground(renderer);    
        drawBoardBackground(renderer);
        drawBoard(renderer, board);

        if (piece_in_hand) {
            SDL_GetMouseState(&mousex, &mousey);
            drawPieceXY(renderer, piece_in_hand, mousex, mousey);
        }

        SDL_RenderPresent(renderer);

        // Event quit on keyboard
        while (SDL_PollEvent(&event) != 0) {
            // Quit game
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    mainloop = 0;
                }
            }

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                piece_in_hand = getPieceInHand(renderer, event, board);
            }

            if (event.type == SDL_MOUSEBUTTONUP && piece_in_hand) {
                dropPieceFromHand(renderer, event, board, piece_in_hand);
                piece_in_hand = NULL;
            }
        }
    }

    freePiecesTextures(texture_array);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}