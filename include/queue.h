#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*structs*/

typedef struct Pedido {
    int id;
    char prato[50];
    int mesa;
    struct Pedido *prox;
} Pedido;

typedef struct Fila {
    Pedido *inicio;
    Pedido *fim;
    int qtd;
} Fila;

/* funções */

Fila* criarFila();
void novoPedido(Fila *f, char prato[], int mesa);
void entregarPedido(Fila *f);
void listarFila(Fila *f);

#endif
