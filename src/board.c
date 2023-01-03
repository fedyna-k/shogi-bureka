/**
 * ----------------------------------------------
 *                  board.c
 * ----------------------------------------------
 * 
 * define the function for the board of the game
 */

#include "board.h"

// Functions ------------------------------------


// Create an empty board
Board createNewBoard() {
    Board res = malloc(sizeof(struct __s_Board));

    // Values
    res->board_piece = malloc(sizeof(struct __s_Piece) * BOARD_SIZE);
    res->first_player_hand = createEmptyList();
    res->second_player_hand = createEmptyList();
    res->score = 0;
    res->team = 0;

    return res;
}

// Copy the board
Board copyBoard(Board board) {
    Board res = createNewBoard();

    // Copy data
    res->board_piece = copy(board->board_piece);
    res->first_player_hand = board->first_player_hand;
    res->second_player_hand = board->second_player_hand;
    res->score = res->score;
    res->hash_key = board->hash_key;
    res->team = board->team;

    return res;
}


// Free the board
void freeBoard(Board board) {
    freeList(board->board_piece);
    free(board);
}


// Returns a board with a move in parameter made
Board makeMove(Board board, Move move) {
    Board res = copyBoard(board);

    res->board_piece[move.ending_square] = board->board_piece[move.starting_square];
    res->board_piece[move.starting_square] = NULL;

    return board;
}


void generatePiece(char _symbol, Piece _piece, SDL_Texture **_textures, Bool _is_promoted) {
    switch (_symbol) {
        // King
        case 'k':            
        case 'K':
            _piece->name = setString("Roi");
            _piece->texture = _textures[_piece->team];
        break;

        // Rook and dragon
        case 'r':
        case 'R':
            if (_is_promoted) {
                _piece->name = setString("Dragon");
                _piece->texture = _textures[3];
            } else {
                _piece->name = setString("Tour");
                _piece->texture = _textures[2];
            }
        break;

        // Bishop and Horse
        case 'b':
        case 'B':
            if (_is_promoted) {
                _piece->name = setString("Horse");
                _piece->texture = _textures[5];
            } else {
                _piece->name = setString("Fou");
                _piece->texture = _textures[4];
            }
        break;

        // Gold
        case 'g':
        case 'G':
            _piece->name = setString("General d'or");
            _piece->texture = _textures[6];
        break;

        // Silver
        case 's':
        case 'S':
            if (_is_promoted) {
                _piece->name = setString("General d'argent d'or");
                _piece->texture = _textures[8];
            } else {
                _piece->name = setString("Fou");
                _piece->texture = _textures[7];
            }
        break;

        // Knight
        case 'n':
        case 'N':
            if (_is_promoted) {
                _piece->name = setString("Cavalier d'or");
                _piece->texture = _textures[10];
            } else {
                _piece->name = setString("Cavalier");
                _piece->texture = _textures[9];
            }
        break;

        // Knight
        case 'l':
        case 'L':
            if (_is_promoted) {
                _piece->name = setString("Lancier d'or");
                _piece->texture = _textures[12];
            } else {
                _piece->name = setString("Lancier");
                _piece->texture = _textures[11];
            }
        break;

        // Pawn and tokin
        case 'p':
        case 'P':
            if (_is_promoted) {
                _piece->name = setString("Pion d'or");
                _piece->texture = _textures[14];
            } else {
                _piece->name = setString("Pion");
                _piece->texture = _textures[13];
            }
        break;
    }
}


void initBoard(Board _board, SDL_Texture **_textures, String _SFEN) {
    int string_parser, board_index = 0;
    char current_char;
    Bool is_promoted;
    Piece current_piece;

    // Loop through SFEN string
    for (string_parser = 0 ; string_parser < _SFEN.length ; string_parser++) {
        // Get current char
        current_char = getString(_SFEN)[string_parser];

        // If the current char is a numeric symbol
        if ('1' <= current_char && current_char <= '9') {
            // Fill in the blanks
            for (board_index ; board_index < board_index + current_char - '0'; board_index++) {
                _board->board_piece[board_index] = NULL;
            }
            continue;
        }

        // Handle promoted pieces
        if (current_char == '+') {
            is_promoted = 1;
            continue;
        }

        // If uppercase, it's on the white team (KING UP)
        // If lowercase, it's on the black team (KINGBIS DOWN)

        current_piece = (Piece)malloc(sizeof(struct __s_Piece));
        current_piece->team = ('a' <= current_char && current_char <= 'z') ? 1 : 0;
        current_piece->position = board_index;

        generatePiece(current_char, current_piece, _textures, is_promoted);

        _board->board_piece[board_index] = current_piece;

        board_index++;
        is_promoted = 0;
    }
}