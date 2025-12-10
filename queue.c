#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pedido {
    int id_pedido;
    char nome_prato[50];
    int numero_mesa;
    struct Pedido* proximo;
} Pedido;

typedef struct {
    Pedido* frente;
    Pedido* fim;
} FilaPedidos;

FilaPedidos* criarFila();
void novoPedido(FilaPedidos* fila, int id, const char *prato, int mesa);
void entregarPedido(FilaPedidos* fila);
void listarFila(FilaPedidos* fila);
int filaVazia(const FilaPedidos* fila);

FilaPedidos* criarFila() {
    FilaPedidos* novafila = (FilaPedidos*)malloc(sizeof(FilaPedidos));
    if (novafila == NULL) {
        perror("Erro ao alocar memória para a fila");
        exit(EXIT_FAILURE);
    }
    novafila->frente = NULL;
    novafila->fim = NULL;
    return novafila;
}

int filaVazia(const FilaPedidos* fila) {
    return fila->frente == NULL;
}

void novoPedido(FilaPedidos* fila, int id, const char *prato, int mesa) {
    Pedido* novo = (Pedido*)malloc(sizeof(Pedido));
    if (novo == NULL){
        perror("Erro ao colocar pedido a fila");
        exit(EXIT_FAILURE);
    }

    novo->id_pedido = id;
    strncpy(novo->nome_prato, prato, sizeof(novo->nome_prato) - 1);
    novo->nome_prato[sizeof(novo->nome_prato) - 1] = '\0';
    novo->numero_mesa = mesa;
    novo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->frente = novo;
        fila->fim = novo;
    } else{
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
    printf("\n Pedido #%d (%s - Mesa %d) adicionado a fila. \n", id, prato, mesa);
}

void entregarPedido(FilaPedidos* fila) {
    if (filaVazia(fila)){
        printf("\n A fila de pedidos esta vazia. Nao ha nada para entregar.\n");
        return;
    }
    Pedido* entregue = fila->frente;
    fila->frente = fila->frente->proximo;
    
    if (fila->frente == NULL) {
        fila->fim = NULL;
    }

    printf("\n Entregue: Pedido #%d (%s) da Mesa %d. (Removido da fila)\n",
        entregue->id_pedido, entregue->nome_prato, entregue->numero_mesa);

    free(entregue);
}

void listarFila(FilaPedidos* fila) {
    if (filaVazia(fila)){
        printf("\n A fila de pedidos para preparo esta vazia.\n");
        return;
    }

    printf("\n===== PEDIDOS AGUARDANDO PREPARO (FILA FIFO) =====\n");
    printf(" ORDEM | ID | PRATO | MESA \n");
    printf("-------------------------------------------------\n");

    Pedido* atual = fila->frente;
    int ordem = 1;
    while (atual != NULL) {
        printf(" %5d | %2d | %s | %d\n", ordem, atual->id_pedido, atual->nome_prato, atual->numero_mesa);
        atual = atual->proximo;
        ordem++;
    }
    printf("==================================================\n");
}

int main() {
    FilaPedidos* cozinha = criarFila();

    printf("--- SIMULACAO DA COZINHA (FILA FIFO) ---\n");

    novoPedido(cozinha, 101, "lasanha", 5);
    novoPedido(cozinha, 102, "File de Frango", 2);
    novoPedido(cozinha, 103, "Carne de Porco", 8);

    listarFila(cozinha);
    entregarPedido(cozinha);
    novoPedido(cozinha, 104, "Pizza de Batata Frita", 1);
    listarFila(cozinha);
    entregarPedido(cozinha);
    
    entregarPedido(cozinha);
    entregarPedido(cozinha);
    entregarPedido(cozinha);

    if (cozinha != NULL) {
        free(cozinha);
    }
    
    return 0;
}