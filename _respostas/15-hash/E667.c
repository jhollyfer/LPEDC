// 0112 · Endereçamento aberto
// Exercício E667 · ★☆☆

#include <stdio.h>

#define M 7
#define LIVRE -1

int main(void) {
    int tab[M];
    for (int i = 0; i < M; i++) {
        tab[i] = LIVRE;
    }
    int chaves[] = {10, 24, 5, 17, 31};
    for (int k = 0; k < 5; k++) {
        int i = chaves[k] % M;
        while (tab[i] != LIVRE) {
            i = (i + 1) % M; // a próxima, dando a volta
        }
        tab[i] = chaves[k];
    }
    for (int i = 0; i < M; i++) {
        if (tab[i] == LIVRE) {
            printf("[%d] -\n", i);
        } else {
            printf("[%d] %d\n", i, tab[i]);
        }
    }
    return 0;
}
