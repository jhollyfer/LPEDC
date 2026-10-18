// A329 · Quando a lista MTF ganha

#include <stdio.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000

// custo médio de um concorrente: chaves embaralhadas, as buscas dadas
double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    // quatro cenários de concentração: quantas chaves são "quentes" e qual a
    // porcentagem das buscas que vai para elas
    int quentes[] = {20, 10, 5, 2};
    int porcento[] = {80, 95, 99, 100};

    unsigned estado = 11;
    int ordem[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        ordem[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(ordem, N, &estado);
    bc_embaralha(sorteio, N, &estado);

    printf("%-14s", "cenário");
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        printf("%11s", CONCORRENTES[k].nome);
    }
    printf("\n");

    static int buscas[BUSCAS];
    for (int c = 0; c < 4; c++) {
        for (int i = 0; i < BUSCAS; i++) { // as mesmas buscas para os quatro
            if (bc_sorteio(&estado) % 100 < porcento[c]) {
                buscas[i] = sorteio[bc_sorteio(&estado) % quentes[c]];
            } else {
                buscas[i] = bc_sorteio(&estado) % N + 1;
            }
        }
        printf("%3d%% em %2d   ", porcento[c], quentes[c]);
        for (int k = 0; k < NUM_CONCORRENTES; k++) {
            printf("%11.1f", mede(&CONCORRENTES[k], ordem, buscas));
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// cenário              BST        AVL  skip list  lista MTF
//  80% em 20          10.5        8.6       19.2      112.1
//  95% em 10          10.6        7.8       19.1       31.2
//  99% em  5          10.0        6.8       18.6        8.8
// 100% em  2          11.5        8.5       18.5        1.6
