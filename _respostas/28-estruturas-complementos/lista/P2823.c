// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2823 · ★★★ · O passo zero da dispersão dupla

#include <stdio.h>

#define M 11

int passo(int k) {
    return 1 + k % (M - 1); // nunca 0
}

int main(void) {
    int t[M];
    for (int j = 0; j < M; j++) {
        t[j] = -1;
    }
    int cartoes[] = {21, 32, 10, 43};
    for (int c = 0; c < 4; c++) {
        int k = cartoes[c];
        int guardado = 0;
        for (int i = 0; i < M && !guardado; i++) {
            int j = (k % M + i * passo(k)) % M;
            if (t[j] == -1) {
                t[j] = k;
                guardado = 1;
                printf("%2d: passo %d -> %d\n", k, passo(k), j);
            }
        }
        if (!guardado) {
            printf("%2d: passo %d -> não coube\n", k, passo(k));
        }
    }
    printf("tabela:");
    for (int j = 0; j < M; j++) {
        if (t[j] == -1) {
            printf(" .");
        } else {
            printf(" %d", t[j]);
        }
    }
    printf("\n");
    return 0;
}
