#include "movemap.h"

Bool canMoveAt(MoveMap map, Position position){
    return (!is_empty_list(map[position]));
}

List getMovesAt(MoveMap map, Position position){
    return (map[position]);
}