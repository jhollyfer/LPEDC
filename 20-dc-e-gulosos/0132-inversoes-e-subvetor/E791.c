// 0132 · Inversões e subvetor de soma máxima
// Exercício E791 · ★★★
//
// Um analista quer contar as quedas fortes no preço de uma ação: pares de
// dias i < j em que o preço do dia i era MAIS QUE O DOBRO do preço do dia j
// (preco[i] > 2 * preco[j]). Os preços de 8 dias, em reais:
//
//   40 18 25 9 30 12 50 20
//
// Escreva a versão O(n log n), adaptando o merge sort que conta inversões,
// e confira com uma força bruta O(n²) feita ANTES de ordenar.
//
//   Saída esperada:
//   Quedas de mais da metade: 7
//   Força bruta: 7
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {
    int preco[] = {40, 18, 25, 9, 30, 12, 50, 20};
    int n = 8;
    (void)preco;
    (void)n;

    return 0;
}
