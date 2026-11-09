// Lista · Módulo 14 · Árvores
// Exercício P1418 · ★★☆ · O heapsort passo a passo

#include <stdio.h>

int trocas;

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    trocas++;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void mostra(const char *rotulo, const int v[], int n, int fim) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf("%s%d", i == fim ? " | " : " ", v[i]);
    }
    printf("\n");
}

int main(void) {
    int notas[] = {6, 9, 2, 7, 10, 4, 8};
    int n = 7;

    trocas = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(notas, n, i);
    }
    mostra("heap:     ", notas, n, n);
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&notas[0], &notas[fim]);
        desce(notas, fim, 0);
        printf("passo %d: ", n - fim);
        mostra(" ", notas, n, fim);
    }
    printf("trocas: %d\n", trocas);
    return 0;
}
