// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2825 · ★★★ · As três sondagens lado a lado
//
// Compare as três sondagens numa tabela de m = 17 com as mesmas chaves,
// nesta ordem: 20, 37, 54, 71, 88, 5, 22, 39 (as cinco primeiras começam no
// 3). Linear: (k mod 17 + i) mod 17; quadrática: (k mod 17 + i * i) mod 17;
// dupla: (k mod 17 + i * (1 + k mod 16)) mod 17. Para cada método, imprima a
// tabela final e o total de sondagens.
//
//   Saída esperada:
//   linear:      .  .  . 20 37 54 71 88  5 22 39  .  .  .  .  .  . | 30 sondagens
//   quadrática:  .  . 88 20 37  5 22 54  . 39  .  . 71  .  .  .  . | 21 sondagens
//   dupla:       .  . 22 20  .  5  .  .  . 37 54 71 88 39  .  .  . | 15 sondagens
//
// Dicas:
// 1. Uma função posicao(metodo, k, i) com um switch deixa um laço só para
//    os três.
// 2. O 22 começa no 5: na linear, ele cai no meio do bloco que as cinco
//    primeiras formaram.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
