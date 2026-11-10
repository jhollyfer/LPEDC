// 0082 · Pilha
// Exercício E490 · ★★☆

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
