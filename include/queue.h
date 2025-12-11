#ifndef QUEUE_H
#define QUEUE_H

typedef struct Pedido {
    int id;
    char prato[50];
    int mesa;
    struct Pedido *prox;
} Pedido;

typedef struct Queue {
    Pedido *head;
    Pedido *tail;
    int size;
} Queue;

Queue* start_queue();
void enqueue(Queue* q, const char *prato, int mesa);
Pedido* dequeue(Queue* q);
int empty_queue(const Queue* q);
int size_queue(const Queue* q);
void displayQueue(const Queue* q);
void free_queue(Queue *q);


#endif