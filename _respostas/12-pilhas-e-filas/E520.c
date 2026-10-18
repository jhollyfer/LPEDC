// 0087 · Pilha
// Exercício E520 · ★★☆
//
// Resposta: o teste de cheia comparava topo com CAPACIDADE. Com a convenção
// topo = -1 para vazia, o topo é o índice do último item, então a pilha
// enche quando topo == CAPACIDADE - 1. Com o bug, a quinta bandeja ia para
// itens[4], fora do vetor, em cima do campo topo (que virava 5).

#include <stdbool.h>
#include <stdio.h>

#define CAPACIDADE 4

typedef struct {
    int itens[CAPACIDADE];
    int topo; // índice do item de cima; -1 quando vazia
} Balcao;

bool balcao_empilha(Balcao *b, int bandeja) {
    if (b->topo == CAPACIDADE - 1) {
        return false;
    }
    b->topo++;
    b->itens[b->topo] = bandeja;
    return true;
}

int main(void) {
    Balcao balcao = {.topo = -1};

    for (int bandeja = 1; bandeja <= 5; bandeja++) {
        if (balcao_empilha(&balcao, bandeja)) {
            printf("Empilhou a bandeja %d\n", bandeja);
        } else {
            printf("Balcão cheio: a bandeja %d ficou de fora\n", bandeja);
        }
    }
    printf("No topo: bandeja %d\n", balcao.itens[balcao.topo]);
    return 0;
}
