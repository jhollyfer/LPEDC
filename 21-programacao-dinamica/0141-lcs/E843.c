// 0141 · Maior subsequência comum (LCS)
// Exercício E843 · ★★☆
//
// A LCS não é só para strings. Ana e Beto montaram playlists para a viagem,
// e cada música tem um número de catálogo:
//
//   Ana:  12  7 33  5 21  8 40 17
//   Beto:  7  5  9 21 40  3 17 12
//
// Eles querem uma playlist em comum que respeite a ordem das DUAS listas.
// Escreva a função
//
//   int lcs_vetor(const int a[], int m, const int b[], int n, int saida[])
//
// que grava em saida a maior subsequência comum dos dois vetores e devolve
// o tamanho dela. Mostre o resultado.
//
//   Saída esperada:
//   5 músicas em comum, na mesma ordem: 7 5 21 40 17
//
// Dicas:
// 1. É o código do texto trocando char por int: a comparação a[i - 1] ==
//    b[j - 1] continua igual, e não há '\0' no fim.
// 2. A volta grava em saida[--k], começando com k = c[m][n].
// 3. A música 12 está nas duas, mas é a primeira da Ana e a última do Beto:
//    ela não cabe na mesma ordem junto com as outras.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>

int main(void) {

    return 0;
}
