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
List addList(ListElem _data, List _list) {
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
ListElem headList(List _list){
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
        printf("%d\n", _list->element);
        current = tailList(_list);
    }
}


// ------ Memory management functions -----


List copy(List l){
    if(!is_empty_list(l)){
        return (add(head(l),copy(tail(l))));
    }
    else{
        return create_empty_list();
    }
}

List freeHead(List l){
    assert(!is_empty_list(l));
    List tmp = l->next;
    free(l);
    return tmp;
}

void freeList(List l){
    if(is_empty_list(l)){
        return;
    }
    else{
        free_list(tail(l));
        free(l);
    }
}