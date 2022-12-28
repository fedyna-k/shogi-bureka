/**
 * ----------------------------------------------
 *                   lists.h
 * ----------------------------------------------
 * 
 * Implementation of list in the form of linked
 * lists.
 */


#ifndef __LISTS_H__
#define __LISTS_H__


// ----- Dependancy -----


#include "bool.h"
#include "variant.h"


// ----- Constants and structs -----

#define LINK_SIZE sizeof(struct __s_List)

struct __s_List {
    Variant element;
    struct __s_List *next;
};

typedef struct __s_List *List;


// ----- Functions -----

// Main functions

List createEmptyList();
Bool isEmptyList(List _list);
List addList(Variant _data, List _list);
Variant headList(List _list);
List tailList(List _list);

// Toolbox

void printList(List _list);

// Memory management functions

List copy(List _list);
List freeHead(List _head);
void freeList(List _list);


#endif