// Lista · Módulo 07 · Memória dinâmica
// Exercício P0714 · ★★☆ · Inserir em ordem num vetor que cresce

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool inserir(int **v, int *n, int *cap, int valor) {
    if (*n == *cap) {
        int nova_cap = (*cap == 0) ? 2 : *cap * 2;
        int *novo = realloc(*v, nova_cap * sizeof *novo);
        if (novo == NULL) {
            return false;
        }
        *v = novo;
        *cap = nova_cap;
        printf("(capacidade %d)\n", *cap);
    }
    int *p = *v;
    int i = *n - 1;
    while (i >= 0 && p[i] > valor) {
        p[i + 1] = p[i]; // empurra os maiores
        i--;
    }
    p[i + 1] = valor;
    (*n)++;
    return true;
}

int main(void) {
    int novos[7] = {45, 12, 89, 30, 12, 70, 5};
    int *v = NULL;
    int n = 0, cap = 0;

    for (int k = 0; k < 7; k++) {
        if (!inserir(&v, &n, &cap, novos[k])) {
            free(v);
            return 1;
        }
    }
    printf("Preços (%d de %d):", n, cap);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
    free(v);
    return 0;
}
