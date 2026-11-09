// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1807 · ★☆☆ · Quantas corridas entre R$ 10 e R$ 20? Em O(1)

#include <stdio.h>

#define N 20
#define K 51 // valores de 0 a 50

int entre(const int c[], int a, int b) {
    return c[b] - (a > 0 ? c[a - 1] : 0); // O(1)
}

int main(void) {
    int corrida[N] = {12, 8, 25, 15, 33, 9, 18, 20, 41, 15,
                      7, 22, 10, 50, 13, 27, 19, 0, 36, 11};
    int perguntas[][2] = {{10, 20}, {0, 50}, {0, 9}, {15, 15}, {30, 50}};
    int c[K] = {0};

    for (int i = 0; i < N; i++) c[corrida[i]]++;  // Θ(n)
    for (int x = 1; x < K; x++) c[x] += c[x - 1]; // Θ(k)

    for (int q = 0; q < 5; q++) {
        int a = perguntas[q][0], b = perguntas[q][1];
        printf("Entre R$ %2d e R$ %2d: %2d corridas\n", a, b, entre(c, a, b));
    }
    return 0;
}
