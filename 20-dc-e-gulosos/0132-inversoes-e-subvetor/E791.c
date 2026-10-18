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
// Dicas:
// 1. Não dá para contar dentro da intercalação, como no texto: a ordem em
//    que os elementos saem segue v[i] <= v[j], e não v[i] > 2 * v[j]. Faça
//    um laço SEPARADO, com as duas metades já ordenadas, ANTES de intercalar.
// 2. Nesse laço, j começa em q e só anda para a frente: para cada i da
//    esquerda, avance j enquanto v[i] > 2 * v[j]; some j - q. Como v[i]
//    cresce, o j de um i serve de ponto de partida para o próximo. O laço
//    todo é O(n).
// 3. Resposta esperada: 7 nas duas linhas. Os pares são (40, 18), (40, 9),
//    (40, 12), (25, 9), (25, 12), (30, 12) e (50, 20). Se as contas não
//    baterem, mostre os pares da força bruta com printf para achar a falha.
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
