// 0107 · Endereçamento aberto
// Exercício E638 · ★☆☆

#include <stdio.h>

#define M 8

int main(void) {
    int tab[M] = {0}; // 0 = livre (nenhuma chave é 0)
    int chaves[] = {16, 8, 3, 24, 11};
    for (int k = 0; k < 5; k++) {
        int i = chaves[k] % M;
        int s = 1;
        while (tab[i] != 0) {
            i = (i + 1) % M;
            s++;
        }
        tab[i] = chaves[k];
        printf("%d: vaga %d (%d)\n", chaves[k], i, s);
    }

    int procurar[] = {24, 19};
    for (int k = 0; k < 2; k++) {
        int i = procurar[k] % M;
        int s = 1;
        while (tab[i] != 0 && tab[i] != procurar[k]) {
            i = (i + 1) % M;
            s++;
        }
        if (tab[i] == procurar[k]) {
            printf("busca %d: vaga %d (%d sondagens)\n", procurar[k], i, s);
        } else {
            printf("busca %d: não está (%d sondagens)\n", procurar[k], s);
        }
    }
    return 0;
}
