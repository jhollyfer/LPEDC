// 0118 · Juntando tudo
// Exercício E708 · ★★★
//
// Conserte o programa. Ele devia comparar as quatro ordenações do
// ordena.h com os MESMOS 20 mil números sorteados, mas os resultados não
// fazem sentido:
//
//   Saída que aparece:
//   insertion: 99529734 comparações, 0.000 s
//   merge:     99668950 comparações, 0.000 s
//   heap:      100198011 comparações, 0.000 s
//   quick:     100445261 comparações, 0.000 s
//
// Há três erros, um em cada medida: o tempo sai sempre zero, as
// comparações vão se acumulando de um algoritmo para o outro, e os três
// últimos algoritmos não recebem a mesma entrada que o primeiro.
//
//   Saída esperada (os tempos variam; as comparações, não):
//   insertion: 99529734 comparações, 0.658 s
//   merge:       260882 comparações, 0.004 s
//   heap:        510606 comparações, 0.007 s
//   quick:       331546 comparações, 0.004 s
//
// Dicas:
// 1. clock() e CLOCKS_PER_SEC são inteiros. O que dá 658000 / 1000000 em
//    divisão inteira?
// 2. Onde a contagem é zerada? Uma vez só, antes do laço?
// 3. Depois do insertion, como está o vetor v? O que o merge recebe?
// 4. Resposta esperada: a saída esperada acima. Os consertos: dividir em
//    double ((double)(clock() - ini) / CLOCKS_PER_SEC), chamar
//    ord_zera_contagem() antes de cada ordenação e copiar o original para
//    v (memcpy) também antes de cada uma.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ordena.h"

#define N 20000

int original[N], v[N];

int main(void) {
    unsigned s = 2025;
    for (int i = 0; i < N; i++) {
        s = s * 1103515245u + 12345u;
        original[i] = (int)(s >> 8);
    }

    const char *nomes[] = {"insertion:", "merge:", "heap:", "quick:"};
    void (*ordena[])(int[], int) = {ord_insertion, ord_merge, ord_heap, ord_quick};

    memcpy(v, original, sizeof v);
    ord_zera_contagem();
    for (int a = 0; a < 4; a++) {
        clock_t ini = clock();
        ordena[a](v, N);
        double segundos = (clock() - ini) / CLOCKS_PER_SEC;
        printf("%-10s %8ld comparações, %.3f s\n", nomes[a], ord_contagem(), segundos);
    }
    return 0;
}
