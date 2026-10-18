// 0165 · Juntando tudo
// Exercício E989 · ★★★

#include <stdio.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000

unsigned estado = 3; // o estado do sorteio

void mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    int acharam = 0;
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        acharam += e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    printf("%-10s acharam %d, custo médio %.1f\n", e->nome, acharam, (double)total / BUSCAS);
}

int main(void) {
    int ordem[N];
    for (int i = 0; i < N; i++) {
        ordem[i] = i + 1;
    }
    unsigned outro = 9;
    bc_embaralha(ordem, N, &outro);

    static int buscas[BUSCAS]; // sorteadas uma vez só: as mesmas para todos
    for (int i = 0; i < BUSCAS; i++) {
        buscas[i] = bc_sorteio(&estado) % 1500 + 1;
    }

    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        mede(&CONCORRENTES[k], ordem, buscas);
    }
    return 0;
}
