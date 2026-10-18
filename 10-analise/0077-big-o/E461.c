// 0077 · Notação O: como o custo cresce
// Exercício E461 · ★★★
//
// Você precisa ordenar a lista de entregas e tem duas opções:
//
//   A: um algoritmo simples, que gasta 2n² passos;
//   B: um sofisticado, que gasta 50 n log₂ n passos.
//
// B é O(n log n) e A é O(n²), então B ganha "no fim". Mas a partir de que n?
// Escreva um programa que encontra o MENOR n (começando em 2) em que B gasta
// menos passos que A, e mostra os dois custos nesse n. Mostre também uma
// tabela para n = 10, 100, 1000 e 10000.
//
//   Saída esperada:
//   B passa a ganhar em n = 190 (A: 72200, B: 71914)
//        n           A          B
//       10         200       1661
//      100       20000      33219
//     1000     2000000     498289
//    10000   200000000    6643856
//
// Dicas:
// 1. log2() está em <math.h> (o rodar já liga com -lm). Faça as contas em
//    double.
// 2. Um laço n = 2, 3, 4, ... que para (break) no primeiro n em que
//    50 * n * log2(n) < 2.0 * n * n.
// 3. Mostre os doubles com %.0f para arredondar.
// 4. Resposta esperada: n = 190. Para listas com menos de 190 entregas, o
//    "pior" algoritmo é o mais rápido. Com 10000, B é 30 vezes mais rápido.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
