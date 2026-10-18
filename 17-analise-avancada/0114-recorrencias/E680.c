// 0114 · Recorrências e árvore de recursão
// Exercício E680 · ★☆☆
//
// Uma recorrência também é um programa: dá para calcular T(n) com uma função
// recursiva que é a própria equação. Complete as três funções abaixo, todas
// com caso base 1 quando n = 1:
//
//   A(n) = A(n/2) + 1          (busca binária)
//   B(n) = 2 B(n/2) + 1        (máximo dividindo ao meio)
//   C(n) = 2 C(n/2) + n        (a auditoria do texto)
//
// O main já mostra, ao lado de cada uma, a fórmula fechada que a árvore de
// recursão dá. Se as colunas baterem, suas funções estão certas:
//
//   Saída esperada:
//    n | A(n) log+1 | B(n) 2n-1 | C(n) n log n + n
//    1 |    1     1 |    1    1 |    1     1
//    2 |    2     2 |    3    3 |    4     4
//    4 |    3     3 |    7    7 |   12    12
//    8 |    4     4 |   15   15 |   32    32
//   16 |    5     5 |   31   31 |   80    80
//   32 |    6     6 |   63   63 |  192   192
//   64 |    7     7 |  127  127 |  448   448
//
// Dicas:
// 1. Cada função tem duas linhas de verdade: if (n == 1) return 1; e o
//    return com a equação.
// 2. B não precisa de duas chamadas: 2 * rec_b(n / 2) + 1 calcula o mesmo
//    valor com uma só (aqui você calcula o custo, não roda o algoritmo).
// 3. Resposta esperada: a tabela acima.
//
// Escreva sua resposta abaixo (complete as três funções):

#include <stdio.h>

long rec_a(long n) {
    (void)n; // apague esta linha
    return 0;
}

long rec_b(long n) {
    (void)n; // apague esta linha
    return 0;
}

long rec_c(long n) {
    (void)n; // apague esta linha
    return 0;
}

int main(void) {
    printf(" n | A(n) log+1 | B(n) 2n-1 | C(n) n log n + n\n");
    long lg = 0; // log2 de n
    for (long n = 1; n <= 64; n *= 2, lg++) {
        printf("%2ld | %4ld %5ld | %4ld %4ld | %4ld %5ld\n",
               n, rec_a(n), lg + 1, rec_b(n), 2 * n - 1, rec_c(n), n * lg + n);
    }
    return 0;
}
