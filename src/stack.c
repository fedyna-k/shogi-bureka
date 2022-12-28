/**
 * ----------------------------------------------
 *                   stack.c
 * ----------------------------------------------
 * 
 * Implementation of stack using the linked list
 * module.
 */



#include "stack.h"
#include "lists.h"
#include <assert.h>
#include <stdlib.h>


/**
 * Create an empty stack
 * @return A new allocated empty stack
 */
Stack createEmptyStack() {
    Stack new_stack = malloc(STACK_SIZE);
    new_stack->size = 0;
    new_stack->top = NULL;

    return new_stack;
}


/**
 * Checks wether a stack is empty or not
 * @param _stack The stack to check
 * @return 1 if empty, 0 otherwise
 */
Bool isEmptyStack(Stack _stack) {
    assert(_stack!=NULL);
    return _stack->size == 0;
}


/**
 * Push pointer to data on top of stack
 * @param _data The data to push on top
 * @param _stack The stack used to store
 */
void pushStack(Variant _data, Stack _stack) {
    _stack->top = addList(_data, _stack->top);
    _stack->size++;
}


/**
 * Get top of stack without poping it
 * @param _stack The stack
 * @return The top of the stack
 */
Variant topStack(Stack _stack) {
    assert(!isEmptyStack(_stack));
    return _stack->top->element;
}


/**
 * Get the top of the stack and pops it
 * @param _stack The stack
 * @return The top of the stack
 */
Variant popStack(Stack _stack) {
    assert(!isEmptyStack(_stack));

    // Get top value and address
    Variant data = headList(_stack->top);
    List top = _stack->top;
    
    // Pop from stack
    _stack->top = tailList(_stack->top);
    _stack->size--;

    // Free old top and return value
    free(top);
    return data;
}