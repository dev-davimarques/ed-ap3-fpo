#ifndef LIST_H
#define LIST_H

typedef struct Insumo
{
    char nome[50];
    int quantidade;
    struct Insumo *prox;
} Insumo;

typedef struct List
{
    Insumo *head;
    int size;
} List;

List *start_list();
void add_insumo(List *l, const char *nome, int quantidade);
int remove_insumo_pos(List *l, int pos, Insumo **removed);
void display_list(const List *l);
void free_list(List *l);


#endif