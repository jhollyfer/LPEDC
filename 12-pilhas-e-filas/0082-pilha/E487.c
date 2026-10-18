// 0082 · Pilha
// Exercício E487 · ★☆☆
//
// O garçom empilha as comandas no espeto do balcão, e a cozinha sempre pega a
// de cima. O programa abaixo já mexe na pilha. Complete o final: depois que o
// laço esvazia a pilha, chame pilha_desempilha(p, &x) mais uma vez, guarde o
// retorno numa variável bool e mostre o que a função devolveu e quanto x
// ficou valendo.
//
//   Saída esperada:
//   7
//   9
//   2 1
//   4
//   vazia? 1
//   mais um desempilha: devolveu 0, x = 4
//
// Dicas:
// 1. bool ok = pilha_desempilha(p, &x); e mostre ok com %d (false vira 0).
// 2. Com a pilha vazia, a função não escreve em x: ele fica com o último
//    valor que saiu.
// 3. Resposta esperada: as seis linhas acima.
//
// Escreva sua resposta abaixo (complete o fim do main):

#include <stdbool.h>
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

    // sua parte: mais um pilha_desempilha e o printf do resultado

    pilha_libera(p);
    return 0;
}
