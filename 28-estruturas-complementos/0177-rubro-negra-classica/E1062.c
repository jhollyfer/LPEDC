// 0177 · Rubro-negra clássica
// Exercício E1062 · ★★★
//
// A central de entregas guarda os pacotes 1000 + (i * 37 % 100), para i de 0
// a 19, numa rubro-negra (vermelhopreto.h). Escreva relatorio(T, a, b), que
// lista em ordem os pacotes com número entre a e b (inclusive) e devolve
// quantos são, em O(log n + k): ache o primeiro nó com chave >= a (o
// "teto" de a, descendo da raiz) e ande com o sucessor (com o ponteiro pai
// e a sentinela) até passar de b. Teste [1020, 1050], [1000, 1010],
// [1093, 1200] e [1500, 1600].
//
//   Saída esperada:
//   [1020, 1050]: 1022 1029 1033 1037 1044 1048 (6 pacotes)
//   [1000, 1010]: 1000 1003 1007 (3 pacotes)
//   [1093, 1200]: 1096 (1 pacotes)
//   [1500, 1600]: (0 pacotes)
//
// Dicas:
// 1. O sucessor é o do 0175, trocando NULL por &T->nil (inclusive o pai da
//    raiz, que é a sentinela).
// 2. No teto, sempre que x->chave >= a, x vira candidato e você desce à
//    esquerda; senão, desce à direita.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "vermelhopreto.h"

int main(void) {

    return 0;
}
