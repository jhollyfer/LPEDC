// 0079 · Lista dupla
// Exercício E472 · ★★☆
//
// Engatar um vagão no meio do trem mexe em QUATRO setas. Escreva
//
//   bool insere_depois(Lista *l, No *p, int valor)
//
// que cria um nó com o valor logo depois do nó p (que está na lista).
// Cuidado com p == l->fim. No trem 98, 105, 87, 110, engate um vagão de 99 t
// depois do de 105 e um de 70 t depois do último. Mostre nos dois sentidos:
// se uma seta ficou errada, um dos sentidos denuncia.
//
//   Saída esperada:
//   98 <-> 105 <-> 99 <-> 87 <-> 110 <-> 70
//   70 <-> 110 <-> 87 <-> 99 <-> 105 <-> 98
//   6 vagões
//
// Dicas:
// 1. O novo aponta para os vizinhos: novo->ant = p; novo->prox = p->prox.
// 2. Os vizinhos apontam para o novo: se p->prox existe, p->prox->ant =
//    novo; senão o novo é o fim (l->fim = novo). Por último, p->prox = novo.
// 3. Por que p->prox = novo por último? Se vier antes, você perde o
//    caminho para o antigo seguinte.
// 4. Não esqueça do l->tamanho++. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

int main(void) {

    return 0;
}
