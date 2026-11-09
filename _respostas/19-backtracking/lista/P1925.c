// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1925 · ★★★ · A poda que corta demais

#include <stdio.h>

#define N 7
#define ALVO 30

const int cesta[N] = {18, 14, 11, 9, 7, 5, 3};
int leva[N];
int lotes = 0;

void busca(int i, int soma) {
    if (soma == ALVO) {
        lotes++;
        printf("Lote %d:", lotes);
        for (int j = 0; j < N; j++) {
            if (leva[j]) {
                printf(" %d", cesta[j]);
            }
        }
        printf("\n");
        return;
    }
    if (i == N) {
        return;
    }
    if (soma + cesta[i] <= ALVO) {
        leva[i] = 1;
        busca(i + 1, soma + cesta[i]);
        leva[i] = 0;
    }
    busca(i + 1, soma);
}

int main(void) {
    busca(0, 0);
    printf("Total: %d lotes\n", lotes);
    return 0;
}
