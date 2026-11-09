// Lista · Módulo 21 · Programação dinâmica
// Exercício P2124 · ★★★ · A mochila quando a capacidade é enorme

#include <stdio.h>

#define N 6
#define CAP 100000L
#define VMAX 59
#define INF 1000000000L

int main(void) {
    const long peso[N] = {41000, 23000, 37000, 18000, 29000, 52000};
    const int valor[N] = {12, 7, 11, 5, 9, 15};
    long menor_peso[VMAX + 1];
    int pegou[N][VMAX + 1] = {{0}};
    menor_peso[0] = 0;
    for (int v = 1; v <= VMAX; v++) {
        menor_peso[v] = INF;
    }
    for (int i = 0; i < N; i++) {
        for (int v = VMAX; v >= valor[i]; v--) {
            if (menor_peso[v - valor[i]] + peso[i] < menor_peso[v]) {
                menor_peso[v] = menor_peso[v - valor[i]] + peso[i];
                pegou[i][v] = 1;
            }
        }
    }
    int melhor = 0;
    for (int v = 0; v <= VMAX; v++) {
        if (menor_peso[v] <= CAP) {
            melhor = v;
        }
    }
    printf("Maior valor: %d mil reais (%ld kg)\n", melhor, menor_peso[melhor]);
    printf("Lotes:");
    int lotes[N], nl = 0;
    for (int i = N - 1, v = melhor; i >= 0; i--) {
        if (pegou[i][v]) {
            lotes[nl++] = i + 1;
            v -= valor[i];
        }
    }
    for (int k = nl - 1; k >= 0; k--) {
        printf(" %d", lotes[k]);
    }
    printf("\n");
    printf("Posições da tabela: %d (a mochila comum teria %ld)\n", VMAX + 1, CAP + 1);
    return 0;
}
