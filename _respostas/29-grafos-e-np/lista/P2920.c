// Lista · Módulo 29 · Grafos: ciclos e cortes; problemas difíceis
// Exercício P2920 · ★★☆ · Quatro heurísticas contra o ótimo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9
#define CAP 10

int desc(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x < y) - (x > y);
}

int next_fit(const int x[], int n) {
    int motos = 0, livre = 0;
    for (int i = 0; i < n; i++) {
        if (motos == 0 || livre < x[i]) motos++, livre = CAP;
        livre -= x[i];
    }
    return motos;
}

int first_fit(const int x[], int n) {
    int livre[N], motos = 0;
    for (int i = 0; i < n; i++) {
        int v = 0;
        while (v < motos && livre[v] < x[i]) v++;
        if (v == motos) livre[motos++] = CAP;
        livre[v] -= x[i];
    }
    return motos;
}

int best_fit(const int x[], int n) {
    int livre[N], motos = 0;
    for (int i = 0; i < n; i++) {
        int b = -1;
        for (int v = 0; v < motos; v++)
            if (livre[v] >= x[i] && (b == -1 || livre[v] < livre[b])) b = v;
        if (b == -1) b = motos, livre[motos++] = CAP;
        livre[b] -= x[i];
    }
    return motos;
}

int ord[N], livre_bt[N], melhor;

void bt(int i, int motos) {
    if (motos >= melhor) return;
    if (i == N) {
        melhor = motos;
        return;
    }
    for (int v = 0; v < motos; v++)
        if (livre_bt[v] >= ord[i]) {
            livre_bt[v] -= ord[i];
            bt(i + 1, motos);
            livre_bt[v] += ord[i];
        }
    livre_bt[motos] = CAP - ord[i];
    bt(i + 1, motos + 1);
}

int main(void) {
    int x[N] = {6, 3, 7, 2, 5, 4, 5, 3, 5};
    memcpy(ord, x, sizeof x);
    qsort(ord, N, sizeof ord[0], desc);
    printf("Next fit: %d\n", next_fit(x, N));
    printf("First fit: %d\n", first_fit(x, N));
    printf("Best fit: %d\n", best_fit(x, N));
    printf("First fit decrescente: %d\n", first_fit(ord, N));
    melhor = N + 1;
    bt(0, 0);
    printf("Ótimo: %d\n", melhor);
    return 0;
}
