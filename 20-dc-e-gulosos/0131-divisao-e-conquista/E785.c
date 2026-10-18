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
// Dicas:
// 1. Produto de matrizes 2 x 2: r.a = x.a*y.a + x.b*y.c,
//    r.b = x.a*y.b + x.b*y.d, r.c = x.c*y.a + x.d*y.c,
//    r.d = x.c*y.b + x.d*y.d.
// 2. Em potencia: metade = potencia(m, n / 2); r = multiplica(metade,
//    metade); se n for ímpar, r = multiplica(r, m).
// 3. Resposta esperada: a saída acima. A recursão do assunto 0033 faria
//    bilhões de chamadas para F(90); o laço simples, 90 somas; esta versão,
//    11 produtos de matriz. F(92) é o último que cabe num long long.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
