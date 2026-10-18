// 0107 · Endereçamento aberto
// Exercício E641 · ★★★

#include <stdio.h>

#define M 7

int insere(int tab[], int chave) {
    int i = chave % M;
    int s = 1;
    while (tab[i] != 0) {
        i = (i + 1) % M; // dá a volta no fim do vetor
        s++;
    }
    tab[i] = chave;
    return s;
}

int main(void) {
    int tab[M] = {0}; // 0 = livre
    int chaves[] = {9, 13, 20, 4};
    for (int k = 0; k < 4; k++) {
        printf("%d: %d sondagem(ns)\n", chaves[k], insere(tab, chaves[k]));
    }
    for (int i = 0; i < M; i++) {
        printf("[%d] %d\n", i, tab[i]);
    }
    return 0;
}
