/**
 * ----------------------------------------------
 *                  direction.h
 * ----------------------------------------------
 * 
 * Add direction handling
 */


#ifndef __DIRECTION_H__
#define __DIRECTION_H__


// ----- Constants and structs -----


struct __s_Direction {
    char dx;
    char dy;
};

typedef struct __s_Direction Direction;


// ----- Functions -----


char getTotalOffset(Direction _direction);


#endif