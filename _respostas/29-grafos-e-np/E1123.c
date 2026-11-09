// 0188 · Aproximação
// Exercício E1123 · ★☆☆

#include <stdio.h>

#define N 10
#define CAPACIDADE 10

int next_fit(const int carga[], int n) {
    int viagens = 0, livre = 0;
    for (int i = 0; i < n; i++) {
        if (viagens == 0 || livre < carga[i]) viagens++, livre = CAPACIDADE; // fecha a atual e abre outra
        livre -= carga[i];
    }
    return viagens;
}

int first_fit(const int carga[], int n) {
    int livre[N], viagens = 0;
    for (int i = 0; i < n; i++) {
        int v = 0;
        while (v < viagens && livre[v] < carga[i]) v++;
        if (v == viagens) livre[viagens++] = CAPACIDADE;
        livre[v] -= carga[i];
    }
    return viagens;
}

int main(void) {
    int carga[N] = {6, 5, 6, 5, 1, 7, 2, 2, 5, 4};
    int total = 0;
    for (int i = 0; i < N; i++) total += carga[i];
    printf("Limite inferior: %d viagens\n", (total + CAPACIDADE - 1) / CAPACIDADE);
    printf("Next fit: %d viagens\n", next_fit(carga, N));
    printf("First fit: %d viagens\n", first_fit(carga, N));
    return 0;
}
