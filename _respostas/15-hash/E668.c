// 0112 · Endereçamento aberto
// Exercício E668 · ★☆☆
//
// Resposta:
// 16: vaga 0 (1)
// 8: vaga 1 (2)
// 3: vaga 3 (1)
// 24: vaga 2 (3)
// 11: vaga 4 (2)
// 16, 8 e 24 têm hash 0 e formam um bloco 0-1-2; o 11 (hash 3) encontra o 3
// na sua vaga e vai para a 4.

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
    return 0;
}
