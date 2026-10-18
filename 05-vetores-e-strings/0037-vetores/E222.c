// 0037 · Vetores
// Exercício E222 · ★★★
//
// O Crivo de Eratóstenes acha todos os primos até N sem fazer nenhuma
// divisão. Com N = 50:
//
//   1. Crie um vetor de bool com 51 posições (índices 0 a 50), todas true.
//   2. Marque 0 e 1 como false (não são primos).
//   3. Para cada p de 2 em diante: se p ainda está true, ele é primo; então
//      marque como false todos os múltiplos de p a partir de p * p
//      (p*p, p*p + p, p*p + 2p, ... até 50).
//   4. Pode parar quando p * p passar de 50.
//
// No fim, mostre os primos e quantos são.
//
//   Saída esperada:
//   2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
//   15 primos até 50
//
// Dicas:
// 1. Use o stdbool.h e bool primo[N + 1]; preencha com um laço (a
//    inicialização {true} só põe true na primeira posição!).
// 2. O laço de dentro anda de p em p: for (int m = p * p; m <= N; m += p).
// 3. Por que começar em p * p? Os múltiplos menores (2p, 3p...) já foram
//    riscados pelos primos menores que p.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdbool.h>

#define N 50

int main(void) {

    return 0;
}
