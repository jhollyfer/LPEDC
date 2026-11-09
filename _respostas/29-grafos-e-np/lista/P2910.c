// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2910 · ★☆☆ · Mudança em caminhões

#include <stdio.h>
#include <stdlib.h>

#define N 8
#define CAP 12

int desc(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x < y) - (x > y);
}

int main(void) {
    int vol[N] = {5, 7, 3, 8, 4, 2, 6, 3};
    int livre[N], dentro[N][N], qtd[N], viagens = 0, soma = 0;
    qsort(vol, N, sizeof vol[0], desc);
    for (int i = 0; i < N; i++) {
        soma += vol[i];
        int v = 0;
        while (v < viagens && livre[v] < vol[i]) v++;
        if (v == viagens) livre[viagens] = CAP, qtd[viagens] = 0, viagens++;
        livre[v] -= vol[i];
        dentro[v][qtd[v]++] = vol[i];
    }
    for (int v = 0; v < viagens; v++) {
        printf("Viagem %d:", v + 1);
        for (int k = 0; k < qtd[v]; k++) printf(" %d", dentro[v][k]);
        printf(" (sobram %d)\n", livre[v]);
    }
    printf("Limite inferior: %d viagens\n", (soma + CAP - 1) / CAP);
    return 0;
}
