// Lista · Módulo 06 · Ponteiros
// Exercício P0611 · ★★☆ · Lado par, lado ímpar

#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separar(int *v, int n) {
    int *esq = v;
    int *dir = v + n - 1;
    while (esq < dir) {
        while (esq < dir && *esq % 2 == 0) {
            esq++;
        }
        while (esq < dir && *dir % 2 != 0) {
            dir--;
        }
        if (esq < dir) {
            troca(esq, dir);
        }
    }
    // esq parou no primeiro ímpar (ou no último elemento)
    return (int) (esq - v) + (*esq % 2 == 0);
}

int main(void) {
    int casas[10] = {15, 8, 23, 42, 7, 10, 31, 6, 19, 4};

    int k = separar(casas, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d%s", casas[i], i < 9 ? " " : "\n");
    }
    printf("Pares: %d casas; o lado ímpar começa na posição %d\n", k, k);
    return 0;
}
