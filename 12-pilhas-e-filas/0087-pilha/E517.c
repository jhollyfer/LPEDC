// 0087 · Pilha
// Exercício E517 · ★☆☆
//
// O garçom empilha as comandas no espeto do balcão, e a cozinha sempre pega a
// de cima. Sem rodar, preveja o que o programa abaixo mostra, linha por linha.
// Depois responda: se o laço final terminasse e você chamasse
// pilha_desempilha(p, &x) mais uma vez, o que a função devolveria? E quanto
// ficaria valendo x?
//
// Dicas:
// 1. Desenhe a pilha de lado, com o topo à direita, e atualize a cada linha.
// 2. pilha_topo só olha: a pilha não muda.
// 3. Resposta esperada: "7", "9", "2 1", "4 " e "vazia? 1". Mais um
//    desempilha devolve false e não mexe em x, que continua 4.
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

    pilha_empilha(p, 4);
    pilha_empilha(p, 7);
    pilha_desempilha(p, &x);
    printf("%d\n", x);

    pilha_empilha(p, 2);
    pilha_empilha(p, 9);
    pilha_topo(p, &x);
    printf("%d\n", x);

    pilha_desempilha(p, &x);
    pilha_desempilha(p, &x);
    printf("%d %d\n", x, pilha_tamanho(p));

    while (pilha_desempilha(p, &x)) {
        printf("%d ", x);
    }
    printf("\nvazia? %d\n", pilha_vazia(p));

    pilha_libera(p);
    return 0;
}
