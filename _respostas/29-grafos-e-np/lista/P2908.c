// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2908 · ★☆☆ · Custo de uma ordem de multiplicação

#include <stdio.h>

#define N 5

const int p[N + 1] = {6, 2, 9, 4, 7, 3};

long custo_esq(int i, int j) { // ((Ai Ai+1) Ai+2) ... Aj
    long total = 0;
    for (int k = i + 1; k <= j; k++) total += (long)p[i - 1] * p[k - 1] * p[k];
    return total;
}

long custo_dir(int i, int j) { // Ai (Ai+1 (... Aj))
    long total = 0;
    for (int k = j - 1; k >= i; k--) total += (long)p[k - 1] * p[k] * p[j];
    return total;
}

int main(void) {
    printf("Resultado: %d x %d\n", p[0], p[N]);
    printf("Da esquerda: %ld\n", custo_esq(1, N));
    printf("Da direita: %ld\n", custo_dir(1, N));
    return 0;
}
