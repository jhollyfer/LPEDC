// Lista · Módulo 07 · Memória dinâmica
// Exercício P0722 · ★★★ · Somar duas matrizes esparsas

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LADO 100

bool anexar(int **v, int *n, int *cap, int l, int c, int x) {
    if (x == 0) {
        return true; // zero não se guarda
    }
    if (*n == *cap) {
        int nova = (*cap == 0) ? 2 : *cap * 2;
        int *novo = realloc(*v, nova * 3 * sizeof *novo);
        if (novo == NULL) {
            return false;
        }
        *v = novo;
        *cap = nova;
    }
    int *t = *v + 3 * *n;
    t[0] = l;
    t[1] = c;
    t[2] = x;
    (*n)++;
    return true;
}

int *somar(const int *a, int na, const int *b, int nb, int *n) {
    int *r = NULL;
    int cap = 0;
    int i = 0, j = 0;
    bool ok = true;
    *n = 0;
    while (ok && (i < na || j < nb)) {
        int ka = i < na ? a[3 * i] * LADO + a[3 * i + 1] : LADO * LADO;
        int kb = j < nb ? b[3 * j] * LADO + b[3 * j + 1] : LADO * LADO;
        if (ka < kb) {
            ok = anexar(&r, n, &cap, a[3 * i], a[3 * i + 1], a[3 * i + 2]);
            i++;
        } else if (kb < ka) {
            ok = anexar(&r, n, &cap, b[3 * j], b[3 * j + 1], b[3 * j + 2]);
            j++;
        } else {
            ok = anexar(&r, n, &cap, a[3 * i], a[3 * i + 1], a[3 * i + 2] + b[3 * j + 2]);
            i++;
            j++;
        }
    }
    if (!ok) {
        free(r);
        return NULL;
    }
    return r;
}

int main(void) {
    int a[] = {0, 4, 2,   3, 7, 1,   3, 9, 5,   42, 0, 3};
    int b[] = {3, 7, 4,   10, 10, 1,   42, 0, 2,   99, 99, 6};
    int n;

    int *s = somar(a, 4, b, 4, &n);
    if (s == NULL) {
        return 1;
    }
    printf("Soma (%d triplas):", n);
    for (int k = 0; k < n; k++) {
        printf(" (%d,%d,%d)", s[3 * k], s[3 * k + 1], s[3 * k + 2]);
    }
    printf("\n");
    printf("Esparsa: %zu bytes; grade cheia: %zu bytes\n",
           3 * n * sizeof(int), LADO * LADO * sizeof(int));
    free(s);
    return 0;
}
