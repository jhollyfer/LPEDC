// 0082 · Pilha
// Exercício E490 · ★★☆
//
// No balcão do restaurante cabem 4 bandejas empilhadas. Este programa traz a
// própria pilha (com a convenção topo = -1 para pilha vazia) e tenta
// empilhar 5 bandejas. A quinta deveria ser recusada, mas o programa tem um
// bug. Rode com o rodar: o sanitizer acusa o erro (procure "out of bounds").
// Ache a linha, conserte e rode de novo até a saída bater com a esperada.
//
//   Saída esperada depois do conserto:
//   Empilhou a bandeja 1
//   Empilhou a bandeja 2
//   Empilhou a bandeja 3
//   Empilhou a bandeja 4
//   Balcão cheio: a bandeja 5 ficou de fora
//   No topo: bandeja 4
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>

#define CAPACIDADE 4

typedef struct {
    int itens[CAPACIDADE];
    int topo; // índice do item de cima; -1 quando vazia
} Balcao;

bool balcao_empilha(Balcao *b, int bandeja) {
    if (b->topo == CAPACIDADE) {
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
