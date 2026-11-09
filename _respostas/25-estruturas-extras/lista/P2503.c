// Lista · Módulo 25 · Estruturas especiais
// Exercício P2503 · ★☆☆ · Busca binária nas triplas

#include <stdio.h>

typedef struct {
    int lin, col, valor;
} Tripla;

// as triplas estão em ordem de (lin, col): dá para fazer busca binária
int valor(const Tripla t[], int n, int i, int j, int *comparacoes) {
    int ini = 0, fim = n - 1;
    *comparacoes = 0;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        (*comparacoes)++;
        if (t[meio].lin == i && t[meio].col == j) return t[meio].valor;
        if (t[meio].lin < i || (t[meio].lin == i && t[meio].col < j)) ini = meio + 1;
        else fim = meio - 1;
    }
    return 0;
}

int main(void) {
    // consumo (kWh) de cada apartamento (andar, número) que teve leitura
    Tripla leituras[] = {{0, 1, 120}, {0, 4, 95}, {1, 2, 210}, {2, 0, 80}, {2, 3, 150},
                         {3, 1, 175}, {4, 4, 60}, {5, 2, 190}, {6, 0, 130}, {7, 3, 105}};
    int n = 10;
    int perguntas[][2] = {{2, 3}, {0, 1}, {7, 3}, {4, 2}, {5, 2}};
    for (int k = 0; k < 5; k++) {
        int c;
        int v = valor(leituras, n, perguntas[k][0], perguntas[k][1], &c);
        printf("(%d, %d): %3d kWh, %d comparação(ões)\n", perguntas[k][0], perguntas[k][1], v, c);
    }
    return 0;
}
