// 0038 · Vetores e funções
// Exercício E223 · ★☆☆

#include <stdio.h>

#define RODADAS 8

int soma(const int v[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += v[i];
    }
    return total;
}

double media(const int v[], int n) {
    return (double) soma(v, n) / n;
}

int main(void) {
    int gols[RODADAS] = {3, 1, 0, 2, 4, 1, 2, 3};

    printf("Gols no campeonato: %d\n", soma(gols, RODADAS));
    printf("Média por rodada: %.2f\n", media(gols, RODADAS));
    return 0;
}
