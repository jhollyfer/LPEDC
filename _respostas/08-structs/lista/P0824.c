// Lista · Módulo 08 · Tipos compostos
// Exercício P0824 · ★★★ · Matriz esparsa vezes vetor

#include <stdio.h>

typedef struct {
    int l, c;
    double v;
} Termo;

void mult(const Termo *t, int k, const double *x, double *y, int linhas) {
    for (int i = 0; i < linhas; i++) {
        y[i] = 0;
    }
    for (int p = 0; p < k; p++) {
        y[t[p].l] += t[p].v * x[t[p].c]; // só os termos que existem
    }
}

void mostrar(const char *nome, const double *y, int n) {
    printf("%s =", nome);
    for (int i = 0; i < n; i++) {
        printf(" %.1f", y[i]);
    }
    printf("\n");
}

int main(void) {
    Termo a[7] = {{0, 0, 2.0}, {0, 3, 1.5}, {1, 1, 4.0}, {2, 5, 0.5},
                  {3, 0, 1.0}, {3, 2, 3.0}, {5, 4, 2.5}};
    double x[6] = {3, 1, 2, 4, 2, 6};
    double y[6];
    Termo tt[7];

    mult(a, 7, x, y, 6);
    mostrar("A x", y, 6);
    printf("Multiplicações: %d (a matriz cheia faria %d)\n", 7, 6 * 6);

    for (int p = 0; p < 7; p++) {
        tt[p] = a[p];       // copia a struct inteira...
        tt[p].l = a[p].c;   // ...e troca linha com coluna
        tt[p].c = a[p].l;
    }
    mult(tt, 7, x, y, 6);
    mostrar("At x", y, 6);
    return 0;
}
