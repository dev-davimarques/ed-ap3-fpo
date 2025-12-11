# Projeto Modular em C — Estruturas de Dados (Fila, Pilha e Lista)

A seguir estão todos os arquivos organizados, incluindo:

* **Makefile**
* **README.md**
* **Explicação para o professor**
* **Estrutura sugerida de diretórios**

## 📁 Estrutura de Pastas

```
projeto/
│
├── src/
│   ├── main.c
│   ├── queue.c
│   ├── stack.c
│   ├── list.c
│
├── include/
│   ├── queue.h
│   ├── stack.h
│   ├── list.h
│
├── Makefile
└── README.md
```

---

# 📌 Makefile

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = src/main.c src/queue.c src/stack.c src/list.c
OBJ = $(SRC:.c=.o)
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)
```

---

# 📘 README.md

```markdown
# Sistema de Restaurante — Estruturas de Dados em C

Este projeto implementa três estruturas de dados clássicas:

- **Fila (Queue)** — controla pedidos
- **Pilha (Stack)** — controla pratos sujos
- **Lista Encadeada (List)** — controla insumos do restaurante

O programa foi totalmente modularizado em arquivos `.c` e `.h`.

## 🚀 Como compilar

Certifique-se de estar dentro da pasta raiz do projeto e execute:

```

make

```

## ▶️ Executar o programa
```

make run

```

## 🧹 Limpar arquivos compilados
```

make clean

```

## 📁 Estrutura
- `src/` contém implementações das funções
- `include/` contém arquivos de cabeçalho (`.h`)
- `Makefile` compila tudo automaticamente

## 📝 Funcionalidades
1. Adicionar pedido à fila
2. Entregar pedido
3. Empilhar pratos sujos
4. Lavar (desempilhar) pratos
5. Adicionar insumo
6. Remover insumo
7. Listar pedidos
8. Listar pratos
9. Listar insumos

---

# Explicação para o Professor

O projeto demonstra domínio de **modularização em C**, permitindo separar lógica, estrutura de dados e interface do programa.

## 📌 Estruturas implementadas
### 1. **Fila (Queue)**
Usada para controlar pedidos que chegam ao restaurante. Implementada com ponteiros para `head` e `tail`, permitindo inserção e remoção em tempo constante.

### 2. **Pilha (Stack)**
Utilizada para empilhar pratos sujos. Implementada com inserção e remoção no topo.

### 3. **Lista Encadeada (List)**
Mantém os insumos do restaurante. Insere no final e permite remoção por posição.

## 📌 Conceitos avaliados
- **Alocação dinâmica (malloc/free)**
- **Listas encadeadas, pilhas e filas**
- **Modularização em C (arquivos .h e .c)**
- **Passagem de ponteiros entre módulos**
- **Organização de projeto**
- **Uso adequado de header guards**

## 🧹 Gerenciamento de memória
O programa evita vazamentos graças às funções:
- `free_queue()`
- `free_stack()`
- `free_list()`

Chamadas no final da `main()`.

Essas funções percorrem cada estrutura liberando todos os nós.

---


```
