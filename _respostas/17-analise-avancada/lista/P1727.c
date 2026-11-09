// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1727 · ★★★ · Montar o heap: n inserções ou BUILD-HEAP?

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long trocas;

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
    trocas++;
}

void sobe(int v[], int i) {
    while (i > 0 && v[(i - 1) / 2] > v[i]) {
        troca(&v[(i - 1) / 2], &v[i]);
        i = (i - 1) / 2;
    }
}

void desce(int v[], int n, int i) {
    for (;;) {
        int m = i, e = 2 * i + 1, d = 2 * i + 2;
        if (e < n && v[e] < v[m]) m = e;
        if (d < n && v[d] < v[m]) m = d;
        if (m == i) return;
        troca(&v[i], &v[m]);
        i = m;
    }
}

int valido(const int v[], int n) {
    for (int i = 1; i < n; i++)
        if (v[(i - 1) / 2] > v[i]) return 0;
    return 1;
}

int main(void) {
    printf("      n   inserindo   build-heap      n lg n  válidos\n");
    for (int k = 4; k <= 20; k += 4) {
        int n = (1 << k) - 1;
        int *a = malloc(n * sizeof *a), *b = malloc(n * sizeof *b);
        if (a == NULL || b == NULL) return 1;

        trocas = 0;
        for (int i = 0; i < n; i++) {
            a[i] = n - i; // decrescente: cada novo é o mais grave até agora
            sobe(a, i);
        }
        long t_ins = trocas;

        trocas = 0;
        for (int i = 0; i < n; i++) b[i] = n - i;
        for (int i = n / 2 - 1; i >= 0; i--) desce(b, n, i);
        long t_build = trocas;

        printf("%7d %11ld %12ld %11.0f %8s\n", n, t_ins, t_build, n * log2((double)n),
               valido(a, n) && valido(b, n) ? "sim" : "não");
        free(a);
        free(b);
    }
    return 0;
}
