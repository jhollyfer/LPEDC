// 0082 · Pilha
// Exercício E490 · ★★☆
//
// No balcão do restaurante cabem 4 bandejas empilhadas. Escreva a própria pilha:
// typedef struct Balcao (vetor itens de CAPACIDADE ints e o índice topo, que vale
// -1 quando a pilha está vazia) e bool balcao_empilha(Balcao *b, int bandeja),
// que recusa (devolve false) a bandeja quando o balcão está cheio. No main,
// tente empilhar as bandejas 1 a 5 mostrando o resultado de cada uma e, no fim,
// a bandeja que está no topo.
//
//   Saída esperada:
//   Empilhou a bandeja 1
//   Empilhou a bandeja 2
//   Empilhou a bandeja 3
//   Empilhou a bandeja 4
//   Balcão cheio: a bandeja 5 ficou de fora
//   No topo: bandeja 4
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

#define CAPACIDADE 4

typedef struct {
    int itens[CAPACIDADE];
    int topo; // índice do item de cima; -1 quando vazia
} Balcao;

int main(void) {

    return 0;
}
