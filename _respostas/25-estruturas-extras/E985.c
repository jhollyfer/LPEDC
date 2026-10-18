// 0165 · Juntando tudo
// Exercício E985 · ★☆☆

#include <stdio.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20

void mede(const Estrutura *e, const int ordem[], const int buscas[], double *media, int *pior) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    *pior = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
        if (custo > *pior) {
            *pior = custo;
        }
    }
    e->libera(d);
    *media = (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        double media;
        int pior;
        mede(&CONCORRENTES[k], embaralhada, buscas, &media, &pior);
        printf("%-10s média %6.1f   pior %4d\n", CONCORRENTES[k].nome, media, pior);
    }
    return 0;
}
