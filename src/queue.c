#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*funções*/

Fila* criarFila() {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->qtd = 0;
    return f;
}

void novoPedido(Fila *f, char prato[], int mesa) {
    Pedido *p = (Pedido*) malloc(sizeof(Pedido));
    static int nextID = 1;

    p->id = nextID++;
    strcpy(p->prato, prato);
    p->mesa = mesa;
    p->prox = NULL;

    if (f->fim == NULL) {
        f->inicio = f->fim = p;
    } else {
        f->fim->prox = p;
        f->fim = p;
    }

    f->qtd++;
    printf("Pedido adicionado! ID:%d | Mesa:%d | Prato:%s\n", p->id, p->mesa, p->prato);
}

void entregarPedido(Fila *f) {
    if (f->inicio == NULL) {
        printf("Nenhum pedido na fila.\n");
        return;
    }

    Pedido *p = f->inicio;
    f->inicio = p->prox;

    if (f->inicio == NULL)
        f->fim = NULL;

    printf("Pedido entregue! ID:%d | Mesa:%d | Prato:%s\n", p->id, p->mesa, p->prato);

    free(p);
    f->qtd--;
}

void listarFila(Fila *f) {
    if (f->inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\n--- Fila de Pedidos ---\n");
    Pedido *aux = f->inicio;

    while (aux != NULL) {
        printf("ID:%d | Mesa:%d | Prato:%s\n", aux->id, aux->mesa, aux->prato);
        aux = aux->prox;
    }
}

/*main*/

int main() {
    Fila *fila = criarFila();
    int op, mesa;
    char prato[50];

    do {
        printf("\n=========== RESTAURANTE ===========\n");
        printf("1 – Novo Pedido\n");
        printf("2 – Entregar Pedido\n");
        printf("3 – Listar Fila\n");
        printf("0 – Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        getchar(); // limpar 

        switch (op) {
            case 1:
                printf("Nome do prato: ");
                fgets(prato, 50, stdin);
                prato[strcspn(prato, "\n")] = '\0';

                printf("Número da mesa: ");
                scanf("%d", &mesa);

                novoPedido(fila, prato, mesa);
                break;

            case 2:
                entregarPedido(fila);
                break;

            case 3:
                listarFila(fila);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (op != 0);

    return 0;
}
