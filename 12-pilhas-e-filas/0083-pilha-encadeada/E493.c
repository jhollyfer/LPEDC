// 0083 · Pilha encadeada
// Exercício E493 · ★☆☆
//
// Você não enxerga os nós da pilha (o tipo é opaco), mas dá para acompanhar
// o que acontece com as funções do pilha.h. Complete a função estado: ela
// mostra quantos itens a pilha tem e quem está no topo, ou "[vazia]". O main
// já chama estado depois de cada operação.
//
//   Saída esperada:
//   [1 item, topo 3]
//   [2 itens, topo 8]
//   saiu 8 -> [1 item, topo 3]
//   [2 itens, topo 5]
//   [3 itens, topo 9]
//   saiu 9 -> [2 itens, topo 5]
//   saiu 5 -> [1 item, topo 3]
//   saiu 3 -> [vazia]
//
// Dicas:
// 1. pilha_topo devolve false com a pilha vazia: use isso para decidir o que
//    mostrar.
// 2. "item" no singular quando o tamanho é 1: um ternário resolve.
// 3. estado só olha: não desempilhe nada dentro dela.
// 4. Resposta esperada: as oito linhas acima. Cada empilha fez um malloc e
//    cada saiu fez um free; o sanitizer não acusa vazamento.
//
// Escreva sua resposta abaixo (complete estado):

#include <stdio.h>
#include "pilha.h"

void estado(const Pilha *p) {
    (void)p; // apague esta linha quando usar p
    printf("\n");
}

int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    int x;

    pilha_empilha(p, 3);
    estado(p);
    pilha_empilha(p, 8);
    estado(p);
    pilha_desempilha(p, &x);
    printf("saiu %d -> ", x);
    estado(p);
    pilha_empilha(p, 5);
    estado(p);
    pilha_empilha(p, 9);
    estado(p);
    while (pilha_desempilha(p, &x)) {
        printf("saiu %d -> ", x);
        estado(p);
    }

    pilha_libera(p);
    return 0;
}
