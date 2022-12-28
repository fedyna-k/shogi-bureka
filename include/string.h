#ifndef __STRING_H__
#define __STRING_H__

#include "bool.h"

typedef struct zString{
    char * value;
    int length;
} String;

String concat(String first_string, String second_string);
Bool isEqual(String first_string, String second_string);
char * getString(String string);
String setString(char * chain);
void printString(String string);

#endif