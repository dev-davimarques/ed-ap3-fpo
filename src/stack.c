#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack *start_stack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void push(Stack *s, int id_tipo, const char *cor)
{
    Prato *p = malloc(sizeof(Prato));
    static int next_id = 1;

    p->id = next_id++;
    p->id_tipo = id_tipo;
    strncpy(p->cor, cor, sizeof(p->cor));
    p->prox = s->top;

    s->top = p;
    s->size++;
}

Prato *pop(Stack *s)
{
    if (s->top == NULL)
        return NULL;

    Prato *p = s->top;
    s->top = p->prox;
    s->size--;
    return p;
}

Prato *top_stack(const Stack *s)
{
    return s->top;
}

int empty_stack(const Stack *s)
{
    return s->size == 0;
}

int size_stack(const Stack *s)
{
    return s->size;
}

void displayStack(const Stack *s)
{
    if (s->top == NULL)
    {
        printf("Pilha vazia.\n");
        return;
    }

    Prato *cur = s->top;
    printf("Pilha (topo -> base):\n");
    while (cur)
    {
        printf("ID %d | Tipo %d | Cor: %s\n", cur->id, cur->id_tipo, cur->cor);
        cur = cur->prox;
    }
}

void free_stack(Stack *s)
{
    Prato *cur = s->top;
    while (cur)
    {
        Prato *tmp = cur;
        cur = cur->prox;
        free(tmp);
    }
    free(s);
}