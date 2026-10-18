// 0103 · Heapsort
// Exercício E616 · ★★☆

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// desce v[i] e devolve quantas trocas fez
int desce(int v[], int n, int i) {
    int trocas = 0;
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        trocas++;
        i = f;
    }
    return trocas;
}

void testa(const char *nome, int v[], int n) {
    int fase1 = 0, fase2 = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        fase1 += desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]); // esta troca não conta: só as do desce
        fase2 += desce(v, fim, 0);
    }
    printf("%-12s fase 1: %d trocas, fase 2: %d trocas ->", nome, fase1, fase2);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int crescente[] = {1, 2, 3, 4, 5, 6, 7};
    int decrescente[] = {7, 6, 5, 4, 3, 2, 1};
    int iguais[] = {5, 5, 5, 5, 5, 5, 5};

    testa("crescente:", crescente, 7);
    testa("decrescente:", decrescente, 7);
    testa("iguais:", iguais, 7);
    return 0;
}
