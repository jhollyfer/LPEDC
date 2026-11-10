// Lista · Módulo 28 · Estruturas: o que faltava
// Exercício P2808 · ★☆☆ · Multiplicação em ponto flutuante
//
// Escreva h(k, m) = floor(m · (k·A mod 1)) com A = (raiz de 5 - 1) / 2, em
// double. Para as senhas 10, 20, ..., 80 e m = 8, mostre o balde de cada uma
// e quantos baldes diferentes foram usados. Compare com k mod 8.
//
//   Saída esperada:
//   senha | mult | k % 8
//      10 |    1 | 2
//      20 |    2 | 4
//      30 |    4 | 6
//      40 |    5 | 0
//      50 |    7 | 2
//      60 |    0 | 4
//      70 |    2 | 6
//      80 |    3 | 0
//   baldes usados: multiplicação 7, divisão 4
//
// Dicas:
// 1. "mod 1" é tirar a parte inteira: p - floor(p).
// 2. Com k mod 8, as senhas múltiplas de 10 só usam baldes pares.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {

    return 0;
}
