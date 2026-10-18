// 0121 · Radix sort
// Exercício E722 · ★☆☆

#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %05d", v[i]);
    }
    printf("\n");
}

void passada(int v[], int aux[], int n, int exp) {
    int c[10] = {0};
    for (int i = 0; i < n; i++) {
        c[(v[i] / exp) % 10]++;
    }
    for (int d = 1; d < 10; d++) {
        c[d] += c[d - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        int d = (v[i] / exp) % 10;
        aux[--c[d]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        v[i] = aux[i];
    }
}

int main(void) {
    int ceps[] = {69050, 13083, 69005, 1310, 40140, 13010, 88015};
    int n = 7;
    int aux[7];

    int maior = ceps[0];
    for (int i = 1; i < n; i++) {
        if (ceps[i] > maior) {
            maior = ceps[i];
        }
    }
    printf("início:     ");
    mostra(ceps, n);
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        passada(ceps, aux, n, exp);
        printf("exp = %5d:", exp);
        mostra(ceps, n);
    }
    return 0;
}
