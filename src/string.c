#include "string.h"
#include <stdlib.h>
#include <stdio.h>

// Concats 2 strings
String concat(String first_string, String second_string){
    int i;
    String result;
    result.value = malloc(sizeof(char) * (first_string.length + second_string.length));

    // Copy of first string
    for (i = 0; i < first_string.length; i++){
        result.value[i] = first_string.value[i];
    }
    // Copy of second string
    for (i = first_string.length; i < (first_string.length + second_string.length); i++){
        result.value[i] = second_string.value[i - first_string.length];
    }
    // Length of the combined strings
    result.length = first_string.length + second_string.length;


    return result;
}

// Returns 1 if the two strings are the same, 0 if not
Bool isEqual(String first_string, String second_string){
    int i;
    if (first_string.length != second_string.length)
        return 0;
    else{
        for (i = 0; i < first_string.length; i++){
            if (first_string.value[i] != second_string.value[i])
                return 0;
        }
        return 1;
    }
}

// Returns the value of the string
char * getString(String string){
    return string.value;
}

String setString(char * chain){
    String result;
    int i = 0;

    while (chain[i] != 0){
        i++;
    }
    // Copies the char*
    result.value = chain;
    // Sets the string's length
    result.length = i;

    return result;
}

void printString(String string){
    int i;
    for (i = 0; i < string.length; i++){
        printf("%c", string.value[i]);
    }
    printf("\n");
}