// Lista · Módulo 17 · Medindo algoritmos recursivos
// Exercício P1701 · ★☆☆ · O faturamento somado pelas metades
//
// A padaria guarda o faturamento de cada dia (em reais) num vetor. A função
// soma(v, ini, fim) do esqueleto soma v[ini..fim] dividindo o pedaço ao meio e
// somando as duas metades. A recorrência do número de chamadas é
//
//   C(1) = 1,  C(n) = C(⌈n/2⌉) + C(⌊n/2⌋) + 1
//
// Confira no computador que C(n) = 2n - 1, para QUALQUER n (não só potência
// de 2): acrescente um contador global de chamadas e mostre, para n = 1, 2,
// 3, 4, 10, 16, 64 e 100, a soma dos n primeiros dias, as chamadas contadas e
// 2n - 1.
//
//   Saída esperada:
//     n       soma  chamadas  2n-1
//     1        900         1     1
//     2       1850         3     3
//     3       2850         5     5
//     4       3900         7     7
//    10      10200        19    19
//    16      16550        31    31
//    64      67050       127   127
//   100     104750       199   199
//
// Dicas:
// 1. Some 1 no contador na primeira linha de soma(). Zere o contador antes
//    de cada n.
// 2. A árvore de recursão tem n folhas (um dia cada) e n - 1 nós internos
//    (cada um junta dois pedaços): 2n - 1 nós no total.
// 3. O custo é Θ(n): dividir ao meio não deixa a soma mais rápida que um
//    laço.
// 4. Resposta esperada: as duas colunas de chamadas são sempre iguais; com
//    n = 100 são 199 chamadas.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

#define DIAS 100

int fat[DIAS];

long soma(const int v[], int ini, int fim) {
    if (ini == fim) return v[ini]; // um dia só
    int meio = (ini + fim) / 2;
    return soma(v, ini, meio) + soma(v, meio + 1, fim);
}

int main(void) {
    for (int i = 0; i < DIAS; i++) fat[i] = 900 + (i % 7) * 50; // sábado vende mais

    printf("Total dos 100 dias: R$ %ld\n", soma(fat, 0, DIAS - 1));
    return 0;
}
