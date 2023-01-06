/**
 * ----------------------------------------------
 *                   lists.c
 * ----------------------------------------------
 * 
 * Implementation of list in the form of linked
 * lists.
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"


// ----- Main functions -----


/**
 * Creates an empty list
 * @return NULL pointer 
 */
List createEmptyList() {
    return NULL;
}


/**
 * Checks wether the list is empty or not
 * @param _list The list to check
 * @return 1 if empty, 0 otherwise
 */
Bool isEmptyList(List _list) {
    return _list == NULL;
}


/**
 * Add new element to list
 * @param _data The data to add to the list
 * @param _list The list in which to add
 * @return A pointer to the newly added element
 */
List addList(Variant _data, List _list) {
    List new_list = malloc(LINK_SIZE);
    new_list->element = _data;
    new_list->next = _list;
    return new_list;
}


/**
 * Get the head element of a list
 * @param _list A linked list
 * @return The head of the list
 */
Variant headList(List _list){
    return _list->element;
}


/**
 * Get the head element of a list
 * @param _list A linked list
 * @return The tail of the list
 */
List tailList(List _list){
    return _list->next;
}


// ----- Toolbox -----


/**
 * Print a list on console
 * @param _list The list we want to display
 */
void printList(List _list){
    List current = _list;
    if(!isEmptyList(current)){
        printf("%p\n", _list->element);
        current = tailList(_list);
    }
}


// ------ Memory management functions -----


/**
 * Copy a list
 * @param _list The list we want to copy
 * @return A copy of the list
 */
List copy(List _list){
    if(!isEmptyList(_list)){
        return (addList(headList(_list), copy(tailList(_list))));
    }
    else{
        return createEmptyList();
    }
}


/**
 * Free the head of a list
 * @param _list The list we want to behead
 * @return The tail of the list
 */
List freeHead(List _list){
    assert(!isEmptyList(_list));
    List tmp = _list->next;
    free(_list);
    return tmp;
}


/**
 * Free an entire list
 * @param _list The list we want to kill
 */
void freeList(List _list){
    if(isEmptyList(_list)){
        return;
    }
    else{
        freeList(tailList(_list));
        free(_list);
    }
}