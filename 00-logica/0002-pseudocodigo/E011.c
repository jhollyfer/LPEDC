// 0002 · Pseudocódigo e teste de mesa
// Exercício E011 · ★★★
//
// A loja dá 10% de desconto em compras ACIMA de R$ 200. Este pseudocódigo
// tem dois erros. Ache os dois com um teste de mesa (use compras de R$ 300 e
// de R$ 150) e corrija.
//
//   leia(compra)
//   se compra < 200 entao
//       desconto <- compra * 10
//   senao
//       desconto <- 0
//   fimse
//   escreva(compra - desconto)
//
// Dicas:
// 1. Com R$ 300 o cliente deveria pagar 270. Quanto o algoritmo cobra?
// 2. 10% não é "vezes 10".
// 3. Resposta esperada: a condição está invertida (deve ser compra > 200) e o
//    desconto deve ser compra * 0.10 (ou compra * 10 / 100). Corrigido: 300
//    paga 270 e 150 paga 150.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
