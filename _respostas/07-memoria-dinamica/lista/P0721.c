// Lista · Módulo 07 · Memória dinâmica
// Exercício P0721 · ★★★ · Um vetor que cresce para qualquer tipo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool empurrar(void **v, size_t *n, size_t *cap, size_t tam, const void *item) {
    if (*n == *cap) {
        size_t nova_cap = (*cap == 0) ? 1 : *cap * 2;
        void *novo = realloc(*v, nova_cap * tam);
        if (novo == NULL) {
            return false;
        }
        *v = novo;
        *cap = nova_cap;
    }
    unsigned char *fim = (unsigned char *) *v + *n * tam;
    memcpy(fim, item, tam); // copia os bytes, seja qual for o tipo
    (*n)++;
    return true;
}

int main(void) {
    int gols[7] = {2, 0, 1, 3, 1, 1, 4};
    double publico[3] = {18450.5, 22010.0, 9875.25};
    void *vg = NULL, *vp = NULL;
    size_t ng = 0, capg = 0, np = 0, capp = 0;

    for (int i = 0; i < 7; i++) {
        if (!empurrar(&vg, &ng, &capg, sizeof gols[0], &gols[i])) {
            free(vg);
            return 1;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (!empurrar(&vp, &np, &capp, sizeof publico[0], &publico[i])) {
            free(vg);
            free(vp);
            return 1;
        }
    }

    const int *g = vg;
    const double *p = vp;
    printf("Gols (n = %zu, cap = %zu):", ng, capg);
    for (size_t i = 0; i < ng; i++) {
        printf(" %d", g[i]);
    }
    printf("\nPúblico (n = %zu, cap = %zu):", np, capp);
    for (size_t i = 0; i < np; i++) {
        printf(" %.2f", p[i]);
    }
    printf("\n");
    free(vg);
    free(vp);
    return 0;
}
