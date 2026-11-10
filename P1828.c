// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1828 · ★★★ · A entrada que derruba os saltos de Shell
//
// Com os saltos de Shell (n/2, n/4, ..., 2, 1) e n potência de 2, TODOS os
// saltos menores que n são pares, menos o último. Então, até a passada com
// h = 1, as posições pares só são comparadas com posições pares, e as ímpares
// com ímpares. Monte uma entrada que aproveita isso:
//
// - as posições PARES recebem os n/2 maiores valores, em ordem crescente;
// - as posições ÍMPARES recebem os n/2 menores, em ordem crescente.
//
// Cada fileira de salto par já está ordenada: as passadas com h >= 2 não
// movem nada. A última passada (insertion sort puro) tem de levar cada
// pequeno da metade da frente até o seu lugar: Θ(n²).
//
// Gere essa entrada para n = 1024 e n = 4096 (valores 0 a n - 1) e conte as
// comparações do shell sort com os saltos de Shell, com os de Hibbard
// (2^k - 1, todos ímpares) e com os de Knuth (3h + 1), mais o insertion sort
// puro. Repita com um vetor sorteado do mesmo tamanho para comparar.
//
//   Saída esperada:
//   n = 1024 (n²/8 = 131072)
//                      ruim   sorteado
//     Shell          140544      23965
//     Hibbard          9998      15278
//     Knuth            8792      14013
//     insertion      132350     254622
//   n = 4096 (n²/8 = 2097152)
//                      ruim   sorteado
//     Shell         2143232     207201
//     Hibbard         50192      79705
//     Knuth           44720      78028
//     insertion     2102270    4116375
//
// Dicas:
// 1. Entrada ruim: para i de 0 a n/2 - 1, v[2i] = n/2 + i e v[2i + 1] = i.
// 2. Reaproveite uma função shell(v, n, saltos, ns) que conta comparações;
//    cada sequência é só um vetor de saltos diferente.
// 3. Na última passada, o menor da metade da frente precisa andar até a
//    posição certa: o i-ésimo pequeno anda cerca de n/2 - i casas. A soma é
//    perto de n²/8.
// 4. Resposta esperada: com n = 4096 na entrada ruim, os saltos de Shell
//    fazem 2143232 comparações (mais que o insertion puro, e perto de
//    n²/8 = 2097152), enquanto Hibbard e Knuth ficam perto de 50 mil.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>

#define MAXN 4096

unsigned semente = 8;

int sorteia(int n) {
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % (unsigned)n);
}

int main(void) {
    static int ruim[MAXN];
    int n = 16;
    for (int i = 0; i < n / 2; i++) {
        ruim[2 * i] = 0;     // complete: os maiores nas posições pares
        ruim[2 * i + 1] = 0; // e os menores nas ímpares
    }
    for (int i = 0; i < n; i++) printf("%d ", ruim[i]);
    printf("\n");
    return 0;
}
