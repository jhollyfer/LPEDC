// 0125 · Subconjuntos
// Exercício E745 · ★☆☆

#include <stdio.h>

#define N 3

int main(void) {
    const char *itens[N] = {"arroz", "feijão", "salada"};

    for (int m = 0; m < (1 << N); m++) {
        int algum = 0;
        printf("%d:", m);
        for (int i = 0; i < N; i++) {
            if (m & (1 << i)) {
                printf(" %s", itens[i]);
                algum = 1;
            }
        }
        if (!algum) {
            printf(" só a carne");
        }
        printf("\n");
    }
    return 0;
}
