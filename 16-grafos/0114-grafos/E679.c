// 0114 · Grafos
// Exercício E679 · ★☆☆
//
// Uma companhia aérea regional tem voos diretos, de ida e volta, entre
// quatro capitais: Recife (0), Salvador (1), Fortaleza (2) e Natal (3). Os
// voos são: Recife-Salvador, Recife-Fortaleza, Recife-Natal e
// Fortaleza-Natal.
//
// Monte a matriz de adjacência (grafo não dirigido), mostre a matriz e conte
// quantos voos existem olhando só para a matriz (não vale contar os pares à
// mão):
//
//   Saída esperada:
//        0 1 2 3
//     0  0 1 1 1
//     1  1 0 0 0
//     2  1 0 0 1
//     3  1 0 1 0
//   Voos diretos: 4
//
// Dicas:
// 1. int adj[4][4] = {0}; e, para cada voo, marque adj[a][b] e adj[b][a].
// 2. Cada voo aparece duas vezes na matriz. Some só a parte de cima da
//    diagonal (j > i) ou some tudo e divida por 2.
// 3. Resposta esperada: a matriz acima e "Voos diretos: 4".
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
