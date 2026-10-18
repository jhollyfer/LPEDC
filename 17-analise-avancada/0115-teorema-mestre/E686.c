// 0115 · Teorema mestre
// Exercício E686 · ★☆☆
//
// A função trabalho(n) abaixo segue T(n) = 3 T(n/2) + n. Pelo teorema
// (a = 3 > b^k = 2, caso 1), T(n) = Θ(n^(log₂ 3)) = Θ(n^1,585): quando n
// dobra, o total deve ser multiplicado por 2^1,585 = 3. Confira no
// computador: complete o main para mostrar T(n) e a razão T(n) / T(n/2)
// para n = 64, 128, ..., 4096:
//
//   Saída esperada:
//       n     T(n)  T(n)/T(n/2)
//      64     2059    3.096
//     128     6305    3.062
//     256    19171    3.041
//     512    58025    3.027
//    1024   175099    3.018
//    2048   527345    3.012
//    4096  1586131    3.008
//
// Dicas:
// 1. Guarde o valor anterior numa variável: comece com anterior =
//    trabalho(32) e, a cada volta, atualize anterior = t.
// 2. A divisão precisa de um cast: (double)t / anterior.
// 3. Resposta esperada: a tabela acima. A razão começa um pouco acima de 3
//    (o "+ n" ainda pesa com n pequeno) e vai chegando em 3.
//
// Escreva sua resposta abaixo (complete o main):

#include <stdio.h>

// cada chamada faz n unidades de trabalho e chama 3 vezes com metade
long trabalho(int n) {
    if (n == 1) {
        return 1;
    }
    long total = n;
    for (int i = 0; i < 3; i++) {
        total += trabalho(n / 2);
    }
    return total;
}

int main(void) {
    printf("T(64) = %ld\n", trabalho(64));
    return 0;
}
