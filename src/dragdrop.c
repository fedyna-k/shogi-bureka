/**
 * ----------------------------------------------
 *                   dragdrop.c
 * ----------------------------------------------
 * 
 * Drag and drop mechanics for game pieces
 */


#include "dragdrop.h"


Piece getPieceInHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Position *_piece_moves) {
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
        if (grabed_piece && grabed_piece->team == _board->team) {
            _board->board_piece[x + y * BOARD_LENGTH] = NULL;
            getPieceMoves(_board, grabed_piece, _piece_moves);
            return grabed_piece;
        }
    }

    return NULL;
}

Move dropPieceFromHand(SDL_Renderer *_renderer, SDL_Event _event, Board _board, Piece _piece, Position *_piece_moves) {
    int screen_width, screen_height;
    int x_offset, y_offset;
    int x, y;
    int i = 0;
    int pawn;
    Bool is_valid;
    Position drop_position;
    //Piece eaten_piece;
    Move move_made;

    // Get screen size and offset
    if (SDL_GetRendererOutputSize(_renderer, &screen_width, &screen_height) != 0) {
        exitOnError("Impossible de recuperer la taille du rendu.");
    }
    x_offset = (screen_width - SQUARE_SIZE * BOARD_LENGTH) / 2;
    y_offset = (screen_height - SQUARE_SIZE * BOARD_LENGTH) / 2;

    x = (_event.button.x - x_offset) / SQUARE_SIZE;
    y = (_event.button.y - y_offset) / SQUARE_SIZE;

    drop_position = x + y * BOARD_LENGTH;

    // Avoid drop not in board
    if (!(0 <= x && x < BOARD_LENGTH && 0 <= y && y < BOARD_LENGTH)) {
        _board->board_piece[(int)_piece->position] = _piece;
        return NULL;
    }

    // Check if move is in valid position
    is_valid = 0;
    while (_piece_moves[i] != -1 && !is_valid) {
        if (_piece_moves[i] == drop_position) {
            is_valid = 1;
        }
        i++;
    }

    if (!is_valid) {
        _board->board_piece[(int)_piece->position] = _piece;
        return NULL;
    }

/*
    // Nom Nom Nom
    if (_board->board_piece[(int)drop_position]) {
        // Get nom-nom-nomed piece
        eaten_piece = _board->board_piece[(int)drop_position];
        eaten_piece->team = _piece->team;
        eaten_piece->position = -1;
        eaten_piece->is_promoted = 0;

        if (_piece->team) {
            _board->second_player_hand = addList((Variant)eaten_piece, _board->second_player_hand);
        } else {
            _board->first_player_hand = addList((Variant)eaten_piece, _board->first_player_hand);
        }
    }
*/
    if (drop_position < 27 && _board->team) {
        _piece->is_promoted = 1;
        promotePiece(_piece, _board->all_textures, _board->all_movesets);
    }

    if (drop_position >= 54 && _board->team == 0) {
        _piece->is_promoted = 1;
        promotePiece(_piece, _board->all_textures, _board->all_movesets);
    }

    move_made = createMove(_piece->position, drop_position);

    if (_piece->position != drop_position) {
        _board->team = 1 - _board->team;
    }

    _piece->position = drop_position;
    _board->board_piece[(int)drop_position] = _piece;

    return move_made;
}