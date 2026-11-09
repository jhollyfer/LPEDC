// Lista · Módulo 15 · Tabelas hash
// Exercício P1505 · ★☆☆ · Dispersão dupla no guarda-volumes

#include <stdio.h>

#define M 13
#define VAZIO -1

int h1(int k) {
    return k % M;
}

int h2(int k) {
    return 1 + k % 11;
}

int insere(int tab[], int k) {
    for (int i = 0; i < M; i++) {
        int pos = (h1(k) + i * h2(k)) % M;
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
    int tickets[] = {27, 40, 53, 14, 66, 1};
    for (int i = 0; i < 6; i++) {
        int k = tickets[i];
        printf("%d (h1 = %d, h2 = %d) -> posição %d\n", k, h1(k), h2(k), insere(tab, k));
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
