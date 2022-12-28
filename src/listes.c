#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "listes.h"



List create_empty_list();
bool is_empty_list(List l);
List add(Data e, List l);
Data head(List l);
List tail(List l);
void print_list(List l);
List copy(List l);
List free_head(maillon *);
void free_list(List l);


List create_empty_list(){
    return NULL;
}

bool is_empty_list(List l){
    if(l == NULL)
        return 1;
    else
        return 0;
}

List add(Data e, List l){
    maillon * tmp = malloc(sizeof(maillon));
    tmp->elt = e;
    tmp->next = l;
    return tmp;
}

Data head(List l){
    return (l->elt);
}

List tail(List l){
    return (l->next);
}

void print_list(List l){
    if(!is_empty_list(l)){
        printf("%d\n",l->elt);
        print_list(tail(l));
    }
}

List copy(List l){
    if(!is_empty_list(l)){
        return (add(head(l),copy(tail(l))));
    }
    else{
        return create_empty_list();
    }
}

List free_head(List l){
    assert(!is_empty_list(l));
    List tmp = l->next;
    free(l);
    return tmp;
}

void free_list(List l){
    if(is_empty_list(l)){
        return;
    }
    else{
        free_list(tail(l));
        free(l);
    }
}