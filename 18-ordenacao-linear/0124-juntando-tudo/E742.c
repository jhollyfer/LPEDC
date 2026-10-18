// 0124 · Juntando tudo
// Exercício E742 · ★★☆
//
// O time de fraudes quer duas estatísticas dos valores do dia: a mediana
// (posição N / 2) e o p99 (posição 989999 de 1 milhão, pela regra do posto
// mais próximo). Para economizar, copie só os valores (os centavos) para um
// vetor de int, 4 MB em vez dos 12 MB dos registros, e use o quickselect
// nele, com pivô do meio. Depois confira: ordene os registros com
// pix_por_valor e compare as duas posições.
//
//   Saída esperada:
//   mediana: R$ 56,98
//   p99:     R$ 9160,98
//   conferindo com o radix: iguais
//
// Dicas:
// 1. Dados: pix_gera(v, 1000000, 2024).
// 2. O quickselect do texto com uma linha a mais no começo de cada volta:
//    troca(&v[p + (r - p) / 2], &v[r]), o pivô do meio.
// 3. Dá para chamar a seleção duas vezes no mesmo vetor de int: a segunda
//    chamada só reaproveita a bagunça da primeira.
// 4. Formato do dinheiro: "R$ %d,%02d" com centavos / 100 e centavos % 100.
// 5. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

#define N 1000000

int main(void) {

    return 0;
}
