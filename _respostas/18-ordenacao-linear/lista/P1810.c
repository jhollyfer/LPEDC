// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1810 · ★☆☆ · Conserte o counting sort das notas

#include <stdio.h>

#define N 12
#define K 10 // notas de 0 a K

int main(void) {
    int nota[N] = {7, 10, 3, 5, 8, 0, 10, 6, 4, 7, 9, 5};
    int saida[N], c[K + 1] = {0}; // erro 1: de 0 a K são K + 1 posições

    for (int i = 0; i < N; i++) c[nota[i]]++;
    for (int x = 1; x <= K; x++) c[x] += c[x - 1]; // erro 2: começa em 1 (c[-1] não existe)
    for (int i = N - 1; i >= 0; i--) saida[--c[nota[i]]] = nota[i];

    for (int i = 0; i < N; i++) printf("%d ", saida[i]);
    printf("\n");
    return 0;
}
