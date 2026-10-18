// 0054 · malloc e free
// Exercício E321 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int *filtrar_pares(const int *v, int n, int *qtd) {
    int pares = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            pares++;
        }
    }
    *qtd = 0;
    if (pares == 0) {
        return NULL;
    }
    int *novo = malloc(pares * sizeof *novo);
    if (novo == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            novo[*qtd] = v[i];
            (*qtd)++;
        }
    }
    return novo;
}

int main(void) {
    int sorteados[] = {7, 4, 10, 3, 8, 1, 6};
    int qtd;
    int *pares = filtrar_pares(sorteados, 7, &qtd);
    if (pares == NULL) {
        printf("Nenhum par\n");
        return 0;
    }
    printf("%d pares:", qtd);
    for (int i = 0; i < qtd; i++) {
        printf(" %d", pares[i]);
    }
    printf("\n");
    free(pares);
    return 0;
}
// Saída:
// 4 pares: 4 10 8 6
