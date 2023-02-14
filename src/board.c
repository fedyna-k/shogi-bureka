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
        if (board->board_piece[i]) {
            res->board_piece[i] = (Piece)malloc(sizeof(struct __s_Piece));
            
            if (!res->board_piece[i]) {
                SDL_Log("prout");
            }

            copyPiece(res->board_piece[i], board->board_piece[i]);
        } else {
            res->board_piece[i] = board->board_piece[i]; 
        }
    }
    res->first_player_hand = board->first_player_hand;
    res->second_player_hand = board->second_player_hand;
    res->score = res->score;
    res->hash_key = board->hash_key;
    res->team = board->team;
    res->all_movesets = board->all_movesets;
    res->all_textures = board->all_textures;

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
    //Piece eaten_piece = (Piece)malloc(sizeof(struct __s_Piece));
    if (board->board_piece[(int)move->starting_square]) {


        // Nom Nom Nom
        /*if (board->board_piece[(int)move->ending_square]) {
            // Get nom-nom-nomed piece
            eaten_piece = board->board_piece[(int)move->ending_square];
            eaten_piece->team = board->board_piece[(int)move->starting_square]->team;
            eaten_piece->position = -1;
            eaten_piece->is_promoted = 0;

            if (board->board_piece[(int)move->starting_square]->team) {
                board->second_player_hand = addList((Variant)eaten_piece, board->second_player_hand);
            } else {
                board->first_player_hand = addList((Variant)eaten_piece, board->first_player_hand);
            }
        }*/

        
        if (move->ending_square < 27 && board->team) {
            board->board_piece[(int)move->starting_square]->is_promoted = 1;
            promotePiece(board->board_piece[(int)move->starting_square], board->all_textures, board->all_movesets);
        }

        if (move->ending_square >= 54 && board->team == 0) {
            board->board_piece[(int)move->starting_square]->is_promoted = 1;
            promotePiece(board->board_piece[(int)move->starting_square], board->all_textures, board->all_movesets);
        }

        board->board_piece[(int)move->starting_square]->position = move->ending_square;
        board->board_piece[(int)move->ending_square] = board->board_piece[(int)move->starting_square];
        board->board_piece[(int)move->starting_square] = NULL;
    }
}

// Drop the piece 'piece' at the position indicated by move (ending square = position)
void dropPiece(Board board, Move move, Piece piece) {
    if (canDropAt(board, piece, move->ending_square)){
        piece->position = move->ending_square;
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
        pawn = 1 << (BOARD_LENGTH - position % BOARD_LENGTH - 1);
        if (piece->team == 0){
            if ((board->first_player_pawn & pawn)){
                return 0;
            }

            board->first_player_pawn ^= pawn;
        }
        else{
            if ((board->second_player_pawn & pawn)){
                return 0;
            }

            board->second_player_pawn ^= pawn;
        }

        // A pawn can not be dropped in front of the king to check mate
        // TO DO     --------------------------------------------------
    }

    return 1;
}

void generatePiece(char _symbol, Piece _piece, SDL_Texture **_textures, Bool _is_promoted, Moveset *_all_movesets) {
    switch (_symbol) {
        // King
        case 'k':            
        case 'K':
            _piece->name = setString("Roi");
            _piece->texture = _textures[(int)_piece->team];
            _piece->moveset = _all_movesets[0];
            _piece->value = 300;
        break;

        // Rook and dragon
        case 'r':
        case 'R':
            if (_is_promoted) {
                _piece->name = setString("Dragon");
                _piece->texture = _textures[3];
                _piece->moveset = _all_movesets[4];
                _piece->value = 13;
            } else {
                _piece->name = setString("Tour");
                _piece->texture = _textures[2];
                _piece->moveset = _all_movesets[2];
                _piece->value = 9;
            }
        break;

        // Bishop and Horse
        case 'b':
        case 'B':
            if (_is_promoted) {
                _piece->name = setString("Horse");
                _piece->texture = _textures[5];
                _piece->moveset = _all_movesets[3];
                _piece->value = 12;
            } else {
                _piece->name = setString("Fou");
                _piece->texture = _textures[4];
                _piece->moveset = _all_movesets[1];
                _piece->value = 8;
            }
        break;

        // Gold
        case 'g':
        case 'G':
            _piece->name = setString("General d'or");
            _piece->texture = _textures[6];
            _piece->moveset = _all_movesets[5];
            _piece->value = 5;
        break;

        // Silver
        case 's':
        case 'S':
            if (_is_promoted) {
                _piece->name = setString("General d'argent d'or");
                _piece->texture = _textures[8];
                _piece->moveset = _all_movesets[5];
                _piece->value = 5;
            } else {
                _piece->name = setString("General d'argent");
                _piece->texture = _textures[7];
                _piece->moveset = _all_movesets[6];
                _piece->value = 3;
            }
        break;

        // Knight
        case 'n':
        case 'N':
            if (_is_promoted) {
                _piece->name = setString("Cavalier d'or");
                _piece->texture = _textures[10];
                _piece->moveset = _all_movesets[5];
                _piece->value = 5;
            } else {
                _piece->name = setString("Cavalier");
                _piece->texture = _textures[9];
                _piece->moveset = _all_movesets[7];
                _piece->value = 3;
            }
        break;

        // Lance
        case 'l':
        case 'L':
            if (_is_promoted) {
                _piece->name = setString("Lancier d'or");
                _piece->texture = _textures[12];
                _piece->moveset = _all_movesets[5];
                _piece->value = 5;
            } else {
                _piece->name = setString("Lancier");
                _piece->texture = _textures[11];
                _piece->moveset = _all_movesets[8];
                _piece->value = 3;
            }
        break;

        // Pawn and tokin
        case 'p':
        case 'P':
            if (_is_promoted) {
                _piece->name = setString("Pion d'or");
                _piece->texture = _textures[14];
                _piece->moveset = _all_movesets[5];
                _piece->value = 5;
            } else {
                _piece->name = setString("Pion");
                _piece->texture = _textures[13];
                _piece->moveset = _all_movesets[9];
                _piece->value = 1;
            }
        break;
    }
}

void promotePiece(Piece _piece, SDL_Texture **_textures, Moveset *_all_movesets) {
    if (isEqualString(_piece->name, setString("Pion"))) {
        generatePiece('p', _piece, _textures, 1, _all_movesets);
    }
    else if (isEqualString(_piece->name, setString("Lancier"))) {
        generatePiece('l', _piece, _textures, 1, _all_movesets);
    }
    else if (isEqualString(_piece->name, setString("Cavalier"))) {
        generatePiece('n', _piece, _textures, 1, _all_movesets);
    }
    else if (isEqualString(_piece->name, setString("General d'argent"))) {
        generatePiece('s', _piece, _textures, 1, _all_movesets);
    }
    else if (isEqualString(_piece->name, setString("Tour"))) {
        generatePiece('r', _piece, _textures, 1, _all_movesets);
    }
    else if (isEqualString(_piece->name, setString("Fou"))) {
        generatePiece('b', _piece, _textures, 1, _all_movesets);
    }
}


void initBoard(Board _board, SDL_Texture **_textures, String _SFEN) {
    int string_parser, board_index = 0, next_step, piece_multiplier = 1;
    int slash_count = 0, sfen_part = 0;
    char current_char;
    Bool is_promoted = 0;
    Piece current_piece;
    Moveset *all_moveset = generateMovesets();
    int i;

    _board->all_movesets = all_moveset;
    _board->all_textures = _textures;

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
        }

        // Handle promoted pieces
        else if (current_char == '+') {
            if (sfen_part != 0) {
                exit(EXIT_FAILURE);
            }
            is_promoted = 1;
        }

        // Handle backslashes
        else if (current_char == '/') {
            if (sfen_part != 0) {
                exit(EXIT_FAILURE);
            }
            slash_count++;
        }

        // Handle part change
        else if (current_char == ' ') {
            sfen_part++;
        }

        // Handle team
        else if (sfen_part == 1) {
            if (slash_count != 8) {
                exit(EXIT_FAILURE);
            }
            _board->team = (current_char == 'w') ? 0 : 1;
        }

        // If uppercase, it's on the white team (KING UP)
        // If lowercase, it's on the black team (KINGBIS DOWN)
        else {
            if (sfen_part == 0) {
                current_piece = (Piece)malloc(sizeof(struct __s_Piece));
                current_piece->team = ('a' <= current_char && current_char <= 'z') ? 0 : 1;
                current_piece->position = (Position)board_index;
                current_piece->is_promoted = is_promoted;

                generatePiece(current_char, current_piece, _textures, is_promoted, all_moveset);
                _board->board_piece[board_index] = current_piece;
                
                board_index++;
                is_promoted = 0;
            } else {

                for (board_index = 0 ; board_index < piece_multiplier ; board_index++) {
                    current_piece = (Piece)malloc(sizeof(struct __s_Piece));
                    current_piece->team = ('a' <= current_char && current_char <= 'z') ? 0 : 1;
                    current_piece->position = -1;
                    current_piece->is_promoted = 0;

                    generatePiece(current_char, current_piece, _textures, is_promoted, all_moveset);

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

    for (i = 0 ; i < BOARD_SIZE ; i++) {
        if (_board->board_piece[i] && !_board->board_piece[i]->texture) {
            SDL_Log("Nom : %s\nTexture : %p\nMoveset : %p", _board->board_piece[i]->name.value, _board->board_piece[i]->texture, _board->board_piece[i]->moveset);
        }
    }
}


/**
 * Return an array of all possible moves for a given piece 
 */
void getPieceMoves(Board _board, Piece _piece, Position *_possible_moves) {
    MoveMap piece_movemap = getMoveMap(_piece->moveset, _piece->team);
    MoveCollection directions = piece_movemap[(int)_piece->position];
    List current_position;
    Position possible_position;
    int i, j = 0;

    if (_piece->position < 0) {return;}

    for (i = 0 ; i < _piece->moveset->direction_number ; i++) {
        current_position = directions[i];

        // Loop for sliding pieces
        while (current_position && current_position->element) {
            possible_position = (Position)(int)current_position->element;
            if (_board->board_piece[(int)possible_position] != NULL) {
                if (_board->board_piece[(int)possible_position]->team != _piece->team) {
                    _possible_moves[j++] = possible_position;
                }
                break;
            }
            _possible_moves[j++] = possible_position;
            current_position = current_position->next;
        }
    }
    _possible_moves[j] = -1;
}