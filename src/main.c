#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



// Para a Fila (Pedidos)
typedef struct Pedido
{
    int id;
    char prato[50];
    struct Pedido *prox;
} Pedido;
// QUEUE
typedef struct queue{
    Pedido *head;
    Pedido *tail;
    int size;
} Queue;
// Inicializar a QUEUE/FILA
Queue* start_queue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return q;
}
// Assinatura dos métodos
void enqueue(Queue* q, char value);
char dequeue(Queue* q);
int size_queue(const Queue* q); // mudar nome na criação do método
char head(const Queue* q);
int empty_queue(const Queue* q); // mudar nome na criação do método
void displayQueue(const Queue* q);





// Para a Pilha (Pratos Sujos)
typedef struct Prato
{
    int id_tipo; // 1-Raso, 2-Fundo, etc.
    char cor[20];
    struct Prato *prox;
} Prato;
// STACK
typedef struct stack{
    Prato *top;
    int size;
} Stack;
// Inicializar a STACK/PILHA
Stack* start_stack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;

    return s;
}
// Assinatura dos métodos
void push(Stack *s, char element);
char top(Stack *s);
char pop(Stack *s);
int empty_stack(Stack *s); // mudar nome na criação do método
int size_stack(const Stack *s); // // mudar nome na criação do método





// Para a Lista (Ingredientes)
typedef struct Insumo
{
    char nome[50];
    int quantidade;
    struct Insumo *prox;
} Insumo;
// LIST
typedef struct list{
    Insumo *head;
    int size;
} List;
// Inicializar LINKED_LIST/LISTA_ENCADEADA
List* start_list() {
    List *l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;

    return l;
}
// Assinatura dos métodos
void add(List *l, char character);
void add_pos(List *l, char character, int position);
char get(List *l, int position);
void set(List *l, int position, char character);
char delete(List *l, int position);
int size(List *l);
int empty(List *l);
void print(List *l);
void destroy(List *l);






int main(int argc, char const *argv[])
{
    printf("Hello, world!\n");
    return 0;
}
