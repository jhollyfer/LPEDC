// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1011 · ★★☆ · Achar a fórmula exata de T(n)
//
// Este trecho pinta faixas de um mural: a cada duas colunas, pinta da
// coluna i até o fim.
//
//   for (int i = 0; i < n; i += 2)
//       for (int j = i; j < n; j++)
//           passos++;
//
// Escreva long conta(int n), que roda o trecho e devolve passos, e
// long formula(int n), que calcula o mesmo número SEM laço nenhum, com uma
// expressão em n. Mostre conta(n) para n = 1 a 6 e depois confira se
// formula(n) == conta(n) para todo n de 1 a 1000.
//
//   Saída esperada:
//   T(1) = 1
//   T(2) = 2
//   T(3) = 4
//   T(4) = 6
//   T(5) = 9
//   T(6) = 12
//   Fórmula confere de 1 a 1000: sim
//
// Dicas:
// 1. Separe n par (n = 2m) e n ímpar (n = 2m + 1). Com n = 2m, o laço de
//    dentro roda 2m, 2m - 2, ..., 2 vezes: 2 (1 + 2 + ... + m) = m (m + 1).
// 2. Com n = 2m + 1: 2m + 1, 2m - 1, ..., 1, a soma dos ímpares: (m + 1)².
// 3. As duas cabem numa expressão só com divisão inteira:
//    ((n + 1) / 2) * ((n + 2) / 2). Confira com n = 5: 3 * 3 = 9.
// 4. Resposta esperada: a saída acima. T(n) ≈ n² / 4, então Θ(n²).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
