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
#include "text.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (int argc, char **argv) {
    // SDL VARIABLES
    SDL_Window *window = createMainWindow();
    SDL_Renderer *renderer = createRenderer(window);
    SDL_Texture **texture_array = generatePiecesTextures(renderer, 0);
    SDL_Event event;

    // Board game
    Board board = createNewBoard();
    String beginning_board = setString("lnsgkgsnl/1r5b1/ppppppppp/9/9/9/PPPPPPPPP/1B5R1/LNSGKGSNL ");
    int team, mainloop = 1;

    // Moving pieces
    Piece piece_in_hand = NULL;
    int mousex, mousey;
    Move last_move = NULL, move_made;

    // Timer variables
    time_t timer_start = time(NULL);
    unsigned long diff;
    int seconds, minutes;
    char *timer_text = (char *)malloc(6);

    // Choose starting at random
    srand(time(NULL));
    team = rand() % 2;

    initBoard(board, texture_array, concat(beginning_board, setString(team ? "w" : "b")));

    while (mainloop) {
        fillBackground(renderer);    
        drawBoardBackground(renderer, last_move, piece_in_hand);
        drawBoard(renderer, board);
        drawHands(renderer, board);
        // blitThinText(renderer, "Par Bastien & Kevin", 10, 10, 18);

        if (piece_in_hand) {
            SDL_GetMouseState(&mousex, &mousey);
            drawPieceXY(renderer, piece_in_hand, mousex, mousey);
        }

        // Blit timer on screen and player
        diff = difftime(time(NULL), timer_start);
        seconds = diff % 60;
        minutes = diff / 60;
        sprintf(timer_text, "%02d:%02d", minutes, seconds);
        blitTimerAndPlayer(renderer, timer_text, board->team);

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
                move_made = dropPieceFromHand(renderer, event, board, piece_in_hand);
                if (move_made && move_made->starting_square != move_made->ending_square) {
                    last_move = move_made;
                }
                piece_in_hand = NULL;
            }
        }
    }

    freePiecesTextures(texture_array);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}