// Lista · Módulo 21 · Programação dinâmica
// Exercício P2112 · ★★☆ · A mochila de uma linha só

#include <stdio.h>

#define N 4
#define CAP 10

int main(void) {
    const int kg[N] = {4, 3, 5, 2};
    const int valor[N] = {40, 27, 45, 16};
    int melhor[CAP + 1] = {0};
    for (int i = 0; i < N; i++) {
        for (int w = CAP; w >= kg[i]; w--) {
            if (melhor[w - kg[i]] + valor[i] > melhor[w]) {
                melhor[w] = melhor[w - kg[i]] + valor[i];
            }
        }
    }
    printf("Melhor valor em %d kg: R$ %d\n", CAP, melhor[CAP]);
    return 0;
}
