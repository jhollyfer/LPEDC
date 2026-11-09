// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1802 · ★☆☆ · Shell sort com os saltos de Shell: n/2, n/4, ..., 1

#include <stdio.h>

#define N 10

int main(void) {
    int v[N] = {190, 175, 201, 168, 183, 178, 194, 172, 186, 181};

    printf("início:");
    for (int i = 0; i < N; i++) printf(" %d", v[i]);
    printf("\n");
    for (int h = N / 2; h >= 1; h /= 2) {
        int comparacoes = 0;
        for (int i = h; i < N; i++) { // insertion sort com passo h
            int x = v[i], j = i;
            while (j - h >= 0) {
                comparacoes++;
                if (v[j - h] <= x) break;
                v[j] = v[j - h];
                j -= h;
            }
            v[j] = x;
        }
        printf("h = %d: ", h);
        for (int i = 0; i < N; i++) printf(" %d", v[i]);
        printf("  (%d comparações)\n", comparacoes);
    }
    return 0;
}
