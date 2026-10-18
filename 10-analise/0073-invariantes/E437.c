// 0073 · Invariantes de laço e corretude
// Exercício E437 · ★★★
//
// Escreva int lg(int n), que devolve o piso de log₂ n (o maior i com
// 2 elevado a i <= n), para n >= 1, SEM math.h: divida n por 2 até chegar a
// 1, contando as divisões.
//
// Confira o invariante com assert no começo de cada volta e o término com
// outro assert depois do laço. Depois teste: mostre lg de 1, 10, 1000, 1024
// e 100000, e compare lg(n) com floor(log2(n)) de math.h para todo n de 1 a
// 100000, contando as divergências.
//
//   Saída esperada:
//   lg(1) = 0
//   lg(10) = 3
//   lg(1000) = 9
//   lg(1024) = 10
//   lg(100000) = 16
//   divergências de 1 a 100000: 0
//
// Dicas:
// 1. Use uma cópia m de n e um contador i: i = 0, m = n; enquanto m > 1,
//    m = m / 2 e i++.
// 2. Invariante: p * m <= n < p * (m + 1), com p = 2 elevado a i. Guarde p
//    numa variável long que dobra junto com o i++. Teste com n = 10: (i, m)
//    passa por (0, 10), (1, 5), (2, 2), (3, 1).
// 3. No término, m == 1: o assert fica p <= n && n < 2 * p.
// 4. Resposta esperada: a saída acima, sem nenhum assert disparando. O laço
//    termina porque m cai pelo menos pela metade a cada volta.
//
// Escreva sua resposta abaixo:

#include <assert.h>
#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
