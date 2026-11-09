// Lista · Módulo 18 · Ordenação além da comparação e seleção
// Exercício P1824 · ★★★ · Por dentro da análise do bucket sort
//
// A análise do bucket sort no Cormen diz: com n valores uniformes em [0, 1)
// e n baldes, o número n_i de itens no balde i segue uma distribuição
// binomial, E[n_i²] = 2 - 1/n, e o tempo esperado é Θ(n). Confira no
// computador.
//
// Gere n = 10000 valores com o gerador do esqueleto, faça o bucket sort
// completo (listas encadeadas com malloc, inserção em ordem contando as
// comparações, concatenação, free de tudo) e mostre:
//
// - o histograma da ocupação: quantos baldes ficaram com 0, 1, 2, ...
// itens, ao lado do esperado pela aproximação de Poisson, n · e^(-1) / j!;
// - a soma dos n_i², comparada com n · (2 - 1/n);
// - as comparações da inserção, comparadas com a soma dos n_i (n_i - 1)/2
// (o pior caso dentro de cada balde) e com n;
// - se o vetor final ficou ordenado.
//
//   Saída esperada:
//   itens  baldes  esperado
//       0    3663      3679
//       1    3736      3679
//       2    1776      1839
//       3     634       613
//       4     149       153
//       5      38        31
//       6       4         5
//   Soma dos n_i²: 20024 (esperado n(2 - 1/n) = 19999)
//   Comparações: 4559 (pior caso nos baldes: 5012; n = 10000)
//   Ordenado: sim
//
// Dicas:
// 1. valor = sorteia() / 4294967296.0 dá um double em [0, 1) a partir de um
//    unsigned de 32 bits.
// 2. Guarde n_i num vetor ao inserir; o histograma é um counting sort dos
//    n_i.
// 3. Poisson com média 1: P(j) = e^(-1) / j!. Calcule j! num laço e use
//    exp(-1.0).
// 4. Resposta esperada: 3663 baldes vazios (Poisson: 3679), 3736 com 1 item,
//    1776 com 2 e 634 com 3; soma dos n_i² 20024 (esperado 19999); 4559
//    comparações, menos de uma por item; ordenado.
//
// Escreva sua resposta abaixo:

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

typedef struct No {
    double x;
    struct No *prox;
} No;

unsigned semente = 2026;

unsigned sorteia(void) { // 32 bits pseudoaleatórios
    semente ^= semente << 13;
    semente ^= semente >> 17;
    semente ^= semente << 5;
    return semente;
}

int main(void) {
    static double v[N];
    for (int i = 0; i < N; i++) v[i] = sorteia() / 4294967296.0;

    printf("%.4f %.4f\n", v[0], v[1]);
    return 0;
}
