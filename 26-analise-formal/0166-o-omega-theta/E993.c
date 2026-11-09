// 0166 · O, Ω e Θ de verdade
// Exercício E993 · ★★☆
//
// Melhor, pior e caso médio de verdade, sem fórmula: para cada n de 3 a 7,
// gere TODAS as ordens dos números 1..n (são n! ordens), ordene uma cópia
// de cada uma com o insertion sort e conte as comparações entre elementos.
// Mostre quantas ordens foram testadas, o menor, o maior e a média de
// comparações:
//
//   Saída esperada:
//   n = 3:    6 ordens | melhor 2 | pior  3 | média 2.67
//   n = 4:   24 ordens | melhor 3 | pior  6 | média 4.92
//   n = 5:  120 ordens | melhor 4 | pior 10 | média 7.72
//   n = 6:  720 ordens | melhor 5 | pior 15 | média 11.05
//   n = 7: 5040 ordens | melhor 6 | pior 21 | média 14.91
//
// Dicas:
// 1. Gere as ordens com backtracking (assunto 0126): um vetor perm, um
//    vetor bool usado e uma função permuta(perm, usado, pos, n).
// 2. No insertion sort, conte uma comparação a cada vez que v[j] é
//    comparado com x, e saia do while com break quando v[j] <= x.
// 3. O melhor caso (já ordenado) é n - 1: Θ(n). O pior (ao contrário) é
//    n(n-1)/2: Θ(n²). A média fica perto de n²/4: também Θ(n²).
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
