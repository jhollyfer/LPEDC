// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1003 · ★☆☆ · O laço contra a fórmula de Gauss
//
// Um app de poupança junta 1 real no dia 1, 2 no dia 2, ..., n no dia n.
// Quanto há no dia n? Escreva duas funções que devolvem a soma 1 + 2 + ...
// + n e contam, em *passos, quantas operações aritméticas fizeram:
//
//   long long soma_laco(int n, int *passos)     // um for: 1 passo por soma
//   long long soma_formula(int n, int *passos)  // n (n + 1) / 2: conte 3
//
// Mostre o resultado para n = 100 e n = 100000.
//
//   Saída esperada:
//   n = 100: laço 5050 (100 passos), fórmula 5050 (3 passos)
//   n = 100000: laço 5000050000 (100000 passos), fórmula 5000050000 (3 passos)
//
// Dicas:
// 1. Com n = 100000 a soma passa de 2 bilhões: use long long e "%lld".
// 2. Na fórmula, faça a conta em long long: (long long) n * (n + 1) / 2.
//    A soma, a multiplicação e a divisão são os 3 passos.
// 3. O laço é O(n); a fórmula é O(1): não importa o tamanho de n.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
