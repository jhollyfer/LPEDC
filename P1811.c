// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1811 · ★★☆ · Quatro sequências de saltos no mesmo shell sort
//
// O shell sort é o mesmo algoritmo com qualquer sequência de saltos que
// termine em 1, mas o desempenho muda muito. Compare quatro:
//
// - Shell (1959): n/2, n/4, ..., 1;
// - Hibbard (1963): 2^k - 1 (1, 3, 7, 15, 31, ...);
// - Knuth (1973): h = 3h + 1 (1, 4, 13, 40, 121, ...), começando no maior
// h < n/3;
// - Sedgewick (1986): 4^k + 3 · 2^(k-1) + 1, com 1 no começo (1, 8, 23, 77,
// 281, 1073, 4193, ...).
//
// Escreva shell(v, n, saltos, ns), que recebe os saltos em ordem DECRESCENTE,
// e conte as comparações. Ordene cópias dos mesmos tempos de entrega (gerados
// no esqueleto) para n = 1000 e n = 10000, confira que ficaram ordenados e
// mostre as comparações de cada sequência e do insertion sort puro.
//
//   Saída esperada:
//                n = 1000  n = 10000
//   Shell           14923     258585
//   Hibbard         14298     231869
//   Knuth           13674     233094
//   Sedgewick       15546     221889
//   insertion      256897   24710349
//   Todos ordenados: sim
//
// Dicas:
// 1. Monte cada sequência num vetor (em ordem crescente, que é mais fácil de
//    gerar) e passe para a função percorrendo de trás para frente.
// 2. Para Hibbard e Sedgewick, use só os saltos menores que n. Para Knuth,
//    pare quando o próximo passaria de n/3.
// 3. O insertion sort é o shell sort com a sequência "1": aproveite a mesma
//    função.
// 4. Resposta esperada: o insertion sort fica perto de n²/4 (24,7 milhões
//    com n = 10000, contra uns 230 mil das sequências). Com n = 1000 as
//    quatro empatam perto de 15 mil; com n = 10000, Shell é a pior (258585) e
//    Sedgewick, a melhor (221889). A diferença cresce com n.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAXN 10000

unsigned semente = 77;

int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 3600); // segundos
}

int main(void) {
    static int original[MAXN];
    for (int i = 0; i < MAXN; i++) original[i] = sorteia();

    printf("%d %d %d\n", original[0], original[1], original[2]);
    return 0;
}
