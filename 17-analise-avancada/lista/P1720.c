// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1720 · ★★☆ · Quatro ordenações contando comparações
//
// Em vez de cronometrar, conte. O esqueleto gera os preços de n produtos com
// um gerador pseudoaleatório fixo (a mesma sequência em toda execução).
// Escreva insertion sort, merge sort, heapsort e quicksort (pivô no último
// elemento, partição de Lomuto) e conte as COMPARAÇÕES ENTRE ELEMENTOS de
// cada um, todos ordenando cópias do mesmo vetor.
//
// Mostre as contagens para n = 1000 e n = 2000, a razão entre as duas (quanto
// cresce quando n dobra) e as referências n²/4 e n lg n. Confira também que
// os quatro deixam o vetor ordenado.
//
//   Saída esperada:
//               n = 1000  n = 2000  razão
//   insertion     250962   1021285   4.07
//   merge           8707     19411   2.23
//   heapsort       16835     37713   2.24
//   quicksort      10531     23811   2.26
//   n²/4         250000   1000000   4.00
//   n lg n          9966     21932   2.20
//   Todos ordenados: sim
//
// Dicas:
// 1. Faça a comparação passar por uma função menor(a, b) que soma 1 num
//    contador global: assim nenhuma comparação escapa.
// 2. Quadrático: dobrar n multiplica por 4. Θ(n lg n): multiplica por um
//    pouco mais que 2 (2 · lg 2n / lg n ≈ 2,2 para n = 1000).
// 3. O insertion sort faz em média n²/4 comparações; merge sort fica perto de
//    n lg n - n; quicksort aleatório, perto de 1,39 n lg n.
// 4. Resposta esperada: o insertion sort fica perto de n²/4 e quadruplica;
//    os outros três ficam entre n lg n - n e 2 n lg n e crescem cerca de 2,2
//    vezes.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000

unsigned semente;

int sorteia(void) { // gerador congruencial: sempre a mesma sequência
    semente = semente * 1103515245u + 12345u;
    return (int)((semente >> 16) % 100000);
}

int main(void) {
    int original[MAXN];
    semente = 2024;
    for (int i = 0; i < MAXN; i++) original[i] = sorteia(); // preço em centavos

    printf("%d %d %d\n", original[0], original[1], original[2]);
    return 0;
}
