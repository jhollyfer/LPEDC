// 0118 · Juntando tudo
// Exercício E707 · ★★★
//
// Escreva o merge sort híbrido hibrido(v, w, p, r) sobre v[p..r-1] (w é o
// rascunho) que, para pedaços com menos de limiar elementos, chama
// insertion_trecho(v, p, r), também sua. Conte as comparações numa função
// menor(a, b) global e cronometre com clock(). Ordene 200 mil números (s =
// 11; s = s * 1103515245u + 12345u; (int)(s >> 8)) com limiar 1, 8, 16, 32,
// 64 e 256, conferindo o resultado. Os tempos variam; as comparações, não.
//
//   Saída esperada:
//   L =   1:  3272603 comparações,   29.2 ms
//   L =   8:  3315173 comparações,   27.2 ms
//   L =  16:  3478137 comparações,   26.8 ms
//   L =  32:  3925760 comparações,   26.5 ms
//   L =  64:  4963872 comparações,   28.2 ms
//   L = 256: 11917965 comparações,   45.1 ms
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 200000

int main(void) {

    return 0;
}
