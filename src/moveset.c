/**
 * ----------------------------------------------
 *                   moveset.c
 * ----------------------------------------------
 * 
 * Encoding of a moveset which is given to a piece
 */


#include "moveset.h"


/**
 * Return the movemap corresponding to the good team
 * @param _set The moveset of a piece type
 * @param _team The team of the piece
 * @return The corresponding movemap
 */
MoveMap getMoveMap(Moveset _set, char _team) {
    if (_team) {
        return _set->first_team;
    } else {
        return _set->second_team;
    }
}


Moveset *generateMovesets(void) {
    Moveset *all_movesets = (Moveset *)malloc(MOVEMENT_TYPE_COUNT * sizeof(Moveset));
    Moveset current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_KING;
    current_moveset->first_team = getKingMovemap();
    current_moveset->second_team = current_moveset->first_team;
    all_movesets[0] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_BISHOP;
    current_moveset->first_team = getBishopMovemap();
    current_moveset->second_team = current_moveset->first_team;
    all_movesets[1] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_ROOK;
    current_moveset->first_team = getRookMovemap();
    current_moveset->second_team = current_moveset->first_team;
    all_movesets[2] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_HORSE;
    current_moveset->first_team = getHorseMovemap();
    current_moveset->second_team = current_moveset->first_team;
    all_movesets[3] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_DRAGON;
    current_moveset->first_team = getDragonMovemap();
    current_moveset->second_team = current_moveset->first_team;
    all_movesets[4] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_GOLDEN;
    current_moveset->first_team = getGoldenMovemap(0);
    current_moveset->second_team = getGoldenMovemap(1);
    all_movesets[5] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_SILVER;
    current_moveset->first_team = getSilverMovemap(0);
    current_moveset->second_team = getSilverMovemap(1);
    all_movesets[6] = current_moveset;

    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_KNIGHT;
    current_moveset->first_team = getKnightMovemap(0);
    current_moveset->second_team = getKnightMovemap(1);
    all_movesets[7] = current_moveset;
    
    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_LANCE;
    current_moveset->first_team = getLanceMovemap(0);
    current_moveset->second_team = getLanceMovemap(1);
    all_movesets[8] = current_moveset;
    
    current_moveset = (Moveset)malloc(sizeof(struct __s_Moveset));
    current_moveset->direction_number = DIRECTION_COUNT_PAWN;
    current_moveset->first_team = getPawnMovemap(0);
    current_moveset->second_team = getPawnMovemap(1);
    all_movesets[9] = current_moveset;

    return all_movesets;
}

