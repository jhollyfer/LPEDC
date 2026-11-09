// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2807 · ★☆☆ · Divisão e colisões

#include <stdio.h>

void testa(const int *k, int n, int m) {
    int conta[16] = {0};
    int colisoes = 0;
    printf("m = %2d:", m);
    for (int i = 0; i < n; i++) {
        int h = k[i] % m;
        printf(" %d", h);
        if (conta[h] > 0) {
            colisoes++;
        }
        conta[h]++;
    }
    printf(" | colisões: %d\n", colisoes);
}

int main(void) {
    int k[] = {1013, 2026, 3039, 4052, 5065, 1500, 2600, 3700};
    testa(k, 8, 13);
    testa(k, 8, 10);
    return 0;
}
