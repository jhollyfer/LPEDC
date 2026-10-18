// 0093 · Insertion sort
// Exercício E558 · ★★★
//
// Ideia aparentemente esperta: a parte v[0..j-1] já está ordenada, então dá
// para achar o lugar de x com BUSCA BINÁRIA em vez de andar casa por casa.
// Implemente essa "insertion binária" e compare com a normal num vetor
// invertido, contando comparações e deslocamentos. Escreva uma função
// void testa(int n) que monta o vetor invertido de n elementos (10n, ...,
// 20, 10), roda as duas versões e mostra os números. Chame com n = 16 e
// n = 32 para ver o que acontece quando n dobra.
//
//   Saída esperada:
//   n = 16
//   normal:  120 comparações, 120 deslocamentos
//   binária:  49 comparações, 120 deslocamentos
//   ordenado? sim
//   n = 32
//   normal:  496 comparações, 496 deslocamentos
//   binária: 129 comparações, 496 deslocamentos
//   ordenado? sim
//
// Dicas:
// 1. Procure a PRIMEIRA posição de v[0..j-1] com valor maior que x (estilo
//    semiaberto do A180, com v[meio] <= x). Assim os iguais ficam na ordem de
//    chegada.
// 2. Achou a posição p? Empurre v[p..j-1] uma casa para a direita e ponha x
//    em v[p].
// 3. Na normal, conte uma comparação por teste v[i] <= x feito.
// 4. Use vetores de 32 posições dentro de testa e preencha só os n primeiros.
// 5. Resposta esperada: a saída acima. As comparações caem, mas os
//    deslocamentos não mudam e quase quadruplicam quando n dobra: cada
//    elemento ainda anda casa por casa, então continua O(n²).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
