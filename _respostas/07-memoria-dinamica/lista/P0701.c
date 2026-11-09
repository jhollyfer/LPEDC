// Lista · Módulo 07 · Memória dinâmica
// Exercício P0701 · ★☆☆ · Uma cópia no heap

#include <stdio.h>
#include <stdlib.h>

double *copiar(const double *v, int n) {
    double *novo = malloc(n * sizeof *novo);
    if (novo == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        novo[i] = v[i];
    }
    return novo;
}

void mostrar(const char *nome, const double *v, int n) {
    double total = 0;
    printf("%-9s", nome);
    for (int i = 0; i < n; i++) {
        printf(" %5.2f", v[i]);
        total += v[i];
    }
    printf(" | total %.2f\n", total);
}

int main(void) {
    double km[6] = {12.4, 3.8, 25.1, 7.6, 18.0, 5.3};

    double *c = copiar(km, 6);
    if (c == NULL) {
        printf("Sem memória\n");
        return 1;
    }
    for (int i = 0; i < 6; i++) {
        c[i] *= 0.9; // mexe só na cópia
    }
    mostrar("Original:", km, 6);
    mostrar("Desconto:", c, 6);
    free(c);
    return 0;
}
