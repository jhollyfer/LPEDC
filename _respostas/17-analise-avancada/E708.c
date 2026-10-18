// 0118 · Juntando tudo
// Exercício E708 · ★★★

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

    for (int a = 0; a < 4; a++) {
        memcpy(v, original, sizeof v);   // conserto 3: a mesma entrada para todos
        ord_zera_contagem();             // conserto 2: contagem do zero
        clock_t ini = clock();
        ordena[a](v, N);
        double segundos = (double)(clock() - ini) / CLOCKS_PER_SEC; // conserto 1
        printf("%-10s %8ld comparações, %.3f s\n", nomes[a], ord_contagem(), segundos);
    }
    return 0;
}
