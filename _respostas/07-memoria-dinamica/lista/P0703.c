// Lista · Módulo 07 · Memória dinâmica
// Exercício P0703 · ★☆☆ · A lista de espera que cresce de 3 em 3

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int chegada[8] = {501, 502, 503, 504, 505, 506, 507, 508};
    int cap = 3;
    int n = 0;
    int *v = malloc(cap * sizeof *v);
    if (v == NULL) {
        return 1;
    }
    printf("Capacidade inicial: %d\n", cap);

    for (int i = 0; i < 8; i++) {
        if (n == cap) {
            int *novo = realloc(v, (cap + 3) * sizeof *v);
            if (novo == NULL) {
                free(v); // o bloco antigo continua valendo
                return 1;
            }
            v = novo;
            cap += 3;
            printf("Senha %d não cabia: capacidade agora %d\n", chegada[i], cap);
        }
        v[n++] = chegada[i];
    }

    printf("Fila (%d de %d):", n, cap);
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
    free(v);
    return 0;
}
