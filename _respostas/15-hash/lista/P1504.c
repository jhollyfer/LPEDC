// Lista · Módulo 15 · Tabelas hash
// Exercício P1504 · ★☆☆ · Sondagem quadrática nas vagas

#include <stdio.h>

#define M 8
#define VAZIO -1

int insere(int tab[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (k % M + (i + i * i) / 2) % M;
        if (tab[pos] == VAZIO) {
            tab[pos] = k;
            return pos;
        }
    }
    return -1;
}

int main(void) {
    int tab[M];
    for (int i = 0; i < M; i++) {
        tab[i] = VAZIO;
    }
    int placas[] = {12, 20, 4, 28, 13, 36};
    for (int i = 0; i < 6; i++) {
        printf("%d -> posição %d\n", placas[i], insere(tab, placas[i]));
    }
    printf("tabela:");
    for (int i = 0; i < M; i++) {
        if (tab[i] == VAZIO) {
            printf(" _");
        } else {
            printf(" %d", tab[i]);
        }
    }
    printf("\n");
    return 0;
}
