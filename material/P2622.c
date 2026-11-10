// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2622 · ★★★ · Sanduíche com logaritmo
//
// A indexação das notas fiscais custa f(n) = n log2 n + 5n operações. Ache
// por busca as fatias do Θ(n log n): para n de 2 até 100000, calcule a razão
// f(n) / (n log2 n) e guarde o menor e o maior valor. Mostre também a razão
// em n = 2, 1024 e 100000, e conclua com os c1, c2 e n0 que servem:
//
//   Saída esperada:
//   n =      2: razão 6.0000
//   n =   1024: razão 1.5000
//   n = 100000: razão 1.3010
//   menor 1.3010, maior 6.0000
//   Θ(n log n) com c1 = 1, c2 = 6 e n0 = 2
//
// Dicas:
// 1. A razão é 1 + 5 / log2 n: começa em 6 e desce devagar para 1.
// 2. Como ela nunca fica abaixo de 1, c1 = 1 vale para todo n >= 2; c2 = 6 é
//    o valor em n = 2.
// 3. Comece em n = 2: com n = 1, log2 n = 0 e a razão divide por zero.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <math.h>

int main(void) {

    return 0;
}
