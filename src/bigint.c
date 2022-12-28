/**
 * ----------------------------------------------
 *                   bigint.c
 * ----------------------------------------------
 * 
 * Bigger Integer on 128 bits to avoid collisions
 * on Zobrist hash.
 */


#include "bigint.h"


/**
 * XOR two BigInt
 * @param _first The first one
 * @param _second The second one
 * @return The xor between the two
 */
BigInt xorBI(BigInt _first, BigInt _second) {
    BigInt result;
    result.hi = _first.hi ^ _second.hi;
    result.lo = _first.lo ^ _second.lo;
    return result;
}


/**
 * Check equality between two BigInt
 * @param _first The first one
 * @param _second The second one
 * @return A bool telling if the two BI are equal
 */
Bool isEqualBI(BigInt _first, BigInt _second) {
    return _first.hi == _second.hi && _first.lo == _second.lo;
}