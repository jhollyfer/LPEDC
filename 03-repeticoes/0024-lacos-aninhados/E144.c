// 0024 · Laços aninhados
// Exercício E144 · ★★★
//
// De quantas formas dá para pagar R$ 100 usando só notas de 50, 20 e 10?
// Resolva por força bruta: três laços aninhados testam todas as quantidades
// possíveis de cada nota e contam as combinações que somam 100. Mostre cada
// uma e o total:
//
//    1) 0 de 50 + 0 de 20 + 10 de 10
//    2) 0 de 50 + 1 de 20 +  8 de 10
//   ...
//   10) 2 de 50 + 0 de 20 +  0 de 10
//   Formas: 10
//
// Dicas:
// 1. Notas de 50: de 0 a 2. De 20: de 0 a 5. De 10: de 0 a 10.
// 2. No laço mais de dentro: if (50 * n50 + 20 * n20 + 10 * n10 == 100).
// 3. Resposta esperada: 10 formas. Desafio extra: o laço das notas de 10 é
//    desnecessário. Com n50 e n20 fixos, quantas notas de 10 faltam? (Só
//    vale se o que falta for >= 0.)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
