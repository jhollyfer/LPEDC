// 0107 · Endereçamento aberto
// Exercício E640 · ★★☆

#include <stdio.h>

#define M 5
#define LIVRE -1

// devolve a posição usada ou -1 se a tabela está cheia
int insere(int tab[], int chave) {
    int i = chave % M;
    for (int passo = 0; passo < M; passo++) { // no máximo M tentativas
        if (tab[i] == LIVRE) {
            tab[i] = chave;
            return i;
        }
        i = (i + 1) % M;
    }
    return -1;
}

int main(void) {
    int tab[M];
    for (int i = 0; i < M; i++) {
        tab[i] = LIVRE;
    }
    int chaves[] = {12, 7, 3, 9, 15, 20};
    int n = 0;
    for (int k = 0; k < 6; k++) {
        int pos = insere(tab, chaves[k]);
        if (pos < 0) {
            printf("%d: tabela cheia!\n", chaves[k]);
        } else {
            n++;
            printf("%d -> %d (carga %.2f)\n", chaves[k], pos, (double)n / M);
        }
    }
    return 0;
}
