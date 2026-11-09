// Lista · Módulo 15 · Tabelas hash
// Exercício P1503 · ★☆☆ · Sondagem linear nos armários

#include <stdio.h>

#define M 11
#define VAZIO -1

// devolve quantas posições olhou
int insere(int tab[], int k) {
    int h = k % M;
    for (int i = 0; i < M; i++) {
        int pos = (h + i) % M;
        if (tab[pos] == VAZIO) {
            tab[pos] = k;
            return i + 1;
        }
    }
    return -1;
}

int main(void) {
    int tab[M];
    for (int i = 0; i < M; i++) {
        tab[i] = VAZIO;
    }
    int chaves[] = {35, 46, 13, 24, 57, 10, 21, 2};
    for (int i = 0; i < 8; i++) {
        int s = insere(tab, chaves[i]);
        printf("%d (h = %d): sondagens %d\n", chaves[i], chaves[i] % M, s);
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
