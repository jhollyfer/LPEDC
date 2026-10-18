// 0108 · Heapsort
// Exercício E644 · ★☆☆

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce_min(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] < v[f]) {
            f++; // o MENOR dos filhos
        }
        if (v[i] <= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort_decrescente(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce_min(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]); // o MENOR vai para o fim
        desce_min(v, fim, 0);
    }
}

int main(void) {
    int pontos[] = {45, 62, 38, 70, 51, 29, 66};
    heapsort_decrescente(pontos, 7);
    printf("Tabela:");
    for (int i = 0; i < 7; i++) {
        printf(" %d", pontos[i]);
    }
    printf("\n");
    return 0;
}
