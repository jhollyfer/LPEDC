// 0185 · Cadeia de matrizes
// Exercício E1107 · ★★☆

#include <limits.h>
#include <stdio.h>

#define N 7

const int p[N + 1] = {8, 20, 4, 15, 6, 25, 10, 12};
long memo[N + 1][N + 1]; // -1 = ainda não calculado
long chamadas = 0, casas = 0;

long custo(int i, int j) {
    chamadas++;
    if (i == j) return 0;
    if (memo[i][j] != -1) return memo[i][j]; // já sei: devolve sem recalcular
    casas++;
    long menor = LONG_MAX;
    for (int k = i; k < j; k++) {
        long c = custo(i, k) + custo(k + 1, j) + (long)p[i - 1] * p[k] * p[j];
        if (c < menor) menor = c;
    }
    memo[i][j] = menor;
    return menor;
}

int main(void) {
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++) memo[i][j] = -1;
    printf("Custo mínimo: %ld\n", custo(1, N));
    printf("Chamadas com memória: %ld\n", chamadas);
    printf("Casas calculadas: %ld\n", casas);
    return 0;
}
