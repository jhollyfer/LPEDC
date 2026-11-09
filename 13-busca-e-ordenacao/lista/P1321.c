// Lista · Módulo 13 · Busca e ordenação
// Exercício P1321 · ★★★ · As quedas de mais da metade
//
// O preço de uma ação, em reais, nos últimos 8 pregões foi
// 40, 15, 22, 90, 10, 35, 8, 50. O analista chama de "queda forte" todo par
// de dias i < j em que o preço do dia i é MAIS QUE O DOBRO do preço do dia j
// (v[i] > 2 * v[j]). Quantas quedas fortes houve?
//
// Escreva duas versões:
//
//   long long forca_bruta(const int v[], int n)                    O(n²)
//   long long conta(int v[], int aux[], int p, int r)    O(n log n), merge sort
//
// Na versão rápida, depois de ordenar as duas metades e ANTES de intercalar,
// conte os pares (i na esquerda, j na direita) com v[i] > 2 * v[j]. Como as
// duas metades estão ordenadas, o índice j só anda para a frente: um laço
// em i com um while em j, os dois juntos em O(n). Depois, intercale normalmente.
// Mostre os dois resultados e o vetor ordenado.
//
//   Saída esperada:
//   força bruta: 9 pares
//   merge sort: 9 pares
//   ordenado: 8 10 15 22 35 40 50 90
//
// Dicas:
// 1. É o mesmo truque da contagem de inversões, com outra condição. Não dá
//    para contar DURANTE a intercalação, porque a condição v[i] > 2 * v[j]
//    não é a mesma que decide quem sai primeiro.
// 2. Para cada i da esquerda, avance j enquanto j <= r e v[i] > 2 * v[j];
//    some j - (q + 1). Quando i cresce, v[i] cresce, e o j antigo continua
//    valendo.
// 3. Use 2LL * v[j] para a conta não estourar com preços grandes.
// 4. Resposta esperada: 9 pares (por exemplo, 40 > 2 · 15 e 90 > 2 · 35).
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
