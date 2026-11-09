// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1707 · ★☆☆ · Insertion sort recursivo e a recorrência T(n-1) + n

#include <stdio.h>

#define N 10

long comparacoes;

void ordena(int v[], int n) {
    if (n <= 1) return;
    ordena(v, n - 1); // T(n - 1)
    int x = v[n - 1], j = n - 2;
    while (j >= 0) { // até n - 1 comparações
        comparacoes++;
        if (v[j] <= x) break;
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = x;
}

void testa(const char *nome, int v[]) {
    comparacoes = 0;
    ordena(v, N);
    printf("%-12s %2ld comparações:", nome, comparacoes);
    for (int i = 0; i < N; i++) printf(" %d", v[i]);
    printf("\n");
}

int main(void) {
    int crescente[N] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int decrescente[N] = {110, 109, 108, 107, 106, 105, 104, 103, 102, 101};
    int misturado[N] = {105, 101, 108, 103, 110, 102, 107, 104, 109, 106};

    testa("crescente", crescente);
    testa("decrescente", decrescente);
    testa("misturado", misturado);
    printf("Melhor caso n - 1 = %d | pior caso n(n - 1)/2 = %d\n", N - 1, N * (N - 1) / 2);
    return 0;
}
