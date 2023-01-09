/**
 * ----------------------------------------------
 *                   dragdrop.c
 * ----------------------------------------------
 * 
 * Drag and drop mechanics for game pieces
 */


#include "dragdrop.h"


Piece getPieceInHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board) {
    int screen_width, screen_height;
    int x_offset, y_offset;
    int x, y;
    Piece grabed_piece;

    // Get screen size and offset
    if (SDL_GetRendererOutputSize(_renderer, &screen_width, &screen_height) != 0) {
        exitOnError("Impossible de recuperer la taille du rendu.");
    }
    x_offset = (screen_width - SQUARE_SIZE * BOARD_LENGTH) / 2;
    y_offset = (screen_height - SQUARE_SIZE * BOARD_LENGTH) / 2;

    x = (_event.button.x - x_offset) / SQUARE_SIZE;
    y = (_event.button.y - y_offset) / SQUARE_SIZE;

    if (0 <= x && x < BOARD_LENGTH && 0 <= y && y < BOARD_LENGTH) {
        grabed_piece = _board->board_piece[x + y * BOARD_LENGTH];
        _board->board_piece[x + y * BOARD_LENGTH] = NULL;
        return grabed_piece;
    }

    return NULL;
}

void dropPieceFromHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Piece _piece) {
    int screen_width, screen_height;
    int x_offset, y_offset;
    int x, y;

    // Get screen size and offset
    if (SDL_GetRendererOutputSize(_renderer, &screen_width, &screen_height) != 0) {
        exitOnError("Impossible de recuperer la taille du rendu.");
    }
    x_offset = (screen_width - SQUARE_SIZE * BOARD_LENGTH) / 2;
    y_offset = (screen_height - SQUARE_SIZE * BOARD_LENGTH) / 2;

    x = (_event.button.x - x_offset) / SQUARE_SIZE;
    y = (_event.button.y - y_offset) / SQUARE_SIZE;

    if (0 <= x && x < BOARD_LENGTH && 0 <= y && y < BOARD_LENGTH) {
        _piece->position = x + y * BOARD_LENGTH;
    }

    _board->board_piece[(int)_piece->position] = _piece;
}