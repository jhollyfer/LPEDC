// 0118 · Juntando tudo
// Exercício E703 · ★☆☆
//
// Meça o tempo de verdade. Escreva cronometra(ordena, n), que copia os n
// primeiros números de original[] para v[], ordena v com a função recebida
// e devolve o tempo em milissegundos, medido com clock(). Depois mostre o
// tempo do ord_insertion e do ord_merge (do TAD ordena.h, que está na
// pasta) para n = 1000, 2000, 4000 e 8000, com a razão em relação à linha
// anterior. Os números do original vêm do gerador já escrito no main.
//
//   Saída esperada (os tempos variam; o formato e as razões, não muito):
//       n   insertion (ms)        merge (ms)
//    1000      1.53            0.184
//    2000      6.08  x4.0      0.327  x1.8
//    4000     24.19  x4.0      0.746  x2.3
//    8000     97.76  x4.0      1.513  x2.0
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordena.h"

#define MAX 8000

int original[MAX], v[MAX];

int main(void) {
    unsigned s = 1;
    for (int i = 0; i < MAX; i++) {
        s = s * 1103515245u + 12345u;
        original[i] = (int)(s >> 8);
    }

    return 0;
}
