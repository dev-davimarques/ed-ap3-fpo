#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"
#include "list.h"

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void read_line(char *buffer, int size)
{
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}

Queue *fila;
Stack *pilha;
List *insumos;

void adicionar_pedido()
{
    char prato[50];
    int mesa;

    printf("Nome do prato: ");
    clear_input_buffer();
    read_line(prato, sizeof(prato));

    printf("Mesa: ");
    scanf("%d", &mesa);

    enqueue(fila, prato, mesa);
}

void entregar_pedido()
{
    Pedido *p = dequeue(fila);
    if (!p)
    {
        printf("Fila vazia.\n");
        return;
    }

    printf("Pedido entregue: %s (Mesa %d)\n", p->prato, p->mesa);
    free(p);
}

void adicionar_prato()
{
    int tipo;
    char cor[20];

    printf("Tipo do prato: ");
    scanf("%d", &tipo);
    clear_input_buffer();

    printf("Cor do prato: ");
    read_line(cor, sizeof(cor));

    push(pilha, tipo, cor);
}

void lavar_prato()
{
    Prato *p = pop(pilha);
    if (!p)
    {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Prato lavado: Tipo %d | Cor %s\n", p->id_tipo, p->cor);
    free(p);
}

void novo_insumo()
{
    char nome[50];
    int qtd;

    clear_input_buffer();
    printf("Nome do insumo: ");
    read_line(nome, sizeof(nome));

    printf("Quantidade: ");
    scanf("%d", &qtd);

    add_insumo(insumos, nome, qtd);
}

void remover_insumo()
{
    int pos;
    Insumo *rem;

    printf("Posição: ");
    scanf("%d", &pos);

    if (remove_insumo_pos(insumos, pos, &rem))
    {
        printf("Removido: %s\n", rem->nome);
        free(rem);
    }
    else
    {
        printf("Posição inválida.\n");
    }
}

int main()
{
    fila = start_queue();
    pilha = start_stack();
    insumos = start_list();

    int opcao;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1 - Adicionar Pedido\n");
        printf("2 - Entregar Pedido\n");
        printf("3 - Receber Prato Sujo\n");
        printf("4 - Lavar Prato\n");
        printf("5 - Adicionar Insumo\n");
        printf("6 - Remover Insumo\n");
        printf("7 - Listar Pedidos\n");
        printf("8 - Listar Pratos\n");
        printf("9 - Listar Insumos\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionar_pedido();
            break;
        case 2:
            entregar_pedido();
            break;
        case 3:
            adicionar_prato();
            break;
        case 4:
            lavar_prato();
            break;
        case 5:
            novo_insumo();
            break;
        case 6:
            remover_insumo();
            break;
        case 7:
            displayQueue(fila);
            break;
        case 8:
            displayStack(pilha);
            break;
        case 9:
            display_list(insumos);
            break;
        }

    } while (opcao != 0);

    free_queue(fila);
    free_stack(pilha);
    free_list(insumos);

    return 0;
}
