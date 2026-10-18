// 0091 · Bubble sort
// Exercício E545 · ★★★
//
// O bubble tem um ponto fraco: elemento pequeno no fim (uma "tartaruga") anda
// só UMA casa para a esquerda por passada. No vetor 2, 3, 4, 5, 6, 7, 8, 1, o
// 1 precisa de 7 passadas para chegar à frente.
//
// O SHAKER SORT (coqueteleira) alterna o sentido: uma passada de ida
// (esquerda para a direita, leva o maior para o fim) e uma de volta (direita
// para a esquerda, traz o menor para a frente). Implemente o bubble com
// bandeira e o shaker, conte passadas (ida e volta contam uma cada) e
// comparações, e compare no vetor acima.
//
//   Saída esperada:
//   bubble: 7 passadas, 28 comparações
//   shaker: 3 passadas, 18 comparações
//   resultado: 1 2 3 4 5 6 7 8
//
// Dicas:
// 1. Guarde a parte ainda bagunçada em v[ini..fim]. Depois da ida, fim--;
//    depois da volta, ini++.
// 2. Na volta, compare v[j - 1] com v[j], com j descendo de fim até ini + 1.
// 3. Pare quando uma passada (de ida ou de volta) não trocar nada.
// 4. Resposta esperada: a saída acima. A ida troca só o 8 com o 1, a volta
//    traz o 1 para a frente, e a terceira passada confirma que acabou.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

int main(void) {

    return 0;
}
