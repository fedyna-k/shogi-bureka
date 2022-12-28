/**
 * ----------------------------------------------
 *                   bigint.c
 * ----------------------------------------------
 * 
 * Bigger Integer on 128 bits to avoid collisions
 * on Zobrist hash.
 */


#ifndef __BIGINT_H__
#define __BIGINT_H__


// ----- Dependancy -----


#include "bool.h"


// ----- Constants and structs -----


struct __s_BigInt {
    long long int hi;
    long long int lo;
};

typedef struct __s_BigInt BigInt;


// ----- Functions -----


BigInt xorBI(BigInt _first, BigInt _second);
Bool isEqualBI(BigInt _first, BigInt _second);


#endif