// 0055 · calloc e realloc
// Exercício E329 · ★★★

#include <stdio.h>
#include <stdlib.h>

#define TOTAL 1000

// modo 1: cresce de 1 em 1; modo 2: dobra. Devolve 0 se faltar memória.
int simular(int modo, int *realocacoes, long *copias) {
    int capacidade = 1;
    int quantidade = 0;
    int *v = malloc(capacidade * sizeof *v);
    if (v == NULL) {
        return 0;
    }
    *realocacoes = 0;
    *copias = 0;
    for (int x = 0; x < TOTAL; x++) {
        if (quantidade == capacidade) {
            int nova = (modo == 1) ? capacidade + 1 : capacidade * 2;
            *copias += quantidade;
            (*realocacoes)++;
            int *maior = realloc(v, nova * sizeof *v);
            if (maior == NULL) {
                free(v);
                return 0;
            }
            v = maior;
            capacidade = nova;
        }
        v[quantidade++] = x;
    }
    free(v);
    return 1;
}

int main(void) {
    int realocacoes;
    long copias;
    if (simular(1, &realocacoes, &copias)) {
        printf("+1:     %d realocações, %ld cópias\n", realocacoes, copias);
    }
    if (simular(2, &realocacoes, &copias)) {
        printf("dobrar: %d realocações, %ld cópias\n", realocacoes, copias);
    }
    return 0;
}
// Saída:
// +1:     999 realocações, 499500 cópias
// dobrar: 10 realocações, 1023 cópias
