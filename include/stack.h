#ifndef STACK_H
#define STACK_H

typedef struct Prato
{
    int id;
    int id_tipo;
    char cor[20];
    struct Prato *prox;
} Prato;

typedef struct Stack
{
    Prato *top;
    int size;
} Stack;

Stack *start_stack();
void push(Stack *s, int id_tipo, const char *cor);
Prato *pop(Stack *s);
Prato *top_stack(const Stack *s);
int empty_stack(const Stack *s);
int size_stack(const Stack *s);
void displayStack(const Stack *s);
void free_stack(Stack *s);


#endif