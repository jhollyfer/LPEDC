// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1901 · ★☆☆ · Três sabores no pote

#include <stdio.h>

#define N 5
#define K 3

const char *sabores[N] = {"açaí", "cupuaçu", "tapioca", "graviola", "buriti"};
int esc[K];
int potes = 0;

void combina(int ini, int k) {
    if (k == K) {
        potes++;
        printf("%2d:", potes);
        for (int j = 0; j < K; j++) {
            printf(" %s", sabores[esc[j]]);
        }
        printf("\n");
        return;
    }
    for (int i = ini; i < N; i++) {
        esc[k] = i;
        combina(i + 1, k + 1);
    }
}

int main(void) {
    combina(0, 0);
    printf("Total: %d potes\n", potes);
    return 0;
}
