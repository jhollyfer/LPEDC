// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2025 · ★★★ · A mediana das medianas
//
// O SELECT pela partição (com pivô qualquer) pode cair no pior caso O(n²).
// O algoritmo da MEDIANA DAS MEDIANAS (Cormen 9.3) escolhe um pivô bom de
// propósito: divida o vetor em grupos de 5, ache a mediana de cada grupo
// (ordenando os 5 com insertion sort), ache recursivamente a mediana
// dessas medianas e use-a como pivô. Assim cada lado da partição tem pelo
// menos cerca de 3n/10 elementos, e o tempo é O(n) no pior caso.
//
// Os 23 lances de um leilão de gado, em mil reais, estão no main. Escreva
// do zero seleciona(v, n, k), que devolve o k-ésimo menor (k a partir de
// 0) com esse pivô, e mostre o menor, a mediana (k = 11) e o maior,
// conferindo com o vetor ordenado por qsort.
//
//   Saída esperada:
//   Menor: 41 (qsort: 41)
//   Mediana: 69 (qsort: 69)
//   Maior: 98 (qsort: 98)
//
// Dicas:
// 1. Com n <= 5, ordene e devolva v[k]. Senão, copie as medianas dos grupos
//    para um vetor med[] (o último grupo pode ter menos de 5) e chame
//    seleciona(med, ng, ng / 2) para achar o pivô.
// 2. Particione em três vetores: menores, iguais e maiores que o pivô (com
//    malloc, e free no fim). Se k < nmen, desça nos menores; se k < nmen +
//    nig, a resposta é o pivô; senão, desça nos maiores com k - nmen - nig.
// 3. Resposta esperada: menor 41, mediana 67 e maior 98, iguais ao qsort.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    return 0;
}
