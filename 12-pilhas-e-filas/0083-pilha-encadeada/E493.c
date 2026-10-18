// 0083 · Pilha encadeada
// Exercício E493 · ★☆☆
//
// Sem rodar, desenhe a lista encadeada da pilha depois de cada linha do main
// (no formato topo -> ... -> NULL) e preveja a saída. Depois conte: até o
// fim do programa, quantas vezes o malloc foi chamado? E o free? Lembre que
// pilha_cria também faz um malloc.
//
// Dicas:
// 1. Empilhar insere no início: o novo nó vira o primeiro da lista.
// 2. Cada empilha faz um malloc; cada desempilha faz um free; pilha_libera
//    faz um free por nó que sobrou e mais um da struct.
// 3. Resposta esperada: mostra "8", "9" e "2 itens, topo 5". A lista final
//    é topo -> 5 -> 3 -> NULL. São 5 mallocs (1 da pilha + 4 nós) e 5 frees
//    (2 nos desempilhas + 2 nós no pilha_libera + 1 da struct).
//
// Escreva sua resposta abaixo (como comentário):

#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }
    int x;

    pilha_empilha(p, 3);
    pilha_empilha(p, 8);
    pilha_desempilha(p, &x);
    printf("%d\n", x);
    pilha_empilha(p, 5);
    pilha_empilha(p, 9);
    pilha_desempilha(p, &x);
    printf("%d\n", x);
    pilha_topo(p, &x);
    printf("%d itens, topo %d\n", pilha_tamanho(p), x);

    pilha_libera(p);
    return 0;
}
