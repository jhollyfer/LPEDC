// 0078 · Invariantes de laço e corretude
// Exercício E467 · ★★★
//
// Escreva int lg(int n), que devolve o piso de log₂ n (o maior i com
// 2 elevado a i <= n), para n >= 1, SEM math.h: divida n por 2 até chegar a
// 1, contando as divisões.
//
// Escreva o invariante como comentário e prove o término. Depois teste: mostre
// lg de 1, 10, 1000, 1024 e 100000, e compare lg(n) com floor(log2(n)) de
// math.h para todo n de 1 a 100000, contando as divergências.
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
// 2. Invariante: (2 elevado a i) * m <= n < (2 elevado a i) * (m + 1). Teste
//    com n = 10: (i, m) passa por (0, 10), (1, 5), (2, 2), (3, 1).
// 3. No término, m == 1: o invariante vira 2^i <= n < 2^(i+1).
// 4. Resposta esperada: a saída acima. Parada: m cai pelo menos pela metade
//    a cada volta e o laço para quando chega a 1.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>

int main(void) {

    return 0;
}
