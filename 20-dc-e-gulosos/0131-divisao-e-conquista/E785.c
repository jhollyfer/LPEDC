// 0131 · Divisão e conquista
// Exercício E785 · ★★★
//
// Fibonacci rápido. Existe um fato curioso sobre a matriz 2 x 2
//
//   | 1 1 |
//   | 1 0 |
//
// elevada a n: o elemento da primeira linha, segunda coluna, é F(n), o
// n-ésimo número de Fibonacci (F(1) = F(2) = 1). Então dá para calcular
// F(n) com a potência rápida, trocando "multiplicar números" por
// "multiplicar matrizes". Escreva:
//
// - um typedef struct Matriz com quatro long long (a, b, c, d);
// - Matriz multiplica(Matriz x, Matriz y), que soma 1 num contador global
//   de produtos a cada chamada;
// - Matriz potencia(Matriz m, int n), recursiva, com a identidade
//   {1, 0, 0, 1} como caso base;
// - long long fib(int n).
//
// Mostre F(10), F(50) e F(90), zerando o contador antes de cada um:
//
//   Saída esperada:
//   F(10) = 55 (6 produtos de matriz)
//   F(50) = 12586269025 (9 produtos de matriz)
//   F(90) = 2880067194370816120 (11 produtos de matriz)
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
