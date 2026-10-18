// 0118 · Juntando tudo
// Exercício E705 · ★★☆

#include <stdio.h>
#include <string.h>
#include "ordena.h"

#define N 10000

unsigned semente = 3;
int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int)(semente >> 8);
}

int main(void) {
    static int base[N], v[N];
    for (int i = 0; i < N; i++) {
        base[i] = i;                         // o cadastro, em ordem
    }
    for (int k = 0; k < 50; k++) {           // 50 trocas de vizinhos
        int i = sorteia() % (N - 1);
        int t = base[i];
        base[i] = base[i + 1];
        base[i + 1] = t;
    }

    const char *nomes[] = {"insertion", "merge", "heap", "quick"};
    void (*ordena[])(int[], int) = {ord_insertion, ord_merge, ord_heap, ord_quick};
    int melhor = 0;
    long menor = -1;
    for (int a = 0; a < 4; a++) {
        memcpy(v, base, sizeof v);
        ord_zera_contagem();
        ordena[a](v, N);
        long c = ord_contagem();
        printf("%-9s %7ld comparações\n", nomes[a], c);
        if (!ord_confere(v, N)) {
            printf("%s não ordenou!\n", nomes[a]);
        }
        if (menor < 0 || c < menor) {
            menor = c;
            melhor = a;
        }
    }
    printf("vencedor: %s\n", nomes[melhor]);
    return 0;
}
