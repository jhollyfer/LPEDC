// Lista · Módulo 14 · Árvores
// Exercício P1410 · ★☆☆ · Montando o heap de uma vez

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
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
    int estoque[] = {4, 17, 9, 23, 8, 31, 12, 2, 19};
    int n = 9;

    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(estoque, n, i);
        printf("desce(%d):", i);
        for (int k = 0; k < n; k++) {
            printf(" %d", estoque[k]);
        }
        printf("\n");
    }
    return 0;
}
