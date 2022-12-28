/**
 * ----------------------------------------------
 *                    string.h
 * ----------------------------------------------
 * 
 * Simple string module that allow to concatenate
 * and compare strings.
 */


#ifndef __STRING_H__
#define __STRING_H__


// ----- Dependancy -----


#include "bool.h"


// ----- Constants and structs -----


#define STRING_SIZE sizeof(String)

struct __s_String{
    char * value;
    int length;
};

typedef struct __s_String String;


// ----- Functions -----


String concat(String _first_string, String _second_string);
Bool isEqualString(String _first_string, String _second_string);
char *getString(String _string);
String setString(char *_string);
void printString(String _string);

#endif