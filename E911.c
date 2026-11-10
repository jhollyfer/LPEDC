// 0152 · Kruskal: árvore geradora mínima
// Exercício E911 · ★★★
//
// O parque de diversões vai ligar seis atrações com os trilhos de um trenzinho,
// gastando o mínimo. As atrações (índices 0 a 5) são Entrada, Carrossel, Roda,
// Lago, Castelo e Montanha. Os trilhos possíveis, com o custo em R$ mil, na
// ordem em que foram levantados:
//
//   Entrada-Carrossel 4  Roda-Lago 5        Carrossel-Lago 6
//   Entrada-Roda 7       Lago-Castelo 8     Castelo-Montanha 9
//   Roda-Montanha 10     Carrossel-Castelo 11  Entrada-Montanha 12
//
// Escreva o Kruskal: ordene as arestas por custo com qsort, use union-find
// (vetor pai[] e função acha com compressão de caminho) e ligue as RAÍZES dos
// dois grupos a cada aresta aceita. Pare quando houver V - 1 trilhos e mostre
// cada um, na ordem em que entra, e o total.
//
//   Saída esperada:
//   Entrada-Carrossel (4)
//   Roda-Lago (5)
//   Carrossel-Lago (6)
//   Lago-Castelo (8)
//   Castelo-Montanha (9)
//   Total: R$ 32 mil
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
