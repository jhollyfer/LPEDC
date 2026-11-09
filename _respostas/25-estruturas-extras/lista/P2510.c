// Lista · Módulo 25 · Estruturas especiais
// Exercício P2510 · ★☆☆ · A conta da feira em formato esparso

#include <stdio.h>

typedef struct {
    int lin, col, valor;
} Tripla;

int main(void) {
    // compras[cliente][produto]: quantas unidades; só o que não é zero
    Tripla compras[] = {{0, 1, 2}, {0, 6, 1}, {1, 0, 3}, {1, 4, 2}, {1, 8, 5}, {2, 3, 1}, {3, 1, 4}, {3, 9, 2}};
    int n = 8, clientes = 4, produtos = 10;
    int preco[10] = {5, 8, 12, 3, 7, 10, 4, 6, 2, 9}; // preço de cada produto, em R$
    int conta[4] = {0};

    // y = A x: cada tripla contribui uma vez, sem olhar os zeros
    for (int k = 0; k < n; k++) conta[compras[k].lin] += compras[k].valor * preco[compras[k].col];

    for (int c = 0; c < clientes; c++) printf("cliente %d: R$ %d\n", c, conta[c]);
    printf("Multiplicações: %d (a matriz cheia faria %d)\n", n, clientes * produtos);
    return 0;
}
