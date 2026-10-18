// 0103 · Heapsort
// Exercício E613 · ★☆☆

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// mostra v[0..n-1]; a barra aparece antes da posição fim (se fim < n)
void mostra(const int v[], int n, int fim) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : (i == fim ? " | %d" : " %d"), v[i]);
    }
    printf("]\n");
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

int main(void) {
    int v[] = {3, 9, 2, 7, 5, 8};
    int n = 6;
    // fase 1: do último pai até a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
        printf("pai %d desceu: ", i);
        mostra(v, n, n);
    }
    // fase 2: só os dois primeiros passos
    for (int fim = n - 1; fim >= n - 2; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
        printf("fase 2:       ");
        mostra(v, n, fim);
    }
    return 0;
}
