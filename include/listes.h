#ifndef __LISTES_H__
#define __LISTES_H__

typedef int Data;
struct zmaillon{
    Data elt;
    struct zmaillon * next;
};
typedef struct zmaillon maillon;
typedef maillon * List;
typedef char bool;

List create_empty_list();
bool is_empty_list(List l);
List add(Data e, List l);
Data head(List l);
List tail(List l);
List copy(List l);
void print_list(List l);
List free_head(maillon *);
void free_list(List l);

#endif