#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue start_queue()
{
    Queueq = malloc(sizeof(Queue));
    q->head = q->tail = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue q, const charprato, int mesa)
{
    Pedido p = malloc(sizeof(Pedido));
    static int next_id = 1;
    p->id = next_id++;
    strncpy(p->prato, prato, sizeof(p->prato));
    p->mesa = mesa;
    p->prox = NULL;

    if (q->tail == NULL)
        q->head = q->tail = p;
    else
    {
        q->tail->prox = p;
        q->tail = p;
    }
    q->size++;
}

Pedidodequeue(Queue q)
{
    if (q->head == NULL)
        return NULL;
    Pedidop = q->head;
    q->head = q->head->prox;
    if (q->head == NULL)
        q->tail = NULL;
    q->size--;
    return p;
}

int empty_queue(const Queue q)
{
    return q->size == 0;
}

int size_queue(const Queueq)
{
    return q->size;
}

void displayQueue(const Queue q)
{
    Pedidocur = q->head;
    if (!cur)
    {
        printf("Fila vazia.\n");
        return;
    }

    printf("Pedidos:\n");
    while (cur)
    {
        printf("ID %d | Mesa %d | Prato: %s\n", cur->id, cur->mesa, cur->prato);
        cur = cur->prox;
    }
}

void free_queue(Queue q)
{
    Pedidocur = q->head;
    while (cur)
    {
        Pedido *tmp = cur;
        cur = cur->prox;
        free(tmp);
    }
    free(q);
}