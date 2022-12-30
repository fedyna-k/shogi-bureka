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

#define TOP             {0, 1}
#define TOP_RIGHT       {1, 1}
#define RIGHT           {1, 0}
#define BOTTOM_RIGHT    {1, -1}
#define BOTTOM          {0, -1}
#define BOTTOM_LEFT     {-1, -1}
#define LEFT            {-1, 0}
#define TOP_LEFT        {-1, 1}

#define KNIGHT_TL       {-1, 2}
#define KNIGHT_TR       {1, 2}
#define KNIGHT_BL       {-1, -2}
#define KNIGHT_BR       {1, -2}

// ----- Functions -----


char getTotalOffset(Direction _direction);


#endif