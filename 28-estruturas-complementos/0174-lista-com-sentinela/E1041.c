// 0174 · Lista com sentinela
// Exercício E1041 · ★★☆
//
// A agenda do dentista guarda os horários do dia (em HHMM) em ordem. Escreva
// insere_ordenado(L, h), que anda a partir de L->nil.prox enquanto não voltou
// à sentinela e a chave é menor que h, e então insere antes do nó onde
// parou, com sent_insere_apos(L, p->ant, h). Repare que vale para a lista
// vazia, para o começo e para o fim, sem nenhum caso especial. Insira 1400,
// 900, 1630, 800 e 1100 e mostre a lista depois de cada um.
//
//   Saída esperada:
//   [ 1400 ]
//   [ 900 1400 ]
//   [ 900 1400 1630 ]
//   [ 800 900 1400 1630 ]
//   [ 800 900 1100 1400 1630 ]
//
// Dicas:
// 1. Se o laço parar na sentinela, p->ant é o último: inserir depois dele é
//    inserir no fim. Se parar no primeiro, p->ant é a sentinela.
// 2. A condição do while tem duas partes: p != &L->nil e p->chave < h.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "sentinela.h"

int main(void) {

    return 0;
}
