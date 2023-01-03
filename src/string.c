/**
 * ----------------------------------------------
 *                    string.c
 * ----------------------------------------------
 * 
 * Simple string module that allow to concatenate
 * and compare UTF-8 strings.
 */


#include "string.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * Concatenate two strings
 * @param _first_string The left member of the string 
 * @param _second_string The right member of the string 
 * @return The concatenated string
 * 
 * @example
 * String f = setString("Hello, "), s = setString("World !");
 * concat(f, s) // return the String "Hello, World !"
 */
String concat(String _first_string, String _second_string){
    int i;
    String result;
    result.value = malloc(sizeof(char) * (_first_string.length + _second_string.length) + 1);

    // Copy of first string
    for (i = 0; i < _first_string.length; i++){
        result.value[i] = _first_string.value[i];
    }
    // Copy of second string
    for (i = _first_string.length; i < (_first_string.length + _second_string.length); i++){
        result.value[i] = _second_string.value[i - _first_string.length];
    }

    // Length of the combined strings
    result.length = _first_string.length + _second_string.length;
    result.value[result.length] = 0;

    return result;
}


/**
 * Returns 1 if the two strings are the same, 0 if not
 * @param _first_string The first string to test
 * @param _second_string The second string to test
 * @return A bool
 * 
 * @example
 * String f = setString("Hello, "), s = setString("World !");
 * isEqualString(f, s) // returns 0
 */
Bool isEqualString(String _first_string, String _second_string){
    int i;
    // If lengths are different, the strings will also be
    if (_first_string.length != _second_string.length)
        return 0;
    
    // Otherwise, check until we find a different char
    for (i = 0; i < _first_string.length; i++){
        if (_first_string.value[i] != _second_string.value[i])
            return 0;
    }
    
    return 1;    
}


/**
 * Returns the value of the string
 * @param _string The string to handle
 * @return A C string object (char *)
 * 
 * @example
 * getString(vroum);
 */
char *getString(String _string){
    return _string.value;
}


/**
 * Set the value and the corresponding length of a string
 * @param _string The char array (C string) value to use
 * @return A String object which contains _string value
 * 
 * @example
 * String vroum = setString("voiture");
 */
String setString(char *_string){
    String result;
    int len = 0;

    // Compute length
    while (_string[len] != 0){
        len++;
    }

    // Free the old value (avoids memory leaks)
    free(result.value);

    // Copies the char *
    result.value = _string;
    
    // Sets the string's length
    result.length = len;

    return result;
}


/**
 * Tool function to rapidly print a string
 * @param _string The string to print on console
 */
void printString(String _string){
    int i;

    for (i = 0; i < _string.length; i++){
        printf("%c", _string.value[i]);
    }

    printf("\n");
}