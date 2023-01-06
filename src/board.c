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
    int i = 0;

    // Copy data
    res->board_piece = malloc(BOARD_SIZE * sizeof(Piece));
    for (i = 0; i < BOARD_SIZE; i++){
        res->board_piece[i] = board->board_piece[i];    
    }
    res->first_player_hand = board->first_player_hand;
    res->second_player_hand = board->second_player_hand;
    res->score = res->score;
    res->hash_key = board->hash_key;
    res->team = board->team;

    return res;
}


// Free the board
void freeBoard(Board board) {
    int i;
    for (i = 0 ; i < BOARD_SIZE ; i++) {
        free(board->board_piece[i]);
    }
    freeList(board->first_player_hand);
    freeList(board->second_player_hand);
    free(board);
}


// Returns a board with a move in parameter made
void makeMove(Board board, Move move){
    board->board_piece[(int)move.starting_square]->position = move.ending_square;
    board->board_piece[(int)move.ending_square] = board->board_piece[(int)move.starting_square];
    board->board_piece[(int)move.starting_square] = NULL;
}

// Drop the piece 'piece' at the position indicated by move (ending square = position)
void dropPiece(Board board, Move move, Piece piece) {
    if (canDropAt(board, piece, move.ending_square)){
        piece->position = move.ending_square;
        board->board_piece[(int)piece->position] = piece;
    }
}

// Returns a boolean indicating if we can drop the piece 'piece' at the position 'position'
Bool canDropAt(Board board, Piece piece, Position position) {
    int pawn;
    // The piece can't be placed if :
    // If a piece is already at this place
    if (board->board_piece[(int)position] != NULL) {
        return 0;
    }
    // The piece wouldn't be able to move if placed here
    if (piece->team == 0){
        if (canMoveAt(piece->moveset->first_team, position)){
            return 0;
        }
    }
    else{
        if (canMoveAt(piece->moveset->second_team, position)){
            return 0;
        }
    }
    // Conditions for dropping a pawn
    if (isEqualString(piece->name, setString("Pion"))){
        // A pawn can not be placed on the same row as another non promoted pawn    
        // Creates a binary number with 1 for the column of the position and 0 on the others
        pawn = 1 << (BOARD_LENGTH - position %BOARD_LENGTH - 1);
        if (piece->team == 0){
            if ((board->first_player_pawn & pawn)){
                return 0;
            }
        }
        else{
            if ((board->second_player_pawn & pawn)){
                return 0;
            }
        }
        // A pawn can not be dropped in front of the king to check mate
        // TO DO------------------------------------------------------------
    }

    return 1;
}

void generatePiece(char _symbol, Piece _piece, SDL_Texture **_textures, Bool _is_promoted) {
    switch (_symbol) {
        // King
        case 'k':            
        case 'K':
            _piece->name = setString("Roi");
            _piece->texture = _textures[(int)_piece->team];
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
                _piece->name = setString("General d'argent");
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
    int string_parser, board_index = 0, next_step, piece_multiplier = 1;
    int slash_count = 0, sfen_part = 0;
    char current_char;
    Bool is_promoted;
    Piece current_piece;

    // Loop through SFEN string
    for (string_parser = 0 ; string_parser < _SFEN.length ; string_parser++) {
        // Get current char
        current_char = getString(_SFEN)[string_parser];

        // If the current char is a numeric symbol
        if ('1' <= current_char && current_char <= '9') {
            if (sfen_part == 0) {
                // Fill in the blanks
                next_step = board_index + current_char - '0';
                for (board_index = board_index ; board_index < next_step ; board_index++) {
                    _board->board_piece[board_index] = NULL;
                }
            } else {
                piece_multiplier = current_char - '0';
            }
            continue;
        }

        // Handle promoted pieces
        if (current_char == '+') {
            if (sfen_part != 0) {
                exit(EXIT_FAILURE);
            }
            is_promoted = 1;
            continue;
        }

        // Handle backslashes
        if (current_char == '/') {
            if (sfen_part != 0) {
                exit(EXIT_FAILURE);
            }
            slash_count++;
            continue;
        }

        // Handle part change
        if (current_char == ' ') {
            sfen_part++;
            continue;
        }

        // Handle team
        if (sfen_part == 1) {
            if (slash_count != 8) {
                exit(EXIT_FAILURE);
            }
            _board->team = (current_char == 'w') ? 0 : 1;
            continue;
        }

        // If uppercase, it's on the white team (KING UP)
        // If lowercase, it's on the black team (KINGBIS DOWN)

        if (sfen_part == 0) {
            current_piece = (Piece)malloc(sizeof(struct __s_Piece));
            current_piece->team = ('a' <= current_char && current_char <= 'z') ? 0 : 1;
            current_piece->position = board_index;

            generatePiece(current_char, current_piece, _textures, is_promoted);
            _board->board_piece[board_index] = current_piece;
            
            board_index++;
            is_promoted = 0;
        } else {

            for (board_index = 0 ; board_index < piece_multiplier ; board_index++) {
                current_piece = (Piece)malloc(sizeof(struct __s_Piece));
                current_piece->team = ('a' <= current_char && current_char <= 'z') ? 0 : 1;
                current_piece->position = 0;

                generatePiece(current_char, current_piece, _textures, is_promoted);

                if (current_piece->team) {
                    _board->second_player_hand = addList((Variant)current_piece, _board->second_player_hand);
                } else {
                    _board->first_player_hand = addList((Variant)current_piece, _board->first_player_hand);
                }
            }

            piece_multiplier = 1;    
        }
    }
}