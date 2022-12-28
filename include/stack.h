/**
 * ----------------------------------------------
 *                   stack.h
 * ----------------------------------------------
 * 
 * Implementation of stack using the linked list
 * module.
 */


#ifndef __STACK_H__
#define __STACK_H__


// ----- Dependancy -----


#include "bool.h"
#include "lists.h"
#include "variant.h"


// ----- Constants and structs -----


#define STACK_SIZE sizeof(struct __s_Stack)

struct __s_Stack {
    List top;
    int size;
};

typedef struct __s_Stack *Stack;


// ----- Functions -----


Stack createEmptyStack();
Bool isEmptyStack(Stack _stack);
void pushStack(Variant _data, Stack _stack);
Variant topStack(Stack _stack);
Variant popStack(Stack _stack);



#endif