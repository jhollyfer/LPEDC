// Lista · Módulo 07 · Memória dinâmica
// Exercício P0719 · ★★☆ · União e interseção do tamanho exato

#include <stdio.h>
#include <stdlib.h>

int *encolher(int *v, int n) {
    if (n == 0) {
        return v;
    }
    int *novo = realloc(v, n * sizeof *novo);
    return novo != NULL ? novo : v; // se falhar, o bloco grande ainda serve
}

int *uniao(const int *a, int na, const int *b, int nb, int *n) {
    int *r = malloc((na + nb) * sizeof *r);
    if (r == NULL) {
        return NULL;
    }
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            r[k++] = a[i++];
        } else if (b[j] < a[i]) {
            r[k++] = b[j++];
        } else {
            r[k++] = a[i++];
            j++;
        }
    }
    while (i < na) {
        r[k++] = a[i++];
    }
    while (j < nb) {
        r[k++] = b[j++];
    }
    *n = k;
    return encolher(r, k);
}

int *intersecao(const int *a, int na, const int *b, int nb, int *n) {
    int menor = na < nb ? na : nb;
    int *r = malloc((menor > 0 ? menor : 1) * sizeof *r);
    if (r == NULL) {
        return NULL;
    }
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            i++;
        } else if (b[j] < a[i]) {
            j++;
        } else {
            r[k++] = a[i++];
            j++;
        }
    }
    *n = k;
    return encolher(r, k);
}

void mostrar(const char *nome, const int *v, int n) {
    printf("%s (%d):", nome, n);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int a[6] = {101, 103, 202, 204, 301, 402};
    int b[5] = {103, 104, 204, 302, 402};
    int nu, ni;

    int *u = uniao(a, 6, b, 5, &nu);
    int *in = intersecao(a, 6, b, 5, &ni);
    if (u != NULL && in != NULL) {
        mostrar("Nos dois grupos ou em um", u, nu);
        mostrar("Nos dois grupos", in, ni);
    }
    free(u);
    free(in);
    return 0;
}
