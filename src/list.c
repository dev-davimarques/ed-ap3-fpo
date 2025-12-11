#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List *start_list()
{
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;
    return l;
}

void add_insumo(List *l, const char *nome, int quantidade)
{
    Insumo *i = malloc(sizeof(Insumo));
    strncpy(i->nome, nome, sizeof(i->nome));
    i->quantidade = quantidade;
    i->prox = NULL;

    if (l->head == NULL)
        l->head = i;
    else
    {
        Insumo *cur = l->head;
        while (cur->prox)
            cur = cur->prox;
        cur->prox = i;
    }
    l->size++;
}

int remove_insumo_pos(List *l, int pos, Insumo **removed)
{
    if (pos < 1 || pos > l->size)
        return 0;

    Insumo *cur = l->head;
    Insumo *prev = NULL;
    int idx = 1;

    while (idx < pos)
    {
        prev = cur;
        cur = cur->prox;
        idx++;
    }

    if (prev == NULL)
        l->head = cur->prox;
    else
        prev->prox = cur->prox;

    cur->prox = NULL;
    l->size--;
    *removed = cur;
    return 1;
}

void display_list(const List *l)
{
    Insumo *cur = l->head;
    int idx = 1;

    if (!cur)
    {
        printf("Lista vazia.\n");
        return;
    }

    printf("Insumos:\n");
    while (cur)
    {
        printf("%d) %s | Qtd: %d\n", idx, cur->nome, cur->quantidade);
        idx++;
        cur = cur->prox;
    }
}

void free_list(List *l)
{
    Insumo *cur = l->head;
    while (cur)
    {
        Insumo *tmp = cur;
        cur = cur->prox;
        free(tmp);
    }
    free(l);
}