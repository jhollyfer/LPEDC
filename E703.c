// 0118 · Juntando tudo
// Exercício E703 · ★☆☆
//
// Escreva cronometra(ordena, n): copia os n primeiros números de original[]
// para v[], ordena v com a função recebida (void (*)(int[], int)) e devolve o
// tempo em ms, medido com clock(). Com ordena.h e ordena.c da pasta, mostre o
// tempo de ord_insertion e de ord_merge para n = 1000, 2000, 4000 e 8000, com
// a razão sobre a linha anterior. original: s = 1 e, a cada posição, s = s *
// 1103515245u + 12345u e original[i] = (int)(s >> 8). Os tempos variam; as
// razões, pouco.
//
//   Saída esperada:
//       n   insertion (ms)        merge (ms)
//    1000      0.66            0.089
//    2000      2.62  x4.0      0.183  x2.1
//    4000     10.55  x4.0      0.408  x2.2
//    8000     42.45  x4.0      0.887  x2.2
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "0118-ordena.h"

#define MAX 8000

int original[MAX], v[MAX];

int main(void) {

    return 0;
}
