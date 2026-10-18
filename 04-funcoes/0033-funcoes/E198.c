// 0033 · Funções
// Exercício E198 · ★★★
//
// Um número é perfeito quando é igual à soma dos seus divisores menores que
// ele: 6 = 1 + 2 + 3. Escreva duas funções que trabalham juntas:
//
//   int soma_divisores(int n)   soma os divisores de n menores que n
//   bool eh_perfeito(int n)     usa soma_divisores para responder
//
// Use-as para mostrar todos os números perfeitos de 2 a 10000 e, para cada
// um, a soma que prova isso.
//
//   Saída esperada:
//   6 = soma dos divisores 6
//   28 = soma dos divisores 28
//   496 = soma dos divisores 496
//   8128 = soma dos divisores 8128
//
// Dicas:
// 1. soma_divisores testa d de 1 até n / 2: se n % d == 0, soma d.
// 2. eh_perfeito cabe numa linha: return soma_divisores(n) == n;
// 3. Resposta esperada: 6, 28, 496 e 8128. São tão raros que o próximo é
//    33550336. Desafio extra: testar d só até a raiz de n (d * d <= n),
//    somando d e n / d de uma vez. Por que isso é muito mais rápido?
//
// Escreva sua resposta abaixo:

#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
