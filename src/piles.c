#include "piles.h"
#include "listes.h"
#include <assert.h>
#include <stdlib.h>


bool is_empty_stack(Stack s);
Stack create_empty_stack();
void push(Data e, Stack s);
Data top(Stack s);
Data pop(Stack s);


bool is_empty_stack(Stack s){
    assert(s!=NULL);
    return (s->size == 0);
}

Stack create_empty_stack(){
    Stack tmp = malloc(sizeof(struct zstack));
    tmp->size = 0;
    tmp->top = NULL;

    return tmp;
}

void push(Data e, Stack s){
    s->top = add(e,s->top);
    s->size++;
}

Data top(Stack s){
    assert(!is_empty_stack(s));
    return s->top->elt;
}

Data pop(Stack s){
    assert(!is_empty_stack(s));
    Data e = head(s->top);
    List l = s->top;
    s->top = tail(s->top);
    s->size--;
    free(l);
    return e;
}