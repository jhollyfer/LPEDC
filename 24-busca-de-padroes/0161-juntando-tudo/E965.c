// 0161 · Juntando tudo
// Exercício E965 · ★★★
//
// Com alfabeto pequeno, quem ganha? Gere um "DNA" de 100.000 letras A, C, G e
// T com o gerador abaixo (sempre a mesma sequência, em qualquer máquina) e,
// para m = 4, 8, 16 e 32, use como padrão as m letras a partir da posição
// 50.000 do próprio texto. Mostre as comparações dos quatro algoritmos numa
// tabela:
//
//   Saída esperada:
//     m    bruta      KMP  Horspool  Rabin-Karp  ocorrências
//     4   132695   124685     46636        1464          366
//     8   133189   125048     43417          24            3
//    16   133190   125049     29489          16            1
//    32   133184   125044     47243          32            1
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "padroes.h"

#define N 100000

static unsigned long semente = 2026;
static int sorteia(int limite) {
    semente = (semente * 1103515245UL + 12345UL) % 2147483648UL;
    return (int) (semente / 65536 % (unsigned long) limite);
}

int main(void) {
    (void)sorteia; // apague esta linha quando usar o sorteia

    return 0;
}
