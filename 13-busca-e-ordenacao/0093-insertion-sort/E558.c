// 0093 · Insertion sort
// Exercício E558 · ★★★
//
// Ideia aparentemente esperta: a parte v[0..j-1] já está ordenada, então dá
// para achar o lugar de x com BUSCA BINÁRIA em vez de andar casa por casa.
// Implemente essa "insertion binária" e compare com a normal no vetor
// invertido 160, 150, ..., 10 (16 elementos), contando comparações e
// deslocamentos. Depois responda num comentário: o algoritmo deixou de ser
// O(n²)?
//
//   Saída esperada:
//   normal:  120 comparações, 120 deslocamentos
//   binária:  49 comparações, 120 deslocamentos
//   ordenado? sim
//
// Dicas:
// 1. Procure a PRIMEIRA posição de v[0..j-1] com valor maior que x (estilo
//    semiaberto do A180, com v[meio] <= x). Assim os iguais ficam na ordem de
//    chegada.
// 2. Achou a posição p? Empurre v[p..j-1] uma casa para a direita e ponha x
//    em v[p].
// 3. Na normal, conte uma comparação por teste v[i] <= x feito.
// 4. Resposta esperada: a saída acima. As comparações caem, mas os
//    deslocamentos não mudam: cada elemento ainda anda casa por casa, então
//    continua O(n²).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
